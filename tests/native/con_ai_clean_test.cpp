#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct SubListConItem {
    char pad_00[0x10];
    float m_pos_x;
    float m_pos_y;
    char pad_18[0x6C - 0x18];
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

    SubListConItem *GetSentinel1() { return &this->m_sentinel1; }
    SubListConItem *GetSentinel2() { return &this->m_sentinel2; }
};

extern "C" {
    static int s_e250_called = 0;
    static void *s_e250_last_self = 0;
    static void *s_e250_items[16] = {0};

    float func_0013C800(void *item) {
        if (!item) return 0.0f;
        return ((SubListConItem*)item)->m_pos_x;
    }

    float func_0013C810(void *item) {
        if (!item) return 0.0f;
        return ((SubListConItem*)item)->m_pos_y;
    }

    void func_0013E250(void *self, void *item) {
        s_e250_last_self = self;
        if (s_e250_called < 16) {
            s_e250_items[s_e250_called] = item;
        }
        s_e250_called++;
    }

    SubListConItem *func_0013F4B0(ConAI *self, float f12, float f13);
    SubListConItem *func_0013F5B0(ConAI *self, float f12, float f13);
    void func_0013F650(ConAI *self);
    void func_0013F6C0(ConAI *self);
}

static void reset_mocks() {
    s_e250_called = 0;
    s_e250_last_self = 0;
    memset(s_e250_items, 0, sizeof(s_e250_items));
}

static void init_con_ai(ConAI *self) {
    memset(self, 0, sizeof(ConAI));
    self->m_sentinel1.m_next = self->GetSentinel1();
    self->m_sentinel1.m_prev = self->GetSentinel1();
    self->m_sentinel2.m_next = self->GetSentinel2();
    self->m_sentinel2.m_prev = self->GetSentinel2();
}

static void test_con_ai_clean_f4b0_found_list1() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1, item2, item3;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));
    memset(&item3, 0, sizeof(item3));

    item1.m_pos_x = 10.0f;
    item1.m_pos_y = 20.0f;
    item1.m_next = &item2;
    item1.m_prev = self->GetSentinel1();

    item2.m_pos_x = 30.0f;
    item2.m_pos_y = 40.0f;
    item2.m_next = self->GetSentinel1();
    item2.m_prev = &item1;

    self->m_sentinel1.m_next = &item1;
    self->m_sentinel1.m_prev = &item2;

    item3.m_pos_x = 50.0f;
    item3.m_pos_y = 60.0f;
    item3.m_next = self->GetSentinel2();
    item3.m_prev = self->GetSentinel2();
    self->m_sentinel2.m_next = &item3;
    self->m_sentinel2.m_prev = &item3;

    SubListConItem *res = func_0013F4B0(self, 10.0f, 20.0f);
    assert(res == &item1);

    printf("CON_AI_CLEAN_TEST_0_F4B0_FOUND_LIST1_PASSED\n");
}

static void test_con_ai_clean_f4b0_found_list2() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1, item2;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));

    item1.m_pos_x = 10.0f;
    item1.m_pos_y = 20.0f;
    item1.m_next = self->GetSentinel1();
    item1.m_prev = self->GetSentinel1();
    self->m_sentinel1.m_next = &item1;
    self->m_sentinel1.m_prev = &item1;

    item2.m_pos_x = 50.0f;
    item2.m_pos_y = 60.0f;
    item2.m_next = self->GetSentinel2();
    item2.m_prev = self->GetSentinel2();
    self->m_sentinel2.m_next = &item2;
    self->m_sentinel2.m_prev = &item2;

    SubListConItem *res = func_0013F4B0(self, 50.0f, 60.0f);
    assert(res == &item2);

    printf("CON_AI_CLEAN_TEST_1_F4B0_FOUND_LIST2_PASSED\n");
}

static void test_con_ai_clean_f4b0_not_found() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_pos_x = 10.0f;
    item1.m_pos_y = 20.0f;
    item1.m_next = self->GetSentinel1();
    item1.m_prev = self->GetSentinel1();
    self->m_sentinel1.m_next = &item1;
    self->m_sentinel1.m_prev = &item1;

    SubListConItem *res = func_0013F4B0(self, 99.0f, 99.0f);
    assert(res == 0);

    printf("CON_AI_CLEAN_TEST_2_F4B0_NOT_FOUND_PASSED\n");
}

static void test_con_ai_clean_f5b0_found_list2() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1, item2;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));

    item1.m_pos_x = 10.0f;
    item1.m_pos_y = 20.0f;
    item1.m_next = self->GetSentinel1();
    item1.m_prev = self->GetSentinel1();
    self->m_sentinel1.m_next = &item1;
    self->m_sentinel1.m_prev = &item1;

    item2.m_pos_x = 30.0f;
    item2.m_pos_y = 40.0f;
    item2.m_next = self->GetSentinel2();
    item2.m_prev = self->GetSentinel2();
    self->m_sentinel2.m_next = &item2;
    self->m_sentinel2.m_prev = &item2;

    SubListConItem *res = func_0013F5B0(self, 30.0f, 40.0f);
    assert(res == &item2);

    printf("CON_AI_CLEAN_TEST_3_F5B0_FOUND_LIST2_PASSED\n");
}

static void test_con_ai_clean_f5b0_in_list1_only_returns_null() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_pos_x = 10.0f;
    item1.m_pos_y = 20.0f;
    item1.m_next = self->GetSentinel1();
    item1.m_prev = self->GetSentinel1();
    self->m_sentinel1.m_next = &item1;
    self->m_sentinel1.m_prev = &item1;

    // item1 is at (10.0f, 20.0f) in list 1, but f5b0 searches list 2 only
    SubListConItem *res = func_0013F5B0(self, 10.0f, 20.0f);
    assert(res == 0);

    printf("CON_AI_CLEAN_TEST_4_F5B0_IN_LIST1_ONLY_RETURNS_NULL_PASSED\n");
}

static void test_con_ai_clean_f650_frees_list1() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1, item2;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));

    item1.m_next = &item2;
    item1.m_prev = self->GetSentinel1();
    item2.m_next = self->GetSentinel1();
    item2.m_prev = &item1;

    self->m_sentinel1.m_next = &item1;
    self->m_sentinel1.m_prev = &item2;
    self->m_fieldAC = 2;

    func_0013F650(self);

    assert(s_e250_called == 2);
    assert(s_e250_items[0] == &item1);
    assert(s_e250_items[1] == &item2);
    assert(self->m_sentinel1.m_next == self->GetSentinel1());
    assert(self->m_sentinel1.m_prev == self->GetSentinel1());
    assert(self->m_fieldAC == 0);

    printf("CON_AI_CLEAN_TEST_5_F650_FREES_LIST1_PASSED\n");
}

static void test_con_ai_clean_f650_empty_list1() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);
    self->m_fieldAC = 0;

    func_0013F650(self);

    assert(s_e250_called == 0);
    assert(self->m_sentinel1.m_next == self->GetSentinel1());
    assert(self->m_sentinel1.m_prev == self->GetSentinel1());
    assert(self->m_fieldAC == 0);

    printf("CON_AI_CLEAN_TEST_6_F650_EMPTY_LIST1_PASSED\n");
}

static void test_con_ai_clean_f6c0_fieldb0_zero_early_return() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_next = self->GetSentinel2();
    item1.m_prev = self->GetSentinel2();
    self->m_sentinel2.m_next = &item1;
    self->m_sentinel2.m_prev = &item1;
    self->m_fieldB0 = 0; // fieldB0 == 0 -> early return

    func_0013F6C0(self);

    assert(s_e250_called == 0);
    assert(self->m_sentinel2.m_next == &item1);
    assert(self->m_fieldB0 == 0);

    printf("CON_AI_CLEAN_TEST_7_F6C0_FIELDB0_ZERO_EARLY_RETURN_PASSED\n");
}

static void test_con_ai_clean_f6c0_frees_list2() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    ConAI *self = (ConAI*)storage;
    init_con_ai(self);

    SubListConItem item1, item2;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));

    item1.m_next = &item2;
    item1.m_prev = self->GetSentinel2();
    item2.m_next = self->GetSentinel2();
    item2.m_prev = &item1;

    self->m_sentinel2.m_next = &item1;
    self->m_sentinel2.m_prev = &item2;
    self->m_fieldB0 = 2;

    func_0013F6C0(self);

    assert(s_e250_called == 2);
    assert(s_e250_items[0] == &item1);
    assert(s_e250_items[1] == &item2);
    assert(self->m_sentinel2.m_next == self->GetSentinel2());
    assert(self->m_sentinel2.m_prev == self->GetSentinel2());
    assert(self->m_fieldB0 == 0);

    printf("CON_AI_CLEAN_TEST_8_F6C0_FREES_LIST2_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-8)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_con_ai_clean_f4b0_found_list1();
    else if (mode == 1) test_con_ai_clean_f4b0_found_list2();
    else if (mode == 2) test_con_ai_clean_f4b0_not_found();
    else if (mode == 3) test_con_ai_clean_f5b0_found_list2();
    else if (mode == 4) test_con_ai_clean_f5b0_in_list1_only_returns_null();
    else if (mode == 5) test_con_ai_clean_f650_frees_list1();
    else if (mode == 6) test_con_ai_clean_f650_empty_list1();
    else if (mode == 7) test_con_ai_clean_f6c0_fieldb0_zero_early_return();
    else if (mode == 8) test_con_ai_clean_f6c0_frees_list2();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
