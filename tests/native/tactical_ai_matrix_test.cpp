#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct SubElement {
    char pad_0[5];
    char field_5;
    char pad_6[0x148 - 6];
};

struct Field20Elem {
    int field_0;
    int field_4;
    short field_8;
    short field_A;
    SubElement *field_C;
};

struct Field24Elem {
    short field_0;
    short field_2;
    short *field_4;
};

struct TacticalNodeRecord {
    char data[24];
};

struct TacticalAI {
    void *vtable;
    char pad_4[8];
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
    SubElement *m_active_node;
    Field20Elem *m_field2C;
    Field24Elem *m_field30;
};

extern "C" {
    static int s_alloc_count = 0;
    static int s_last_alloc_size = 0;

    void *func_100730(unsigned int size) {
        s_alloc_count++;
        s_last_alloc_size = (int)size;
        void *p = malloc(size > 0 ? size : 1);
        if (p) memset(p, 0, size > 0 ? size : 1);
        return p;
    }

    static int s_vec_new_count = 0;
    void *func_1004E0(void *ptr, void (*ctor)(void*), void (*dtor)(void*), unsigned int size, int count) {
        (void)ctor; (void)dtor; (void)size; (void)count;
        s_vec_new_count++;
        return ptr;
    }

    static int s_vec_del_count = 0;
    void func_1002A0(void *ptr, void (*dtor)(void*)) {
        (void)dtor;
        s_vec_del_count++;
        if (ptr) free(ptr);
    }

    static int s_free_count = 0;
    void func_00100630(void *ptr) {
        s_free_count++;
        if (ptr) free(ptr);
    }

    void func_145680(void *ptr) { (void)ptr; }
    void func_1456F0(void *ptr) { (void)ptr; }

    static int s_1a20_result = 1;
    static int s_1a20_called = 0;
    int func_00141A20(void *self, int index) {
        (void)self; (void)index;
        s_1a20_called++;
        return s_1a20_result;
    }

    static int s_4530_count = 0;
    void func_00144530(void *node) {
        (void)node;
        s_4530_count++;
    }

    static int s_1c70_result = 1;
    static int s_1c70_called = 0;
    int func_00141C70(void *self) {
        (void)self;
        s_1c70_called++;
        return s_1c70_result;
    }

    int func_00141500(void *self, int size);
    int func_00141630(void *self, int index);
    int func_00141760(void *self, int index, short *out);
    int func_001418B0(void *self);
}

static void reset_mocks() {
    s_alloc_count = 0;
    s_last_alloc_size = 0;
    s_vec_new_count = 0;
    s_vec_del_count = 0;
    s_free_count = 0;
    s_1a20_result = 1;
    s_1a20_called = 0;
    s_4530_count = 0;
    s_1c70_result = 1;
    s_1c70_called = 0;
}

static void test_tactical_ai_func_1500_success() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field1C = 3;
    Field20Elem f20[3];
    memset(f20, 0, sizeof(f20));
    f20[0].field_0 = 1; // occupied
    f20[1].field_0 = 0; // free slot
    f20[2].field_0 = 0;
    ai.m_field20 = f20;

    Field24Elem f24[3];
    memset(f24, 0, sizeof(f24));
    ai.m_field24 = f24;

    int slot = func_00141500(&ai, 10);

    assert(slot == 1);
    assert(f20[1].field_0 == 1);
    assert(f20[1].field_4 == 1);
    assert(f20[1].field_8 == 10);
    assert(f20[1].field_A == 0);
    assert(f20[1].field_C != 0);
    assert(f24[1].field_0 == 100);
    assert(f24[1].field_2 == 0);
    assert(f24[1].field_4 != 0);
    for (int k = 0; k < 100; k++) {
        assert(f24[1].field_4[k] == -1);
    }
    assert(s_alloc_count == 2);

    free(f20[1].field_C);
    free(f24[1].field_4);
    printf("TACTICAL_AI_MATRIX_TEST_0_FUNC_1500_SUCCESS_PASSED\n");
}

static void test_tactical_ai_func_1500_capacity_full() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field1C = 2;
    Field20Elem f20[2];
    memset(f20, 0, sizeof(f20));
    f20[0].field_0 = 1;
    f20[1].field_0 = 1;
    ai.m_field20 = f20;

    int slot = func_00141500(&ai, 10);

    assert(slot == -1);
    assert(s_alloc_count == 0);

    printf("TACTICAL_AI_MATRIX_TEST_1_FUNC_1500_CAPACITY_FULL_PASSED\n");
}

static void test_tactical_ai_func_1630_invalid_index() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_result = 0;

    int res = func_00141630(&ai, 5);

    assert(res == 0);
    assert(s_1a20_called == 1);

    printf("TACTICAL_AI_MATRIX_TEST_2_FUNC_1630_INVALID_INDEX_PASSED\n");
}

static void test_tactical_ai_func_1630_success_reset() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_result = 1;

    Field20Elem f20;
    memset(&f20, 0, sizeof(f20));
    f20.field_8 = 5;
    f20.field_A = 3;
    f20.field_C = (SubElement*)malloc(sizeof(SubElement) * 5);
    ai.m_field20 = &f20;

    Field24Elem f24;
    memset(&f24, 0, sizeof(f24));
    f24.field_4 = (short*)malloc(200);
    ai.m_field24 = &f24;

    int res = func_00141630(&ai, 0);

    assert(res == 1);
    assert(s_vec_del_count == 1);
    assert(s_free_count == 1);
    assert(f20.field_A == 0);
    assert(f20.field_C != 0);
    assert(f24.field_0 == 100);
    assert(f24.field_2 == 0);
    assert(f24.field_4 != 0);
    for (int k = 0; k < 100; k++) {
        assert(f24.field_4[k] == -1);
    }

    free(f20.field_C);
    free(f24.field_4);
    printf("TACTICAL_AI_MATRIX_TEST_3_FUNC_1630_SUCCESS_RESET_PASSED\n");
}

static void test_tactical_ai_func_1760_invalid_index() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_result = 0;

    short out[2] = {0, 0};
    int res = func_00141760(&ai, 3, out);

    assert(res == 0);
    assert(s_1a20_called == 1);

    printf("TACTICAL_AI_MATRIX_TEST_4_FUNC_1760_INVALID_INDEX_PASSED\n");
}

static void test_tactical_ai_func_1760_scan_nodes() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_result = 1;
    s_1c70_result = 1;

    ai.m_fieldE = 2;
    TacticalNodeRecord nodes[2];
    memset(nodes, 0, sizeof(nodes));
    ai.m_field10 = nodes;

    Field20Elem f20;
    memset(&f20, 0, sizeof(f20));
    f20.field_A = 3;
    SubElement subs[3];
    memset(subs, 0, sizeof(subs));
    subs[0].field_5 = 1; // active -> evaluated (s_1c70=1)
    subs[1].field_5 = 0; // inactive -> skipped
    subs[2].field_5 = 1; // active -> evaluated (s_1c70=1)
    f20.field_C = subs;
    ai.m_field20 = &f20;

    Field24Elem f24;
    memset(&f24, 0, sizeof(f24));
    ai.m_field24 = &f24;

    short out[2] = { 0, 0 };
    int res = func_00141760(&ai, 0, out);

    assert(res == 1);
    assert(s_4530_count == 2);
    assert(s_1c70_called == 2);
    assert(out[0] == 3); // cap
    assert(out[1] == 2); // count
    assert(ai.m_active_node == 0);
    assert(ai.m_field2C == 0);
    assert(ai.m_field30 == 0);

    printf("TACTICAL_AI_MATRIX_TEST_5_FUNC_1760_SCAN_NODES_PASSED\n");
}

static void test_tactical_ai_func_1760_null_out() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    s_1a20_result = 1;

    Field20Elem f20;
    memset(&f20, 0, sizeof(f20));
    f20.field_A = 0;
    ai.m_field20 = &f20;

    Field24Elem f24;
    memset(&f24, 0, sizeof(f24));
    ai.m_field24 = &f24;

    int res = func_00141760(&ai, 0, 0);

    assert(res == 1);
    assert(ai.m_active_node == 0);

    printf("TACTICAL_AI_MATRIX_TEST_6_FUNC_1760_NULL_OUT_PASSED\n");
}

static void test_tactical_ai_func_18b0_active() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    SubElement sub;
    memset(&sub, 0, sizeof(sub));
    sub.field_5 = 1;
    ai.m_active_node = &sub;

    int res = func_001418B0(&ai);

    assert(res == 1);
    assert(sub.field_5 == 0);

    printf("TACTICAL_AI_MATRIX_TEST_7_FUNC_18B0_ACTIVE_PASSED\n");
}

static void test_tactical_ai_func_18b0_inactive() {
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.m_active_node = 0;

    int res = func_001418B0(&ai);

    assert(res == 0);

    printf("TACTICAL_AI_MATRIX_TEST_8_FUNC_18B0_INACTIVE_PASSED\n");
}

static void test_tactical_ai_matrix_layout() {
    assert(sizeof(Field20Elem) == 16);
    assert(sizeof(Field24Elem) == 8);
    assert(sizeof(SubElement) == 0x148);
    assert(sizeof(TacticalNodeRecord) == 24);
    assert(offsetof(SubElement, field_5) == 5);
    assert(offsetof(TacticalAI, vtable) == 0);
    assert(offsetof(TacticalAI, m_fieldC) == 0xC);
    assert(offsetof(TacticalAI, m_fieldE) == 0xE);
    assert(offsetof(TacticalAI, m_field10) == 0x10);
    assert(offsetof(TacticalAI, m_field14) == 0x14);
    assert(offsetof(TacticalAI, m_field16) == 0x16);
    assert(offsetof(TacticalAI, m_field18) == 0x18);
    assert(offsetof(TacticalAI, m_field1C) == 0x1C);
    assert(offsetof(TacticalAI, m_field20) == 0x20);
    assert(offsetof(TacticalAI, m_field24) == 0x24);
    assert(offsetof(TacticalAI, m_active_node) == 0x28);
    assert(offsetof(TacticalAI, m_field2C) == 0x2C);
    assert(offsetof(TacticalAI, m_field30) == 0x30);

    printf("TACTICAL_AI_MATRIX_TEST_9_LAYOUT_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-9)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_tactical_ai_func_1500_success();
    else if (mode == 1) test_tactical_ai_func_1500_capacity_full();
    else if (mode == 2) test_tactical_ai_func_1630_invalid_index();
    else if (mode == 3) test_tactical_ai_func_1630_success_reset();
    else if (mode == 4) test_tactical_ai_func_1760_invalid_index();
    else if (mode == 5) test_tactical_ai_func_1760_scan_nodes();
    else if (mode == 6) test_tactical_ai_func_1760_null_out();
    else if (mode == 7) test_tactical_ai_func_18b0_active();
    else if (mode == 8) test_tactical_ai_func_18b0_inactive();
    else if (mode == 9) test_tactical_ai_matrix_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
