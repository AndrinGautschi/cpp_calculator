cmake_minimum_required(VERSION 3.14)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

# specify library calculator
add_library(calculator_lib
        calc.cpp
        sevensegment.cpp
        pocketcalculator.cpp)

# build calculator executable
add_executable(calculator main.cpp)
target_link_libraries(calculator calculator_lib)

# build calculator test executable
include_directories(../libs/cute)
add_executable(calculator_test test/calculatorTest.cpp)
target_link_libraries(calculator_test calculator_lib)