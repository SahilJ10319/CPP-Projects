#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void sort() {
	string word;
	vector<string> sorted;
	vector<string> words;
	int i = 0, j = 0, n = 0;
	while (cin >> word) {
		words.push_back(word);
		sort(word.begin(), word.end());
		word += to_string(i);
		sorted.push_back(word);
		i++;
	}
	sort(sorted.begin(), sorted.end());
	for(char c : sorted[49999]) {
		if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
			n = stoi(sorted[49999].substr(j, sorted[49999].size() - j));
			break;
		}
		j++;
	}
	cout << words[n] << endl;
}

int main() {
	sort();
}