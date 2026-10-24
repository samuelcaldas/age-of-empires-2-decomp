#pragma exceptions off
#include "tactical_ai_target_scan_helpers.h"

static void ScanGlobalEntities(TargetScanManager *self, TargetEntitySubsystem *sub) {
    if (!sub || !sub->m_players || !sub->m_players[0]) return;
    TargetEntityList *list = sub->m_players[0]->m_list;
    if (!list) return;

    int count = list->m_count;
    TargetEntity **entities = list->m_entities;
    int mode = self->m_field194;

    for (int i = 0; i < count; i++) {
        TargetEntity *ent = entities[i];
        if (!ent || mode == 1) continue;

        TargetTypeDesc *desc = ent->m_type_desc;
        if (!desc) continue;
        short cat = desc->m_category;

        if (mode == 2) {
            if (cat == 33 || cat == 31 || cat == 5) {
                func_309500(self, ent, 71, 71, 1);
            } else if (cat == 58 || cat == 9 || cat == 7) {
                func_309500(self, ent, 70, 70, 1);
            } else if (cat == 32) {
                func_309500(self, ent, 68, 68, 0);
            } else if (cat == 42) {
                func_309500(self, ent, 69, 69, 0);
            } else if (cat == 8) {
                func_309500(self, ent, 66, 66, 0);
            }
        } else if (mode == 0) {
            if (cat == 58 || cat == 10 || cat == 9 || cat == 7) {
                func_309500(self, ent, 70, 70, 1);
            } else if (cat == 33 || cat == 31 || cat == 5) {
                func_309500(self, ent, 71, 71, 1);
            } else if (cat == 8) {
                func_309500(self, ent, 66, 66, 0);
            } else if (cat == 42) {
                func_309500(self, ent, 69, 69, 0);
            } else if (cat == 32) {
                func_309500(self, ent, 68, 68, 0);
            } else {
                func_309500(self, ent, 255, 255, 0);
            }
        }
    }
}

static void ScanPlayerDiplomacyAndUnits(TargetScanManager *self, TargetEntitySubsystem *sub) {
    if (!sub || !self->m_player) return;
    int player_count = sub->m_player_count;
    void **diplomacy = *(void ***)((char *)self->m_player + 6960);
    if (!diplomacy) return;

    DiplomacyQueryFn is_enemy = (DiplomacyQueryFn)diplomacy[8];
    DiplomacyQueryFn is_ally = (DiplomacyQueryFn)diplomacy[9];
    DiplomacyQueryFn is_neutral = (DiplomacyQueryFn)diplomacy[10];

    for (int p_idx = 1; p_idx <= player_count; p_idx++) {
        if (p_idx == sub->m_my_player_index || p_idx == 0) continue;
        TargetPlayerManager *p = sub->m_players[p_idx];
        if (!p) continue;

        int ally = is_ally(self->m_player, p_idx);
        int enemy = is_enemy(self->m_player, p_idx);
        int neutral = is_neutral(self->m_player, p_idx);

        int color = p->m_color_info ? *(unsigned char *)((char *)p->m_color_info + 24) : 0;
        int s0 = color;
        int s3 = color;
        int s6 = 0;
        int s2 = 0;

        if (self->m_field194 == 1) {
            for (int a2 = 0; a2 < 8; a2++) {
                if (s3 == S_TABLE_336[a2]) {
                    s6 = S_TABLE_368[a2];
                    s2 = S_TABLE_400[a2];
                    break;
                }
            }
        }

        ScanPlayerLists140And128(self, p, s0, s3);
        ScanPlayerPrimaryUnits(self, p, ally, enemy || neutral, s0, s3, s6, s2);
    }
}

static void ScanSpecialTablesAndBuildings(TargetScanManager *self, TargetPlayerManager *player) {
    if (!player) return;

    if (player->m_fieldD50 > 0) {
        self->m_field184 = 3;
        for (int i = 0; i < 40 && i < player->m_fieldD50; i++) {
            TargetEntity *ent = player->m_table3244[i];
            if (!ent) continue;
            func_309500(self, ent, 255, 255, 0);
            TargetTypeDesc *desc = ent->m_type_desc;
            if (desc && (desc->m_tag77 == 10 || desc->m_tag77 == 2) && ent->m_flag347) {
                int tx = func_123350(ent->m_coord348);
                int ty = func_123350(ent->m_coord352);
                func_00308A70(self, tx, ty, 255, 2);
            }
        }
    }

    self->m_field184 = 4;
    if (player->m_units) {
        for (int i = 0; i < player->m_unit_count; i++) {
            TargetEntity *ent = player->m_units[i];
            if (!ent || !func_26ad20(ent, 16)) continue;
            if (self->m_field194 != 2 && self->m_field194 != 3) {
                TargetTypeDesc *desc = ent->m_type_desc;
                int tag = desc ? desc->m_tag78 : 0;
                func_309500(self, ent, tag, tag, 0);
            }
        }
    }

    self->m_field184 = 100;
    if (player->m_units) {
        for (int i = 0; i < player->m_unit_count; i++) {
            TargetEntity *ent = player->m_units[i];
            if (!ent) continue;
            TargetTypeDesc *desc = ent->m_type_desc;
            if (desc && desc->m_id == 274) {
                int tx = func_123350(ent->m_posX);
                int ty = func_123350(ent->m_posY);
                int mark = self->m_field1A0 ? 70 : 69;
                func_00308A70(self, tx, ty, mark, 4);
            }
        }
    }
}

void func_00307B80(TargetScanManager *self) {
    int now = func_2261c0();
    if ((unsigned int)(now - self->m_field19C) >= 333U) {
        self->m_field1A0 = (self->m_field1A0 == 0);
        self->m_field19C = now;
    }

    if (!func_1ab8f0(self->m_field20, 1)) {
        return;
    }

    self->m_field184 = 1;
    ScanGlobalEntities(self, self->m_field11C);

    func_00307640(self);

    self->m_field184 = 2;
    ScanPlayerDiplomacyAndUnits(self, self->m_field11C);

    ScanSpecialTablesAndBuildings(self, self->m_player);

    func_1ab9d0(self->m_field20);
}
