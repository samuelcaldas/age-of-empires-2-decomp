#pragma exceptions off

extern "C" {
void func_00261ED0(void *texture, int p1, int p2, int p3, int p4, int p5);
void func_00226D90(void *stream, void *dest, int size);
void func_00226F70(void *stream, void *src, int size);
void func_00262570(void *texture, void *dest, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
void func_00262760(void *texture, void *dest, int p2, int p3, int p4, int p5, int p6);
void func_002628E0(void *texture, void *dest, int p2, int p3, int p4, int p5, int p6, int p7);
void func_002621E0(void *texture, int p1, int p2, void *p3);
int func_00262BA0(void *texture);
int func_00262FA0(void *texture);
int func_002634A0(void *texture);

struct AspNode {
    void *texture;
    short x;
    short y;
    unsigned char mode;
    unsigned char priority;
    unsigned char active;
    unsigned char ref_count;
};

void func_00183240(AspNode *node, void *texture, int priority, short x, short y, int flags) {
    node->priority = 1;
    node->texture = texture;
    node->x = 0;
    node->y = 0;
    node->mode = 0;
    node->active = 0;
    short sy = y;
    if ((*(unsigned char *)((char *)texture + 59) & 4) != 0) {
        node->mode = 0;
    } else {
        node->mode = 0;
    }
    if (flags != 0) {
        if (node->texture != 0) {
            func_00261ED0(node->texture, 0, 1, priority, sy, 0);
        }
    }
}

void func_001832c0(AspNode *node, void *stream, void *textures) {
    node->priority = 1;
    short tex_idx;
    func_00226D90(stream, &tex_idx, 2);
    if (tex_idx >= 0) {
        node->texture = *(void **)((char *)textures + tex_idx * 4);
    } else {
        node->texture = 0;
    }
    func_00226D90(stream, &node->x, 4);
    func_00226D90(stream, &node->y, 4);
    func_00226D90(stream, &node->mode, 2);
    func_00226D90(stream, &node->active, 1);
}

void func_00183380(AspNode *node) {
    node->ref_count = 0;
}

void func_00183390(AspNode *node, short x, short y) {
    node->x = x;
    node->y = y;
}

void func_001833a0(AspNode *node, void *stream) {
    short tex_idx;
    if (node->texture != 0) {
        tex_idx = *(short *)((char *)node->texture + 52);
    } else {
        tex_idx = -1;
    }
    func_00226F70(stream, &node->priority, 1);
    func_00226F70(stream, &tex_idx, 2);
    func_00226F70(stream, &node->x, 4);
    func_00226F70(stream, &node->y, 4);
    func_00226F70(stream, &node->mode, 2);
    func_00226F70(stream, &node->active, 1);
}

int func_00183450(AspNode *node, float x, float y) {
    return 1;
}

void func_00183460(AspNode *node, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2, void *extra) {
    if (node->active != 0) {
        if (extra == 0) return;
        void *f8 = *(void **)((char *)extra + 8);
        int f2968 = *(int *)((char *)f8 + 2968);
        int f2976 = *(int *)((char *)f8 + 2976);
        short val = *(short *)((char *)f2968 + 152);
        if ((f2976 ^ val) >= 1) return;
    }
    if (node->texture != 0) {
        func_00262570(node->texture, dest, node->mode, x + node->x, y + node->y, cx1, cy1, cx2, cy2, 0);
    }
}

void func_00183550(AspNode *node, void *dest, short x, short y, int p0, int p1) {
    if (node->texture != 0) {
        func_00262760(node->texture, dest, node->mode, x + node->x, y + node->y, p0, p1);
    }
}

void func_001835a0(AspNode *node, void *dest, short x, short y, int t0, int t1, int t2) {
    if (node->texture != 0) {
        func_002628E0(node->texture, dest, node->mode, x, y, t0, t1, t2);
    }
}

int func_001835f0(AspNode *node) {
    return node->mode;
}

void func_00183600(AspNode *node, int mode) {
    node->mode = mode;
}

void func_00183610(AspNode *node, int p1, void *p2) {
    if (node->texture != 0) {
        func_00261ED0(node->texture, 0, 1, p1, (int)p2, 0);
    }
}

int func_00183650(AspNode *node) {
    return 0;
}

int func_00183660(AspNode *node, int p1) {
    return 1;
}

int func_00183670(AspNode *node) {
    return 0;
}

int func_00183680(AspNode *node, int p1) {
    short res = 0;
    if (node->texture != 0) {
        func_002621E0(node->texture, p1, 0, &res);
    }
    return res;
}

int func_001836c0(AspNode *node, int p1, int p2, int p3, int p4, int p5) {
    if (node->texture != 0) {
        return (unsigned char)func_00262BA0(node->texture);
    }
    return 0;
}

int func_00183700(AspNode *node) {
    if (node->texture != 0) {
        return func_00262FA0(node->texture);
    }
    return 20;
}

int func_00183740(AspNode *node) {
    if (node->texture != 0) {
        return func_002634A0(node->texture);
    }
    return 0;
}
}
