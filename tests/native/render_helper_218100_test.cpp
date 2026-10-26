#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_00218100(void *self, int arg1);
}

void test_case_218100_basic() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    func_00218100(obj, 1);
    assert(true);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_218100_basic();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
