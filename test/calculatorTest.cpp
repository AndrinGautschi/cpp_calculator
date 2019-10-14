#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "../calculator/calculator.h"

void test_one_plus_one() {
    auto result = calc(1, 1, '+');
    ASSERT_EQUAL(2, result);
}

void test_one_plus_minus_one() {
    auto result = calc(1, -1, '+');
    ASSERT_EQUAL(0, result);
}

void test_one_minus_minus_one() {
    auto result = calc(1, -1, '-');
    ASSERT_EQUAL(2, result);
}

void test_multiply_one_by_minus_one() {
    auto result = calc(1, -1, '*');
    ASSERT_EQUAL(-1, result);
}

void test_multiply_two_by_twenty() {
    auto result = calc(2, 20, '*');
    ASSERT_EQUAL(40, result);
}

void test_divide_twenty_by_two() {
    auto result = calc(20, 2, '/');
    ASSERT_EQUAL(10, result);
}

void test_divide_twenty_by_zero() {
    ASSERT_THROWS(calc(20, 0, '/'), std::invalid_argument);
}

void test_modulo_two_by_two() {
    auto result = calc(2, 2, '%');
    ASSERT_EQUAL(0, result);
}

void test_modulo_two_by_zero() {
    ASSERT_THROWS(calc(2, 0, '%'), std::invalid_argument);
}

bool runAllTests(int argc, char const *argv[]) {
    cute::suite s{};
    s.push_back(CUTE(test_one_plus_one));
    s.push_back(CUTE(test_one_plus_minus_one));
    s.push_back(CUTE(test_one_minus_minus_one));
    s.push_back(CUTE(test_multiply_one_by_minus_one));
    s.push_back(CUTE(test_multiply_two_by_twenty));
    s.push_back(CUTE(test_divide_twenty_by_two));
    s.push_back(CUTE(test_divide_twenty_by_zero));
    s.push_back(CUTE(test_modulo_two_by_two));
    s.push_back(CUTE(test_modulo_two_by_zero));
    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
    auto runner{cute::makeRunner(lis, argc, argv)};
    bool success = runner(s, "AllTests");
    return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
