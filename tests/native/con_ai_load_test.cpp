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

    static int s_1452b0_called = 0;
    static int s_dfb0_called = 0;
    static int s_e0a0_called = 0;
    static int s_1003b0_called = 0;
    static int s_100340_called = 0;
    static int s_13f650_called = 0;
    static int s_13f6c0_called = 0;
    static int s_145350_called = 0;
    static int s_100670_called = 0;

    void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1) {
        (void)name; (void)id; (void)p2; (void)p1;
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
        s_e0a0_called++;
        return self;
    }

    void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count) {
        (void)list; (void)ctor; (void)dtor; (void)elem_size; (void)count;
        s_1003b0_called++;
    }

    void func_00100340(void *list, void *dtor, int elem_size, int count) {
        (void)list; (void)dtor; (void)elem_size; (void)count;
        s_100340_called++;
    }

    void func_0013F650(void *self) {
        (void)self;
        s_13f650_called++;
    }

    void func_0013F6C0(void *self) {
        (void)self;
        s_13f6c0_called++;
    }

    void func_00145350(void *self, int flag) {
        (void)self; (void)flag;
        s_145350_called++;
    }

    void func_00100670(void *ptr) {
        (void)ptr;
        s_100670_called++;
    }

    SubListConItem *func_0013E200(ConAI *self) {
        SubListConItem *item = (SubListConItem *)((char *)self + 0x2D0);
        for (int i = 0; i < 10; i++, item = (SubListConItem *)((char *)item + 0x80)) {
            if (item->m_field6C == 0 && item->m_field70 == 0) {
                return item;
            }
        }
        return 0;
    }

    void func_0013E000(SubListConItem *self,
                       float f12, float f13, float f14,
                       float f15, float f16, float f17,
                       int a1, const char *str) {
        (void)f12; (void)f13; (void)f14; (void)f15; (void)f16; (void)f17;
        (void)a1; (void)str;
        if (self && str) {
            strncpy(self->m_name, str, sizeof(self->m_name) - 1);
        }
    }

    void func_0013E190(SubListConItem *self, int val) {
        if (self) self->m_field74 = val;
    }

    void func_0013E1A0(SubListConItem *self, int val) {
        if (self) self->m_field78 = val;
    }

    void func_0013E1F0(SubListConItem *self, int val) {
        if (self) self->m_field7C = val;
    }

    void func_0013C880(void *item, int val) {
        if (item) ((SubListItemBase*)item)->m_field4 = val;
    }

    void func_0013C890(void *item, int val) {
        if (item) ((SubListItemBase*)item)->m_field8 = val;
    }

    void func_0013C8D0(void *item, int val) {
        if (item) ((SubListItemBase*)item)->m_fieldC = val;
    }

    struct StreamMock {
        const unsigned char *data;
        size_t size;
        size_t offset;
    };

    void func_00226D90(void *stream, void *dst, int size) {
        StreamMock *s = (StreamMock*)stream;
        if (s && dst && size > 0) {
            if (s->offset + (size_t)size <= s->size) {
                memcpy(dst, s->data + s->offset, size);
                s->offset += size;
            } else {
                memset(dst, 0, size);
            }
        }
    }

    void *func_0013E370(ConAI *self, void *p1, void *stream);
    void *func_0013E8D0(ConAI *self, int flag);
}

static void test_con_ai_load_empty() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    // Stream layout for empty load:
    // int count1 = 0;
    // int len = 4;
    // char name[4] = "AI1";
    // float fBC = 1.0f;
    // float fC0 = 2.0f;
    // float fC4 = 3.0f;
    // int nB4 = 10;
    // int nB8 = 20;
    // int count2 = 0;

    unsigned char buffer[128];
    memset(buffer, 0, sizeof(buffer));
    size_t off = 0;

    int count1 = 0;
    memcpy(buffer + off, &count1, 4); off += 4;
    int len = 4;
    memcpy(buffer + off, &len, 4); off += 4;
    memcpy(buffer + off, "AI1\0", 4); off += 4;
    float fBC = 1.0f;
    memcpy(buffer + off, &fBC, 4); off += 4;
    float fC0 = 2.0f;
    memcpy(buffer + off, &fC0, 4); off += 4;
    float fC4 = 3.0f;
    memcpy(buffer + off, &fC4, 4); off += 4;
    int nB4 = 10;
    memcpy(buffer + off, &nB4, 4); off += 4;
    int nB8 = 20;
    memcpy(buffer + off, &nB8, 4); off += 4;
    int count2 = 0;
    memcpy(buffer + off, &count2, 4); off += 4;

    StreamMock sm;
    sm.data = buffer;
    sm.size = off;
    sm.offset = 0;

    void *res = func_0013E370(self, (void*)0x1234, &sm);

    assert(res == self);
    assert(*(int*)((char*)self + 0xAC) == 0);
    assert(strcmp((char*)self + 0xC8, "AI1") == 0);
    assert(*(float*)((char*)self + 0xBC) == 1.0f);
    assert(*(float*)((char*)self + 0xC0) == 2.0f);
    assert(*(float*)((char*)self + 0xC4) == 3.0f);
    assert(*(int*)((char*)self + 0xB4) == 10);
    assert(*(int*)((char*)self + 0xB8) == 20);
    assert(*(int*)((char*)self + 0xB0) == 0);

    printf("CON_AI_LOAD_TEST_0_EMPTY_LOAD_PASSED\n");
}

static void test_con_ai_load_items() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    unsigned char buffer[512];
    memset(buffer, 0, sizeof(buffer));
    size_t off = 0;

    int count1 = 1;
    memcpy(buffer + off, &count1, 4); off += 4;
    int len = 4;
    memcpy(buffer + off, &len, 4); off += 4;
    memcpy(buffer + off, "AI1\0", 4); off += 4;
    float fBC = 1.0f;
    memcpy(buffer + off, &fBC, 4); off += 4;
    float fC0 = 2.0f;
    memcpy(buffer + off, &fC0, 4); off += 4;
    float fC4 = 3.0f;
    memcpy(buffer + off, &fC4, 4); off += 4;
    int nB4 = 10;
    memcpy(buffer + off, &nB4, 4); off += 4;
    int nB8 = 20;
    memcpy(buffer + off, &nB8, 4); off += 4;

    // Item 1 fields:
    int ilen1 = 5;
    memcpy(buffer + off, &ilen1, 4); off += 4;
    memcpy(buffer + off, "Item1", 5); off += 5;
    // Align? Note: func_00226D90 reads exact bytes
    int v1_a1 = 1; memcpy(buffer + off, &v1_a1, 4); off += 4;
    int v1_c880 = 2; memcpy(buffer + off, &v1_c880, 4); off += 4;
    int v1_c890 = 3; memcpy(buffer + off, &v1_c890, 4); off += 4;
    float f12 = 1.1f; memcpy(buffer + off, &f12, 4); off += 4;
    float f13 = 1.2f; memcpy(buffer + off, &f13, 4); off += 4;
    float f14 = 1.3f; memcpy(buffer + off, &f14, 4); off += 4;
    float f15 = 1.4f; memcpy(buffer + off, &f15, 4); off += 4;
    float f16 = 1.5f; memcpy(buffer + off, &f16, 4); off += 4;
    float f17 = 1.6f; memcpy(buffer + off, &f17, 4); off += 4;
    int v1_c8d0 = 4; memcpy(buffer + off, &v1_c8d0, 4); off += 4;
    int v1_e190 = 5; memcpy(buffer + off, &v1_e190, 4); off += 4;
    int v1_e1a0 = 6; memcpy(buffer + off, &v1_e1a0, 4); off += 4;
    int v1_e1f0 = 7; memcpy(buffer + off, &v1_e1f0, 4); off += 4;

    // count2 = 1
    int count2 = 1;
    memcpy(buffer + off, &count2, 4); off += 4;

    // Item 2 fields:
    int ilen2 = 5;
    memcpy(buffer + off, &ilen2, 4); off += 4;
    memcpy(buffer + off, "Item2", 5); off += 5;
    int v2_a1 = 11; memcpy(buffer + off, &v2_a1, 4); off += 4;
    int v2_c880 = 12; memcpy(buffer + off, &v2_c880, 4); off += 4;
    int v2_c890 = 13; memcpy(buffer + off, &v2_c890, 4); off += 4;
    float f22 = 2.1f; memcpy(buffer + off, &f22, 4); off += 4;
    float f23 = 2.2f; memcpy(buffer + off, &f23, 4); off += 4;
    float f24 = 2.3f; memcpy(buffer + off, &f24, 4); off += 4;
    float f25 = 2.4f; memcpy(buffer + off, &f25, 4); off += 4;
    float f26 = 2.5f; memcpy(buffer + off, &f26, 4); off += 4;
    float f27 = 2.6f; memcpy(buffer + off, &f27, 4); off += 4;
    int v2_c8d0 = 14; memcpy(buffer + off, &v2_c8d0, 4); off += 4;
    int v2_e190 = 15; memcpy(buffer + off, &v2_e190, 4); off += 4;
    int v2_e1a0 = 16; memcpy(buffer + off, &v2_e1a0, 4); off += 4;
    int v2_e1f0 = 17; memcpy(buffer + off, &v2_e1f0, 4); off += 4;

    StreamMock sm;
    sm.data = buffer;
    sm.size = off;
    sm.offset = 0;

    void *res = func_0013E370(self, (void*)0x5678, &sm);
    assert(res == self);
    assert(*(int*)((char*)self + 0xAC) == 1);
    assert(*(int*)((char*)self + 0xB0) == 1);

    SubListConItem *item1 = (SubListConItem*)((char*)self + 0x2D0);
    assert(item1->m_field74 == 5);
    assert(item1->m_field78 == 6);
    assert(item1->m_field7C == 7);
    assert(item1->m_field4 == 2);
    assert(item1->m_field8 == 3);
    assert(item1->m_fieldC == 4);

    SubListConItem *item2 = (SubListConItem*)((char*)self + 0x2D0 + 0x80);
    assert(item2->m_field74 == 15);
    assert(item2->m_field78 == 16);
    assert(item2->m_field7C == 17);
    assert(item2->m_field4 == 12);
    assert(item2->m_field8 == 13);
    assert(item2->m_fieldC == 14);

    printf("CON_AI_LOAD_TEST_1_ITEMS_LOAD_PASSED\n");
}

static void test_con_ai_load_dtor_null() {
    void *res = func_0013E8D0(0, 1);
    assert(res == 0);
    printf("CON_AI_LOAD_TEST_2_DTOR_NULL_PASSED\n");
}

static void test_con_ai_load_dtor_no_cleanup() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    *(int*)((char*)self + 0xAC) = 0; // count <= 0

    s_13f650_called = 0;
    s_13f6c0_called = 0;
    s_100340_called = 0;
    s_e0a0_called = 0;
    s_145350_called = 0;
    s_100670_called = 0;

    void *res = func_0013E8D0(self, 0);
    assert(res == self);
    assert(s_13f650_called == 0); // Not called when 0xAC <= 0
    assert(s_13f6c0_called == 1);
    assert(s_100340_called == 1);
    assert(s_e0a0_called == 2); // 0x24C and 0x1CC
    assert(s_145350_called == 1);
    assert(s_100670_called == 0); // flag == 0

    printf("CON_AI_LOAD_TEST_3_DTOR_NO_CLEANUP_PASSED\n");
}

static void test_con_ai_load_dtor_full_cleanup() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;
    *(int*)((char*)self + 0xAC) = 5; // count > 0

    s_13f650_called = 0;
    s_13f6c0_called = 0;
    s_100340_called = 0;
    s_e0a0_called = 0;
    s_145350_called = 0;
    s_100670_called = 0;

    void *res = func_0013E8D0(self, 1);
    assert(res == self);
    assert(s_13f650_called == 1); // Called when 0xAC > 0
    assert(s_13f6c0_called == 1);
    assert(s_100340_called == 1);
    assert(s_e0a0_called == 2);
    assert(s_145350_called == 1);
    assert(s_100670_called == 1); // flag > 0

    printf("CON_AI_LOAD_TEST_4_DTOR_FULL_CLEANUP_PASSED\n");
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
    if (mode == 0) test_con_ai_load_empty();
    else if (mode == 1) test_con_ai_load_items();
    else if (mode == 2) test_con_ai_load_dtor_null();
    else if (mode == 3) test_con_ai_load_dtor_no_cleanup();
    else if (mode == 4) test_con_ai_load_dtor_full_cleanup();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
