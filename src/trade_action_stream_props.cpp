#pragma exceptions off

extern "C" {
void func_001835a0(void *node, void *dest, int x, int y, int t0, int t1, int t2);
void func_00183eb0(void *node, void *dest, int x, int y, int t0, int t1, int t2);
int func_00183f00(void *node);
int func_001835f0(void *node);
int func_00183f20(void *node);
int func_00183650(void *node);
void func_00183600(void *node, int param);
void func_00183f10(void *node, int param);
void func_00183610(void *node, int param, void *extra);
void func_00183f60(void *node, int param, void *extra);
int func_00183f70(void *node, int param);
int func_00183660(void *node, int param);
int func_00183fe0(void *node);
int func_00183670(void *node);
int func_00183ff0(void *node, int param);
int func_00183680(void *node, int param);
int func_00184030(void *node, int p1, int p2, int p3, int p4, int p5);
int func_001836c0(void *node, int p1, int p2, int p3, int p4, int p5);
int func_00183700(void *node);

struct AspList {
    void *head;
    void *extra;
};

void func_00182c40(void *this_ptr, void *dest, short x, short y, int t0, int t1, int t2) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        if ((*(unsigned char *)((char *)item + 8) != 0) ^ 1) {
            func_001835a0(*(void **)item, dest, x, y, t0, t1, t2);
        } else {
            func_00183eb0(*(void **)item, dest, x, y, t0, t1, t2);
        }
        item = *(void **)((char *)item + 4);
    }
}

int func_00182d20(void *this_ptr, int id) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == id) {
            if (*(unsigned char *)((char *)item + 8) != 0) {
                return func_00183f00(node);
            }
            return func_001835f0(node);
        }
        item = *(void **)((char *)item + 4);
    }
    return 0;
}

int func_00182d90(void *this_ptr, int id) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == id) {
            if (*(unsigned char *)((char *)item + 8) != 0) {
                return func_00183f20(node);
            }
            return func_00183650(node);
        }
        item = *(void **)((char *)item + 4);
    }
    return 0;
}

void func_00182e00(void *this_ptr, int id, int param) {
    void *item = *(void **)this_ptr;
    int sid = id;
    int sparam = param;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == sid) {
            if ((*(unsigned char *)((char *)item + 8) != 0) ^ 1) {
                func_00183600(node, sparam);
            } else {
                func_00183f10(node, sparam);
            }
        }
        item = *(void **)((char *)item + 4);
    }
}

void func_00182e90(AspList *this_ptr, int param) {
    void *item = this_ptr->head;
    int sparam = param;
    AspList *sthis = this_ptr;
    while (item != 0) {
        if ((*(unsigned char *)((char *)item + 8) != 0) ^ 1) {
            func_00183610(*(void **)item, sparam, sthis->extra);
        } else {
            func_00183f60(*(void **)item, sparam, sthis->extra);
        }
        item = *(void **)((char *)item + 4);
    }
}

int func_00182f20(void *this_ptr, int id, int param) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == id) {
            if (*(unsigned char *)((char *)item + 8) != 0) {
                return func_00183f70(node, param);
            }
            return func_00183660(node, param);
        }
        item = *(void **)((char *)item + 4);
    }
    return 0;
}

int func_00182f90(void *this_ptr, int id) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == id) {
            if (*(unsigned char *)((char *)item + 8) != 0) {
                return func_00183fe0(node);
            }
            return func_00183670(node);
        }
        item = *(void **)((char *)item + 4);
    }
    return 0;
}

int func_00183000(void *this_ptr, int id, int param) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == id) {
            if (*(unsigned char *)((char *)item + 8) != 0) {
                return func_00183ff0(node, param);
            }
            return func_00183680(node, param);
        }
        item = *(void **)((char *)item + 4);
    }
    return 0;
}

int func_00183070(void *this_ptr, int p1, int p2, int p3, int p4, int p5, int p6) {
    void *item = *(void **)this_ptr;
    while (item != 0) {
        void *node = *(void **)item;
        if (*(int *)node == p5) {
            if (*(unsigned char *)((char *)item + 8) != 0) {
                return func_00184030(node, p1, p2, p3, p4, p6);
            }
            return func_001836c0(node, p1, p2, p3, p4, p6);
        }
        item = *(void **)((char *)item + 4);
    }
    return 0;
}

unsigned char func_001830e0(void *this_ptr) {
    unsigned char min_val = 20;
    void *item = *(void **)this_ptr;
    while (item != 0) {
        int val = (unsigned char)func_00183700(*(void **)item);
        if (val < (unsigned char)min_val) {
            min_val = (unsigned char)val;
        }
        item = *(void **)((char *)item + 4);
    }
    return min_val;
}
}
