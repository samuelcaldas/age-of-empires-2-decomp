#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct SubListConItem {
    char pad_00[0x6C];
    SubListConItem *m_next;
    SubListConItem *m_prev;
    int m_field74;
    int m_field78;
    int m_field7C;
};

struct ConAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0;
    int m_fieldB4;
    int m_fieldB8;
    float m_fieldBC;
    float m_fieldC0;
    float m_fieldC4;
    char pad_C8[0x104];
    SubListConItem m_sentinel1;
    SubListConItem m_sentinel2;
    char pad_2CC[0x4];
    SubListConItem m_items[10];

    SubListConItem *GetSentinel1() { return &this->m_sentinel1; }
};

extern "C" {
    static int s_f650_called = 0;
    static int s_e250_called = 0;
    static void *s_e250_last_item = 0;

    static float s_item_x = 10.0f;
    static float s_item_y = 10.0f;
    static float s_item_z = 0.0f;
    static float s_item_w = 4.0f;
    static float s_item_h = 4.0f;

    void func_0013F650(void *self) {
        (void)self;
        s_f650_called++;
    }

    float func_0013C800(void *item) { (void)item; return s_item_x; }
    float func_0013C810(void *item) { (void)item; return s_item_y; }
    float func_0013C820(void *item) { (void)item; return s_item_z; }
    float func_0013C830(void *item) { (void)item; return s_item_w; }
    float func_0013C840(void *item) { (void)item; return s_item_h; }

    void func_0013C8A0(void *item, float val) { (void)item; s_item_x = val; }
    void func_0013C8B0(void *item, float val) { (void)item; s_item_y = val; }
    void func_0013C8C0(void *item, float val) { (void)item; s_item_z = val; }

    void func_0013E250(void *self, void *item) {
        (void)self;
        s_e250_called++;
        s_e250_last_item = item;
    }

    void func_0013EEF0(void *self_ptr, int a1, int a2, float f12, float f13, float f14);
    int func_0013F180(void *self);
}

static void reset_mocks() {
    s_f650_called = 0;
    s_e250_called = 0;
    s_e250_last_item = 0;
    s_item_x = 10.0f;
    s_item_y = 10.0f;
    s_item_z = 0.0f;
    s_item_w = 4.0f;
    s_item_h = 4.0f;
}

static void test_con_ai_plan_setup_invalid_bounds() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    // f12 = -1.0f <= 0.0f -> invalid
    func_0013EEF0(self, 100, 100, -1.0f, 10.0f, 0.0f);

    assert(s_f650_called == 1);
    assert(self->m_fieldB4 == 100);
    assert(self->m_fieldB8 == 100);

    // f12 >= a1 (100.0f >= 100) -> invalid
    reset_mocks();
    func_0013EEF0(self, 100, 100, 100.0f, 10.0f, 0.0f);
    assert(s_f650_called == 1);

    printf("CON_AI_PLAN_SETUP_TEST_0_INVALID_BOUNDS_PASSED\n");
}

static void test_con_ai_plan_setup_empty_list() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    *(SubListConItem**)((char*)self + 0x238) = self->GetSentinel1();

    func_0013EEF0(self, 100, 100, 10.0f, 10.0f, 0.0f);
    assert(s_f650_called == 0);
    assert(s_e250_called == 0);
    assert(self->m_fieldB4 == 100);
    assert(self->m_fieldB8 == 100);
    assert(self->m_fieldBC == 10.0f);
    assert(self->m_fieldC0 == 10.0f);
    assert(self->m_fieldC4 == 0.0f);

    printf("CON_AI_PLAN_SETUP_TEST_1_EMPTY_LIST_PASSED\n");
}

static void test_con_ai_plan_setup_item_inside() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    self->m_fieldAC = 1;

    SubListConItem item;
    memset(&item, 0, sizeof(item));
    item.m_next = self->GetSentinel1();
    item.m_prev = self->GetSentinel1();
    self->GetSentinel1()->m_next = &item;
    self->GetSentinel1()->m_prev = &item;

    *(SubListConItem**)((char*)self + 0x238) = &item;

    s_item_x = 10.0f;
    s_item_y = 10.0f;
    s_item_w = 4.0f;
    s_item_h = 4.0f;

    // Shift by dx=5.0, dy=5.0, dz=1.0
    // New pos: x=15.0, y=15.0, z=1.0. Bounds: [0, 99]. 15 - 2 = 13 > 0, 15 + 2 = 17 <= 99. Inside.
    func_0013EEF0(self, 100, 100, 5.0f, 5.0f, 1.0f);

    assert(s_f650_called == 0);
    assert(s_e250_called == 0); // Not deleted
    assert(self->m_fieldAC == 1);
    assert(s_item_x == 15.0f);
    assert(s_item_y == 15.0f);
    assert(s_item_z == 1.0f);

    printf("CON_AI_PLAN_SETUP_TEST_2_ITEM_INSIDE_PASSED\n");
}

static void test_con_ai_plan_setup_item_outside() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    self->m_fieldAC = 1;

    SubListConItem item;
    memset(&item, 0, sizeof(item));
    item.m_next = self->GetSentinel1();
    item.m_prev = self->GetSentinel1();
    self->GetSentinel1()->m_next = &item;
    self->GetSentinel1()->m_prev = &item;

    *(SubListConItem**)((char*)self + 0x238) = &item;

    s_item_x = 2.0f;
    s_item_y = 10.0f;
    s_item_w = 6.0f;
    s_item_h = 4.0f;

    // Shift by dx=-1.0. New x = 1.0. x - w/2 = 1.0 - 3.0 = -2.0 < 0.0 -> outside!
    func_0013EEF0(self, 100, 100, -1.0f + 10.0f, 5.0f, 0.0f);
    // Note: f12 must be > 0 and < a1, so let's set f12 = 1.0f, but s_item_x initial = 1.0f
    reset_mocks();
    self->m_fieldAC = 1;
    s_item_x = 1.0f;
    s_item_y = 10.0f;
    s_item_w = 6.0f; // 1.0 + 0.5 - 3.0 = -1.5 < 0
    s_item_h = 4.0f;
    func_0013EEF0(self, 100, 100, 0.5f, 5.0f, 0.0f);

    assert(s_e250_called == 1);
    assert(s_e250_last_item == &item);
    assert(self->m_fieldAC == 0);
    assert(self->GetSentinel1()->m_next == self->GetSentinel1());
    assert(self->GetSentinel1()->m_prev == self->GetSentinel1());

    printf("CON_AI_PLAN_SETUP_TEST_3_ITEM_OUTSIDE_PASSED\n");
}

static void test_con_ai_plan_setup_stub_180() {
    int res = func_0013F180(0);
    assert(res == 0);
    printf("CON_AI_PLAN_SETUP_TEST_4_STUB_180_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-4)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_con_ai_plan_setup_invalid_bounds();
    else if (mode == 1) test_con_ai_plan_setup_empty_list();
    else if (mode == 2) test_con_ai_plan_setup_item_inside();
    else if (mode == 3) test_con_ai_plan_setup_item_outside();
    else if (mode == 4) test_con_ai_plan_setup_stub_180();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
