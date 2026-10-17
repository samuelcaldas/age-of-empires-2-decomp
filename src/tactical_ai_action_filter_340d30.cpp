#pragma exceptions off
#include "tactical_ai_action_filter_340d30.h"

extern "C" {
int func_340D70(void *a0, void *a3, void *t0);
int func_1F45E0(void *a0, void *a1, int a2, void *a3);

int func_00340D30(void *a0, void *a1, int a2, void *a3, void *t0) {
    if (a2 == 0x520) {
        return func_340D70(a0, a3, t0);
    }
    return func_1F45E0(a0, a1, a2, a3);
}

}
