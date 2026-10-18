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

int func_00342170(TacticalObj_341040 *self, int a1, int a2, int a3, int t0) {
    if (!self) return 0;

    TacticalSubObj *sub838 = self->field_838;
    if (sub838) {
        func_33A5D0(sub838, a1);
    }

    if (a1 == (int)(long)sub838 && a2 == 16) {
        func_33A730();
    }

    func_339900(self, a1);

    if (a3 > 0) {
        func_33F8B0(self);
    }

    int mode = self->field_84C;
    int f840 = self->field_840;

    if (mode == 31 && a2 != 1) {
        func_1FBD30(self, a2);
        return 0;
    }

    switch (mode) {
    case 0:
        self->field_84C = 0;
        self->field_83C = 0;
        func_00341040(self);
        break;
    case 1:
        self->field_84C = 1;
        break;
    case 11:
        self->field_84C = 11;
        break;
    case 14:
        self->field_84C = 14;
        break;
    case 16:
        if ((unsigned short)t0 == 0xFFFF) {
            self->field_84C = 12;
            self->field_83C = 12;
        } else {
            self->field_84C = 16;
        }
        break;
    case 28:
    case 29:
        self->field_84C = mode;
        break;
    case 30:
        self->field_84C = 30;
        self->field_83C = 1;
        func_339960(self, 0);
        break;
    case 31:
        self->field_84C = 31;
        self->field_83C = 1;
        func_339960(self, 1);
        break;
    case 35:
        self->field_84C = 35;
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
                typedef void (*VFunc_104)(void *self, int a);
                ((VFunc_104)(*(void***)sub828)[65])(sub828, 0xc3d5 + mode);
            }
        }
        break;
    }

    void *field844 = self->field_844;
    if (mode == 16 && (unsigned short)t0 == 0xFFFF) {
        mode = 12;
    }

    self->field_84C = mode;
    if (field844) {
        *(int*)((char*)field844 + 2052) = 4; // +0x804
    }

    if (t0 == 1) {
        func_219BA0(self, 10);
    } else if (t0 == 2) {
        func_1FBD30(self, 20);
    }

    TacticalSubObj *sub830 = self->field_830;
    if (sub830) {
        typedef void (*VFunc_28)(void *self, int a);
        ((VFunc_28)(*(void***)sub830)[7])(sub830, 1);
    }

    TacticalSubObj *sub834 = self->field_834;
    if (sub834) {
        typedef void (*VFunc_28)(void *self, int a);
        ((VFunc_28)(*(void***)sub834)[7])(sub834, 0);
    }

    self->field_84C = mode;
    return 0;
}
}
