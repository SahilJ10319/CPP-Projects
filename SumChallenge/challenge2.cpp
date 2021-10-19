#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>

int calculateSum (std::string s, char c) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) 
        if (s[i] == c)
        result++;
        return result;
}

int main() {
    long sum = 0;
    for (int k = 999; k < 1000000; k++) {
        std::string numbers = std::to_string(k);
        if (calculateSum(numbers,'9') == 3) {
            sum += k;
        }
    }
    std::cout << sum;
}