#ifndef RENDER_MANAGER_DRAW_BUFFER_H
#define RENDER_MANAGER_DRAW_BUFFER_H

struct DrawBufferItem {
    int field_0;
    int field_4;
    char pad[0x40];
};

struct RenderManagerDrawBuffer {
    char pad_00[0x4];
    char field_4[0xC];
    int field_10;
    DrawBufferItem *field_14;
    int field_18;
};

extern const int D_00391CF0[];
extern const char D_003921D0[];
extern const char D_00567CA0[];

extern "C" {
void func_21BC30(const void *entry, const void *ptr, int a, int b, int c);
int func_219FB0(void *ptr, int a, int b, int c);

int func_00188c00();
RenderManagerDrawBuffer *func_00188c10(RenderManagerDrawBuffer *self);
void func_00188c20(RenderManagerDrawBuffer *self, int a1);
int func_00188cf0(RenderManagerDrawBuffer *self, int idx);
void *func_00188db0(RenderManagerDrawBuffer *self);
int func_00188dc0(RenderManagerDrawBuffer *self);
void *func_00188dd0(RenderManagerDrawBuffer *self, int idx);
}

#endif // RENDER_MANAGER_DRAW_BUFFER_H
