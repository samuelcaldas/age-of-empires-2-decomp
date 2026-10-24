#pragma exceptions off

extern "C" {
void func_00183240(void *node, void *texture, int priority, short x, short y, int flags);
void func_001832c0(void *node, void *stream, void *textures);
void func_00183780(void *node, void *texture, int priority, short x, short y, int flags);
void func_00183870(void *node, void *stream, void *textures);

extern void *D_004E3180;

struct StaticPool {
    char slots[4000 * 12];
};

struct AnimPool {
    char slots[6000 * 28];
};

void func_00184070(StaticPool *pool) {
    char *p = (char *)pool;
    for (int i = 0; i < 4000; i++) {
        *(unsigned char *)(p + 11) = 0;
        p += 12;
    }
}

void *func_001840a0(StaticPool *pool) {
    func_00184070(pool);
    return pool;
}

void *func_001840d0(StaticPool *pool, void *tex, int prio, short x, short y, int fl) {
    char *p = (char *)pool;
    for (int i = 0; i < 4000; i++) {
        if (*(unsigned char *)(p + 11) == 0) {
            *(unsigned char *)(p + 11) = 1;
            func_00183240(p, tex, prio, x, y, fl);
            return p;
        }
        p += 12;
    }
    return 0;
}

void *func_00184140(StaticPool *pool, void *stream, void *textures) {
    char *p = (char *)pool;
    for (int i = 0; i < 4000; i++) {
        if (*(unsigned char *)(p + 11) == 0) {
            func_001832c0(p, stream, textures);
            *(unsigned char *)(p + 11) = 1;
            return p;
        }
        p += 12;
    }
    return 0;
}

void func_001841b0(AnimPool *pool) {
    char *p = (char *)pool;
    for (int i = 0; i < 6000; i++) {
        *(unsigned char *)(p + 11) = 0;
        p += 28;
    }
}

void *func_001841e0(AnimPool *pool) {
    func_001841b0(pool);
    return pool;
}

void *func_00184210(AnimPool *pool, void *tex, int prio, short x, short y, int fl) {
    char *p = (char *)pool;
    for (int i = 0; i < 6000; i++) {
        if (*(unsigned char *)(p + 11) == 0) {
            *(unsigned char *)(p + 11) = 1;
            func_00183780(p, tex, prio, x, y, fl);
            return p;
        }
        p += 28;
    }
    return 0;
}

void *func_00184280(AnimPool *pool, void *stream, void *textures) {
    char *p = (char *)pool;
    for (int i = 0; i < 6000; i++) {
        if (*(unsigned char *)(p + 11) == 0) {
            *(unsigned char *)(p + 11) = 1;
            func_00183870(p, stream, textures);
            return p;
        }
        p += 28;
    }
    return 0;
}

int func_001842f0(void *p0, void *p1, void *p2, void *p3) {
    void *mgr = D_004E3180;
    if (mgr != 0) {
        typedef int (*VMethod4)(void *self, void *a, void *b, void *c, void *d);
        VMethod4 fn = *(VMethod4 *)(*(char **)mgr + 16);
        return fn(mgr, p0, p1, p2, p3);
    }
    return 0;
}
}
