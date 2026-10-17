// Tests for func_276D50 — Milestone 100 (1072B)
// Verifies ActionBuild construction ambient sound/effect creation, proto dispatch, and cleanup.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_6d50.h"

static int g_last_sound_id = -1;
static int g_dc0_called = 0;
static int g_init_called = 0;
static void *g_mock_sound_obj = nullptr;
static void *g_mock_vtable[16];

extern "C" void *func_2C2D20(int sound_id) {
    g_last_sound_id = sound_id;
    return g_mock_sound_obj;
}

extern "C" void func_2C2DC0(void *) {
    g_dc0_called++;
}

static void mock_sound_init(void *, void *, int) {
    g_init_called++;
}

static void setup_test(unsigned char *self, unsigned char *proto, short category, short entity_id, int field_158) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 512);

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif

    std::memcpy(proto + 0xE, &category, sizeof(short));
    std::memcpy(proto + 0x8, &entity_id, sizeof(short));
    std::memcpy(proto + 0x158, &field_158, sizeof(int));

    g_last_sound_id = -1;
    g_dc0_called = 0;
    g_init_called = 0;
}

static void setup_sound_obj(unsigned char *sound_mem) {
    std::memset(sound_mem, 0, 64);
    std::memset(g_mock_vtable, 0, sizeof(g_mock_vtable));
    typedef void (*Fn)(void *, void *, int);
    Fn fn = mock_sound_init;
    std::memcpy((char *)g_mock_vtable + 0x8, &fn, sizeof(void *));

    void *vtable_ptr = g_mock_vtable;
    std::memcpy(sound_mem + 0x4, &vtable_ptr, sizeof(void *));
    g_mock_sound_obj = sound_mem;
}

static void test_cleanup_existing_sound() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 58, 0, 0);

    void *dummy = (void *)0x9999;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x190, &dummy, sizeof(void *));
#else
    std::memcpy(self + 0xC8, &dummy, sizeof(void *));
#endif

    func_276D50(self);
    assert(g_dc0_called == 1);
    printf("PASS test_cleanup_existing_sound\n");
}

static void test_category_36_plays_sound_6() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 0x36, 0, 0);

    func_276D50(self);
    assert(g_last_sound_id == 6);
    assert(g_init_called == 1);
    printf("PASS test_category_36_plays_sound_6\n");
}

static void test_category_33_special_entity() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 0x33, 0x24C, 0);

    func_276D50(self);
    assert(g_last_sound_id == 6);
    assert(g_init_called == 1);
    printf("PASS test_category_33_special_entity\n");
}

static void test_silent_category() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 58, 0, 0);

    func_276D50(self);
    assert(g_last_sound_id == -1);
    printf("PASS test_silent_category\n");
}

static void test_category_4_plays_sound_1() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 4, 0, 0);

    func_276D50(self);
    assert(g_last_sound_id == 1);
    printf("PASS test_category_4_plays_sound_1\n");
}

static void test_category_52_plays_sound_8() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 52, 0, 0);

    func_276D50(self);
    assert(g_last_sound_id == 8);
    printf("PASS test_category_52_plays_sound_8\n");
}

static void test_category_49_field_158() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);

    setup_test(self, proto, 49, 0, -1);
    func_276D50(self);
    assert(g_last_sound_id == 0);

    setup_test(self, proto, 49, 0, 10);
    func_276D50(self);
    assert(g_last_sound_id == 8);
    printf("PASS test_category_49_field_158\n");
}

static void test_default_sound_7() {
    unsigned char self[512], proto[512], sound[64];
    setup_sound_obj(sound);
    setup_test(self, proto, 99, 0, 0);

    func_276D50(self);
    assert(g_last_sound_id == 7);
    printf("PASS test_default_sound_7\n");
}

int main() {
    test_cleanup_existing_sound();
    test_category_36_plays_sound_6();
    test_category_33_special_entity();
    test_silent_category();
    test_category_4_plays_sound_1();
    test_category_52_plays_sound_8();
    test_category_49_field_158();
    test_default_sound_7();
    printf("All unit_action_build_6d50 tests passed!\n");
    return 0;
}
