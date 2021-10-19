#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>


void findVowel() {
    std::string word, neededWord;
    int vowelCount, greatestNumberOfVowels = 0;
    while (std::cin >> word) {
        vowelCount = 0;
        for (char letter : word) {
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
                vowelCount++;
            }
        }
        if (vowelCount > greatestNumberOfVowels) {
                    greatestNumberOfVowels = vowelCount;
                    neededWord = word;
        }
    }
    std::cout << "The Word is " << neededWord << std::endl;
}

int main() {
    findVowel();
}