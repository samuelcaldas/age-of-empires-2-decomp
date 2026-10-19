#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_0021B7B0(void *manager, int unused, void *palette_src, void **out_slot);
void *func_0021B830(void *manager);

// Mock dependencies
static void *g_mock_slot = nullptr;
static int g_slot_alloc_called = 0;
static void *g_set_palette_obj = nullptr;
static int g_set_palette_count = 0;
static int g_set_palette_trans = -1;
static void *g_set_palette_src = nullptr;

void *func_0021B760(void *manager) {
    g_slot_alloc_called++;
    return g_mock_slot;
}

int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx) {
    g_set_palette_obj = palette_obj;
    g_set_palette_count = count;
    g_set_palette_src = src_buf;
    g_set_palette_trans = trans_idx;
    return 0;
}
}

static void test_func_0021B7B0() {
    g_slot_alloc_called = 0;
    g_set_palette_obj = nullptr;
    g_set_palette_count = 0;
    g_set_palette_src = nullptr;
    g_set_palette_trans = -1;

    char dummy_mgr[1024];
    char dummy_palette[256 * 4];
    for (int i = 0; i < 256 * 4; ++i) {
        dummy_palette[i] = (char)(i & 0xFF);
    }
    void *out_slot = nullptr;

    // Case 1: Slot allocation failure returns 1
    g_mock_slot = nullptr;
    int res = func_0021B7B0(dummy_mgr, 0, dummy_palette, &out_slot);
    assert(res == 1);
    assert(g_slot_alloc_called == 1);
    assert(out_slot == nullptr);

    // Case 2: Successful allocation with palette upload
    char mock_slot_obj[64];
    g_mock_slot = mock_slot_obj;
    res = func_0021B7B0(dummy_mgr, 0, dummy_palette, &out_slot);
    assert(res == 0);
    assert(out_slot == mock_slot_obj);
    assert(g_set_palette_obj == mock_slot_obj);
    assert(g_set_palette_count == 256);
    assert(g_set_palette_trans == 0xFF);
    assert(g_set_palette_src == dummy_palette);

    // Case 3: Successful allocation with nullptr palette_src (no upload)
    g_set_palette_obj = nullptr;
    out_slot = nullptr;
    res = func_0021B7B0(dummy_mgr, 0, nullptr, &out_slot);
    assert(res == 0);
    assert(out_slot == mock_slot_obj);
    assert(g_set_palette_obj == nullptr);

    // Case 4: Null out_slot pointer handling
    res = func_0021B7B0(dummy_mgr, 0, nullptr, nullptr);
    assert(res == 0);

    std::cout << "PASS: func_0021B7B0" << std::endl;
}

static void test_func_0021B830() {
    // 6 viewports of size 0xA8 = 168 bytes = 1008 bytes
    char manager[1008];
    std::memset(manager, 0, sizeof(manager));

    // Allocate first viewport
    void *vp0 = func_0021B830(manager);
    assert(vp0 == manager);
    assert(*(int *)vp0 == 1);

    // Allocate second viewport
    void *vp1 = func_0021B830(manager);
    assert(vp1 == manager + 0xA8);
    assert(*(int *)vp1 == 1);

    // Allocate remaining 4 viewports
    void *vp2 = func_0021B830(manager);
    assert(vp2 == manager + 0xA8 * 2);
    void *vp3 = func_0021B830(manager);
    assert(vp3 == manager + 0xA8 * 3);
    void *vp4 = func_0021B830(manager);
    assert(vp4 == manager + 0xA8 * 4);
    void *vp5 = func_0021B830(manager);
    assert(vp5 == manager + 0xA8 * 5);

    // Saturation: all 6 viewports active -> returns nullptr
    void *vp_overflow = func_0021B830(manager);
    assert(vp_overflow == nullptr);

    // Freeing viewport 2 allows it to be reallocated
    *(int *)vp2 = 0;
    void *vp_realloc = func_0021B830(manager);
    assert(vp_realloc == vp2);
    assert(*(int *)vp2 == 1);

    std::cout << "PASS: func_0021B830" << std::endl;
}

static void test_func_0021B830_skip_occupied() {
    char manager[1008];
    std::memset(manager, 0xCC, sizeof(manager));

    // Viewports 0, 1, 2, 4, 5 are busy
    // Viewport 3 is free (int == 0)
    *(int *)(manager + 0xA8 * 0) = 5;
    *(int *)(manager + 0xA8 * 1) = 0x1000;
    *(int *)(manager + 0xA8 * 2) = -1;
    *(int *)(manager + 0xA8 * 3) = 0;
    *(int *)(manager + 0xA8 * 4) = 1;
    *(int *)(manager + 0xA8 * 5) = 2;

    void *vp = func_0021B830(manager);
    assert(vp == manager + 0xA8 * 3);
    assert(*(int *)vp == 1);

    // Now all are busy -> saturation returns nullptr
    void *vp_fail = func_0021B830(manager);
    assert(vp_fail == nullptr);

    std::cout << "PASS: func_0021B830_skip_occupied" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0021B7B0();
        test_func_0021B830();
        test_func_0021B830_skip_occupied();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_func_0021B7B0();
    } else if (argv[1][0] == '1') {
        test_func_0021B830();
    } else if (argv[1][0] == '2') {
        test_func_0021B830_skip_occupied();
    }
    return 0;
}
