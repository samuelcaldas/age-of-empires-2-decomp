#pragma once

#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001C98A0(void *self, int width, int height);

extern std::vector<void *> g_eba_calls;
extern std::vector<std::string> g_seq_log;
extern std::vector<void *> g_de30_items;
extern void *g_expected_zm;
extern void *g_c9fa0_self;
extern int g_c9fa0_calls;
extern int g_c9fa0_x0, g_c9fa0_y0, g_c9fa0_x1, g_c9fa0_y1;
extern void *g_3273e0_self;
extern int g_3273e0_count, g_3273e0_flag;
extern int g_d0430_calls;
extern int g_1387c0_calls, g_1387c0_width, g_1387c0_height;

void func_1EBA20(void *elem);
void func_1D16D0(void *self);
void func_25DE30(void *item, int a1);
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

extern char D_81D120[0x111700];
extern char D_92E820[0x9C40];
extern char D_938460[0x400];
extern char D_938790[0x400];
extern void *D_6F1AF0;
extern void *D_5E90B0;
extern void *D_6F1B50;
extern void *D_6101D0;
extern void *D_4E2DF0;
extern void *D_4E2DE8;
extern void *D_4E2DEC;
extern void *D_4E2DF4;
extern void *D_4E3244;
}

struct DispatchCell {
    char pad_0[16];
    void *f_10;
    char pad_14[8];
};
static_assert(sizeof(DispatchCell) == 28, "Cell must be 28 bytes");

struct DispatchLayout {
    char pad_0[4];
    int child_count;
    int width, height, cell_count_x, cell_count_y;
    char pad_18[0x8E74];
    DispatchCell **cells_ptr;
    int f_8E90, f_8E94;
    float width_f, height_f, width_plus_1, height_plus_1;
    char pad_8EA8[6];
    short f_8EAE, f_8EB0;
    char pad_8EB2[0x12];
    void *f_8EC4, *f_8EC8;
    char pad_8ECC[0x14];
    void *f_8EE0;
    char pad_8EE4[4];
    void *zone_child, *f_8EEC, *f_8EF0, *f_8EF4;
    char pad_8EF8[8];
    void *f_8F00;
};
static_assert(offsetof(DispatchLayout, width) == 0x8, "width offset mismatch");
static_assert(offsetof(DispatchLayout, cells_ptr) == 0x8E8C, "cells_ptr offset mismatch");
static_assert(offsetof(DispatchLayout, zone_child) == 0x8EE8, "child offset mismatch");
static_assert(sizeof(DispatchLayout) == 0x8F04, "layout size mismatch");
