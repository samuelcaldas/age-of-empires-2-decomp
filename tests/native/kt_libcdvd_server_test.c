#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "kt_libcdvd_server.h"

/* Mock external data symbols */
char D_38C7D8[256] = {0};
char D_48E101[256] = {0};
char D_48F4D0[256] = {0};
char D_48F4E0[256] = {0};
char D_48F500[256] = {0};
char D_48F518[256] = {0};
char D_48F540[256] = {0};
char D_48F560[256] = {0};
char D_48F620[256] = {0};
char D_48F630[256] = {0};
char D_48F668[256] = {0};
char D_48F678[256] = {0};
char D_48F698[256] = {0};
char D_48F6C0[256] = {0};
char D_48F6D8[256] = {0};
char D_48F7E8[256] = {0};
char D_48F858[256] = {0};
char D_48F890[256] = {0};
char D_48F8A0[256] = {0};
char D_48F900[256] = {0};
char D_48F930[256] = {0};
char D_48F970[256] = {0};
char D_48F9A0[256] = {0};
char D_48F9C8[256] = {0};
char D_48F9D8[256] = {0};
char D_48FA00[256] = {0};
char D_48FA18[256] = {0};
char D_48FA28[256] = {0};
char D_48FA68[256] = {0};
char D_48FAB0[256] = {0};
char D_48FB68[256] = {0};
char D_48FBA0[256] = {0};
char D_48FBB8[256] = {0};
char D_48FBE0[256] = {0};
char D_48FBF8[256] = {0};
char D_48FC08[256] = {0};
char D_48FC28[256] = {0};
char D_48FC50[256] = {0};
char D_48FC78[256] = {0};
char D_48FCB0[256] = {0};
char D_48FCC8[256] = {0};
char D_48FCF0[256] = {0};
char D_48FD30[256] = {0};
char D_48FD68[256] = {0};
char D_48FD80[256] = {0};
char D_48FD98[256] = {0};
char D_48FDB0[256] = {0};
char D_48FDC8[256] = {0};
char D_48FE28[256] = {0};
char D_4E2C30[256] = {0};
char D_4E2C38[256] = {0};
char D_4E2C40[256] = {0};
char D_4E2C48[256] = {0};
char D_4E2C50[256] = {0};
char D_4E2C58[256] = {0};
char D_4E2C68[256] = {0};
char D_4E2C70[256] = {0};
char D_4E2C78[256] = {0};
char D_4E2C80[256] = {0};
char D_4EC200[256] = {0};
char D_4ED200[256] = {0};
char D_4ED300[256] = {0};
char D_4ED334[256] = {0};
char D_4ED360[256] = {0};
char D_4ED370[256] = {0};
char D_4ED3E0[256] = {0};
char D_4ED400[256] = {0};
char D_4F1400[256] = {0};
char D_4F1508[256] = {0};
void *jtbl_48FE10[16] = {0};

/* Mock external functions */
void *func_001143C0(void *a0, ...) { (void)a0; return NULL; }
void *func_0011ACD0(void *a0, ...) { return (void *)(a0 ? strlen((const char *)a0) : 0); }
void *func_00128D10(void *a0, ...) { (void)a0; return NULL; }
void *func_00128EC8(void *a0, ...) { (void)a0; return NULL; }
void *func_00129348(void *a0, ...) { (void)a0; return NULL; }
void *func_00129388(void *a0, ...) { (void)a0; return NULL; }
void *func_001294E8(void *a0, ...) { (void)a0; return NULL; }
void *func_00129548(void *a0, ...) { (void)a0; return NULL; }
void *func_00129560(void *a0, ...) { (void)a0; return NULL; }
void *func_00129588(void *a0, ...) { (void)a0; return NULL; }
void *func_0012B8A8(void *a0, ...) { (void)a0; return NULL; }
void *func_00134DE8(void *a0, ...) { (void)a0; return NULL; }
void *func_103358(void *a0, ...) { (void)a0; return NULL; }
void *func_104A00(void *a0, ...) { (void)a0; return NULL; }
void *func_104D70(void *a0, ...) { (void)a0; return NULL; }
void *func_104D80(void *a0, ...) { (void)a0; return NULL; }
void *func_1057B0(void *a0, ...) { (void)a0; return NULL; }
void *func_10DFB8(void *a0, ...) { (void)a0; return NULL; }
void *func_10ECA0(void *a0, ...) { (void)a0; return NULL; }
void *func_10F178(void *a0, ...) { (void)a0; return NULL; }
void *func_10FD58(void *a0, ...) { (void)a0; return NULL; }
void *func_114320(void *a0, ...) { (void)a0; return NULL; }
void *func_118de0(void *a0, ...) { (void)a0; return NULL; }
void *func_11AFB8(void *a0, ...) { (void)a0; return NULL; }
void *func_12CEA0(void *a0, ...) { (void)a0; return NULL; }
void *func_12CF58(void *a0, ...) { (void)a0; return NULL; }
void *func_12CFC8(void *a0, ...) { (void)a0; return NULL; }
void *func_12D038(void *a0, ...) { (void)a0; return NULL; }
void *func_12D4D0(void *a0, ...) { (void)a0; return NULL; }
void *func_12D5F0(void *a0, ...) { (void)a0; return NULL; }
void *func_12D8D8(void *a0, ...) { (void)a0; return NULL; }
void *func_12D990(void *a0, ...) { (void)a0; return NULL; }
void *func_12DA38(void *a0, ...) { (void)a0; return NULL; }
void *func_12DA88(void *a0, ...) { (void)a0; return NULL; }
void *func_12DAC8(void *a0, ...) { (void)a0; return NULL; }
void *func_12DB08(void *a0, ...) { (void)a0; return NULL; }
void *func_12DB48(void *a0, ...) { (void)a0; return NULL; }
void *func_12DB80(void *a0, ...) { (void)a0; return NULL; }
void *func_12DBA0(void *a0, ...) { (void)a0; return NULL; }
void *func_12DBC0(void *a0, ...) { (void)a0; return NULL; }
void *func_12DBE0(void *a0, ...) { (void)a0; return NULL; }
void *func_12DC00(void *a0, ...) { (void)a0; return NULL; }
void *func_12DC20(void *a0, ...) { (void)a0; return NULL; }
void *func_12DC60(void *a0, ...) { (void)a0; return NULL; }
void *func_134140(void *a0, ...) { (void)a0; return NULL; }
void *func_1341B8(void *a0, ...) { (void)a0; return NULL; }
void *func_134210(void *a0, ...) { (void)a0; return NULL; }
void *func_134378(void *a0, ...) { (void)a0; return NULL; }
void *func_134440(void *a0, ...) { (void)a0; return NULL; }
void *func_134480(void *a0, ...) { (void)a0; return NULL; }
void *func_1344C0(void *a0, ...) { (void)a0; return NULL; }
void *func_134500(void *a0, ...) { (void)a0; return NULL; }

static void test_kt_libcdvd_server_data_access(void) {
    const unsigned char data[] = {0, 0, 0x12, 0x34};
    const char zero[] = "0";
    const char at[] = "@";
    const char other[] = "A";
    assert(func_0012CBF8(NULL) == 0);
    assert(func_0012CBF8(data) == 0x3412);
    assert(func_0012CC48(0) == 0);
    assert(func_0012CC48(data) == data + 4);
    assert(func_0012CC58(0) == 0);
    assert(func_0012CC58(zero) == 1);
    assert(func_0012CC58(at) == 0);
    assert(func_0012CC78(0) == 0);
    assert(func_0012CC78(at) == 1);
    assert(func_0012CC78(other) == 0);
}

static void test_kt_libcdvd_server_execution(void) {
    int dummy = 42;
    /* Exercise leaf / utility server entry points without hardware loops */
    func_0012CB00(&dummy, 0, 0, 0);
    func_0012CB60(&dummy, 0, 0, 0);
    func_0012CC98(&dummy, 0, 0, 0);
}

static void test_tail_helpers_semantics(void) {
    unsigned char buf[8] = { 0x40, 0x12, 0x34, 0x56, 0x78, 0x00, 0x00, 0x00 };
    int high = 0, low = 0;

    /* func_0012CB00: masks lower 3 bits */
    assert((int)(long)func_0012CB00((void *)0x1F, 0, 0, 0) == 7);
    assert((int)(long)func_0012CB00((void *)0x18, 0, 0, 0) == 0);

    /* func_0012CB08: masks bit 15 (0x8000) */
    assert((int)(long)func_0012CB08((void *)0x8000, 0, 0, 0) == 0x8000);
    assert((int)(long)func_0012CB08((void *)0x7FFF, 0, 0, 0) == 0);

    /* func_0012CB10: clears bit 15 */
    assert((int)(long)func_0012CB10((void *)0xFFFF, 0, 0, 0) == 0x7FFF);

    /* func_0012CB20: reads u16 at ptr */
    assert((int)(long)func_0012CB20(buf, 0, 0, 0) == 0x1240);
    assert((int)(long)func_0012CB20(NULL, 0, 0, 0) == 0);

    /* func_0012CB38: reads u16 and clears bit 15 */
    assert((int)(long)func_0012CB38(buf, 0, 0, 0) == (0x1240 & 0x7FFF));

    /* func_0012CB60: unpacks bits 16..39 (3 bytes) */
    assert((int)(long)func_0012CB60(buf, 0, 0, 0) == 0x785634);
    assert((int)(long)func_0012CB60(NULL, 0, 0, 0) == 0);

    /* func_0012CB90: unpacks bits 8..31 */
    assert((int)(long)func_0012CB90(buf, 0, 0, 0) == (int)((*(unsigned long *)buf >> 8)));
    assert((int)(long)func_0012CB90(NULL, 0, 0, 0) == 0);

    /* func_0012CBA8: unpacks into pointers */
    assert((int)(long)func_0012CBA8(buf, &high, &low, 0) == 1);
    assert(high == 0x785634);
    assert(low == (int)((*(unsigned long *)buf >> 8)));
    assert((int)(long)func_0012CBA8(NULL, &high, &low, 0) == 0);

    /* func_0012CC20: strlen(data + 4) + 5 */
    char name_record[32] = { 0, 0, 0, 0, 'H', 'E', 'L', 'L', 'O', '\0' };
    assert((int)(long)func_0012CC20(name_record, 0, 0, 0) == 10);
    assert((int)(long)func_0012CC20(NULL, 0, 0, 0) == 0);
}

int main(void) {
    test_kt_libcdvd_server_data_access();
    test_kt_libcdvd_server_execution();
    test_tail_helpers_semantics();
    puts("All native kt_libcdvd_server tests passed successfully.");
    return 0;
}
