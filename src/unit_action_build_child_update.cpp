#pragma exceptions off
#include "unit_action_build_child_update.h"

int func_0026F590(ActionRebind *self, ActionRebind *child, float x, float y) {
    float pos_x;
    float pos_y;
    void *child_f4 = *(void**)((char*)child + 4);
    int res = func_271B40(self, child_f4, &pos_x, &pos_y);
    if (res == 0) {
        return 0;
    }

    func_0026F8A0(self);

    float self_z = *(float*)((char*)self + 76);
    func_2697B0(child, pos_x, pos_y, self_z);

    typedef void (*Method58Fn)(void *c);
    typedef void (*Method17Fn)(void *c, float px, float py, float pz);
    void **child_vt = *(void***)child;
    Method58Fn m58 = (Method58Fn)child_vt[58];
    m58(child);
    Method17Fn m17 = (Method17Fn)child_vt[17];
    m17(child, pos_x, pos_y, self_z);

    if (x == -1.0f) {
        if (*(unsigned char*)((char*)self + 347) != 0) {
            short f168 = *(short*)((char*)self + 360);
            if (f168 != *(short*)((char*)self + 36) && f168 != -1) {
                float target_x = *(float*)((char*)self + 348);
                float target_y = *(float*)((char*)self + 352);
                void *world = *(void**)((char*)self + 8);
                void *target = func_332E60(*(void**)((char*)world + 2968));
                if (target != 0) {
                    typedef void* (*Method89Fn)(void *c);
                    typedef void (*Method81Fn)(void *c, int val);
                    Method89Fn m89 = (Method89Fn)child_vt[89];
                    void *sub = m89(child);
                    func_14BCE0(*(void**)sub);
                    Method81Fn m81 = (Method81Fn)child_vt[81];
                    m81(child, 1);

                    void *target_f4 = *(void**)((char*)target + 4);
                    if (*(unsigned char*)target_f4 == 80) {
                        void *child_master = *(void**)((char*)child + 4);
                        void *interf = *(void**)((char*)child_master + 200);
                        typedef int (*InterfFn)(void *it, void *c, void *tgt, float tx, float ty, float zero, int mode, int opt);
                        void **interf_vt = *(void***)interf;
                        InterfFn ifn = (InterfFn)interf_vt[3];
                        if (ifn(interf, child, target, target_x, target_y, 0.0f, 3, 0) != 0) {
                            typedef void (*Method192Fn)(void *c, int zero, void *tgt, int mode, float tx, float ty, float fz);
                            Method192Fn m192 = (Method192Fn)child_vt[192];
                            m192(child, 0, target, 3, target_x, target_y, 0.0f);
                            return 1;
                        }
                    }

                    typedef void (*Method42Fn)(void *c, void *tgt, float tx, float ty, float fz);
                    Method42Fn m42 = (Method42Fn)child_vt[42];
                    m42(child, target, target_x, target_y, 0.0f);
                    return 1;
                }
            }
        }
    }

    if (x != -1.0f && y != -1.0f) {
        typedef void* (*Method89Fn)(void *c);
        typedef void (*Method81Fn)(void *c, int val);
        Method89Fn m89 = (Method89Fn)child_vt[89];
        void *sub = m89(child);
        if (sub != 0) {
            func_14BCE0(*(void**)sub);
        }
        Method81Fn m81 = (Method81Fn)child_vt[81];
        m81(child, 1);

        typedef void (*Method42Fn)(void *c, void *tgt, float tx, float ty, float fz);
        Method42Fn m42 = (Method42Fn)child_vt[42];
        m42(child, 0, x, y, 0.0f);
        return 1;
    }

    typedef void* (*Method89Fn)(void *c);
    Method89Fn m89 = (Method89Fn)child_vt[89];
    void *sub = m89(child);
    if (sub != 0) {
        typedef void (*SubMethod23)(void *s, int val);
        void **sub_vt = *(void***)*(void**)sub;
        SubMethod23 sm23 = (SubMethod23)sub_vt[23];
        sm23(*(void**)sub, 1);
        func_14BCE0(*(void**)sub);
        void *sub2 = m89(child);
        void *sub3 = m89(child);
        func_14C7F0(*(void**)sub3, *(unsigned char*)((char*)*(void**)sub2 + 46));
    }
    return 1;
}
