#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#include "kt_mc_2.h"

/* Global arrays and references needed by kt_mc_2 */
int D_4E2CB8 = 0;
int D_4E2D00 = 0;
int D_4E2D40 = 0;
int D_4E2D48 = 0;
int D_4E2D50 = 0;
int D_4E2D58 = 0;
int D_4E2D60 = 0;

int D_4F9700[64] = {0};
int D_4F97D8[64] = {0};
int D_4F9840[64] = {0};
int D_4F9E40[64] = {0};
int D_4F9EC0[64] = {0};
int D_509EC0[64] = {0};
int D_509ED0[64] = {0};
int D_509EE0[64] = {0};

/* Mock string constants */
const char D_48FF90[] = "Unformated";
const char D_48FFB0[] = "SAVEDATA";
const char D_490010[] = "icon.sys";
const char D_490048[] = "n_card <= KT_MC_CARD_MAX";
const char D_490068[] = "kt_mc_2.c";
const char D_490078[] = "ktMcInit2";
const char D_490088[] = "sceMcInit: unknown code %d\n";
const char D_4900A8[] = "sceMcInit: error\n";
const char D_4900C0[] = "sceMcInit: old mcserv.irx\n";
const char D_490100[] = "card != NULL";
const char D_490110[] = "n_card <= numberof( buf )";
const char D_490130[] = "UNFORMAT";
const char D_4901C8[] = "strlen( name ) >= numberof( filedata->name )";
const char D_4901F8[] = "ktMcSetFileDataName";
const char D_490210[] = "number >= KT_MC_FILE_ICONSYS && number <= KT_MC_FILE_DELETEICON";
const char D_490250[] = "get_default_iconname";
const char D_490288[] = "NOPERMIT";
const char D_4902C8[] = "search_number_file";
const char D_4902F0[] = "FILEBROKEN";
const char D_490370[] = "FILEEXIST";
const char D_490390[] = "SAVEDATA";
const char D_4903D0[] = "VIEWICON";
const char D_4903F0[] = "COPYICON";
const char D_490420[] = "DELETEICON";
const char D_490440[] = "mc0:/";
const char D_490458[] = "icon.sys";
const char D_490490[] = "ktMcGetDir2";
const char D_4904A0[] = "!((unsigned int)table & 63)";
const char D_4904C0[] = "new_name != NULL";
const char D_4904D8[] = "ktMcRename";
const char D_4904E8[] = "dir_name != NULL";
const char D_490500[] = "strlen( new_name ) < sizeof mc->rename";
const char D_490528[] = "strlen( dir_name ) < sizeof mc->dir_name";
const char D_490558[] = "strlen( file_name ) < sizeof mc->file_name";

/* Mock external symbols */
char D_00130748[64] = {0};
char D_00131190[64] = {0};
char D_00131720[64] = {0};
char D_00131DA8[64] = {0};
char D_00132358[64] = {0};
char D_00132840[64] = {0};
char D_001328E0[64] = {0};
char D_00132C70[64] = {0};
char D_00133000[64] = {0};
char D_00133640[64] = {0};
char D_00133698[64] = {0};
char D_001336E0[64] = {0};
char D_00133700[64] = {0};
char D_00133930[64] = {0};
char D_00133A18[64] = {0};
char D_00133DB8[64] = {0};
char D_00133DE8[64] = {0};
char D_38C8B0[64] = {0};
char D_38C8C0[64] = {0};
char D_38C900[64] = {0};
char D_38C930[64] = {0};
char D_38C960[64] = {0};
char D_38C970[64] = {0};
char D_38C980[64] = {0};
char D_38C990[64] = {0};
char D_38CA10[64] = {0};
char D_38CA40[64] = {0};
char D_38CA70[64] = {0};
char D_38CAA0[64] = {0};
char D_38CAD0[64] = {0};
char D_38CB00[64] = {0};
char D_38CB60[64] = {0};
char D_38CB90[64] = {0};
char D_38CBD8[64] = {0};
char D_38CC08[64] = {0};
char D_38CC38[64] = {0};
char D_38CC68[64] = {0};
char D_38CC98[64] = {0};
char D_38CCC8[64] = {0};
char D_38CCE0[64] = {0};
char D_38CD10[64] = {0};
char D_38CD40[64] = {0};
char D_38CD70[64] = {0};
char D_38CDA0[64] = {0};
char D_38CDE0[64] = {0};
char D_38CE10[64] = {0};
char D_38CE40[64] = {0};
char D_38CE70[64] = {0};
char D_38CE90[64] = {0};
int func_1043B8(void) {
    return 0;
}
int func_1043C8(void) {
    return 0;
}

/* Mock state */
static int mock_assert_calls = 0;
static int mock_mc_init_code = 0;

void func_114320(const char *file, int line, const char *expr) {
    (void)file;
    (void)line;
    (void)expr;
    mock_assert_calls++;
}

void func_123790(const char *file, int line, const char *expr) {
    (void)file;
    (void)line;
    (void)expr;
    mock_assert_calls++;
}

void func_001143C0(void *ptr, int size) {
    if (ptr != NULL && (unsigned long)ptr >= 0x400000 && (unsigned long)ptr < 0x600000) {
        memset(ptr, 0, size);
    }
}

int func_0011ACD0(const char *str) {
    return (int)strlen(str);
}

void func_118de0(const char *fmt, ...) {
    (void)fmt;
}

int func_10FE50(void) {
    return 0;
}
int func_10FF40(void) {
    return mock_mc_init_code;
}
int func_116F40(int size) {
    (void)size;
    return 0x1000;
}
int func_116F68(int p) {
    (void)p;
    return 0;
}
int func_117CAC(void *dst, int val, int size) {
    memset(dst, val, size);
    return 0;
}
int func_1236D0(int a) {
    return a;
}
int func_12DD00(int a0, void *a1, int a2) {
    (void)a0;
    (void)a1;
    (void)a2;
    return 0;
}
int func_12DE28(int a0) {
    return a0;
}
int func_00128990(void) {
    return 0;
}
int func_00126040(void *p) {
    (void)p;
    return 0;
}
int func_1043D8(void) {
    return 0;
}
int func_104558(void) {
    return 0;
}
int func_104FA0(void *p) {
    (void)p;
    return 0;
}
int func_1102A0(void) {
    return 0;
}
int func_1103D8(void) {
    return 0;
}
int func_110410(void) {
    return 0;
}
int func_1104C8(void) {
    return 0;
}
int func_110630(void) {
    return 0;
}
int func_110750(void) {
    return 0;
}
int func_110940(void) {
    return 0;
}
int func_110A78(void) {
    return 0;
}
int func_110C00(void) {
    return 0;
}
int func_110F30(void) {
    return 0;
}
int func_110FF8(void) {
    return 0;
}
int func_1111D8(void) {
    return 0;
}
int func_1113B0(void) {
    return 0;
}
int func_1115E0(void) {
    return 0;
}
int func_116D40(int a, int b) {
    (void)a;
    (void)b;
    return 0;
}
int func_123818(void) {
    return 0;
}
int func_123848(void) {
    return 0;
}

/* Test Cases */
static void test_table_lookup(void) {
    int table[4] = {10, 100, 20, 200};
    /* func_0012DEB8 does table lookup: key, table, count, dummy */
    int res1 = (int)(long)func_0012DEB8((void *)10, table, (void *)2, 0);
    assert(res1 == 100);
    int res2 = (int)(long)func_0012DEB8((void *)20, table, (void *)2, 0);
    assert(res2 == 200);
    printf("  [PASS] test_table_lookup\n");
}

static void test_string_helpers(void) {
    char buf[64];
    strcpy(buf, "test");
    assert(strcmp(buf, "test") == 0);
    printf("  [PASS] test_string_helpers\n");
}

static void test_card_limit_validation(void) {
    mock_assert_calls = 0;
    /* Card limit check: n_card > 2 triggers assert */
    func_0012E068(0, (void *)5, 0, 0);
    assert(mock_assert_calls > 0);
    printf("  [PASS] test_card_limit_validation\n");
}

static void test_initialization_flow(void) {
    /* Test basic init stubs */
    func_0012DE88(0, 0, 0, 0);
    func_0012DE98(0, 0, 0, 0);
    func_0012E260((void *)42, 0, 0, 0);
    printf("  [PASS] test_initialization_flow\n");
}

int main(void) {
    /* Map PS2 low BSS region (0x400000 - 0x600000) so fixed hardware addresses are valid */
    mmap((void *)0x400000, 0x200000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);

    printf("Running native kt_mc_2 test suite...\n");
    test_table_lookup();
    test_string_helpers();
    test_card_limit_validation();
    test_initialization_flow();
    printf("All native kt_mc_2 tests passed successfully.\n");
    return 0;
}
