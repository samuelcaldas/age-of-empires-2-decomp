#pragma exceptions off
#include "memory_card_dialog.h"
#include "memory_card_screen.h"

extern "C" {
void func_20BAF0(void *self, void *res);
void func_20BE60(void *self, int flags);
void func_100670(void *ptr);
void func_25D060(int sound_id);
void func_1F88B0(void *self, void *ctrl);
void func_1F6750(void *self, void *ctrl);
void func_1F55C0(void *self, int key);
int func_1F8140(void *self);
int func_2261C0();
void func_33A730();
void func_20BF20(void *self);
void func_1F2900(void *mgr, void *res, int a2);
void func_00340360(void *screen);
int func_339900(void *self, int a1);
int func_1FBF30(void *self, int a1, int a2, int a3, int t0);
void func_225560(void *a0);

extern void *D_4DF3F0;
extern void *D_A80BB0;
}

typedef void (*VFunc_08)(void *self, int a);
typedef void (*VFunc_1C)(void *self, int a);
typedef int (*VFunc_D8)(void *self, int a1, int a2);

extern "C" {

void *func_003407F0(MemoryCardDialog *self, int flags) {
    if (self) {
        self->vtable = (TacticalSubObj*)&D_4DF3F0;
        if (self->field_844) {
            ((char*)self->field_844)[124] = (char)self->pad_848[0];
        }
        if (self->field_828) {
            ((VFunc_08)(*(void***)self->field_828)[2])(self->field_828, 1);
            self->field_828 = 0;
        }
        if (self->field_82C) {
            ((VFunc_08)(*(void***)self->field_82C)[2])(self->field_82C, 1);
            self->field_82C = 0;
        }
        if (self->field_830) {
            ((VFunc_08)(*(void***)self->field_830)[2])(self->field_830, 1);
            self->field_830 = 0;
        }
        if (self->field_834) {
            ((VFunc_08)(*(void***)self->field_834)[2])(self->field_834, 1);
            self->field_834 = 0;
        }
        if (self->field_838) {
            ((VFunc_08)(*(void***)self->field_838)[2])(self->field_838, 1);
            self->field_838 = 0;
        }
        func_20BE60(self, 0);
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

int func_00340930(MemoryCardDialog *self, int key) {
    if (self->field_838 && *(void**)((char*)self + 60) == self->field_838) {
        if (key == 0x26 || key == 0x28) {
            func_25D060(0x40FF);
            func_1F88B0(self, self->field_830);
            func_1F6750(self, self->field_830);
            return 1;
        }
    }
    func_1F55C0(self, key);
    return 0;
}

int func_003409C0(MemoryCardDialog *self) {
    if (self->field_858) {
        func_00340C30(self);
        return 0;
    }
    return func_1F8140(self);
}

int func_00340A00(MemoryCardDialog *self, int a1, int a2, int a3, int t0) {
    if (!func_339900(self, a1)) {
        if (self->field_834 && ((VFunc_D8)(*(void***)self->field_834)[54])(self->field_834, a1, a2)) {
            func_1F6750(self, self->field_834);
        } else if (self->field_830 && ((VFunc_D8)(*(void***)self->field_830)[54])(self->field_830, a1, a2)) {
            func_1F6750(self, self->field_830);
        } else if (self->field_838 && ((VFunc_D8)(*(void***)self->field_838)[54])(self->field_838, a1, a2)) {
            func_1F6750(self, self->field_838);
        }
    }
    return func_1FBF30(self, a1, a2, a3, t0);
}

void func_00340C30(void *self_ptr) {
    MemoryCardDialog *self = (MemoryCardDialog*)self_ptr;
    if (*(int*)((char*)self + 132) == 1) {
        int now = func_2261C0();
        if ((unsigned int)(now - self->field_854) < 1000) {
            if (!self->field_858) {
                self->field_858 = 1;
            }
            return;
        }
    }
    self->field_83C = -1;
    self->field_840 = -1;
    self->field_84C = -1;
    self->field_854 = 0;
    func_33A730();
    self->field_858 = 0;
    func_20BF20(self);
    func_1F2900(&D_A80BB0, (void*)0x4D5510, 0);
    ((VFunc_1C)(*(void***)self)[7])(self, 0);
    func_00340360(self->field_844);
}

void func_003427A0(MemoryCardDialog *self, int step, int mode) {
    self->field_83C = step;
    self->field_840 = mode;
    self->field_84C = self->field_83C;
    self->field_854 = func_2261C0();
    self->field_858 = 0;
    ((VFunc_1C)(*(void***)self)[7])(self, 1);
    func_225560((char*)self + 2064);
    func_1F6750(self->field_844, self);
    func_00341040(self);
}

}
