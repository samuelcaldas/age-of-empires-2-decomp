#include "hud_panel_layout.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

static int test_pc_640x480(void) {
    HudLayoutConfig cfg;
    int ret = hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 640, 480);
    assert(ret == 0);
    assert(cfg.preset == HUD_PRESET_PC_640x480);
    assert(cfg.screen_width == 640);
    assert(cfg.screen_height == 480);

    /* Top resource bar: height 22 */
    assert(cfg.resource_bar.bar_rect.left == 0);
    assert(cfg.resource_bar.bar_rect.top == 0);
    assert(cfg.resource_bar.bar_rect.right == 640);
    assert(cfg.resource_bar.bar_rect.bottom == 22);

    /* Resource counter boxes are sequentially ordered */
    assert(cfg.resource_bar.wood_rect.left < cfg.resource_bar.food_rect.left);
    assert(cfg.resource_bar.food_rect.left < cfg.resource_bar.gold_rect.left);
    assert(cfg.resource_bar.gold_rect.left < cfg.resource_bar.stone_rect.left);

    /* Bottom command panel: y=360 to 480, height 120 */
    assert(cfg.command_panel.panel_rect.left == 0);
    assert(cfg.command_panel.panel_rect.top == 360);
    assert(cfg.command_panel.panel_rect.right == 640);
    assert(cfg.command_panel.panel_rect.bottom == 480);

    /* Three main horizontal partitions: minimap, status, command */
    assert(cfg.command_panel.minimap_rect.right <= cfg.command_panel.status_rect.left);
    assert(cfg.command_panel.status_rect.right <= cfg.command_panel.command_rect.left);

    /* 15 button slots: 3 rows x 5 columns */
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 5; ++c) {
            int idx = r * 5 + c;
            assert(cfg.command_panel.button_grid[idx].right > cfg.command_panel.button_grid[idx].left);
            assert(cfg.command_panel.button_grid[idx].bottom > cfg.command_panel.button_grid[idx].top);
            /* Row order checks */
            if (c > 0) {
                assert(cfg.command_panel.button_grid[idx].left >= cfg.command_panel.button_grid[idx - 1].right);
            }
            if (r > 0) {
                assert(cfg.command_panel.button_grid[idx].top >= cfg.command_panel.button_grid[(r - 1) * 5 + c].bottom);
            }
        }
    }
    return 0;
}

static int test_pc_800x600(void) {
    HudLayoutConfig cfg;
    int ret = hud_layout_init(&cfg, HUD_PRESET_PC_800x600, 800, 600);
    assert(ret == 0);
    assert(cfg.preset == HUD_PRESET_PC_800x600);
    assert(cfg.screen_width == 800);
    assert(cfg.screen_height == 600);

    assert(cfg.resource_bar.bar_rect.right == 800);
    assert(cfg.resource_bar.bar_rect.bottom == 24);

    assert(cfg.command_panel.panel_rect.left == 0);
    assert(cfg.command_panel.panel_rect.top == 480);
    assert(cfg.command_panel.panel_rect.right == 800);
    assert(cfg.command_panel.panel_rect.bottom == 600);
    return 0;
}

static int test_ps2_640x448(void) {
    HudLayoutConfig cfg;
    int ret = hud_layout_init(&cfg, HUD_PRESET_PS2_640x448, 640, 448);
    assert(ret == 0);
    assert(cfg.preset == HUD_PRESET_PS2_640x448);
    assert(cfg.screen_width == 640);
    assert(cfg.screen_height == 448);

    /* PS2 bottom panel spans up to 448 */
    assert(cfg.command_panel.panel_rect.bottom == 448);
    assert(cfg.command_panel.panel_rect.top == 448 - 120);
    return 0;
}

static int test_ps2_640x512(void) {
    HudLayoutConfig cfg;
    int ret = hud_layout_init(&cfg, HUD_PRESET_PS2_640x512, 640, 512);
    assert(ret == 0);
    assert(cfg.preset == HUD_PRESET_PS2_640x512);
    assert(cfg.screen_width == 640);
    assert(cfg.screen_height == 512);

    assert(cfg.command_panel.panel_rect.bottom == 512);
    assert(cfg.command_panel.panel_rect.top == 512 - 120);
    return 0;
}

static int test_custom_scaling(void) {
    HudLayoutConfig cfg;
    int ret = hud_layout_init(&cfg, HUD_PRESET_CUSTOM, 1024, 768);
    assert(ret == 0);
    assert(cfg.preset == HUD_PRESET_CUSTOM);
    assert(cfg.screen_width == 1024);
    assert(cfg.screen_height == 768);

    assert(cfg.resource_bar.bar_rect.right == 1024);
    assert(cfg.command_panel.panel_rect.right == 1024);
    assert(cfg.command_panel.panel_rect.bottom == 768);
    return 0;
}

static int test_invalid_parameters(void) {
    HudLayoutConfig cfg;
    assert(hud_layout_init(NULL, HUD_PRESET_PC_640x480, 640, 480) != 0);
    assert(hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 0, 480) != 0);
    assert(hud_layout_init(&cfg, HUD_PRESET_PC_640x480, 640, 0) != 0);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_pc_640x480();
        case 1: return test_pc_800x600();
        case 2: return test_ps2_640x448();
        case 3: return test_ps2_640x512();
        case 4: return test_custom_scaling();
        case 5: return test_invalid_parameters();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
