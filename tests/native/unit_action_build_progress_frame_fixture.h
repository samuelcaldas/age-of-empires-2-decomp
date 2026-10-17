#ifndef UNIT_ACTION_BUILD_PROGRESS_FRAME_FIXTURE_H
#define UNIT_ACTION_BUILD_PROGRESS_FRAME_FIXTURE_H

#include <cstddef>
#include "unit_action_build_progress_frame.h"

struct DummyFrameMaster {
    char pad_00[325];
    unsigned char m_max_frame;
    char pad_146[2];
    float m_max_progress;
};

struct DummyFrameAction {
    void *vtable;
    DummyFrameMaster *m_master;
    char pad_08[280];
    float m_progress;
};

static int g_func_123350_called = 0;

extern "C" {
    int func_123350(float val) {
        g_func_123350_called++;
        return (int)val;
    }
}

#endif // UNIT_ACTION_BUILD_PROGRESS_FRAME_FIXTURE_H
