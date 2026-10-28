#include "hud_panel_layout.h"
#include <string.h>

extern "C" {

int hud_layout_init(HudLayoutConfig *cfg, HudPreset preset, int screen_w, int screen_h) {
    if (!cfg || screen_w <= 0 || screen_h <= 0) {
        return -1;
    }

    memset(cfg, 0, sizeof(*cfg));
    cfg->preset = preset;
    cfg->screen_width = screen_w;
    cfg->screen_height = screen_h;

    /* 1. Top Resource Bar */
    int top_h = (preset == HUD_PRESET_PC_800x600 || screen_w >= 800) ? 24 : 22;
    cfg->resource_bar.bar_rect.left = 0;
    cfg->resource_bar.bar_rect.top = 0;
    cfg->resource_bar.bar_rect.right = screen_w;
    cfg->resource_bar.bar_rect.bottom = top_h;

    int item_w = (screen_w >= 800) ? 75 : 60;
    int cur_x = 10;
    int margin_y = 2;

    /* Wood */
    cfg->resource_bar.wood_rect.left = cur_x;
    cfg->resource_bar.wood_rect.top = margin_y;
    cfg->resource_bar.wood_rect.right = cur_x + item_w;
    cfg->resource_bar.wood_rect.bottom = top_h - margin_y;
    cur_x += item_w + 6;

    /* Food */
    cfg->resource_bar.food_rect.left = cur_x;
    cfg->resource_bar.food_rect.top = margin_y;
    cfg->resource_bar.food_rect.right = cur_x + item_w;
    cfg->resource_bar.food_rect.bottom = top_h - margin_y;
    cur_x += item_w + 6;

    /* Gold */
    cfg->resource_bar.gold_rect.left = cur_x;
    cfg->resource_bar.gold_rect.top = margin_y;
    cfg->resource_bar.gold_rect.right = cur_x + item_w;
    cfg->resource_bar.gold_rect.bottom = top_h - margin_y;
    cur_x += item_w + 6;

    /* Stone */
    cfg->resource_bar.stone_rect.left = cur_x;
    cfg->resource_bar.stone_rect.top = margin_y;
    cfg->resource_bar.stone_rect.right = cur_x + item_w;
    cfg->resource_bar.stone_rect.bottom = top_h - margin_y;
    cur_x += item_w + 6;

    /* Population */
    cfg->resource_bar.pop_rect.left = cur_x;
    cfg->resource_bar.pop_rect.top = margin_y;
    cfg->resource_bar.pop_rect.right = cur_x + item_w;
    cfg->resource_bar.pop_rect.bottom = top_h - margin_y;
    cur_x += item_w + 6;

    /* Age */
    cfg->resource_bar.age_rect.left = cur_x;
    cfg->resource_bar.age_rect.top = margin_y;
    cfg->resource_bar.age_rect.right = cur_x + item_w + 20;
    cfg->resource_bar.age_rect.bottom = top_h - margin_y;

    /* Top right buttons */
    int btn_w = (screen_w >= 800) ? 55 : 45;
    int r_x = screen_w - 5;

    cfg->resource_bar.chat_btn.right = r_x;
    cfg->resource_bar.chat_btn.left = r_x - btn_w;
    cfg->resource_bar.chat_btn.top = margin_y;
    cfg->resource_bar.chat_btn.bottom = top_h - margin_y;
    r_x -= (btn_w + 4);

    cfg->resource_bar.diplomacy_btn.right = r_x;
    cfg->resource_bar.diplomacy_btn.left = r_x - btn_w;
    cfg->resource_bar.diplomacy_btn.top = margin_y;
    cfg->resource_bar.diplomacy_btn.bottom = top_h - margin_y;
    r_x -= (btn_w + 4);

    cfg->resource_bar.menu_btn.right = r_x;
    cfg->resource_bar.menu_btn.left = r_x - btn_w;
    cfg->resource_bar.menu_btn.top = margin_y;
    cfg->resource_bar.menu_btn.bottom = top_h - margin_y;

    /* 2. Bottom Command & Status Panel */
    int panel_h = 120;
    int panel_y0 = screen_h - panel_h;

    cfg->command_panel.panel_rect.left = 0;
    cfg->command_panel.panel_rect.top = panel_y0;
    cfg->command_panel.panel_rect.right = screen_w;
    cfg->command_panel.panel_rect.bottom = screen_h;

    int minimap_w = (screen_w >= 800) ? 240 : 200;
    int cmd_w = (screen_w >= 800) ? 260 : 200;
    int cmd_x0 = screen_w - cmd_w;

    /* Minimap section */
    cfg->command_panel.minimap_rect.left = 0;
    cfg->command_panel.minimap_rect.top = panel_y0;
    cfg->command_panel.minimap_rect.right = minimap_w;
    cfg->command_panel.minimap_rect.bottom = screen_h;

    /* Command section */
    cfg->command_panel.command_rect.left = cmd_x0;
    cfg->command_panel.command_rect.top = panel_y0;
    cfg->command_panel.command_rect.right = screen_w;
    cfg->command_panel.command_rect.bottom = screen_h;

    /* Status section (in between) */
    cfg->command_panel.status_rect.left = minimap_w;
    cfg->command_panel.status_rect.top = panel_y0;
    cfg->command_panel.status_rect.right = cmd_x0;
    cfg->command_panel.status_rect.bottom = screen_h;

    /* Portrait and HP bar inside status */
    cfg->command_panel.portrait_rect.left = minimap_w + 10;
    cfg->command_panel.portrait_rect.top = panel_y0 + 12;
    cfg->command_panel.portrait_rect.right = minimap_w + 10 + 48;
    cfg->command_panel.portrait_rect.bottom = panel_y0 + 12 + 48;

    cfg->command_panel.hp_bar_rect.left = minimap_w + 10;
    cfg->command_panel.hp_bar_rect.top = panel_y0 + 66;
    cfg->command_panel.hp_bar_rect.right = minimap_w + 10 + 64;
    cfg->command_panel.hp_bar_rect.bottom = panel_y0 + 74;

    /* 3x5 Command Button Grid */
    int pad_x = 6;
    int pad_y = 6;
    int spacing = 3;
    int avail_w = cmd_w - (pad_x * 2);
    int avail_h = panel_h - (pad_y * 2);
    int bw = (avail_w - (spacing * 4)) / 5;
    int bh = (avail_h - (spacing * 2)) / 3;

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 5; ++c) {
            int idx = r * 5 + c;
            int bx = cmd_x0 + pad_x + c * (bw + spacing);
            int by = panel_y0 + pad_y + r * (bh + spacing);
            cfg->command_panel.button_grid[idx].left = bx;
            cfg->command_panel.button_grid[idx].top = by;
            cfg->command_panel.button_grid[idx].right = bx + bw;
            cfg->command_panel.button_grid[idx].bottom = by + bh;
        }
    }

    return 0;
}

} /* extern "C" */
