#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct BuildAIItem {
    char pad_00[0x6C];
    BuildAIItem *m_next;
    BuildAIItem *m_prev;
};

struct BuildAI {
    char pad_00[0x11C];
    BuildAIItem *m_buildItemPrev;
};

extern "C" {
    void func_0013DD80(void *self, void *item);
    void func_0013DDD0(void *self, void *item);
}

static void test_build_ai_list_ops_dd80_null() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));
    func_0013DD80(&ai, 0);
    printf("BUILD_AI_LIST_OPS_TEST_0_DD80_NULL_PASSED\n");
}

static void test_build_ai_list_ops_dd80_relink() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));

    BuildAIItem n1, item, n2;
    memset(&n1, 0, sizeof(n1));
    memset(&item, 0, sizeof(item));
    memset(&n2, 0, sizeof(n2));

    n1.m_next = &item;
    item.m_prev = &n1;
    item.m_next = &n2;
    n2.m_prev = &item;

    BuildAIItem target_prev, target_next;
    memset(&target_prev, 0, sizeof(target_prev));
    memset(&target_next, 0, sizeof(target_next));

    target_prev.m_next = &target_next;
    target_next.m_prev = &target_prev;
    ai.m_buildItemPrev = &target_prev;

    func_0013DD80(&ai, &item);

    assert(n1.m_next == &n2);
    assert(n2.m_prev == &n1);
    assert(item.m_prev == &target_prev);
    assert(item.m_next == &target_next);
    assert(target_prev.m_next == &item);
    assert(target_next.m_prev == &item);

    printf("BUILD_AI_LIST_OPS_TEST_1_DD80_RELINK_PASSED\n");
}

static void test_build_ai_list_ops_ddd0_null() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));
    func_0013DDD0(&ai, 0);
    printf("BUILD_AI_LIST_OPS_TEST_2_DDD0_NULL_PASSED\n");
}

static void test_build_ai_list_ops_ddd0_unlink() {
    BuildAI ai;
    memset(&ai, 0, sizeof(ai));

    BuildAIItem n1, item, n2;
    memset(&n1, 0, sizeof(n1));
    memset(&item, 0, sizeof(item));
    memset(&n2, 0, sizeof(n2));

    n1.m_next = &item;
    item.m_prev = &n1;
    item.m_next = &n2;
    n2.m_prev = &item;

    func_0013DDD0(&ai, &item);

    assert(n1.m_next == &n2);
    assert(n2.m_prev == &n1);
    assert(item.m_next == 0);
    assert(item.m_prev == 0);

    printf("BUILD_AI_LIST_OPS_TEST_3_DDD0_UNLINK_PASSED\n");
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
    if (mode == 0) test_build_ai_list_ops_dd80_null();
    else if (mode == 1) test_build_ai_list_ops_dd80_relink();
    else if (mode == 2) test_build_ai_list_ops_ddd0_null();
    else if (mode == 3) test_build_ai_list_ops_ddd0_unlink();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
