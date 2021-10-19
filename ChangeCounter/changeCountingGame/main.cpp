//
//  main.cpp
//  changeCountingGame
//
//  Created by Sahil Janjua on 2019-11-21.
//  Copyright © 2019 Sahil Janjua. All rights reserved.
//

#include <iostream>
int main() {
  // State the constants
  float nickels = 0.05;
  float dimes = 0.10;
  float quarters = 0.25;
  // Variables user will be inputting
  int n;
  int d;
  int q;
  // Output for users to enter quantity of change
  std::cout << "How many Nickels will you need: ";
  std::cin >> n;
  std::cout << std::endl;
  std::cout << "How many Dimes will you need: ";
  std::cin >> d;
  std::cout << std::endl;
  std::cout << "How many Quarters will you need: ";
  std::cin >> q;
  std::cout << std::endl;
  // Calculations
  double total = (n * nickels) + (d * dimes) + (q * quarters);
  // Conditions with Outputs
  if (total == 1) {
      std::cout << "Nickels:  " << n << std::endl;
      std::cout << "Dimes:    " << d << std::endl;
      std::cout << "Quarters: " << q << std::endl;
      std::cout << "YES" << std::endl;
  } else if (total < 1) {
      std::cout << "Nickels:  " << n << std::endl;
      std::cout << "Dimes:    " << d << std::endl;
      std::cout << "Quarters: " << q << std::endl;
      std::cout << "LESS THAN" << std::endl;
  } else if (total > 1) {
      std::cout << "Nickels:  " << n << std::endl;
      std::cout << "Dimes:    " << d << std::endl;
      std::cout << "Quarters: " << q << std::endl;
      std::cout << "MORE THAN" << std::endl;
  }
  return 0;
}
