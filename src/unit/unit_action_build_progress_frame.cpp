#pragma exceptions off
#include "unit_action_build_progress_frame.h"

int func_00270E70(ActionRebind *self) {
    void *master = *(void**)((char*)self + 4);
    float progress = *(float*)((char*)self + 288);
    float max_progress = *(float*)((char*)master + 328);

    float val = progress;
    if (max_progress < progress) {
        val = max_progress;
    }

    int result = func_123350(val);
    unsigned char max_frame = *(unsigned char*)((char*)master + 325);

    if ((int)max_frame < result) {
        result = (int)max_frame;
    }

    if (result > 0) {
        result--;
    }

    return result;
}
