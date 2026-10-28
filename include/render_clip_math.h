#ifndef RENDER_CLIP_MATH_H
#define RENDER_CLIP_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RenderRect {
    int left;
    int top;
    int right;  /* exclusive right */
    int bottom; /* exclusive bottom */
} RenderRect;

typedef struct RenderSpriteClip {
    int dst_x;
    int dst_y;
    int src_x;
    int src_y;
    int visible_w;
    int visible_h;
    int is_visible;
} RenderSpriteClip;

/**
 * Returns 1 if rect has zero or negative area, 0 otherwise.
 */
int render_rect_is_empty(const RenderRect *r);

/**
 * Returns 1 if point (x, y) is inside rect (left <= x < right, top <= y < bottom).
 */
int render_rect_contains_point(const RenderRect *r, int x, int y);

/**
 * Returns 1 if rects a and b overlap, 0 otherwise.
 */
int render_rect_intersects(const RenderRect *a, const RenderRect *b);

/**
 * Calculates intersection of a and b into out.
 * Returns 1 if intersection is non-empty, 0 if disjoint.
 */
int render_rect_intersect(const RenderRect *a, const RenderRect *b, RenderRect *out);

/**
 * Calculates bounding box union of a and b into out.
 * Returns 1 if valid result, 0 if both empty.
 */
int render_rect_union(const RenderRect *a, const RenderRect *b, RenderRect *out);

/**
 * Clips rect in-place against (0, 0, width, height) screen dimensions.
 * Returns 1 if resulting rect is non-empty, 0 if completely clipped out.
 */
int render_clip_to_bounds(RenderRect *r, int width, int height);

/**
 * Clips a sprite of size (spr_w, spr_h) placed at (spr_x, spr_y) against a viewport.
 * Populates out_clip with adjusted source/dest origins and dimensions.
 * Returns 1 if sprite is visible, 0 if completely clipped out.
 */
int render_clip_sprite(int spr_x, int spr_y, int spr_w, int spr_h,
                       const RenderRect *viewport,
                       RenderSpriteClip *out_clip);

#ifdef __cplusplus
}
#endif

#endif /* RENDER_CLIP_MATH_H */
