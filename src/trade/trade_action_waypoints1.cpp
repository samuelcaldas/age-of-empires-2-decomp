#pragma exceptions off
#include "sub_list.h"

class TargetObj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual int Target609(short id); // index 95 -> 388 (0x184)
    virtual int Target604(short id); // index 96 -> 392 (0x188)
    virtual int Target603(short id); // index 97 -> 396 (0x18C)
    virtual int Target618(short id); // index 98 -> 400 (0x190)

    char pad_04[0x4];
    void *m_world;
};

struct TradeAction {
    char pad_00[0x38];
    TargetObj *m_target;
    char pad_3C[0x0C];
    short m_field48;
};

extern "C" {
void *func_332e60(void *mgr, short id);
short func_001471B0(TradeAction *self, short cmd);
int func_14bd90(TradeAction *self, short target_id, short obj_type, float x, float y, float z);

int func_00149FE0(TradeAction *self, short target_id, int flag) {
    int res = 0;
    if (!flag && self->m_field48 == 604) {
        return res;
    }
    if (self->m_target->Target604(target_id) == 1) {
        void *world = self->m_target->m_world;
        void *mgr = *(void **)((char *)world + 2968);
        void *obj = func_332e60(mgr, target_id);
        func_001471B0(self, 604);
        if (!obj) {
            float f = 0.0f;
            func_14bd90(self, target_id, -1, f, f, f);
        } else {
            void *master = *(void **)((char *)obj + 4);
            short obj_type = *(short *)((char *)master + 14);
            float x = *(float *)((char *)obj + 68);
            float y = *(float *)((char *)obj + 72);
            float z = *(float *)((char *)obj + 76);
            func_14bd90(self, target_id, obj_type, x, y, z);
        }
        return 1;
    }
    return res;
}

int func_0014A0D0(TradeAction *self, short target_id, int flag) {
    int res = 0;
    if (!flag && self->m_field48 == 603) {
        return res;
    }
    if (self->m_target->Target603(target_id) == 1) {
        void *world = self->m_target->m_world;
        void *mgr = *(void **)((char *)world + 2968);
        void *obj = func_332e60(mgr, target_id);
        func_001471B0(self, 603);
        if (!obj) {
            float y = 0.0f;
            func_14bd90(self, target_id, -1, 0.0f, y, y);
        } else {
            void *master = *(void **)((char *)obj + 4);
            short obj_type = *(short *)((char *)master + 14);
            float x = *(float *)((char *)obj + 68);
            float y = *(float *)((char *)obj + 72);
            float z = *(float *)((char *)obj + 76);
            func_14bd90(self, target_id, obj_type, x, y, z);
        }
        return 1;
    }
    return res;
}

int func_0014A1C0(TradeAction *self, short target_id, int flag) {
    int res = 0;
    if (!flag && self->m_field48 == 609) {
        return res;
    }
    if (self->m_target->Target609(target_id) == 1) {
        void *world = self->m_target->m_world;
        void *mgr = *(void **)((char *)world + 2968);
        void *obj = func_332e60(mgr, target_id);
        func_001471B0(self, 609);
        if (!obj) {
            float f = 0.0f;
            func_14bd90(self, target_id, -1, f, f, f);
        } else {
            void *master = *(void **)((char *)obj + 4);
            short obj_type = *(short *)((char *)master + 14);
            float x = *(float *)((char *)obj + 68);
            float y = *(float *)((char *)obj + 72);
            float z = *(float *)((char *)obj + 76);
            func_14bd90(self, target_id, obj_type, x, y, z);
        }
        return 1;
    }
    return res;
}

int func_0014A2B0(TradeAction *self, short target_id, int flag) {
    int res = 0;
    if (!flag && self->m_field48 == 618) {
        return res;
    }
    if (self->m_target->Target618(target_id) == 1) {
        void *world = self->m_target->m_world;
        void *mgr = *(void **)((char *)world + 2968);
        void *obj = func_332e60(mgr, target_id);
        func_001471B0(self, 618);
        if (!obj) {
            float f = 0.0f;
            func_14bd90(self, target_id, -1, f, f, f);
        } else {
            void *master = *(void **)((char *)obj + 4);
            short obj_type = *(short *)((char *)master + 14);
            float x = *(float *)((char *)obj + 68);
            float y = *(float *)((char *)obj + 72);
            float z = *(float *)((char *)obj + 76);
            func_14bd90(self, target_id, obj_type, x, y, z);
        }
        return 1;
    }
    return res;
}

}
