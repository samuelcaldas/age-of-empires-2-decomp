#pragma once
#pragma exceptions off

#include "zone_deserialize.h"

extern "C" {
int func_226D90(void *stream, void *dst, int size);
void func_1C98A0(void *self, int width, int height);
void func_335560(void *ai_mgr);
void func_335470(void *ai_mgr, void *stream, void *self);
void func_1CAD90(void *self, void *stream);
void func_138830(void *obj, void *stream);
void func_1CF3E0(void *self, int x0, int y0, int x1, int y1, int p5, int p6, int p7);
void func_1CF9B0(void *self, int p1, void *world, int p3, int p4, int x1, int y1, int p7);

extern void *D_4E2DF0;
extern float D_004E2F24;
extern float D_004E29E8;
extern float D_004E29EC;
}

struct ZoneCell {
    short f_0;              // 0x0 screen x
    short f_2;              // 0x2 screen y
    char pad_4;             // 0x4
    char f_5;               // 0x5 terrain
    char f_6;               // 0x6 elevation
    char f_7;               // 0x7
    char f_8;               // 0x8
    char f_9;               // 0x9
    char f_A;               // 0xA
    char f_B;               // 0xB
    char f_C;               // 0xC
    char f_D;               // 0xD
    char f_E;               // 0xE
    char f_F;               // 0xF
    void *f_10;             // 0x10
    void *f_14;             // 0x14
    char pad_18[4];         // 0x18..0x1B to reach 28 bytes
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[0x22];    // 0x8E90..0x8EB1
    short f_8EB2;           // 0x8EB2 (-0x714E)
    short f_8EB4;           // 0x8EB4 (-0x714C)
    short f_8EB6;           // 0x8EB6 (-0x714A)
    char pad_8EB8[0x15];    // 0x8EB8..0x8ECC
    char f_8ECD;            // 0x8ECD
    char f_8ECE;            // 0x8ECE
    char pad_8ECF[0x19];    // 0x8ECF..0x8EE7
    void *m_world;          // 0x8EE8 (-0x7118)
    void *f_8EEC;           // 0x8EEC (-0x7114)
    void *f_8EF0;           // 0x8EF0 (-0x7110)
};

extern "C" void func_001CD770(void *self, void *stream) {
    ZoneLayout *zm = (ZoneLayout *)self;
    int width, height;

    func_226D90(stream, &width, 4);
    func_226D90(stream, &height, 4);
    func_1C98A0(zm, width, height);

    if (zm->f_8EEC != 0) {
        func_335560(D_4E2DF0);
    }
    func_335470(D_4E2DF0, stream, zm);

    func_226D90(stream, &zm->f_8ECD, 1);
    func_226D90(stream, &zm->f_8ECE, 1);

    if (D_004E2F24 >= 7.0f) {
        for (int y = 0; y < zm->height; y++) {
            ZoneCell *row = zm->cells_ptr[y];
            for (int x = 0; x < zm->width; x++) {
                func_226D90(stream, &row[x].f_5, 1);
                func_226D90(stream, &row[x].f_6, 1);

                row[x].f_0 = (short)((x + y) * (int)zm->f_8EB4);
                row[x].f_2 = (short)((y - x) * (int)zm->f_8EB2 - (int)(unsigned char)row[x].f_6 * (int)zm->f_8EB6);

                row[x].f_7 = 0;
                row[x].f_8 = -1;
                row[x].f_9 = 0;
                row[x].f_A = 0;
                row[x].f_B = 0;
                row[x].f_C = 0;
                row[x].f_D = 0;
                row[x].f_E = -1;
                row[x].f_F = 0;
                row[x].f_10 = 0;
                row[x].f_14 = 0;
            }
        }
    }

    if (D_004E2F24 >= D_004E29E8) {
        func_1CAD90(zm, stream);
    }

    func_138830(zm->f_8EF0, stream);

    if (D_004E2F24 >= D_004E29EC) {
        func_1CF3E0(zm, 0, 0, zm->width - 1, zm->height - 1, 0, 0, 0);
        func_1CF9B0(zm, 0, zm->m_world, 0, 0, zm->width - 1, zm->height - 1, 0);
    }
}
