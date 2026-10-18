#include "render_manager_config.h"
#include <cassert>
#include <cstdlib>
#include <cstring>

static unsigned char g_snapshot[0xB0];
static int g_187d00_calls = 0;
static int g_188060_calls = 0;

extern "C" {
void *func_192BF0(void *obj, int *size_out) {
    if (!obj) return 0;
    *size_out = 0xB0;
    return g_snapshot;
}

void func_188250(void *, float) {}
void func_188240(void *, unsigned char) {}
void func_188260(void *, const void *) {}
void func_1882B0(void *, unsigned char) {}
void func_1882D0(void *, unsigned char) {}
void func_1882F0(void *, unsigned char, unsigned char, unsigned char) {}
void func_188300(void *, unsigned char) {}
void func_188310(void *, unsigned char) {}
void func_188320(void *, unsigned char) {}
void func_188330(void *, unsigned char) {}
void func_188340(void *, unsigned char) {}
void func_188350(void *, unsigned char) {}
void func_188360(void *, unsigned char) {}
void func_1883C0(void *, unsigned char) {}
void func_1883F0(void *, unsigned char) {}
void func_188020(void *, unsigned char) {}
void func_188490(void *, float) {}
void func_1884B0(void *) {}
void func_1884F0(void *) {}
void func_1884C0(void *) {}
void func_188500(void *) {}
void func_1883B0(void *, int, unsigned char) {}
void func_1883D0(void *, int, unsigned char) {}

float func_188060(void *) { g_188060_calls++; return 1.5f; }
unsigned char func_188070(void *) { return 2; }
const char *func_1880C0(void *) { return "test"; }
char *func_11ABBC(char *dst, const char *src) { return std::strcpy(dst, src); }
unsigned char func_1880D0(void *) { return 0x10; }
unsigned char func_1880E0(void *) { return 0x20; }
unsigned char func_1880F0(void *) { return 0x30; }
unsigned char func_188100(void *) { return 0x40; }
unsigned char func_188110(void *) { return 0x50; }
unsigned char func_188120(void *) { return 0x60; }
unsigned char func_188130(void *) { return 0x70; }
unsigned char func_188140(void *) { return 0x80; }
unsigned char func_188150(void *) { return 0x90; }
unsigned char func_188160(void *) { return 0xA0; }
unsigned char func_1881D0(void *) { return 0xB0; }
unsigned char func_188170(void *) { return 0xC0; }
unsigned char func_1881C0(void *) { return 0xD0; }
unsigned char func_188220(void *) { return 0xE0; }
unsigned char func_188050(void *) { return 0xF0; }
float func_1884E0(void *) { return 3.5f; }
unsigned char func_188510(void *) { return 1; }
unsigned char func_188520(void *) { return 1; }
unsigned char func_1881B0(void *, int idx) { return (unsigned char)idx; }
unsigned char func_1881E0(void *, int idx) { return (unsigned char)(idx + 10); }
}

static void test_load_snapshot_field1ac_null() {
    RenderManagerConfigSnapshot mgr = {};
    mgr.field_1AC = 0;
    func_00187ca0(&mgr);
}

static void test_load_snapshot_field1ac_valid() {
    RenderManagerConfigSnapshot mgr = {};
    mgr.field_1AC = (void *)0x1234;
    std::memset(g_snapshot, 0, sizeof(g_snapshot));
    g_snapshot[0xA5] = 1;
    g_snapshot[0xA6] = 1;
    func_00187ca0(&mgr);
}

static void test_save_snapshot() {
    RenderManagerConfigSnapshot mgr = {};
    unsigned char data[0xB0] = {};
    g_188060_calls = 0;
    func_00187ea0(&mgr, data);
    assert(g_188060_calls == 1);
    assert(*(float *)&data[0] == 1.5f);
    assert(data[4] == 2);
    assert(std::strcmp((char *)&data[5], "test") == 0);
    assert(data[0x85] == 0x10);
    assert(*(float *)&data[0xA8] == 3.5f);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_load_snapshot_field1ac_null(); return 0;
    case 1: test_load_snapshot_field1ac_valid(); return 0;
    case 2: test_save_snapshot(); return 0;
    default: return 1;
    }
}
