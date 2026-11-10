#ifndef HUD_COMMAND_BAR_H
#define HUD_COMMAND_BAR_H

#include "hud_panel_layout.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HudButtonState {
    HUD_BTN_STATE_HIDDEN = 0,
    HUD_BTN_STATE_NORMAL = 1,
    HUD_BTN_STATE_HOVER = 2,
    HUD_BTN_STATE_PRESSED = 3,
    HUD_BTN_STATE_DISABLED = 4
} HudButtonState;

typedef enum HudGamepadButton {
    HUD_PAD_NONE = 0,
    HUD_PAD_CROSS = 1,
    HUD_PAD_CIRCLE = 2,
    HUD_PAD_SQUARE = 3,
    HUD_PAD_TRIANGLE = 4,
    HUD_PAD_DPAD_UP = 5,
    HUD_PAD_DPAD_DOWN = 6,
    HUD_PAD_DPAD_LEFT = 7,
    HUD_PAD_DPAD_RIGHT = 8
} HudGamepadButton;

typedef struct HudActionSlot {
    int action_id;              /* Action/command identifier */
    int icon_slp_id;            /* SLP asset ID for button icon */
    char hotkey_char;           /* PC keyboard hotkey (e.g. 'A', 'S') */
    HudGamepadButton pad_button;/* PS2 DualShock 2 mapped prompt */
    HudButtonState state;       /* Current button visual state */
} HudActionSlot;

typedef struct HudUnitStatus {
    int unit_id;
    int portrait_slp_id;
    int current_hp;
    int max_hp;
    int attack;
    int armor_melee;
    int armor_pierce;
    int range;
    int kills;
} HudUnitStatus;

typedef struct HudCommandState {
    HudActionSlot slots[15];   /* 15 action slots */
    HudUnitStatus selected_unit;
    int active_slot_index;     /* -1 if none, 0..14 */
} HudCommandState;

/**
 * Initialize a command bar state with default slots and neutral status.
 */
int hud_command_bar_init(HudCommandState *state);

/**
 * Set an action slot's configuration.
 */
int hud_command_bar_set_slot(HudCommandState *state, int slot_idx,
                             int action_id, int icon_slp, char hotkey,
                             HudGamepadButton pad_btn, HudButtonState initial_state);

/**
 * Hit test a screen coordinate (x, y) against the 15 button slots.
 * Returns slot index (0..14) if hit and visible, or -1 if none.
 */
int hud_command_bar_hit_test(const HudCommandLayout *layout,
                             const HudCommandState *state,
                             int x, int y);

/**
 * Calculate HP percentage (0..100) and color classification:
 * 0 = Red (< 25%), 1 = Yellow (25%..50%), 2 = Green (> 50%).
 */
int hud_unit_calc_hp_ratio(const HudUnitStatus *unit, int *out_percent, int *out_color_class);

#ifdef __cplusplus
}
#endif

#endif /* HUD_COMMAND_BAR_H */
