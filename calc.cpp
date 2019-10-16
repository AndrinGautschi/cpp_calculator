#include <iostream>
#include <stdexcept>

int readNumberFromStream(std::istream & in) {
    int number;
    in >> number;
    if(!in) throw std::invalid_argument("could not read a number where a number was excepted");
    return number;
}

char readOperatorFromStream(std::istream & in) {
    char op;
    in >> op;
    if(!in) throw std::invalid_argument("could not read an operation where an operation was excepted");
    return op;
}

int add(int number1, int number2) {
    return number1 + number2;
}

int subtract(int number1, int number2) {
    return number1 - number2;
}

int multiply(int number1, int number2) {
    return number1 * number2;
}

int divide(int number1, int number2) {
    if (number2 == 0) {
        throw std::invalid_argument("division by zero is not valid");
    }
    return number1 / number2;
}

int modulo(int number1, int number2) {
    if (number2 == 0) {
        throw std::invalid_argument("modulo with zero is not valid");
    }
    return number1 % number2;
}

int calc(int lhs, int rhs, char op) {
    switch (op) {
        case '+':
            return add(lhs, rhs);
        case '-':
            return subtract(lhs, rhs);
        case '*':
            return multiply(lhs, rhs);
        case '/':
            return divide(lhs, rhs);
        case '%':
            return modulo(lhs, rhs);
        default:
            throw std::invalid_argument("not a valid operation");
    }
}

[[deprecated("This function is only here to make the alf tests happy")]]
int calc(std::istream & in) {
    int firstNumber = readNumberFromStream(in);
    char op = readOperatorFromStream(in);
    int secondNumber = readNumberFromStream(in);

    return calc(firstNumber, secondNumber, op);
}

