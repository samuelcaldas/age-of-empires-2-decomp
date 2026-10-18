#pragma exceptions off
#include "tactical_ai_layout_341040.h"

extern "C" {
void func_33A730();
void func_33A5D0(int a0, int a1, int a2, int a3, int t0, int t1);
int func_339900(TacticalObj_341040 *self, int a1);
void func_339960(int a0, int a1, int a2, int a3, int t0, int t1, int t2);
int func_00340CF0(void *a0);
void func_00340C30(void *a0);
void func_00341040(TacticalObj_341040 *a0);
void func_1F6750(void *a0, void *a1);
void func_1F88B0(void *a0, void *a1);
void func_33F8B0(void *a0, int a1);
int func_00219BA0(void *a0);
int func_1FBD30(void *a0, int a1);
int func_1F6EA0(void *a0, int a1);
void func_36ACC0(int a0);
extern const char D_4D5508[];

int func_00342170(TacticalObj_341040 *self, int a1, int a2, int a3, int t0) {
    if (self->field_838 != 0 && (TacticalSubObj*)a1 == self->field_838 && a2 == 16) {
        if (!func_339900(self, a1)) {
            func_33A5D0(0, 0, 0, 1, 0, 0);
            func_339960(0, self->field_C + 100, self->field_10 + 97, 168, 22, 8, 6);
            func_1F6750(self, self->field_838);
            typedef void (*VFunc76)(void *self, const void *data);
            ((VFunc76)(*(void***)self->field_838)[76])(self->field_838, D_4D5508);
            return 1;
        } else {
            func_33A730();
            if (!func_00340CF0(self)) {
                int r = func_1F6EA0(self, 0xc356);
                typedef void (*VFunc76)(void *self, int code);
                ((VFunc76)(*(void***)self->field_838)[76])(self->field_838, r);
            }
            int r2 = func_00219BA0(self->field_838);
            func_33F8B0(self->field_844, r2);
            self->field_84C = 11;
            func_00341040(self);
            return 1;
        }
    }

    if (a2 != 1) {
        return func_1FBD30(self, a1);
    }

    if ((TacticalSubObj*)a1 == self->field_834) {
        switch (self->field_84C) {
        case 11:
            self->field_84C = 3;
            func_00341040(self);
            return 1;
        case 3:
            func_33A730();
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 2;
            }
            return 1;
        case 1:
        case 2:
        case 4:
        case 7:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 2;
            }
            return 1;
        case 18:
        case 21:
        case 22:
        case 23:
        case 24:
            self->field_84C = 12;
            func_00341040(self);
            return 1;
        case 20:
            if (self->field_840 == 2 || (self->field_840 >= 4 && self->field_840 <= 6)) {
                self->field_84C = 18;
            } else {
                self->field_84C = 17;
            }
            func_00341040(self);
            return 1;
        case 15:
            if (self->field_840 == 2 || self->field_840 == 4) {
                self->field_84C = 18;
                func_00341040(self);
                return 1;
            } else {
                func_00340C30(self);
                if (self->field_844) {
                    *(int*)((char*)self->field_844 + 2052) = 12;
                }
                return 1;
            }
        case 14:
            if (self->field_840 == 2 || (self->field_840 >= 4 && self->field_840 <= 6)) {
                self->field_84C = 18;
            } else {
                self->field_84C = 17;
            }
            func_00341040(self);
            return 1;
        default:
            func_00341040(self);
            return 1;
        }
    } else if ((TacticalSubObj*)a1 == self->field_830) {
        int mode = self->field_84C;
        if ((unsigned int)mode >= 30) {
            func_00341040(self);
            return 1;
        }

        switch (mode) {
        case 0:
            func_00341040(self);
            return 1;
        case 1:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 5;
            }
            return 1;
        case 2:
        case 4:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 7;
            }
            return 1;
        case 3:
            func_33A730();
            if (self->field_838) {
                if (!func_00340CF0(self)) {
                    int code = func_1F6EA0(self, 0xc356);
                    typedef void (*VFunc76)(void *self, int c);
                    ((VFunc76)(*(void***)self->field_838)[76])(self->field_838, code);
                }
                int r = func_00219BA0(self->field_838);
                func_33F8B0(self->field_844, r);
                self->field_84C = 11;
            }
            func_00341040(self);
            return 1;
        case 5:
        case 6:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 1;
            }
            return 1;
        case 7:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 9;
            }
            return 1;
        case 8:
            if ((unsigned short)t0 == 0xFFFF) {
                func_00340C30(self);
                if (self->field_844) {
                    *(int*)((char*)self->field_844 + 2052) = 6;
                }
                return 1;
            }
            return 0;
        case 9:
            if ((unsigned short)t0 == 0xFFFF) {
                func_00340C30(self);
                if (self->field_844) {
                    *(int*)((char*)self->field_844 + 2052) = 3;
                }
                return 1;
            }
            return 0;
        case 10:
            if ((unsigned short)t0 == 0xFFFF) {
                self->field_84C = 12;
                self->field_83C = 12;
                func_00341040(self);
                return 1;
            }
            return 0;
        case 11:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 11;
            }
            return 1;
        case 12:
            self->field_84C = 13;
            func_00341040(self);
            return 1;
        case 13:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 4;
            }
            return 1;
        case 14:
            if (self->field_840 == 2 || (self->field_840 >= 4 && self->field_840 <= 6)) {
                self->field_84C = 12;
                func_00341040(self);
                return 1;
            } else {
                func_00340C30(self);
                if (self->field_844) {
                    *(int*)((char*)self->field_844 + 2052) = 12;
                }
                return 1;
            }
        case 15:
            if (self->field_840 == 2 || self->field_840 == 4) {
                func_36ACC0(7);
                self->field_84C = 16;
                func_00341040(self);
                return 1;
            } else {
                self->field_84C = 17;
                func_00341040(self);
                return 1;
            }
        case 16:
            if ((unsigned short)t0 == 0xFFFF) {
                self->field_84C = 12;
                self->field_83C = 12;
                func_00341040(self);
                return 1;
            }
            return 0;
        case 17:
            self->field_84C = 12;
            func_00341040(self);
            return 1;
        case 18:
        case 21:
        case 22:
        case 23:
        case 24:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 3;
            }
            return 1;
        case 19:
            self->field_84C = 20;
            func_00341040(self);
            return 1;
        case 20:
            if (self->field_840 == 2 || (self->field_840 >= 4 && self->field_840 <= 6)) {
                self->field_84C = 17;
                func_00341040(self);
                return 1;
            } else {
                func_00340C30(self);
                if (self->field_844) {
                    *(int*)((char*)self->field_844 + 2052) = 12;
                }
                return 1;
            }
        case 25:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 3;
            }
            return 1;
        case 26:
            func_00340C30(self);
            if (self->field_844) {
                *(int*)((char*)self->field_844 + 2052) = 6;
            }
            return 1;
        case 27:
            self->field_84C = 12;
            self->field_83C = 12;
            func_00341040(self);
            return 1;
        case 28:
        case 29:
            self->field_84C = self->field_850;
            func_00341040(self);
            return 1;
        default:
            break;
        }
    }

    return func_1FBD30(self, a1);
}
}
