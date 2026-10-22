#include <cassert>
#include <cstdint>
#include <cstring>
#include "zone_path_queries.h"

struct Func262570Args {
    void *internal_obj;
    int a5;
    int a6;
    int py1;
    int target1;
    int py2;
    int target2;
    int mode;
    float *px;
    int ten;
};

struct Func326F60Args {
    void *obj;
    int one;
    int target_info;
    short c1_x;
    short c1_y;
    short c2_x;
    short c2_y;
    short c3_x;
    short c3_y;
    short c4_x;
    short c4_y;
    int eleven;
    unsigned char flag;
    int d4e3400;
};

enum CallEvent {
    CALL_EVENT_FUNC_262570,
    CALL_EVENT_FUNC_001D0350,
    CALL_EVENT_FUNC_326F60
};

CallEvent g_call_events[6];
int g_call_event_count = 0;

void record_call_event(CallEvent event) {
    assert(g_call_event_count < 6);
    g_call_events[g_call_event_count++] = event;
}

void reset_call_events() {
    g_call_event_count = 0;
}

void assert_call_events(const CallEvent *expected, int expected_count) {
    assert(g_call_event_count == expected_count);
    for (int i = 0; i < expected_count; ++i) {
        assert(g_call_events[i] == expected[i]);
    }
}

const CallEvent g_query_only_trace[] = {CALL_EVENT_FUNC_262570};
const CallEvent g_full_projection_trace[] = {
    CALL_EVENT_FUNC_262570,
    CALL_EVENT_FUNC_001D0350,
    CALL_EVENT_FUNC_001D0350,
    CALL_EVENT_FUNC_001D0350,
    CALL_EVENT_FUNC_001D0350,
    CALL_EVENT_FUNC_326F60
};

static_assert(sizeof(float) == sizeof(std::uint32_t), "requires 32-bit floats");

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
Func262570Args g_args_262570;
int func_262570(
    void *internal_obj,
    int a5,
    int a6,
    long long py1,
    long long target1,
    long long py2,
    long long target2,
    int mode,
    float *px,
    int ten
) {
    record_call_event(CALL_EVENT_FUNC_262570);
    ++g_calls_262570;
    g_args_262570.internal_obj = internal_obj;
    g_args_262570.a5 = a5;
    g_args_262570.a6 = a6;
    g_args_262570.py1 = static_cast<int>(py1);
    g_args_262570.target1 = static_cast<int>(target1);
    g_args_262570.py2 = static_cast<int>(py2);
    g_args_262570.target2 = static_cast<int>(target2);
    g_args_262570.mode = mode;
    g_args_262570.px = px;
    g_args_262570.ten = ten;
    return 1;
}

int g_calls_1d0350 = 0;
float g_coords_1d0350[4][2];
float g_z_1d0350[4];
std::uint32_t g_z_bits_1d0350[4];
short *g_out_x_ptrs_1d0350[4];
short *g_out_y_ptrs_1d0350[4];
void *g_ctx_1d0350[4];
int g_extra_1d0350[4][2];
int func_001D0350(
    void *ctx,
    short *out_x,
    short *out_y,
    float x,
    float y,
    float z,
    int py,
    int target_info
) {
    record_call_event(CALL_EVENT_FUNC_001D0350);
    if (g_calls_1d0350 < 4) {
        g_ctx_1d0350[g_calls_1d0350] = ctx;
        g_coords_1d0350[g_calls_1d0350][0] = x;
        g_coords_1d0350[g_calls_1d0350][1] = y;
        g_z_1d0350[g_calls_1d0350] = z;
        std::memcpy(&g_z_bits_1d0350[g_calls_1d0350], &z, sizeof(z));
        g_out_x_ptrs_1d0350[g_calls_1d0350] = out_x;
        g_out_y_ptrs_1d0350[g_calls_1d0350] = out_y;
        g_extra_1d0350[g_calls_1d0350][0] = py;
        g_extra_1d0350[g_calls_1d0350][1] = target_info;
    }
    if (out_x) *out_x = static_cast<short>(10 + g_calls_1d0350 * 2);
    if (out_y) *out_y = static_cast<short>(20 + g_calls_1d0350 * 2);
    ++g_calls_1d0350;
    return 1;
}

int g_calls_326f60 = 0;
Func326F60Args g_args_326f60;
int func_326F60(
    void *obj,
    int one,
    long long target_info,
    short c1_x,
    short c1_y,
    short c2_x,
    short c2_y,
    short c3_x,
    short c3_y,
    short c4_x,
    short c4_y,
    int eleven,
    unsigned char flag,
    int d4e3400
) {
    record_call_event(CALL_EVENT_FUNC_326F60);
    ++g_calls_326f60;
    g_args_326f60.obj = obj;
    g_args_326f60.one = one;
    g_args_326f60.target_info = static_cast<int>(target_info);
    g_args_326f60.c1_x = c1_x;
    g_args_326f60.c1_y = c1_y;
    g_args_326f60.c2_x = c2_x;
    g_args_326f60.c2_y = c2_y;
    g_args_326f60.c3_x = c3_x;
    g_args_326f60.c3_y = c3_y;
    g_args_326f60.c4_x = c4_x;
    g_args_326f60.c4_y = c4_y;
    g_args_326f60.eleven = eleven;
    g_args_326f60.flag = flag;
    g_args_326f60.d4e3400 = d4e3400;
    return 1;
}

void *D_004E3180 = reinterpret_cast<void *>(0x4E3180);
void *D_4E3400 = reinterpret_cast<void *>(0x4E3400);
void *D_4E3408 = reinterpret_cast<void *>(0x4E3408);
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
    reset_call_events();
    func_001C8A50(zone_buf);
    assert(g_calls_262570 == 0);
    assert(g_calls_1d0350 == 0);
    assert(g_calls_326f60 == 0);
    assert(g_call_event_count == 0);

    // Test 2: *(this + 0x10) != 0, but a7 == 0 -> calls func_262570, then early return
    *reinterpret_cast<void **>(zone_buf + 0x10) = internal_obj;
    g_calls_262570 = 0;
    g_calls_1d0350 = 0;
    g_calls_326f60 = 0;
    reset_call_events();
    float test_x = 5.0f;
    float test_y = 7.0f;
    void *target_info_val = reinterpret_cast<void *>(0x12345);

    func_001C8A50(zone_buf, &test_x, &test_y, target_info_val, 1, 2, 3, 0, 77);
    assert(g_calls_262570 == 1);
    assert(g_calls_1d0350 == 0);
    assert(g_calls_326f60 == 0);
    assert_call_events(g_query_only_trace, 1);
    // Verify argument forwarding to func_262570
    assert(g_args_262570.internal_obj == internal_obj);
    assert(g_args_262570.a5 == 2);
    assert(g_args_262570.a6 == 3);
    assert(g_args_262570.py1 == static_cast<short>(reinterpret_cast<int>(&test_y)));
    assert(g_args_262570.target1 == 0x2345);
    assert(g_args_262570.py2 == static_cast<short>(reinterpret_cast<int>(&test_y)));
    assert(g_args_262570.target2 == 0x2345);
    assert(g_args_262570.mode == 1);
    assert(g_args_262570.px == &test_x);
    assert(g_args_262570.ten == 10);

    // Test 3: *(this + 0x10) != 0 and a7 != 0 -> projects all 4 corners and calls rasterizer
    g_calls_262570 = 0;
    g_calls_1d0350 = 0;
    g_calls_326f60 = 0;
    reset_call_events();
    *reinterpret_cast<float *>(zone_buf + 0x94) = 2.0f; // rx
    *reinterpret_cast<float *>(zone_buf + 0x98) = 3.0f; // ry

    func_001C8A50(zone_buf, &test_x, &test_y, target_info_val, 1, 2, 3, 1, 77);
    assert(g_calls_262570 == 1);
    // Verified original makes exactly 4 calls to func_001D0350 for the 4 corners
    assert(g_calls_1d0350 == 4);
    assert(g_calls_326f60 == 1);
    assert_call_events(g_full_projection_trace, 6);

    // Verified 4-corner coordinate sequence and extra argument forwarding to func_001D0350
    assert(g_coords_1d0350[0][0] == 2.0f && g_coords_1d0350[0][1] == -3.0f);
    assert(g_coords_1d0350[1][0] == 2.0f && g_coords_1d0350[1][1] == 3.0f);
    assert(g_coords_1d0350[2][0] == -2.0f && g_coords_1d0350[2][1] == 3.0f);
    assert(g_coords_1d0350[3][0] == -2.0f && g_coords_1d0350[3][1] == -3.0f);

    for (int i = 0; i < 4; ++i) {
        assert(g_ctx_1d0350[i] == ctx_buf);
        assert(g_z_1d0350[i] == 0.0f);
        assert(g_z_bits_1d0350[i] == 0x00000000u);
        assert(g_out_x_ptrs_1d0350[i] != nullptr);
        assert(g_out_y_ptrs_1d0350[i] != nullptr);
        assert(g_out_x_ptrs_1d0350[i] != g_out_y_ptrs_1d0350[i]);
        assert(g_extra_1d0350[i][0] == reinterpret_cast<int>(&test_y));
        assert(g_extra_1d0350[i][1] == reinterpret_cast<int>(target_info_val));
    }

    // Verify all 4 corner output pointer pairs point to distinct addresses
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            assert(g_out_x_ptrs_1d0350[i] != g_out_x_ptrs_1d0350[j]);
            assert(g_out_y_ptrs_1d0350[i] != g_out_y_ptrs_1d0350[j]);
        }
    }

    // Cross-axis checks complete pairwise uniqueness without asserting private stack slots.
    for (int x_index = 0; x_index < 4; ++x_index) {
        for (int y_index = 0; y_index < 4; ++y_index) {
            assert(g_out_x_ptrs_1d0350[x_index] != g_out_y_ptrs_1d0350[y_index]);
        }
    }

    // Verify all 14 arguments passed to func_326F60, including all 4 corners!
    assert(g_args_326f60.obj == D_4E3408);
    assert(g_args_326f60.one == 1);
    assert(g_args_326f60.target_info == 0x2345);
    assert(g_args_326f60.c1_x == 10);
    assert(g_args_326f60.c1_y == 20);
    assert(g_args_326f60.c2_x == 12);
    assert(g_args_326f60.c2_y == 22);
    assert(g_args_326f60.c3_x == 14);
    assert(g_args_326f60.c3_y == 24); // Corner 3 y forwarded on stack!
    assert(g_args_326f60.c4_x == 16); // Corner 4 x forwarded on stack!
    assert(g_args_326f60.c4_y == 26); // Corner 4 y forwarded on stack!
    assert(g_args_326f60.eleven == 11);
    assert(g_args_326f60.flag == 77);
    assert(g_args_326f60.d4e3400 == reinterpret_cast<int>(D_4E3400));

    return 0;
}
