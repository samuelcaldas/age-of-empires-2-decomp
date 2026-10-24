#pragma exceptions off

#include "render_manager_loop.h"

extern "C" {
int func_00185230(RenderManagerLoop *self) {
    self->field_1C = 0;
    MSG msg = D_00391CD0;

    while (func_2265D0(&msg, 0, 0, 0, 1)) {
        if (msg.message == 0x12) { // WM_QUIT
            if (D_004E89C4 == 0) {
                break;
            }
            D_004E89C4 = 0;
        }

        if (self->PreTranslateMessage(&msg) == 0) {
            continue;
        }

        const InputTableEntry *entry = 0;
        int status = func_185160(&msg, &entry);
        if (D_004E89C8 == 0) {
            if (status > 0) {
                D_004E89C8 = entry;
            }
            func_226620(&msg);
            func_226630(&msg);
            continue;
        }

        if (status < 0) {
            if (msg.message == D_004E89C8->field_4) {
                if (D_004E89C8->field_8 == 0 || D_004E89C8->field_8 == msg.wParam) {
                    D_004E89C8 = 0;
                }
            } else if (D_004E89C8->field_4 == 0) {
                D_004E89C8 = 0;
            }
        }

        if (D_004E89C8 == 0 || status == 0 || (D_004E89C8->id == msg.message && (D_004E89C8->field_8 == 0 || D_004E89C8->field_8 == msg.wParam))) {
            func_226620(&msg);
            func_226630(&msg);
        }
    }

    self->OnIdle();
    func_388010();
    return 0;
}
}
