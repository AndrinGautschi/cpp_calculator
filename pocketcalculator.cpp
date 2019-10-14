#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "calc.h"
#include "sevensegment.h"

#define MAX_RESULT_LENGTH 8

int readNumberFromStream(std::istringstream &in) {
    int number;
    in >> number;
    return number;
}

char readOperatorFromStream(std::istringstream &in) {
    char op;
    in >> op;
    return op;
}

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
    printLargeDigit(number, out);
}

void pocketcalculator(std::istream &in, std::ostream &out) {
    while (true) {
        std::string input;
        out << "What do you want to calculate?\n";
        std::getline(in, input);

        if (input == "q") break;
        try {
            int result = executeCalc(input);
            printResult(result, out);
        } catch (const std::invalid_argument &ia) {
            printLargeError(out);
            out << "Your input seems to have an invalid format, please use format: <operand><operator><operand>\n\n";
        }
    }
    out << "Leaving calculator... See you!\n";
}