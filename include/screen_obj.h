#ifndef SCREEN_OBJ_H
#define SCREEN_OBJ_H

/**
 * ScreenObj - Graphics screen / surface representation.
 */
class ScreenObj {
public:
    int pad[7];
    int m_width;
    int m_height;

    float AspectRatio();
};

#endif // SCREEN_OBJ_H
