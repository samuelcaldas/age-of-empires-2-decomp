#include <cassert>
#include <iostream>
#include <string>

static int ensure_obj_calls = 0;
static int kick_calls = 0;
static int build_calls = 0;
static int packet_begin_calls = 0;
static int tag_calls = 0;
static int append_calls = 0;
static int packet_end_calls = 0;
static void *mock_obj = (void *)0x9999;
static short build_args[5];
static unsigned char captured_buf[64];
static unsigned char captured_tag[16];

static unsigned short read_u16(const unsigned char *data) {
    return (unsigned short)(data[0] | (data[1] << 8));
}

unsigned int D_392BB0[4] = {0xAAAA, 0xBBBB, 0xCCCC, 0xDDDD};
unsigned short D_00CA158C = 0;
unsigned short D_00CA158E = 0;

extern "C" {
void *func_123908(void *arg) {
    ensure_obj_calls++;
    return mock_obj;
}

void func_102C88(void *buffer, int a1, int a2, int a3, int a4, int a5) {
    build_calls++;
    build_args[0] = a1;
    build_args[1] = a2;
    build_args[2] = a3;
    build_args[3] = a4;
    build_args[4] = a5;
    for (int i = 0; i < 64; ++i) {
        ((unsigned char *)buffer)[i] = 0xFF;
    }
}
void *func_104448(void *obj, int a1, int a2, int a3) {
    packet_begin_calls++;
    assert(a1 == 0 && a2 == 0 && a3 == 0);
    return obj;
}
void *func_1045E8(void *obj, void *tag) {
    tag_calls++;
    for (int i = 0; i < 16; ++i) captured_tag[i] = ((unsigned char *)tag)[i];
    return obj;
}
void *func_104890(void *obj, void *data, int count) {
    append_calls++;
    assert(count == 8);
    for (int i = 0; i < 64; ++i) captured_buf[i] = ((unsigned char *)data)[i];
    return obj;
}
void *func_104600(void *obj) { packet_end_calls++; return obj; }
void func_104FA0(void *obj) { kick_calls++; assert(obj == 0); }

void *func_0021E370(void *obj, short s5, short s4, short s3, short s2,
                    short s1, short s0, short s7);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];
    ensure_obj_calls = 0;
    kick_calls = 0;
    build_calls = 0;
    packet_begin_calls = 0;
    tag_calls = 0;
    append_calls = 0;
    packet_end_calls = 0;
    D_00CA158C = 0;
    D_00CA158E = 0;

    if (test_case == "0") {
        // Standard call: sets screen center and kicks DMA
        void *res = func_0021E370(mock_obj, 0x5800, 0x123, 0x1A80, -2,
                                   0x3800, -3, 4);
        assert(res == mock_obj);
        assert(kick_calls == 1);
        assert(build_calls == 1 && packet_begin_calls == 1 && tag_calls == 1);
        assert(append_calls == 1 && packet_end_calls == 1);
        assert(build_args[0] == 0x123 && build_args[1] == 0x1A80);
        assert(build_args[2] == -2 && build_args[3] == -3 && build_args[4] == 4);
        assert(read_u16(captured_buf + 0) == 0xFE0B);
        assert(captured_buf[2] == 0xEA && captured_buf[3] == 0xE3);
        assert(read_u16(captured_buf + 16) == 0xFE07);
        assert(read_u16(captured_tag + 0) == 0xAAAA);
        assert(read_u16(captured_tag + 4) == 0xBBBB);
        assert(read_u16(captured_tag + 8) == 0xCCCC);
        assert(read_u16(captured_tag + 12) == 0xDDDD);
        assert(D_00CA158C == (unsigned short)0x1A80);
        assert(D_00CA158E == (unsigned short)-2);
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        // Null object allocates packet
        void *res = func_0021E370(nullptr, 0, 0, 800, 600, 0x5000, 2, 2);
        assert(res == mock_obj);
        assert(ensure_obj_calls == 1);
        assert(kick_calls == 1);
        assert(D_00CA158C == 800);
        assert(D_00CA158E == 600);
        std::cout << "PASS case 1\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
