//
//  main.cpp
//  rootCalculator
//
//  Created by Sahil Janjua on 2019-11-21.
//  Copyright © 2019 Sahil Janjua. All rights reserved.
//
/* This Program will be used to calculate solutions of
quadratic equations with values added for a, b and c */
#include <iostream>
#include <cmath>
int main() {
  // Declare the variables we'll be inputting
  double a, b, c;
  std::cout << "a: ";
  std::cin >> a;
  std::cout << "b: ";
  std::cin >> b;
  std::cout << "c: ";
  std::cin >> c;
  // Declare the Equations, we'll use, disc = discriminant
  // p = power
  // Write code for user input
  double p = pow(b, 2);
  double disc = p - (4 * a * c);
  // Output using If / Else statements
  if (disc < 0) {
    std::cout << "ZERO" << std::endl;
  } else if (disc > 0) {
    std::cout << "TWO" << std::endl;
  } else if (disc == 0) {
    std::cout << "ONE" << std::endl;
  }
    return 0;
}
