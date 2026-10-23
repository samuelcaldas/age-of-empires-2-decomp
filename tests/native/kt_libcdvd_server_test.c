#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "kt_libcdvd_server.h"

/* Mock external definitions for native testing */
int D_4F1508[32];
int D_4F1510 = 0x12345678;

static int s_mock_1143c0_called = 0;
static void *s_mock_1143c0_arg = NULL;
static int s_mock_1143c0_len = 0;

int func_0011ACD0(const char *s) {
    if (!s) return 0;
    return (int)strlen(s);
}

void func_001143C0(void *a, int b) {
    s_mock_1143c0_called++;
    s_mock_1143c0_arg = a;
    s_mock_1143c0_len = b;
}

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

static void test_kt_libcdvd_server_external_calls(void) {
    const char test_path[] = "1234hello";
    assert(func_0012CC20(NULL) == 0);
    assert(func_0012CC20(test_path) == 5 + 5); /* strlen("hello") + 5 = 10 */

    s_mock_1143c0_called = 0;
    s_mock_1143c0_arg = NULL;
    s_mock_1143c0_len = 0;
    func_0012CCD8();
    assert(s_mock_1143c0_called == 1);
    assert(s_mock_1143c0_arg == D_4F1508);
    assert(s_mock_1143c0_len == 0x14);
}

static void test_kt_libcdvd_server_stubs(void) {
    int dummy = 42;
    /* Exercise several server entry points */
    func_001295D0(&dummy);
    func_00129620(&dummy, 1, 2);
    func_00129670(&dummy);
    func_0012CB00(&dummy);
    func_0012CB60(&dummy);
}

int main(void) {
    test_kt_libcdvd_server_data_access();
    test_kt_libcdvd_server_external_calls();
    test_kt_libcdvd_server_stubs();
    puts("All native kt_libcdvd_server tests passed successfully.");
    return 0;
}
