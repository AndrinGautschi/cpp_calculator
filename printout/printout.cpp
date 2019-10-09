#include <ostream>
#include <vector>
#include <functional>
#include "number.h"

std::vector<std::string> resolve7SectorDigitByInt(int digit) {
    switch (digit) {
        case -1:
            return number::minus;
        case 0:
            return number::zero;
        case 1:
            return number::one;
        case 2:
            return number::two;
        case 3:
            return number::three;
        case 4:
            return number::four;
        case 5:
            return number::five;
        case 6:
            return number::six;
        case 7:
            return number::seven;
        case 8:
            return number::eight;
        case 9:
            return number::nine;
        default:
            return number::zero;
    }
}

int resolveIntFromChar(char numericChar) {
    if (numericChar == '-') return -1;
    return numericChar - '0';
}

void printDigitLine(const std::string &line, std::ostream &out) {
    for_each(cbegin(line), cend(line), [&out](auto singleChar) {
        out << singleChar;
    });
}

void printLineBreak(std::ostream &out) {
    out << std::endl;
}

void printLargeNumber(int i, std::ostream &out) {
    auto digit = resolve7SectorDigitByInt(i);
    for_each(cbegin(digit), cend(digit), [&out](auto lineVector) {
        printDigitLine(lineVector, out);
        printLineBreak(out);
    });
}

void repeat(int times, const std::function<void(int)> &executable) {
    for (size_t i = 0; i < times; i++) {
        executable(i);
    }
}

std::vector<std::vector<std::string>> buildSignVectorRepresentation(const std::string& number) {
    std::vector<std::vector<std::string>> digitsInSigns{};
    // resolve for each digit the appropriate 7digitSign and store it in the digitsInSigns vector
    for_each(cbegin(number), cend(number), [&digitsInSigns](auto singleChar) {
        digitsInSigns.push_back(resolve7SectorDigitByInt(resolveIntFromChar(singleChar)));
    });
    return digitsInSigns;
}

void printMultipleLargeDigits(int i, std::ostream &out) {
    const auto numberAsString = std::to_string(i);
    const auto digitsInSigns = buildSignVectorRepresentation(numberAsString);

    repeat(number::amount_of_lines, [&digitsInSigns, &out](auto index) {
        for_each(cbegin(digitsInSigns), cend(digitsInSigns), [&index, &out](auto digit) {
            printDigitLine(digit.at(index), out);
        });
        printLineBreak(out);
    });
}

void printLargeDigit(int i, std::ostream &out) {
    if (i <= 9 && i >= 0) {
        printLargeNumber(i, out);
    } else {
        printMultipleLargeDigits(i, out);
    }
}