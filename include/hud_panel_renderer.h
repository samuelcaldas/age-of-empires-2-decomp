#ifndef HUD_PANEL_RENDERER_H
#define HUD_PANEL_RENDERER_H

#include "hud_panel_layout.h"
#include "hud_command_bar.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HudDrawSurface {
    unsigned char *buffer;
    int width;
    int height;
    int stride;
} HudDrawSurface;

typedef struct HudPaletteTheme {
    unsigned char border_light;
    unsigned char border_dark;
    unsigned char fill_normal;
    unsigned char fill_pressed;
    unsigned char fill_disabled;
    unsigned char hp_green;
    unsigned char hp_yellow;
    unsigned char hp_red;
    unsigned char hp_bg;
} HudPaletteTheme;

/**
 * Fill a solid rectangle within surface boundaries.
 */
int hud_render_fill_rect(HudDrawSurface *surf, const RenderRect *rect, unsigned char color);

/**
 * Draw a 1-pixel outline rectangle within surface boundaries.
 */
int hud_render_outline_rect(HudDrawSurface *surf, const RenderRect *rect, unsigned char color);

/**
 * Draw a button frame with beveled edges corresponding to its state (normal, pressed, disabled).
 */
int hud_render_button_frame(HudDrawSurface *surf, const RenderRect *rect,
                            HudButtonState state, const HudPaletteTheme *theme);

/**
 * Render an entity HP bar into surf with color corresponding to remaining health percentage.
 */
int hud_render_hp_bar(HudDrawSurface *surf, const RenderRect *rect,
                      int hp_percent, int color_class, const HudPaletteTheme *theme);

#ifdef __cplusplus
}
#endif

#endif /* HUD_PANEL_RENDERER_H */
