#pragma exceptions off
#include "memory_card_screen.h"
#include "memory_card_dialog.h"

extern "C" {
char *strcpy(char *dst, const char *src);
char *strcat(char *dst, const char *src);
void *memset(void *dst, int val, unsigned int size);
void func_11A498(void *dst, const char *src, int count);
void func_00219D20(void *ctrl);
void func_1F6750(void *parent, void *child);
void func_2119B0(void *out, void *ctrl);
void func_2257C0(void *self, int a, int b);
void func_1F88B0(void *self, void *ctrl);
int func_1F8140(void *self);
void func_00188680(void *app);
void func_001886B0(void *self);
void func_003427A0(MemoryCardDialog *dialog, int step, int mode);
void func_1F2900(void *mgr, void *res, int a2);
int func_1F2700(void *mgr, void *res);
int func_002193F0(void *ctrl);
void func_00344120(void *a0);
void func_344580(void *a0, void *a1);
void func_36BD30(void *a0, int a1, int a2, void *a3, int t0, int t1);

extern char D_1292360[];
extern int D_004E360C;
extern int D_004E3610;
extern void *D_004E3180;
extern void *D_A80BB0;
extern const char D_4D5340[];
extern const char D_4D5360[];
extern const char D_4D5380[];
extern const char D_4D53D0[];
extern const char D_4D53F0[];
extern const void *jtbl_4D5390[];
}

typedef void (*VFunc_100)(void *self, const char *str, int a);
typedef void (*VFunc_1C)(void *self, int a);

extern "C" {

int func_0033EC50(MemoryCardScreen *self) {
    if (self->field_80C < 0) {
        return 1;
    }
    return 0;
}

void func_0033EC70(MemoryCardScreen *self, int a1) {
    self->field_80C = a1;
    self->field_804 = 0;
    if (a1 >= 0) {
        func_00188680(&D_004E3180);
        func_003427A0(self->field_8A0, a1, self->field_808);
        func_1F2900(&D_A80BB0, (void*)D_4D5340, 0);
    }
}

int func_0033E100(MemoryCardScreen *self) {
    if (*(int*)((char*)&D_004E3180 + 496) == 0) {
        func_001886B0(self);
    }
    int res = func_1F8140(self);
    func_0033ECE0(self);
    return res;
}

void func_0033DED0(MemoryCardScreen *self) {
    self->field_80C = -1;
    self->field_804 = 0;
    self->field_83C = -1;
    self->field_840 = 0;
    self->field_844 = 0;
    self->field_848 = 0;
    self->field_810 = 0;
    self->field_814 = 0;
    self->field_818 = 0;
    self->field_81C = 0;
    self->field_820 = 0;
    self->field_824 = 0;
    self->field_828 = 0;
    self->field_82C = 0;
    self->field_830 = 0;
    self->field_834 = 0;
    self->field_838 = 0;
    memset(&self->pad_84C[0], 0, 16);
    memset(&self->pad_84C[16], 0, 68);
}

void func_0033F660(MemoryCardScreen *self) {
    if (func_1F2700(&D_A80BB0, (void*)D_4D5360)) {
        func_00188680(&D_004E3180);
        func_1F2900(&D_A80BB0, (void*)D_4D5360, 0);
        return;
    }
    if (func_1F2700(&D_A80BB0, (void*)D_4D53D0)) {
        func_00188680(&D_004E3180);
        func_1F2900(&D_A80BB0, (void*)D_4D53D0, 0);
        return;
    }
    if (func_1F2700(&D_A80BB0, (void*)D_4D53F0)) {
        func_00188680(&D_004E3180);
        func_1F2900(&D_A80BB0, (void*)D_4D53F0, 0);
        return;
    }
    func_1F2900(&D_A80BB0, (void*)0x4D5510, 0);
}

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
            strcpy(buf2, func_1F6EA0(self, 0xC3E2));
            func_11A498(buf1, buf2, count);
        }
        strcat(buf1, buf2);
        ((VFunc_100)(*(void***)self->field_818)[64])(self->field_818, buf1, 0);
    } else {
        self->field_840 = 0;
        self->field_848 = 0;
        strcpy(buf1, func_1F6EA0(self, 0xC3BD));
        strcat(buf1, func_1F6EA0(self, 0xC3E3));
        ((VFunc_100)(*(void***)self->field_818)[64])(self->field_818, buf1, 0);
    }

    func_00219D20(self->field_824);
    self->field_83C = -1;
    func_0033F540(self);

    if (self->field_840 != 0) {
        func_0033F480(self);
        ((VFunc_1C)(*(void***)self->field_824)[7])(self->field_824, 1);
        func_1F6750(self->field_820, self->field_824);
        func_2119B0(rect1, self->field_824);
        func_2119B0(rect2, self->field_824);
        func_2257C0(self, rect2[3] - 5, rect1[2] - 5);
        return 1;
    } else {
        ((VFunc_1C)(*(void***)self->field_824)[7])(self->field_824, 0);
        func_1F6750(self->field_820, self->field_838);
        func_1F88B0(self, self->field_838);
        ((VFunc_1C)(*(void***)self->field_824)[7])(self->field_824, 0);
        return 0;
    }
}

void func_0033ECE0(MemoryCardScreen *self) {
    if (self->field_80C <= 0) {
        return;
    }
    int action = self->field_804;
    if (action <= 0) {
        return;
    }
    if ((unsigned int)action >= 13) {
        func_0033EC70(self, -1);
        return;
    }

    switch (action) {
    case 1:
        func_0033EC70(self, -1);
        break;
    case 3:
        func_0033EC70(self, -1);
        if (self->field_808 != 0) {
            func_0033F660(self);
        }
        break;
    case 4:
    case 10:
        func_0033F280(self, 1);
        func_0033EC70(self, -1);
        break;
    case 5:
        if (self->field_824) {
            func_002193F0(self->field_824);
        }
        func_0033EC70(self, -1);
        break;
    case 6:
        if (self->field_808 != 0) {
            func_0033EC70(self, 5);
        } else {
            func_0033EC70(self, 6);
        }
        break;
    case 7:
        if (self->field_808 != 0) {
            func_0033EC70(self, 25);
        } else {
            func_0033EC70(self, 26);
        }
        break;
    case 8:
        func_0033EC70(self, 10);
        break;
    case 9:
        func_0033EC70(self, 11);
        break;
    case 11: {
        void *s0 = *(void**)((char*)&D_004E3180 + 36);
        func_0033EC70(self, -1);
        func_00344120(s0);
        func_344580(s0, &self->pad_84C[0]);
        func_0033F660(self);
        break;
    }
    case 12:
        func_0033F280(self, 0);
        func_0033EC70(self, -1);
        break;
    default:
        func_0033EC70(self, -1);
        break;
    }
}

int func_0033E590(MemoryCardScreen *self, void *control, int action, int a3, int a4) {
    if (func_0033EC50(self)) {
        return 0;
    }
    if (control && action == 1) {
        if (control == self->field_82C) {
            func_0033F660(self);
            return 1;
        }
        if (control == self->field_830) {
            if (self->field_808 == 0 || self->field_808 == 1) {
                func_0033EC70(self, 3);
                return 1;
            }
            if (self->field_840 < 100) {
                func_0033EC70(self, 4);
                return 1;
            }
            func_0033EC70(self, 1);
            return 1;
        }
    }
    return 0;
}

}
