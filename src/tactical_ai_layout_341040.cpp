#pragma exceptions off
#include "tactical_ai_layout_341040.h"

extern "C" {
void func_33A730();
void func_11ABBC(void *dst, const char *src);
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0);
void func_36ACC0(int a0);

extern const char aBesles50282age2G[];
extern const char aBesles50282age2S[];
extern const char aDmy[];
}

typedef void (*VFunc_104)(void *self, int a);
typedef void (*VFunc_36)(void *self, int a, int b, int c, int d);
typedef void (*VFunc_28)(void *self, int a);

extern "C" {
void func_00341040(TacticalObj_341040 *self) {
    if (!self) return;

    TacticalSubObj *sub828 = self->field_828;
    if (sub828) {
        ((VFunc_104)(*(void***)sub828)[65])(sub828, 0);
    }

    TacticalSubObj *sub82C = self->field_82C;
    if (sub82C) {
        ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0);
        ((VFunc_36)(*(void***)sub82C)[9])(sub82C, 0, 0, 320, 220);
    }

    TacticalSubObj *sub830 = self->field_830;
    if (sub830) {
        ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
        ((VFunc_36)(*(void***)sub830)[9])(sub830, 29, 172, 114, 26);
        *(int*)((char*)sub830 + 552) = 0;
    }

    TacticalSubObj *sub834 = self->field_834;
    if (sub834) {
        ((VFunc_28)(*(void***)sub834)[7])(sub834, 1);
        *(int*)((char*)sub834 + 552) = 0;
    }

    TacticalSubObj *sub838 = self->field_838;
    if (sub838) {
        ((VFunc_28)(*(void***)sub838)[7])(sub838, 0);
    }

    func_33A730();
    if (self->vtable) {
        ((VFunc_28)(*(void***)self)[7])(self, 1);
    }

    switch (self->field_84C) {
    case 12:
    case 13: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3be);
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3bf);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 0);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        if (self->vtable) {
            ((VFunc_28)(*(void***)self)[7])(self, 0);
        }

        int s0;
        if (self->field_84C != 12) {
            s0 = 1;
        } else {
            s0 = 2;
        }

        char buffer[256];
        if (self->field_840 == 3 || self->field_840 == 4 || self->field_840 != 6) {
            func_11ABBC(buffer, aBesles50282age2G);
        } else {
            func_11ABBC(buffer, aBesles50282age2S);
        }
        func_36BD30(buffer, 0, 0, aDmy, 0);
        func_36ACC0(s0);
        break;
    }
    default:
        break;
    }
}
}
