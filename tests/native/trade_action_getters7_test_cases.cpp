#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
#include <vector>

void run_getters7_test_part1(int test_case, std::vector<char> &storage);
void run_getters7_test_part2(int test_case, std::vector<char> &storage);

void run_getters7_test(int test_case, std::vector<char> &storage) {
    if (test_case <= 9) {
        run_getters7_test_part1(test_case, storage);
    } else {
        run_getters7_test_part2(test_case, storage);
    }
}
