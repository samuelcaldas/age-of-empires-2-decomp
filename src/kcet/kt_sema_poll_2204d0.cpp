#pragma exceptions off
#include "kt_sema_poll.h"

extern "C" {
int func_104D70(int sema_id);

int func_002204E0(int sema_id);

int func_002204D0(int sema_id) {
    return func_002204E0(sema_id);
}

int func_002204E0(int sema_id) {
    int count = 0;
    while (func_104D70(sema_id) == sema_id) {
        count++;
    }
    return count;
}
}
