#pragma exceptions off
#include "unit_action_build_690.h"

void func_00271690(ActionRebind *self, void *stream) {
    func_001C4240(self, stream);
    for (int i = 0; i < 3; ++i) {
        func_00226F70(stream, (char *)self + 300 + i * 6, 6);
    }
    func_00226F70(stream, (char *)self + 318, 2);
    func_00226F70(stream, (char *)self + 328, 4);
    func_00226F70(stream, (char *)self + 325, 1);
}
