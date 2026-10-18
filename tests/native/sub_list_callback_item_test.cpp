#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

extern "C" {
    struct CallbackItem {
        unsigned char m_type;
        void *m_func;
        unsigned char m_arg1;
        unsigned char m_arg2;
        unsigned char m_arg3;
        unsigned char m_arg4;
    };

    CallbackItem* func_0013C4F0(CallbackItem *self);
    CallbackItem* func_0013C510(CallbackItem *self, int flag);
    void func_0013C560(CallbackItem *self, unsigned char type, void *func,
                       unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4);
    void func_0013C580(CallbackItem *self, int a1, int a2, int a3, int a4);
    unsigned char func_0013C650(CallbackItem *self);

    static int vec_ctor_called = 0;
    static void *vec_ctor_self = 0;

    void __vec_ctor(void *self) {
        vec_ctor_called++;
        vec_ctor_self = self;
    }
}

static int cb0_called = 0;
static void cb0() { cb0_called++; }

static int cb1_called = 0;
static int cb1_arg1 = 0;
static void cb1(int a1) { cb1_called++; cb1_arg1 = a1; }

static int cb2_called = 0;
static int cb2_arg1 = 0, cb2_arg2 = 0;
static void cb2(int a1, int a2) { cb2_called++; cb2_arg1 = a1; cb2_arg2 = a2; }

static int cb3_called = 0;
static int cb3_arg1 = 0, cb3_arg2 = 0, cb3_arg3 = 0;
static void cb3(int a1, int a2, int a3) { cb3_called++; cb3_arg1 = a1; cb3_arg2 = a2; cb3_arg3 = a3; }

static int cb4_called = 0;
static int cb4_arg1 = 0, cb4_arg2 = 0, cb4_arg3 = 0, cb4_arg4 = 0;
static void cb4(int a1, int a2, int a3, int a4) {
    cb4_called++;
    cb4_arg1 = a1; cb4_arg2 = a2; cb4_arg3 = a3; cb4_arg4 = a4;
}

static void test_sub_list_callback_item_ctor() {
    CallbackItem item;
    memset(&item, 0xFF, sizeof(item));

    CallbackItem *res = func_0013C4F0(&item);
    assert(res == &item);
    assert(item.m_type == 0);
    assert(item.m_func == 0);
    assert(item.m_arg1 == 0);
    assert(item.m_arg2 == 0);
    assert(item.m_arg3 == 0);
    assert(item.m_arg4 == 0);
    printf("SUB_LIST_CALLBACK_ITEM_TEST_0_CTOR_PASSED\n");
}

static void test_sub_list_callback_item_dtor_flag_1() {
    CallbackItem item;
    item.m_func = (void*)0x12345678;

    vec_ctor_called = 0;
    CallbackItem *res = func_0013C510(&item, 1);
    assert(res == &item);
    assert(item.m_func == 0);
    assert(vec_ctor_called == 1);
    assert(vec_ctor_self == &item);
    printf("SUB_LIST_CALLBACK_ITEM_TEST_1_DTOR_FLAG1_PASSED\n");
}

static void test_sub_list_callback_item_dtor_flag_0() {
    CallbackItem item;
    item.m_func = (void*)0x12345678;

    vec_ctor_called = 0;
    CallbackItem *res = func_0013C510(&item, 0);
    assert(res == &item);
    assert(item.m_func == 0);
    assert(vec_ctor_called == 0);
    printf("SUB_LIST_CALLBACK_ITEM_TEST_2_DTOR_FLAG0_PASSED\n");
}

static void test_sub_list_callback_item_setter_and_getter() {
    CallbackItem item;
    memset(&item, 0, sizeof(item));

    func_0013C560(&item, 3, (void*)(size_t)cb3, 11, 22, 33, 44);
    assert(item.m_type == 3);
    assert(item.m_func == (void*)(size_t)cb3);
    assert(item.m_arg1 == 11);
    assert(item.m_arg2 == 22);
    assert(item.m_arg3 == 33);
    assert(item.m_arg4 == 44);
    assert(func_0013C650(&item) == 3);
    printf("SUB_LIST_CALLBACK_ITEM_TEST_3_SETTER_GETTER_PASSED\n");
}

static void test_sub_list_callback_item_dispatch() {
    CallbackItem item;

    // Type 0
    cb0_called = 0;
    func_0013C560(&item, 0, (void*)(size_t)cb0, 0, 0, 0, 0);
    func_0013C580(&item, 1, 2, 3, 4);
    assert(cb0_called == 1);

    // Type 1
    cb1_called = 0;
    func_0013C560(&item, 1, (void*)(size_t)cb1, 0, 0, 0, 0);
    func_0013C580(&item, 10, 20, 30, 40);
    assert(cb1_called == 1);
    assert(cb1_arg1 == 10);

    // Type 2
    cb2_called = 0;
    func_0013C560(&item, 2, (void*)(size_t)cb2, 0, 0, 0, 0);
    func_0013C580(&item, 100, 200, 300, 400);
    assert(cb2_called == 1);
    assert(cb2_arg1 == 100);
    assert(cb2_arg2 == 200);

    // Type 3
    cb3_called = 0;
    func_0013C560(&item, 3, (void*)(size_t)cb3, 0, 0, 0, 0);
    func_0013C580(&item, 111, 222, 333, 444);
    assert(cb3_called == 1);
    assert(cb3_arg1 == 111);
    assert(cb3_arg2 == 222);
    assert(cb3_arg3 == 333);

    // Type 4
    cb4_called = 0;
    func_0013C560(&item, 4, (void*)(size_t)cb4, 0, 0, 0, 0);
    func_0013C580(&item, 1000, 2000, 3000, 4000);
    assert(cb4_called == 1);
    assert(cb4_arg1 == 1000);
    assert(cb4_arg2 == 2000);
    assert(cb4_arg3 == 3000);
    assert(cb4_arg4 == 4000);

    printf("SUB_LIST_CALLBACK_ITEM_TEST_4_DISPATCH_PASSED\n");
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
    if (mode == 0) test_sub_list_callback_item_ctor();
    else if (mode == 1) test_sub_list_callback_item_dtor_flag_1();
    else if (mode == 2) test_sub_list_callback_item_dtor_flag_0();
    else if (mode == 3) test_sub_list_callback_item_setter_and_getter();
    else if (mode == 4) test_sub_list_callback_item_dispatch();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
