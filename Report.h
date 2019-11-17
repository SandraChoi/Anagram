#ifndef _REPORT_INCLUDED_
#define _PEPORT_INCLUDED_

#include <string>
#include <iostream>

using namespace std;

class Report
{
public:
	Report(string phrase) : target_angram(phrase), n_anagram(0) {
		cout << "Anagrams of " << phrase << ":" << endl;
	}
	~Report() {}

	static void cb_find_anagram(string anagram) {
		cout << anagram << endl;
	}
private:
	string target_angram;
	int n_anagram;
};
#endif
