#ifndef CALCULATOR_NUMBER_H
#define CALCULATOR_NUMBER_H

#include <vector>
#include <string>

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

#endif //CALCULATOR_NUMBER_H
