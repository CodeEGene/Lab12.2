
#include <iostream>
#include <string>
#include <cctype>
#include<fstream>

using namespace std;

void pressEnterToContinue();
bool isLetter(char c);

int main() {

	string dataFile;
	cout << "Enter file name: ";
	getline(cin, dataFile);
	ifstream inFile(dataFile);

	string word;
	char c;
	bool inWord = false;
	int letters = 0, wordAmount = 0;

	if (!inFile.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}

	while (inFile.get(c)) {
		if (isLetter(c)) {
			letters++;
			if (!inWord) {
				inWord = true;
				wordAmount++;
			}
		}
		else {
			inWord = false;
		}
	}

	inFile.close();

	cout << "Amount of words: " << wordAmount << endl;
	cout << "Amount of letters: " << letters << endl;

	pressEnterToContinue();

	return 0;
}

void pressEnterToContinue() {

	cout << "Press Enter to continue..." << endl;
	cin.clear();
	cin.get();

}

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}