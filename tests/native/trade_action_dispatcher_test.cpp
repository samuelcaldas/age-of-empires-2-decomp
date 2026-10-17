#include <iostream>
#include <cassert>
#include <vector>
#include "trade_action_dispatcher_test_support.h"

void run_dispatcher_cases_part1(int test_case, std::vector<char> &storage);
void run_dispatcher_cases_part2(int test_case, std::vector<char> &storage);

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int test_case = std::stoi(argv[1]);

    const size_t buf_size = 32768;
    std::vector<char> storage(buf_size, 0);

    if (test_case <= 6) {
        run_dispatcher_cases_part1(test_case, storage);
    } else {
        run_dispatcher_cases_part2(test_case, storage);
    }

    std::cout << "DISPATCHER TEST " << test_case << " PASSED\n";
    return 0;
}
