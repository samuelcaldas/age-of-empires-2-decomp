#include "trade_action_helper_2181F0_fixture.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int test_case = std::atoi(argv[1]);
    if (test_case <= 5) test_cases_basic(test_case);
    else if (test_case <= 9) test_cases_callbacks(test_case);
    else if (test_case <= 12) test_cases_mutations(test_case);
    else if (test_case == 13) test_cases_wrap(test_case);
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
