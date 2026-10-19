#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct EmotionalAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[6];
    char m_buf1[30];
    char m_buf2[30];
    char m_buf3[30];
    char m_buf4[30];
    char m_buf5[30];
    char m_buf6[30];
};

extern "C" {
    char D_4D7710[16] = "VTABLE_EMOT";
    char D_00490DF8[16] = "Emotional AI";
    char D_00490E08[16] = "Aggressive";
    char D_00490E18[16] = "Compassionate";
    char D_00490E28[16] = "Defensive";
    char D_00490E38[16] = "Friendly";
    char D_00490E48[16] = "Passive";
    char D_00490E50[16] = "Vengeful";

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

    static int s_11abbc_called = 0;

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
        }
    }

    void func_00100670(void *ptr) {
        s_0670_called++;
        s_0670_last_ptr = ptr;
    }

    char *func_0011ABBC(char *dst, const char *src) {
        s_11abbc_called++;
        return strcpy(dst, src);
    }

    EmotionalAI *func_00140370(EmotionalAI *self, void *p1, void *p2);
    EmotionalAI *func_00140470(EmotionalAI *self, void *p1, void *p2);
    EmotionalAI *func_00140580(EmotionalAI *self, int flag);
    void func_001405F0(EmotionalAI *self, int val);
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

    s_11abbc_called = 0;
}

static void test_emotional_ai_init_0370_base_call() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0xAA, sizeof(ai));

    EmotionalAI *res = func_00140370(&ai, (void*)0x1111, (void*)0x2222);

    assert(res == &ai);
    assert(s_52b0_called == 1);
    assert(s_52b0_last_self == &ai);
    assert(s_52b0_last_name == D_00490DF8);
    assert(s_52b0_last_id == 1004);
    assert(s_52b0_last_p2 == (void*)0x2222);
    assert(s_52b0_last_p1 == (void*)0x1111);
    assert(ai.m_vtable == (void*)D_4D7710);
    assert(ai.m_fieldAC == 0);

    printf("EMOTIONAL_AI_INIT_TEST_0_0370_BASE_CALL_PASSED\n");
}

static void test_emotional_ai_init_0370_arrays_and_strings() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));

    EmotionalAI *res = func_00140370(&ai, 0, 0);

    assert(res == &ai);
    for (int i = 0; i < 6; i++) {
        assert(ai.m_fieldB0[i] == 49);
    }
    assert(strcmp(ai.m_buf1, "Aggressive") == 0);
    assert(strcmp(ai.m_buf2, "Compassionate") == 0);
    assert(strcmp(ai.m_buf3, "Defensive") == 0);
    assert(strcmp(ai.m_buf4, "Friendly") == 0);
    assert(strcmp(ai.m_buf5, "Passive") == 0);
    assert(strcmp(ai.m_buf6, "Vengeful") == 0);

    printf("EMOTIONAL_AI_INIT_TEST_1_0370_ARRAYS_AND_STRINGS_PASSED\n");
}

static void test_emotional_ai_init_0470_base_call() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0xBB, sizeof(ai));

    EmotionalAI *res = func_00140470(&ai, (void*)0x3333, (void*)0x4444);

    assert(res == &ai);
    assert(s_52b0_called == 1);
    assert(s_52b0_last_self == &ai);
    assert(s_52b0_last_name == D_00490DF8);
    assert(s_52b0_last_id == 1004);
    assert(s_52b0_last_p2 == (void*)0x3333);
    assert(s_52b0_last_p1 == 0);
    assert(ai.m_vtable == (void*)D_4D7710);
    assert(ai.m_fieldAC == 0);

    printf("EMOTIONAL_AI_INIT_TEST_2_0470_BASE_CALL_PASSED\n");
}

static void test_emotional_ai_init_0470_stream_reads_and_strings() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));

    EmotionalAI *res = func_00140470(&ai, 0, (void*)0x5555);

    assert(res == &ai);
    assert(s_6d90_called == 6);
    assert(s_6d90_last_stream == (void*)0x5555);
    assert(s_6d90_total_bytes == 24);
    for (int i = 0; i < 6; i++) {
        assert(ai.m_fieldB0[i] == 100 + (i + 1));
    }
    assert(strcmp(ai.m_buf1, "Aggressive") == 0);
    assert(strcmp(ai.m_buf2, "Compassionate") == 0);
    assert(strcmp(ai.m_buf3, "Defensive") == 0);
    assert(strcmp(ai.m_buf4, "Friendly") == 0);
    assert(strcmp(ai.m_buf5, "Passive") == 0);
    assert(strcmp(ai.m_buf6, "Vengeful") == 0);

    printf("EMOTIONAL_AI_INIT_TEST_3_0470_STREAM_READS_AND_STRINGS_PASSED\n");
}

static void test_emotional_ai_init_0580_null() {
    reset_mocks();

    EmotionalAI *res = func_00140580(0, 1);

    assert(res == 0);
    assert(s_5350_called == 0);
    assert(s_0670_called == 0);

    printf("EMOTIONAL_AI_INIT_TEST_4_0580_NULL_PASSED\n");
}

static void test_emotional_ai_init_0580_destructor_nofree() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.m_fieldAC = 7;

    EmotionalAI *res = func_00140580(&ai, 0);

    assert(res == &ai);
    assert(ai.m_vtable == (void*)D_4D7710);
    assert(ai.m_fieldAC == 0);
    assert(s_5350_called == 1);
    assert(s_5350_last_self == &ai);
    assert(s_5350_last_flag == 0);
    assert(s_0670_called == 0);

    printf("EMOTIONAL_AI_INIT_TEST_5_0580_DESTRUCTOR_NOFREE_PASSED\n");
}

static void test_emotional_ai_init_0580_destructor_free() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));

    EmotionalAI *res = func_00140580(&ai, 1);

    assert(res == &ai);
    assert(s_5350_called == 1);
    assert(s_0670_called == 1);
    assert(s_0670_last_ptr == &ai);

    printf("EMOTIONAL_AI_INIT_TEST_6_0580_DESTRUCTOR_FREE_PASSED\n");
}

static void test_emotional_ai_init_0580_destructor_negative_flag() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));

    EmotionalAI *res = func_00140580(&ai, -1);

    assert(res == &ai);
    assert(s_5350_called == 1);
    assert(s_0670_called == 0);

    printf("EMOTIONAL_AI_INIT_TEST_7_0580_DESTRUCTOR_NEGATIVE_FLAG_PASSED\n");
}

static void test_emotional_ai_init_05f0_set_fieldac() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));

    func_001405F0(&ai, 0x1234);

    assert(ai.m_fieldAC == 0x1234);

    printf("EMOTIONAL_AI_INIT_TEST_8_05F0_SET_FIELDAC_PASSED\n");
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
    if (mode == 0) test_emotional_ai_init_0370_base_call();
    else if (mode == 1) test_emotional_ai_init_0370_arrays_and_strings();
    else if (mode == 2) test_emotional_ai_init_0470_base_call();
    else if (mode == 3) test_emotional_ai_init_0470_stream_reads_and_strings();
    else if (mode == 4) test_emotional_ai_init_0580_null();
    else if (mode == 5) test_emotional_ai_init_0580_destructor_nofree();
    else if (mode == 6) test_emotional_ai_init_0580_destructor_free();
    else if (mode == 7) test_emotional_ai_init_0580_destructor_negative_flag();
    else if (mode == 8) test_emotional_ai_init_05f0_set_fieldac();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
