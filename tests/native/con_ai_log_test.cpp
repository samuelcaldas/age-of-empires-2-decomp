#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct ConAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    char pad_B0[0x18];
    char m_name[64];
};

extern "C" {
    static int s_eef0_called = 0;
    static int s_eef0_a1 = 0;
    static int s_eef0_a2 = 0;
    static float s_eef0_f12 = 0.0f;
    static float s_eef0_f13 = 0.0f;
    static float s_eef0_f14 = 0.0f;
    static int s_f650_called = 0;
    static int s_f6c0_called = 0;
    static int s_54c0_called = 0;
    static char s_54c0_last_msg[128];

    extern const char D_00490DA8[8] = "NONE";
    extern const char D_00490DB0[8] = "NULL";
    extern const char D_00490DC0[64] = "There is no construction plan to load.";

    void func_0013EEF0(void *self, int a1, int a2, float f12, float f13, float f14) {
        (void)self;
        s_eef0_called++;
        s_eef0_a1 = a1;
        s_eef0_a2 = a2;
        s_eef0_f12 = f12;
        s_eef0_f13 = f13;
        s_eef0_f14 = f14;
    }

    void func_0013F650(void *self) {
        (void)self;
        s_f650_called++;
    }

    void func_0013F6C0(void *self) {
        (void)self;
        s_f6c0_called++;
    }

    void func_0011B170(char *dst, const char *src, int n) {
        if (dst && src) {
            strncpy(dst, src, n);
            dst[n] = '\0';
        }
    }

    int func_0011AA78(const char *s1, const char *s2) {
        if (!s1 && !s2) return 0;
        if (!s1) return -1;
        if (!s2) return 1;
        return strcmp(s1, s2);
    }

    void func_0011ABBC(char *dst, const char *src) {
        if (dst && src) strcpy(dst, src);
    }

    void func_001454C0(void *self, const char *fmt, ...) {
        (void)self;
        s_54c0_called++;
        if (fmt) {
            strncpy(s_54c0_last_msg, fmt, sizeof(s_54c0_last_msg) - 1);
            s_54c0_last_msg[sizeof(s_54c0_last_msg) - 1] = '\0';
        }
    }

    int func_0013EE20(ConAI *self, const char *name, int a2, int a3, float f12, float f13, float f14);
}

static void reset_mocks() {
    s_eef0_called = 0;
    s_eef0_a1 = 0;
    s_eef0_a2 = 0;
    s_eef0_f12 = 0.0f;
    s_eef0_f13 = 0.0f;
    s_eef0_f14 = 0.0f;
    s_f650_called = 0;
    s_f6c0_called = 0;
    s_54c0_called = 0;
    memset(s_54c0_last_msg, 0, sizeof(s_54c0_last_msg));
}

static void test_con_ai_log_normal_zero_count() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x40];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    self->m_fieldAC = 0;

    int res = func_0013EE20(self, "BuildPlanA", 10, 20, 1.0f, 2.0f, 3.0f);

    assert(res == 1);
    assert(s_eef0_called == 1);
    assert(s_eef0_a1 == 10);
    assert(s_eef0_a2 == 20);
    assert(s_eef0_f12 == 1.0f);
    assert(s_eef0_f13 == 2.0f);
    assert(s_eef0_f14 == 3.0f);
    assert(s_f650_called == 0); // count == 0, so not called
    assert(s_f6c0_called == 1);
    assert(strcmp(self->m_name, "BuildPlanA") == 0);
    assert(s_54c0_called == 0);

    printf("CON_AI_LOG_TEST_0_NORMAL_ZERO_COUNT_PASSED\n");
}

static void test_con_ai_log_normal_nonzero_count() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x40];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    self->m_fieldAC = 5;

    int res = func_0013EE20(self, "CustomPlan", 11, 22, 4.0f, 5.0f, 6.0f);
    assert(res == 1);
    assert(s_eef0_called == 1);
    assert(s_f650_called == 1); // count > 0, so called
    assert(s_f6c0_called == 1);
    assert(strcmp(self->m_name, "CustomPlan") == 0);
    assert(s_54c0_called == 0);

    printf("CON_AI_LOG_TEST_1_NORMAL_NONZERO_COUNT_PASSED\n");
}

static void test_con_ai_log_none_name() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x40];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    self->m_fieldAC = 0;

    int res = func_0013EE20(self, "NONE", 0, 0, 0.0f, 0.0f, 0.0f);
    assert(res == 1);
    assert(s_eef0_called == 1);
    assert(s_f650_called == 0);
    assert(s_f6c0_called == 1);
    assert(strcmp(self->m_name, "NONE") == 0);
    assert(s_54c0_called == 1);
    assert(strcmp(s_54c0_last_msg, "There is no construction plan to load.") == 0);

    printf("CON_AI_LOG_TEST_2_NONE_NAME_PASSED\n");
}

static void test_con_ai_log_empty_name() {
    reset_mocks();
    char storage[sizeof(ConAI) + 0x40];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    self->m_fieldAC = 0;

    int res = func_0013EE20(self, "", 0, 0, 0.0f, 0.0f, 0.0f);
    assert(res == 1);
    assert(s_eef0_called == 1);
    assert(s_f650_called == 0);
    assert(s_f6c0_called == 1);
    assert(strcmp(self->m_name, "NULL") == 0);
    assert(s_54c0_called == 1);
    assert(strcmp(s_54c0_last_msg, "There is no construction plan to load.") == 0);

    printf("CON_AI_LOG_TEST_3_EMPTY_NAME_PASSED\n");
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
    if (mode == 0) test_con_ai_log_normal_zero_count();
    else if (mode == 1) test_con_ai_log_normal_nonzero_count();
    else if (mode == 2) test_con_ai_log_none_name();
    else if (mode == 3) test_con_ai_log_empty_name();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
