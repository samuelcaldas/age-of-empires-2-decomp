#include "render_clip_math.h"
#include <string.h>

extern "C" {

int render_rect_is_empty(const RenderRect *r) {
    if (!r) {
        return 1;
    }
    return (r->right <= r->left || r->bottom <= r->top) ? 1 : 0;
}

int render_rect_contains_point(const RenderRect *r, int x, int y) {
    if (!r || render_rect_is_empty(r)) {
        return 0;
    }
    return (x >= r->left && x < r->right && y >= r->top && y < r->bottom) ? 1 : 0;
}

int render_rect_intersects(const RenderRect *a, const RenderRect *b) {
    if (!a || !b || render_rect_is_empty(a) || render_rect_is_empty(b)) {
        return 0;
    }
    if (a->left >= b->right || a->right <= b->left) {
        return 0;
    }
    if (a->top >= b->bottom || a->bottom <= b->top) {
        return 0;
    }
    return 1;
}

int render_rect_intersect(const RenderRect *a, const RenderRect *b, RenderRect *out) {
    if (!a || !b || !out) {
        return 0;
    }
    int l = (a->left > b->left) ? a->left : b->left;
    int t = (a->top > b->top) ? a->top : b->top;
    int r = (a->right < b->right) ? a->right : b->right;
    int btm = (a->bottom < b->bottom) ? a->bottom : b->bottom;

    out->left = l;
    out->top = t;
    out->right = r;
    out->bottom = btm;

    return (l < r && t < btm) ? 1 : 0;
}

int render_rect_union(const RenderRect *a, const RenderRect *b, RenderRect *out) {
    if (!a || !b || !out) {
        return 0;
    }
    int a_empty = render_rect_is_empty(a);
    int b_empty = render_rect_is_empty(b);

    if (a_empty && b_empty) {
        out->left = 0;
        out->top = 0;
        out->right = 0;
        out->bottom = 0;
        return 0;
    }
    if (a_empty) {
        *out = *b;
        return 1;
    }
    if (b_empty) {
        *out = *a;
        return 1;
    }

    out->left = (a->left < b->left) ? a->left : b->left;
    out->top = (a->top < b->top) ? a->top : b->top;
    out->right = (a->right > b->right) ? a->right : b->right;
    out->bottom = (a->bottom > b->bottom) ? a->bottom : b->bottom;

    return 1;
}

int render_clip_to_bounds(RenderRect *r, int width, int height) {
    if (!r || width <= 0 || height <= 0) {
        return 0;
    }
    if (r->left >= width || r->right <= 0 || r->top >= height || r->bottom <= 0) {
        return 0;
    }

    if (r->left < 0) {
        r->left = 0;
    }
    if (r->top < 0) {
        r->top = 0;
    }
    if (r->right > width) {
        r->right = width;
    }
    if (r->bottom > height) {
        r->bottom = height;
    }

    return (r->left < r->right && r->top < r->bottom) ? 1 : 0;
}

int render_clip_sprite(int spr_x, int spr_y, int spr_w, int spr_h,
                       const RenderRect *viewport,
                       RenderSpriteClip *out_clip) {
    if (!out_clip) {
        return 0;
    }
    memset(out_clip, 0, sizeof(*out_clip));

    if (spr_w <= 0 || spr_h <= 0 || !viewport || render_rect_is_empty(viewport)) {
        return 0;
    }

    RenderRect spr;
    spr.left = spr_x;
    spr.top = spr_y;
    spr.right = spr_x + spr_w;
    spr.bottom = spr_y + spr_h;

    RenderRect clipped;
    if (!render_rect_intersect(&spr, viewport, &clipped)) {
        return 0;
    }

    out_clip->dst_x = clipped.left;
    out_clip->dst_y = clipped.top;
    out_clip->src_x = clipped.left - spr_x;
    out_clip->src_y = clipped.top - spr_y;
    out_clip->visible_w = clipped.right - clipped.left;
    out_clip->visible_h = clipped.bottom - clipped.top;
    out_clip->is_visible = 1;

    return 1;
}

} /* extern "C" */
