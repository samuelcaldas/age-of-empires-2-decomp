#pragma exceptions off
#include "unit_action_build_retry_reset.h"

struct ActionBuildLayout {
    char pad[0x15A];
    unsigned char m_field15A;
};

void func_00270E30(ActionRebind *self) {
    ActionBuildLayout *act = (ActionBuildLayout*)self;
    unsigned char status = act->m_field15A;
    if (status != 0xFF) {
        func_270BA0(self, status);
        act->m_field15A = 0xFF;
    }
}
