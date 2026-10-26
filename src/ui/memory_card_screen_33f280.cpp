#pragma exceptions off
#include "memory_card_screen.h"
#include "memory_card_dialog.h"

extern "C" {
char *strcpy(char *dst, const char *src);
char *strcat(char *dst, const char *src);
void func_11A498(void *dst, const char *src, int count);
void func_00219D20(void *ctrl);
void func_1F6750(void *parent, void *child);
void func_2119B0(void *out, void *ctrl);
void func_2257C0(int a, int b);
void func_1F88B0(void *self, void *ctrl);

extern char D_1292360[];
extern int D_004E360C;
extern int D_004E3610;
}

extern "C" {

int func_0033F280(MemoryCardScreen *self, int has_card) {
    char buf1[512];
    char buf2[256];
    int rect1[4];
    int rect2[4];

    if (has_card) {
        self->field_840 = D_004E360C;
        self->field_848 = (int)D_1292360;
        int count = D_004E3610 - 2;
        if (count < 0) {
            count = 0;
        }
        strcpy(buf1, func_1F6EA0(self, 0xC3BD));
        if (D_004E3610 < 0) {
            strcpy(buf2, func_1F6EA0(self, 0xC3E3));
        } else {
            func_11A498(buf2, func_1F6EA0(self, 0xC3E2), count);
        }
        strcat(buf1, buf2);
        self->field_818->vfunc_62(buf1, 0);
    } else {
        self->field_840 = 0;
        self->field_848 = 0;
        strcpy(buf1, func_1F6EA0(self, 0xC3BD));
        strcat(buf1, func_1F6EA0(self, 0xC3E3));
        self->field_818->vfunc_62(buf1, 0);
    }

    func_00219D20(self->field_824);
    self->field_83C = -1;
    func_0033F540(self);

    if (self->field_840 != 0) {
        func_0033F480(self);
        self->field_824->vfunc_05(1);
        func_1F6750(self->field_820, self->field_824);
        func_2119B0(rect1, self->field_824);
        int val1 = rect1[2] - 5;
        func_2119B0(rect2, self->field_824);
        func_2257C0(val1, rect2[3] - 5);
        return 1;
    } else {
        self->field_824->vfunc_05(0);
        func_1F6750(self->field_820, self->field_838);
        func_1F88B0(self, self->field_838);
        self->field_824->vfunc_05(0);
        return 0;
    }
}

}
