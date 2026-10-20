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

    SubListConItem* GetSentinel1() { return &this->m_sentinel1; }
    SubListConItem* GetSentinel2() { return &this->m_sentinel2; }

    int Save(void *stream);
};

extern "C" {
    static int s_write_count = 0;
    static int s_last_write_size = 0;
    static unsigned char s_last_write_data[64];

    void func_00226F70(void *stream, void *src, int size) {
        (void)stream;
        s_write_count++;
        s_last_write_size = size;
        if (src && size > 0 && size <= (int)sizeof(s_last_write_data)) {
            memcpy(s_last_write_data, src, size);
        }
    }

    void func_0011ABBC(char *dst, const char *src) {
        if (dst && src) strcpy(dst, src);
    }

    int func_0011ACD0(const char *str) {
        if (str) return (int)strlen(str);
        return 0;
    }

    const char *func_0013C7F0(void *item) {
        (void)item;
        return "ConItemName";
    }

    int func_0013C7C0(void *item) { (void)item; return 101; }
    int func_0013C7D0(void *item) { (void)item; return 102; }
    int func_0013C7E0(void *item) { (void)item; return 103; }

    float func_0013C800(void *item) { (void)item; return 1.5f; }
    float func_0013C810(void *item) { (void)item; return 2.5f; }
    float func_0013C820(void *item) { (void)item; return 3.5f; }
    float func_0013C830(void *item) { (void)item; return 4.5f; }
    float func_0013C840(void *item) { (void)item; return 5.5f; }
    float func_0013C850(void *item) { (void)item; return 6.5f; }

    int func_0013C860(void *item) { (void)item; return 104; }
    int func_0013E160(void *item) { (void)item; return 105; }
    int func_0013E170(void *item) { (void)item; return 106; }
    int func_0013E180(void *item) { (void)item; return 107; }
}

static void test_con_ai_save_empty() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    strcpy((char*)self + 0xC8, "TestConAI");
    *(SubListConItem**)((char*)self + 0x238) = self->GetSentinel1();
    *(SubListConItem**)((char*)self + 0x2B8) = self->GetSentinel2();

    s_write_count = 0;
    int res = self->Save((void*)0x9999);

    assert(res == 1);
    // 0xAC count(1), len(2), str(3), 0xBC(4), 0xC0(5), 0xC4(6), 0xB4(7), 0xB8(8), 0xB0 count(9)
    assert(s_write_count == 9);

    printf("CON_AI_SAVE_TEST_0_EMPTY_PASSED\n");
}

static void test_con_ai_save_list1_item() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    strcpy((char*)self + 0xC8, "TestConAI");

    SubListConItem item1;
    memset(&item1, 0, sizeof(item1));
    item1.m_field6C = (int)self->GetSentinel1();

    *(SubListConItem**)((char*)self + 0x238) = &item1;
    *(SubListConItem**)((char*)self + 0x2B8) = self->GetSentinel2();

    s_write_count = 0;
    int res = self->Save((void*)0x9999);
    assert(res == 1);
    // 9 header writes + 15 item writes = 24
    assert(s_write_count == 24);

    printf("CON_AI_SAVE_TEST_1_LIST1_ITEM_PASSED\n");
}

static void test_con_ai_save_list2_item() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    strcpy((char*)self + 0xC8, "TestConAI");

    SubListConItem item2;
    memset(&item2, 0, sizeof(item2));
    item2.m_field6C = (int)self->GetSentinel2();

    *(SubListConItem**)((char*)self + 0x238) = self->GetSentinel1();
    *(SubListConItem**)((char*)self + 0x2B8) = &item2;

    s_write_count = 0;
    int res = self->Save((void*)0x9999);
    assert(res == 1);
    assert(s_write_count == 24);

    printf("CON_AI_SAVE_TEST_2_LIST2_ITEM_PASSED\n");
}

static void test_con_ai_save_both_lists() {
    char storage[sizeof(ConAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    ConAI *self = (ConAI*)storage;

    strcpy((char*)self + 0xC8, "TestConAI");

    SubListConItem item1, item2;
    memset(&item1, 0, sizeof(item1));
    memset(&item2, 0, sizeof(item2));
    item1.m_field6C = (int)self->GetSentinel1();
    item2.m_field6C = (int)self->GetSentinel2();

    *(SubListConItem**)((char*)self + 0x238) = &item1;
    *(SubListConItem**)((char*)self + 0x2B8) = &item2;

    s_write_count = 0;
    int res = self->Save((void*)0x9999);
    assert(res == 1);
    // 9 + 15 + 15 = 39
    assert(s_write_count == 39);

    printf("CON_AI_SAVE_TEST_3_BOTH_LISTS_PASSED\n");
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
    if (mode == 0) test_con_ai_save_empty();
    else if (mode == 1) test_con_ai_save_list1_item();
    else if (mode == 2) test_con_ai_save_list2_item();
    else if (mode == 3) test_con_ai_save_both_lists();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
