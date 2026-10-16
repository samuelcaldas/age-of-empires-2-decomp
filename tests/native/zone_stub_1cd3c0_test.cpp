#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CD3C0(void *self);
}

static void test_stub_returns_zero_with_null() {
    int ret = func_001CD3C0(nullptr);
    assert(ret == 0);
}

static void test_stub_returns_zero_with_pointer() {
    char dummy[64];
    std::memset(dummy, 0xAA, sizeof(dummy));
    int ret = func_001CD3C0(dummy);
    assert(ret == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "null_pointer") {
        test_stub_returns_zero_with_null();
    } else if (argc > 1 && std::string(argv[1]) == "valid_pointer") {
        test_stub_returns_zero_with_pointer();
    } else {
        test_stub_returns_zero_with_null();
        test_stub_returns_zero_with_pointer();
    }
    return 0;
}
