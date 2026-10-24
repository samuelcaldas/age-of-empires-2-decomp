#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "thelp_overlay.h"

/* Mock external functions */
void *func_00100670(void *a, ...) { (void)a; return NULL; }
void *func_00100850(void *a, ...) { (void)a; return NULL; }
void *func_00114308(void *a, ...) { (void)a; return NULL; }
void *func_001143F8(void *a, ...) { (void)a; return NULL; }
void *func_00116F68(void *a, ...) { (void)a; return NULL; }
void *func_00117AF8(void *a, ...) { (void)a; return NULL; }
void *func_00117CAC(void *a, ...) { (void)a; return NULL; }
void *func_0011A498(void *a, ...) { (void)a; return NULL; }
void *func_0011A8E8(void *a, ...) { (void)a; return NULL; }
void *func_0011AA78(void *a, ...) { (void)a; return NULL; }
void *func_0011ABBC(void *a, ...) { (void)a; return NULL; }
void *func_0011ACD0(void *a, ...) { (void)a; return NULL; }
void *func_0011AE08(void *a, ...) { (void)a; return NULL; }
void *func_0011B170(void *a, ...) { (void)a; return NULL; }
void *func_0011B330(void *a, ...) { (void)a; return NULL; }
void *func_00123350(void *a, ...) { (void)a; return NULL; }
void *func_0017DCA0(void *a, ...) { (void)a; return NULL; }
void *func_00185D40(void *a, ...) { (void)a; return NULL; }
void *func_00185E20(void *a, ...) { (void)a; return NULL; }
void *func_00185F00(void *a, ...) { (void)a; return NULL; }
void *func_001861C0(void *a, ...) { (void)a; return NULL; }
void *func_001880D0(void *a, ...) { (void)a; return NULL; }
void *func_001880E0(void *a, ...) { (void)a; return NULL; }
void *func_001886B0(void *a, ...) { (void)a; return NULL; }
void *func_001AB8F0(void *a, ...) { (void)a; return NULL; }
void *func_001AB9D0(void *a, ...) { (void)a; return NULL; }
void *func_001ABA00(void *a, ...) { (void)a; return NULL; }
void *func_001ABA70(void *a, ...) { (void)a; return NULL; }
void *func_001AC320(void *a, ...) { (void)a; return NULL; }
void *func_001AC470(void *a, ...) { (void)a; return NULL; }
void *func_001AC650(void *a, ...) { (void)a; return NULL; }
void *func_001AD650(void *a, ...) { (void)a; return NULL; }
void *func_001AE110(void *a, ...) { (void)a; return NULL; }
void *func_001AE120(void *a, ...) { (void)a; return NULL; }
void *func_001AECD0(void *a, ...) { (void)a; return NULL; }
void *func_001AED20(void *a, ...) { (void)a; return NULL; }
void *func_001F26D0(void *a, ...) { (void)a; return NULL; }
void *func_001F2900(void *a, ...) { (void)a; return NULL; }
void *func_001F2CB0(void *a, ...) { (void)a; return NULL; }
void *func_001F45E0(void *a, ...) { (void)a; return NULL; }
void *func_001F55C0(void *a, ...) { (void)a; return NULL; }
void *func_001F5AD0(void *a, ...) { (void)a; return NULL; }
void *func_001F6460(void *a, ...) { (void)a; return NULL; }
void *func_001F6750(void *a, ...) { (void)a; return NULL; }
void *func_001F6850(void *a, ...) { (void)a; return NULL; }
void *func_001F6CD0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DB0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DC0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DD0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DE0(void *a, ...) { (void)a; return NULL; }
void *func_001F6DF0(void *a, ...) { (void)a; return NULL; }
void *func_001F6E00(void *a, ...) { (void)a; return NULL; }
void *func_001F6E50(void *a, ...) { (void)a; return NULL; }
void *func_001F6EA0(void *a, ...) { (void)a; return NULL; }
void *func_001F7B90(void *a, ...) { (void)a; return NULL; }
void *func_001F8140(void *a, ...) { (void)a; return NULL; }
void *func_001F8190(void *a, ...) { (void)a; return NULL; }
void *func_001F86F0(void *a, ...) { (void)a; return NULL; }
void *func_001F8E60(void *a, ...) { (void)a; return NULL; }
void *func_001F8E70(void *a, ...) { (void)a; return NULL; }
void *func_001FA670(void *a, ...) { (void)a; return NULL; }
void *func_001FBA10(void *a, ...) { (void)a; return NULL; }
void *func_001FBF30(void *a, ...) { (void)a; return NULL; }
void *func_00204920(void *a, ...) { (void)a; return NULL; }
void *func_0020BAF0(void *a, ...) { (void)a; return NULL; }
void *func_0020BB50(void *a, ...) { (void)a; return NULL; }
void *func_0020BE60(void *a, ...) { (void)a; return NULL; }
void *func_0020DA60(void *a, ...) { (void)a; return NULL; }
void *func_0020DA80(void *a, ...) { (void)a; return NULL; }
void *func_0020DB70(void *a, ...) { (void)a; return NULL; }
void *func_0020DC00(void *a, ...) { (void)a; return NULL; }
void *func_0020DDC0(void *a, ...) { (void)a; return NULL; }
void *func_002134F0(void *a, ...) { (void)a; return NULL; }
void *func_00215910(void *a, ...) { (void)a; return NULL; }
void *func_00215950(void *a, ...) { (void)a; return NULL; }
void *func_00215EE0(void *a, ...) { (void)a; return NULL; }
void *func_00216240(void *a, ...) { (void)a; return NULL; }
void *func_00217840(void *a, ...) { (void)a; return NULL; }
void *func_00217880(void *a, ...) { (void)a; return NULL; }
void *func_002178A0(void *a, ...) { (void)a; return NULL; }
void *func_002178E0(void *a, ...) { (void)a; return NULL; }
void *func_002181F0(void *a, ...) { (void)a; return NULL; }
void *func_002193D0(void *a, ...) { (void)a; return NULL; }
void *func_00219F00(void *a, ...) { (void)a; return NULL; }
void *func_0021FEC0(void *a, ...) { (void)a; return NULL; }
void *func_0021FED0(void *a, ...) { (void)a; return NULL; }
void *func_002254F0(void *a, ...) { (void)a; return NULL; }
void *func_00225520(void *a, ...) { (void)a; return NULL; }
void *func_00225560(void *a, ...) { (void)a; return NULL; }
void *func_002257A0(void *a, ...) { (void)a; return NULL; }
void *func_002257C0(void *a, ...) { (void)a; return NULL; }
void *func_00225820(void *a, ...) { (void)a; return NULL; }
void *func_00225BE0(void *a, ...) { (void)a; return NULL; }
void *func_002261C0(void *a, ...) { (void)a; return NULL; }
void *func_00226B40(void *a, ...) { (void)a; return NULL; }
void *func_00226BF0(void *a, ...) { (void)a; return NULL; }
void *func_00226D90(void *a, ...) { (void)a; return NULL; }
void *func_00252CA0(void *a, ...) { (void)a; return NULL; }
void *func_00252CE0(void *a, ...) { (void)a; return NULL; }
void *func_00252CF0(void *a, ...) { (void)a; return NULL; }
void *func_0025D060(void *a, ...) { (void)a; return NULL; }
void *func_0025D6D0(void *a, ...) { (void)a; return NULL; }
void *func_0025DE30(void *a, ...) { (void)a; return NULL; }
void *func_0025E640(void *a, ...) { (void)a; return NULL; }
void *func_0025F2B0(void *a, ...) { (void)a; return NULL; }
void *func_002D2AA0(void *a, ...) { (void)a; return NULL; }
void *func_002D2D90(void *a, ...) { (void)a; return NULL; }
void *func_002D2EB0(void *a, ...) { (void)a; return NULL; }
void *func_002D2F00(void *a, ...) { (void)a; return NULL; }
void *func_002D2FF0(void *a, ...) { (void)a; return NULL; }
void *func_002D3000(void *a, ...) { (void)a; return NULL; }
void *func_002D33E0(void *a, ...) { (void)a; return NULL; }
void *func_002FEDD0(void *a, ...) { (void)a; return NULL; }
void *func_0032F1F0(void *a, ...) { (void)a; return NULL; }
void *func_0036C2D0(void *a, ...) { (void)a; return NULL; }
void *func_0036C320(void *a, ...) { (void)a; return NULL; }
void *func_0036C3A0(void *a, ...) { (void)a; return NULL; }
void *func_0036DDF0(void *a, ...) { (void)a; return NULL; }
void *func_01F694A0(void *a, ...) { (void)a; return NULL; }
void *func_01F69C20(void *a, ...) { (void)a; return NULL; }
void *func_01F69FB0(void *a, ...) { (void)a; return NULL; }
void *func_01F69FC0(void *a, ...) { (void)a; return NULL; }
void *func_01F6A270(void *a, ...) { (void)a; return NULL; }
void *func_01F6A3A0(void *a, ...) { (void)a; return NULL; }
void *func_01F6A4F0(void *a, ...) { (void)a; return NULL; }
void *func_01F6B250(void *a, ...) { (void)a; return NULL; }
void *func_01F6CB30(void *a, ...) { (void)a; return NULL; }
void *func_01F6E210(void *a, ...) { (void)a; return NULL; }
void *func_01F6E3A0(void *a, ...) { (void)a; return NULL; }
void *func_01F6E5C0(void *a, ...) { (void)a; return NULL; }
void *func_01F6EAE0(void *a, ...) { (void)a; return NULL; }
void *func_01F6F250(void *a, ...) { (void)a; return NULL; }
void *func_01F6F2E0(void *a, ...) { (void)a; return NULL; }
void *func_01F6F380(void *a, ...) { (void)a; return NULL; }
void *func_01F6F390(void *a, ...) { (void)a; return NULL; }
void *func_01F6F3F0(void *a, ...) { (void)a; return NULL; }
void *func_01F6F450(void *a, ...) { (void)a; return NULL; }
void *func_01F6F5B0(void *a, ...) { (void)a; return NULL; }
void *func_01F6F770(void *a, ...) { (void)a; return NULL; }
void *func_01F6F8C0(void *a, ...) { (void)a; return NULL; }
void *func_01F6F9B0(void *a, ...) { (void)a; return NULL; }
void *func_01F6FAA0(void *a, ...) { (void)a; return NULL; }
void *func_01F6FAE0(void *a, ...) { (void)a; return NULL; }
void *func_01F6FBD0(void *a, ...) { (void)a; return NULL; }
void *func_01F6FCF0(void *a, ...) { (void)a; return NULL; }
void *func_01F6FD40(void *a, ...) { (void)a; return NULL; }
void *func_01F6FD90(void *a, ...) { (void)a; return NULL; }
void *func_01F6FDE0(void *a, ...) { (void)a; return NULL; }
void *func_01F6FE30(void *a, ...) { (void)a; return NULL; }
void *func_01F6FEA0(void *a, ...) { (void)a; return NULL; }
void *func_01F704A0(void *a, ...) { (void)a; return NULL; }
void *func_01F70AC0(void *a, ...) { (void)a; return NULL; }
void *func_01F70D50(void *a, ...) { (void)a; return NULL; }
void *func_01F71A60(void *a, ...) { (void)a; return NULL; }
void *func_01F71AC0(void *a, ...) { (void)a; return NULL; }
void *func_01F71C40(void *a, ...) { (void)a; return NULL; }
void *func_01F724A0(void *a, ...) { (void)a; return NULL; }
void *func_01F72BD0(void *a, ...) { (void)a; return NULL; }
void *func_01F72E90(void *a, ...) { (void)a; return NULL; }
void *func_01F73000(void *a, ...) { (void)a; return NULL; }
void *func_01F734C0(void *a, ...) { (void)a; return NULL; }
void *func_01F73780(void *a, ...) { (void)a; return NULL; }
void *func_01F73AB0(void *a, ...) { (void)a; return NULL; }
void *func_01F73C90(void *a, ...) { (void)a; return NULL; }
void *func_01F743E0(void *a, ...) { (void)a; return NULL; }
void *func_01F745B0(void *a, ...) { (void)a; return NULL; }
void *func_01F746F0(void *a, ...) { (void)a; return NULL; }
void *func_01F74A10(void *a, ...) { (void)a; return NULL; }
void *func_01F74C80(void *a, ...) { (void)a; return NULL; }
void *func_01F74CC0(void *a, ...) { (void)a; return NULL; }
void *func_01F74CF0(void *a, ...) { (void)a; return NULL; }
void *func_01F75210(void *a, ...) { (void)a; return NULL; }
void *func_01F75230(void *a, ...) { (void)a; return NULL; }
void *func_01F75300(void *a, ...) { (void)a; return NULL; }
void *func_01F75420(void *a, ...) { (void)a; return NULL; }
void *func_01F757B0(void *a, ...) { (void)a; return NULL; }
void *func_01F75840(void *a, ...) { (void)a; return NULL; }
void *func_01F758A0(void *a, ...) { (void)a; return NULL; }
void *func_01F758F0(void *a, ...) { (void)a; return NULL; }
void *func_01F75930(void *a, ...) { (void)a; return NULL; }
void *func_01F759E0(void *a, ...) { (void)a; return NULL; }
void *func_01F75A40(void *a, ...) { (void)a; return NULL; }
void *func_01F75F60(void *a, ...) { (void)a; return NULL; }
void *func_01F761D0(void *a, ...) { (void)a; return NULL; }
void *func_01F76BE0(void *a, ...) { (void)a; return NULL; }
void *func_01F76D80(void *a, ...) { (void)a; return NULL; }
void *func_01F771D0(void *a, ...) { (void)a; return NULL; }
void *func_01F77270(void *a, ...) { (void)a; return NULL; }
void *func_01F776B0(void *a, ...) { (void)a; return NULL; }
void *func_01F77800(void *a, ...) { (void)a; return NULL; }
void *func_01F77910(void *a, ...) { (void)a; return NULL; }
void *func_01F779F0(void *a, ...) { (void)a; return NULL; }
void *func_01F77BA0(void *a, ...) { (void)a; return NULL; }
void *func_01F77C00(void *a, ...) { (void)a; return NULL; }
void *func_01F77D80(void *a, ...) { (void)a; return NULL; }
void *func_01F77E80(void *a, ...) { (void)a; return NULL; }
void *func_01F78030(void *a, ...) { (void)a; return NULL; }
void *func_01F78090(void *a, ...) { (void)a; return NULL; }
void *func_01F78210(void *a, ...) { (void)a; return NULL; }
void *func_01F78370(void *a, ...) { (void)a; return NULL; }
void *func_01F78410(void *a, ...) { (void)a; return NULL; }
void *func_01F78430(void *a, ...) { (void)a; return NULL; }
void *func_01F78520(void *a, ...) { (void)a; return NULL; }
void *func_01F78680(void *a, ...) { (void)a; return NULL; }
void *func_01F78780(void *a, ...) { (void)a; return NULL; }
void *func_01F78BD0(void *a, ...) { (void)a; return NULL; }
void *func_01F78C20(void *a, ...) { (void)a; return NULL; }
void *func_01F78C70(void *a, ...) { (void)a; return NULL; }
void *func_01F78CC0(void *a, ...) { (void)a; return NULL; }
void *func_01F78D10(void *a, ...) { (void)a; return NULL; }
void *func_01F78D70(void *a, ...) { (void)a; return NULL; }
void *func_01F78E30(void *a, ...) { (void)a; return NULL; }
void *func_01F78E50(void *a, ...) { (void)a; return NULL; }
void *func_01F78E70(void *a, ...) { (void)a; return NULL; }
void *func_01F78ED0(void *a, ...) { (void)a; return NULL; }
void *func_01F78F00(void *a, ...) { (void)a; return NULL; }
void *func_01F78F30(void *a, ...) { (void)a; return NULL; }
void *func_01F79140(void *a, ...) { (void)a; return NULL; }
void *func_01F79330(void *a, ...) { (void)a; return NULL; }
void *func_01F794C0(void *a, ...) { (void)a; return NULL; }

extern const unsigned int thelp_data[];

static void test_thelp_data_integrity(void) {
    /* Verify known header values in thelp_data (.rodata) */
    assert(thelp_data[0] == 0x706C6568);
    assert(thelp_data[1] == 0x73705F33);
    assert(thelp_data[2] == 0x706C732E);
}

static void test_thelp_function_execution(void) {
    int dummy[100];
    memset(dummy, 0, sizeof(dummy));
    /* Exercise decompiled thelp routines */
    thelp_func_01F79440(dummy, (void *)1, NULL, NULL);
    thelp_func_01F78E44(dummy, NULL, NULL, NULL);
    thelp_func_01F78E80(dummy, NULL, NULL, NULL);
}

int main(void) {
    test_thelp_data_integrity();
    test_thelp_function_execution();
    puts("All native thelp tests passed successfully.");
    return 0;
}
