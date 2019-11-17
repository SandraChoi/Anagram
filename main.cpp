#include <iostream>
#include <fstream>
#include <string>

#include "Dictionary.h"

using namespace std;

int main()
{
	string inDicFileName = "words_test.txt";

	ifstream inFile;

	inFile.open(inDicFileName);

	if (inFile.is_open()) 
	{
		Dictionary dictionary;
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

	
	return 0;
}