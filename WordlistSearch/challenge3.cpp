// The purpose of this program is to search a word list and count the number of words that include C,A,T in this order
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Find C,A,T as required from wordlist
void wordSearchCounter() {
    vector<char> analysisTool;
	string neededWords;
	int accumaltor = 0;
	
	while (cin >> neededWords){
		analysisTool.clear();
		int k = 0;
		for (char letter : neededWords) {
			analysisTool.push_back(letter);
		}
		while (k < analysisTool.size()) {
			if (analysisTool.at(k) == 'c') {
				while (k < analysisTool.size()) {
					if (analysisTool.at(k) == 'a') {
						while (k < analysisTool.size()) {
							if (analysisTool.at(k) == 't') {
								accumaltor++;
								while (k < analysisTool.size()) {
									k++;
								}
							} else {
								k++;
							}
						}
					} else {
						k++;
					}
				}
			} else {
				k++;
			}
		}
	}
    cout << accumaltor;
}

int main() {
    cout << "Searching Provided List" << endl;
    cout << "Scan completed, There are : ";
    wordSearchCounter(); 
    cout << " words that fit the criteria" << endl;
}