#ifndef HUD_RESOURCE_BAR_H
#define HUD_RESOURCE_BAR_H

#include "hud_panel_layout.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HudResourceButtonId {
    HUD_BTN_NONE = 0,
    HUD_BTN_MENU = 1,
    HUD_BTN_DIPLOMACY = 2,
    HUD_BTN_CHAT = 3
} HudResourceButtonId;

typedef enum HudAge {
    HUD_AGE_DARK = 0,
    HUD_AGE_FEUDAL = 1,
    HUD_AGE_CASTLE = 2,
    HUD_AGE_IMPERIAL = 3
} HudAge;

typedef struct HudPlayerData {
    int wood;
    int food;
    int gold;
    int stone;
    int current_pop;
    int max_pop;
    HudAge age;
} HudPlayerData;

typedef struct HudFormattedStrings {
    char wood_str[16];
    char food_str[16];
    char gold_str[16];
    char stone_str[16];
    char pop_str[24];
    char age_str[32];
} HudFormattedStrings;

/**
 * Format numeric player data into HUD display strings.
 * Clamps resources at 0..999999 and handles population cap.
 *
 * @param data Input player data
 * @param out_strings Output formatted strings
 * @return 0 on success, negative error code on failure
 */
int hud_resource_format_strings(const HudPlayerData *data, HudFormattedStrings *out_strings);

/**
 * Hit test a screen coordinate (x, y) against the top resource bar buttons.
 *
 * @param layout Top bar layout geometry
 * @param x Screen X coordinate
 * @param y Screen Y coordinate
 * @return Button ID if hit, or HUD_BTN_NONE
 */
HudResourceButtonId hud_resource_bar_hit_test(const HudResourceLayout *layout, int x, int y);

/**
 * Returns canonical age string name for a given HudAge enum.
 */
const char *hud_age_to_string(HudAge age);

#ifdef __cplusplus
}
#endif

#endif /* HUD_RESOURCE_BAR_H */
