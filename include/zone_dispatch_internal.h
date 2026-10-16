#pragma once

#include "zone_dispatch.h"

struct ZoneCell {
    char f_0[6];
    char f_6;
    char f_7;
    char f_8;
    char f_9;
    char f_A;
    char pad_B[3];
    char f_E;               // 0xE
    char pad_F;
    void *f_10;             // 0x10
    char pad_14[8];         // to reach 0x1C (28 bytes total)
};

struct ZoneRow {
    ZoneCell cells[200];  // up to 200 wide
};

struct ZoneCellsLayout {
    char pad_0[4];
    int child_count;        // 0x4 (stores &D_81D120)
    int width;              // 0x8
    int height;             // 0xC
    int cell_count_x;       // 0x10
    int cell_count_y;       // 0x14
    char pad_18[0x8E74];    // 0x18..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C — ZoneCell** avoids implicit cast
    int f_8E90;             // 0x8E90
    int f_8E94;             // 0x8E94
    float width_f;          // 0x8E98
    float height_f;         // 0x8E9C
    float width_plus_1;     // 0x8EA0
    float height_plus_1;    // 0x8EA4
    char pad_8EA8[6];       // 0x8EA8..0x8EAD
    short f_8EAE;           // 0x8EAE
    short f_8EB0;           // 0x8EB0
    char pad_8EB2[0x12];    // 0x8EB2..0x8EC3
    void *f_8EC4;           // 0x8EC4 (-0x713C)
    void *f_8EC8;           // 0x8EC8 (-0x7138)
    char pad_8ECC[0x14];    // 0x8ECC..0x8EDF
    void *f_8EE0;           // 0x8EE0 — event sub-object slot (func_1ED830/D_6F1B50)
    char pad_8EE4[4];       // 0x8EE4..0x8EE7
    void *zone_child;       // 0x8EE8 — entity child (a1 for func_3273E0/1ED3C0)
    void *f_8EEC;           // 0x8EEC — zone-manager sub-object slot (D_6F1AF0)
    void *f_8EF0;           // 0x8EF0 — entity-manager sub-object slot (D_5E90B0)
    void *f_8EF4;           // 0x8EF4 — AI-manager sub-object slot (D_6101D0)
    char pad_8EF8[8];       // 0x8EF8..0x8EFF
    void *f_8F00;           // 0x8F00 (gp-based)
};

extern "C" {
void func_1EBA20(void *self);
void func_1D16D0(void *self);
void func_25DE30(void *self, int a1);
void func_1D06A0(void *self);
void func_001C9FA0(void *self, int a1, int a2, int a3, int a4);
void func_335560(void *self);
void func_335550(void *self, void *a1);
void func_001387C0(void *self, int a1, int a2);
void func_001389F0(void *self);
void func_327590(void *self);
void func_3273E0(void *self, int a1, int a2);
void func_1ED830(void *self);
void func_1ED150(void *self);
void func_1ED3C0(void *self, void *a1);
void func_1D0430(void *self);
void *memset(void *ptr, int val, unsigned int n);
extern int D_81D120;
extern int D_92E820;
extern int D_938460;
extern int D_938790;
extern void *D_6F1AF0;
extern void *D_5E90B0;
extern void *D_6F1B50;
extern void *D_6101D0;
// gp-relative manager singleton pointers (loaded via lw reg,offset(gp))
extern void *D_4E2DF0;  // gp-0x79D0: zone manager (used for func_335560/335550)
extern void *D_4E2DE8;  // gp-0x79D8: entity manager (used for func_001389F0/001387C0)
extern void *D_4E2DEC;  // gp-0x79D4: ai manager (used for func_327590/3273E0)
extern void *D_4E2DF4;  // gp-0x79CC: event manager (used for func_1ED150/1ED3C0)
extern void *D_4E3244;  // gp-0x757C: stores &D_6F1B50 after event init
}
