#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];
};

extern "C" {
    char D_4D76C0[16] = "VTABLE_DIPLOM";
    char D_00490DE8[16] = "DIP_AI_NAME";

    static int s_52b0_called = 0;
    static void *s_52b0_last_self = 0;
    static const char *s_52b0_last_name = 0;
    static int s_52b0_last_id = 0;
    static void *s_52b0_last_p2 = 0;
    static void *s_52b0_last_p1 = 0;

    static int s_5350_called = 0;
    static void *s_5350_last_self = 0;
    static int s_5350_last_flag = 0;

    static int s_6d90_called = 0;
    static void *s_6d90_last_stream = 0;
    static int s_6d90_total_bytes = 0;

    static int s_0670_called = 0;
    static void *s_0670_last_ptr = 0;

    void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1) {
        s_52b0_called++;
        s_52b0_last_self = self;
        s_52b0_last_name = name;
        s_52b0_last_id = id;
        s_52b0_last_p2 = p2;
        s_52b0_last_p1 = p1;
        return self;
    }

    void func_00145350(void *self, int flag) {
        s_5350_called++;
        s_5350_last_self = self;
        s_5350_last_flag = flag;
    }

    void func_00226D90(void *stream, void *dst, int size) {
        s_6d90_called++;
        s_6d90_last_stream = stream;
        s_6d90_total_bytes += size;
        if (size == 4) {
            *(int*)dst = 100 + s_6d90_called;
        } else if (size == 1) {
            *(char*)dst = (char)(50 + s_6d90_called);
        }
    }

    void func_00100670(void *ptr) {
        s_0670_called++;
        s_0670_last_ptr = ptr;
    }

    DiplomacyAI *func_0013F730(DiplomacyAI *self, void *p1, void *p2);
    DiplomacyAI *func_0013F7C0(DiplomacyAI *self, void *p1, void *p2);
    DiplomacyAI *func_0013F890(DiplomacyAI *self, int flag);
    void func_0013F900(DiplomacyAI *self, int val);
}

static void reset_mocks() {
    s_52b0_called = 0;
    s_52b0_last_self = 0;
    s_52b0_last_name = 0;
    s_52b0_last_id = 0;
    s_52b0_last_p2 = 0;
    s_52b0_last_p1 = 0;

    s_5350_called = 0;
    s_5350_last_self = 0;
    s_5350_last_flag = 0;

    s_6d90_called = 0;
    s_6d90_last_stream = 0;
    s_6d90_total_bytes = 0;

    s_0670_called = 0;
    s_0670_last_ptr = 0;
}

static void test_diplomacy_ai_init_f730_base_call() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0xAA, sizeof(ai));

    DiplomacyAI *res = func_0013F730(&ai, (void*)0x1111, (void*)0x2222);

    assert(res == &ai);
    assert(s_52b0_called == 1);
    assert(s_52b0_last_self == &ai);
    assert(s_52b0_last_name == D_00490DE8);
    assert(s_52b0_last_id == 1003);
    assert(s_52b0_last_p2 == (void*)0x2222);
    assert(s_52b0_last_p1 == (void*)0x1111);
    assert(ai.m_vtable == (void*)D_4D76C0);

    assert(ai.m_fieldAC == 0);

    printf("DIPLOMACY_AI_INIT_TEST_0_F730_BASE_CALL_PASSED\n");
}

static void test_diplomacy_ai_init_f730_arrays_init() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0, sizeof(ai));

    DiplomacyAI *res = func_0013F730(&ai, 0, 0);

    assert(res == &ai);
    for (int i = 0; i <= 9; i++) {
        assert(ai.m_fieldB0[i] == 49);
        assert(ai.m_fieldD8[i] == 49);
        assert(ai.m_field100[i] == 1);
    }

    printf("DIPLOMACY_AI_INIT_TEST_1_F730_ARRAYS_INIT_PASSED\n");
}

static void test_diplomacy_ai_init_f7c0_base_call() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0xBB, sizeof(ai));

    DiplomacyAI *res = func_0013F7C0(&ai, (void*)0x3333, (void*)0x4444);

    assert(res == &ai);
    assert(s_52b0_called == 1);
    assert(s_52b0_last_self == &ai);
    assert(s_52b0_last_name == D_00490DE8);
    assert(s_52b0_last_id == 1003);
    assert(s_52b0_last_p2 == (void*)0x3333);
    assert(s_52b0_last_p1 == 0);
    assert(ai.m_vtable == (void*)D_4D76C0);
    assert(ai.m_fieldAC == 0);

    printf("DIPLOMACY_AI_INIT_TEST_2_F7C0_BASE_CALL_PASSED\n");
}

static void test_diplomacy_ai_init_f7c0_stream_reads() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0, sizeof(ai));

    DiplomacyAI *res = func_0013F7C0(&ai, 0, (void*)0x5555);

    assert(res == &ai);
    assert(s_6d90_called == 30);
    assert(s_6d90_last_stream == (void*)0x5555);
    // 10 * (4 + 4 + 1) = 90 bytes
    assert(s_6d90_total_bytes == 90);

    printf("DIPLOMACY_AI_INIT_TEST_3_F7C0_STREAM_READS_PASSED\n");
}

static void test_diplomacy_ai_init_f890_null() {
    reset_mocks();

    DiplomacyAI *res = func_0013F890(0, 1);

    assert(res == 0);
    assert(s_5350_called == 0);
    assert(s_0670_called == 0);

    printf("DIPLOMACY_AI_INIT_TEST_4_F890_NULL_PASSED\n");
}

static void test_diplomacy_ai_init_f890_destructor_nofree() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.m_fieldAC = 5;

    DiplomacyAI *res = func_0013F890(&ai, 0);

    assert(res == &ai);
    assert(ai.m_vtable == (void*)D_4D76C0);
    assert(ai.m_fieldAC == 0);
    assert(s_5350_called == 1);
    assert(s_5350_last_self == &ai);
    assert(s_5350_last_flag == 0);
    assert(s_0670_called == 0);

    printf("DIPLOMACY_AI_INIT_TEST_5_F890_DESTRUCTOR_NOFREE_PASSED\n");
}

static void test_diplomacy_ai_init_f890_destructor_free() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0, sizeof(ai));

    DiplomacyAI *res = func_0013F890(&ai, 1);

    assert(res == &ai);
    assert(s_5350_called == 1);
    assert(s_0670_called == 1);
    assert(s_0670_last_ptr == &ai);

    printf("DIPLOMACY_AI_INIT_TEST_6_F890_DESTRUCTOR_FREE_PASSED\n");
}

static void test_diplomacy_ai_init_f900_set_fieldac() {
    reset_mocks();
    DiplomacyAI ai;
    memset(&ai, 0, sizeof(ai));

    func_0013F900(&ai, 42);

    assert(ai.m_fieldAC == 42);

    printf("DIPLOMACY_AI_INIT_TEST_7_F900_SET_FIELDAC_PASSED\n");
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
    if (mode == 0) test_diplomacy_ai_init_f730_base_call();
    else if (mode == 1) test_diplomacy_ai_init_f730_arrays_init();
    else if (mode == 2) test_diplomacy_ai_init_f7c0_base_call();
    else if (mode == 3) test_diplomacy_ai_init_f7c0_stream_reads();
    else if (mode == 4) test_diplomacy_ai_init_f890_null();
    else if (mode == 5) test_diplomacy_ai_init_f890_destructor_nofree();
    else if (mode == 6) test_diplomacy_ai_init_f890_destructor_free();
    else if (mode == 7) test_diplomacy_ai_init_f900_set_fieldac();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
