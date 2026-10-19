#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

struct u128 {
    uint32_t words[4];
};

static std::vector<int> g_call_order;

struct RegWrite {
    int reg;
    uint64_t data;
};
static std::vector<RegWrite> g_writes;

extern "C" {
void *func_0021C990(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *xy_pts, int t2, int t3, int z);
void *func_0021CC90(void *obj, int a1, int a2, int a3, const short *uv_rect, const short *rect, int t2, int t3, int z);

uint32_t D_00392B40[4] = {0x00000000, 0x00000000, 0x0000000E, 0x00000000};
uint16_t D_00CA158C = 640;
uint16_t D_00CA158E = 448;

static int g_alloc_calls = 0;
static char g_allocated_buf[256];
void *func_123908(void *unused) {
    g_alloc_calls++;
    g_call_order.push_back(0);
    return g_allocated_buf;
}

static int g_init_calls = 0;
static int g_init_a1 = -1, g_init_a2 = -1, g_init_a3 = -1;
void *func_104448(void *obj, int a1, int a2, int a3) {
    g_init_calls++;
    g_init_a1 = a1;
    g_init_a2 = a2;
    g_init_a3 = a3;
    g_call_order.push_back(1);
    return obj;
}

static int g_set_tag_calls = 0;
static u128 g_last_tag;
void *func_1045E8(void *obj, u128 tag) {
    g_set_tag_calls++;
    g_last_tag = tag;
    g_call_order.push_back(2);
    return obj;
}

void *func_1046A8(void *obj, int reg, uint64_t data) {
    g_writes.push_back({reg, data});
    g_call_order.push_back(3);
    return obj;
}

static int g_finalize_calls = 0;
void *func_104600(void *obj) {
    g_finalize_calls++;
    g_call_order.push_back(4);
    return obj;
}
}

static void test_func_0021C990_existing_obj() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;
    g_call_order.clear();
    std::memset(&g_last_tag, 0, sizeof(g_last_tag));

    char my_obj[64];
    short uv[4] = {10, 20, 30, 40}; // u=10, v=20, h=30, w=40
    // 4 points (x, y) spaced by 8 bytes (4 shorts: x, y, 0, 0)
    short pts[16] = {
        100, 200, 0, 0,
        150, 200, 0, 0,
        100, 250, 0, 0,
        150, 250, 0, 0
    };

    // t3 = 1 -> sprite mode reg 0x07
    void *ret = func_0021C990(my_obj, 0x11, 2, 0x22, uv, pts, 0x55, 1, 10);
    assert(ret == my_obj);
    assert(g_alloc_calls == 0);
    assert(g_init_calls == 1);
    assert(g_init_a1 == 0 && g_init_a2 == 0 && g_init_a3 == 0);
    assert(g_set_tag_calls == 1);

    // Tag calculation verification
    // low 64 bits = 0x8000 | (0x10004000ULL << 32) | (((0x114ULL | (2 << 6) | (1 << 9))) << 47)
    // 0x114 | (2<<6) | (1<<9) = 0x114 | 0x80 | 0x200 = 0x394
    // 0x394 << 47
    uint64_t v0 = 0x114ULL | (2ULL << 6) | (1ULL << 9);
    uint64_t expected_tag_low = 0x8000ULL | (0x10004000ULL << 32) | (v0 << 47);
    uint32_t exp_word0 = (uint32_t)expected_tag_low;
    uint32_t exp_word1 = (uint32_t)(expected_tag_low >> 32);
    assert(g_last_tag.words[0] == exp_word0);
    assert(g_last_tag.words[1] == exp_word1);
    assert(g_last_tag.words[2] == D_00392B40[2]);
    assert(g_last_tag.words[3] == D_00392B40[3]);

    assert(g_finalize_calls == 1);

    // 10 register writes: 1 (reg 0x07) + 1 (reg 0x01) + 4*(0x03, 0x04)
    assert(g_writes.size() == 10);
    assert(g_writes[0].reg == 0x07);
    assert(g_writes[0].data == 0x11ULL);

    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x22ULL);

    // Vertex 0: u=10, v=20 -> UV = (10<<4) | ((20<<4)<<16) = 160 | (320<<16)
    assert(g_writes[2].reg == 0x03);
    assert(g_writes[2].data == (160ULL | (320ULL << 16)));

    // Center = (640, 448). base_x = (0x800 - 320) << 4 = 1728 << 4 = 27648
    // base_y = (0x800 - 224) << 4 = 1824 << 4 = 29184
    // depth_offset = (-10) << 3 = -80
    // x0 = (100 << 4) + 27648 - 80 = 1600 + 27648 - 80 = 29168
    // y0 = (200 << 4) + 29184 - 80 = 3200 + 29184 - 80 = 32304
    // XYZ0: (0x55ULL << 32) | (29168 & 0xFFFF) | ((32304 & 0xFFFF) << 16)
    uint64_t expected_xyz0 = (0x55ULL << 32) | (29168ULL & 0xFFFF) | ((32304ULL & 0xFFFF) << 16);
    assert(g_writes[3].reg == 0x04);
    assert(g_writes[3].data == expected_xyz0);

    // Call order: 1 (init), 2 (tag), 3..3 (10 writes), 4 (finalize)
    assert(g_call_order.size() == 13);
    assert(g_call_order[0] == 1);
    assert(g_call_order[1] == 2);
    for (int i = 2; i <= 11; ++i) {
        assert(g_call_order[i] == 3);
    }
    assert(g_call_order[12] == 4);

    std::cout << "PASS: test_func_0021C990_existing_obj" << std::endl;
}

static void test_func_0021C990_null_obj_and_mode0() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;
    g_call_order.clear();

    short uv[4] = {0, 0, 16, 16};
    short pts[16] = {
        0, 0, 0, 0,
        16, 0, 0, 0,
        0, 16, 0, 0,
        16, 16, 0, 0
    };

    // t3 = 0 -> sprite mode reg 0x06, null obj -> triggers func_123908
    void *ret = func_0021C990(nullptr, 0x77, 0, 0x88, uv, pts, 0x10, 0, -5);
    assert(ret == g_allocated_buf);
    assert(g_alloc_calls == 1);
    assert(g_writes.size() == 10);
    assert(g_writes[0].reg == 0x06); // reg 0x06 when t3 == 0
    assert(g_writes[0].data == 0x77ULL);
    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x88ULL);

    // Call order starts with 0 (allocation)
    assert(g_call_order[0] == 0);
    assert(g_call_order[1] == 1);
    assert(g_call_order[2] == 2);

    std::cout << "PASS: test_func_0021C990_null_obj_and_mode0" << std::endl;
}

static void test_func_0021CC90() {
    g_alloc_calls = 0;
    g_init_calls = 0;
    g_set_tag_calls = 0;
    g_writes.clear();
    g_finalize_calls = 0;
    g_call_order.clear();

    char my_obj[64];
    short uv[4] = {5, 10, 15, 20};
    short rect[4] = {50, 60, 100, 80}; // x=50, y=60, w=100, h=80

    // t3 = 0 -> writes reg 0x06 with a1
    void *ret = func_0021CC90(my_obj, 0x99, 1, 0x33, uv, rect, 0x77, 0, 5);
    assert(ret == my_obj);
    assert(g_writes.size() == 10);
    assert(g_writes[0].reg == 0x06);
    assert(g_writes[0].data == 0x99ULL);

    assert(g_writes[1].reg == 0x01);
    assert(g_writes[1].data == 0x33ULL);

    // Verify 4 transformed vertex writes in 0x04 correspond to rect expansion
    // pt0: (50, 60), pt1: (150, 60), pt2: (50, 140), pt3: (150, 140)
    // base_x = 27648, base_y = 29184, depth_offset = (-5) << 3 = -40
    // x0 = (50 << 4) + 27648 - 40 = 800 + 27648 - 40 = 28408
    // y0 = (60 << 4) + 29184 - 40 = 960 + 29184 - 40 = 30104
    uint64_t exp_xyz0 = (0x77ULL << 32) | (28408ULL & 0xFFFF) | ((30104ULL & 0xFFFF) << 16);
    assert(g_writes[3].reg == 0x04);
    assert(g_writes[3].data == exp_xyz0);

    // pt3: x3 = (150 << 4) + 27648 - 40 = 2400 + 27648 - 40 = 30008
    // y3 = (140 << 4) + 29184 - 40 = 2240 + 29184 - 40 = 31384
    uint64_t exp_xyz3 = (0x77ULL << 32) | (30008ULL & 0xFFFF) | ((31384ULL & 0xFFFF) << 16);
    assert(g_writes[9].reg == 0x04);
    assert(g_writes[9].data == exp_xyz3);

    std::cout << "PASS: test_func_0021CC90" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021C990_existing_obj();
        test_func_0021C990_null_obj_and_mode0();
        test_func_0021CC90();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021C990_existing_obj();
    } else if (argv[1][0] == '1') {
        test_func_0021C990_null_obj_and_mode0();
    } else if (argv[1][0] == '2') {
        test_func_0021CC90();
    }
    return 0;
}
