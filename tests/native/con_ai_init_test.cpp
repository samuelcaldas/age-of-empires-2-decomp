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

struct ConAI {
    void *m_vtable;
    char pad_04[0xC4];
    char m_name[64];
    char pad_108[0xC4];
    SubListConItem m_sentinel1;
    SubListConItem m_sentinel2;
    char pad_2CC[0x4];
    SubListConItem m_items[10];
};

extern "C" {
    char D_4D7650[32] = "D_4D7650_vtable";
    char D_00490D98[32] = "ConAI_Class";
    char D_00490DA0[32] = "ConAI_Name";

    static int s_1452b0_called = 0;
    static int s_dfb0_called = 0;
    static int s_1003b0_called = 0;

    void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1) {
        (void)self; (void)name; (void)id; (void)p2; (void)p1;
        s_1452b0_called++;
        return self;
    }

    SubListConItem *func_0013DFB0(SubListConItem *self) {
        s_dfb0_called++;
        if (self) {
            self->m_field6C = 0;
            self->m_field70 = 0;
        }
        return self;
    }

    SubListConItem *func_0013E0A0(SubListConItem *self, int flag) {
        (void)flag;
        return self;
    }

    void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count) {
        (void)list; (void)ctor; (void)dtor; (void)elem_size; (void)count;
        s_1003b0_called++;
    }

    void func_0011ABBC(char *dst, const char *src) {
        if (dst && src) strcpy(dst, src);
    }

    SubListConItem* func_0013E200(ConAI *self);
    void func_0013E250(ConAI *self, SubListConItem *item);
    void *func_0013E260(void *self, void *p1, void *p2);
}

static void test_con_ai_init_alloc_first() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    SubListConItem *res = func_0013E200(self);

    assert(res == (SubListConItem*)((char*)self + 0x2D0));
    printf("CON_AI_INIT_TEST_0_ALLOC_FIRST_PASSED\n");
}

static void test_con_ai_init_alloc_full() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    // Mark first 3 occupied
    SubListConItem *items = (SubListConItem*)((char*)self + 0x2D0);
    items[0].m_field6C = 1;
    items[1].m_field70 = 2;
    items[2].m_field6C = 3;

    SubListConItem *res = func_0013E200(self);
    assert(res == &items[3]);

    // Mark all 10 occupied
    for (int i = 0; i < 10; i++) {
        items[i].m_field6C = 1;
    }
    assert(func_0013E200(self) == 0);

    printf("CON_AI_INIT_TEST_1_ALLOC_FULL_PASSED\n");
}

static void test_con_ai_init_free() {
    SubListConItem item;
    item.m_field6C = 10;
    item.m_field70 = 20;

    func_0013E250(0, &item);
    assert(item.m_field6C == 0);
    assert(item.m_field70 == 0);

    printf("CON_AI_INIT_TEST_2_FREE_PASSED\n");
}

static void test_con_ai_init_fields() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0xEE, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    s_1452b0_called = 0;
    s_dfb0_called = 0;
    s_1003b0_called = 0;

    void *ret = func_0013E260(self, (void*)0x1111, (void*)0x2222);
    assert(ret == self);
    assert(s_1452b0_called == 1);
    assert(*(void**)self == (void*)D_4D7650);

    assert(*(int*)((char*)self + 0xAC) == 0);
    assert(*(int*)((char*)self + 0xB0) == 0);
    assert(*(int*)((char*)self + 0xB4) == -1);
    assert(*(int*)((char*)self + 0xB8) == -1);
    assert(*(float*)((char*)self + 0xBC) == -1.0f);
    assert(*(float*)((char*)self + 0xC0) == -1.0f);
    assert(*(float*)((char*)self + 0xC4) == -1.0f);

    assert(s_dfb0_called == 2);
    assert(*(int*)((char*)self + 0x2CC) == 0);
    assert(s_1003b0_called == 1);

    assert(*(void**)((char*)self + 0x238) == (char*)self + 0x1CC);
    assert(*(void**)((char*)self + 0x23C) == (char*)self + 0x1CC);
    assert(*(void**)((char*)self + 0x2B8) == (char*)self + 0x24C);
    assert(*(void**)((char*)self + 0x2BC) == (char*)self + 0x24C);
    assert(strcmp((char*)self + 0xC8, "ConAI_Name") == 0);

    printf("CON_AI_INIT_TEST_3_INIT_FIELDS_PASSED\n");
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
    if (mode == 0) test_con_ai_init_alloc_first();
    else if (mode == 1) test_con_ai_init_alloc_full();
    else if (mode == 2) test_con_ai_init_free();
    else if (mode == 3) test_con_ai_init_fields();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
