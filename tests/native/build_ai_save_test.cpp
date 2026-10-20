#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>

struct BuildItemNode {
    char pad_00[0x6C];
    BuildItemNode *m_next;
    char pad_70[0xAC - 0x70];
    int m_fieldAC;
};

struct BuildAI {
    void *m_vtable;
    char pad_04[0xA8];
    BuildItemNode m_sentinel;
    char pad_sentinel[0x160 - (0xAC + sizeof(BuildItemNode))];
    int m_field160;
    char m_buf1[257];
    char m_buf2[257];
    char m_buf3[257];
    char m_buf4[257];
    int m_field568;

    int Save(void *stream);
};

static int func_00226f70_called = 0;
static int last_written_int = 0;
static int write_count_int = 0;

extern "C" {
    void func_00226F70(void *stream, void *src, int size) {
        (void)stream;
        func_00226f70_called++;
        if (src && size == 4) {
            last_written_int = *(int*)src;
            if (func_00226f70_called == 11) {
                write_count_int = *(int*)src;
            }
        }
    }

    char* func_0011ABBC(char *dst, const char *src) {
        if (dst && src) return strcpy(dst, src);
        return dst;
    }

    int func_0011ACD0(const char *str) {
        if (str) return strlen(str);
        return 0;
    }

    char mock_item_name[32] = "ItemName";
    char* func_0013C7F0(void*) { return mock_item_name; }
    int func_0013C7C0(void*) { return 10; }
    int func_0013C7D0(void*) { return 20; }
    int func_0013C7E0(void*) { return 30; }
    float func_0013C800(void*) { return 1.0f; }
    float func_0013C810(void*) { return 2.0f; }
    float func_0013C820(void*) { return 3.0f; }
    float func_0013C830(void*) { return 4.0f; }
    float func_0013C840(void*) { return 5.0f; }
    float func_0013C850(void*) { return 6.0f; }
    int func_0013C860(void*) { return 70; }
    int func_0013CAB0(void*) { return 80; }
    int func_0013CAC0(void*) { return 90; }
    int func_0013CAD0(void*) { return 100; }
    int func_0013CAE0(void*) { return 110; }
    int func_0013CAF0(void*) { return 120; }
    int func_0013CB00(void*) { return 130; }
    int func_0013CB10(void*, int idx) { return 130 + idx; }
    int func_0013CB50(void*) { return 140; }
    int func_0013CBD0(void*) { return 150; }
    int func_0013CC00(void*) { return 160; }
    int func_0013CC20(void*) { return 170; }
    unsigned char func_0013CC40(void*) { return 180; }
}

static void test_build_ai_save_count0() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    self->m_field160 = 123;
    strcpy(self->m_buf1, "Str1");
    strcpy(self->m_buf2, "Str2");
    strcpy(self->m_buf3, "Str3");
    strcpy(self->m_buf4, "Str4");
    self->m_field568 = 456;
    self->m_sentinel.m_next = &self->m_sentinel; // Empty circular list

    func_00226f70_called = 0;
    int res = self->Save((void*)0x11223344);
    assert(res == 1);
    assert(func_00226f70_called == 11);
    assert(write_count_int == 0);
    printf("BUILD_AI_SAVE_TEST_0_COUNT0_PASSED\n");
}

static void test_build_ai_save_count1() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    self->m_field160 = 123;
    strcpy(self->m_buf1, "Str1");
    strcpy(self->m_buf2, "Str2");
    strcpy(self->m_buf3, "Str3");
    strcpy(self->m_buf4, "Str4");
    self->m_field568 = 456;

    BuildItemNode node1;
    memset(&node1, 0, sizeof(node1));
    node1.m_fieldAC = 999;
    self->m_sentinel.m_next = &node1;
    node1.m_next = &self->m_sentinel;

    func_00226f70_called = 0;
    last_written_int = 0;
    int res = self->Save((void*)0x11223344);
    assert(res == 1);
    assert(write_count_int == 1);
    assert(last_written_int == 999);
    assert(func_00226f70_called == 11 + 26);
    printf("BUILD_AI_SAVE_TEST_1_COUNT1_PASSED\n");
}

static void test_build_ai_save_count2() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    self->m_field160 = 123;
    strcpy(self->m_buf1, "Str1");
    strcpy(self->m_buf2, "Str2");
    strcpy(self->m_buf3, "Str3");
    strcpy(self->m_buf4, "Str4");
    self->m_field568 = 456;

    BuildItemNode node1;
    BuildItemNode node2;
    memset(&node1, 0, sizeof(node1));
    memset(&node2, 0, sizeof(node2));
    node1.m_fieldAC = 111;
    node2.m_fieldAC = 888;

    self->m_sentinel.m_next = &node1;
    node1.m_next = &node2;
    node2.m_next = &self->m_sentinel;

    func_00226f70_called = 0;
    last_written_int = 0;
    int res = self->Save((void*)0x11223344);
    assert(res == 1);
    assert(write_count_int == 2);
    assert(last_written_int == 888);
    assert(func_00226f70_called == 11 + 52);
    printf("BUILD_AI_SAVE_TEST_2_COUNT2_PASSED\n");
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
    if (mode == 0) test_build_ai_save_count0();
    else if (mode == 1) test_build_ai_save_count1();
    else if (mode == 2) test_build_ai_save_count2();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
