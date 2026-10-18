#ifndef RENDER_MANAGER_DISPLAY_RESET_H
#define RENDER_MANAGER_DISPLAY_RESET_H

struct RenderManagerDisplayReset {
    char pad_00[0xFC5];
    char field_FC5[0x103];
    int field_10C8;
    char pad_10CC[0x460];
    int field_152C;
    char pad_1530[0xBC];
    void *field_15EC;
    void *field_15F0;
    char pad_15F4[0x58];
    void *field_164C;
};

extern "C" {
extern const char D_00491B98[];

void func_198260(void *p);
void func_1A9BF0(void *p);
int func_193190(void *p);
const char *func_1910F0();
const char *func_00189c80(void *self, int a1);
int func_11A498(char *dst, const char *fmt, ...);

void func_00189b40(RenderManagerDisplayReset *self);
void func_00189ba0(RenderManagerDisplayReset *self);
int func_00189bc0(RenderManagerDisplayReset *self);
char *func_00189c10(RenderManagerDisplayReset *self, int a1);
}

#endif
