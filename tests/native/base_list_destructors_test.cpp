#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

static int func_2639d0_called = 0;
static int cleanup_baselist_called = 0;
static int func_1dc100_called = 0;
static int vec_ctor_called = 0;

extern "C" {
    char D_4D7A90[32] = {1};
    char D_4D7230[32] = {2};

    void func_2639D0(void *a, int b) { (void)a; (void)b; func_2639d0_called++; }
    void Cleanup__8BaseListFi(void *a, int b) { (void)a; (void)b; cleanup_baselist_called++; }
    void func_1DC100(void *a, int b) { (void)a; (void)b; func_1dc100_called++; }
    void __vec_ctor(void *a) { (void)a; vec_ctor_called++; }

    void* func_00139BB0(void *self, int flag);
    void* func_00139C10(void *self, int flag);
}

static void test_base_list_destructors_bb0() {
    char obj[64];
    memset(obj, 0, sizeof(obj));
    func_2639d0_called = 0;
    vec_ctor_called = 0;

    void *res = func_00139BB0(obj, 1);
    assert(res == obj);
    assert(*(void**)obj == (void*)D_4D7A90);
    assert(func_2639d0_called == 1);
    assert(vec_ctor_called == 1);
    printf("BASE_LIST_DESTRUCTORS_TEST_0_BB0_PASSED\n");
}

static void test_base_list_destructors_c10() {
    char obj[64];
    memset(obj, 0, sizeof(obj));
    cleanup_baselist_called = 0;
    func_1dc100_called = 0;
    vec_ctor_called = 0;

    void *res = func_00139C10(obj, 1);
    assert(res == obj);
    assert(*(void**)obj == (void*)D_4D7230);
    assert(cleanup_baselist_called == 1);
    assert(func_1dc100_called == 1);
    assert(vec_ctor_called == 1);
    printf("BASE_LIST_DESTRUCTORS_TEST_1_C10_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-1)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_base_list_destructors_bb0();
    else if (mode == 1) test_base_list_destructors_c10();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
