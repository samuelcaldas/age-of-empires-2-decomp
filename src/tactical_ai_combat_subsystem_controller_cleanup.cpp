#include "tactical_ai_combat_subsystem_controller_cleanup.h"

void func_0032E820(CombatSubsystemControllerInstance *self) {
    if (self == 0) {
        return;
    }

    for (int i = 0; i < 10; i++) {
        SlotEntry *entry = self->m_slots[i];
        if (entry != 0 && (entry->flag & 4) == 4) {
            SlotSub *sub = entry->m_sub;
            if (sub != 0 && (int)sub->action_id == self->m_slot_action_ids[i]) {
                if (self->m_sub12c != 0) {
                    sub_260ED0(self->m_sub12c->m_sub_target);
                }
                self->m_slots[i] = 0;
            }
        }
    }

    self->m_slot_count = 0;
}
