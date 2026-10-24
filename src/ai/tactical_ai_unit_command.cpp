#pragma exceptions off
#include "tactical_ai_unit_command.h"

int func_00305F30(void *self, Unit *source_unit, const char *cmd, Unit *target_unit, short mode, int flag, float x, float y, float z) {
    int s8 = 0;
    short s0 = mode;

    if (flag != 1) {
        if (s0 != 3) {
            goto L_mode2;
        }
    }

    if (!target_unit) {
        goto L_check_mode3;
    }

    {
        Player *target_player = target_unit->m_player;
        Player *source_player = source_unit->m_player;
        if (target_player != source_player) {
            if (!source_player->m_diplomacy->IsAlliedWith(target_player->m_player_id)) {
                return 0;
            }
            if (!target_player->m_diplomacy->IsAlliedWith(source_player->m_player_id)) {
                return 0;
            }
        }
        if (!target_unit->m_player->m_player_id) {
            return 0;
        }
        if (target_unit->m_field39 != 2) {
            return 0;
        }
        if (!target_unit->m_type_info || *(unsigned char *)target_unit->m_type_info != 80) {
            return 0;
        }
        if (*(unsigned char *)cmd != 70) {
            return 0;
        }
        Unit *leader = target_unit->m_formation_leader;
        Unit *target = leader ? leader : target_unit;
        UnitTypeInfo *type_info = target->m_type_info;

        if (*(unsigned char *)((char *)type_info + 1) > 0) {
            Manager *mgr = (Manager *)self;
            short act_count = mgr->m_action_count;
            for (short t3 = 0; t3 < act_count; t3++) {
                ActionDesc *desc = mgr->m_actions[t3];
                if (desc->m_type != 3 || desc->m_mode != 3) continue;
                if (s0 != -1 && s0 != desc->m_type) continue;

                short cat = *(short *)((char *)cmd + 14);
                unsigned char mask = type_info->m_class_flags;
                int matched = 0;

                if (cat == 43 || cat == 18) {
                    if (mask & 0x08) matched = 1;
                } else if (cat == 59 || cat == 19 || cat == 4) {
                    if (mask & 0x01) matched = 1;
                } else if (cat == 36 || cat == 57 || cat == 47 || cat == 12) {
                    if (mask & 0x04) matched = 1;
                } else if (cat == 44 || cat == 0 || cat == 56 || cat == 46 || cat == 45 || cat == 6 || cat == 50) {
                    if (mask & 0x02) matched = 1;
                }

                if (matched) {
                    short min_x, min_y, min_z;
                    target->GetTargetBoundingBox(&min_x, &min_y, &min_z, 0, 0);
                    if (min_x == 124 || min_x == 125) {
                        return 0;
                    }
                }
            }
        }

        if (s0 == -1 && *(short *)((char *)cmd + 14) == 4) {
            s8 = 1;
        }
    }

L_check_mode3:
    if (s0 == 3) {
        if (!target_unit || !target_unit->m_type_info || target_unit->m_type_info->m_category != 20) {
            return 0;
        }
    }

L_mode2:
    // Defect 1 fix: flag == 2 returns 0
    if (flag == 2) {
        return 0;
    }

    if (target_unit && target_unit->m_type_info && *(unsigned char *)target_unit->m_type_info == 80) {
        Unit *leader = target_unit->m_formation_leader;
        if (leader) target_unit = leader;
    }
    if (source_unit && source_unit->m_field3C == 57 && target_unit && target_unit->m_field39 == 2) {
        if (target_unit->m_player->m_player_id == source_unit->m_player->m_player_id) {
            if (target_unit->m_type_info && target_unit->m_type_info->m_type_id == 109) {
                Manager *mgr = (Manager *)self;
                for (short i = 0; i < mgr->m_action_count; i++) {
                    if (mgr->m_actions[i]->m_type == 135) {
                        return 0;
                    }
                }
            }
        }
    }

    if (source_unit) {
        Player *src_p = source_unit->m_player;
        float f380 = *(float *)((char *)src_p + 2988 + 380);
        short src_type = source_unit->m_type_info->m_type_id;

        if (f380 == 2.0f && (src_type == 448 || src_type == 546)) {
            if (target_unit && target_unit->m_type_info && target_unit->m_type_info->m_category == 4) {
                if (src_p->m_diplomacy->IsEnemyWith(target_unit->m_player->m_player_id)) {
                    Manager *mgr = (Manager *)self;
                    for (short i = 0; i < mgr->m_action_count; i++) {
                        if (mgr->m_actions[i]->m_type == 135) {
                            return 0;
                        }
                    }
                }
            }
        }

        if (f380 == 3.0f && (src_type == 448 || src_type == 546)) {
            if (target_unit && target_unit->m_type_info && target_unit->m_type_info->m_category == 3) {
                if (src_p->m_diplomacy->IsEnemyWith(target_unit->m_player->m_player_id)) {
                    Manager *mgr = (Manager *)self;
                    for (short i = 0; i < mgr->m_action_count; i++) {
                        if (mgr->m_actions[i]->m_type == 122) {
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // Segment B2: 0x306518 - 0x3066E8 (Defect 3 fix: preserve <= 0.0f polarity)
    if (source_unit && source_unit->m_field3C != -1) {
        float f64 = *(float *)((char *)source_unit + 64);
        if (f64 <= 0.0f) {
            goto L_segB3;
        }
        if (target_unit && target_unit->m_field39 == 2) {
            if (target_unit->m_player->m_player_id == source_unit->m_player->m_player_id) {
                short cmd_cat = *(short *)((char *)cmd + 14);
                short t3 = target_unit->m_type_info->m_type_id;
                short v1_val = -1;
                short a0_val = -1;

                if (cmd_cat == 21) {
                    if (source_unit->m_field3C == 9 || source_unit->m_field3C == 17) {
                        v1_val = 45;
                    }
                } else {
                    switch (source_unit->m_field3C) {
                    case 0:
                    case 15:
                    case 16:
                    case 17:
                        v1_val = 109; a0_val = 68; break;
                    case 1:
                        v1_val = 109; a0_val = 562; break;
                    case 2:
                    case 3:
                    case 56:
                        v1_val = 109; a0_val = 584; break;
                    }
                }

                if (t3 == v1_val || t3 == a0_val) {
                    Manager *mgr = (Manager *)self;
                    for (short t5 = 0; t5 < mgr->m_action_count; t5++) {
                        ActionDesc *desc = mgr->m_actions[t5];
                        if (*(short *)((char *)desc + 20) == source_unit->m_field3C) {
                            short t4 = desc->m_type;
                            if (t4 == 5 || (unsigned short)(t4 - 110) < 2) {
                                if (s0 == -1 || s0 == t4) {
                                    return 0;
                                }
                            }
                        }
                    }
                    if (t3 == v1_val || t3 == a0_val) {
                        return 0;
                    }
                }
            }
        }
    }

L_segB3:
    // Segment B3: 0x3066E8 - 0x3067E0
    if (target_unit && source_unit) {
        if (target_unit->m_player == source_unit->m_player) {
            if (target_unit->m_type_info && *(unsigned char *)target_unit->m_type_info == 80) {
                if (target_unit->m_field39 == 0) {
                    short min_x, min_y, min_z;
                    // Defect 2 fix: slot 217 emits physical offset 0x36C (876)
                    target_unit->GetTargetBoundingBox(&min_x, &min_y, &min_z, 0, 0);
                    if (min_z == 100) {
                        min_x = 0;
                    }
                    if (min_x != 124 && min_x != 125) {
                        Manager *mgr = (Manager *)self;
                        for (short i = 0; i < mgr->m_action_count; i++) {
                            ActionDesc *desc = mgr->m_actions[i];
                            if (desc->m_type == 101) {
                                if (s0 == -1 || s0 == desc->m_type) {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Segment C: 0x3067E0 - 0x3069D0 (Defect 4 fix: type 50 action finding logic)
    if (target_unit && source_unit) {
        if (target_unit->m_type_info && target_unit->m_type_info->m_type_id == 50) {
            int a1_found = 0;
            Manager *mgr = (Manager *)self;
            for (short s7_idx = 0; s7_idx < mgr->m_action_count; s7_idx++) {
                ActionDesc *desc = mgr->m_actions[s7_idx];
                if (desc->m_type != 5) continue;
                if (*(short *)((char *)desc + 10) != 50) continue;
                if (s0 != -1 && s0 != desc->m_type) continue;

                // Defect 2 fix: slot 53 emits physical offset 0xDC (220)
                if (source_unit->GetActionTarget() == target_unit) {
                    return (int)desc;
                }
                a1_found = 1;
                if (target_unit->m_field3A == 0) {
                    return (int)desc;
                }
            }
            if (a1_found != 0) {
                if (s0 == -1) return 0;
            } else {
                if (source_unit->m_type_info && source_unit->m_type_info->m_category == 4) {
                    if (s0 == -1) return 0;
                }
            }
        }
    }

    if (target_unit) {
        Player *target_player = target_unit->m_player;
        Player *source_player = source_unit ? source_unit->m_player : 0;
        if (source_player && target_player != source_player) {
            if (!source_player->m_diplomacy->IsAlliedWith(target_player->m_player_id)) {
                goto L_target_check;
            }
            if (!target_player->m_diplomacy->IsAlliedWith(source_player->m_player_id)) {
                goto L_target_check;
            }
        }
        if (target_unit->m_field39 < 3 && target_unit->m_type_info && target_unit->m_type_info->m_category == 20) {
            Manager *mgr = (Manager *)self;
            for (short t2 = 0; t2 < mgr->m_action_count; t2++) {
                ActionDesc *desc = mgr->m_actions[t2];
                if (desc->m_type == 3 && desc->m_mode == 20) {
                    if (s0 == -1 || s0 == desc->m_type) {
                        return 0;
                    }
                }
            }
            if (s0 == 3) {
                return 0;
            }
            if (s0 == -1 || s0 == 3) {
                s8 = 1;
            }
        }
    }

L_target_check:
    // Segment D: 0x3069D0 - 0x306DA0
    if (target_unit && target_unit->m_field39 < 3) {
        short type = target_unit->m_type_info->m_type_id;
        if (type == 45 || type == 84) {
            Manager *mgr = (Manager *)self;
            for (short t4 = 0; t4 < mgr->m_action_count; t4++) {
                ActionDesc *desc = mgr->m_actions[t4];
                if (desc->m_type == 111) {
                    if (*(short *)((char *)desc + 10) == type || desc->m_mode == target_unit->m_type_info->m_category) {
                        if (s0 == -1 || s0 == desc->m_type) {
                            return 0;
                        }
                    }
                }
            }
        }
    }

    if (target_unit && source_unit) {
        if (target_unit->m_player != source_unit->m_player) {
            if (target_unit->m_player->m_player_id != 0) {
                if (!source_unit->m_player->m_diplomacy->IsAlliedWith(target_unit->m_player->m_player_id)) {
                    goto L_check_s8;
                }
            }
        }
        short cat = target_unit->m_type_info->m_category;
        int is_repairable = 0;
        if (*(unsigned char *)target_unit->m_type_info == 80) is_repairable = 1;
        else if (cat == 20 || cat == 21 || cat == 22 || cat == 2 || cat == 13 || cat == 51 || (cat >= 53 && cat <= 55)) is_repairable = 1;

        if (is_repairable) {
            short max_hp = *(short *)((char *)target_unit->m_type_info + 62);
            float cur_hp = *(float *)((char *)target_unit + 48);
            if (cur_hp < (float)max_hp && target_unit->m_field39 < 3) {
                Manager *mgr = (Manager *)self;
                for (short t1 = 0; t1 < mgr->m_action_count; t1++) {
                    ActionDesc *desc = mgr->m_actions[t1];
                    if (desc->m_type == 106) {
                        if (desc->m_mode == -1 || desc->m_mode == 0) {
                            if (s0 == -1 || s0 == desc->m_type) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

L_check_s8:
    if (s8 != 0) {
        return 0;
    }

    if (source_unit && *(short *)((char *)cmd + 14) == 18) {
        if (target_unit && target_unit->m_player != source_unit->m_player) {
            if (target_unit->m_field39 < 3 && target_unit->m_player->m_player_id > 0) {
                if (!source_unit->m_player->m_diplomacy->IsAlliedWith(target_unit->m_player->m_player_id)) {
                    short cat = target_unit->m_type_info->m_category;
                    if (cat != 1 && cat != 42 && cat != 58 && cat != 14 && target_unit->m_type_info->m_type_id != 50) {
                        Manager *mgr = (Manager *)self;
                        for (short t0 = 0; t0 < mgr->m_action_count; t0++) {
                            ActionDesc *desc = mgr->m_actions[t0];
                            if (desc->m_type == 104) {
                                if (s0 == -1 || s0 == desc->m_type) {
                                    return 0;
                                }
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }

    // Segment E: 0x306DA0 - 0x307160
    if (target_unit && target_unit->m_field39 < 3) {
        short cat = target_unit->m_type_info->m_category;
        int is_huntable = 1;
        if (cat == 21 || cat == 2 || cat == 20 || cat == 22 || cat == 53 || cat == 51 || cat == 54 ||
            cat == 13 || cat == 55 || cat == 1 || cat == 27 || cat == 52 || cat == 39 || cat == 3) {
            is_huntable = 0;
        }

        if (is_huntable) {
            Manager *mgr = (Manager *)self;
            for (short t0 = 0; t0 < mgr->m_action_count; t0++) {
                ActionDesc *desc = mgr->m_actions[t0];
                if (desc->m_type == 105) {
                    if (s0 == -1 || s0 == desc->m_type) {
                        return 0;
                    }
                }
            }
            return 0;
        }
    }

    if (source_unit && *(short *)((char *)cmd + 14) == 53) {
        if (target_unit && target_unit->m_player != source_unit->m_player) {
            if (target_unit->m_field39 < 3 && target_unit->m_player->m_player_id > 0) {
                if (!source_unit->m_player->m_diplomacy->IsAlliedWith(target_unit->m_player->m_player_id)) {
                    short cat = target_unit->m_type_info->m_category;
                    if (cat == 2 || (unsigned short)(cat - 20) < 3 || cat == 53) {
                        Manager *mgr = (Manager *)self;
                        for (short t0 = 0; t0 < mgr->m_action_count; t0++) {
                            ActionDesc *desc = mgr->m_actions[t0];
                            if (desc->m_type == 104) {
                                if (s0 == -1 || s0 == desc->m_type) {
                                    return 0;
                                }
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }

    // Defect 5 fix: task 13 on category 1 returns 0 unconditionally once found
    if (source_unit && target_unit && target_unit->m_field39 < 3) {
        if (target_unit->m_player != source_unit->m_player) {
            if (source_unit->m_player->m_diplomacy->IsAlliedWith(target_unit->m_player->m_player_id)) {
                goto L_check_farm;
            }
        }
        if (target_unit->m_type_info->m_category == 1) {
            Manager *mgr = (Manager *)self;
            for (short a2 = 0; a2 < mgr->m_action_count; a2++) {
                ActionDesc *desc = mgr->m_actions[a2];
                if (desc->m_type == 13) {
                    if (s0 == desc->m_type) {
                        return (int)desc;
                    }
                    return 0;
                }
            }
        }
    }

L_check_farm:
    if (source_unit && target_unit) {
        if (target_unit->m_type_info->m_type_id == 594 && source_unit->m_type_info->m_category == 4) {
            Manager *mgr = (Manager *)self;
            for (short t2 = 0; t2 < mgr->m_action_count; t2++) {
                ActionDesc *desc = mgr->m_actions[t2];
                if (desc->m_type == 110 && *(short *)((char *)desc + 10) == 594) {
                    if (s0 == -1 || s0 == desc->m_type) {
                        return 0;
                    }
                }
            }
            return 0;
        }
    }

    return func_2cc2a0(self, source_unit, cmd, target_unit, mode, 0, x, y, z);
}
