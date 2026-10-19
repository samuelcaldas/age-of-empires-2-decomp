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
    float m_x;
    float m_y;
    float m_field18;
    float m_field1C;
    float m_field20;
    float m_field24;
    int m_field28;
    char m_name[64];
};

struct SubListConItem : public SubListItemBase {
    int m_field6C;
    int m_field70;
    int m_field74;
    int m_field78;
    int m_field7C;
};

extern "C" {
    char D_4D7640[32] = "D_4D7640_vtable";

    static int s_c660_called = 0;
    static int s_c6d0_called = 0;
    static int s_c710_called = 0;
    static int s_c770_called = 0;
    static int s_vec_ctor_called = 0;

    SubListItemBase* func_0013C660(SubListItemBase *self) {
        s_c660_called++;
        return self;
    }

    void func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                       float f1, float f2, float f3, float f4, float f5, float f6,
                       const char *str) {
        (void)self; (void)a1; (void)a2; (void)a3;
        (void)f1; (void)f2; (void)f3; (void)f4; (void)f5; (void)f6; (void)str;
        s_c6d0_called++;
    }

    void func_0013C710(SubListItemBase *self, SubListItemBase *src) {
        (void)self; (void)src;
        s_c710_called++;
    }

    SubListItemBase* func_0013C770(SubListItemBase *self, int flag) {
        (void)flag;
        s_c770_called++;
        return self;
    }

    void __vec_ctor(void *ptr) {
        (void)ptr;
        s_vec_ctor_called++;
    }

    SubListConItem* func_0013DFB0(SubListConItem *self);
    void func_0013E000(SubListConItem *self, int a1, const char *str,
                       float f12, float f13, float f14,
                       float f15, float f16, float f17);
    void func_0013E050(SubListConItem *self, SubListConItem *src);
    SubListConItem* func_0013E0A0(SubListConItem *self, int flag);
    int func_0013E110(SubListConItem *self, SubListConItem *other);
    int func_0013E160(SubListConItem *self);
    int func_0013E170(SubListConItem *self);
    int func_0013E180(SubListConItem *self);
    void func_0013E190(SubListConItem *self, int val);
    void func_0013E1A0(SubListConItem *self, int val);
    void func_0013E1B0(SubListConItem *self);
    void func_0013E1C0(SubListConItem *self);
    void func_0013E1F0(SubListConItem *self, int val);
}

static void test_sub_list_con_item_ctor() {
    SubListConItem item;
    memset(&item, 0xAA, sizeof(item));
    s_c660_called = 0;

    SubListConItem *res = func_0013DFB0(&item);

    assert(res == &item);
    assert(s_c660_called == 1);
    assert(*(void**)&item == (void*)D_4D7640);
    assert(item.m_field6C == 0);
    assert(item.m_field70 == 0);
    assert(item.m_field74 == 0);
    assert(item.m_field78 == 0);
    assert(item.m_field7C == 0);
    printf("SUB_LIST_CON_ITEM_TEST_0_CTOR_PASSED\n");
}

static void test_sub_list_con_item_init() {
    SubListConItem item;
    memset(&item, 0xBB, sizeof(item));
    s_c6d0_called = 0;

    func_0013E000(&item, 10, "test", 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
    assert(s_c6d0_called == 1);
    assert(item.m_field74 == 0);
    assert(item.m_field78 == 0);
    assert(item.m_field7C == 0);
    assert(item.m_field6C == 0);
    assert(item.m_field70 == 0);
    printf("SUB_LIST_CON_ITEM_TEST_1_INIT_PASSED\n");
}

static void test_sub_list_con_item_copy() {
    SubListConItem dst, src;
    memset(&dst, 0x11, sizeof(dst));
    memset(&src, 0x22, sizeof(src));
    src.m_field74 = 100;
    src.m_field78 = 200;
    src.m_field7C = 300;

    s_c710_called = 0;
    func_0013E050(&dst, &src);
    assert(s_c710_called == 1);
    assert(dst.m_field74 == 100);
    assert(dst.m_field78 == 200);
    assert(dst.m_field7C == 300);
    assert(dst.m_field6C == 0);
    assert(dst.m_field70 == 0);
    printf("SUB_LIST_CON_ITEM_TEST_2_COPY_PASSED\n");
}

static void test_sub_list_con_item_dtor() {
    // Null pointer handling
    SubListConItem *null_res = func_0013E0A0(0, 1);
    assert(null_res == 0);

    // Non-null with flag <= 0
    SubListConItem item1;
    memset(&item1, 0x33, sizeof(item1));
    s_c770_called = 0;
    s_vec_ctor_called = 0;
    SubListConItem *res1 = func_0013E0A0(&item1, 0);
    assert(res1 == &item1);
    assert(*(void**)&item1 == (void*)D_4D7640);
    assert(item1.m_field6C == 0);
    assert(item1.m_field70 == 0);
    assert(s_c770_called == 1);
    assert(s_vec_ctor_called == 0);

    // Non-null with flag > 0 (calls __vec_ctor)
    SubListConItem item2;
    memset(&item2, 0x44, sizeof(item2));
    s_c770_called = 0;
    s_vec_ctor_called = 0;
    SubListConItem *res2 = func_0013E0A0(&item2, 1);
    assert(res2 == &item2);
    assert(s_c770_called == 1);
    assert(s_vec_ctor_called == 1);
    printf("SUB_LIST_CON_ITEM_TEST_3_DTOR_PASSED\n");
}

static void test_sub_list_con_item_pos_eq() {
    SubListConItem a, b;
    memset(&a, 0, sizeof(a));
    memset(&b, 0, sizeof(b));

    a.m_x = 10.0f; a.m_y = 20.0f;
    b.m_x = 10.0f; b.m_y = 20.0f;
    assert(func_0013E110(&a, &b) == 1);

    b.m_x = 15.0f;
    assert(func_0013E110(&a, &b) == 0);

    b.m_x = 10.0f;
    b.m_y = 25.0f;
    assert(func_0013E110(&a, &b) == 0);

    printf("SUB_LIST_CON_ITEM_TEST_4_POS_EQ_PASSED\n");
}

static void test_sub_list_con_item_accessors() {
    SubListConItem item;
    memset(&item, 0, sizeof(item));

    func_0013E190(&item, 123);
    assert(func_0013E160(&item) == 123);

    func_0013E1A0(&item, 456);
    assert(func_0013E170(&item) == 456);

    func_0013E1F0(&item, 10);
    assert(func_0013E180(&item) == 10);

    func_0013E1B0(&item);
    assert(func_0013E180(&item) == 11);

    func_0013E1C0(&item);
    assert(func_0013E180(&item) == 10);

    func_0013E1F0(&item, 0);
    func_0013E1C0(&item); // Underflow clamp
    assert(func_0013E180(&item) == 0);

    printf("SUB_LIST_CON_ITEM_TEST_5_ACCESSORS_PASSED\n");
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
    if (mode == 0) test_sub_list_con_item_ctor();
    else if (mode == 1) test_sub_list_con_item_init();
    else if (mode == 2) test_sub_list_con_item_copy();
    else if (mode == 3) test_sub_list_con_item_dtor();
    else if (mode == 4) test_sub_list_con_item_pos_eq();
    else if (mode == 5) test_sub_list_con_item_accessors();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
