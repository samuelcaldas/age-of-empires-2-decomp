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

int g_calls_262570 = 0;
int g_result_262570 = 1;
int func_262570(void *a0, int a1, int a2, int a3, int a4, int a5, int a6) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6;
    ++g_calls_262570;
    return g_result_262570;
}

int g_calls_1d0350 = 0;
float g_coords_1d0350[4][2];
int func_001D0350(void *a0, short *out_x, short *out_y, float x, float y) {
    (void)a0;
    if (g_calls_1d0350 < 4) {
        g_coords_1d0350[g_calls_1d0350][0] = x;
        g_coords_1d0350[g_calls_1d0350][1] = y;
    }
    if (out_x) *out_x = 10;
    if (out_y) *out_y = 20;
    ++g_calls_1d0350;
    return 1;
}

int g_calls_326f60 = 0;
int func_326F60(void *a0, int a1, int a2, short c1, short c2, short c3, short c4, short c5) {
    (void)a0; (void)a1; (void)a2;
    (void)c1; (void)c2; (void)c3; (void)c4; (void)c5;
    ++g_calls_326f60;
    return 1;
}

void *D_004E3180 = 0;
void *D_4E3400 = 0;
void *D_4E3408 = 0;
}

int main() {
    // -------------------------------------------------------------
    // Behavioral test for func_001C8780 (4-corner bounding projection)
    // -------------------------------------------------------------
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

    assert(ret == 1);
    assert(out0 != -1);
    assert(out1 != -1);
    assert(out2 != -1);
    assert(out3 != -1);
    assert(out4 != -1);
    assert(out5 != -1);
    assert(out6 != -1);
    assert(out7 != -1);

    // -------------------------------------------------------------
    // Behavioral tests for func_001C8A50 (MapZone ray & corner projection)
    // -------------------------------------------------------------
    char zone_buf[0x200];
    std::memset(zone_buf, 0, sizeof(zone_buf));
    char internal_obj[0x100];
    std::memset(internal_obj, 0, sizeof(internal_obj));

    char singleton_buf[0x500];
    std::memset(singleton_buf, 0, sizeof(singleton_buf));
    char sub_obj[0x100];
    std::memset(sub_obj, 0, sizeof(sub_obj));
    *reinterpret_cast<void **>(singleton_buf + 0x404) = sub_obj;
    *reinterpret_cast<void **>(sub_obj + 0x3C) = ctx_buf;
    D_004E3180 = singleton_buf;

    // Test 1: *(this + 0x10) == 0 must early return without invoking helpers
    *reinterpret_cast<void **>(zone_buf + 0x10) = 0;
    g_calls_262570 = 0;
    g_calls_1d0350 = 0;
    g_calls_326f60 = 0;
    func_001C8A50(zone_buf);
    assert(g_calls_262570 == 0);
    assert(g_calls_1d0350 == 0);
    assert(g_calls_326f60 == 0);

    // Test 2: *(this + 0x10) != 0, but func_262570 returns 0 (ray validation fail) -> early return
    *reinterpret_cast<void **>(zone_buf + 0x10) = internal_obj;
    g_result_262570 = 0;
    g_calls_262570 = 0;
    g_calls_1d0350 = 0;
    g_calls_326f60 = 0;
    func_001C8A50(zone_buf);
    assert(g_calls_262570 == 1);
    assert(g_calls_1d0350 == 0);
    assert(g_calls_326f60 == 0);

    // Test 3: *(this + 0x10) != 0 and func_262570 returns 1 -> projects 4 corners and calls rasterizer
    g_result_262570 = 1;
    g_calls_262570 = 0;
    g_calls_1d0350 = 0;
    g_calls_326f60 = 0;
    *reinterpret_cast<float *>(zone_buf + 0x94) = 2.0f; // rx
    *reinterpret_cast<float *>(zone_buf + 0x98) = 3.0f; // ry

    func_001C8A50(zone_buf);
    assert(g_calls_262570 == 1);
    // Verified original makes exactly 4 calls to func_001D0350 for the 4 corners
    assert(g_calls_1d0350 == 4);
    assert(g_calls_326f60 == 1);

    // Verified 4-corner coordinate order: (+rx, -ry), (+rx, +ry), (-rx, +ry), (-rx, -ry)
    assert(g_coords_1d0350[0][0] == 2.0f && g_coords_1d0350[0][1] == -3.0f);
    assert(g_coords_1d0350[1][0] == 2.0f && g_coords_1d0350[1][1] == 3.0f);
    assert(g_coords_1d0350[2][0] == -2.0f && g_coords_1d0350[2][1] == 3.0f);
    assert(g_coords_1d0350[3][0] == -2.0f && g_coords_1d0350[3][1] == -3.0f);

    return 0;
}
