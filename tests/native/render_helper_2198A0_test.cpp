#include <cassert>
#include <cstring>
#include <iostream>

static int c1f6e50_calls = 0;
static int last_1f6e50_arg0 = -1;
static int last_1f6e50_arg1 = -1;
static void *last_1f6e50_buffer = nullptr;
static int last_1f6e50_size = -1;

static int c2195a0_calls = 0;
static void *last_2195a0_self = nullptr;
static short last_2195a0_arg1 = -1;
static void *last_2195a0_buffer = nullptr;
static int last_2195a0_arg3 = -1;
static int last_2195a0_arg4 = -1;
static int mock_2195a0_ret = 42;

extern "C" {
int func_002198A0(void *self, short arg1, int arg2, int arg3, int arg4);

int func_001F6E50(int arg0, int arg1, void *buffer, int buf_size) {
    c1f6e50_calls++;
    last_1f6e50_arg0 = arg0;
    last_1f6e50_arg1 = arg1;
    last_1f6e50_buffer = buffer;
    last_1f6e50_size = buf_size;
    std::strcpy((char *)buffer, "formatted_msg");
    return 1;
}

int func_002195A0(void *self, short arg1, void *buffer, int arg3, int arg4) {
    c2195a0_calls++;
    last_2195a0_self = self;
    last_2195a0_arg1 = arg1;
    last_2195a0_buffer = buffer;
    last_2195a0_arg3 = arg3;
    last_2195a0_arg4 = arg4;
    return mock_2195a0_ret;
}
}

static void reset_mocks() {
    c1f6e50_calls = 0;
    last_1f6e50_arg0 = -1;
    last_1f6e50_arg1 = -1;
    last_1f6e50_buffer = nullptr;
    last_1f6e50_size = -1;
    c2195a0_calls = 0;
    last_2195a0_self = nullptr;
    last_2195a0_arg1 = -1;
    last_2195a0_buffer = nullptr;
    last_2195a0_arg3 = -1;
    last_2195a0_arg4 = -1;
    mock_2195a0_ret = 42;
}

void test_case_buffer_formatting_and_dispatch() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    mock_2195a0_ret = 999;
    int res = func_002198A0(obj, 10, 20, 30, 40);
    assert(res == 999);

    assert(c1f6e50_calls == 1);
    assert(last_1f6e50_arg0 == (int)(unsigned long)obj);
    assert(last_1f6e50_arg1 == 20);
    assert(last_1f6e50_size == 256);
    assert(last_1f6e50_buffer != nullptr);

    assert(c2195a0_calls == 1);
    assert(last_2195a0_self == obj);
    assert(last_2195a0_arg1 == 10);
    assert(last_2195a0_buffer == last_1f6e50_buffer);
    assert(last_2195a0_arg3 == 30);
    assert(last_2195a0_arg4 == 40);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_buffer_formatting_and_dispatch();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
