//  main.cpp
//  jacob'sLemonadeStand
//
//  Created by Sahil Janjua on 2019-11-21.
//  Copyright © 2019 Sahil Janjua. All rights reserved.
//

/*
This program will be used to charge the customers of
Jacob's Lemonade stand with the correct amount of
money depending on what the buy.*/
#include <iostream>
#include <iomanip>
int main() {
  // State the constants
const int small = 1;
const int medium = 2;
const int large = 8;
const int taxApplied = 12;
// CENTS_PER_DOLLAR = CPD
const int CPD = 100;
  // Output for customers, Order = Ord
  int smallOrd, mediumOrd, largeOrd;
  std::cout << "Menu:" << std::endl;
  std::cout << "*******************" << std::endl;
  std::cout << "New-age lemonade sizes:" << std::endl;
  std::cout << " Small:  $" << small << std::endl;
  std::cout << " Medium: $" << medium << std::endl;
  std::cout << " Large:  $" << large << std::endl;
  std::cout << std::endl;
  std::cout << "Enter number of drinks purchased..." << std::endl;
  std::cout << " #Small: ";
  std::cin >> smallOrd;
  std::cout << " #Medium: ";
  std::cin >> mediumOrd;
  std::cout <<" #Large:  ";
  std::cin >> largeOrd;
  std::cout << std::endl;
  std::cout <<"Your order is:" << std::endl;
  std::cout <<" Small:   " << std::setw(2) << smallOrd;
  std::cout <<" @ $1 each" << std::endl;
  std::cout <<" Medium:  "  << std::setw(2) << mediumOrd;
  std::cout <<" @ $2 each" << std::endl;
  std::cout <<" Large:   " << std::setw(2) << largeOrd;
  std::cout <<" @ $8 each" << std::endl;
  // Do calculations to display Dollar and Cents of total
  int subtotal = (smallOrd* 100.0) + (mediumOrd * 200.0) + (largeOrd * 800.0);
  int dollarsForSubtotal = subtotal / CPD;
  int centsForSubtotal = (subtotal / CPD - dollarsForSubtotal) * CPD;
  std::cout << "Amount owing:" << std::endl;
  std::cout << " Subtotal: $"<< std::setw(3) << dollarsForSubtotal;
  std::cout << "." << std::setfill('0') << std::setw(2)<< centsForSubtotal;
  std::cout << std::setfill(' ') << std::endl;
  int tax = taxApplied / 100.0 * subtotal;
  int dollarsForTax = tax / CPD;
  int centsForTax = (tax / 100.0 - dollarsForTax) * 100.0;
  std::cout << " Tax:      $" << std::setw(3) << dollarsForTax << ".";
  std::cout << std::setfill('0') << std::setw(2);
  std::cout << centsForTax << std::setfill(' ') << std::endl;
  int totalDollars = dollarsForSubtotal + dollarsForTax;
  int totalCents = centsForSubtotal + centsForTax;
  std::cout << " Total:    $" << std::setw(3) << totalDollars;
  std::cout << "." << std::setfill('0');
  std::cout << std::setw(2) << totalCents << std::setfill(' ') << std::endl;
  return 0;
}
