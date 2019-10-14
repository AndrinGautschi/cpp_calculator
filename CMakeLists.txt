cmake_minimum_required(VERSION 3.14)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

# specify library calculator
add_library(calculator_lib
        calculator/calc.cpp
        printout/sevensegment.cpp
        pocketcalculator/pocketcalculator.cpp)

# build calculator executable
add_executable(calculator main.cpp)
target_link_libraries(calculator calculator_lib)

# build calculator test executable
include_directories(../libs/cute)
add_executable(calculator_test test/calculatorTest.cpp)
target_link_libraries(calculator_test calculator_lib)

# build printout test executable
include_directories(../libs/cute)
add_executable(printout_test test/printoutTest.cpp)
target_link_libraries(printout_test calculator_lib)