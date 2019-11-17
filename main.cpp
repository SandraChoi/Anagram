#include <iostream>
#include <fstream>
#include <string>

#include "Dictionary.h"
#include "Report.h"

using namespace std;


int main()
{
	Dictionary dictionary;

	/* Fill a dictionary */
	string inDicFileName = "words.txt";

	ifstream inFile;

	inFile.open(inDicFileName);

	if (inFile.is_open()) 
	{
		string line;

		while (inFile) {
			getline(inFile, line);
			dictionary.add(line);
		}

		inFile.close();
	}
	else {
		cout << "Cannot open file: " << inDicFileName << endl;
	}

	/* Find possible anagrams */

	while (true)
	{
		cout << endl << "Enter a phrase with multiple words as input: ";

		string phrase;
		getline(cin, phrase);
		if (!cin || phrase.empty())
			return false;

		Report report = Report(phrase);
		dictionary.search(phrase, report.cb_find_anagram);
	}
	
	return true;
}