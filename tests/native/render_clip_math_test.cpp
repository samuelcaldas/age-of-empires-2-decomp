#include "render_clip_math.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

static int test_rect_empty_and_contains(void) {
    RenderRect r1 = { 10, 20, 10, 50 }; /* zero width -> empty */
    RenderRect r2 = { 10, 20, 5, 50 };  /* right < left -> empty */
    RenderRect r3 = { 10, 20, 40, 20 }; /* zero height -> empty */
    RenderRect r4 = { 10, 20, 40, 60 }; /* valid */

    assert(render_rect_is_empty(&r1) == 1);
    assert(render_rect_is_empty(&r2) == 1);
    assert(render_rect_is_empty(&r3) == 1);
    assert(render_rect_is_empty(&r4) == 0);

    /* Point containment: left <= x < right, top <= y < bottom */
    assert(render_rect_contains_point(&r4, 10, 20) == 1); /* top-left inclusive */
    assert(render_rect_contains_point(&r4, 39, 59) == 1); /* inside */
    assert(render_rect_contains_point(&r4, 40, 60) == 0); /* bottom-right exclusive */
    assert(render_rect_contains_point(&r4, 9, 20) == 0);
    assert(render_rect_contains_point(&r4, 10, 19) == 0);
    return 0;
}

static int test_rect_intersect(void) {
    RenderRect a = { 0, 0, 100, 100 };
    RenderRect b = { 50, 50, 150, 150 };
    RenderRect out;

    assert(render_rect_intersects(&a, &b) == 1);
    int ret = render_rect_intersect(&a, &b, &out);
    assert(ret == 1);
    assert(out.left == 50);
    assert(out.top == 50);
    assert(out.right == 100);
    assert(out.bottom == 100);

    /* Disjoint rects */
    RenderRect c = { 110, 0, 200, 100 };
    assert(render_rect_intersects(&a, &c) == 0);
    ret = render_rect_intersect(&a, &c, &out);
    assert(ret == 0);
    return 0;
}

static int test_rect_union(void) {
    RenderRect a = { 10, 20, 50, 60 };
    RenderRect b = { 30, 10, 80, 70 };
    RenderRect out;

    int ret = render_rect_union(&a, &b, &out);
    assert(ret == 1);
    assert(out.left == 10);
    assert(out.top == 10);
    assert(out.right == 80);
    assert(out.bottom == 70);

    /* Union with empty rect */
    RenderRect empty = { 0, 0, 0, 0 };
    ret = render_rect_union(&a, &empty, &out);
    assert(ret == 1);
    assert(out.left == 10);
    assert(out.top == 20);
    assert(out.right == 50);
    assert(out.bottom == 60);
    return 0;
}

static int test_clip_to_bounds(void) {
    /* rect spanning outside (800x600 screen): (-20, -10, 850, 620) */
    RenderRect r = { -20, -10, 850, 620 };
    int ret = render_clip_to_bounds(&r, 800, 600);
    assert(ret == 1);
    assert(r.left == 0);
    assert(r.top == 0);
    assert(r.right == 800);
    assert(r.bottom == 600);

    /* rect totally out to the right */
    RenderRect out = { 850, 10, 900, 50 };
    ret = render_clip_to_bounds(&out, 800, 600);
    assert(ret == 0);
    return 0;
}

static int test_clip_sprite_partial(void) {
    /* Viewport: 640x480 */
    RenderRect vp = { 0, 0, 640, 480 };

    /* Sprite 64x64 at (-10, -20) */
    RenderSpriteClip clip;
    int ret = render_clip_sprite(-10, -20, 64, 64, &vp, &clip);
    assert(ret == 1);
    assert(clip.is_visible == 1);
    assert(clip.dst_x == 0);
    assert(clip.dst_y == 0);
    assert(clip.src_x == 10);
    assert(clip.src_y == 20);
    assert(clip.visible_w == 54);
    assert(clip.visible_h == 44);

    /* Sprite 32x32 at (630, 470) -> partially exceeds right and bottom */
    ret = render_clip_sprite(630, 470, 32, 32, &vp, &clip);
    assert(ret == 1);
    assert(clip.is_visible == 1);
    assert(clip.dst_x == 630);
    assert(clip.dst_y == 470);
    assert(clip.src_x == 0);
    assert(clip.src_y == 0);
    assert(clip.visible_w == 10); /* 640 - 630 */
    assert(clip.visible_h == 10); /* 480 - 470 */
    return 0;
}

static int test_clip_sprite_invisible(void) {
    RenderRect vp = { 0, 0, 640, 480 };
    RenderSpriteClip clip;

    /* Sprite completely to the left: x = -100, w = 50 -> right = -50 <= 0 */
    int ret = render_clip_sprite(-100, 100, 50, 50, &vp, &clip);
    assert(ret == 0);
    assert(clip.is_visible == 0);

    /* Sprite completely below: y = 500, h = 32 */
    ret = render_clip_sprite(100, 500, 32, 32, &vp, &clip);
    assert(ret == 0);
    assert(clip.is_visible == 0);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <case_index>\n", argv[0]);
        return 1;
    }
    int idx = atoi(argv[1]);
    switch (idx) {
        case 0: return test_rect_empty_and_contains();
        case 1: return test_rect_intersect();
        case 2: return test_rect_union();
        case 3: return test_clip_to_bounds();
        case 4: return test_clip_sprite_partial();
        case 5: return test_clip_sprite_invisible();
        default:
            fprintf(stderr, "unknown case: %d\n", idx);
            return 2;
    }
}
