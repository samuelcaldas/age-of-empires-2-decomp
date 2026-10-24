#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "kt_file.h"

/* Globals referenced by kt_file */
CdServerState D_4F1508;
char D_4F1540[256];
char D_4F1640[16];
char D_4F1680[16];
CdStreamStatus D_4F16C0;

const char D_48FE38[] = "log1";
const char D_48FE70[] = "log2";
const char D_48FEA0[] = "kt_file.c";
const char D_48FEB0[] = "kind < 4";
const char D_48FEC8[] = "";
const char D_48FED8[] = "";
const char D_48FF08[] = "";
const char D_48FF28[] = "";
const char D_48FF40[] = "";

/* Dispatch tables */
void *D_38C7F8[4];
void *D_38C808[4];
void *D_38C818[4];
void *D_38C828[4];
void *D_38C838[4];
void *D_38C880[16];

/* Mock implementations of helper calls */
int func_0012CB10(int id) {
    return id;
}

int func_0012CB60(void *p) {
    FileRecord *rec = (FileRecord *)p;
    return rec->id;
}

int func_0012CBF8(void *p) {
    /* returns ID at offset 0 */
    return *(int *)p;
}

int func_0012CC20(void *p) {
    /* returns entry stride: 16 bytes */
    return 16;
}

int func_0012CB00(void *p) {
    return 0;
}

int func_0012CC48(void *p) {
    return 1;
}

int func_0012CB90(void *p) {
    return 0;
}

int func_0012CB20(void *p) {
    return (int)p;
}

int func_0012CB08(void *p) {
    return (int)p;
}

int func_0012CB38(void) {
    return 42;
}

int func_0012CAC0(void *p) {
    return 5;
}

int func_0012CAD0(void *p) {
    return (int)p;
}

int func_0012CAE0(void) {
    return 3;
}

int func_0012CAF0(void) {
    return 0;
}

void func_114320(const char *file, int line, const char *msg) {
    /* assert helper */
}

int func_118de0(const char *fmt, ...) {
    return 0;
}

int func_1075C8(int a) { return 0; }
int func_107E08(int a, int b, int c, int d, int e, int f, int g, int h) { return 0; }
int func_10E170(void) { return 0; }
int func_10E518(void) { return 0; }
int func_10EA20(int a) { return 0; }
int func_10ECA0(void *p) { return 0; }
int func_10EF80(int a) { return 0; }
int func_10F178(void *p) { return 0; }
int func_10F240(void) { return 0; }
int func_10F308(void) { return 0; }
int func_10F368(int a, int b, int c, int d) { return 0; }
int func_10F548(void) { return 0; }
int func_10F7D8(void) { return 0; }
int func_10F8A8(void) { return 0; }
int func_10F958(void) { return 0; }
int func_10FA08(void) { return 0; }
int func_10FAB8(void) { return 0; }
int func_10FB50(void) { return 0; }
int func_10FBE8(void) { return 0; }
int func_10FCA0(void) { return 0; }
int func_10FD58(void) { return 0; }

static void test_pure_helpers(void) {
    assert(func_0012D0D0(0) == 0);
    assert(func_0012D0D0(42) == 42);
    assert(func_0012D0D0(-1) == -1);

    assert(func_0012D218(123) == 123);
    assert(func_0012D2D8(999) == 999);

    assert(func_0012D0D8() == 0);
    assert(func_0012D220() == 0);
    assert(func_0012D308() == 0);
    assert(func_0012D4C8() == 0);
    assert(func_0012D988() == 0);
}

static void test_stream_sectors(void) {
    memset(&D_4F16C0, 0, sizeof(D_4F16C0));

    /* Inactive stream */
    D_4F16C0.active = 0;
    D_4F16C0.bytes_remaining = 40960;
    assert(func_0012DA00() == 0);

    /* Active stream, 2048 bytes (1 sector) */
    D_4F16C0.active = 1;
    D_4F16C0.bytes_remaining = 2048;
    assert(func_0012DA00() == 1);

    /* Active stream, 20480 bytes (10 sectors) */
    D_4F16C0.bytes_remaining = 20480;
    assert(func_0012DA00() == 10);

    /* Active stream, 0 bytes */
    D_4F16C0.bytes_remaining = 0;
    assert(func_0012DA00() == 0);
}

static void test_binary_search(void) {
    FileRecord table[5] = {
        {10, 0, 100},
        {20, 0, 200},
        {30, 0, 300},
        {40, 0, 400},
        {50, 0, 500}
    };

    /* Null / empty table */
    assert(func_0012D128(10, NULL, 0) == 0);
    assert(func_0012D128(10, table, 0) == 0);

    /* Lookups */
    assert(func_0012D128(10, table, 5) == (int)&table[0]);
    assert(func_0012D128(30, table, 5) == (int)&table[2]);
    assert(func_0012D128(50, table, 5) == (int)&table[4]);
    assert(func_0012D128(25, table, 5) == 0);
    assert(func_0012D128(5, table, 5) == 0);
    assert(func_0012D128(60, table, 5) == 0);
}

static void test_classify_kind(void) {
    u16 tag_40 = 0x40;
    u16 tag_20 = 0x20;

    assert(func_0012CEA0(NULL) == 3);
    assert(func_0012CEA0(&tag_40) == 1);
    assert(func_0012CEA0(&tag_20) == 2);
}

static void test_state_tables(void) {
    FileRecord recs[3] = {
        {30, 0, 1},
        {10, 0, 2},
        {0, 0, 0}
    };

    void *old = func_0012CCE8((char *)recs);
    assert(D_4F1508.record_count == 2);
    assert(D_4F1508.min_val == 10);
    assert((void *)D_4F1508.record_table == (void *)recs);
}

int main(void) {
    test_pure_helpers();
    test_stream_sectors();
    test_binary_search();
    test_classify_kind();
    test_state_tables();
    printf("All native kt_file tests passed successfully.\n");
    return 0;
}
