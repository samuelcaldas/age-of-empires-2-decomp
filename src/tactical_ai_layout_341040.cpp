#pragma exceptions off
#include "tactical_ai_layout_341040.h"

extern "C" {
void func_33A730();
void func_11ABBC(void *dst, const char *src);
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0);
void func_36ACC0(int a0);
int func_1F6EA0(int a0, int a1);
void *func_36C000(int a0);
void func_11A498(void *dst, void *src, int a2);

extern const char aBesles50282age2G[];
extern const char aBesles50282age2S[];
extern const char aDmy[];
}

typedef void (*VFunc_104)(void *self, int a);
typedef void (*VFunc_100)(void *self, void *a);
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
    case 14: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3c0);
        }
        int code = 0xc3c9;
        if (self->field_840 == 2 || (unsigned int)(self->field_840 - 4) < 3) {
            code = 0xc3c1;
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, code);
        }
        break;
    }
    case 15: {
        int f840 = self->field_840;
        if (f840 == 2 || (unsigned int)(f840 - 4) < 3) {
            if (sub828) {
                ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3c2);
            }
            if (sub82C) {
                ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3c4);
            }
        } else {
            if (sub82C) {
                ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3c2);
            }
        }
        break;
    }
    case 16: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3c5);
        }
        break;
    }
    case 17: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3c1);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
            ((VFunc_36)(*(void***)sub830)[9])(sub830, 108, 172, 114, 26);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    case 18: {
        int code = 0xc3ca;
        if (self->field_840 != 2 && self->field_840 != 4) {
            if ((unsigned int)(self->field_840 - 5) < 2) {
                code = 0xc3cb;
            } else {
                code = 0xc3d8;
            }
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, code);
        }
        break;
    }
    case 19: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3cf);
        }
        char buffer[256];
        if (self->field_840 == 2) {
            int r = func_1F6EA0(0, 0xc3d0);
            void *p = func_36C000(0);
            func_11A498(buffer, p, r);
        } else {
            int r = func_1F6EA0(0, 0xc3d1);
            void *p = func_36C000(1);
            func_11A498(buffer, p, r);
        }
        if (sub82C) {
            ((VFunc_100)(*(void***)sub82C)[64])(sub82C, buffer);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
            ((VFunc_36)(*(void***)sub830)[9])(sub830, 108, 172, 114, 26);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    case 20: {
        int code = 0xc3c9;
        if (self->field_840 == 2 || (unsigned int)(self->field_840 - 4) < 3) {
            code = 0xc3c3;
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, code);
        }
        break;
    }
    case 21: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3c6);
        }
        int code = 0xc3ca;
        if (self->field_840 != 2 && self->field_840 != 4) {
            if ((unsigned int)(self->field_840 - 5) < 2) {
                code = 0xc3cb;
            } else {
                code = 0xc3d8;
            }
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, code);
        }
        break;
    }
    case 22: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3cc);
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3ca);
        }
        break;
    }
    case 23: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3cd);
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3ca);
        }
        break;
    }
    case 24: {
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3ce);
        }
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3cb);
        }
        break;
    }
    case 25: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3e6);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 0);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    case 26: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3e7);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 0);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    case 27: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3e8);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
            ((VFunc_36)(*(void***)sub830)[9])(sub830, 108, 172, 114, 26);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    case 28: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3cd);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
            ((VFunc_36)(*(void***)sub830)[9])(sub830, 108, 172, 114, 26);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    case 29: {
        if (sub82C) {
            ((VFunc_104)(*(void***)sub82C)[65])(sub82C, 0xc3ce);
        }
        if (sub830) {
            ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
            ((VFunc_36)(*(void***)sub830)[9])(sub830, 108, 172, 114, 26);
        }
        if (sub834) {
            ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
        }
        break;
    }
    default:
        break;
    }
}
}
