#pragma exceptions off
#include "render_manager_chat_init.h"

extern "C" {

ChatLog *func_00188df0(ChatLog *self, int a1) {
    func_117CAC(self->field_4, 0, 0x28);
    func_117CAC(self->field_2C, 0, 0x28);
    self->field_128 = 0;
    self->field_0 = a1;
    self->field_120 = 0;

    for (int i = 0; i <= 50; i++) {
        self->field_54[i] = 0;
    }

    self->field_124 = 0;

    for (int j = 0; j <= 9; j++) {
        func_189160(self, j, 0);
    }

    return self;
}

}
