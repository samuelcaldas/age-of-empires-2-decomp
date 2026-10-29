#include <cassert>
#include <iostream>
#include <string>

struct ZoneStubLayout {
    char pad_base[0x8EAE];
    short f_8EAE;
    short f_8EB0;
    short f_8EB2;
    short f_8EB4;
    short f_8EB6;
    char pad_8EB8[0x15];
    unsigned char f_8ECD;
    unsigned char f_8ECE;
};

static int g_calls_1c98a0 = 0;
static int g_calls_32f090 = 0;
static int g_calls_1cf9b0 = 0;
static int g_calls_32fbd0 = 0;

extern "C" {
void func_1C98A0(void *a0, void *a1, void *a2) { g_calls_1c98a0++; }
void func_32F090(void *a0) { g_calls_32f090++; }
void func_1CF9B0(void *a0, void *a1, void *a2, int a3, int a4,
                 short a5, short a6, void *a7, long long sp0, long long sp8) {
    g_calls_1cf9b0++;
}
void func_32FBD0(void *a0) { g_calls_32fbd0++; }

void func_001C97A0(void);
void func_001C97B0(void *self, unsigned char val);
void func_001C97C0(void *self, unsigned char val);
void func_001C97D0(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    std::string test_case = argv[1];

    if (test_case == "stubs") {
        func_001C97A0();
        char buffer[0x10000];
        ZoneStubLayout *layout = (ZoneStubLayout *)buffer;
        func_001C97B0(buffer, 0x42);
        assert(layout->f_8ECD == 0x42);
        func_001C97C0(buffer, 0x84);
        assert(layout->f_8ECE == 0x84);
        std::cout << "PASS stubs\n";
        return 0;
    }

    if (test_case == "dispatch") {
        char dummy[16];
        func_001C97D0(dummy, dummy, dummy, dummy, (void *)10, (void *)20);
        assert(g_calls_1c98a0 == 1);
        assert(g_calls_32f090 == 1);
        assert(g_calls_1cf9b0 == 1);
        assert(g_calls_32fbd0 == 1);
        std::cout << "PASS dispatch\n";
        return 0;
    }

    return 2;
}
