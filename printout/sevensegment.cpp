#include <ostream>
#include <vector>
#include <functional>

namespace RenderedDigit {
    const int amount_of_lines = 5;
    const int length_of_line = 3;

    const std::vector<std::string> minus = {
            "   ",
            "   ",
            "---",
            "   ",
            "   "
    };
    const std::vector<std::string> zero = {
            " - ",
            "| |",
            "   ",
            "| |",
            " - "
    };
    const std::vector<std::string> one = {
            "   ",
            "  |",
            "   ",
            "  |",
            "   "
    };
    const std::vector<std::string> two = {
            " - ",
            "  |",
            " - ",
            "|  ",
            " - "
    };
    const std::vector<std::string> three = {
            " - ",
            "  |",
            " - ",
            "  |",
            " - "
    };
    const std::vector<std::string> four = {
            "   ",
            "| |",
            " - ",
            "  |",
            "   "
    };
    const std::vector<std::string> five = {
            " - ",
            "|  ",
            " - ",
            "  |",
            " - "
    };
    const std::vector<std::string> six = {
            " - ",
            "|  ",
            " - ",
            "| |",
            " - "
    };
    const std::vector<std::string> seven = {
            " - ",
            "  |",
            "   ",
            "  |",
            "   "
    };
    const std::vector<std::string> eight = {
            " - ",
            "| |",
            " - ",
            "| |",
            " - "
    };
    const std::vector<std::string> nine = {
            " - ",
            "| |",
            " - ",
            "  |",
            " - "
    };
    const std::vector<std::string> big_e = {
            "---",
            "|  ",
            "|- ",
            "|  ",
            "---"
    };
    const std::vector<std::string> small_r = {
            "   ",
            "   ",
            " --",
            "|  ",
            "|  "
    };
    const std::vector<std::string> small_o = {
            "   ",
            "   ",
            " - ",
            "| |",
            " - "
    };
}

std::vector<std::string> resolve7SectorDigit(char digit) {
    switch (digit) {
        case '-':
            return RenderedDigit::minus;
        case '0':
            return RenderedDigit::zero;
        case '1':
            return RenderedDigit::one;
        case '2':
            return RenderedDigit::two;
        case '3':
            return RenderedDigit::three;
        case '4':
            return RenderedDigit::four;
        case '5':
            return RenderedDigit::five;
        case '6':
            return RenderedDigit::six;
        case '7':
            return RenderedDigit::seven;
        case '8':
            return RenderedDigit::eight;
        case '9':
            return RenderedDigit::nine;
        case 'E':
            return RenderedDigit::big_e;
        case 'r':
            return RenderedDigit::small_r;
        case 'o':
            return RenderedDigit::small_o;
        default:
            return RenderedDigit::zero;
    }
}

void printLineBreak(std::ostream &out) {
    out << std::endl;
}

void repeat(int times, const std::function<void(int)> &executable) {
    for (size_t i = 0; i < times; i++) {
        executable(i);
    }
}

void printVector(const std::vector<std::vector<std::string>> &vector, std::ostream &out) {
    repeat(RenderedDigit::amount_of_lines, [&vector, &out](auto index) {
        for_each(cbegin(vector), cend(vector), [&index, &out](auto digit) {
            out << digit.at(index);
        });
        printLineBreak(out);
    });
}

// takes a const string reference and builds the corresponding 7 digit sign representation
std::vector<std::vector<std::string>> buildSignVectorRepresentation(const std::string &number) {
    std::vector<std::vector<std::string>> digitsInSigns{};
    for_each(cbegin(number), cend(number), [&digitsInSigns](auto singleChar) {
        digitsInSigns.push_back(resolve7SectorDigit(singleChar));
    });
    return digitsInSigns;
}

void printFromString(const std::string &text, std::ostream &out) {
    printVector(buildSignVectorRepresentation(text), out);
}

void printLargeDigit(int i, std::ostream &out) {
    printFromString(std::to_string(i), out);
}

void printError(std::ostream &out) {
    printFromString("Error", out);
}