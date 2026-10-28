#pragma exceptions off
#include "kt_render_sync.h"

extern "C" {
int func_2204D0(int sema_id);
int func_104D60(int sema_id);
int func_2204E0(int sema_id);
void func_2207B0(void);
int func_104D40(int sema_id);
void func_103358(int a0);

void func_00220CD0(void) {
    while (1) {
        func_2204D0(D_00C6F390.id);
        func_104D60(D_00C6F390.id);
        if (func_2204E0(D_00C824F0.id) != 0) {
            func_2207B0();
        }
        func_104D40(D_00C6F390.id);
    }
}

void func_00220D20(void) {
    func_104D40(D_00C824F0.id);
    func_103358(0);
}
}
