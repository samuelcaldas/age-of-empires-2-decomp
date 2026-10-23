#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "dcomp_overlay.h"

/* Mock external calls */
void *func_00100670(void *a0, ...) { (void)a0; return NULL; }
void *func_00114320(void *a0, ...) { (void)a0; return NULL; }
void *func_00117AF8(void *a0, ...) { (void)a0; return NULL; }
void *func_00117CAC(void *a0, ...) { (void)a0; return NULL; }
void *func_00118DE0(void *a0, ...) { (void)a0; return NULL; }
void *func_00118de0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98080(void *a0, ...) { (void)a0; return NULL; }
void *func_01D980B0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D980E0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98190(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98280(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98480(void *a0, ...) { (void)a0; return NULL; }
void *func_01D985A0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D986B0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98860(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98AC0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98B00(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98B70(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98C80(void *a0, ...) { (void)a0; return NULL; }
void *func_01D98D70(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99050(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99170(void *a0, ...) { (void)a0; return NULL; }
void *func_01D991A0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99240(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99310(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99680(void *a0, ...) { (void)a0; return NULL; }
void *func_01D998C0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99B80(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99BD0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D99E20(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9A2D0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9A360(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9A430(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9AB60(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9B120(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9B840(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9B8A0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9B8C0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9B990(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9BB00(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C010(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C030(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C050(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C0B0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C0E0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C110(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C150(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C1A0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C1C0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C210(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C270(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9C300(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9CCE0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9CE10(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9CF90(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9D0D0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9D210(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9D490(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9D610(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9D750(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9DBC0(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9DE90(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9E160(void *a0, ...) { (void)a0; return NULL; }
void *func_01D9ED10(void *a0, ...) { (void)a0; return NULL; }
void *func_01DA0FB0(void *a0, ...) { (void)a0; return NULL; }
void *func_01DA1200(void *a0, ...) { (void)a0; return NULL; }

static void test_dcomp_data_table_integrity(void) {
    assert(DCOMP_DATA_WORD_COUNT == 976);
    assert(DCOMP_DATA_BYTE_SIZE == 3904);
    assert(dcomp_data[0] == 0x010D010D);
    assert(dcomp_data[1] == 0x010D010D);
    assert(dcomp_data[2] == 0x010E010E);
    assert(dcomp_data[3] == 0x010E010E);
}

static void test_dcomp_function_execution(void) {
    int dummy = 42;
    /* Exercise multiple decompiled RMS routines */
    dcomp_func_01D98000(&dummy, (void *)0, (void *)0, (void *)0);
    dcomp_func_01D98024(&dummy, (void *)0, (void *)0, (void *)0);
    dcomp_func_01D9805C(&dummy, (void *)0, (void *)0, (void *)0);
    dcomp_func_01DA1C18(&dummy, (void *)0, (void *)0, (void *)0);
}

int main(void) {
    test_dcomp_data_table_integrity();
    test_dcomp_function_execution();
    puts("All native dcomp tests passed successfully.");
    return 0;
}
