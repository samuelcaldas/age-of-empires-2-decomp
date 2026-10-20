#pragma exceptions off
#include "zone_spatial_grid_load_palette.h"

#ifdef __MWERKS__
extern "C" {
char *strrchr(const char *str, int ch);
int sprintf(char *buffer, const char *format, ...);
char *strcpy(char *dest, const char *src);
int strcmp(const char *str1, const char *str2);
}
#else
#include <cstdio>
#include <cstring>
using std::strrchr;
using std::sprintf;
using std::strcpy;
using std::strcmp;
#endif

struct Palette {
    int id;
};

struct ManagerSub {
    char pad_00[0x45];
    unsigned char mode_45;
};

struct GlobalManager {
    char pad_00[0x6C];
    ManagerSub *field_6C;
};

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    void *field_10;
    void *field_14;
    int field_18;
    int field_1C;
    Palette *table_20[10];
    char buckets_48[10][256];
    int table_A48[10];
    int table_A70[16];
    int field_AB0;
};

extern "C" Palette *func_001F2F80(ZoneSpatialGrid *self, const char *name, int flag1, int flag2) {
    char norm_name[256];
    if (name != 0) {
        const char *ext = strrchr(name, '.');
        if (ext == 0) {
            sprintf(norm_name, "%s.pal", name);
        } else {
            strcpy(norm_name, name);
        }
        func_001AAA70(norm_name);
    } else {
        norm_name[0] = '\0';
    }

    int empty_slot = -1;
    for (int i = 0; i < 10; ++i) {
        if (self->table_20[i] != 0) {
            if ((flag1 != -1 && self->table_A70[i] == flag1) ||
                strcmp(self->buckets_48[i], norm_name) == 0) {
                self->table_A48[i]++;
                return self->table_20[i];
            }
        } else if (empty_slot == -1) {
            empty_slot = i;
        }
    }

    if (empty_slot == -1) {
        return 0;
    }

    self->table_20[empty_slot] = func_001A6270(norm_name, flag1, flag2);
    if (self->table_20[empty_slot] == 0) {
        return 0;
    }

    if (D_004D89C0->field_6C != 0 && D_004D89C0->field_6C->mode_45 == 2) {
        Palette *sec = func_001A6270(norm_name, flag1, 0);
        if (sec != 0) {
            unsigned char colors[256 * 4];
            unsigned char sub_colors[9 * 4];
            func_0021BAE0(sec, 0, 256, colors);
            for (int i = 0; i < 9; ++i) {
                sub_colors[i * 4 + 0] = colors[(i + 1) * 4 + 0];
                sub_colors[i * 4 + 1] = colors[(i + 1) * 4 + 1];
                sub_colors[i * 4 + 2] = colors[(i + 1) * 4 + 2];
                sub_colors[i * 4 + 3] = 0;
            }
            func_0021BB20(self->table_20[empty_slot], 1, 9, sub_colors);
            for (int i = 0; i < 9; ++i) {
                sub_colors[i * 4 + 0] = colors[(i + 246) * 4 + 0];
                sub_colors[i * 4 + 1] = colors[(i + 246) * 4 + 1];
                sub_colors[i * 4 + 2] = colors[(i + 246) * 4 + 2];
                sub_colors[i * 4 + 3] = 0;
            }
            func_0021BB20(self->table_20[empty_slot], 246, 9, sub_colors);
            func_0021B430(sec);
        }
    }

    self->table_A48[empty_slot]++;
    strcpy(self->buckets_48[empty_slot], norm_name);
    self->table_A70[empty_slot] = flag1;
    return self->table_20[empty_slot];
}
