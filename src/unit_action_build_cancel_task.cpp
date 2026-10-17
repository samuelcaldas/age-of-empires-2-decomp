#pragma exceptions off
#include "unit_action_build_cancel_task.h"

struct TaskCleanupAction {
    char pad_00[336];
    void *m_slots;
    char pad_154[2];
    unsigned char m_cap;
    unsigned char m_count;
};

void func_0026FF60(ActionRebind *self) {
    TaskCleanupAction *a = (TaskCleanupAction*)self;
    if (a->m_count == 0) {
        if (a->m_slots != 0) {
            func_116F68(a->m_slots);
            a->m_slots = 0;
        }
        a->m_cap = 0;
    }
}
