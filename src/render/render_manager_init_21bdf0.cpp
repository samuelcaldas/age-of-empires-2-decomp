#pragma exceptions off
#include "sub_list.h"

extern "C" {
char *strcpy(char *dest, const char *src);
void *func_100850(unsigned int size);
void func_2F61F0(void *obj, void *cfg, int arg);
void func_00219F60();

extern char D_00C5E300[];
extern void *D_004E32E4;

static void InitConfigStrings(char *cfg) {
    strcpy(cfg + 0x18, "palette");
    strcpy(cfg + 0x28, "mcursors");
}

static void InitConfigFlags(char *cfg) {
    *(int *)(cfg + 0x00) = 0;
    *(int *)(cfg + 0x04) = 1;
    *(int *)(cfg + 0x08) = 3;
    *(int *)(cfg + 0x38) = 8;
    *(int *)(cfg + 0x3C) = 0;
    *(short *)(cfg + 0x40) = 9;
    *(short *)(cfg + 0x42) = 15;
    *(short *)(cfg + 0x44) = 99;
    *(int *)(cfg + 0x48) = 1;
    *(int *)(cfg + 0x4C) = 1;
    *(int *)(cfg + 0x50) = 0;
    *(int *)(cfg + 0x54) = 1;
    *(int *)(cfg + 0x58) = 1;
    *(int *)(cfg + 0x5C) = 1;
    *(int *)(cfg + 0x60) = 0;
    *(int *)(cfg + 0x64) = 1;
    *(int *)(cfg + 0x68) = 1;
    *(int *)(cfg + 0x6C) = 0;
    *(int *)(cfg + 0x70) = 0;
    *(int *)(cfg + 0x74) = 0;
    *(int *)(cfg + 0x78) = 0;
    *(int *)(cfg + 0x7C) = 1;
    *(int *)(cfg + 0x80) = 1;
}

static void InitConfigDisplay(char *cfg) {
    *(int *)(cfg + 0x88) = 3;
    *(int *)(cfg + 0x8C) = 0x54;
    *(float *)(cfg + 0x90) = 1.0f;
    *(int *)(cfg + 0x94) = 0x54;
    *(float *)(cfg + 0x98) = 1.0f;
    *(float *)(cfg + 0x9C) = 0.05f;
    *(short *)(cfg + 0xA0) = 2;
    *(int *)(cfg + 0xA4) = 640;
    *(int *)(cfg + 0xA8) = 448;
    *(int *)(cfg + 0xAC) = 640;
    *(int *)(cfg + 0xB0) = 448;
    *(int *)(cfg + 0xB4) = 640;
    *(int *)(cfg + 0xB8) = 448;
}

static void SetupMasterConfig() {
    InitConfigStrings(D_00C5E300);
    InitConfigFlags(D_00C5E300);
    InitConfigDisplay(D_00C5E300);
}

void func_0021BDF0() {
    SetupMasterConfig();

    void *obj = func_100850(0x1948);
    if (obj != 0) {
        func_2F61F0(obj, D_00C5E300, 1);
    }
    func_00219F60();
    D_004E32E4 = obj;
}
}
