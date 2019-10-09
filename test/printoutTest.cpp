#include <cstdlib>
#include <stdexcept>
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "../printout/printout.h"

void testPrintLargeDigitZero() {
    std::ostringstream output{};
    printLargeDigit(0, output);
    ASSERT_EQUAL(" - \n"
                 "| |\n"
                 "   \n"
                 "| |\n"
                 " - \n", output.str());
}

void testPrintLargeDigitOneThreeFour() {
    std::ostringstream output{};
    printLargeDigit(134, output);
    ASSERT_EQUAL("    -    \n"
                 "  |  || |\n"
                 "    -  - \n"
                 "  |  |  |\n"
                 "    -    \n", output.str());
}

bool runAllTests(int argc, char const *argv[]) {
    cute::suite s{};
    s.push_back(CUTE(testPrintLargeDigitZero));
    s.push_back(CUTE(testPrintLargeDigitOneThreeFour));
    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
    auto runner{cute::makeRunner(lis, argc, argv)};
    bool success = runner(s, "AllTests");
    return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
