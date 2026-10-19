#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct BuildItemNode {
    char pad_00[0x6C];
    BuildItemNode *m_prev;
    BuildItemNode *m_next;
    char pad_74[0xAC - 0x74];
    int m_fieldAC;
};

struct BuildAI {
    void *m_vtable;
    char pad_04[0x118];
    BuildItemNode *m_head;
    char pad_120[0x160 - 0x120];
    int m_count;

    int AddItem(void *player, int unit_id, int type, int a5, int a6, int a7);
};

extern "C" {
    char D_00490D50[32] = "NameD50";
    char D_00490D60[32] = "NameD60";
    char D_00490D80[32] = "NameD80";

    static int func_0013dac0_called = 0;
    static void *func_0013dac0_ret = 0;
    static int func_0013c960_called = 0;
    static float func_0013c960_f12 = 0.0f;
    static float func_0013c960_f13 = 0.0f;
    static char func_0013c960_str[64] = {0};

    void* func_0011ABBC(void *dst, const void *src) {
        if (dst && src) return strcpy((char*)dst, (const char*)src);
        return dst;
    }

    void* func_0011B170(void *dst, const void *src, int n) {
        if (dst && src && n > 0) {
            strncpy((char*)dst, (const char*)src, n);
            ((char*)dst)[n] = '\0';
            return dst;
        }
        return dst;
    }

    void* func_0013DAC0(void *self, int param) {
        (void)self; (void)param;
        func_0013dac0_called++;
        return func_0013dac0_ret;
    }

    void func_0013C960(void *self, int p74, int a1, int a3,
                       int p78, int p7C, int p84, const char *str,
                       float f12, float f13, float f14,
                       long long p88, long long p8C, long long p90, long long pA8) {
        (void)self; (void)p74; (void)a1; (void)a3;
        (void)p78; (void)p7C; (void)p84;
        (void)f14; (void)p88; (void)p8C; (void)p90; (void)pA8;
        func_0013c960_called++;
        func_0013c960_f12 = f12;
        func_0013c960_f13 = f13;
        if (str) strcpy(func_0013c960_str, str);
    }

    void func_0013CB70(void*, int) {}
    void func_0013CB60(void*, int) {}
    void func_0013CB80(void*, int) {}
    void func_0013C8D0(void*, int) {}
    void func_0013C880(void*, int) {}
    void func_0013C8A0(void*, float) {}
    void func_0013C8B0(void*, float) {}
    void func_0013C8C0(void*, float) {}
    void func_0013CBF0(void*, int) {}
    void func_0013CC10(void*, int) {}
    void func_0013CC30(void*, int) {}
    void func_0013CC50(void*, unsigned char) {}
}

static void test_build_ai_add_item_null_alloc() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    func_0013dac0_called = 0;
    func_0013dac0_ret = 0;

    int res = self->AddItem(0, 1, 6, 0, 0, 0);
    assert(res == -1);
    assert(func_0013dac0_called == 1);
    printf("BUILD_AI_ADD_ITEM_TEST_0_NULL_ALLOC_PASSED\n");
}

static void test_build_ai_add_item_type_6() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    BuildItemNode head_node;
    memset(&head_node, 0, sizeof(head_node));
    head_node.m_prev = &head_node;
    head_node.m_next = &head_node;
    self->m_head = &head_node;
    self->m_count = 0;

    BuildItemNode allocated_item;
    memset(&allocated_item, 0, sizeof(allocated_item));
    func_0013dac0_ret = &allocated_item;
    func_0013c960_called = 0;

    int res = self->AddItem(0, 1, 6, 10, 20, 30);
    assert(res == 1);
    assert(func_0013c960_called == 1);
    assert(func_0013c960_f12 == 3.0f);
    assert(func_0013c960_f13 == 3.0f);
    assert(strcmp(func_0013c960_str, "NameD80") == 0);
    assert(allocated_item.m_fieldAC == 30);
    assert(allocated_item.m_next == &head_node);
    assert(allocated_item.m_prev == &head_node);
    assert(head_node.m_prev == &allocated_item);
    assert(head_node.m_next == &allocated_item);
    assert(self->m_count == 1);
    printf("BUILD_AI_ADD_ITEM_TEST_1_TYPE6_PASSED\n");
}

static void test_build_ai_add_item_unit_type_valid() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    BuildItemNode head_node;
    memset(&head_node, 0, sizeof(head_node));
    head_node.m_prev = &head_node;
    head_node.m_next = &head_node;
    self->m_head = &head_node;
    self->m_count = 5;

    BuildItemNode allocated_item;
    memset(&allocated_item, 0, sizeof(allocated_item));
    func_0013dac0_ret = &allocated_item;

    // Set up player and unit_type
    char unit_type_data[64];
    memset(unit_type_data, 0, sizeof(unit_type_data));
    *(float*)(unit_type_data + 32) = 1.5f;
    *(float*)(unit_type_data + 36) = 2.5f;

    void *unit_types[4] = {0, 0, unit_type_data, 0};
    char player_data[128];
    memset(player_data, 0, sizeof(player_data));
    *(void***)(player_data + 112) = unit_types;

    func_0013c960_called = 0;
    int res = self->AddItem(player_data, 2, 1, 10, 20, 44);
    assert(res == 1);
    assert(func_0013c960_called == 1);
    assert(func_0013c960_f12 == 3.0f); // 2 * 1.5f
    assert(func_0013c960_f13 == 5.0f); // 2 * 2.5f
    assert(strcmp(func_0013c960_str, "NameD50") == 0);
    assert(allocated_item.m_fieldAC == 44);
    assert(self->m_count == 6);
    printf("BUILD_AI_ADD_ITEM_TEST_2_UNIT_TYPE_VALID_PASSED\n");
}

static void test_build_ai_add_item_unit_type_null() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    BuildItemNode head_node;
    memset(&head_node, 0, sizeof(head_node));
    head_node.m_prev = &head_node;
    head_node.m_next = &head_node;
    self->m_head = &head_node;
    self->m_count = 0;

    BuildItemNode allocated_item;
    memset(&allocated_item, 0, sizeof(allocated_item));
    func_0013dac0_ret = &allocated_item;

    void *unit_types[4] = {0, 0, 0, 0};
    char player_data[128];
    memset(player_data, 0, sizeof(player_data));
    *(void***)(player_data + 112) = unit_types;

    func_0013c960_called = 0;
    int res = self->AddItem(player_data, 2, 1, 10, 20, 55);
    assert(res == 1);
    assert(func_0013c960_called == 1);
    assert(func_0013c960_f12 == 3.0f);
    assert(func_0013c960_f13 == 3.0f);
    assert(strcmp(func_0013c960_str, "NameD60") == 0);
    assert(allocated_item.m_fieldAC == 55);
    assert(self->m_count == 1);
    printf("BUILD_AI_ADD_ITEM_TEST_3_UNIT_TYPE_NULL_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-3)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_build_ai_add_item_null_alloc();
    else if (mode == 1) test_build_ai_add_item_type_6();
    else if (mode == 2) test_build_ai_add_item_unit_type_valid();
    else if (mode == 3) test_build_ai_add_item_unit_type_null();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
