#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct BuildAIBuffer {
    void *m_data;
    int m_size;
    int m_cap;
    int m_flags;
};

extern "C" {
    char D_4D75F0[32] = {1, 1, 1, 1};
    char D_00490C18[32] = "BuildAI";
    char D_00490C24[32] = "Str164";
    char D_00490C28[32] = "Str265";

    static int func_001452b0_called = 0;
    static void *func_001452b0_self = 0;
    static int func_0013c8e0_called = 0;
    static void *func_0013c8e0_arg = 0;
    static int func_001003b0_called = 0;
    static void *func_001003b0_list = 0;
    static int func_00100630_called = 0;
    static void *func_00100630_ptr = 0;
    static int func_00100670_called = 0;
    static void *func_00100670_ptr = 0;

    void* func_001452B0(void *self, const char *name, int id, void *p2, void *p1) {
        (void)name; (void)id; (void)p2; (void)p1;
        func_001452b0_called++;
        func_001452b0_self = self;
        return self;
    }

    void* func_0013C8E0(void *self) {
        func_0013c8e0_called++;
        func_0013c8e0_arg = self;
        return self;
    }

    void* func_0013CA40(void *self, int flag) {
        (void)flag;
        return self;
    }

    void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count) {
        (void)ctor; (void)dtor; (void)elem_size; (void)count;
        func_001003b0_called++;
        func_001003b0_list = list;
    }

    void func_0011ABBC(char *dst, const char *src) {
        if (dst && src) {
            strcpy(dst, src);
        }
    }

    void func_00100630(void *ptr) {
        func_00100630_called++;
        func_00100630_ptr = ptr;
    }

    void func_00100670(void *ptr) {
        func_00100670_called++;
        func_00100670_ptr = ptr;
    }

    void* func_0013CC60(void *self, void *p1, void *p2);
    BuildAIBuffer* func_0013CD70(BuildAIBuffer *self, int flag);
}

static void test_build_ai_init_cc60() {
    char storage[0x1000];
    memset(storage, 0xFF, sizeof(storage));

    func_001452b0_called = 0;
    func_0013c8e0_called = 0;
    func_001003b0_called = 0;

    void *p1 = (void*)0x11223344;
    void *p2 = (void*)0x55667788;
    void *res = func_0013CC60(storage, p1, p2);

    assert(res == storage);
    assert(func_001452b0_called == 1);
    assert(func_001452b0_self == storage);
    assert(*(void**)storage == (void*)D_4D75F0);
    assert(func_0013c8e0_called == 1);
    assert(func_0013c8e0_arg == storage + 0xAC);
    assert(*(int*)(storage + 0x160) == 0);
    assert(*(int*)(storage + 0x568) == 0);
    assert(*(int*)(storage + 0x578) == 0);
    assert(func_001003b0_called == 1);
    assert(func_001003b0_list == storage + 0x57C);
    assert(*(void**)(storage + 0x118) == storage + 0xAC);
    assert(*(void**)(storage + 0x11C) == storage + 0xAC);
    assert(strcmp(storage + 0x164, "Str164") == 0);
    assert(strcmp(storage + 0x265, "Str265") == 0);
    printf("BUILD_AI_INIT_TEST_0_CC60_PASSED\n");
}

static void test_build_ai_init_cd70_null() {
    BuildAIBuffer *res = func_0013CD70(0, 1);
    assert(res == 0);
    printf("BUILD_AI_INIT_TEST_1_CD70_NULL_PASSED\n");
}

static void test_build_ai_init_cd70_flag_1() {
    BuildAIBuffer buffer;
    buffer.m_data = (void*)0x12345678;
    buffer.m_size = 10;
    buffer.m_cap = 20;
    buffer.m_flags = 30;

    func_00100630_called = 0;
    func_00100670_called = 0;

    BuildAIBuffer *res = func_0013CD70(&buffer, 1);
    assert(res == &buffer);
    assert(func_00100630_called == 1);
    assert(func_00100630_ptr == (void*)0x12345678);
    assert(buffer.m_data == 0);
    assert(buffer.m_size == 0);
    assert(buffer.m_cap == 0);
    assert(buffer.m_flags == 0);
    assert(func_00100670_called == 1);
    assert(func_00100670_ptr == &buffer);
    printf("BUILD_AI_INIT_TEST_2_CD70_FLAG1_PASSED\n");
}

static void test_build_ai_init_cd70_flag_0() {
    BuildAIBuffer buffer;
    buffer.m_data = (void*)0x12345678;
    buffer.m_size = 10;
    buffer.m_cap = 20;
    buffer.m_flags = 30;

    func_00100630_called = 0;
    func_00100670_called = 0;

    BuildAIBuffer *res = func_0013CD70(&buffer, 0);
    assert(res == &buffer);
    assert(func_00100630_called == 1);
    assert(buffer.m_data == 0);
    assert(func_00100670_called == 0);
    printf("BUILD_AI_INIT_TEST_3_CD70_FLAG0_PASSED\n");
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
    if (mode == 0) test_build_ai_init_cc60();
    else if (mode == 1) test_build_ai_init_cd70_null();
    else if (mode == 2) test_build_ai_init_cd70_flag_1();
    else if (mode == 3) test_build_ai_init_cd70_flag_0();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
