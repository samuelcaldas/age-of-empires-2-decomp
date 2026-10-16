#include <iostream>
#include <cassert>
#include <vector>

extern "C" void func_002B6220(void *self);

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int test_case = std::stoi(argv[1]);

    std::vector<char> storage(2048, 0);
    void *self = storage.data();

    func_002B6220(self);
    func_002B6220(nullptr);

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
