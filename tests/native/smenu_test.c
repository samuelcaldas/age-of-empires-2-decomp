#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "smenu_overlay.h"

/* Mock external functions */
void *func_00100670(void *a, ...) { (void)a; return NULL; }
void *func_00100850(void *a, ...) { (void)a; return NULL; }
void *func_00114308(void *a, ...) { (void)a; return NULL; }
void *func_00117CAC(void *a, ...) { (void)a; return NULL; }
void *func_0011A498(void *a, ...) { (void)a; return NULL; }
void *func_0011AA78(void *a, ...) { (void)a; return NULL; }
void *func_0011ABBC(void *a, ...) { (void)a; return NULL; }
void *func_0011ACD0(void *a, ...) { (void)a; return NULL; }
void *func_0011B170(void *a, ...) { (void)a; return NULL; }
void *func_00122118(void *a, ...) { (void)a; return NULL; }
void *func_00122690(void *a, ...) { (void)a; return NULL; }
void *func_00122748(void *a, ...) { (void)a; return NULL; }
void *func_00123350(void *a, ...) { (void)a; return NULL; }
void *func_00136230(void *a, ...) { (void)a; return NULL; }
void *func_0017DCA0(void *a, ...) { (void)a; return NULL; }
void *func_00185D40(void *a, ...) { (void)a; return NULL; }
void *func_00185E20(void *a, ...) { (void)a; return NULL; }
void *func_00185E70(void *a, ...) { (void)a; return NULL; }
void *func_00185F00(void *a, ...) { (void)a; return NULL; }
void *func_00186000(void *a, ...) { (void)a; return NULL; }
void *func_00186010(void *a, ...) { (void)a; return NULL; }
void *func_001861C0(void *a, ...) { (void)a; return NULL; }
void *func_001880D0(void *a, ...) { (void)a; return NULL; }
void *func_001880E0(void *a, ...) { (void)a; return NULL; }
void *func_001881D0(void *a, ...) { (void)a; return NULL; }
void *func_001884A0(void *a, ...) { (void)a; return NULL; }
void *func_001884D0(void *a, ...) { (void)a; return NULL; }
void *func_001884E0(void *a, ...) { (void)a; return NULL; }
void *func_00188510(void *a, ...) { (void)a; return NULL; }
void *func_00188520(void *a, ...) { (void)a; return NULL; }
void *func_00188680(void *a, ...) { (void)a; return NULL; }
void *func_001886B0(void *a, ...) { (void)a; return NULL; }
void *func_00188870(void *a, ...) { (void)a; return NULL; }
void *func_001890A0(void *a, ...) { (void)a; return NULL; }
void *func_00189230(void *a, ...) { (void)a; return NULL; }
void *func_00189250(void *a, ...) { (void)a; return NULL; }
void *func_0018E020(void *a, ...) { (void)a; return NULL; }
void *func_00190E70(void *a, ...) { (void)a; return NULL; }
void *func_00190EB0(void *a, ...) { (void)a; return NULL; }
void *func_001910F0(void *a, ...) { (void)a; return NULL; }
void *func_001AB510(void *a, ...) { (void)a; return NULL; }
void *func_001AB8F0(void *a, ...) { (void)a; return NULL; }
void *func_001AB9D0(void *a, ...) { (void)a; return NULL; }
void *func_001ABA00(void *a, ...) { (void)a; return NULL; }
void *func_001ABA70(void *a, ...) { (void)a; return NULL; }
void *func_001ACC00(void *a, ...) { (void)a; return NULL; }
void *func_001ACF10(void *a, ...) { (void)a; return NULL; }
void *func_001ADA70(void *a, ...) { (void)a; return NULL; }
void *func_001C0F90(void *a, ...) { (void)a; return NULL; }
void *func_001EC350(void *a, ...) { (void)a; return NULL; }
void *func_001F26C0(void *a, ...) { (void)a; return NULL; }
void *func_001F2700(void *a, ...) { (void)a; return NULL; }
void *func_001F2900(void *a, ...) { (void)a; return NULL; }
void *func_001F2CB0(void *a, ...) { (void)a; return NULL; }
void *func_001F36B0(void *a, ...) { (void)a; return NULL; }
void *func_001F37E0(void *a, ...) { (void)a; return NULL; }
void *func_001F38F0(void *a, ...) { (void)a; return NULL; }
void *func_001F45E0(void *a, ...) { (void)a; return NULL; }
void *func_001F4FA0(void *a, ...) { (void)a; return NULL; }
void *func_001F55C0(void *a, ...) { (void)a; return NULL; }
void *func_001F5EB0(void *a, ...) { (void)a; return NULL; }
void *func_001F60F0(void *a, ...) { (void)a; return NULL; }
void *func_001F6460(void *a, ...) { (void)a; return NULL; }
void *func_001F6660(void *a, ...) { (void)a; return NULL; }
void *func_001F6750(void *a, ...) { (void)a; return NULL; }
void *func_001F6850(void *a, ...) { (void)a; return NULL; }
void *func_001F6CD0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DB0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DC0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DD0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DE0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DF0(void *a, ...) { (void)a; return NULL; }
void *func_001F6E00(void *a, ...) { (void)a; return NULL; }
void *func_001F6EA0(void *a, ...) { (void)a; return NULL; }
void *func_001F6ED0(void *a, ...) { (void)a; return NULL; }
void *func_001F6EE0(void *a, ...) { (void)a; return NULL; }
void *func_001F7250(void *a, ...) { (void)a; return NULL; }
void *func_001F7B90(void *a, ...) { (void)a; return NULL; }
void *func_001F8140(void *a, ...) { (void)a; return NULL; }
void *func_001F8190(void *a, ...) { (void)a; return NULL; }
void *func_001F8280(void *a, ...) { (void)a; return NULL; }
void *func_001F86F0(void *a, ...) { (void)a; return NULL; }
void *func_001F88B0(void *a, ...) { (void)a; return NULL; }
void *func_001F8AF0(void *a, ...) { (void)a; return NULL; }
void *func_001F8B70(void *a, ...) { (void)a; return NULL; }
void *func_001F8B80(void *a, ...) { (void)a; return NULL; }
void *func_001F8E80(void *a, ...) { (void)a; return NULL; }
void *func_001FB860(void *a, ...) { (void)a; return NULL; }
void *func_001FBA10(void *a, ...) { (void)a; return NULL; }
void *func_001FBA90(void *a, ...) { (void)a; return NULL; }
void *func_001FBC40(void *a, ...) { (void)a; return NULL; }
void *func_001FBC60(void *a, ...) { (void)a; return NULL; }
void *func_001FBC70(void *a, ...) { (void)a; return NULL; }
void *func_001FBD30(void *a, ...) { (void)a; return NULL; }
void *func_001FBF30(void *a, ...) { (void)a; return NULL; }
void *func_001FC160(void *a, ...) { (void)a; return NULL; }
void *func_00205910(void *a, ...) { (void)a; return NULL; }
void *func_00205920(void *a, ...) { (void)a; return NULL; }
void *func_00208CD0(void *a, ...) { (void)a; return NULL; }
void *func_00208E20(void *a, ...) { (void)a; return NULL; }
void *func_00208F20(void *a, ...) { (void)a; return NULL; }
void *func_00208FA0(void *a, ...) { (void)a; return NULL; }
void *func_00208FC0(void *a, ...) { (void)a; return NULL; }
void *func_00208FD0(void *a, ...) { (void)a; return NULL; }
void *func_00209090(void *a, ...) { (void)a; return NULL; }
void *func_00209170(void *a, ...) { (void)a; return NULL; }
void *func_00209180(void *a, ...) { (void)a; return NULL; }
void *func_002091A0(void *a, ...) { (void)a; return NULL; }
void *func_00209210(void *a, ...) { (void)a; return NULL; }
void *func_002094A0(void *a, ...) { (void)a; return NULL; }
void *func_00209560(void *a, ...) { (void)a; return NULL; }
void *func_00209580(void *a, ...) { (void)a; return NULL; }
void *func_002095D0(void *a, ...) { (void)a; return NULL; }
void *func_00209630(void *a, ...) { (void)a; return NULL; }
void *func_00209740(void *a, ...) { (void)a; return NULL; }
void *func_00209760(void *a, ...) { (void)a; return NULL; }
void *func_002097D0(void *a, ...) { (void)a; return NULL; }
void *func_002097E0(void *a, ...) { (void)a; return NULL; }
void *func_002098B0(void *a, ...) { (void)a; return NULL; }
void *func_0020A4D0(void *a, ...) { (void)a; return NULL; }
void *func_0020A5D0(void *a, ...) { (void)a; return NULL; }
void *func_0020AD30(void *a, ...) { (void)a; return NULL; }
void *func_0020BA60(void *a, ...) { (void)a; return NULL; }
void *func_0020BAF0(void *a, ...) { (void)a; return NULL; }
void *func_0020BE60(void *a, ...) { (void)a; return NULL; }
void *func_0020DA80(void *a, ...) { (void)a; return NULL; }
void *func_0020DC40(void *a, ...) { (void)a; return NULL; }
void *func_0020DD40(void *a, ...) { (void)a; return NULL; }
void *func_0020DDC0(void *a, ...) { (void)a; return NULL; }
void *func_0020DE40(void *a, ...) { (void)a; return NULL; }
void *func_0020DF30(void *a, ...) { (void)a; return NULL; }
void *func_00213270(void *a, ...) { (void)a; return NULL; }
void *func_002134F0(void *a, ...) { (void)a; return NULL; }
void *func_00213E40(void *a, ...) { (void)a; return NULL; }
void *func_00215910(void *a, ...) { (void)a; return NULL; }
void *func_00215950(void *a, ...) { (void)a; return NULL; }
void *func_00215A50(void *a, ...) { (void)a; return NULL; }
void *func_00215EE0(void *a, ...) { (void)a; return NULL; }
void *func_00216020(void *a, ...) { (void)a; return NULL; }
void *func_002160C0(void *a, ...) { (void)a; return NULL; }
void *func_002164C0(void *a, ...) { (void)a; return NULL; }
void *func_00216660(void *a, ...) { (void)a; return NULL; }
void *func_002166C0(void *a, ...) { (void)a; return NULL; }
void *func_00217730(void *a, ...) { (void)a; return NULL; }
void *func_002177C0(void *a, ...) { (void)a; return NULL; }
void *func_00217840(void *a, ...) { (void)a; return NULL; }
void *func_00217880(void *a, ...) { (void)a; return NULL; }
void *func_002178A0(void *a, ...) { (void)a; return NULL; }
void *func_002178C0(void *a, ...) { (void)a; return NULL; }
void *func_002178E0(void *a, ...) { (void)a; return NULL; }
void *func_00217900(void *a, ...) { (void)a; return NULL; }
void *func_00217920(void *a, ...) { (void)a; return NULL; }
void *func_00217AD0(void *a, ...) { (void)a; return NULL; }
void *func_00217DD0(void *a, ...) { (void)a; return NULL; }
void *func_00218350(void *a, ...) { (void)a; return NULL; }
void *func_00219040(void *a, ...) { (void)a; return NULL; }
void *func_002193D0(void *a, ...) { (void)a; return NULL; }
void *func_00219990(void *a, ...) { (void)a; return NULL; }
void *func_00219D20(void *a, ...) { (void)a; return NULL; }
void *func_0021FEC0(void *a, ...) { (void)a; return NULL; }
void *func_00223FD0(void *a, ...) { (void)a; return NULL; }
void *func_00225560(void *a, ...) { (void)a; return NULL; }
void *func_002257A0(void *a, ...) { (void)a; return NULL; }
void *func_002257C0(void *a, ...) { (void)a; return NULL; }
void *func_00225DB0(void *a, ...) { (void)a; return NULL; }
void *func_002261C0(void *a, ...) { (void)a; return NULL; }
void *func_0023AD20(void *a, ...) { (void)a; return NULL; }
void *func_00247190(void *a, ...) { (void)a; return NULL; }
void *func_0024C290(void *a, ...) { (void)a; return NULL; }
void *func_0024FF80(void *a, ...) { (void)a; return NULL; }
void *func_002539D0(void *a, ...) { (void)a; return NULL; }
void *func_00253B00(void *a, ...) { (void)a; return NULL; }
void *func_00253C20(void *a, ...) { (void)a; return NULL; }
void *func_00253E60(void *a, ...) { (void)a; return NULL; }
void *func_00256800(void *a, ...) { (void)a; return NULL; }
void *func_0025A9E0(void *a, ...) { (void)a; return NULL; }
void *func_0025D060(void *a, ...) { (void)a; return NULL; }
void *func_0025D320(void *a, ...) { (void)a; return NULL; }
void *func_0025D6D0(void *a, ...) { (void)a; return NULL; }
void *func_0025DE30(void *a, ...) { (void)a; return NULL; }
void *func_0025E640(void *a, ...) { (void)a; return NULL; }
void *func_0025F2B0(void *a, ...) { (void)a; return NULL; }
void *func_002D1750(void *a, ...) { (void)a; return NULL; }
void *func_002D17F0(void *a, ...) { (void)a; return NULL; }
void *func_002D18A0(void *a, ...) { (void)a; return NULL; }
void *func_002D33E0(void *a, ...) { (void)a; return NULL; }
void *func_002DE630(void *a, ...) { (void)a; return NULL; }
void *func_00300050(void *a, ...) { (void)a; return NULL; }
void *func_003000B0(void *a, ...) { (void)a; return NULL; }
void *func_00304190(void *a, ...) { (void)a; return NULL; }
void *func_003041B0(void *a, ...) { (void)a; return NULL; }
void *func_00309320(void *a, ...) { (void)a; return NULL; }
void *func_00339900(void *a, ...) { (void)a; return NULL; }
void *func_0033D690(void *a, ...) { (void)a; return NULL; }
void *func_0033D910(void *a, ...) { (void)a; return NULL; }
void *func_0033DAF0(void *a, ...) { (void)a; return NULL; }
void *func_00344AC0(void *a, ...) { (void)a; return NULL; }
void *func_00344AD0(void *a, ...) { (void)a; return NULL; }
void *func_00344AE0(void *a, ...) { (void)a; return NULL; }
void *func_00344AF0(void *a, ...) { (void)a; return NULL; }
void *func_00344B00(void *a, ...) { (void)a; return NULL; }
void *func_00344B10(void *a, ...) { (void)a; return NULL; }
void *func_00344B20(void *a, ...) { (void)a; return NULL; }
void *func_00344B30(void *a, ...) { (void)a; return NULL; }
void *func_00344B70(void *a, ...) { (void)a; return NULL; }
void *func_00344B80(void *a, ...) { (void)a; return NULL; }
void *func_00344B90(void *a, ...) { (void)a; return NULL; }
void *func_00344BA0(void *a, ...) { (void)a; return NULL; }
void *func_00344BB0(void *a, ...) { (void)a; return NULL; }
void *func_00344BC0(void *a, ...) { (void)a; return NULL; }
void *func_00344BD0(void *a, ...) { (void)a; return NULL; }
void *func_0036DDF0(void *a, ...) { (void)a; return NULL; }
void *func_01D98080(void *a, ...) { (void)a; return NULL; }
void *func_01D988E0(void *a, ...) { (void)a; return NULL; }
void *func_01D9B120(void *a, ...) { (void)a; return NULL; }
void *func_01D9B1F0(void *a, ...) { (void)a; return NULL; }
void *func_01D9B370(void *a, ...) { (void)a; return NULL; }
void *func_01D9CC70(void *a, ...) { (void)a; return NULL; }
void *func_01D9D000(void *a, ...) { (void)a; return NULL; }
void *func_01D9D120(void *a, ...) { (void)a; return NULL; }
void *func_01D9DE40(void *a, ...) { (void)a; return NULL; }
void *func_01D9E310(void *a, ...) { (void)a; return NULL; }
void *func_01D9EEC0(void *a, ...) { (void)a; return NULL; }
void *func_01D9FC40(void *a, ...) { (void)a; return NULL; }
void *func_01DA0030(void *a, ...) { (void)a; return NULL; }
void *func_01DA00D0(void *a, ...) { (void)a; return NULL; }
void *func_01DA0230(void *a, ...) { (void)a; return NULL; }
void *func_01DA06C0(void *a, ...) { (void)a; return NULL; }
void *func_01DA0730(void *a, ...) { (void)a; return NULL; }
void *func_01DA07A0(void *a, ...) { (void)a; return NULL; }
void *func_01DA0870(void *a, ...) { (void)a; return NULL; }
void *func_01DA09F0(void *a, ...) { (void)a; return NULL; }
void *func_01DA1AE0(void *a, ...) { (void)a; return NULL; }
void *func_01DA1C10(void *a, ...) { (void)a; return NULL; }
void *func_01DA1CF0(void *a, ...) { (void)a; return NULL; }
void *func_01DA1F30(void *a, ...) { (void)a; return NULL; }
void *func_01DA2870(void *a, ...) { (void)a; return NULL; }
void *func_01DA2FF0(void *a, ...) { (void)a; return NULL; }
void *func_01DA4020(void *a, ...) { (void)a; return NULL; }
void *func_01DA4860(void *a, ...) { (void)a; return NULL; }
void *func_01DA4F40(void *a, ...) { (void)a; return NULL; }
void *func_01DA51E0(void *a, ...) { (void)a; return NULL; }
void *func_01DA5340(void *a, ...) { (void)a; return NULL; }
void *func_01DA5AD0(void *a, ...) { (void)a; return NULL; }
void *func_01DA5D40(void *a, ...) { (void)a; return NULL; }
void *func_01DA61D0(void *a, ...) { (void)a; return NULL; }
void *func_01DA6690(void *a, ...) { (void)a; return NULL; }
void *func_01DA6F50(void *a, ...) { (void)a; return NULL; }
void *func_01DA70D0(void *a, ...) { (void)a; return NULL; }
void *func_01DA71E0(void *a, ...) { (void)a; return NULL; }
void *func_01DA8480(void *a, ...) { (void)a; return NULL; }
void *func_01DA8570(void *a, ...) { (void)a; return NULL; }
void *func_01DA8730(void *a, ...) { (void)a; return NULL; }
void *func_01DA8DF0(void *a, ...) { (void)a; return NULL; }
void *func_01DA8EC0(void *a, ...) { (void)a; return NULL; }
void *func_01DA9510(void *a, ...) { (void)a; return NULL; }
void *func_01DAB8D0(void *a, ...) { (void)a; return NULL; }
void *func_01DAD410(void *a, ...) { (void)a; return NULL; }
void *func_01DAD530(void *a, ...) { (void)a; return NULL; }
void *func_01DAD650(void *a, ...) { (void)a; return NULL; }
void *func_01DAD770(void *a, ...) { (void)a; return NULL; }
void *func_01DAD990(void *a, ...) { (void)a; return NULL; }

extern const unsigned int smenu_data[];

static void test_smenu_data_integrity(void) {
    /* Verify known header values in smenu_data (.rodata) */
    assert(smenu_data[0] == 0x00001357);
    assert(smenu_data[1] == 0x00001358);
    assert(smenu_data[2] == 0x00001359);
    assert(smenu_data[3] == 0x0000135A);
}

static void test_smenu_function_execution(void) {
    int dummy = 42;
    /* Exercise decompiled menu routines */
    func_01D9E1F0(&dummy, NULL, NULL, NULL);
    func_01D9E200(&dummy, NULL, NULL, NULL);
    func_01DA0D70(&dummy, NULL, NULL, NULL);
}

int main(void) {
    test_smenu_data_integrity();
    test_smenu_function_execution();
    puts("All native smenu tests passed successfully.");
    return 0;
}
