#pragma exceptions off
#include "sub_list.h"

struct BaseObj {
    virtual void func0();
    virtual void func1();
};

struct Config {
    int value_00;
    int value_04;
    int value_08;
    char reserved_0C[0x0C];
    char palette_name[0x10];
    char cursor_name[0x10];
    int value_38;
    int value_3C;
    short value_40;
    short value_42;
    short value_44;
    short reserved_46;
    int value_48;
    int value_4C;
    int value_50;
    int value_54;
    int value_58;
    int value_5C;
    int value_60;
    int value_64;
    int value_68;
    int value_6C;
    int value_70;
    int value_74;
    int value_78;
    int value_7C;
    int value_80;
    int reserved_84;
    int value_88;
    int value_8C;
    float value_90;
    int value_94;
    float value_98;
    float value_9C;
    short value_A0;
    short reserved_A2;
    int value_A4;
    int value_A8;
    int value_AC;
    int value_B0;
    int value_B4;
    int value_B8;
};

extern "C" {
char *strcpy(char *dest, const char *src);
void *func_100850(unsigned int size);
void func_2F61F0(void *obj, void *cfg, int arg);
void func_00219F60();
extern Config D_00C5E300;
extern const char D_492C70[];
extern const char D_492C78[];
extern BaseObj *D_004E32E4;

void func_0021BDF0() {
    strcpy(D_00C5E300.palette_name, D_492C70);
    strcpy(D_00C5E300.cursor_name, D_492C78);

    D_00C5E300.value_00 = 0;
    D_00C5E300.value_04 = 1;
    D_00C5E300.value_08 = 3;
    D_00C5E300.value_38 = 8;
    D_00C5E300.value_3C = 0;
    D_00C5E300.value_40 = 9;
    D_00C5E300.value_42 = 15;
    D_00C5E300.value_44 = 99;
    D_00C5E300.value_48 = 1;
    D_00C5E300.value_4C = 1;
    D_00C5E300.value_50 = 0;
    D_00C5E300.value_54 = 1;
    D_00C5E300.value_58 = 1;
    D_00C5E300.value_5C = 1;
    D_00C5E300.value_60 = 0;
    D_00C5E300.value_64 = 1;
    D_00C5E300.value_68 = 1;
    D_00C5E300.value_7C = 1;
    D_00C5E300.value_80 = 1;
    D_00C5E300.value_88 = 3;
    D_00C5E300.value_8C = 0x54;
    D_00C5E300.value_90 = 1.0f;
    D_00C5E300.value_94 = 0x54;
    D_00C5E300.value_98 = 1.0f;
    D_00C5E300.value_9C = 0.05f;
    D_00C5E300.value_A0 = 2;
    D_00C5E300.value_6C = 0;
    D_00C5E300.value_70 = 0;
    D_00C5E300.value_74 = 0;
    D_00C5E300.value_78 = 0;
    D_00C5E300.value_A4 = 640;
    D_00C5E300.value_A8 = 448;
    D_00C5E300.value_B4 = 640;
    D_00C5E300.value_B8 = 448;
    D_00C5E300.value_AC = 640;
    D_00C5E300.value_B0 = 448;

    void *obj;
    if ((obj = func_100850(0x1948)) != 0) {
        func_2F61F0(obj, &D_00C5E300, 1);
    }
    D_004E32E4 = (BaseObj *)obj;
    func_00219F60();
}

void func_0021BFB0() {
    D_004E32E4->func1();
}
}
