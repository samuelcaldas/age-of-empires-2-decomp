#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct SubListBuildItem {
    char pad[0x6C];
    SubListBuildItem *m_next;
    SubListBuildItem *m_prev;
};

struct BuildAI {
    char pad[0xAC];
    SubListBuildItem m_sentinel;
};

extern "C" {
    static int s_c7c0_type = 0;
    static int s_cab0_cat = 0;
    static int s_cad0_ret = 0;
    static int s_cac0_ret = 0;
    static int s_c7e0_id = 0;

    int func_0013C7C0(void *item) {
        (void)item;
        return s_c7c0_type;
    }

    int func_0013CAB0(void *item) {
        (void)item;
        return s_cab0_cat;
    }

    int func_0013CAD0(void *item) {
        (void)item;
        return s_cad0_ret;
    }

    int func_0013CAC0(void *item) {
        (void)item;
        return s_cac0_ret;
    }

    int func_0013C7E0(void *item) {
        (void)item;
        return s_c7e0_id;
    }

    int func_0013DE00(BuildAI *self, int type, int category);
    void func_0013DEC0(BuildAI *self);
    void* func_0013DF00(BuildAI *self, int id);
    int func_0013DF80(BuildAI *self);
    int func_0013DF90(BuildAI *self);
    int func_0013DFA0(BuildAI *self);
}

static void test_build_ai_query_empty_count() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));
    ai.m_sentinel.m_next = &ai.m_sentinel;
    ai.m_sentinel.m_prev = &ai.m_sentinel;

    int count = func_0013DE00(&ai, 1, 2);
    assert(count == 0);
    printf("BUILD_AI_QUERY_TEST_0_EMPTY_COUNT_PASSED\n");
}

static void test_build_ai_query_count_matches() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));

    SubListBuildItem it1, it2, it3;
    memset(&it1, 0, sizeof(it1));
    memset(&it2, 0, sizeof(it2));
    memset(&it3, 0, sizeof(it3));

    ai.m_sentinel.m_next = &it1;
    it1.m_prev = &ai.m_sentinel;
    it1.m_next = &it2;
    it2.m_prev = &it1;
    it2.m_next = &it3;
    it3.m_prev = &it2;
    it3.m_next = &ai.m_sentinel;
    ai.m_sentinel.m_prev = &it3;

    // Matching type and category
    s_c7c0_type = 5;
    s_cab0_cat = 10;
    // CAD0 returns 1 -> should count
    s_cad0_ret = 1;
    s_cac0_ret = 0;

    int count1 = func_0013DE00(&ai, 5, 10);
    assert(count1 == 3);

    // Now test CAC0 returns 1 when CAD0 returns 0
    s_cad0_ret = 0;
    s_cac0_ret = 1;
    int count2 = func_0013DE00(&ai, 5, 10);
    assert(count2 == 3);

    // Both return 0 -> should not count
    s_cad0_ret = 0;
    s_cac0_ret = 0;
    int count3 = func_0013DE00(&ai, 5, 10);
    assert(count3 == 0);

    // Type mismatch -> should not count
    s_cad0_ret = 1;
    int count4 = func_0013DE00(&ai, 999, 10);
    assert(count4 == 0);

    printf("BUILD_AI_QUERY_TEST_1_COUNT_MATCHES_PASSED\n");
}

static void test_build_ai_query_dec0_clear() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));

    SubListBuildItem it1, it2;
    memset(&it1, 0, sizeof(it1));
    memset(&it2, 0, sizeof(it2));

    ai.m_sentinel.m_next = &it1;
    it1.m_prev = &ai.m_sentinel;
    it1.m_next = &it2;
    it2.m_prev = &it1;
    it2.m_next = &ai.m_sentinel;
    ai.m_sentinel.m_prev = &it2;

    func_0013DEC0(&ai);

    assert(it1.m_next == 0);
    assert(it1.m_prev == 0);
    assert(it2.m_next == 0);
    assert(it2.m_prev == 0);
    assert(ai.m_sentinel.m_next == &ai.m_sentinel);
    assert(ai.m_sentinel.m_prev == &ai.m_sentinel);

    printf("BUILD_AI_QUERY_TEST_2_DEC0_CLEAR_PASSED\n");
}

static void test_build_ai_query_df00_find() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));

    SubListBuildItem it1, it2;
    memset(&it1, 0, sizeof(it1));
    memset(&it2, 0, sizeof(it2));

    ai.m_sentinel.m_next = &it1;
    it1.m_prev = &ai.m_sentinel;
    it1.m_next = &it2;
    it2.m_prev = &it1;
    it2.m_next = &ai.m_sentinel;
    ai.m_sentinel.m_prev = &it2;

    // Setup: s_c7e0_id returns 42
    s_c7e0_id = 42;
    void *found = func_0013DF00(&ai, 42);
    assert(found == &it1);

    void *not_found = func_0013DF00(&ai, 999);
    assert(not_found == 0);

    printf("BUILD_AI_QUERY_TEST_3_DF00_FIND_PASSED\n");
}

static void test_build_ai_query_stubs_zero() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));

    assert(func_0013DF80(&ai) == 0);
    assert(func_0013DF90(&ai) == 0);
    assert(func_0013DFA0(&ai) == 0);

    printf("BUILD_AI_QUERY_TEST_4_STUBS_ZERO_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-4)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_build_ai_query_empty_count();
    else if (mode == 1) test_build_ai_query_count_matches();
    else if (mode == 2) test_build_ai_query_dec0_clear();
    else if (mode == 3) test_build_ai_query_df00_find();
    else if (mode == 4) test_build_ai_query_stubs_zero();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
