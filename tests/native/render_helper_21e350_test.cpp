#include <cassert>
#include <iostream>
#include <string>

extern "C" {
int func_0021E350(unsigned short val);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];

    if (test_case == "0") {
        // Base case: val = 0 -> 0x7C000
        int res = func_0021E350(0);
        assert(res == 0x7C000);
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        // Mask test: bits outside 0x1F0 are masked out
        // 0x000F & 0x1F0 == 0 -> should equal 0x7C000
        int res = func_0021E350(0x000F);
        assert(res == 0x7C000);
        std::cout << "PASS case 1\n";
        return 0;
    }

    if (test_case == "2") {
        // Non-zero masked: val = 0x10 -> (0x10 << 4) = 0x100 -> 0x7C100
        int res = func_0021E350(0x0010);
        assert(res == 0x7C100);
        std::cout << "PASS case 2\n";
        return 0;
    }

    if (test_case == "3") {
        // Maximum masked value: val = 0x1F0 -> (0x1F0 << 4) = 0x1F00 -> 0x7DF00
        int res = func_0021E350(0x01F0);
        assert(res == 0x7DF00);
        std::cout << "PASS case 3\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
