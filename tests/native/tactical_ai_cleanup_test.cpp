#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalItem {
    int m_field00;
    char m_name[1024];
    int m_field404;
    int m_field408;
    int m_field40C;
    int m_field410;
    int m_field414;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x194];
    int m_field198;
    char pad_19C[0x108];
    int m_field2A4;
    char m_name[1024];
    int m_field6A8;
    int m_field6AC;
    int m_field6B0;
    int pad_6B4;
    int m_field6B8;
    int m_field6BC;
    int m_item_count;
    TacticalItem m_items[10];
    int m_stack_count;
    int m_stack[50];
};

extern "C" {
    static int s_11abbc_called = 0;

    char *func_0011ABBC(char *dst, const char *src) {
        s_11abbc_called++;
        return strcpy(dst, src);
    }

    void func_144050(TacticalAI2 *self);
    void func_144180(TacticalAI2 *self);
}

static void reset_mocks() {
    s_11abbc_called = 0;
}

static void test_tactical_ai_cleanup_144050() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_item_count = 2;
    // Set item 1 fields (the one being popped)
    ai.m_items[1].m_field00 = 111;
    strcpy(ai.m_items[1].m_name, "popped_scope_name");
    ai.m_items[1].m_field404 = 222;
    ai.m_items[1].m_field408 = 333;
    ai.m_items[1].m_field40C = 444;
    ai.m_items[1].m_field410 = 555;
    ai.m_items[1].m_field414 = 666;

    func_144050(&ai);

    assert(ai.m_item_count == 1);
    assert(ai.m_field2A4 == 111);
    assert(ai.m_field6AC == 333);
    assert(ai.m_field6A8 == 222);
    assert(ai.m_field6B0 == 444);
    assert(strcmp(ai.m_name, "popped_scope_name") == 0);
    assert(s_11abbc_called == 1);
    assert(ai.m_field6B8 == 555);
    assert(ai.m_field6BC == 666);

    // End of test_tactical_ai_cleanup_144050

    printf("TACTICAL_AI_CLEANUP_TEST_0_144050_PASSED\n");
}

static void test_tactical_ai_cleanup_144180() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_stack_count = 3;
    ai.m_stack[0] = 0;
    ai.m_stack[1] = 0;
    ai.m_stack[2] = 42; // the one being popped

    func_144180(&ai);

    assert(ai.m_stack_count == 2);
    assert(ai.m_field198 == 42);

    printf("TACTICAL_AI_CLEANUP_TEST_1_144180_PASSED\n");
}

static void test_tactical_ai_cleanup_layout() {
    assert(sizeof(TacticalItem) == 1048);
    assert(offsetof(TacticalItem, m_field00) == 0);
    assert(offsetof(TacticalItem, m_name) == 4);
    assert(offsetof(TacticalItem, m_field404) == 0x404);
    assert(offsetof(TacticalItem, m_field408) == 0x408);
    assert(offsetof(TacticalItem, m_field40C) == 0x40C);
    assert(offsetof(TacticalItem, m_field410) == 0x410);
    assert(offsetof(TacticalItem, m_field414) == 0x414);

    assert(offsetof(TacticalAI2, m_field198) == 0x198);
    assert(offsetof(TacticalAI2, m_field2A4) == 0x2A4);
    assert(offsetof(TacticalAI2, m_name) == 0x2A8);
    assert(offsetof(TacticalAI2, m_field6A8) == 0x6A8);
    assert(offsetof(TacticalAI2, m_field6AC) == 0x6AC);
    assert(offsetof(TacticalAI2, m_field6B0) == 0x6B0);
    assert(offsetof(TacticalAI2, m_field6B8) == 0x6B8);
    assert(offsetof(TacticalAI2, m_field6BC) == 0x6BC);
    assert(offsetof(TacticalAI2, m_item_count) == 0x6C0);
    assert(offsetof(TacticalAI2, m_items) == 0x6C4);
    assert(offsetof(TacticalAI2, m_stack_count) == 0x2FB4);
    assert(offsetof(TacticalAI2, m_stack) == 0x2FB8);

    printf("TACTICAL_AI_CLEANUP_TEST_2_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-2)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_cleanup_144050();
    else if (mode == 1) test_tactical_ai_cleanup_144180();
    else if (mode == 2) test_tactical_ai_cleanup_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
