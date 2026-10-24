
#pragma exceptions off
#include "unit_action_build_818d0.h"

struct Table2 { char pad[2976]; int active_id; };
struct D90160Entry { int field_0; int field_4; };
extern "C" {
extern void *D_4E341C;
extern void *D_4E3420;
extern D90160Entry D_00D90160[];
extern unsigned char D_00D8F45F[];
void func_002807D0(int, void (*)(int, void *), void *);
int func_00141470(void *);
}

void func_002818D0(int code_or_id, void *param) {
    register int s0;
    register void *s1 = param;
    register int s2;

    int v = (code_or_id < -100);
    if (v) v = (code_or_id < -205) ^ 1;
    if ((unsigned char)v) {
        func_002807D0(code_or_id, (void (*)(int, void *))func_002818D0, s1);
        return;
    }

    v = (code_or_id < 112);
    if (v) v = (code_or_id < 101) ^ 1;
    if ((unsigned char)v) {
        register int v1;
        switch (code_or_id) {
        case 101: v1 = 0; goto do_lookup;
        case 102: v1 = 1; goto do_lookup;
        case 103: v1 = 2; goto do_lookup;
        case 104: v1 = 3; goto do_lookup;
        case 105: v1 = 4; goto do_lookup;
        case 106: v1 = 5; goto do_lookup;
        case 107: v1 = 6; goto do_lookup;
        case 108: v1 = 7; goto do_lookup;
        case 109: v1 = 8; goto do_lookup;
        case 110: v1 = 9; goto do_lookup;
        case 111: v1 = 10; goto do_lookup;
        default:
            code_or_id = -1;
            break;
        }
        goto check_code;

    do_lookup:
        s0 = v1 * 8;
        s2 = D_00D90160[v1].field_4;
        if (s2 == -1 || s2 != func_00141470(D_4E341C)) {
            code_or_id = -1;
        } else {
            code_or_id = D_00D90160[v1].field_0;
        }

    check_code:
        if (code_or_id == -1) return;
    }

    register int p = (int)s1;
    if (p > 0) {
        if (p <= 256) goto do_mask;
    }
    return;

do_mask:
    register int mask = ~(1 << (code_or_id - 1));
    register int active_id = ((Table2 *)D_4E3420)->active_id;
    D_00D8F45F[(active_id << 8) + p] &= mask;
}

void func_2818D0(int code_or_id, void *param) {
    func_002818D0(code_or_id, param);
}
