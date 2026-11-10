#ifndef HUD_PANEL_LAYOUT_H
#define HUD_PANEL_LAYOUT_H

#include "render_clip_math.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HudPreset {
    HUD_PRESET_PC_640x480 = 0,
    HUD_PRESET_PC_800x600 = 1,
    HUD_PRESET_PS2_640x448 = 2,
    HUD_PRESET_PS2_640x512 = 3,
    HUD_PRESET_CUSTOM = 4
} HudPreset;

typedef struct HudResourceLayout {
    RenderRect bar_rect;       /* Full top bar bounds */
    RenderRect wood_rect;      /* Wood counter box */
    RenderRect food_rect;      /* Food counter box */
    RenderRect gold_rect;      /* Gold counter box */
    RenderRect stone_rect;     /* Stone counter box */
    RenderRect pop_rect;       /* Population ratio box */
    RenderRect age_rect;       /* Current age badge box */
    RenderRect menu_btn;       /* Menu button */
    RenderRect diplomacy_btn;  /* Diplomacy button */
    RenderRect chat_btn;       /* Chat button */
} HudResourceLayout;

typedef struct HudCommandLayout {
    RenderRect panel_rect;     /* Full bottom panel bounds */
    RenderRect minimap_rect;   /* Minimap / radar viewport */
    RenderRect status_rect;    /* Selected entity portrait & stats */
    RenderRect command_rect;   /* 3x5 Action / Command grid */
    RenderRect portrait_rect;  /* Portrait box within status */
    RenderRect hp_bar_rect;    /* HP gauge within status */
    RenderRect button_grid[15];/* 15 button slots: 3 rows x 5 cols */
} HudCommandLayout;

typedef struct HudLayoutConfig {
    HudPreset preset;
    int screen_width;
    int screen_height;
    HudResourceLayout resource_bar;
    HudCommandLayout command_panel;
} HudLayoutConfig;

/**
 * Initialize HUD layout configuration for given preset and screen resolution.
 *
 * @param cfg Output configuration to populate
 * @param preset Selected HUD preset
 * @param screen_w Screen width in pixels
 * @param screen_h Screen height in pixels
 * @return 0 on success, negative error code on failure
 */
int hud_layout_init(HudLayoutConfig *cfg, HudPreset preset, int screen_w, int screen_h);

#ifdef __cplusplus
}
#endif

#endif /* HUD_PANEL_LAYOUT_H */
