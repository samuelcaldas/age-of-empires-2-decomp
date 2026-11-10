#include "hud_panel_renderer.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

static HudPaletteTheme get_test_theme(void) {
    HudPaletteTheme t;
    t.border_light = 0x10;
    t.border_dark = 0x20;
    t.fill_normal = 0x30;
    t.fill_pressed = 0x40;
    t.fill_disabled = 0x50;
    t.hp_green = 0xAA;
    t.hp_yellow = 0xBB;
    t.hp_red = 0xCC;
    t.hp_bg = 0x11;
    return t;
}

static int test_fill_rect_clipping(void) {
    unsigned char buffer[10 * 10];
    memset(buffer, 0, sizeof(buffer));
    HudDrawSurface surf = { buffer, 10, 10, 10 };

    /* Rect: (-2, -2, 5, 5) -> clipped to (0, 0, 5, 5) */
    RenderRect r = { -2, -2, 5, 5 };
    int ret = hud_render_fill_rect(&surf, &r, 0xFF);
    assert(ret == 0);

    /* (0, 0) through (4, 4) should be 0xFF */
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            assert(buffer[y * 10 + x] == 0xFF);
        }
        /* x=5..9 should be 0 */
        assert(buffer[y * 10 + 5] == 0);
    }
    /* y=5..9 should be 0 */
    assert(buffer[5 * 10 + 0] == 0);
    return 0;
}

static int test_outline_rect(void) {
    unsigned char buffer[8 * 8];
    memset(buffer, 0, sizeof(buffer));
    HudDrawSurface surf = { buffer, 8, 8, 8 };

    RenderRect r = { 1, 1, 6, 6 }; /* 5x5 rect */
    int ret = hud_render_outline_rect(&surf, &r, 0xEE);
    assert(ret == 0);

    /* Check top edge (y=1, x=1..5) */
    for (int x = 1; x < 6; ++x) assert(buffer[1 * 8 + x] == 0xEE);
    /* Check bottom edge (y=5, x=1..5) */
    for (int x = 1; x < 6; ++x) assert(buffer[5 * 8 + x] == 0xEE);
    /* Check left edge (x=1, y=1..5) */
    for (int y = 1; y < 6; ++y) assert(buffer[y * 8 + 1] == 0xEE);
    /* Check right edge (x=5, y=1..5) */
    for (int y = 1; y < 6; ++y) assert(buffer[y * 8 + 5] == 0xEE);

    /* Center (x=2, y=2) should be 0 (untouched) */
    assert(buffer[2 * 8 + 2] == 0);
    return 0;
}

static int test_button_bevels(void) {
    unsigned char buffer[6 * 6];
    HudDrawSurface surf = { buffer, 6, 6, 6 };
    HudPaletteTheme theme = get_test_theme();
    RenderRect r = { 0, 0, 6, 6 };

    /* NORMAL state */
    memset(buffer, 0, sizeof(buffer));
    int ret = hud_render_button_frame(&surf, &r, HUD_BTN_STATE_NORMAL, &theme);
    assert(ret == 0);
    /* Top-left: border_light */
    assert(buffer[0 * 6 + 0] == theme.border_light);
    assert(buffer[0 * 6 + 4] == theme.border_light);
    /* Bottom-right: border_dark */
    assert(buffer[5 * 6 + 5] == theme.border_dark);

    /* PRESSED state */
    memset(buffer, 0, sizeof(buffer));
    ret = hud_render_button_frame(&surf, &r, HUD_BTN_STATE_PRESSED, &theme);
    assert(ret == 0);
    /* Inverted: top-left has border_dark */
    assert(buffer[0 * 6 + 0] == theme.border_dark);
    /* Bottom-right has border_light */
    assert(buffer[5 * 6 + 5] == theme.border_light);
    return 0;
}

static int test_hp_bar_rendering(void) {
    unsigned char buffer[10 * 3];
    HudDrawSurface surf = { buffer, 10, 3, 10 };
    HudPaletteTheme theme = get_test_theme();
    RenderRect r = { 0, 0, 10, 3 };

    /* 40% health -> 4 pixels green/yellow, 6 pixels bg */
    memset(buffer, 0, sizeof(buffer));
    int ret = hud_render_hp_bar(&surf, &r, 40, 1 /* yellow */, &theme);
    assert(ret == 0);

    /* Inner fill at y=1: x=0..3 should be yellow, x=4..9 should be bg */
    assert(buffer[1 * 10 + 0] == theme.hp_yellow);
    assert(buffer[1 * 10 + 3] == theme.hp_yellow);
    assert(buffer[1 * 10 + 4] == theme.hp_bg);
    assert(buffer[1 * 10 + 9] == theme.hp_bg);
    return 0;
}

static int test_complete_rejection(void) {
    unsigned char buffer[4 * 4];
    memset(buffer, 0x55, sizeof(buffer));
    HudDrawSurface surf = { buffer, 4, 4, 4 };

    RenderRect r = { 10, 10, 20, 20 }; /* completely out */
    int ret = hud_render_fill_rect(&surf, &r, 0x99);
    assert(ret == 0);
    assert(buffer[0] == 0x55); /* untouched */
    return 0;
}

static int test_null_guards(void) {
    HudPaletteTheme theme = get_test_theme();
    RenderRect r = { 0, 0, 10, 10 };
    assert(hud_render_fill_rect(NULL, &r, 0) != 0);
    assert(hud_render_outline_rect(NULL, &r, 0) != 0);
    assert(hud_render_button_frame(NULL, &r, HUD_BTN_STATE_NORMAL, &theme) != 0);
    assert(hud_render_hp_bar(NULL, &r, 50, 1, &theme) != 0);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_fill_rect_clipping();
        case 1: return test_outline_rect();
        case 2: return test_button_bevels();
        case 3: return test_hp_bar_rendering();
        case 4: return test_complete_rejection();
        case 5: return test_null_guards();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
