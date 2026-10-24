#pragma exceptions off

#include "zone_cursor_controller_render_sprite.h"

extern "C" {
extern void *D_004E3244;
void func_1EE8C0(void *obj, void *p1, void *p2, int count);
}

struct CursorController {
    char pad[0x10];
};

extern "C" void func_001DB890(CursorController *self, int x, int y, int frame, int w, int h) {
    if (self == 0) {
        return;
    }
    func_1EE8C0(D_004E3244, 0, 0, 0x19);
}
