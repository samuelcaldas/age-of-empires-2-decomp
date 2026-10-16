#include <cassert>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

extern "C" int func_002B61F0(void *self, int index);

namespace {
const int TABLE_START_INDEX = 0x858 / sizeof(int);
const int TABLE_SIZE = 239;
const int INPUT_INDICES[] = {INT_MIN, -1, 0, 238, 239, INT_MAX};
const int EXPECTED_VALUES[] = {-1, -1, 5, 2385, -1, -1};
static_assert(sizeof(int) == 4, "The PS2 getter reads 32-bit fields");

/** Create aligned storage with distinct entries and poisoned adjacent fields. */
std::vector<int> create_storage() {
    std::vector<int> storage(TABLE_START_INDEX + TABLE_SIZE + 1, -927);
    for (int index = 0; index < TABLE_SIZE; ++index) {
        storage[TABLE_START_INDEX + index] = index * 10 + 5;
    }
    return storage;
}

/** Check one signed-index boundary and reject all writes to the object. */
void verify_case(int case_number) {
    assert(case_number >= 0 && case_number < 6);
    std::vector<int> storage = create_storage();
    const std::vector<int> original_storage = storage;
    int result = func_002B61F0(storage.data(), INPUT_INDICES[case_number]);
    assert(result == EXPECTED_VALUES[case_number]);
    assert(storage == original_storage);
}
}

/** Run the isolated native case selected by pytest. */
int main(int argument_count, char **arguments) {
    if (argument_count != 2) {
        std::cerr << "Usage: " << arguments[0] << " <case>\n";
        return 1;
    }
    verify_case(std::stoi(arguments[1]));
    return 0;
}
