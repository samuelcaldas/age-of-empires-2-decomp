#include <cstdint>
#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
    int func_00227ED0(void* a0, void* a1, void* a2, void* a3, void* t0, void* t1);
}

int main() {
    int res = func_00227ED0(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    (void)res;
    return 0;
}
