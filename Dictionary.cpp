#include <string>
#include <cctype>

#include "Dictionary.h"

Dictionary::Dictionary() {
	for (int i = 0; i < tableSize; i++)
	{
		m_buckets[i] = nullptr;
	}
}

Dictionary::~Dictionary() {
	{
		for (int i = 0; i < tableSize; i++)
		{
			Bucket_t * p_del = m_buckets[i];
			if (p_del == nullptr)
				continue;
			else
			{
				while (p_del != nullptr)
				{
					Bucket_t * p_temp = p_del;
					p_del = p_del->p_next;
					delete p_temp;
				}
			}
		}
	}
}

void Dictionary::add(string word)
{
	size_t index = hash(word);

	if (!word.empty())
	{
		Bucket_t * node = new Bucket_t;
		node->name = word;

		Bucket_t * ptr = m_buckets[index];

		if (ptr != nullptr)
		{
			while (ptr->p_next != nullptr)
			{
				ptr = ptr->p_next;
			}
			ptr->p_next = node;
			node->p_next = nullptr;
		}
		else
		{
			m_buckets[index] = node;
			node->p_next = nullptr;
		}
	}
}



void Dictionary::search(string letters, void callback(string)) 
{
	if (callback == nullptr) return;

	remove_non_letters(letters);
	if (letters.empty()) return;

	size_t target_index = hash(letters);

	string jumbled = letters;	// init

	Bucket_t * node = m_buckets[target_index];

	if (node != nullptr)
	{
		while (node != nullptr)
		{
			if (count(jumbled) == count(node->name))
			{
				int found = 0;

				for (int k = 0; k < jumbled.length(); k++)
				{
					for (int i = 0; i < node->name.length(); i++)
					{
						if (jumbled[k] == node->name[i])
						{
							found++;
							break;
						}
					}
				}
				if (found == node->name.length())
				{
					if (node->name != letters) {
						callback(node->name);
					}
				}
					
			}

			node = node->p_next;
		}
	}
}


/**/

static const size_t Initial = 2166136261U;
static const size_t Multiple = 16777619;

size_t Dictionary::hash(string word) const
{
	size_t index = Initial;

	for (size_t i = 0; i < word.length(); i++)
	{
		index = index * (word[i]);
		index = index * Multiple;
	}
	return (index * 107) % tableSize;
}

/**/
void Dictionary::remove_non_letters(string& letters)
{
	string::iterator dst = letters.begin();
	for (string::const_iterator src = letters.begin(); src != letters.end(); src++)
	{
		if (isalpha(*src))
		{
			*dst = tolower(*src);
			dst++;
		}
	}
	letters.erase(dst, letters.end());
}

/**/
size_t Dictionary::count(string word) const
{
	size_t count = 0;

	for (int i = 0; i < word.length(); i++)
	{
		count += word[i];
	}

	return count;
}