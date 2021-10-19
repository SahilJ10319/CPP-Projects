#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void wordFinder(){
	string word, neededWord;
	vector<string> words;
	int count = 1, i = 0;
	while (cin >> word){
		words.push_back(word);
	}
	while (i < words.size()) {
		neededWord = words[i];
		int j = i + 1;
		while(j < words.size()) {
			if(neededWord == words[j]) {
				count++;
				i = words.size();
			}
			j++;
		}
		i++;
	}
	cout << neededWord << " " << count << endl;
}

int main (){
	wordFinder();
	return 0;
} 