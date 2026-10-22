#ifndef TACTICAL_AI_TARGET_SCAN_HELPERS_H
#define TACTICAL_AI_TARGET_SCAN_HELPERS_H

#include "tactical_ai_target_scan.h"

typedef int (*DiplomacyQueryFn)(void *, int);
typedef int (*VirtualMethodFn)(void *);

static const int S_TABLE_336[8] = { 242, 36, 241, 243, 133, 252, 84, 251 };
static const int S_TABLE_368[8] = { 23, 35, 51, 67, 131, 114, 82, 98 };
static const int S_TABLE_400[8] = { 17, 34, 51, 64, 128, 113, 80, 97 };

static inline void ScanPlayerLists140And128(TargetScanManager *self, TargetPlayerManager *p, int s0, int s3) {
    if (p->m_items140) {
        for (int i = 0; i < p->m_count144; i++) {
            TargetEntity *ent = p->m_items140[i];
            if (!ent) continue;
            if (self->m_field194 == 2) {
                if (ent->m_type_desc && ent->m_type_desc->m_id == 50) {
                    func_309500(self, ent, 78, 78, 0);
                }
            } else {
                func_309500(self, ent, s0, s3, 0);
            }
        }
    }

    if (self->m_field194 == 0 && p->m_items128) {
        for (int i = 0; i < p->m_count132; i++) {
            TargetEntity *ent = p->m_items128[i];
            if (!ent) continue;
            func_309500(self, ent, s0, s3, 0);
        }
    }
}

static inline void ScanMode2Units(TargetScanManager *self, TargetPlayerManager *p, TargetEntity *ent, TargetTypeDesc *desc, int s0) {
    if (self->m_player && self->m_player->m_player_id == p->m_player_id) {
        if (!desc) return;
        short cat = desc->m_category;
        if (cat == 84 || cat == 45) {
            func_309500(self, ent, s0, 0, 0);
        } else if (cat == 128 || cat == 204 || cat == 4 || cat == 21 || cat == 2) {
            void **vt = *(void ***)ent;
            if (vt && ((VirtualMethodFn)vt[88])(ent) && self->m_field1A0) {
                func_309500(self, ent, s0, 0, 0);
            }
        }
    } else {
        if (desc && (desc->m_category == 84 || desc->m_category == 45)) {
            func_309500(self, ent, s0, 0, 0);
        }
    }
}

static inline void ScanMode1Units(TargetScanManager *self, TargetPlayerManager *p, TargetEntity *ent, TargetTypeDesc *desc, int is_ally, int is_enemy_or_neutral, int s0, int s3, int s6, int s2) {
    if (!desc) return;

    if (desc->m_id == 250 || desc->m_id == 533) {
        func_309330(self, ent, s0, s6 & 0xFF, s2 & 0xFF);
    }

    if (self->m_player && self->m_player->m_player_id == p->m_player_id) {
        if (desc->m_id == 125) {
            func_309330(self, ent, s0, s6 & 0xFF, s2 & 0xFF);
        }
        if (desc->m_category == 20) {
            func_309330(self, ent, s0, s6 & 0xFF, s2 & 0xFF);
        } else if (desc->m_type_code == 80 && (desc->m_flag424 & 1) &&
                   func_00268500(ent) && func_00268530(ent) > 0 &&
                   func_00268610(ent, -1, -1, 2, -1, -1, -1, -1) > 0) {
            func_309330(self, ent, s0, s6 & 0xFF, s2 & 0xFF);
        }
        if (desc->m_tag77 == 4) {
            func_309330(self, ent, s0, s6 & 0xFF, s2 & 0xFF);
        }
    } else if (is_ally) {
        if (desc->m_id == 125) {
            func_309330(self, ent, s0, s6 & 0xFF, s2 & 0xFF);
        }
        if (desc->m_tag77 == 4) {
            void **vt = *(void ***)ent;
            int res = (vt && vt[83]) ? (((VirtualMethodFn)vt[83])(ent) & 0xFF) : 0;
            if (res == 12) {
                func_309500(self, ent, (s0 & 0xFF) + 3, (s3 & 0xFF) + 3, 0);
            } else {
                func_309500(self, ent, s0, s3, 0);
            }
        }
    } else if (is_enemy_or_neutral) {
        if (desc->m_tag77 == 4) {
            func_309500(self, ent, s0, s3, 0);
        }
    }
}

static inline void ScanPlayerPrimaryUnits(TargetScanManager *self, TargetPlayerManager *p, int is_ally, int is_enemy_or_neutral, int s0, int s3, int s6, int s2) {
    if (!p->m_units) return;

    for (int i = 0; i < p->m_unit_count; i++) {
        TargetEntity *ent = p->m_units[i];
        if (!ent || (ent->m_field36 & 1)) continue;

        TargetTypeDesc *desc = ent->m_type_desc;
        if (desc && desc->m_id == 274 && p != self->m_player) continue;

        if (self->m_field194 == 0) {
            func_309500(self, ent, s0, s3, 0);
        } else if (self->m_field194 == 2) {
            ScanMode2Units(self, p, ent, desc, s0);
        } else if (self->m_field194 == 1) {
            ScanMode1Units(self, p, ent, desc, is_ally, is_enemy_or_neutral, s0, s3, s6, s2);
        }
    }
}

#endif // TACTICAL_AI_TARGET_SCAN_HELPERS_H
