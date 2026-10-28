#include "hud_resource_bar.h"
#include <stdio.h>
#include <string.h>

extern "C" {

static int clamp_resource(int val) {
    if (val < 0) return 0;
    if (val > 999999) return 999999;
    return val;
}

const char *hud_age_to_string(HudAge age) {
    switch (age) {
        case HUD_AGE_DARK:     return "Dark Age";
        case HUD_AGE_FEUDAL:   return "Feudal Age";
        case HUD_AGE_CASTLE:   return "Castle Age";
        case HUD_AGE_IMPERIAL: return "Imperial Age";
        default:               return "Unknown Age";
    }
}

int hud_resource_format_strings(const HudPlayerData *data, HudFormattedStrings *out_strings) {
    if (!data || !out_strings) {
        return -1;
    }

    snprintf(out_strings->wood_str, sizeof(out_strings->wood_str), "%d", clamp_resource(data->wood));
    snprintf(out_strings->food_str, sizeof(out_strings->food_str), "%d", clamp_resource(data->food));
    snprintf(out_strings->gold_str, sizeof(out_strings->gold_str), "%d", clamp_resource(data->gold));
    snprintf(out_strings->stone_str, sizeof(out_strings->stone_str), "%d", clamp_resource(data->stone));

    int pop_cur = (data->current_pop < 0) ? 0 : data->current_pop;
    int pop_max = (data->max_pop < 0) ? 0 : data->max_pop;
    snprintf(out_strings->pop_str, sizeof(out_strings->pop_str), "%d/%d", pop_cur, pop_max);

    snprintf(out_strings->age_str, sizeof(out_strings->age_str), "%s", hud_age_to_string(data->age));

    return 0;
}

HudResourceButtonId hud_resource_bar_hit_test(const HudResourceLayout *layout, int x, int y) {
    if (!layout) {
        return HUD_BTN_NONE;
    }

    if (render_rect_contains_point(&layout->menu_btn, x, y)) {
        return HUD_BTN_MENU;
    }
    if (render_rect_contains_point(&layout->diplomacy_btn, x, y)) {
        return HUD_BTN_DIPLOMACY;
    }
    if (render_rect_contains_point(&layout->chat_btn, x, y)) {
        return HUD_BTN_CHAT;
    }

    return HUD_BTN_NONE;
}

} /* extern "C" */
