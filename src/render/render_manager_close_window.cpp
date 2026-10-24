#pragma exceptions off
#include "render_manager_close_window.h"

extern "C" {
int func_00187660(RenderManagerCloseWindow *self) {
    self->field_30 = 0;
    if (self->field_68 != 0) {
        func_226180(self->field_2C, 1);
    }
    self->field_2C = 0;
    func_225750(0);
    return 1;
}
}
