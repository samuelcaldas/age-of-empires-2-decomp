#pragma exceptions off
#include "tactical_ai_target_dispatch.h"

typedef int (*DiplomacyQueryFn)(void *, int);

void func_003088A0(TargetScanManager *self, int arg1, int arg2, int arg3, int arg4, TargetEntity *ent) {
    int s2_mark = arg3;
    int s1_code = arg4;

    unsigned char flag57 = *(unsigned char *)((char *)ent + 57);
    if (flag57 == 0) {
        TargetTypeDesc *desc = ent->m_type_desc;
        if (desc && desc->m_type_code == 80 && ent->m_field368 == 0.0f) {
            void *v0 = func_186010(D_004E3180);
            TargetPlayerManager *p = *(TargetPlayerManager **)((char *)ent + 8);
            if (!v0) return;

            void **diplomacy = *(void ***)((char *)v0 + 6960);
            DiplomacyQueryFn is_ally = (DiplomacyQueryFn)diplomacy[9];
            if (!is_ally(v0, p ? p->m_player_id : 0)) {
                return;
            }
        }
    }

    if (self->m_field184 == 4) {
        if (self->m_field1A0 == 0) {
            s2_mark = 69;
        } else {
            TargetPlayerManager *p = *(TargetPlayerManager **)((char *)ent + 8);
            int p_id = p ? p->m_player_id : 0;
            TargetEntitySubsystem *sub = self->m_field11C;
            if (sub && sub->m_players && sub->m_players[p_id] && sub->m_players[p_id]->m_color_info) {
                s2_mark = *(unsigned char *)((char *)sub->m_players[p_id]->m_color_info + 24);
            }
        }
    } else if (self->m_field184 == 100) {
        s2_mark = (self->m_field1A0 == 0) ? 70 : 69;
    }

    TargetTypeDesc *desc = ent->m_type_desc;
    if (desc) {
        if (desc->m_id == 276) {
            s1_code = 4;
        } else if (desc->m_id == 104 && ent->m_field364 > 0) {
            s1_code = 4;
        }
    }

    func_1a4960(self, arg1, arg2, s2_mark, s1_code, ent);
}
