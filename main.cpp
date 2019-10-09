#include <iostream>
#include "calculator/calculator.h"
#include "printout/printout.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << calc(3,3,'+');
    printLargeDigit(5, std::cout);
    printLargeDigit(10, std::cout);
    printLargeDigit(134, std::cout);
    return 0;
}