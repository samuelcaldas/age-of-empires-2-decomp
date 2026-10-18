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

extern "C" {
    char D_4D75D0[32] = {5, 5, 5, 5};
    char D_00490C10[32] = "Initial";

    static int vec_ctor_called = 0;
    static void *vec_ctor_self = 0;

    char* func_0011ABBC(char *dest, const char *src) {
        if (dest && src) {
            return strcpy(dest, src);
        }
        return dest;
    }

    char* func_0011B170(char *dest, const char *src, int count) {
        if (dest && src && count > 0) {
            strncpy(dest, src, count);
            dest[count] = '\0';
            return dest;
        }
        return dest;
    }

    void __vec_ctor(void *self) {
        vec_ctor_called++;
        vec_ctor_self = self;
    }

    SubListItemBase* func_0013C660(SubListItemBase *self);
    char* func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                        float f1, float f2, float f3, float f4, float f5, float f6,
                        const char *str);
    char* func_0013C710(SubListItemBase *self, SubListItemBase *other);
    SubListItemBase* func_0013C770(SubListItemBase *self, int flag);

    int func_0013C7C0(SubListItemBase *self);
    int func_0013C7D0(SubListItemBase *self);
    int func_0013C7E0(SubListItemBase *self);
    char* func_0013C7F0(SubListItemBase *self);
    float func_0013C800(SubListItemBase *self);
    float func_0013C810(SubListItemBase *self);
    float func_0013C820(SubListItemBase *self);
    float func_0013C830(SubListItemBase *self);
    float func_0013C840(SubListItemBase *self);
    float func_0013C850(SubListItemBase *self);
    int func_0013C860(SubListItemBase *self);

    void func_0013C870(SubListItemBase *self, int val);
    void func_0013C880(SubListItemBase *self, int val);
    void func_0013C890(SubListItemBase *self, int val);
    void func_0013C8A0(SubListItemBase *self, float val);
    void func_0013C8B0(SubListItemBase *self, float val);
    void func_0013C8C0(SubListItemBase *self, float val);
    void func_0013C8D0(SubListItemBase *self, int val);
}

static void test_sub_list_item_base_ctor() {
    SubListItemBase item;
    memset(&item, 0, sizeof(item));

    SubListItemBase *res = func_0013C660(&item);
    assert(res == &item);
    assert(*(void**)&item == (void*)D_4D75D0);
    assert(item.m_field4 == -1);
    assert(item.m_field8 == -1);
    assert(item.m_fieldC == -1);
    assert(item.m_field10 == 0.0f);
    assert(item.m_field28 == 0);
    assert(strcmp(item.m_name, "Initial") == 0);
    printf("SUB_LIST_ITEM_BASE_TEST_0_CTOR_PASSED\n");
}

static void test_sub_list_item_base_setter() {
    SubListItemBase item;
    memset(&item, 0, sizeof(item));

    func_0013C6D0(&item, 10, 20, 30, 1.5f, 2.5f, 3.5f, 4.5f, 5.5f, 6.5f, "TestName");
    assert(item.m_field4 == 10);
    assert(item.m_field8 == 20);
    assert(item.m_fieldC == 30);
    assert(item.m_field10 == 1.5f);
    assert(item.m_field14 == 2.5f);
    assert(item.m_field18 == 3.5f);
    assert(item.m_field1C == 4.5f);
    assert(item.m_field20 == 5.5f);
    assert(item.m_field24 == 6.5f);
    assert(item.m_field28 == 0);
    assert(strcmp(item.m_name, "TestName") == 0);
    printf("SUB_LIST_ITEM_BASE_TEST_1_SETTER_PASSED\n");
}

static void test_sub_list_item_base_copy() {
    SubListItemBase src;
    memset(&src, 0, sizeof(src));
    src.m_field4 = 111;
    src.m_field8 = 222;
    src.m_fieldC = 333;
    src.m_field10 = 7.5f;
    src.m_field28 = 444;
    strcpy(src.m_name, "CopiedName");

    SubListItemBase dst;
    memset(&dst, 0, sizeof(dst));

    func_0013C710(&dst, &src);
    assert(dst.m_field4 == 111);
    assert(dst.m_field8 == 222);
    assert(dst.m_fieldC == 333);
    assert(dst.m_field10 == 7.5f);
    assert(dst.m_field28 == 444);
    assert(strcmp(dst.m_name, "CopiedName") == 0);
    printf("SUB_LIST_ITEM_BASE_TEST_2_COPY_PASSED\n");
}

static void test_sub_list_item_base_dtor() {
    assert(func_0013C770(0, 1) == 0);

    SubListItemBase item;
    vec_ctor_called = 0;
    SubListItemBase *res = func_0013C770(&item, 1);
    assert(res == &item);
    assert(*(void**)&item == (void*)D_4D75D0);
    assert(vec_ctor_called == 1);
    assert(vec_ctor_self == &item);

    vec_ctor_called = 0;
    res = func_0013C770(&item, 0);
    assert(res == &item);
    assert(vec_ctor_called == 0);
    printf("SUB_LIST_ITEM_BASE_TEST_3_DTOR_PASSED\n");
}

static void test_sub_list_item_base_getters() {
    SubListItemBase item;
    memset(&item, 0, sizeof(item));
    item.m_field4 = 4;
    item.m_field8 = 8;
    item.m_fieldC = 12;
    strcpy(item.m_name, "GetterName");
    item.m_field10 = 10.0f;
    item.m_field14 = 14.0f;
    item.m_field18 = 18.0f;
    item.m_field1C = 19.0f;
    item.m_field20 = 20.0f;
    item.m_field24 = 24.0f;
    item.m_field28 = 28;

    assert(func_0013C7C0(&item) == 4);
    assert(func_0013C7D0(&item) == 8);
    assert(func_0013C7E0(&item) == 12);
    assert(strcmp(func_0013C7F0(&item), "GetterName") == 0);
    assert(func_0013C800(&item) == 10.0f);
    assert(func_0013C810(&item) == 14.0f);
    assert(func_0013C820(&item) == 18.0f);
    assert(func_0013C830(&item) == 19.0f);
    assert(func_0013C840(&item) == 20.0f);
    assert(func_0013C850(&item) == 24.0f);
    assert(func_0013C860(&item) == 28);
    printf("SUB_LIST_ITEM_BASE_TEST_4_GETTERS_PASSED\n");
}

static void test_sub_list_item_base_setters() {
    SubListItemBase item;
    memset(&item, 0, sizeof(item));

    func_0013C870(&item, 44);
    assert(item.m_field4 == 44);

    func_0013C880(&item, 88);
    assert(item.m_field8 == 88);

    func_0013C890(&item, 122);
    assert(item.m_fieldC == 122);

    func_0013C8A0(&item, 101.0f);
    assert(item.m_field10 == 101.0f);

    func_0013C8B0(&item, 141.0f);
    assert(item.m_field14 == 141.0f);

    func_0013C8C0(&item, 181.0f);
    assert(item.m_field18 == 181.0f);

    func_0013C8D0(&item, 288);
    assert(item.m_field28 == 288);
    printf("SUB_LIST_ITEM_BASE_TEST_5_SETTERS_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-5)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_item_base_ctor();
    else if (mode == 1) test_sub_list_item_base_setter();
    else if (mode == 2) test_sub_list_item_base_copy();
    else if (mode == 3) test_sub_list_item_base_dtor();
    else if (mode == 4) test_sub_list_item_base_getters();
    else if (mode == 5) test_sub_list_item_base_setters();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
