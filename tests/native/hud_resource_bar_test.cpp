#include "hud_resource_bar.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

static int test_standard_formatting(void) {
    HudPlayerData data;
    data.wood = 200;
    data.food = 150;
    data.gold = 100;
    data.stone = 50;
    data.current_pop = 15;
    data.max_pop = 25;
    data.age = HUD_AGE_FEUDAL;

    HudFormattedStrings out;
    int ret = hud_resource_format_strings(&data, &out);
    assert(ret == 0);

    assert(strcmp(out.wood_str, "200") == 0);
    assert(strcmp(out.food_str, "150") == 0);
    assert(strcmp(out.gold_str, "100") == 0);
    assert(strcmp(out.stone_str, "50") == 0);
    assert(strcmp(out.pop_str, "15/25") == 0);
    assert(strcmp(out.age_str, "Feudal Age") == 0);
    return 0;
}

static int test_boundary_formatting(void) {
    HudPlayerData data;
    data.wood = -50; /* clamped to 0 */
    data.food = 1000000; /* clamped to 999999 */
    data.gold = 0;
    data.stone = 999999;
    data.current_pop = 200;
    data.max_pop = 200;
    data.age = HUD_AGE_IMPERIAL;

    HudFormattedStrings out;
    int ret = hud_resource_format_strings(&data, &out);
    assert(ret == 0);

    assert(strcmp(out.wood_str, "0") == 0);
    assert(strcmp(out.food_str, "999999") == 0);
    assert(strcmp(out.gold_str, "0") == 0);
    assert(strcmp(out.stone_str, "999999") == 0);
    assert(strcmp(out.pop_str, "200/200") == 0);
    assert(strcmp(out.age_str, "Imperial Age") == 0);
    return 0;
}

static int test_hit_test_buttons(void) {
    HudLayoutConfig cfg;
    hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 640, 480);

    /* Click inside menu button */
    int mx = (cfg.resource_bar.menu_btn.left + cfg.resource_bar.menu_btn.right) / 2;
    int my = (cfg.resource_bar.menu_btn.top + cfg.resource_bar.menu_btn.bottom) / 2;
    assert(hud_resource_bar_hit_test(&cfg.resource_bar, mx, my) == HUD_BTN_MENU);

    /* Click inside diplomacy button */
    int dx = (cfg.resource_bar.diplomacy_btn.left + cfg.resource_bar.diplomacy_btn.right) / 2;
    int dy = (cfg.resource_bar.diplomacy_btn.top + cfg.resource_bar.diplomacy_btn.bottom) / 2;
    assert(hud_resource_bar_hit_test(&cfg.resource_bar, dx, dy) == HUD_BTN_DIPLOMACY);

    /* Click inside chat button */
    int cx = (cfg.resource_bar.chat_btn.left + cfg.resource_bar.chat_btn.right) / 2;
    int cy = (cfg.resource_bar.chat_btn.top + cfg.resource_bar.chat_btn.bottom) / 2;
    assert(hud_resource_bar_hit_test(&cfg.resource_bar, cx, cy) == HUD_BTN_CHAT);
    return 0;
}

static int test_hit_test_outside(void) {
    HudLayoutConfig cfg;
    hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 640, 480);

    /* Below the bar */
    assert(hud_resource_bar_hit_test(&cfg.resource_bar, 300, 50) == HUD_BTN_NONE);
    /* In the wood counter area */
    assert(hud_resource_bar_hit_test(&cfg.resource_bar, 20, 10) == HUD_BTN_NONE);
    /* Outside screen */
    assert(hud_resource_bar_hit_test(&cfg.resource_bar, -5, -5) == HUD_BTN_NONE);
    return 0;
}

static int test_age_strings(void) {
    assert(strcmp(hud_age_to_string(HUD_AGE_DARK), "Dark Age") == 0);
    assert(strcmp(hud_age_to_string(HUD_AGE_FEUDAL), "Feudal Age") == 0);
    assert(strcmp(hud_age_to_string(HUD_AGE_CASTLE), "Castle Age") == 0);
    assert(strcmp(hud_age_to_string(HUD_AGE_IMPERIAL), "Imperial Age") == 0);
    assert(strcmp(hud_age_to_string((HudAge)99), "Unknown Age") == 0);
    return 0;
}

static int test_null_pointers(void) {
    HudFormattedStrings out;
    HudPlayerData data;
    assert(hud_resource_format_strings(NULL, &out) != 0);
    assert(hud_resource_format_strings(&data, NULL) != 0);
    assert(hud_resource_bar_hit_test(NULL, 10, 10) == HUD_BTN_NONE);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_standard_formatting();
        case 1: return test_boundary_formatting();
        case 2: return test_hit_test_buttons();
        case 3: return test_hit_test_outside();
        case 4: return test_age_strings();
        case 5: return test_null_pointers();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
