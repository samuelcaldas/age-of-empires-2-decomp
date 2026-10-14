#ifndef VISIBLE_MAP_H
#define VISIBLE_MAP_H

/**
 * VisibleMap - Map visibility / Fog of War tile grid.
 */
struct VisibleMap {
    int m_width;
    int m_height;
    int *m_buffer;
    int m_staticBuf[40000];
};

extern "C" {
    void* func_00138760(void *self);
    void* func_00138770(void *self, int flag);
    void func_001387C0(VisibleMap *self, int width, int height);
    void func_00138830(VisibleMap *self, void *stream);
    void func_001388E0(VisibleMap *self, void *stream);
    void func_00138960(VisibleMap *self);
    void func_001389E0(void *self, int val);
    void func_001389F0(VisibleMap *self);
}

#endif // VISIBLE_MAP_H
