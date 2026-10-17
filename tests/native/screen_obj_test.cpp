#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "screen_obj.h"

static void test_screen_obj_aspect_ratio() {
    ScreenObj screen;
    memset(&screen, 0, sizeof(screen));
    screen.m_width = 640;
    screen.m_height = 480;

    float ratio = screen.AspectRatio();
    float expected = 640.0f / 480.0f;
    float diff = ratio - expected;
    if (diff < 0) diff = -diff;
    assert(diff < 0.0001f);
}

int main(int argc, char **argv) {
    (void)argc; (void)argv;
    test_screen_obj_aspect_ratio();
    return 0;
}
