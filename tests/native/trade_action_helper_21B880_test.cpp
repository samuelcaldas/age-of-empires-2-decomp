#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_0021B880(void *manager, void *config, void **out_viewport, int unused, void *extra_ptr);

static void *g_mock_vp = nullptr;
static int g_alloc_vp_calls = 0;

void *func_0021B830(void *manager) {
    g_alloc_vp_calls++;
    return g_mock_vp;
}
}

static void test_func_0021B880_basic() {
    g_alloc_vp_calls = 0;
    char manager[2048];
    std::memset(manager, 0, sizeof(manager));

    char config[256];
    std::memset(config, 0, sizeof(config));

    // Case 1: Allocation failure
    g_mock_vp = nullptr;
    void *out_vp = nullptr;
    int res = func_0021B880(manager, config, &out_vp, 0, nullptr);
    assert(res == 1);
    assert(g_alloc_vp_calls == 1);
    assert(out_vp == nullptr);

    // Case 2: Standard allocation without fullscreen override
    char vp_buf[256];
    std::memset(vp_buf, 0, sizeof(vp_buf));
    g_mock_vp = vp_buf;

    // Setup config:
    // flags (offset 4) = 4 (compute x2) | 2 (compute y2) | 0x1000 (apply pixel format)
    *(int *)(config + 4) = 4 | 2 | 0x1000;
    *(int *)(config + 8) = 100;   // h
    *(int *)(config + 12) = 200;  // w

    // initial vp_buf coords at offset 4 and 8
    *(int *)(vp_buf + 4) = 50;    // x1
    *(int *)(vp_buf + 8) = 60;    // y1

    // pixel format config at offset 76 & 84
    *(unsigned short *)(config + 76) = 0x40; // use custom bpp
    *(int *)(config + 84) = 32;              // 32 bpp
    *(int *)(vp_buf + 132) = 32;

    int extra_val = 0x12345678;
    res = func_0021B880(manager, config, &out_vp, 0, &extra_val);
    assert(res == 0);
    assert(out_vp == vp_buf);

    // Verify 0x80808080 at offset 40
    assert(*(int *)(vp_buf + 40) == (int)0x80808080);

    // Verify x2 = 50 + 200 - 1 = 249 at offset 12
    assert(*(int *)(vp_buf + 12) == 249);
    // Verify y2 = 60 + 100 - 1 = 159 at offset 16
    assert(*(int *)(vp_buf + 16) == 159);

    // Verify format code for 32 bpp is 0 at offset 28
    assert(*(int *)(vp_buf + 28) == 0);

    // Verify extra_ptr written to offset 84
    assert(*(void **)(vp_buf + 84) == &extra_val);

    // Verify manager pointer written to offset 24
    assert(*(void **)(vp_buf + 24) == manager);

    // Verify row pitch = (((width + 3) & ~3) * bpp) >> 3 = (200 * 32) >> 3 = 800 at offset 64
    assert(*(int *)(vp_buf + 64) == 800);

    std::cout << "PASS: test_func_0021B880_basic" << std::endl;
}

static void test_func_0021B880_fullscreen() {
    char manager[2048];
    std::memset(manager, 0, sizeof(manager));

    char config[256];
    std::memset(config, 0, sizeof(config));

    char vp_buf[256];
    std::memset(vp_buf, 0, sizeof(vp_buf));
    g_mock_vp = vp_buf;

    // Fullscreen: flags & 1 and flags_68 & 0x200
    *(int *)(config + 4) = 1 | 0x1000;
    *(unsigned short *)(config + 104) = 0x200;

    // 8 bpp via flag 0x20 at offset 76
    *(unsigned short *)(config + 76) = 0x20;

    void *out_vp = nullptr;
    int res = func_0021B880(manager, config, &out_vp, 0, nullptr);
    assert(res == 0);
    assert(out_vp == vp_buf);

    // Verify full screen rect and dimensions
    assert(*(int *)(vp_buf + 4) == 0);
    assert(*(int *)(vp_buf + 12) == 639);
    assert(*(int *)(vp_buf + 8) == 0);
    assert(*(int *)(vp_buf + 16) == 511);
    assert(*(int *)(vp_buf + 60) == 640);
    assert(*(int *)(vp_buf + 56) == 512);

    // Verify 8 bpp -> format code 19
    assert(*(int *)(vp_buf + 132) == 8);
    assert(*(int *)(vp_buf + 28) == 19);

    // Verify fullscreen flag at offset 152
    assert(*(int *)(vp_buf + 152) & 0x4000);

    // Verify manager + 1056 receives viewport pointer
    assert(*(void **)(manager + 1056) == vp_buf);

    // Verify row pitch = (640 * 8) >> 3 = 640 at offset 64
    assert(*(int *)(vp_buf + 64) == 640);

    std::cout << "PASS: test_func_0021B880_fullscreen" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021B880_basic();
        test_func_0021B880_fullscreen();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021B880_basic();
    } else if (argv[1][0] == '1') {
        test_func_0021B880_fullscreen();
    }
    return 0;
}
