#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "../calculator/calculator.h"
#include "../printout/printout.h"

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

int executeCalc(const std::string &input) {
    std::istringstream stringStream(input);
    int firstNumber = readNumberFromStream(stringStream);
    char op = readOperatorFromStream(stringStream);
    int secondNumber = readNumberFromStream(stringStream);
    return calc(firstNumber, secondNumber, op);
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
            printError(out);
            out << "Your input seems to have an invalid format, please use format: <operand><operator><operand>\n\n";
        }
    }
    out << "Leaving calculator... See you!\n";
}