#include "hud_command_bar.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

static int test_state_init(void) {
    HudCommandState state;
    int ret = hud_command_bar_init(&state);
    assert(ret == 0);
    assert(state.active_slot_index == -1);
    for (int i = 0; i < 15; ++i) {
        assert(state.slots[i].state == HUD_BTN_STATE_HIDDEN);
        assert(state.slots[i].action_id == 0);
    }
    return 0;
}

static int test_set_slot_properties(void) {
    HudCommandState state;
    hud_command_bar_init(&state);

    int ret = hud_command_bar_set_slot(&state, 0, 101, 50100, 'A', HUD_PAD_CROSS, HUD_BTN_STATE_NORMAL);
    assert(ret == 0);
    assert(state.slots[0].action_id == 101);
    assert(state.slots[0].icon_slp_id == 50100);
    assert(state.slots[0].hotkey_char == 'A');
    assert(state.slots[0].pad_button == HUD_PAD_CROSS);
    assert(state.slots[0].state == HUD_BTN_STATE_NORMAL);
    return 0;
}

static int test_hit_test_active_slots(void) {
    HudLayoutConfig cfg;
    hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 640, 480);

    HudCommandState state;
    hud_command_bar_init(&state);

    /* Enable slots 0, 7, 14 */
    hud_command_bar_set_slot(&state, 0, 1, 10, 'Q', HUD_PAD_CROSS, HUD_BTN_STATE_NORMAL);
    hud_command_bar_set_slot(&state, 7, 2, 11, 'W', HUD_PAD_CIRCLE, HUD_BTN_STATE_NORMAL);
    hud_command_bar_set_slot(&state, 14, 3, 12, 'E', HUD_PAD_SQUARE, HUD_BTN_STATE_NORMAL);

    /* Click center of slot 0 */
    int x0 = (cfg.command_panel.button_grid[0].left + cfg.command_panel.button_grid[0].right) / 2;
    int y0 = (cfg.command_panel.button_grid[0].top + cfg.command_panel.button_grid[0].bottom) / 2;
    assert(hud_command_bar_hit_test(&cfg.command_panel, &state, x0, y0) == 0);

    /* Click center of slot 7 */
    int x7 = (cfg.command_panel.button_grid[7].left + cfg.command_panel.button_grid[7].right) / 2;
    int y7 = (cfg.command_panel.button_grid[7].top + cfg.command_panel.button_grid[7].bottom) / 2;
    assert(hud_command_bar_hit_test(&cfg.command_panel, &state, x7, y7) == 7);

    /* Click center of slot 14 */
    int x14 = (cfg.command_panel.button_grid[14].left + cfg.command_panel.button_grid[14].right) / 2;
    int y14 = (cfg.command_panel.button_grid[14].top + cfg.command_panel.button_grid[14].bottom) / 2;
    assert(hud_command_bar_hit_test(&cfg.command_panel, &state, x14, y14) == 14);
    return 0;
}

static int test_hit_test_hidden_slot(void) {
    HudLayoutConfig cfg;
    hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 640, 480);

    HudCommandState state;
    hud_command_bar_init(&state);
    /* Slot 3 is HIDDEN */

    int x3 = (cfg.command_panel.button_grid[3].left + cfg.command_panel.button_grid[3].right) / 2;
    int y3 = (cfg.command_panel.button_grid[3].top + cfg.command_panel.button_grid[3].bottom) / 2;
    assert(hud_command_bar_hit_test(&cfg.command_panel, &state, x3, y3) == -1);

    /* Click in minimap area */
    assert(hud_command_bar_hit_test(&cfg.command_panel, &state, 50, 400) == -1);
    return 0;
}

static int test_hp_ratio_calculation(void) {
    HudUnitStatus unit;
    int percent = 0;
    int color_class = 0;

    /* Full health: 100/100 -> 100%, Green (class 2) */
    unit.current_hp = 100;
    unit.max_hp = 100;
    assert(hud_unit_calc_hp_ratio(&unit, &percent, &color_class) == 0);
    assert(percent == 100);
    assert(color_class == 2);

    /* Yellow zone: 40/100 -> 40%, Yellow (class 1) */
    unit.current_hp = 40;
    unit.max_hp = 100;
    assert(hud_unit_calc_hp_ratio(&unit, &percent, &color_class) == 0);
    assert(percent == 40);
    assert(color_class == 1);

    /* Red zone: 15/100 -> 15%, Red (class 0) */
    unit.current_hp = 15;
    unit.max_hp = 100;
    assert(hud_unit_calc_hp_ratio(&unit, &percent, &color_class) == 0);
    assert(percent == 15);
    assert(color_class == 0);

    /* Dead / 0 HP */
    unit.current_hp = 0;
    unit.max_hp = 50;
    assert(hud_unit_calc_hp_ratio(&unit, &percent, &color_class) == 0);
    assert(percent == 0);
    assert(color_class == 0);
    return 0;
}

static int test_error_handling(void) {
    HudCommandState state;
    hud_command_bar_init(&state);
    /* Out of range slot indices */
    assert(hud_command_bar_set_slot(&state, -1, 1, 1, 'X', HUD_PAD_NONE, HUD_BTN_STATE_NORMAL) != 0);
    assert(hud_command_bar_set_slot(&state, 15, 1, 1, 'X', HUD_PAD_NONE, HUD_BTN_STATE_NORMAL) != 0);
    assert(hud_command_bar_set_slot(NULL, 0, 1, 1, 'X', HUD_PAD_NONE, HUD_BTN_STATE_NORMAL) != 0);

    /* Invalid HP zero max */
    HudUnitStatus unit;
    unit.current_hp = 10;
    unit.max_hp = 0;
    int pct, cls;
    assert(hud_unit_calc_hp_ratio(&unit, &pct, &cls) != 0);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_state_init();
        case 1: return test_set_slot_properties();
        case 2: return test_hit_test_active_slots();
        case 3: return test_hit_test_hidden_slot();
        case 4: return test_hp_ratio_calculation();
        case 5: return test_error_handling();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
