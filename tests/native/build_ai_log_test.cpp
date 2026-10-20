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

struct BuildAI {
    void *m_vtable;
    char m_pad4[0xA8];
    char m_buildItem[0xB4];
    int m_field160;
    char m_buf1[257];
    char m_buf2[257];
    char m_buf3[257];
    char m_buf4[257];
    int m_field568;
    BuildAIBuffer m_buffer;
    char m_items[50 * 0xB4];

    void Log();
};

extern "C" {
    char D_00490C30[32] = "LogHeader";
    char D_00490C50[32] = "LogFmt1";
    char D_00490CD0[32] = "LogFmt2";

    static int func_001454c0_called = 0;
    static const char *func_001454c0_last_fmt = 0;
    static int func_0013cad0_ret = 0;

    void func_001454C0(void *obj, const char *fmt, ...) {
        (void)obj;
        func_001454c0_called++;
        func_001454c0_last_fmt = fmt;
    }

    const char *func_0013C7F0(void *item) { (void)item; return "Name"; }
    int func_0013C7C0(void *item) { (void)item; return 1; }
    int func_0013C7D0(void *item) { (void)item; return 2; }
    int func_0013C7E0(void *item) { (void)item; return 3; }
    int func_0013C860(void *item) { (void)item; return 4; }
    int func_0013CAB0(void *item) { (void)item; return 5; }
    int func_0013CAC0(void *item) { (void)item; return 6; }
    int func_0013CAD0(void *item) { (void)item; return func_0013cad0_ret; }
    int func_0013CAE0(void *item) { (void)item; return 8; }
    int func_0013CAF0(void *item) { (void)item; return 9; }
    int func_0013CBD0(void *item) { (void)item; return 10; }
    int func_0013CC00(void *item) { (void)item; return 11; }
    int func_0013CC20(void *item) { (void)item; return 12; }
    unsigned char func_0013CC40(void *item) { (void)item; return 13; }
}

static void test_build_ai_log_empty() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    strcpy(self->m_buf1, "HeaderBuf");
    *(char**)((char*)self + 0x118) = self->m_buildItem;

    func_001454c0_called = 0;
    self->Log();
    assert(func_001454c0_called == 1);
    assert(func_001454c0_last_fmt == D_00490C30);
    printf("BUILD_AI_LOG_TEST_0_EMPTY_PASSED\n");
}

static void test_build_ai_log_item_fmt1() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    char item[0x100];
    memset(item, 0, sizeof(item));
    *(char**)(item + 0x6C) = self->m_buildItem; // next is end
    *(char**)((char*)self + 0x118) = item;

    func_001454c0_called = 0;
    func_0013cad0_ret = 1;
    self->Log();
    assert(func_001454c0_called == 2);
    assert(func_001454c0_last_fmt == D_00490C50);
    printf("BUILD_AI_LOG_TEST_1_ITEM_FMT1_PASSED\n");
}

static void test_build_ai_log_item_fmt2() {
    char storage[sizeof(BuildAI) + 0x100];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    char item[0x100];
    memset(item, 0, sizeof(item));
    *(char**)(item + 0x6C) = self->m_buildItem; // next is end
    *(char**)((char*)self + 0x118) = item;

    func_001454c0_called = 0;
    func_0013cad0_ret = 0; // != 1
    self->Log();
    assert(func_001454c0_called == 2);
    assert(func_001454c0_last_fmt == D_00490CD0);
    printf("BUILD_AI_LOG_TEST_2_ITEM_FMT2_PASSED\n");
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
    if (mode == 0) test_build_ai_log_empty();
    else if (mode == 1) test_build_ai_log_item_fmt1();
    else if (mode == 2) test_build_ai_log_item_fmt2();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
