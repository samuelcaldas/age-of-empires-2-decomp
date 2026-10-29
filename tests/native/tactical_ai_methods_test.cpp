#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Msg {
    char type;
    char pad;
    short val;
};

struct TacticalAI2Methods {
    void *m_vtable;
    char pad_04[0x18];
    short m_field1C;
    char pad_1E[0x34 - 0x1E];
    char m_field34[8];
    void **m_field3C;
    int m_field40;
    char m_field44[0x25C];
    int m_field2A0;
    int m_field2A4;
    char pad_2A8[0x400];
    int m_field6A8;
    int m_field6AC;
    char pad_6B0[4];
    int m_field6B4;
    char pad_6B8[0x29C8];
    int m_field3080;
};

extern "C" {
    char D_4D7768[16] = "VT_TACTICAL2";

    static int s_26ae00_called = 0;
    static void *s_26ae00_last_ptr = 0;
    static int s_26ae00_last_val = 0;

    void func_26AE00(void *ptr, int val) {
        s_26ae00_called++;
        s_26ae00_last_ptr = ptr;
        s_26ae00_last_val = val;
    }

    static int s_0630_called = 0;
    void func_100630(void *ptr) {
        s_0630_called++;
        if (ptr) free(ptr);
    }
    void func_00100630(void *ptr) {
        func_100630(ptr);
    }

    static int s_1456f0_called = 0;
    static void *s_1456f0_last_ptr = 0;
    static int s_1456f0_last_val = 0;

    void func_1456F0(void *ptr, int val) {
        s_1456f0_called++;
        s_1456f0_last_ptr = ptr;
        s_1456f0_last_val = val;
    }

    static int s_base_dtor_called = 0;
    static void *s_base_dtor_self = 0;
    static int s_base_dtor_val = 0;

    void func_00140D40(void *self, int val) {
        s_base_dtor_called++;
        s_base_dtor_self = self;
        s_base_dtor_val = val;
    }

    static int s_0670_called = 0;
    static void *s_0670_last_ptr = 0;

    void func_100670(void *self) {
        s_0670_called++;
        s_0670_last_ptr = self;
    }
    void func_00100670(void *self) {
        func_100670(self);
    }

    static int s_26af90_called = 0;
    static void *s_26af90_last_ptr = 0;
    static int s_26af90_last_a1 = 0;
    static int s_26af90_override_val = -1;
    static Msg s_26af90_ret_msg;

    Msg *func_26AF90(void *ptr, int a1, Msg *a2) {
        s_26af90_called++;
        s_26af90_last_ptr = ptr;
        s_26af90_last_a1 = a1;
        s_26af90_ret_msg = *a2; // default mirror
        if (s_26af90_override_val >= 0) {
            s_26af90_ret_msg.val = (short)s_26af90_override_val;
        }
        return &s_26af90_ret_msg;
    }

    static int s_save_called = 0;
    static void *s_save_last_self = 0;
    static void *s_save_last_stream = 0;

    void Save__10TacticalAIFPv(void *self, void *stream) {
        s_save_called++;
        s_save_last_self = self;
        s_save_last_stream = stream;
    }

    void* func_00141F60(void *self, int flag);
    void func_00142050(void *self, void *stream);
    int func_00142060(void *self, int a1, int a2);
    int func_001420C0(void *self, int a1, int a2);
}

static void reset_mocks() {
    s_26ae00_called = 0;
    s_26ae00_last_ptr = 0;
    s_26ae00_last_val = 0;
    s_0630_called = 0;
    s_1456f0_called = 0;
    s_1456f0_last_ptr = 0;
    s_1456f0_last_val = 0;
    s_base_dtor_called = 0;
    s_base_dtor_self = 0;
    s_base_dtor_val = 0;
    s_0670_called = 0;
    s_0670_last_ptr = 0;
    s_26af90_called = 0;
    s_26af90_last_ptr = 0;
    s_26af90_last_a1 = 0;
    s_26af90_override_val = -1;
    memset(&s_26af90_ret_msg, 0, sizeof(s_26af90_ret_msg));
    s_save_called = 0;
    s_save_last_self = 0;
    s_save_last_stream = 0;
}

static void test_tactical_ai_methods_1f60_null() {
    reset_mocks();

    void *res = func_00141F60(0, 1);

    assert(res == 0);
    assert(s_26ae00_called == 0);
    assert(s_0630_called == 0);
    assert(s_1456f0_called == 0);
    assert(s_base_dtor_called == 0);
    assert(s_0670_called == 0);

    assert(s_base_dtor_called == 0);

    printf("TACTICAL_AI_METHODS_TEST_0_1F60_NULL_PASSED\n");
}

static void test_tactical_ai_methods_1f60_flag_zero() {
    reset_mocks();
    TacticalAI2Methods ai;
    memset(&ai, 0xEE, sizeof(ai));

    ai.m_field1C = 2;
    void **ptrs = (void**)malloc(2 * sizeof(void*));
    ptrs[0] = (void*)0x1111;
    ptrs[1] = 0;
    ai.m_field3C = ptrs;

    void *res = func_00141F60(&ai, 0);

    assert(res == &ai);
    assert(ai.m_vtable == (void*)D_4D7768);
    assert(s_26ae00_called == 2); // 1 for ptrs[0] (val 1), 1 for m_field34 (val -1)
    assert(s_0630_called == 1);   // free m_field3C
    assert(ai.m_field2A0 == 0);
    assert(ai.m_field2A4 == 0);
    assert(ai.m_field6A8 == 0);
    assert(ai.m_field6AC == 0);
    assert(ai.m_field6B4 == 0);
    assert(s_1456f0_called == 1);
    assert(s_1456f0_last_ptr == ai.m_field44);
    assert(s_1456f0_last_val == -1);
    assert(ai.m_field3080 == 0);
    assert(s_base_dtor_called == 1);
    assert(s_base_dtor_self == &ai);
    assert(s_base_dtor_val == 0);
    assert(s_0670_called == 0);   // flag 0: no delete(this)

    printf("TACTICAL_AI_METHODS_TEST_1_1F60_FLAG_ZERO_PASSED\n");
}

static void test_tactical_ai_methods_1f60_flag_one() {
    reset_mocks();
    TacticalAI2Methods ai;
    memset(&ai, 0, sizeof(ai));

    void *res = func_00141F60(&ai, 1);

    assert(res == &ai);
    assert(s_0670_called == 1);
    assert(s_0670_last_ptr == &ai);

    printf("TACTICAL_AI_METHODS_TEST_2_1F60_FLAG_ONE_PASSED\n");
}

static void test_tactical_ai_methods_1f60_flag_negative() {
    reset_mocks();
    TacticalAI2Methods ai;
    memset(&ai, 0, sizeof(ai));

    void *res = func_00141F60(&ai, -1);

    assert(res == &ai);
    assert(s_0670_called == 0);

    printf("TACTICAL_AI_METHODS_TEST_3_1F60_FLAG_NEGATIVE_PASSED\n");
}

static void test_tactical_ai_methods_2050_save() {
    reset_mocks();
    TacticalAI2Methods ai;
    memset(&ai, 0, sizeof(ai));

    func_00142050(&ai, (void*)0x8888);

    assert(s_save_called == 1);
    assert(s_save_last_self == &ai);
    assert(s_save_last_stream == (void*)0x8888);

    printf("TACTICAL_AI_METHODS_TEST_4_2050_SAVE_PASSED\n");
}

static void test_tactical_ai_methods_2060() {
    reset_mocks();
    TacticalAI2Methods ai;
    memset(&ai, 0, sizeof(ai));

    // Case 1: Match
    int res = func_00142060(&ai, 10, 42);
    assert(res == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == ai.m_field34);
    assert(s_26af90_last_a1 == 10);

    // Case 2: Mismatch
    s_26af90_override_val = 999;
    res = func_00142060(&ai, 10, 42);
    assert(res == 0);

    printf("TACTICAL_AI_METHODS_TEST_5_2060_PASSED\n");
}

static void test_tactical_ai_methods_20c0() {
    reset_mocks();
    TacticalAI2Methods ai;
    memset(&ai, 0, sizeof(ai));

    void *elements[2] = { (void*)0x1234, (void*)0x5678 };
    ai.m_field3C = elements;

    // Case 1: Match
    int res = func_001420C0(&ai, 1, 20);
    assert(res == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == (void*)0x5678);
    assert(s_26af90_last_a1 == 20);

    // Case 2: Mismatch
    s_26af90_override_val = 0;
    res = func_001420C0(&ai, 1, 20);
    assert(res == 0);

    printf("TACTICAL_AI_METHODS_TEST_6_20C0_PASSED\n");
}

static void test_tactical_ai_methods_layout() {
    assert(offsetof(TacticalAI2Methods, m_vtable) == 0);
    assert(offsetof(TacticalAI2Methods, m_field1C) == 0x1C);
    assert(offsetof(TacticalAI2Methods, m_field34) == 0x34);
    assert(offsetof(TacticalAI2Methods, m_field3C) == 0x3C);
    assert(offsetof(TacticalAI2Methods, m_field44) == 0x44);
    assert(offsetof(TacticalAI2Methods, m_field2A0) == 0x2A0);
    assert(offsetof(TacticalAI2Methods, m_field2A4) == 0x2A4);
    assert(offsetof(TacticalAI2Methods, m_field6A8) == 0x6A8);
    assert(offsetof(TacticalAI2Methods, m_field6AC) == 0x6AC);
    assert(offsetof(TacticalAI2Methods, m_field6B4) == 0x6B4);
    assert(offsetof(TacticalAI2Methods, m_field3080) == 0x3080);
    assert(sizeof(TacticalAI2Methods) == 0x3084);

    printf("TACTICAL_AI_METHODS_TEST_7_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_methods_1f60_null();
    else if (mode == 1) test_tactical_ai_methods_1f60_flag_zero();
    else if (mode == 2) test_tactical_ai_methods_1f60_flag_one();
    else if (mode == 3) test_tactical_ai_methods_1f60_flag_negative();
    else if (mode == 4) test_tactical_ai_methods_2050_save();
    else if (mode == 5) test_tactical_ai_methods_2060();
    else if (mode == 6) test_tactical_ai_methods_20c0();
    else if (mode == 7) test_tactical_ai_methods_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
