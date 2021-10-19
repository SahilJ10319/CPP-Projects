#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void caculator() {
	int number = 0, xMax = 0, yMax = 0, Max = 0, x = 0, y = 0;
	vector<int> line;
	vector<vector<int> > numbers;
	while(cin >> number) {
		if (y < 5) {
			line.push_back(number);
			y++;
		} else {
			numbers.push_back(line);
			line.clear();
			line.push_back(number);
			y = 1;
		}
	}
	while(x < numbers.size() - 1) {
		int z = x + 1;
		while(z < numbers.size()) {
			int k = 0, sum = 0;
			while(k < 5) {
				sum += (numbers[x][k] * numbers[z][k]);
				k++;
			}
			if(sum > Max) {
				Max = sum;
				xMax = x;
				yMax = z;
			}
			z++;
		}
		x++;
	}
	cout << xMax << endl;
	cout << yMax << endl;
	cout << Max << endl;
}

int main() {
	caculator();
}