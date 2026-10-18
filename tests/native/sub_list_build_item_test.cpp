#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct SubListItemBase {
    void *m_vtable;
    int m_field4;
    int m_field8;
    int m_fieldC;
    float m_field10;
    float m_field14;
    float m_field18;
    float m_field1C;
    float m_field20;
    float m_field24;
    int m_field28;
    char m_name[64];
};

struct SubListBuildItem : public SubListItemBase {
    int m_field6C;
    int m_field70;
    int m_field74;
    int m_field78;
    int m_field7C;
    int m_field80;
    int m_field84;
    int m_targets[3];
    int m_field94;
    int m_field98;
    int m_field9C;
    int m_fieldA0;
    int m_fieldA4;
    int m_fieldA8;
    int pad_AC;
    unsigned char m_fieldB0;
};

extern "C" {
    char D_4D75E0[32] = {7, 7, 7, 7};
    char D_4D75D0[32] = {5, 5, 5, 5};

    static int base_ctor_called = 0;
    static int base_dtor_called = 0;
    static int base_setter_called = 0;
    static int vec_ctor_called = 0;
    static void *vec_ctor_self = 0;

    SubListItemBase* func_0013C660(SubListItemBase *self) {
        base_ctor_called++;
        *(void**)self = D_4D75D0;
        return self;
    }

    void func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                       float f1, float f2, float f3, float f4, float f5, float f6,
                       const char *str) {
        (void)self; (void)a1; (void)a2; (void)a3;
        (void)f1; (void)f2; (void)f3; (void)f4; (void)f5; (void)f6; (void)str;
        base_setter_called++;
    }

    SubListItemBase* func_0013C770(SubListItemBase *self, int flag) {
        (void)flag;
        base_dtor_called++;
        return self;
    }

    void __vec_ctor(void *self) {
        vec_ctor_called++;
        vec_ctor_self = self;
    }

    SubListBuildItem* func_0013C8E0(SubListBuildItem *self);
    void func_0013C960(SubListBuildItem *self, int p74, int a1, int a3,
                       int p78, int p7C, int p84, const char *str,
                       float f12, float f13, float f14,
                       int p88, int p8C, int p90, int pA8);
    SubListBuildItem* func_0013CA40(SubListBuildItem *self, int flag);

    int func_0013CAB0(SubListBuildItem *self);
    int func_0013CAC0(SubListBuildItem *self);
    int func_0013CAD0(SubListBuildItem *self);
    int func_0013CAE0(SubListBuildItem *self);
    int func_0013CAF0(SubListBuildItem *self);
    int func_0013CB00(SubListBuildItem *self);
    int func_0013CB10(SubListBuildItem *self, int idx);
    int func_0013CB50(SubListBuildItem *self);

    void func_0013CB60(SubListBuildItem *self, int val);
    void func_0013CB70(SubListBuildItem *self, int val);
    void func_0013CB80(SubListBuildItem *self, int val);
    void func_0013CB90(SubListBuildItem *self);
    void func_0013CBA0(SubListBuildItem *self);

    int func_0013CBD0(SubListBuildItem *self);
    void func_0013CBE0(SubListBuildItem *self);
    void func_0013CBF0(SubListBuildItem *self, int val);

    int func_0013CC00(SubListBuildItem *self);
    void func_0013CC10(SubListBuildItem *self, int val);

    int func_0013CC20(SubListBuildItem *self);
    void func_0013CC30(SubListBuildItem *self, int val);

    unsigned char func_0013CC40(SubListBuildItem *self);
    void func_0013CC50(SubListBuildItem *self, unsigned char val);
}

static void test_sub_list_build_item_ctor() {
    SubListBuildItem item;
    memset(&item, 0xFF, sizeof(item));

    base_ctor_called = 0;
    SubListBuildItem *res = func_0013C8E0(&item);
    assert(res == &item);
    assert(base_ctor_called == 1);
    assert(*(void**)&item == (void*)D_4D75E0);
    assert(item.m_field6C == 0);
    assert(item.m_field70 == 0);
    assert(item.m_field74 == -1);
    assert(item.m_field84 == -1);
    assert(item.m_targets[0] == -1);
    assert(item.m_targets[1] == -1);
    assert(item.m_targets[2] == -1);
    assert(item.m_field98 == -1);
    assert(item.m_fieldB0 == 0);
    printf("SUB_LIST_BUILD_ITEM_TEST_0_CTOR_PASSED\n");
}

static void test_sub_list_build_item_setter() {
    SubListBuildItem item;
    memset(&item, 0, sizeof(item));

    base_setter_called = 0;
    func_0013C960(&item, 74, 11, 33, 78, 79, 84, "Name",
                  1.0f, 2.0f, 3.0f, 88, 89, 90, 108);

    assert(base_setter_called == 1);
    assert(item.m_field74 == 74);
    assert(item.m_field78 == 78);
    assert(item.m_field7C == 79);
    assert(item.m_field84 == 84);
    assert(item.m_targets[0] == 88);
    assert(item.m_targets[1] == 89);
    assert(item.m_targets[2] == 90);
    assert(item.m_fieldA8 == 108);
    assert(item.m_fieldA0 == 0);
    assert(item.m_fieldA4 == 0);
    assert(item.m_field80 == 0);
    assert(item.m_field98 == -1);
    assert(item.m_fieldB0 == 0);
    printf("SUB_LIST_BUILD_ITEM_TEST_1_SETTER_PASSED\n");
}

static void test_sub_list_build_item_dtor() {
    assert(func_0013CA40(0, 1) == 0);

    SubListBuildItem item;
    item.m_field6C = 99;
    item.m_field70 = 88;

    vec_ctor_called = 0;
    base_dtor_called = 0;
    SubListBuildItem *res = func_0013CA40(&item, 1);
    assert(res == &item);
    assert(*(void**)&item == (void*)D_4D75E0);
    assert(item.m_field6C == 0);
    assert(item.m_field70 == 0);
    assert(base_dtor_called == 1);
    assert(vec_ctor_called == 1);
    assert(vec_ctor_self == &item);

    vec_ctor_called = 0;
    res = func_0013CA40(&item, 0);
    assert(res == &item);
    assert(vec_ctor_called == 0);
    printf("SUB_LIST_BUILD_ITEM_TEST_2_DTOR_PASSED\n");
}

static void test_sub_list_build_item_idx() {
    SubListBuildItem item;
    item.m_targets[0] = 100;
    item.m_targets[1] = 200;
    item.m_targets[2] = 300;

    assert(func_0013CB00(&item) == 100);
    assert(func_0013CB10(&item, 0) == -1);
    assert(func_0013CB10(&item, -1) == -1);
    assert(func_0013CB10(&item, 3) == -1);
    assert(func_0013CB10(&item, 1) == 200);
    assert(func_0013CB10(&item, 2) == 300);
    printf("SUB_LIST_BUILD_ITEM_TEST_3_IDX_PASSED\n");
}

static void test_sub_list_build_item_inc_dec_80() {
    SubListBuildItem item;
    item.m_field80 = 0;

    func_0013CB90(&item);
    assert(item.m_field80 == 1);

    func_0013CBA0(&item);
    assert(item.m_field80 == 0);

    func_0013CBA0(&item); // clamped to 0
    assert(item.m_field80 == 0);
    printf("SUB_LIST_BUILD_ITEM_TEST_4_INC_DEC_80_PASSED\n");
}

static void test_sub_list_build_item_inc_94() {
    SubListBuildItem item;
    item.m_field94 = 10;

    func_0013CBE0(&item);
    assert(item.m_field94 == 11);
    printf("SUB_LIST_BUILD_ITEM_TEST_5_INC_94_PASSED\n");
}

static void test_sub_list_build_item_getters_setters() {
    SubListBuildItem item;
    memset(&item, 0, sizeof(item));

    item.m_field74 = 74;
    assert(func_0013CAB0(&item) == 74);

    func_0013CB60(&item, 160);
    assert(func_0013CAC0(&item) == 160);

    func_0013CB70(&item, 164);
    assert(func_0013CAD0(&item) == 164);

    func_0013CB80(&item, 128);
    assert(func_0013CAE0(&item) == 128);

    item.m_field84 = 132;
    assert(func_0013CAF0(&item) == 132);

    item.m_fieldA8 = 168;
    assert(func_0013CB50(&item) == 168);

    func_0013CBF0(&item, 148);
    assert(func_0013CBD0(&item) == 148);

    func_0013CC10(&item, 152);
    assert(func_0013CC00(&item) == 152);

    func_0013CC30(&item, 156);
    assert(func_0013CC20(&item) == 156);

    func_0013CC50(&item, (unsigned char)220);
    assert(func_0013CC40(&item) == (unsigned char)220);
    printf("SUB_LIST_BUILD_ITEM_TEST_6_GETTERS_SETTERS_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-6)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_build_item_ctor();
    else if (mode == 1) test_sub_list_build_item_setter();
    else if (mode == 2) test_sub_list_build_item_dtor();
    else if (mode == 3) test_sub_list_build_item_idx();
    else if (mode == 4) test_sub_list_build_item_inc_dec_80();
    else if (mode == 5) test_sub_list_build_item_inc_94();
    else if (mode == 6) test_sub_list_build_item_getters_setters();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
