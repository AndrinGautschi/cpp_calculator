#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "calc.h"
#include "sevensegment.h"

#define MAX_RESULT_LENGTH 8

bool endOfLine(std::istringstream &in) {
    std::string test;
    in >> test;
    return test.empty();
}

int executeCalc(const std::string &input) {
    std::istringstream stringStream(input);
    int firstNumber = readNumberFromStream(stringStream);
    char op = readOperatorFromStream(stringStream);
    int secondNumber = readNumberFromStream(stringStream);
    if (!endOfLine(stringStream)) {
        throw std::invalid_argument("Only integers are valid inputs");
    }

    auto result = calc(firstNumber, secondNumber, op);
    auto resultLength = std::to_string(result).length();
    if (result >= 0) resultLength++;
    if (resultLength > MAX_RESULT_LENGTH) {
        throw std::invalid_argument("The result has too many digits!");
    }
    return result;
}

void printResult(int number, std::ostream &out) {
    printLargeNumber(number, out);
}

void pocketcalculator(std::istream &in, std::ostream &out) {
    while (true) {
        if (!in.good()) break;
        std::string input;
        std::getline(in, input);

        if (input == "q") break;
        if (input.length() == 0) continue;
        try {
            int result = executeCalc(input);
            printResult(result, out);
        } catch (const std::invalid_argument &ia) {
            printLargeError(out);
        }
    }
}