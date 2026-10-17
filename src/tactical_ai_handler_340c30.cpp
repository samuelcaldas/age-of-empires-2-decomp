#pragma exceptions off
#include "tactical_ai_handler_340c30.h"

extern "C" {
int func_2261c0();
void func_33A730();
void func_20BF20(void *ptr);
void func_1F2900(void *a0, const char *a1, int a2);
void func_340360(void *ptr);

extern char D_00A80BB0[];
extern const char aMemorycardScreen[];

void func_00340C30(TacticalObj_340C30 *self) {
    if (self->field_84 == 1) {
        int elapsed = (unsigned int)func_2261c0() - self->field_854;
        if ((unsigned int)elapsed < 1000) {
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
    self->field_858 = 0;
    func_33A730();
    func_20BF20(self);
    func_1F2900(D_00A80BB0, aMemorycardScreen, 0);
    self->vfunc_1c(0);
    func_340360(self->field_844);
}
}
