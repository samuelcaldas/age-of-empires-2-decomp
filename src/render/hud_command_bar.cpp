#include "hud_command_bar.h"
#include <string.h>

extern "C" {

int hud_command_bar_init(HudCommandState *state) {
    if (!state) {
        return -1;
    }
    memset(state, 0, sizeof(*state));
    state->active_slot_index = -1;
    for (int i = 0; i < 15; ++i) {
        state->slots[i].state = HUD_BTN_STATE_HIDDEN;
    }
    return 0;
}

int hud_command_bar_set_slot(HudCommandState *state, int slot_idx,
                             int action_id, int icon_slp, char hotkey,
                             HudGamepadButton pad_btn, HudButtonState initial_state) {
    if (!state || slot_idx < 0 || slot_idx >= 15) {
        return -1;
    }
    state->slots[slot_idx].action_id = action_id;
    state->slots[slot_idx].icon_slp_id = icon_slp;
    state->slots[slot_idx].hotkey_char = hotkey;
    state->slots[slot_idx].pad_button = pad_btn;
    state->slots[slot_idx].state = initial_state;
    return 0;
}

int hud_command_bar_hit_test(const HudCommandLayout *layout,
                             const HudCommandState *state,
                             int x, int y) {
    if (!layout || !state) {
        return -1;
    }
    for (int i = 0; i < 15; ++i) {
        if (state->slots[i].state == HUD_BTN_STATE_HIDDEN) {
            continue;
        }
        if (render_rect_contains_point(&layout->button_grid[i], x, y)) {
            return i;
        }
    }
    return -1;
}

int hud_unit_calc_hp_ratio(const HudUnitStatus *unit, int *out_percent, int *out_color_class) {
    if (!unit || !out_percent || !out_color_class || unit->max_hp <= 0) {
        return -1;
    }
    int cur = (unit->current_hp < 0) ? 0 : unit->current_hp;
    if (cur > unit->max_hp) {
        cur = unit->max_hp;
    }
    int pct = (cur * 100) / unit->max_hp;
    *out_percent = pct;

    if (pct < 25) {
        *out_color_class = 0; /* Red */
    } else if (pct <= 50) {
        *out_color_class = 1; /* Yellow */
    } else {
        *out_color_class = 2; /* Green */
    }
    return 0;
}

} /* extern "C" */
