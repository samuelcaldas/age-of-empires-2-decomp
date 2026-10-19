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


static inline void set_handler_state(TacticalObj_341040 *self, int code) {
    *(int*)((char*)self->field_844 + 2052) = code;
    func_00340C30(self);
}
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
        case 14: {
            int m = 18;
            if (self->field_840 == 2) {
            } else if ((unsigned)(self->field_840 - 4) < 3) {
                m = 18;
            } else {
                m = 17;
            }
            self->field_84C = m;
            break;
        }
        case 15: {
            int m = 18;
            if (self->field_840 == 2) {
            } else if (self->field_840 == 4) {
            } else {
                set_handler_state(self, 12);
                return 1;
            }
            self->field_84C = m;
            break;
        }
        case 20: {
            int m = 18;
            if (self->field_840 == 2) {
            } else if ((unsigned)(self->field_840 - 4) < 3) {
                m = 18;
            } else {
                m = 17;
            }
            self->field_84C = m;
            break;
        }
        case 18:
        case 21:
        case 22:
        case 23:
        case 24:
            self->field_84C = 12;
            break;
        case 1:
        case 2:
        case 4:
        case 7:
            set_handler_state(self, 2);
            return 1;
        case 3:
            func_33A730();
            set_handler_state(self, 2);
            return 1;
        case 11:
            self->field_84C = 3;
            break;
        default:
            break;
        }
        func_00341040(self);
        return 1;
    } else if ((TacticalSubObj*)a1 == self->field_830) {
        switch (self->field_84C) {
        case 14:
            if (self->field_840 == 2 || (unsigned)(self->field_840 - 4) < 3) {
                self->field_84C = 12;
                break;
            } else {
                set_handler_state(self, 12);
                return 1;
            }
        case 15:
            if (self->field_840 == 2 || self->field_840 == 4) {
                func_36ACC0(7);
                self->field_84C = 16;
                break;
            } else {
                self->field_84C = 17;
                break;
            }
        case 17:
            self->field_84C = 12;
            break;
        case 19:
            self->field_84C = 20;
            break;
        case 20:
            if (self->field_840 == 2 || (unsigned)(self->field_840 - 4) < 3) {
                self->field_84C = 17;
                break;
            } else {
                set_handler_state(self, 12);
                return 1;
            }
        case 18:
        case 21:
        case 22:
        case 23:
        case 24:
            set_handler_state(self, 3);
            return 1;
        case 1:
            set_handler_state(self, 5);
            return 1;
        case 8:
            if ((unsigned short)t0 == 0xFFFF) {
                set_handler_state(self, 6);
                return 1;
            }
            return 0;
        case 26:
            set_handler_state(self, 6);
            return 1;
        case 2:
        case 4:
            set_handler_state(self, 7);
            return 1;
        case 9:
            if ((unsigned short)t0 == 0xFFFF) {
                set_handler_state(self, 3);
                return 1;
            }
            return 0;
        case 25:
            set_handler_state(self, 3);
            return 1;
        case 5:
            set_handler_state(self, 1);
            return 1;
        case 6:
            set_handler_state(self, 1);
            return 1;
        case 7:
            set_handler_state(self, 9);
            return 1;
        case 10:
            if ((unsigned short)t0 == 0xFFFF) {
                self->field_84C = 12;
                self->field_83C = 12;
                break;
            }
            return 0;
        case 28:
        case 29:
            self->field_84C = self->field_850;
            break;
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
            break;
        case 11:
            set_handler_state(self, 11);
            return 1;
        case 12:
            self->field_84C = 13;
            break;
        case 13:
            set_handler_state(self, 4);
            return 1;
        case 16:
            if ((unsigned short)t0 == 0xFFFF) {
                self->field_84C = 12;
                self->field_83C = 12;
                break;
            }
            return 0;
        case 27:
            self->field_84C = 12;
            self->field_83C = 12;
            break;
        case 0:
        default:
            break;
        }
        func_00341040(self);
        return 1;
    }

    return func_1FBD30(self, a1);
}
}
