#include "tactical_ai_combat_subsystem_controller_order_dispatch.h"

void func_0032E6B0(CombatSubsystemControllerInstance *self, int action_id, int a2, int a3, int t0) {
    if (t0 != 0) {
        func_0032E820(self);
    }

    if (self == 0) {
        return;
    }

    if (self->m_slot_count == 10) {
        self->m_slot_count = 0;
    }

    if (t0 == 0) {
        int slot = self->m_slot_count;
        if (slot >= 0 && slot < 10) {
            SlotEntry *entry = self->m_slots[slot];
            if (entry != 0 && (entry->flag & 4) != 0) {
                if (entry->action_id == self->m_slot_action_ids[slot]) {
                    if (self->m_sub12c != 0) {
                        sub_260ED0(self->m_sub12c->m_sub_target);
                    }
                    self->m_slots[slot] = 0;
                }
            }
        }
    }

    func_0032E640(self, 2);

    int param = 0;
    if (action_id == 2962) {
        param = 1;
    }
    if (a2 != 0) {
        param |= a2;
    }

    void *ret_slot = 0;
    if (self->m_sub12c != 0) {
        ret_slot = sub_260E50(self->m_sub12c->m_sub_target, action_id, 0, param & 0xFF, a3);
    }

    int cur_slot = self->m_slot_count;
    if (cur_slot >= 0 && cur_slot < 10) {
        self->m_slots[cur_slot] = (SlotEntry*)ret_slot;
        self->m_slot_action_ids[cur_slot] = action_id;
    }

    self->m_slot_count++;
}
