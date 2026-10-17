#ifndef RENDER_MANAGER_CLOSE_WINDOW_H
#define RENDER_MANAGER_CLOSE_WINDOW_H

struct RenderManagerCloseWindow {
    char pad_00[0x2C];
    void *field_2C;
    int field_30;
    char pad_34[0x34];
    int field_68;
};

extern "C" {
void func_226180(void *hwnd, int cmd);
void func_225750(int arg);

int func_00187660(RenderManagerCloseWindow *self);
}

#endif
