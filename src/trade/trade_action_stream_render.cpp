#pragma exceptions off

extern "C" {
void func_00183210(void *pool, void *item);
int func_00183450(void *node, float x, float y);
int func_001839D0(void *node, float x, float y);
void func_00183460(void *node, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2, void *extra);
void func_001839E0(void *node, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2, void *extra);
void func_00183550(void *node, void *dest, short x, short y, int p0, int p1);
void func_00183E00(void *node, void *dest, short x, short y, int p0, int p1);

void func_00182890(void *this_ptr, float x, float y) {
    void **prev_ptr = (void **)this_ptr;
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *next = *(void **)((char *)item + 4);
        int ret;
        if (*(unsigned char *)((char *)item + 8) == 0) {
            ret = func_00183450(*(void **)item, x, y);
        } else {
            ret = func_001839D0(*(void **)item, x, y);
        }
        if (ret == 0) {
            *prev_ptr = next;
            func_00183210((void *)0x514E30, item);
        } else {
            prev_ptr = (void **)((char *)item + 4);
        }
        item = next;
    }
}

void func_001829f0(void *this_ptr, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2) {
    void *extra = *(void **)((char *)this_ptr + 4);
    void *item = *(void **)this_ptr;
    while (item != 0) {
        if (*(unsigned char *)((char *)item + 8) == 0) {
            func_00183460(*(void **)item, dest, x, y, cx1, cy1, cx2, cy2, extra);
        } else {
            func_001839E0(*(void **)item, dest, x, y, cx1, cy1, cx2, cy2, extra);
        }
        item = *(void **)((char *)item + 4);
    }
}

void func_00182b60(void *this_ptr, void *dest, short x, short y, int p0, int p1) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        if (*(unsigned char *)((char *)item + 8) == 0) {
            func_00183550(*(void **)item, dest, x, y, p0, p1);
        } else {
            func_00183E00(*(void **)item, dest, x, y, p0, p1);
        }
        item = *(void **)((char *)item + 4);
    }
}
}
