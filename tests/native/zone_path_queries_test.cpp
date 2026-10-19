#include <cassert>
#include <cstring>
#include "zone_path_queries.h"

extern "C" {
int func_123350(float val) {
    return static_cast<int>(val);
}
int func_1234E0(float val) {
    (void)val;
    return 1;
}
int func_122058(int a0, int a1) {
    (void)a0; (void)a1;
    return 1;
}
int func_1220B0(int a0, int a1) {
    (void)a0; (void)a1;
    return 1;
}
int func_122690(int a0, int a1) {
    (void)a0; (void)a1;
    return 1;
}
int func_122118(int a0, int a1) {
    (void)a0; (void)a1;
    return 1;
}
int func_122748(int a0) {
    (void)a0;
    return 42;
}
}

int main() {
    MasterInfo master;
    std::memset(&master, 0, sizeof(master));
    master.rx = 1.0f;
    master.ry = 1.0f;

    char map_buf[0x100];
    char ctx_buf[0x9000];
    std::memset(map_buf, 0, sizeof(map_buf));
    std::memset(ctx_buf, 0, sizeof(ctx_buf));
    *reinterpret_cast<void **>(map_buf + 0x3C) = ctx_buf;
    *reinterpret_cast<short *>(ctx_buf + 0x8EB4) = 10;
    *reinterpret_cast<short *>(ctx_buf + 0x8EB2) = 10;

    short out0 = -1, out1 = -1, out2 = -1, out3 = -1;
    short out4 = -1, out5 = -1, out6 = -1, out7 = -1;

    int ret = func_001C8780(&master, map_buf,
                            &out0, &out1, &out2, &out3,
                            &out4, &out5, &out6, &out7,
                            10.0f, 10.0f);

    // Verified original returns status 1 upon completion (ELF 0x1C8A44)
    assert(ret == 1);

    // Verified original writes all 8 output short pointers
    assert(out0 != -1);
    assert(out1 != -1);
    assert(out2 != -1);
    assert(out3 != -1);
    assert(out4 != -1);
    assert(out5 != -1);
    assert(out6 != -1);
    assert(out7 != -1);

    return 0;
}
