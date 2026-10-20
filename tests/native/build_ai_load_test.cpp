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
};

extern "C" {
    char D_4D75F0[32] = {1, 1, 1, 1};
    char D_00490C18[32] = "BuildAI";
    float D_004E2F24 = 10.0f;
    float D_004E2AD0 = 5.0f;
    float D_004E2AD4 = 6.0f;

    static int func_001452b0_called = 0;
    static int func_0013c8e0_called = 0;
    static int func_0013ca40_called = 0;
    static int func_001003b0_called = 0;
    static int func_00100340_called = 0;
    static int func_0013dec0_called = 0;
    static int func_00100630_called = 0;
    static int func_00145350_called = 0;
    static int func_00100670_called = 0;
    static int func_0013dac0_called = 0;

    void* func_001452B0(void *self, const char *name, int id, void *p2, void *p1) {
        (void)name; (void)id; (void)p2; (void)p1;
        func_001452b0_called++;
        return self;
    }

    void* func_0013C8E0(void *self) {
        func_0013c8e0_called++;
        return self;
    }

    void* func_0013CA40(void *self, int flag) {
        (void)flag;
        func_0013ca40_called++;
        return self;
    }

    void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count) {
        (void)list; (void)ctor; (void)dtor; (void)elem_size; (void)count;
        func_001003b0_called++;
    }

    void func_00100340(void *list, void *dtor, int elem_size, int count) {
        (void)list; (void)dtor; (void)elem_size; (void)count;
        func_00100340_called++;
    }

    void func_0013DEC0(void *self) {
        (void)self;
        func_0013dec0_called++;
    }

    void func_00100630(void *ptr) {
        (void)ptr;
        func_00100630_called++;
    }

    void func_00145350(void *self, int flag) {
        (void)self; (void)flag;
        func_00145350_called++;
    }

    void func_00100670(void *ptr) {
        (void)ptr;
        func_00100670_called++;
    }

    static char mock_item_storage[0x200];
    void* func_0013DAC0(void *self, int param) {
        (void)self; (void)param;
        func_0013dac0_called++;
        memset(mock_item_storage, 0, sizeof(mock_item_storage));
        return mock_item_storage;
    }

    void func_0013CB70(void*, int) {}
    void func_0013CB60(void*, int) {}
    void func_0013CB80(void*, int) {}
    void func_0013C8D0(void*, int) {}
    void func_0013C880(void*, int) {}
    void func_0013C8A0(void*, float) {}
    void func_0013C8B0(void*, float) {}
    void func_0013C8C0(void*, float) {}
    void func_0013CBF0(void*, int) {}
    void func_0013CC10(void*, int) {}
    void func_0013CC30(void*, int) {}
    void func_0013CC50(void*, unsigned char) {}

    static int read_step = 0;
    static int mock_read_count = 0;
    void func_00226D90(void *stream, void *dst, int size) {
        (void)stream;
        if (!dst || size <= 0) return;
        read_step++;
        if (size == 4) {
            if (read_step == 7) { // count
                *(int*)dst = mock_read_count;
            } else {
                *(int*)dst = 0;
            }
        } else {
            memset(dst, 0, size);
        }
    }

    void* func_0013CDE0(BuildAI *self, void *p1, void *stream);
    void* func_0013D2B0(BuildAI *self, int flag);
}

static void test_build_ai_load_cde0_count0() {
    char storage[sizeof(BuildAI) + 0x1000];
    memset(storage, 0xFF, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    read_step = 0;
    mock_read_count = 0;
    func_001452b0_called = 0;

    void *stream = (void*)0x11223344;
    void *res = func_0013CDE0(self, 0, stream);
    assert(res == self);
    assert(func_001452b0_called == 1);
    assert(*(void**)self == (void*)D_4D75F0);
    printf("BUILD_AI_LOAD_TEST_0_CDE0_COUNT0_PASSED\n");
}

static void test_build_ai_load_cde0_count1() {
    char storage[sizeof(BuildAI) + 0x1000];
    memset(storage, 0xFF, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    read_step = 0;
    mock_read_count = 1;
    func_0013dac0_called = 0;

    void *stream = (void*)0x11223344;
    void *res = func_0013CDE0(self, 0, stream);
    assert(res == self);
    assert(func_0013dac0_called == 1);
    assert(*(void**)((char*)self + 0x11C) == mock_item_storage);
    printf("BUILD_AI_LOAD_TEST_1_CDE0_COUNT1_PASSED\n");
}

static void test_build_ai_load_d2b0_null() {
    void *res = func_0013D2B0(0, 1);
    assert(res == 0);
    printf("BUILD_AI_LOAD_TEST_2_D2B0_NULL_PASSED\n");
}

static void test_build_ai_load_d2b0_flag_1() {
    char storage[sizeof(BuildAI) + 0x1000];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;
    self->m_buffer.m_data = (void*)0x12345678;
    self->m_buffer.m_size = 100;

    func_0013dec0_called = 0;
    func_00100340_called = 0;
    func_00100630_called = 0;
    func_0013ca40_called = 0;
    func_00145350_called = 0;
    func_00100670_called = 0;

    void *res = func_0013D2B0(self, 1);
    assert(res == self);
    assert(func_0013dec0_called == 1);
    assert(func_00100340_called == 1);
    assert(func_00100630_called == 1);
    assert(self->m_buffer.m_data == 0);
    assert(self->m_buffer.m_size == 0);
    assert(func_0013ca40_called == 1);
    assert(func_00145350_called == 1);
    assert(func_00100670_called == 1);
    printf("BUILD_AI_LOAD_TEST_3_D2B0_FLAG1_PASSED\n");
}

static void test_build_ai_load_d2b0_flag_0() {
    char storage[sizeof(BuildAI) + 0x1000];
    memset(storage, 0, sizeof(storage));
    BuildAI *self = (BuildAI*)storage;

    func_00100670_called = 0;
    void *res = func_0013D2B0(self, 0);
    assert(res == self);
    assert(func_00100670_called == 0);
    printf("BUILD_AI_LOAD_TEST_4_D2B0_FLAG0_PASSED\n");
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
    if (mode == 0) test_build_ai_load_cde0_count0();
    else if (mode == 1) test_build_ai_load_cde0_count1();
    else if (mode == 2) test_build_ai_load_d2b0_null();
    else if (mode == 3) test_build_ai_load_d2b0_flag_1();
    else if (mode == 4) test_build_ai_load_d2b0_flag_0();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
