#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct SubListBuildItemNode {
    char pad_00[0x6C];
    void *m_next;
    void *m_prev;
    char pad_74[0xB4 - 0x74];
};

struct BuildAI {
    void *m_vtable;
    char pad_04[0x578];
    SubListBuildItemNode m_items[50];
};

extern "C" {
    void* func_0013DAC0(BuildAI *self);
}

static void test_build_ai_alloc_item_slot0() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    void *res = func_0013DAC0(self);
    assert(res == (void*)&self->m_items[0]);
    printf("BUILD_AI_ALLOC_ITEM_TEST_0_SLOT0_PASSED\n");
}

static void test_build_ai_alloc_item_skips() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    self->m_items[0].m_next = (void*)0x1111;
    self->m_items[1].m_prev = (void*)0x2222;
    self->m_items[2].m_next = (void*)0x3333;

    void *res = func_0013DAC0(self);
    assert(res == (void*)&self->m_items[3]);
    printf("BUILD_AI_ALLOC_ITEM_TEST_1_SKIPS_PASSED\n");
}

static void test_build_ai_alloc_item_full() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    for (int i = 0; i < 50; i++) {
        self->m_items[i].m_next = (void*)0x9999;
    }

    void *res = func_0013DAC0(self);
    assert(res == 0);
    printf("BUILD_AI_ALLOC_ITEM_TEST_2_FULL_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-2)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_build_ai_alloc_item_slot0();
    else if (mode == 1) test_build_ai_alloc_item_skips();
    else if (mode == 2) test_build_ai_alloc_item_full();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
