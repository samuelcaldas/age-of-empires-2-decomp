#pragma once
#pragma exceptions off

#include "zone_serialize.h"

extern "C" {
int func_226F70(void *stream, void *src, int size);
void func_3355C0(void *ai_mgr, void *stream);
void func_1CAC90(void *self, void *stream);
void func_1388E0(void *obj, void *stream);

extern float D_004E2F24;
}

struct ZoneCell {
    char pad_0[5];          // 0x0..0x4
    char f_5;               // 0x5 terrain
    char f_6;               // 0x6 elevation
    char pad_7[21];         // 28 bytes total
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[0x3D];    // 0x8E90..0x8ECC
    char f_8ECD;            // 0x8ECD
    char f_8ECE;            // 0x8ECE
    char pad_8ECF[0x1D];    // 0x8ECF..0x8EEB
    void *f_8EEC;           // 0x8EEC (-0x7114)
    void *m_world;          // 0x8EE8 (-0x7118)
    char pad_8EF0[4];
    void *f_8EF0;           // 0x8EF0 (-0x7110)
};

extern "C" void func_001CDA40(void *self, void *stream) {
    ZoneLayout *zm = (ZoneLayout *)self;

    func_226F70(stream, &zm->width, 4);
    func_226F70(stream, &zm->height, 4);

    func_3355C0(zm->f_8EEC, stream);

    func_226F70(stream, &zm->f_8ECD, 1);
    func_226F70(stream, &zm->f_8ECE, 1);

    if (D_004E2F24 >= 7.0f) {
        for (int y = 0; y < zm->height; y++) {
            ZoneCell *row = zm->cells_ptr[y];
            for (int x = 0; x < zm->width; x++) {
                char t = row[x].f_5;
                func_226F70(stream, &t, 1);
                char e = row[x].f_6;
                func_226F70(stream, &e, 1);
            }
        }
    }

    func_1CAC90(zm, stream);
    func_1388E0(zm->f_8EF0, stream);
}
