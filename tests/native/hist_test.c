#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hist_overlay.h"

/* Mock tracking state */
static int s_mock_2138D0_called = 0;
static void *s_mock_2138D0_arg = NULL;
static int s_mock_1F6E00_calls = 0;
static int s_mock_117CAC_called = 0;

void func_002138D0(void *a) {
    s_mock_2138D0_called++;
    s_mock_2138D0_arg = a;
}

void func_001AB8F0(void *a, int b) {
    (void)a;
    (void)b;
}
void func_001AB9D0(void *a) {
    (void)a;
}
void func_001ACDF0(void *a) {
    (void)a;
}
void func_001AD940(void *a) {
    (void)a;
}
void func_001ADA70(void *a) {
    (void)a;
}
void func_001ADC00(void *a) {
    (void)a;
}
void func_001AD450(void *a) {
    (void)a;
}
void func_001AD270(void *a) {
    (void)a;
}
void func_0025D060(void *a) {
    (void)a;
}
void func_001F6750(void *a) {
    (void)a;
}
void func_001F6DB0(void *a) {
    (void)a;
}
void func_001F6DD0(void *a) {
    (void)a;
}
void func_001F6DE0(void *a) {
    (void)a;
}
void func_001F6DC0(void *a) {
    (void)a;
}
void func_002257C0(void *a) {
    (void)a;
}
void func_00215910(void *a) {
    (void)a;
}
void func_001F7250(void *a) {
    (void)a;
}
void func_001F8B70(void *a) {
    (void)a;
}
void func_001F8B80(void *a) {
    (void)a;
}
void func_001FC100(void *a) {
    (void)a;
}
void func_00217A10(void *a) {
    (void)a;
}
void func_00217900(void *a) {
    (void)a;
}
void func_002178C0(void *a) {
    (void)a;
}
void func_00211B70(void *a) {
    (void)a;
}
void func_00211B80(void *a) {
    (void)a;
}
void func_002104F0(void *a) {
    (void)a;
}
void func_00219D20(void *a) {
    (void)a;
}
void func_001F6EA0(void *a) {
    (void)a;
}
void func_00114378(void *a) {
    (void)a;
}
void func_00219580(void *a) {
    (void)a;
}
void func_00100850(void *a) {
    (void)a;
}
void func_00212F90(void *a) {
    (void)a;
}
void func_002130A0(void *a) {
    (void)a;
}
void func_00185E20(void *a) {
    (void)a;
}
void func_002177C0(void *a) {
    (void)a;
}
void func_0025F2B0(void *a) {
    (void)a;
}
void func_0025D6D0(void *a) {
    (void)a;
}
void func_00213FB0(void *a) {
    (void)a;
}
void func_001F86F0(void *a) {
    (void)a;
}

void func_00117CAC(void *a) {
    s_mock_117CAC_called++;
    (void)a;
}

void func_00223080(void *a) {
    (void)a;
}

void func_001F6E00(void *a) {
    s_mock_1F6E00_calls++;
    (void)a;
}

void func_0025DE30(void *a) {
    (void)a;
}
void func_002230C0(void *a) {
    (void)a;
}
void func_00215950(void *a) {
    (void)a;
}
void func_00100670(void *a) {
    (void)a;
}
void func_001886B0(void *a) {
    (void)a;
}
void func_001F8140(void *a) {
    (void)a;
}
void func_001FBF30(void *a) {
    (void)a;
}
void func_00188680(void *a) {
    (void)a;
}
void func_00219CD0(void *a) {
    (void)a;
}
void func_00219BA0(void *a) {
    (void)a;
}
void func_002134F0(void *a) {
    (void)a;
}
void func_00256800(void *a) {
    (void)a;
}
void func_001F2900(void *a) {
    (void)a;
}
void func_001F2CB0(void *a) {
    (void)a;
}
void func_001FBD30(void *a) {
    (void)a;
}
void func_00213B40(void *a) {
    (void)a;
}
void func_00216460(void *a) {
    (void)a;
}
void func_00213FD0(void *a) {
    (void)a;
}
void func_00213AE0(void *a) {
    (void)a;
}

static void test_hist_ctor_destructor(void) {
    void *dummy_obj[32];
    memset(dummy_obj, 0, sizeof(dummy_obj));

    s_mock_2138D0_called = 0;
    s_mock_2138D0_arg = NULL;
    hist_func_01D98000(dummy_obj);
    assert(s_mock_2138D0_called == 1);
    assert(s_mock_2138D0_arg == (void *)dummy_obj);
    assert(dummy_obj[0] == (void *)0x004E26C0);

    s_mock_117CAC_called = 0;
    hist_func_01D98D8C(dummy_obj);
    assert(dummy_obj[0] == (void *)0x004E26C0);
    assert(s_mock_117CAC_called == 1);

    s_mock_1F6E00_calls = 0;
    hist_func_01D98DFC(dummy_obj);
    assert(s_mock_1F6E00_calls == 8);
}

static void test_hist_data_table(void) {
    const char *text_section;

    assert(hist_data[0] == 0x00000612);
    assert(hist_data[1] == 0x00006A51);
    assert(hist_data[2] == 0x00000DFE);
    assert(hist_data[3] == 0x00007063);

    /* Index table terminator at 0x158 (index 86 and 87) */
    assert(hist_data[86] == 0xFFFFFFFF);
    assert(hist_data[87] == 0xFFFFFFFF);

    /* Text starts at byte offset 0x160 (word index 88) */
    text_section = (const char *)&hist_data[88];
    assert(strncmp(text_section, "The Britons", 11) == 0);
}

int main(void) {
    test_hist_ctor_destructor();
    test_hist_data_table();
    printf("All native hist tests passed successfully.\n");
    return 0;
}
