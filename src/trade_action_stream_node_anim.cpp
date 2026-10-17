#pragma exceptions off
#pragma inline_intrinsics on

#ifndef __MWERKS__
inline void __I_cvt_w_s(long, long) {}
inline void __I_mfc1(long, long) {}
inline void __I_mtc1(long, long) {}
inline void __I_cvt_s_w(long, long) {}
#endif

extern "C" {
void func_00183240(void *node, void *texture, int priority, short x, short y, int flags);
void func_001832c0(void *node, void *stream, void *textures);
void func_001833a0(void *node, void *stream);
int func_001aab30();
void func_00226D90(void *stream, void *dest, int size);
void func_00226F70(void *stream, void *src, int size);
void func_00262570(void *texture, void *dest, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
void func_00262760(void *texture, void *dest, int p2, int p3, int p4, int p5, int p6);
void func_002628E0(void *texture, void *dest, int p2, int p3, int p4, int p5, int p6, int p7);
void func_00261ED0(void *texture, int p1, int p2, int p3, int p4, int p5);
void func_002621E0(void *texture, int p1, int p2, void *p3);
int func_00262BA0(void *texture);

extern int D_004E33F4;

struct AspAnimatedNode {
    void *texture;
    short x, y;
    unsigned char mode, priority, active, ref_count;
    float frame_duration, elapsed_time, speed;
    unsigned char loop_frame, trigger_flag, end_flag, anim_mode;
};

void func_00183780(AspAnimatedNode *n, void *tex, int prio, short x, short y, int fl) {
    func_00183240(n, tex, prio, x, y, 0);
    n->priority = 2; n->speed = 0.0f; n->loop_frame = 0;
    float dur = *(float *)((char *)n->texture + 32);
    n->frame_duration = (dur < 0.01f) ? 0.01f : dur;
    if ((*(unsigned char *)((char *)n->texture + 59) & 4) != 0) {
        if (*(float *)((char *)n->texture + 32) > 0.0f) {
            int r = func_001aab30();
            n->mode = (*(unsigned char *)((char *)n->texture + 57) * r) / 32767;
        } else { n->mode = 0; }
    } else { n->mode = 0; }
    n->loop_frame = n->mode; n->elapsed_time = 0.0f;
    n->trigger_flag = 0; n->end_flag = 0; n->anim_mode = 1;
}

void func_00183870(AspAnimatedNode *n, void *str, void *texs) {
    func_001832c0(n, str, texs);
    n->priority = 2;
    func_00226D90(str, &n->frame_duration, 4);
    func_00226D90(str, &n->elapsed_time, 4);
    func_00226D90(str, &n->loop_frame, 2);
    func_00226D90(str, &n->end_flag, 1);
    func_00226D90(str, &n->anim_mode, 1);
    func_00226D90(str, &n->speed, 4);
}

void func_00183920(AspAnimatedNode *n) { n->ref_count = 0; }

void func_00183930(AspAnimatedNode *n, void *str) {
    func_001833a0(n, str);
    func_00226F70(str, &n->frame_duration, 4);
    func_00226F70(str, &n->elapsed_time, 4);
    func_00226F70(str, &n->loop_frame, 2);
    func_00226F70(str, &n->end_flag, 1);
    func_00226F70(str, &n->anim_mode, 1);
    func_00226F70(str, &n->speed, 4);
}

void func_001839d0(AspAnimatedNode *n, float dt, float sp) {
    n->trigger_flag = 0; n->end_flag = 0;
    if (n->texture == 0 || n->anim_mode == 0) return;
    unsigned char tot = *(unsigned char *)((char *)n->texture + 57);
    if (n->mode >= tot) n->mode = tot - 1;
    if ((*(unsigned char *)((char *)n->texture + 59) & 1) == 0) return;
    n->elapsed_time += dt;
    if (n->speed != sp) {
        float b = *(float *)((char *)n->texture + 28);
        if (b == 0.0f || sp == 0.0f) {
            n->frame_duration = *(float *)((char *)n->texture + 32);
        } else {
            n->frame_duration = (*(float *)((char *)n->texture + 32) * b) / sp;
        }
        if (n->frame_duration < 0.01f) n->frame_duration = 0.01f;
        n->speed = sp;
    }
    if (n->elapsed_time < n->frame_duration) return;
    n->trigger_flag = 1; n->loop_frame = n->mode;
    __I_cvt_w_s(0, 0);
    __I_mfc1(3, 0);
    __I_mtc1(5, 0);
    __I_cvt_s_w(0, 0);
    if (sp <= 0.0f && *(float *)((char *)n->texture + 28) == 0.0f) {
    } else {
        if (n->mode >= *(unsigned char *)((char *)n->texture + 57)) n->end_flag = 1;
    }
    if (n->end_flag != 0) {
        void *tex = n->texture;
        float f36 = *(float *)((char *)tex + 36);
        if (f36 <= 0.0f || n->anim_mode == 2) {
            n->anim_mode = 1;
            while (n->mode >= *(unsigned char *)((char *)n->texture + 57)) {
                n->mode -= *(unsigned char *)((char *)n->texture + 57);
            }
        } else {
            unsigned char a1 = n->mode;
            unsigned char tot2 = *(unsigned char *)((char *)tex + 57);
            n->frame_duration = f36 - (*(float *)((char *)tex + 32) * (float)(a1 - tot2));
            n->mode = *(unsigned char *)((char *)n->texture + 57) - 1;
            n->anim_mode = 2;
            n->end_flag = 0;
        }
    }
    if (n->end_flag != 0) {
        if ((*(unsigned char *)((char *)n->texture + 59) & 8) != 0) {
            n->anim_mode = 0;
            n->mode = *(unsigned char *)((char *)n->texture + 57) - 1;
        }
    }
}

void func_00183cc0(AspAnimatedNode *n, void *dest, short x, short y, short cx1, short cy1, short cx2, short cy2, void *extra) {
    if (n->texture == 0) return;
    if (n->active != 0) {
        if (extra == 0) goto check_trig;
        void *f8 = *(void **)((char *)extra + 8);
        int a = *(int *)((char *)f8 + 2968), b = *(int *)((char *)f8 + 2976);
        if (b != *(short *)((char *)a + 152)) goto check_trig;
    }
    func_00262570(n->texture, dest, n->mode, x + n->x, y + n->y, cx1, cy1, cx2, cy2, 0);
check_trig:
    if (n->trigger_flag != 0) {
        if (D_004E33F4 == 0) {
            func_00261ED0(n->texture, n->loop_frame, n->mode, (int)dest, (int)extra, 0);
        }
        n->trigger_flag = 0;
    }
}

void func_00183e00(AspAnimatedNode *n, void *dest, short x, short y, int p0, int p1) {
    if (n->texture != 0) {
        func_00262760(n->texture, dest, n->mode, x + n->x, y + n->y, p0, p1);
        if (n->trigger_flag != 0) {
            func_00261ED0(n->texture, n->loop_frame, n->mode, (int)dest, p1, 0);
            n->trigger_flag = 0;
        }
    }
}

void func_00183eb0(AspAnimatedNode *n, void *dest, short x, short y, int t0, int t1, int t2) {
    if (n->texture != 0) {
        func_002628E0(n->texture, dest, n->mode, x, y, t0, t1, t2);
    }
}

int func_00183f00(AspAnimatedNode *n) { return n->mode; }

void func_00183f10(AspAnimatedNode *n, int m) {
    n->mode = m;
    n->loop_frame = m;
}

int func_00183f20(AspAnimatedNode *n) {
    if (n->texture == 0 || n->anim_mode == 0) return 0;
    if ((*(unsigned char *)((char *)n->texture + 59) & 1) != 0) return 1;
    return 0;
}

void func_00183f60(AspAnimatedNode *n, int p, void *e) {}

int func_00183f70(AspAnimatedNode *n, int target) {
    if (n->trigger_flag == 0) return 0;
    if (n->end_flag != 0) return 1;
    if (n->mode < (short)target && n->loop_frame > (short)target) return 1;
    return 0;
}

int func_00183fe0(AspAnimatedNode *n) { return n->end_flag; }

int func_00183ff0(AspAnimatedNode *n, int p) {
    short res = 0;
    if (n->texture != 0) func_002621E0(n->texture, p, n->mode, &res);
    return res;
}

int func_00184030(AspAnimatedNode *n, int p1, int p2, int p3, int p4, int p5) {
    if (n->texture != 0) return (unsigned char)func_00262BA0(n->texture);
    return 0;
}
}
