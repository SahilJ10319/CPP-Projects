#include <iostream>
/* input canDollar : Canadian Dollars
   output: US Dollar amount
   This program will be used to convert canadian dollar
   amounts to us dollar amounts */

int main() {
  // define constants
  const double USDOLLAR_PER_CANDOLLAR = 0.76;
  // collect input canDollar
  double canDollar;
  std::cout << "Please enter CAN dollar amount: ";
  std::cin >> canDollar;
  std::cout << "$";
  // calculate currency input in us dollar amount
  double usDollar = canDollar * USDOLLAR_PER_CANDOLLAR;
  // output of the # of us dollar after exchange
  printf("%0.2f", usDollar);
    std::cout << std::endl;
  return 0;
}

