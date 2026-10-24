#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "multim_overlay.h"

/* Mock external functions */
void *func_00100670(void *a, ...) { (void)a; return NULL; }
void *func_00100850(void *a, ...) { (void)a; return NULL; }
void *func_00114378(void *a, ...) { (void)a; return NULL; }
void *func_00116F40(void *a, ...) { (void)a; return NULL; }
void *func_00116F68(void *a, ...) { (void)a; return NULL; }
void *func_00117AF8(void *a, ...) { (void)a; return NULL; }
void *func_00117CAC(void *a, ...) { (void)a; return NULL; }
void *func_00118DE0(void *a, ...) { (void)a; return NULL; }
void *func_0011A498(void *a, ...) { (void)a; return NULL; }
void *func_0011A708(void *a, ...) { (void)a; return NULL; }
void *func_0011AA78(void *a, ...) { (void)a; return NULL; }
void *func_0011ABBC(void *a, ...) { (void)a; return NULL; }
void *func_0011ACD0(void *a, ...) { (void)a; return NULL; }
void *func_0011AFB8(void *a, ...) { (void)a; return NULL; }
void *func_0017DD90(void *a, ...) { (void)a; return NULL; }
void *func_00185E20(void *a, ...) { (void)a; return NULL; }
void *func_001860D0(void *a, ...) { (void)a; return NULL; }
void *func_00186110(void *a, ...) { (void)a; return NULL; }
void *func_001886B0(void *a, ...) { (void)a; return NULL; }
void *func_001AB8F0(void *a, ...) { (void)a; return NULL; }
void *func_001AB9D0(void *a, ...) { (void)a; return NULL; }
void *func_001ABA00(void *a, ...) { (void)a; return NULL; }
void *func_001ABA70(void *a, ...) { (void)a; return NULL; }
void *func_001F2900(void *a, ...) { (void)a; return NULL; }
void *func_001F6EA0(void *a, ...) { (void)a; return NULL; }
void *func_001F8140(void *a, ...) { (void)a; return NULL; }
void *func_00215910(void *a, ...) { (void)a; return NULL; }
void *func_00215950(void *a, ...) { (void)a; return NULL; }
void *func_002159B0(void *a, ...) { (void)a; return NULL; }
void *func_00215A50(void *a, ...) { (void)a; return NULL; }
void *func_00215A80(void *a, ...) { (void)a; return NULL; }
void *func_002254F0(void *a, ...) { (void)a; return NULL; }
void *func_002257A0(void *a, ...) { (void)a; return NULL; }
void *func_00225820(void *a, ...) { (void)a; return NULL; }
void *func_00225BE0(void *a, ...) { (void)a; return NULL; }
void *func_002261C0(void *a, ...) { (void)a; return NULL; }
void *func_0025D060(void *a, ...) { (void)a; return NULL; }
void *func_0025DAA0(void *a, ...) { (void)a; return NULL; }
void *func_0025DE30(void *a, ...) { (void)a; return NULL; }
void *func_0025F140(void *a, ...) { (void)a; return NULL; }
void *func_0025F2B0(void *a, ...) { (void)a; return NULL; }
void *func_01D98590(void *a, ...) { (void)a; return NULL; }
void *func_01D988A0(void *a, ...) { (void)a; return NULL; }
void *func_01D988D0(void *a, ...) { (void)a; return NULL; }
void *func_01D98DE0(void *a, ...) { (void)a; return NULL; }
void *func_01D98E20(void *a, ...) { (void)a; return NULL; }
void *func_01D991F0(void *a, ...) { (void)a; return NULL; }
void *func_01D99630(void *a, ...) { (void)a; return NULL; }
void *func_01D99730(void *a, ...) { (void)a; return NULL; }
void *func_01D99810(void *a, ...) { (void)a; return NULL; }
void *func_01D99D30(void *a, ...) { (void)a; return NULL; }

extern const unsigned int multim_data[];

static void test_multim_data_integrity(void) {
    /* Verify known header values in multim_data (.rodata) */
    assert(multim_data[0] == 0x000005F9);
    assert(multim_data[1] == 0x000033C5);
    assert(multim_data[2] == 0x00000351);
    assert(multim_data[3] == 0x000039BE);
}

static void test_multim_function_execution(void) {
    int dummy[100];
    memset(dummy, 0, sizeof(dummy));
    /* Exercise key entry functions */
    multim_func_01D985A8(dummy, NULL, NULL, NULL);
    multim_func_01D987C0(dummy, NULL, NULL, NULL);
    multim_func_01D9880C(dummy, NULL, NULL, NULL);
    multim_func_01D98D5C(dummy, NULL, NULL, NULL);
    multim_func_01D99E2C(dummy, NULL, NULL, NULL);
    multim_func_01D99E78(dummy, NULL, NULL, NULL);
}

int main(void) {
    test_multim_data_integrity();
    test_multim_function_execution();
    puts("All native multim tests passed successfully.");
    return 0;
}
