#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x30];
    void *field_34;
    char pad_38[0x4];
    void **field_3C;
};

struct SpatialBuf {
    char tag;
    char pad;
    short id;
};

extern "C" {
    static int s_11e0_called = 0;
    static void *s_11e0_last_self = 0;
    static int s_11e0_last_a1 = 0;
    static int s_11e0_last_a2 = 0;
    static int s_11e0_ret = 0;

    int func_001411E0(void *self, int a1, int a2) {
        s_11e0_called++;
        s_11e0_last_self = self;
        s_11e0_last_a1 = a1;
        s_11e0_last_a2 = a2;
        return s_11e0_ret;
    }

    static int s_26af90_called = 0;
    static void *s_26af90_last_ptr = 0;
    static int s_26af90_last_a1 = 0;
    static SpatialBuf s_26af90_ret_buf;
    static short s_26af90_override_id = -1;

    void *func_26AF90(void *ptr, int a1, void *a2) {
        s_26af90_called++;
        s_26af90_last_ptr = ptr;
        s_26af90_last_a1 = a1;
        s_26af90_ret_buf = *(SpatialBuf*)a2;
        if (s_26af90_override_id >= 0) {
            s_26af90_ret_buf.id = s_26af90_override_id;
        }
        return &s_26af90_ret_buf;
    }

    static int s_1500_called = 0;
    static void *s_1500_last_self = 0;
    static int s_1500_last_a1 = 0;
    static int s_1500_ret = 0;

    int func_00141500(void *self, int a1) {
        s_1500_called++;
        s_1500_last_self = self;
        s_1500_last_a1 = a1;
        return s_1500_ret;
    }

    static int s_1630_called = 0;
    static void *s_1630_last_self = 0;
    static int s_1630_last_a1 = 0;
    static int s_1630_ret = 1;

    int func_00141630(void *self, int a1) {
        s_1630_called++;
        s_1630_last_self = self;
        s_1630_last_a1 = a1;
        return s_1630_ret;
    }

    static int s_f850_called = 0;
    static int s_f850_last_size = 0;

    void *func_100850(int size) {
        s_f850_called++;
        s_f850_last_size = size;
        void *p = malloc(size > 0 ? size : 1);
        if (p) memset(p, 0xCC, size > 0 ? size : 1);
        return p;
    }

    static int s_26ad90_called = 0;
    static void *s_26ad90_last_ptr = 0;
    static int s_26ad90_last_id = 0;

    void func_26AD90(void *ptr, int id) {
        s_26ad90_called++;
        s_26ad90_last_ptr = ptr;
        s_26ad90_last_id = id;
    }

    static int s_26ae00_called = 0;
    static void *s_26ae00_last_ptr = 0;
    static int s_26ae00_last_val = 0;

    void func_26AE00(void *ptr, int val) {
        s_26ae00_called++;
        s_26ae00_last_ptr = ptr;
        s_26ae00_last_val = val;
        if (ptr) free(ptr);
    }

    int func_001422F0(TacticalAI2 *self, int a1, int a2, int a3);
    int func_00142380(TacticalAI2 *self, int a1);
    int func_00142400(TacticalAI2 *self, int a1);
}

static void reset_mocks() {
    s_11e0_called = 0;
    s_11e0_last_self = 0;
    s_11e0_last_a1 = 0;
    s_11e0_last_a2 = 0;
    s_11e0_ret = 0;

    s_26af90_called = 0;
    s_26af90_last_ptr = 0;
    s_26af90_last_a1 = 0;
    s_26af90_override_id = -1;
    memset(&s_26af90_ret_buf, 0, sizeof(s_26af90_ret_buf));

    s_1500_called = 0;
    s_1500_last_self = 0;
    s_1500_last_a1 = 0;
    s_1500_ret = 0;

    s_1630_called = 0;
    s_1630_last_self = 0;
    s_1630_last_a1 = 0;
    s_1630_ret = 1;

    s_f850_called = 0;
    s_f850_last_size = 0;

    s_26ad90_called = 0;
    s_26ad90_last_ptr = 0;
    s_26ad90_last_id = 0;

    s_26ae00_called = 0;
    s_26ae00_last_ptr = 0;
    s_26ae00_last_val = 0;
}

static void test_tactical_ai_spatial_22f0_fail_11e0() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_11e0_ret = -1;

    int res = func_001422F0(&ai, 1, 2, 3);

    assert(res == 0);
    assert(s_11e0_called == 1);
    assert(s_11e0_last_self == &ai);
    assert(s_11e0_last_a1 == 2);
    assert(s_11e0_last_a2 == 3);
    assert(s_26af90_called == 0);

    assert(s_11e0_called == 1);

    printf("TACTICAL_AI_SPATIAL_TEST_0_22F0_FAIL_11E0_PASSED\n");
}

static void test_tactical_ai_spatial_22f0_match() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_11e0_ret = 77;

    int res = func_001422F0(&ai, 5, 10, 20);

    assert(res == 1);
    assert(s_11e0_called == 1);
    assert(s_26af90_called == 1);
    assert(s_26af90_last_ptr == &ai.field_34);
    assert(s_26af90_last_a1 == 5);

    printf("TACTICAL_AI_SPATIAL_TEST_1_22F0_MATCH_PASSED\n");
}

static void test_tactical_ai_spatial_22f0_mismatch() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_11e0_ret = 77;
    s_26af90_override_id = 99; // mismatch

    int res = func_001422F0(&ai, 5, 10, 20);

    assert(res == 0);
    assert(s_26af90_called == 1);

    printf("TACTICAL_AI_SPATIAL_TEST_2_22F0_MISMATCH_PASSED\n");
}

static void test_tactical_ai_spatial_2380_fail_1500() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_1500_ret = -1;

    int res = func_00142380(&ai, 10);

    assert(res == -1);
    assert(s_1500_called == 1);
    assert(s_1500_last_self == &ai);
    assert(s_1500_last_a1 == 10);
    assert(s_f850_called == 0);

    printf("TACTICAL_AI_SPATIAL_TEST_3_2380_FAIL_1500_PASSED\n");
}

static void test_tactical_ai_spatial_2380_success() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_1500_ret = 2;

    void *elements[4] = {0, 0, 0, 0};
    ai.field_3C = elements;

    int res = func_00142380(&ai, 50);

    assert(res == 2);
    assert(s_1500_called == 1);
    assert(s_f850_called == 1);
    assert(s_f850_last_size == 8);
    assert(s_26ad90_called == 1);
    assert(s_26ad90_last_id == 0xD3);
    assert(ai.field_3C[2] != 0);

    free(ai.field_3C[2]);
    printf("TACTICAL_AI_SPATIAL_TEST_4_2380_SUCCESS_PASSED\n");
}

static void test_tactical_ai_spatial_2400_fail_1630() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_1630_ret = 0;

    int res = func_00142400(&ai, 3);

    assert(res == 0);
    assert(s_1630_called == 1);
    assert(s_f850_called == 0);

    printf("TACTICAL_AI_SPATIAL_TEST_5_2400_FAIL_1630_PASSED\n");
}

static void test_tactical_ai_spatial_2400_success_with_old() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_1630_ret = 1;

    void *old_ptr = malloc(8);
    void *elements[2] = { old_ptr, 0 };
    ai.field_3C = elements;

    int res = func_00142400(&ai, 0);

    assert(res == 1);
    assert(s_1630_called == 1);
    assert(s_26ae00_called == 1);
    assert(s_26ae00_last_ptr == old_ptr);
    assert(s_26ae00_last_val == 1);
    assert(s_f850_called == 1);
    assert(s_f850_last_size == 8);
    assert(s_26ad90_called == 1);
    assert(s_26ad90_last_id == 0xD3);
    assert(ai.field_3C[0] != 0);

    free(ai.field_3C[0]);
    printf("TACTICAL_AI_SPATIAL_TEST_6_2400_SUCCESS_WITH_OLD_PASSED\n");
}

static void test_tactical_ai_spatial_2400_success_null_old() {
    reset_mocks();
    TacticalAI2 ai;
    memset(&ai, 0, sizeof(ai));
    s_1630_ret = 1;

    void *elements[2] = { 0, 0 };
    ai.field_3C = elements;

    int res = func_00142400(&ai, 1);

    assert(res == 1);
    assert(s_26ae00_called == 0); // No old object to delete
    assert(s_f850_called == 1);
    assert(s_26ad90_called == 1);
    assert(ai.field_3C[1] != 0);

    free(ai.field_3C[1]);
    printf("TACTICAL_AI_SPATIAL_TEST_7_2400_SUCCESS_NULL_OLD_PASSED\n");
}

static void test_tactical_ai_spatial_layout() {
    assert(sizeof(SpatialBuf) == 4);
    assert(offsetof(SpatialBuf, tag) == 0);
    assert(offsetof(SpatialBuf, id) == 2);
    assert(offsetof(TacticalAI2, field_34) == 0x34);
    assert(offsetof(TacticalAI2, field_3C) == 0x3C);

    printf("TACTICAL_AI_SPATIAL_TEST_8_LAYOUT_PASSED\n");
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
    if (mode == 0) test_tactical_ai_spatial_22f0_fail_11e0();
    else if (mode == 1) test_tactical_ai_spatial_22f0_match();
    else if (mode == 2) test_tactical_ai_spatial_22f0_mismatch();
    else if (mode == 3) test_tactical_ai_spatial_2380_fail_1500();
    else if (mode == 4) test_tactical_ai_spatial_2380_success();
    else if (mode == 5) test_tactical_ai_spatial_2400_fail_1630();
    else if (mode == 6) test_tactical_ai_spatial_2400_success_with_old();
    else if (mode == 7) test_tactical_ai_spatial_2400_success_null_old();
    else if (mode == 8) test_tactical_ai_spatial_layout();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
