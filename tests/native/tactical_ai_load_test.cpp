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
    SubElement *m_active_node;
    Field20Elem *m_field2C;
    Field24Elem *m_field30;

    TacticalAI* Load(void *stream);
    TacticalAI* Destroy(int flag);
};

struct MockStream {
    const char *buffer;
    size_t size;
    size_t pos;
    int fail_after_bytes;
};

extern "C" {
    char D_4D7758[16] = "VT_TACTICAL";
    char D_00144440[16] = "CTOR_NODE";
    char D_00144470[16] = "DTOR_NODE";

    void func_0013C4F0(void *self) { (void)self; }
    void func_0013C510(void *self) { (void)self; }
    void func_145680(void *self) { (void)self; }
    void func_1456F0(void *self) { (void)self; }

    static int s_read_called = 0;
    static int s_read_bytes_total = 0;

    int func_00226D90(void *stream, void *buf, int size) {
        s_read_called++;
        MockStream *s = (MockStream*)stream;
        if (!s) return 0;
        if (s->fail_after_bytes >= 0 && (int)(s->pos + size) > s->fail_after_bytes) {
            return -1;
        }
        if (s->pos + size <= s->size) {
            memcpy(buf, s->buffer + s->pos, size);
            s->pos += size;
            s_read_bytes_total += size;
            return size;
        }
        return 0;
    }

    static int s_alloc_count = 0;
    void *func_100730(unsigned int size) {
        s_alloc_count++;
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

    static int s_f40_alloc_count = 0;
    void *func_116F40(int size) {
        s_f40_alloc_count++;
        void *p = malloc(size > 0 ? size : 1);
        if (p) memset(p, 0, size > 0 ? size : 1);
        return p;
    }

    static int s_f68_free_count = 0;
    void func_116F68(void *ptr) {
        s_f68_free_count++;
        if (ptr) free(ptr);
    }

    static int s_0630_free_count = 0;
    void func_00100630(void *ptr) {
        s_0630_free_count++;
        if (ptr) free(ptr);
    }

    static int s_vec_delete_count = 0;
    void func_1002A0(void *ptr, void (*dtor)(void*)) {
        (void)dtor;
        s_vec_delete_count++;
        if (ptr) free(ptr);
    }

    static int s_0670_free_count = 0;
    static void *s_0670_last_ptr = 0;
    void func_00100670(void *ptr) {
        s_0670_free_count++;
        s_0670_last_ptr = ptr;
    }

    void *func_001409B0(void *self, void *stream);
    void *func_00140D40(void *self, int flag);
}

static void reset_mocks() {
    s_read_called = 0;
    s_read_bytes_total = 0;
    s_alloc_count = 0;
    s_vec_new_count = 0;
    s_f40_alloc_count = 0;
    s_f68_free_count = 0;
    s_0630_free_count = 0;
    s_vec_delete_count = 0;
    s_0670_free_count = 0;
    s_0670_last_ptr = 0;
}

static void test_tactical_ai_load_basic() {
    reset_mocks();
    char stream_buf[1024];
    memset(stream_buf, 0, sizeof(stream_buf));

    // offset 0: m_field4=2, m_field6=1, pad=0 (8 bytes)
    short *s_ptr = (short*)stream_buf;
    s_ptr[0] = 2; // m_field4
    s_ptr[1] = 1; // m_field6
    s_ptr[2] = 0; s_ptr[3] = 0;

    // string 0: len=4, data="AI01"
    int *i_ptr = (int*)(stream_buf + 8);
    i_ptr[0] = 4;
    memcpy(stream_buf + 12, "AI01", 4);

    // m_fieldC = 3
    short *c_ptr = (short*)(stream_buf + 16);
    c_ptr[0] = 3;

    // m_field14 = 2
    short *c14_ptr = (short*)(stream_buf + 18);
    c14_ptr[0] = 2;

    // m_field1C = 0 (no items in field20/field24)
    short *c1C_ptr = (short*)(stream_buf + 20);
    c1C_ptr[0] = 0;

    MockStream stream;
    stream.buffer = stream_buf;
    stream.size = 22;
    stream.pos = 0;
    stream.fail_after_bytes = -1;

    TacticalAI ai;
    memset(&ai, 0xCC, sizeof(ai));

    TacticalAI *res = (TacticalAI*)func_001409B0(&ai, &stream);

    assert(res == &ai);
    assert(ai.vtable == (void*)D_4D7758);
    assert(ai.m_field4 == 2);
    assert(ai.m_field6 == 1);
    assert(ai.m_field8 != 0);
    assert(strcmp(ai.m_field8[0], "AI01") == 0);
    assert(ai.m_fieldC == 3);
    assert(ai.m_fieldE == 0);
    assert(ai.m_field10 != 0);
    assert(ai.m_field14 == 2);
    assert(ai.m_field16 == 0);
    assert(ai.m_field18 != 0);
    assert(ai.m_field1C == 0);
    assert(ai.m_active_node == 0);
    assert(ai.m_field2C == 0);
    assert(ai.m_field30 == 0);

    // Clean up allocated memory via destructor with flag 0
    func_00140D40(&ai, 0);

    printf("TACTICAL_AI_LOAD_TEST_0_BASIC_PASSED\n");
}

static void test_tactical_ai_load_subelement_alloc() {
    reset_mocks();
    char stream_buf[2048];
    memset(stream_buf, 0, sizeof(stream_buf));

    short *s_ptr = (short*)stream_buf;
    s_ptr[0] = 0; // m_field4
    s_ptr[1] = 0; // m_field6
    s_ptr[2] = 0; s_ptr[3] = 0; // pad

    short *c_ptr = (short*)(stream_buf + 8);
    c_ptr[0] = 0; // m_fieldC

    short *c14_ptr = (short*)(stream_buf + 10);
    c14_ptr[0] = 0; // m_field14

    short *c1C_ptr = (short*)(stream_buf + 12);
    c1C_ptr[0] = 2; // m_field1C = 2

    // Element 0: field_0 = 1, field_8 = 2, field_A = 1
    Field20Elem *f20_0 = (Field20Elem*)(stream_buf + 14);
    f20_0->field_0 = 1;
    f20_0->field_4 = 0;
    f20_0->field_8 = 2;
    f20_0->field_A = 1;
    f20_0->field_C = 0;

    // SubElement 0 of Element 0 (0x148 bytes) immediately follows f20_0
    char *sub_0 = stream_buf + 14 + 16;
    memset(sub_0, 0x55, 0x148);

    // Element 1: field_0 = 0 (inactive), immediately follows sub_0
    Field20Elem *f20_1 = (Field20Elem*)(sub_0 + 0x148);
    f20_1->field_0 = 0;
    f20_1->field_4 = 0;
    f20_1->field_8 = 0;
    f20_1->field_A = 0;
    f20_1->field_C = 0;

    // Now field24 elements (2 * 8 = 16 bytes)
    Field24Elem *f24_0 = (Field24Elem*)((char*)(f20_1 + 1));
    f24_0->field_0 = 3;
    f24_0->field_2 = 1;
    f24_0->field_4 = 0;

    Field24Elem *f24_1 = f24_0 + 1;
    f24_1->field_0 = 0;
    f24_1->field_2 = 0;
    f24_1->field_4 = 0;

    // Short data for f24_0: field_2 * 2 = 2 bytes
    short *f24_0_shorts = (short*)(f24_1 + 1);
    f24_0_shorts[0] = 42;

    size_t total_size = (char*)(f24_0_shorts + 1) - stream_buf;

    MockStream stream;
    stream.buffer = stream_buf;
    stream.size = total_size;
    stream.pos = 0;
    stream.fail_after_bytes = -1;

    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = (TacticalAI*)func_001409B0(&ai, &stream);

    assert(res == &ai);
    assert(ai.m_field1C == 2);
    assert(ai.m_field20[0].field_0 == 1);
    assert(ai.m_field20[0].field_C != 0);
    assert(ai.m_field20[0].field_C[0].data[0] == 0x55);
    assert(ai.m_field20[1].field_0 == 0);
    assert(ai.m_field20[1].field_C == 0);

    func_00140D40(&ai, 0);

    printf("TACTICAL_AI_LOAD_TEST_1_SUBELEMENT_ALLOC_PASSED\n");
}

static void test_tactical_ai_load_field24_padding() {
    reset_mocks();
    char stream_buf[2048];
    memset(stream_buf, 0, sizeof(stream_buf));

    short *s_ptr = (short*)stream_buf;
    s_ptr[0] = 0; s_ptr[1] = 0; s_ptr[2] = 0; s_ptr[3] = 0;

    short *c_ptr = (short*)(stream_buf + 8);
    c_ptr[0] = 0; // m_fieldC
    short *c14_ptr = (short*)(stream_buf + 10);
    c14_ptr[0] = 0; // m_field14
    short *c1C_ptr = (short*)(stream_buf + 12);
    c1C_ptr[0] = 1; // m_field1C = 1

    Field20Elem *f20 = (Field20Elem*)(stream_buf + 14);
    f20->field_0 = 1;
    f20->field_4 = 0;
    f20->field_8 = 1;
    f20->field_A = 0;
    f20->field_C = 0;

    Field24Elem *f24 = (Field24Elem*)(stream_buf + 14 + 16);
    f24->field_0 = 4; // capacity 4
    f24->field_2 = 2; // stored 2
    f24->field_4 = 0;

    short *shorts = (short*)(stream_buf + 14 + 16 + 8);
    shorts[0] = 10;
    shorts[1] = 20;

    size_t total_size = (char*)(shorts + 2) - stream_buf;

    MockStream stream;
    stream.buffer = stream_buf;
    stream.size = total_size;
    stream.pos = 0;
    stream.fail_after_bytes = -1;

    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = (TacticalAI*)func_001409B0(&ai, &stream);

    assert(res == &ai);
    assert(ai.m_field24[0].field_4 != 0);
    assert(ai.m_field24[0].field_4[0] == 10);
    assert(ai.m_field24[0].field_4[1] == 20);
    // Unfilled elements padded with -1
    assert(ai.m_field24[0].field_4[2] == -1);
    assert(ai.m_field24[0].field_4[3] == -1);

    func_00140D40(&ai, 0);

    printf("TACTICAL_AI_LOAD_TEST_2_FIELD24_PADDING_PASSED\n");
}

static void test_tactical_ai_load_stream_fail() {
    reset_mocks();
    char stream_buf[128];
    memset(stream_buf, 0, sizeof(stream_buf));

    MockStream stream;
    stream.buffer = stream_buf;
    stream.size = 128;
    stream.pos = 0;
    // Fail immediately on read
    stream.fail_after_bytes = 0;

    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    TacticalAI *res = (TacticalAI*)func_001409B0(&ai, &stream);

    // Return value is still self even on simulated short stream read
    assert(res == &ai);
    assert(ai.vtable == (void*)D_4D7758);

    func_00140D40(&ai, 0);

    printf("TACTICAL_AI_LOAD_TEST_3_STREAM_FAIL_PASSED\n");
}

static void test_tactical_ai_destroy_null() {
    reset_mocks();

    void *res = func_00140D40(0, 1);

    assert(res == 0);
    assert(s_f68_free_count == 0);
    assert(s_0630_free_count == 0);
    assert(s_vec_delete_count == 0);
    assert(s_0670_free_count == 0);

    printf("TACTICAL_AI_DESTROY_TEST_4_NULL_PASSED\n");
}

static void test_tactical_ai_destroy_flag_zero() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    ai.m_field6 = 2;
    ai.m_field8 = (char**)malloc(2 * sizeof(char*));
    ai.m_field8[0] = (char*)malloc(16);
    ai.m_field8[1] = (char*)malloc(16);

    ai.m_field10 = (TacticalNodeRecord*)malloc(24);
    ai.m_field18 = malloc(12);

    ai.m_field1C = 1;
    ai.m_field20 = (Field20Elem*)malloc(sizeof(Field20Elem));
    ai.m_field20[0].field_0 = 1;
    ai.m_field20[0].field_C = (SubElement*)malloc(sizeof(SubElement));

    ai.m_field24 = (Field24Elem*)malloc(sizeof(Field24Elem));
    ai.m_field24[0].field_4 = (short*)malloc(4 * sizeof(short));

    ai.m_active_node = (SubElement*)0x1234;
    ai.m_field2C = (Field20Elem*)0x5678;
    ai.m_field30 = (Field24Elem*)0x9ABC;

    void *res = func_00140D40(&ai, 0);

    assert(res == &ai);
    assert(ai.vtable == (void*)D_4D7758);
    assert(s_f68_free_count == 2);
    assert(s_vec_delete_count == 3); // field10, field18, field20[0].field_C
    assert(s_0630_free_count == 4);  // field8, field24[0].field_4, field24, field20
    assert(s_0670_free_count == 0);  // flag=0: no delete(this)
    assert(ai.m_active_node == 0);
    assert(ai.m_field2C == 0);
    assert(ai.m_field30 == 0);

    printf("TACTICAL_AI_DESTROY_TEST_5_FLAG_ZERO_PASSED\n");
}

static void test_tactical_ai_destroy_flag_one() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    void *res = func_00140D40(&ai, 1);

    assert(res == &ai);
    assert(s_0670_free_count == 1);
    assert(s_0670_last_ptr == &ai);

    printf("TACTICAL_AI_DESTROY_TEST_6_FLAG_ONE_PASSED\n");
}

static void test_tactical_ai_destroy_flag_negative() {
    reset_mocks();
    TacticalAI ai;
    memset(&ai, 0, sizeof(ai));

    void *res = func_00140D40(&ai, -1);

    assert(res == &ai);
    assert(s_0670_free_count == 0);

    printf("TACTICAL_AI_DESTROY_TEST_7_FLAG_NEGATIVE_PASSED\n");
}

static void test_tactical_ai_load_layout() {
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
    assert(offsetof(TacticalAI, m_active_node) == 0x28);
    assert(offsetof(TacticalAI, m_field2C) == 0x2C);
    assert(offsetof(TacticalAI, m_field30) == 0x30);

    printf("TACTICAL_AI_LOAD_TEST_8_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_load_basic();
    else if (mode == 1) test_tactical_ai_load_subelement_alloc();
    else if (mode == 2) test_tactical_ai_load_field24_padding();
    else if (mode == 3) test_tactical_ai_load_stream_fail();
    else if (mode == 4) test_tactical_ai_destroy_null();
    else if (mode == 5) test_tactical_ai_destroy_flag_zero();
    else if (mode == 6) test_tactical_ai_destroy_flag_one();
    else if (mode == 7) test_tactical_ai_destroy_flag_negative();
    else if (mode == 8) test_tactical_ai_load_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
