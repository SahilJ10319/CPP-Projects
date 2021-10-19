#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool is_operator(const char& s) {
    return (s == '*'|| s == '%' || s == '+' || s == '-');
}

string remove_spaces(const string& s) {
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ' && s[i] != '\n') {
            temp += s[i];
        }
    }
    return temp;
}

int main() {
    string input;
    int count = 0;

    while(getline(cin, input)) {
        input = remove_spaces(input);
        int pos = 0;
        vector<int> num;
        vector<char> operators;

        for (int i = 0; i < input.size(); i++) {
            if(is_operator(input[i])){
                operators.push_back(input[i]);
                num.push_back(stoi(input.substr(pos, i - pos)));
                pos = i + 1;
            }
            else if(i + 1 == input.size())
                num.push_back(stoi(input.substr(pos, input.size())));
        }
        int i = 0, j = 1;
        int sum = num[0];
        while (i < operators.size()) {
            if(operators[i] == '+') {
                sum += num[j];
                i++;
                j++;
            }
            else if(operators[i] == '-') {
                sum -= num[j];
                i++;
                j++;
            }
            else if(operators[i] == '*') {
                sum *= num[j];
                i++;
                j++;
            }
            else if(operators[i] == '%') {
                sum %= num[j];
                i++;
                j++;
            }
        }
        if (sum < 0) {
            count++;
        }
    }
    cout << "Count: " << count << endl;
}