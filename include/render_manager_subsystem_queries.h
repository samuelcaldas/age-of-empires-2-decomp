#ifndef RENDER_MANAGER_SUBSYSTEM_QUERIES_H
#define RENDER_MANAGER_SUBSYSTEM_QUERIES_H

struct SubObj404E {
    char pad_00[0x50];
    short field_50;
    char pad_52[2];
    void **field_54;
    char pad_58[0x40];
    short field_98;
};

struct RenderManagerSubsystemQueries {
    char pad_00[0x2C];
    int field_2C;
    char pad_30[0x4C];
    int field_7C;
    char pad_80[0x158];
    void *field_1D8;
    char pad_1DC[8];
    int field_1E4;
    int field_1E8;
    int field_1EC;
    char pad_1F0[0x214];
    SubObj404E *field_404;
    char pad_408[0x5C4];
    int field_9CC[9];
};

extern int D_004E8980;

extern "C" {
int func_225560(int a1);
int func_225E80(int f2c);
void func_1DB7D0(void *arg);
void func_1DB7C0(void *arg);
int func_1DB760(void *arg);
void func_224300(int arg);

int func_00186000(void *unused, int a1);
void *func_00186010(RenderManagerSubsystemQueries *self);
int func_00186080(RenderManagerSubsystemQueries *self, int a1);
int func_001860c0(RenderManagerSubsystemQueries *self);
void func_001860d0(RenderManagerSubsystemQueries *self);
void func_00186110(RenderManagerSubsystemQueries *self);
void func_00186150(RenderManagerSubsystemQueries *self, int a1);
void func_001861a0(RenderManagerSubsystemQueries *self, int a1);
int func_001861c0(RenderManagerSubsystemQueries *self);
}

#endif
