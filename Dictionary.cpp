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

void Dictionary::search(string letters, void callback(string)) const
{

}

