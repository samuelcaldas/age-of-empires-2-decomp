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
    int m_id;
    int m_field84;
    int m_field88;
    float m_pos_x;
    float m_pos_y;
};

struct ConAI {
    void *m_vtable;
    char pad_04[0x1C8];
    SubListConItem m_sentinel1;

    SubListConItem *GetSentinel1() { return &this->m_sentinel1; }
};

extern "C" {
    static int s_1c0_called = 0;
    static int s_890_called = 0;
    static int s_890_last_val = 0;

    int func_0013E110(void *item, int val) {
        if (!item) return 0;
        return (((SubListConItem*)item)->m_id == val) ? 1 : 0;
    }

    void func_0013E190(void *item, int val) {
        if (item) ((SubListConItem*)item)->m_field84 = val;
    }

    void func_0013E1A0(void *item, int val) {
        if (item) ((SubListConItem*)item)->m_field88 = val;
    }

    void func_0013E1C0(void *item) {
        (void)item;
        s_1c0_called++;
    }

    int func_0013C7E0(void *item) {
        if (!item) return 0;
        return ((SubListConItem*)item)->m_id + 500;
    }

    void func_0013C890(void *item, int val) {
        (void)item;
        s_890_called++;
        s_890_last_val = val;
    }

    float func_0013C800(void *item) {
        if (!item) return 0.0f;
        return ((SubListConItem*)item)->m_pos_x;
    }

    float func_0013C810(void *item) {
        if (!item) return 0.0f;
        return ((SubListConItem*)item)->m_pos_y;
    }

    void func_0013F190(ConAI *self, int a1, int a2);
    int func_0013F220(ConAI *self, int a1, int a2);
    int func_0013F2F0(ConAI *self, float f12, float f13, int a1);
}

static void reset_mocks() {
    s_1c0_called = 0;
    s_890_called = 0;
    s_890_last_val = 0;
}

static void test_con_ai_query_update_item() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    SubListConItem item1, item2;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));

    item1.m_id = 10;
    item1.m_field88 = 0;
    item1.m_next = &item2;

    item2.m_id = 20;
    item2.m_field88 = 0;
    item2.m_next = self->GetSentinel1();

    *(SubListConItem**)((char*)self + 0x238) = &item1;

    // Update item2 (id=20) with val=99
    func_0013F190(self, 20, 99);
    assert(item1.m_field88 == 0);
    assert(item2.m_field88 == 99);

    // Update non-existing item (id=30)
    func_0013F190(self, 30, 88);
    assert(item1.m_field88 == 0);
    assert(item2.m_field88 == 99);

    printf("CON_AI_QUERY_TEST_0_UPDATE_ITEM_PASSED\n");
}

static void test_con_ai_query_reset_by_id_no_1c0() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_id = 15;
    item1.m_field84 = 7;
    item1.m_field88 = 8;
    item1.m_next = self->GetSentinel1();

    *(SubListConItem**)((char*)self + 0x238) = &item1;

    // a2 = 0 -> does not call func_0013E1C0
    int res = func_0013F220(self, 15, 0);
    assert(res == 515); // 15 + 500
    assert(item1.m_field84 == 0);
    assert(item1.m_field88 == 0);
    assert(s_890_called == 1);
    assert(s_890_last_val == -1);
    assert(s_1c0_called == 0);

    printf("CON_AI_QUERY_TEST_1_RESET_BY_ID_NO_1C0_PASSED\n");
}

static void test_con_ai_query_reset_by_id_with_1c0() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_id = 25;
    item1.m_field84 = 7;
    item1.m_field88 = 8;
    item1.m_next = self->GetSentinel1();

    *(SubListConItem**)((char*)self + 0x238) = &item1;

    // a2 = 1 -> calls func_0013E1C0
    int res = func_0013F220(self, 25, 1);
    assert(res == 525);
    assert(item1.m_field84 == 0);
    assert(item1.m_field88 == 0);
    assert(s_890_called == 1);
    assert(s_890_last_val == -1);
    assert(s_1c0_called == 1);

    printf("CON_AI_QUERY_TEST_2_RESET_BY_ID_WITH_1C0_PASSED\n");
}

static void test_con_ai_query_reset_by_id_not_found() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    *(SubListConItem**)((char*)self + 0x238) = self->GetSentinel1();

    int res = func_0013F220(self, 999, 1);
    assert(res == -1);
    assert(s_890_called == 0);
    assert(s_1c0_called == 0);

    printf("CON_AI_QUERY_TEST_3_RESET_BY_ID_NOT_FOUND_PASSED\n");
}

static void test_con_ai_query_reset_by_pos_found() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_id = 35;
    item1.m_field84 = 3;
    item1.m_field88 = 4;
    item1.m_pos_x = 12.5f;
    item1.m_pos_y = 24.5f;
    item1.m_next = self->GetSentinel1();

    *(SubListConItem**)((char*)self + 0x238) = &item1;

    // a1 = 1 -> calls func_0013E1C0
    int res = func_0013F2F0(self, 12.5f, 24.5f, 1);
    assert(res == 535);
    assert(item1.m_field84 == 0);
    assert(item1.m_field88 == 0);
    assert(s_890_called == 1);
    assert(s_890_last_val == -1);
    assert(s_1c0_called == 1);

    printf("CON_AI_QUERY_TEST_4_RESET_BY_POS_FOUND_PASSED\n");
}

static void test_con_ai_query_reset_by_pos_not_found() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_id = 35;
    item1.m_pos_x = 12.5f;
    item1.m_pos_y = 24.5f;
    item1.m_next = self->GetSentinel1();

    *(SubListConItem**)((char*)self + 0x238) = &item1;

    int res = func_0013F2F0(self, 99.0f, 99.0f, 1);
    assert(res == -1);
    assert(s_890_called == 0);
    assert(s_1c0_called == 0);

    printf("CON_AI_QUERY_TEST_5_RESET_BY_POS_NOT_FOUND_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-5)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_con_ai_query_update_item();
    else if (mode == 1) test_con_ai_query_reset_by_id_no_1c0();
    else if (mode == 2) test_con_ai_query_reset_by_id_with_1c0();
    else if (mode == 3) test_con_ai_query_reset_by_id_not_found();
    else if (mode == 4) test_con_ai_query_reset_by_pos_found();
    else if (mode == 5) test_con_ai_query_reset_by_pos_not_found();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
