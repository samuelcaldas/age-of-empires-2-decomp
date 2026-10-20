#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct SubElement {
    char data[0x148];
};

struct Field20Elem {
    int field_0;
    char pad_4[6];
    short field_A;
    SubElement *field_C;
};

struct Field24Elem {
    char pad_0[2];
    short field_2;
    void *field_4;
};

struct TacticalNodeRecord {
    char data[24];
};

struct TacticalAI {
    void *vtable;
    short m_field4;
    short m_field6;
    char **m_field8;
    short m_fieldC;
    short m_fieldE;
    TacticalNodeRecord *m_field10;
    short m_field14;
    short m_field16;
    void *m_field18;
    short m_field1C;
    short pad_1E;
    Field20Elem *m_field20;
    Field24Elem *m_field24;

    int Save(void *stream);
};

extern "C" {
    static int s_6f70_called = 0;
    static int s_6f70_total_bytes = 0;
    static void *s_6f70_last_stream = 0;

    int func_00226F70(void *stream, void *buf, int size) {
        (void)buf;
        s_6f70_called++;
        s_6f70_total_bytes += size;
        s_6f70_last_stream = stream;
        return size;
    }

    int func_0011ACD0(const char *str) {
        return (int)strlen(str);
    }

    static int s_f40_alloc_count = 0;
    void *func_116F40(int size) {
        s_f40_alloc_count++;
        void *p = malloc(size > 0 ? size : 1);
        if (p) memset(p, 0, size > 0 ? size : 1);
        return p;
    }

    char *func_0011ABBC(char *dst, const char *src) {
        return strcpy(dst, src);
    }

    static int s_44c0_called = 0;
    static void *s_44c0_last_node = 0;
    static int s_44c0_last_a1 = 0;
    static char s_44c0_last_a2 = 0;
    static int (*s_44c0_last_a3)() = 0;

    void func_001444C0(void *node, int a1, char a2, int (*a3)(), char t0, char t1, char t2, char t3) {
        (void)t0; (void)t1; (void)t2; (void)t3;
        s_44c0_called++;
        s_44c0_last_node = node;
        s_44c0_last_a1 = a1;
        s_44c0_last_a2 = a2;
        s_44c0_last_a3 = a3;
    }

    static int s_c560_called = 0;
    static void *s_c560_last_elem = 0;
    static int s_c560_last_a1 = 0;
    static int s_c560_last_a2 = 0;

    void func_0013C560(void *elem, int a1, int a2, int a3, int t0, int t1, int t2) {
        (void)a3; (void)t0; (void)t1; (void)t2;
        s_c560_called++;
        s_c560_last_elem = elem;
        s_c560_last_a1 = a1;
        s_c560_last_a2 = a2;
    }

    int func_001410E0(void *self, const char *str);
    int func_00141170(void *self, int a1, char a2, int (*a3)());
    int func_001411E0(void *self, int a1, int a2);
}

static void reset_mocks() {
    s_6f70_called = 0;
    s_6f70_total_bytes = 0;
    s_6f70_last_stream = 0;
    s_f40_alloc_count = 0;
    s_44c0_called = 0;
    s_44c0_last_node = 0;
    s_44c0_last_a1 = 0;
    s_44c0_last_a2 = 0;
    s_44c0_last_a3 = 0;
    s_c560_called = 0;
    s_c560_last_elem = 0;
    s_c560_last_a1 = 0;
    s_c560_last_a2 = 0;
}

static void test_tactical_ai_save_stream_writes() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field4 = 5;
    ai.m_field6 = 1;
    char str[] = "TACTIC";
    char *strs[1] = { str };
    ai.m_field8 = strs;

    ai.m_fieldC = 2;
    ai.m_field14 = 3;
    ai.m_field1C = 1;

    Field20Elem f20;
    memset(&f20, 0, sizeof(f20));
    f20.field_0 = 1;
    f20.field_A = 1;
    SubElement sub;
    memset(&sub, 0, sizeof(sub));
    f20.field_C = &sub;
    ai.m_field20 = &f20;

    Field24Elem f24;
    memset(&f24, 0, sizeof(f24));
    f24.field_2 = 2;
    short shorts[2] = { 11, 22 };
    f24.field_4 = shorts;
    ai.m_field24 = &f24;

    int ret = ai.Save((void*)0x9999);

    assert(ret == 1);
    assert(s_6f70_last_stream == (void*)0x9999);
    assert(s_6f70_total_bytes == 380);

    printf("TACTICAL_AI_SAVE_TEST_0_STREAM_WRITES_PASSED\n");
}

static void test_tactical_ai_func_10e0_success() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field4 = 3;
    ai.m_field6 = 0;
    char *arr[3] = {0, 0, 0};
    ai.m_field8 = arr;

    int idx = func_001410E0(&ai, "Alpha");

    assert(idx == 0);
    assert(ai.m_field6 == 1);
    assert(ai.m_field8[0] != 0);
    assert(strcmp(ai.m_field8[0], "Alpha") == 0);
    assert(s_f40_alloc_count == 1);

    free(ai.m_field8[0]);
    printf("TACTICAL_AI_SAVE_TEST_1_FUNC_10E0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_func_10e0_capacity_full() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field4 = 2;
    ai.m_field6 = 2;

    int idx = func_001410E0(&ai, "Overflow");

    assert(idx == -1);
    assert(ai.m_field6 == 2);
    assert(s_f40_alloc_count == 0);

    printf("TACTICAL_AI_SAVE_TEST_2_FUNC_10E0_CAPACITY_FULL_PASSED\n");
}

static int dummy_cb() { return 123; }

static void test_tactical_ai_func_1170_success() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalNodeRecord records[4];
    memset(records, 0, sizeof(records));
    ai.m_fieldC = 4;
    ai.m_fieldE = 1;
    ai.m_field10 = records;

    int idx = func_00141170(&ai, 42, 7, dummy_cb);

    assert(idx == 1);
    assert(ai.m_fieldE == 2);
    assert(s_44c0_called == 1);
    assert(s_44c0_last_node == &records[1]);
    assert(s_44c0_last_a1 == 42);
    assert(s_44c0_last_a2 == 7);
    assert(s_44c0_last_a3 == dummy_cb);

    printf("TACTICAL_AI_SAVE_TEST_3_FUNC_1170_SUCCESS_PASSED\n");
}

static void test_tactical_ai_func_1170_capacity_full() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_fieldC = 2;
    ai.m_fieldE = 2;

    int idx = func_00141170(&ai, 1, 2, dummy_cb);

    assert(idx == -1);
    assert(ai.m_fieldE == 2);
    assert(s_44c0_called == 0);

    printf("TACTICAL_AI_SAVE_TEST_4_FUNC_1170_CAPACITY_FULL_PASSED\n");
}

static void test_tactical_ai_func_11e0_success() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    char storage[48];
    memset(storage, 0, sizeof(storage));
    ai.m_field14 = 4;
    ai.m_field16 = 2;
    ai.m_field18 = storage;

    int idx = func_001411E0(&ai, 55, 66);

    assert(idx == 2);
    assert(ai.m_field16 == 3);
    assert(s_c560_called == 1);
    assert(s_c560_last_elem == storage + 24);
    assert(s_c560_last_a1 == 55);
    assert(s_c560_last_a2 == 66);

    printf("TACTICAL_AI_SAVE_TEST_5_FUNC_11E0_SUCCESS_PASSED\n");
}

static void test_tactical_ai_func_11e0_capacity_full() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field14 = 3;
    ai.m_field16 = 3;

    int idx = func_001411E0(&ai, 10, 20);

    assert(idx == -1);
    assert(ai.m_field16 == 3);
    assert(s_c560_called == 0);

    printf("TACTICAL_AI_SAVE_TEST_6_FUNC_11E0_CAPACITY_FULL_PASSED\n");
}

static void test_tactical_ai_save_layout() {
    assert(sizeof(Field20Elem) == 16);
    assert(sizeof(Field24Elem) == 8);
    assert(sizeof(SubElement) == 0x148);
    assert(sizeof(TacticalNodeRecord) == 24);
    assert(offsetof(TacticalAI, vtable) == 0);
    assert(offsetof(TacticalAI, m_field4) == 4);
    assert(offsetof(TacticalAI, m_field6) == 6);
    assert(offsetof(TacticalAI, m_field8) == 8);
    assert(offsetof(TacticalAI, m_fieldC) == 0xC);
    assert(offsetof(TacticalAI, m_fieldE) == 0xE);
    assert(offsetof(TacticalAI, m_field10) == 0x10);
    assert(offsetof(TacticalAI, m_field14) == 0x14);
    assert(offsetof(TacticalAI, m_field16) == 0x16);
    assert(offsetof(TacticalAI, m_field18) == 0x18);
    assert(offsetof(TacticalAI, m_field1C) == 0x1C);
    assert(offsetof(TacticalAI, m_field20) == 0x20);
    assert(offsetof(TacticalAI, m_field24) == 0x24);

    printf("TACTICAL_AI_SAVE_TEST_7_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-7)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_save_stream_writes();
    else if (mode == 1) test_tactical_ai_func_10e0_success();
    else if (mode == 2) test_tactical_ai_func_10e0_capacity_full();
    else if (mode == 3) test_tactical_ai_func_1170_success();
    else if (mode == 4) test_tactical_ai_func_1170_capacity_full();
    else if (mode == 5) test_tactical_ai_func_11e0_success();
    else if (mode == 6) test_tactical_ai_func_11e0_capacity_full();
    else if (mode == 7) test_tactical_ai_save_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
