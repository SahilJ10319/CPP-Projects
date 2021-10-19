//
//  main.cpp
//  talkNumbers
//
//  Created by Sahil Janjua on 2019-11-21.
//  Copyright © 2019 Sahil Janjua. All rights reserved.
//

#include <iostream>
int main() {
  int number;
  std::cout << "Enter your favorite number: ";
  std::cin >> number;
  if (number == 42) {
    std::cout << "Awesome Choice!" << std::endl;
    std::cout << "That's mine too!" << std::endl;
       if (number % 2 == 0)
      std::cout << "Now you're just getting even with me." << std::endl;
      else
      std::cout << "How odd!" << std::endl;
  } else {
      if (number % 2 == 0)
      std::cout << "Now you're just getting even with me." << std::endl;
      else
      std::cout << "How odd!" << std::endl;
  }
  if (number < 10) {
    std::cout << "Small." << std::endl;
  } else if (number >= 10 && number <= 50) {
    std::cout << "Medium." << std::endl;
  } else if (number > 50 && number < 100) {
    std::cout << "Large." << std::endl;
  } else if (number >= 100 && number <= 1000) {
    std::cout << "Huge." << std::endl;
  } else if (number > 1000) {
    std::cout << "Massive!" << std::endl;
  }
  if (number > 10000) {
      int numberThousand = number / 1000;
      std::cout << "That's " << numberThousand << "k!" << std::endl;
      if (number % 1000 == 0)
      std::cout << "With nothing left over. " << std::endl;
      else
      std::cout << "With " <<number % 1000 << " left over.";
  }
  return 0;
}
