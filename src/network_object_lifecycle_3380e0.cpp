#include "network_object_lifecycle_3380e0.h"
extern "C" {
extern unsigned char D_010990A0;
extern unsigned char D_01087ED0[];
void func_003381A0(void *);
}
int func_003380E0(void *unused, void **result) {
    (void)unused;
    *result = D_01087ED0;
    if (D_010990A0 == 0) func_003381A0(D_01087ED0);
    D_010990A0++;
    return 0;
}
