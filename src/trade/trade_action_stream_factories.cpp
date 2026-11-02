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
    for (int i = 0; i < 4000; ++i, p += 12) {
        *(unsigned char *)(p + 11) = 0;
    }
}

void *func_001840A0(StaticPool *pool) {
    func_00184070(pool);
    return pool;
}

void *func_001840D0(StaticPool *pool, void *tex, int prio, short x, short y, int fl) {
    char *p = (char *)pool;
    for (int i = 0; i < 4000; ++i, p += 12) {
        if (*(unsigned char *)(p + 11) == 0) {
            *(unsigned char *)(p + 11) = 1;
            func_00183240(p, tex, prio, x, y, fl);
            return p;
        }
    }
    return 0;
}

void *func_00184140(StaticPool *pool, void *stream, void *textures) {
    char *p = (char *)pool;
    for (int i = 0; i < 4000; ++i, p += 12) {
        if (*(unsigned char *)(p + 11) == 0) {
            func_001832c0(p, stream, textures);
            *(unsigned char *)(p + 11) = 1;
            return p;
        }
    }
    return 0;
}

void func_001841B0(AnimPool *pool) {
    char *p = (char *)pool;
    for (int i = 0; i < 6000; ++i, p += 28) {
        *(unsigned char *)(p + 11) = 0;
    }
}

void *func_001841E0(AnimPool *pool) {
    func_001841B0(pool);
    return pool;
}

void *func_00184210(AnimPool *pool, void *tex, int prio, short x, short y, int fl) {
    char *p = (char *)pool;
    for (int i = 0; i < 6000; ++i, p += 28) {
        if (*(unsigned char *)(p + 11) == 0) {
            *(unsigned char *)(p + 11) = 1;
            func_00183780(p, tex, prio, x, y, fl);
            return p;
        }
    }
    return 0;
}

void *func_00184280(AnimPool *pool, void *stream, void *textures) {
    char *p = (char *)pool;
    for (int i = 0; i < 6000; ++i, p += 28) {
        if (*(unsigned char *)(p + 11) == 0) {
            *(unsigned char *)(p + 11) = 1;
            func_00183870(p, stream, textures);
            return p;
        }
    }
    return 0;
}

class FactoryManager {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual int Dispatch(void *p0, void *p1, void *p2, void *p3);
};

int func_001842F0(void *p0, void *p1, void *p2, void *p3) {
    FactoryManager *mgr = (FactoryManager *)D_004E3180;
    if (mgr) {
        return mgr->Dispatch(p0, p1, p2, p3);
    }
    return 0;
}
}
