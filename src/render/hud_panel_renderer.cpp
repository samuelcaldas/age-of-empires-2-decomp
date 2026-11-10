#include "hud_panel_renderer.h"
#include <string.h>

extern "C" {

int hud_render_fill_rect(HudDrawSurface *surf, const RenderRect *rect, unsigned char color) {
    if (!surf || !surf->buffer || !rect || surf->width <= 0 || surf->height <= 0 || surf->stride <= 0) {
        return -1;
    }

    RenderRect vp;
    vp.left = 0;
    vp.top = 0;
    vp.right = surf->width;
    vp.bottom = surf->height;

    RenderRect clipped;
    if (!render_rect_intersect(rect, &vp, &clipped)) {
        return 0; /* Clipped out completely */
    }

    int span = clipped.right - clipped.left;
    for (int y = clipped.top; y < clipped.bottom; ++y) {
        memset(surf->buffer + (y * surf->stride) + clipped.left, color, (size_t)span);
    }

    return 0;
}

int hud_render_outline_rect(HudDrawSurface *surf, const RenderRect *rect, unsigned char color) {
    if (!surf || !surf->buffer || !rect || surf->width <= 0 || surf->height <= 0 || surf->stride <= 0) {
        return -1;
    }

    if (render_rect_is_empty(rect)) {
        return 0;
    }

    int x0 = rect->left;
    int y0 = rect->top;
    int x1 = rect->right - 1;
    int y1 = rect->bottom - 1;

    /* Draw horizontal borders */
    for (int x = x0; x <= x1; ++x) {
        if (x >= 0 && x < surf->width) {
            if (y0 >= 0 && y0 < surf->height) {
                surf->buffer[y0 * surf->stride + x] = color;
            }
            if (y1 >= 0 && y1 < surf->height && y1 != y0) {
                surf->buffer[y1 * surf->stride + x] = color;
            }
        }
    }

    /* Draw vertical borders */
    for (int y = y0; y <= y1; ++y) {
        if (y >= 0 && y < surf->height) {
            if (x0 >= 0 && x0 < surf->width) {
                surf->buffer[y * surf->stride + x0] = color;
            }
            if (x1 >= 0 && x1 < surf->width && x1 != x0) {
                surf->buffer[y * surf->stride + x1] = color;
            }
        }
    }

    return 0;
}

int hud_render_button_frame(HudDrawSurface *surf, const RenderRect *rect,
                            HudButtonState state, const HudPaletteTheme *theme) {
    if (!surf || !rect || !theme || surf->width <= 0 || surf->height <= 0) {
        return -1;
    }

    if (state == HUD_BTN_STATE_HIDDEN) {
        return 0;
    }

    if (state == HUD_BTN_STATE_DISABLED) {
        hud_render_fill_rect(surf, rect, theme->fill_disabled);
        return 0;
    }

    unsigned char top_left_col = (state == HUD_BTN_STATE_PRESSED) ? theme->border_dark : theme->border_light;
    unsigned char btm_right_col = (state == HUD_BTN_STATE_PRESSED) ? theme->border_light : theme->border_dark;
    unsigned char fill_col = (state == HUD_BTN_STATE_PRESSED) ? theme->fill_pressed : theme->fill_normal;

    /* Fill interior if size allows */
    RenderRect interior;
    interior.left = rect->left + 1;
    interior.top = rect->top + 1;
    interior.right = rect->right - 1;
    interior.bottom = rect->bottom - 1;
    if (!render_rect_is_empty(&interior)) {
        hud_render_fill_rect(surf, &interior, fill_col);
    }

    int x0 = rect->left;
    int y0 = rect->top;
    int x1 = rect->right - 1;
    int y1 = rect->bottom - 1;

    /* Top and Left borders */
    for (int x = x0; x <= x1; ++x) {
        if (x >= 0 && x < surf->width && y0 >= 0 && y0 < surf->height) {
            surf->buffer[y0 * surf->stride + x] = top_left_col;
        }
    }
    for (int y = y0; y <= y1; ++y) {
        if (y >= 0 && y < surf->height && x0 >= 0 && x0 < surf->width) {
            surf->buffer[y * surf->stride + x0] = top_left_col;
        }
    }

    /* Bottom and Right borders */
    for (int x = x0; x <= x1; ++x) {
        if (x >= 0 && x < surf->width && y1 >= 0 && y1 < surf->height) {
            surf->buffer[y1 * surf->stride + x] = btm_right_col;
        }
    }
    for (int y = y0; y <= y1; ++y) {
        if (y >= 0 && y < surf->height && x1 >= 0 && x1 < surf->width) {
            surf->buffer[y * surf->stride + x1] = btm_right_col;
        }
    }

    return 0;
}

int hud_render_hp_bar(HudDrawSurface *surf, const RenderRect *rect,
                      int hp_percent, int color_class, const HudPaletteTheme *theme) {
    if (!surf || !rect || !theme || surf->width <= 0 || surf->height <= 0) {
        return -1;
    }

    int pct = (hp_percent < 0) ? 0 : (hp_percent > 100 ? 100 : hp_percent);
    int bar_w = rect->right - rect->left;
    if (bar_w <= 0) {
        return 0;
    }

    /* Fill background first */
    hud_render_fill_rect(surf, rect, theme->hp_bg);

    int fill_w = (bar_w * pct) / 100;
    if (fill_w > 0) {
        unsigned char fill_col = (color_class == 0) ? theme->hp_red :
                                 ((color_class == 1) ? theme->hp_yellow : theme->hp_green);
        RenderRect fill_r;
        fill_r.left = rect->left;
        fill_r.top = rect->top;
        fill_r.right = rect->left + fill_w;
        fill_r.bottom = rect->bottom;
        hud_render_fill_rect(surf, &fill_r, fill_col);
    }

    return 0;
}

} /* extern "C" */
