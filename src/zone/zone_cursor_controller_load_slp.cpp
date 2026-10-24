#pragma exceptions off

#include "zone_cursor_controller_load_slp.h"

extern "C" {
int func_11A498(char *buf, const char *fmt, ...);
void *func_25F2B0(int size);
int func_25D6D0(void *res, const char *path, int flags);
int func_1DB6A0(void *self);
void func_1DB760(void *self, int val);
void func_1DB790(void *self, int val);
void func_224170();
extern void *D_004E3248;
}

struct SlpRes {
    char pad[0x12];
    unsigned char frame_count;
    unsigned char flags;
};

struct CursorController {
    int f0;
    int f4;
    SlpRes *slp_res;
};

extern "C" int func_001DB500(CursorController *self, int a1, int a2, const char *name, int t0, int t1) {
    char path[256];
    func_11A498(path, "%s.slp", name);
    D_004E3248 = self;

    SlpRes *res = (SlpRes *)func_25F2B0(0x14);
    if (res != 0) {
        func_25D6D0(res, path, t0);
    }
    self->slp_res = res;
    if (self->slp_res == 0) {
        return 0;
    }
    if (((self->slp_res->flags >> 1) & 1) != 0) {
        return 0;
    }
    self->f4 = t1;
    if (self->f4 <= 0 || self->f4 >= 0x14) {
        return 0;
    }
    self->f0 = self->slp_res->frame_count;
    if (self->f4 >= self->f0) {
        return 0;
    }
    if (func_1DB6A0(self) == 0) {
        return 0;
    }
    func_1DB760(self, 0);
    func_1DB790(self, 0);
    func_224170();
    return 1;
}
