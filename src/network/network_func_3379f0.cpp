#include "network_func_3379f0.h"

extern int D_004E3568;
extern int D_004E356C;
extern int D_004E352C;
extern int D_004E3530;
extern int D_004E3560;
extern int D_004E3538;
extern int D_004E3534;

#ifdef __cplusplus
extern "C" {
#endif
    extern const char D_004D1EE8[];
    extern const char D_004D1EF0[];
    extern const char D_004D1F00[];
    char *func_11ABBC(char *dst, const char *src);
    int func_104D60(int semaphore);
    int func_104D40(int semaphore);
    int func_388D60(int socket, const void *buf, int len, int flags);
#ifdef __cplusplus
}
#endif

int func_003379F0(void) {
    char buf1[496];
    char buf2[496];

    if (D_004E3568 != 0) {
        int i = 0;
        D_004E356C++;
        if (D_004E352C == 1) {
            if (D_004E3530 == 1) {
                func_11ABBC(buf2, D_004D1EE8);
            } else {
                func_11ABBC(buf2, D_004D1EF0);
            }
            do {
                func_104D60(D_004E3560);
                int sent = func_388D60(D_004E3538, buf2, 492, 0);
                func_104D40(D_004E3560);
                if (sent == 492 || sent == -1026) {
                    goto done;
                }
                i++;
            } while (i <= 5);
            return 1;
        }
        if (D_004E3530 == 1) {
            func_11ABBC(buf1, D_004D1EE8);
        } else {
            func_11ABBC(buf1, D_004D1F00);
        }
        func_104D60(D_004E3560);
        func_388D60(D_004E3534, buf1, 492, 0);
        func_104D40(D_004E3560);
    }
done:
    return 0;
}
