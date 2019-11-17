#ifndef _DICTIONARY_INCLUDED_
#define _DICTIONARY_INCLUDED_

#include <string>

using namespace std;

const int tableSize = 50000;

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	void add(string word);
	void search(string letters, void callback(string)) const;
	size_t hash(string word) const;

private:
	struct Bucket_t
	{
		string name;
		Bucket_t * p_next;
	};

	Bucket_t * m_buckets[tableSize];

};
#endif


