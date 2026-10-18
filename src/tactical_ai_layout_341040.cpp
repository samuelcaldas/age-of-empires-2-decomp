#pragma exceptions off
#include "tactical_ai_layout_341040.h"

extern "C" {
void func_33A730();
void func_33A5D0(void *a0, int a1);
void func_339900(void *a0, int a1);
void func_339960(void *a0, int a1);
void func_340CF0(void *a0);
void func_340C30(void *a0);
void func_00341040(TacticalObj_341040 *a0);
void func_1F6750(void *a0, void *a1);
void func_1F88B0(void *a0, void *a1);
void func_33F8B0(void *a0);
void func_219BA0(void *a0, int a1);
void func_1FBD30(void *a0, int a1);
void func_11ABBC(void *dst, const char *src);
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0);
void func_36ACC0(int a0);
int func_1F6EA0(int a0, int a1);
void *func_36C000(int a0);
void func_11A498(void *dst, void *src, void *a2);
char *func_33F820(void *a0);
int func_11ACD0(const char *s);
char *func_33F8A0(void *a0);

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
    case 1: {
        int code = 9471;
        if (self->field_840 == 1 || self->field_840 == 0) {
            code = 9276;
        }
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, code);
        }
        char *path = func_33F820(self->field_844);
        char buf1088[256];
        func_11ABBC(buf1088, path);
        int len = func_11ACD0(buf1088);
        for (int i = len - 1; i >= 0; i--) {
            if (buf1088[i] == '/') {
                buf1088[i] = '\n';
                break;
            }
        }
        int r = func_1F6EA0(0, 0xc3b6);
        char buffer[256];
        func_11A498(buffer, (void*)(unsigned int)r, buf1088);
        if (sub82C) {
            ((VFunc_100)(*(void***)sub82C)[64])(sub82C, buffer);
        }
        break;
    }
    case 2: {
        int code = 9411;
        if (self->field_840 == 2) {
            code = 9281;
        }
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, code);
        }
        char *path = func_33F8A0(self->field_844);
        char buf1088[256];
        func_11ABBC(buf1088, path);
        int len = func_11ACD0(buf1088);
        for (int i = len - 1; i >= 0; i--) {
            if (buf1088[i] == '/') {
                buf1088[i] = '\n';
                break;
            }
        }
        int r = func_1F6EA0(0, 0xc3b7);
        char buffer[256];
        func_11A498(buffer, (void*)(unsigned int)r, buf1088);
        if (sub82C) {
            ((VFunc_100)(*(void***)sub82C)[64])(sub82C, buffer);
        }
        break;
    }
    case 3: {
        int code = 9411;
        if (self->field_840 == 2) {
            code = 9281;
        }
        if (sub828) {
            ((VFunc_104)(*(void***)sub828)[65])(sub828, code);
        }
        char *path = func_33F8A0(self->field_844);
        int r = func_1F6EA0(0, 0xc3c7);
        char buffer[256];
        func_11A498(buffer, (void*)(unsigned int)r, path);
        if (sub82C) {
            ((VFunc_100)(*(void***)sub82C)[64])(sub82C, buffer);
        }
        break;
    }
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
        int s0 = (self->field_84C != 12) ? 1 : 2;
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

// 0x342170 to 0x342798 state machine port with exact signature (self, a1, a2, a3, t0)
void func_00342170(TacticalObj_341040 *self, int a1, int a2, int a3, int t0) {
    if (!self) return;

    // 0x34217C: check field_838 and call func_33A5D0
    TacticalSubObj *sub838 = self->field_838;
    if (sub838) {
        func_33A5D0(sub838, a1);
    }

    // 0x342188 - 0x342194: compare a1 with field_838 and a2 with 16
    if (a1 == (int)(long)sub838 && a2 == 16) {
        func_33A730();
    }

    // 0x3421AC: use a3
    if (a3 > 0) {
        func_33F8B0(self);
    }

    int mode = self->field_84C;
    int f840 = self->field_840;

    // Jump-table / switch dispatch matching 0x342170 - 0x342798
    switch (mode) {
    case 30:
        self->field_83C = 1;
        func_339960(self, 0);
        break;
    case 31:
        self->field_83C = 1;
        func_339960(self, 1);
        break;
    case 35:
        self->field_83C = 2;
        func_339960(self, 1);
        break;
    default:
        if (mode >= 40 && mode <= 50) {
            func_339900(self, mode);
        } else if (f840 == 2) {
            func_340CF0(self);
        } else if (f840 == 3) {
            func_340C30(self);
        } else {
            TacticalSubObj *sub828 = self->field_828;
            if (sub828) {
                ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3d5 + mode);
            }
        }
        break;
    }

    // 0x3423AC: write state and subobject +0x804
    self->field_84C = mode;
    if (sub838) {
        *(int*)((char*)sub838 + 2052) = mode; // +0x804
    }

    // t0 usage at 0x3425B4, 0x3425FC, 0x342678
    if (t0 == 1) {
        func_219BA0(self, 10);
    } else if (t0 == 2) {
        func_1FBD30(self, 20);
    }

    // Subobject interactions
    TacticalSubObj *sub830 = self->field_830;
    if (sub830) {
        ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
    }

    TacticalSubObj *sub834 = self->field_834;
    if (sub834) {
        ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
    }

    // Strict call order at 0x342738: func_1F6750 then func_1F88B0
    func_1F6750(self, sub838);
    func_1F88B0(self, sub838);
}
}
