#include "tactical_ai_target_scan_fixture.h"

static void test_gate_check_and_categories() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    reset_tracking(); s_gate_check_return = 0;
    func_00307B80(&mgr);
    assert(s_gate_check_calls == 1 && s_cleanup_calls == 0 && s_waypoint_cost_calls == 0);

    s_gate_check_return = 1;
    TargetEntitySubsystem sub; std::memset(&sub, 0, sizeof(sub));
    TargetPlayerManager cont0; std::memset(&cont0, 0, sizeof(cont0));
    TargetEntityList list0; std::memset(&list0, 0, sizeof(list0));
    TargetTypeDesc desc; std::memset(&desc, 0, sizeof(desc));
    TargetEntity ent; std::memset(&ent, 0, sizeof(ent));
    ent.m_type_desc = &desc;
    TargetEntity *ents[1] = {&ent};
    list0.m_entities = ents; list0.m_count = 1; cont0.m_list = &list0;
    TargetPlayerManager *players[1] = {&cont0};
    sub.m_players = players; mgr.m_field11C = &sub;

    desc.m_category = 33; mgr.m_field194 = 2; reset_tracking();
    func_00307B80(&mgr); assert(s_mark_calls == 1 && s_last_mark == 71 && s_last_a3 == 71 && s_last_t0 == 1);

    desc.m_category = 58; mgr.m_field194 = 2; reset_tracking();
    func_00307B80(&mgr); assert(s_mark_calls == 1 && s_last_mark == 70 && s_last_a3 == 70 && s_last_t0 == 1);

    desc.m_category = 99; mgr.m_field194 = 0; reset_tracking();
    func_00307B80(&mgr); assert(s_mark_calls == 1 && s_last_mark == 255 && s_last_a3 == 255 && s_last_t0 == 0);

    // Verify m_field1A0 toggle behavior (field == 0) across -1, 0, 1
    mgr.m_field19C = 0; s_timestamp = 400;
    mgr.m_field1A0 = -1; func_00307B80(&mgr); assert(mgr.m_field1A0 == 0);
    mgr.m_field19C = 0; s_timestamp = 400;
    mgr.m_field1A0 = 0; func_00307B80(&mgr); assert(mgr.m_field1A0 == 1);
    mgr.m_field19C = 0; s_timestamp = 400;
    mgr.m_field1A0 = 1; func_00307B80(&mgr); assert(mgr.m_field1A0 == 0);
}

static void test_player_lists_128_and_140() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    TargetEntitySubsystem sub; std::memset(&sub, 0, sizeof(sub));
    sub.m_player_count = 1; sub.m_my_player_index = 99;

    TargetPlayerManager own; std::memset(&own, 0, sizeof(own));
    own.m_diplomacy_vtable = s_diplomacy_vtable; mgr.m_player = &own;

    TargetPlayerManager player1; std::memset(&player1, 0, sizeof(player1));
    unsigned char color_buffer[64]; std::memset(color_buffer, 0, sizeof(color_buffer));
    color_buffer[24] = 5; player1.m_color_info = color_buffer;

    TargetEntity ent128; std::memset(&ent128, 0, sizeof(ent128));
    TargetEntity *items128[1] = {&ent128};
    player1.m_items128 = items128; player1.m_count132 = 1;
    TargetPlayerManager *players[2] = {0, &player1};
    sub.m_players = players; mgr.m_field11C = &sub;

    mgr.m_field194 = 0; reset_tracking();
    func_00307B80(&mgr);
    assert(s_mark_calls == 1);
    assert(s_mark_log[0].ent == &ent128);
    assert(s_mark_log[0].mark == 5 && s_mark_log[0].a3 == 5 && s_mark_log[0].t0 == 0);
}

static void test_mode_1_overlapping_and_nonallied_250() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_field194 = 1;
    TargetEntitySubsystem sub; std::memset(&sub, 0, sizeof(sub));
    sub.m_player_count = 2; sub.m_my_player_index = 99;

    TargetPlayerManager own; std::memset(&own, 0, sizeof(own));
    own.m_diplomacy_vtable = s_diplomacy_vtable; own.m_player_id = 10;
    mgr.m_player = &own;

    TargetPlayerManager ally; std::memset(&ally, 0, sizeof(ally)); ally.m_player_id = 20;
    TargetPlayerManager enemy; std::memset(&enemy, 0, sizeof(enemy)); enemy.m_player_id = 30;

    unsigned char color_buf[64]; std::memset(color_buf, 0, sizeof(color_buf));
    color_buf[24] = 242; enemy.m_color_info = color_buf; ally.m_color_info = color_buf; own.m_color_info = color_buf;

    // Case 1: own player cat 20 + type 80 -> cat 20 only (1 call)
    TargetTypeDesc desc1; std::memset(&desc1, 0, sizeof(desc1));
    desc1.m_category = 20; desc1.m_type_code = 80; desc1.m_flag424 = 1;
    TargetEntity ent1; std::memset(&ent1, 0, sizeof(ent1)); ent1.m_type_desc = &desc1;
    TargetEntity *units1[1] = {&ent1}; own.m_units = units1; own.m_unit_count = 1;
    TargetPlayerManager *players1[2] = {0, &own}; sub.m_players = players1; sub.m_player_count = 1;
    mgr.m_field11C = &sub; reset_tracking(); func_00307B80(&mgr);
    assert(s_action_calls == 1 && s_action_log[0].ent == &ent1);

    // Case 2: cat 20 + tag 4 -> 2 calls; with ID 125 -> 3 calls
    desc1.m_tag77 = 4; reset_tracking(); func_00307B80(&mgr); assert(s_action_calls == 2);
    desc1.m_id = 125; reset_tracking(); func_00307B80(&mgr); assert(s_action_calls == 3);

    // Case 3: non-allied ID 250 -> 1 call; allied ID 250 + tag 4 -> 1 action + 1 mark (245/245)
    TargetTypeDesc d250; std::memset(&d250, 0, sizeof(d250)); d250.m_id = 250;
    TargetEntity e_enemy; std::memset(&e_enemy, 0, sizeof(e_enemy)); e_enemy.m_type_desc = &d250;
    TargetEntity *e_units[1] = {&e_enemy}; enemy.m_units = e_units; enemy.m_unit_count = 1;

    TargetTypeDesc d_ally; std::memset(&d_ally, 0, sizeof(d_ally)); d_ally.m_id = 250; d_ally.m_tag77 = 4;
    TargetEntity e_ally; std::memset(&e_ally, 0, sizeof(e_ally)); e_ally.m_type_desc = &d_ally;
    void *ent_vt[100]; std::memset(ent_vt, 0, sizeof(ent_vt));
    auto vslot_fn = [](void *) -> int { return 12; };
    ent_vt[83] = reinterpret_cast<void *>(+vslot_fn); e_ally.m_vtable = ent_vt;
    TargetEntity *a_units[1] = {&e_ally}; ally.m_units = a_units; ally.m_unit_count = 1;

    TargetPlayerManager *players2[3] = {0, &ally, &enemy};
    sub.m_players = players2; sub.m_player_count = 2; own.m_unit_count = 0;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_action_calls == 2 && s_mark_calls == 1 && s_last_mark == 245 && s_last_a3 == 245);

    // Case 4: category != 20 with type 80 + tag 4 -> type 80 (call 0) + tag 4 (call 1)
    TargetTypeDesc desc_c4; std::memset(&desc_c4, 0, sizeof(desc_c4));
    desc_c4.m_type_code = 80; desc_c4.m_tag77 = 4; desc_c4.m_flag424 = 1;
    TargetEntity ent_c4; std::memset(&ent_c4, 0, sizeof(ent_c4)); ent_c4.m_type_desc = &desc_c4;
    TargetEntity *units_c4[1] = {&ent_c4}; own.m_units = units_c4; own.m_unit_count = 1;
    sub.m_players = players1; sub.m_player_count = 1;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_action_calls == 2);
    assert(s_action_log[0].ent == &ent_c4 && s_action_log[0].a2 == 242);
    assert(s_action_log[0].s6 == 23 && s_action_log[0].s2 == 17);
    assert(s_action_log[1].ent == &ent_c4 && s_action_log[1].a2 == 242);
    assert(s_action_log[1].s6 == 23 && s_action_log[1].s2 == 17);
}

static void test_mode_2_gates_and_bounds() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_field194 = 2; mgr.m_field1A0 = 1;
    TargetEntitySubsystem sub; std::memset(&sub, 0, sizeof(sub));
    sub.m_player_count = 1; sub.m_my_player_index = 99;

    TargetPlayerManager own; std::memset(&own, 0, sizeof(own));
    own.m_diplomacy_vtable = s_diplomacy_vtable; own.m_player_id = 10;
    mgr.m_player = &own;

    unsigned char color_buf[64]; std::memset(color_buf, 0, sizeof(color_buf));
    color_buf[24] = 7; own.m_color_info = color_buf;

    // Cat 84 in Mode 2 -> mark_calls == 1
    TargetTypeDesc d84; std::memset(&d84, 0, sizeof(d84)); d84.m_category = 84;
    TargetEntity e84; std::memset(&e84, 0, sizeof(e84)); e84.m_type_desc = &d84;
    TargetEntity *units[1] = {&e84}; own.m_units = units; own.m_unit_count = 1;
    TargetPlayerManager *players[2] = {0, &own}; sub.m_players = players; mgr.m_field11C = &sub;

    reset_tracking(); func_00307B80(&mgr);
    assert(s_mark_calls == 1 && s_last_mark == 7);

    // Foreign ID 274 is skipped
    TargetPlayerManager foreign; std::memset(&foreign, 0, sizeof(foreign));
    foreign.m_player_id = 20; foreign.m_color_info = color_buf;
    TargetTypeDesc d274; std::memset(&d274, 0, sizeof(d274)); d274.m_id = 274;
    TargetEntity e274; std::memset(&e274, 0, sizeof(e274)); e274.m_type_desc = &d274;
    TargetEntity *f_units[1] = {&e274}; foreign.m_units = f_units; foreign.m_unit_count = 1;
    TargetPlayerManager *players_f[2] = {0, &foreign}; sub.m_players = players_f;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_mark_calls == 0 && s_action_calls == 0); // skipped

    // Field 36 & 1 is skipped
    e84.m_field36 = 1; sub.m_players = players;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_mark_calls == 0);
}

int main() {
    test_gate_check_and_categories();
    test_player_lists_128_and_140();
    test_mode_1_overlapping_and_nonallied_250();
    test_mode_2_gates_and_bounds();
    return 0;
}
