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
    virtual int Method17C(float x, float y, float z, int a1, int a2); // index 93 -> offset 0x17C (380)

    char pad_04[0x4];
    void *m_world;      // 0x08
    char pad_0C[0x18];
    short m_action;     // 0x24
    char pad_26[0x1E];
    float pos_x;        // 0x44
    float pos_y;        // 0x48
    float pos_z;        // 0x4C
    char pad_50[0x14];
    int m_timer_id;     // 0x64
};

class TradeAction {
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
    virtual void Method5C(int a1); // index 21 -> offset 0x5C

    char pad_04[0x2A];
    unsigned char m_state; // 0x2E
    char pad_2F[0x09];
    TargetObj *m_target;   // 0x38
    char pad_3C[0x08];
    short m_field44;       // 0x44
    char pad_46[0x02];
    short m_field48;       // 0x48
    char pad_4A[0x10A];
    float m_target_x;      // 0x154
    float m_target_y;      // 0x158
};

extern "C" {
extern void *D_004E3180;
extern const char D_4910C0[];
extern const char D_4910D0[];
extern const char D_4910D8[];
extern const char D_4910E8[];
extern const char D_4910F8[];

void func_14bce0(TradeAction *self);
float func_269190(TargetObj *t, float x, float y, float z);
short func_001471B0(TradeAction *self, short cmd);
void *func_332e60(void *mgr, int id);
void *func_333b30(void *mgr, int id);
int func_1bbe40(void *timer, int a1);
void func_1b95b0(void *timer, short target_action, int target_id);

void func_0014C7E0(TradeAction *self, unsigned char state) {
    self->m_state = state;
    self->m_target_x = self->m_target->pos_x;
    self->m_target_y = self->m_target->pos_y;
    if (self->m_state == 3) {
        if (self->m_field44 == 700 || self->m_field48 == 600) {
            self->Method5C(1);
            func_14bce0(self);
        }
    }
}

int func_0014C870(TradeAction *self) {
    TargetObj *target = self->m_target;
    float dist = func_269190(target, self->m_target_x, self->m_target_y, target->pos_z);
    if (dist <= 1.0f) {
        return 0;
    }
    if (self->m_target->Method17C(self->m_target_x, self->m_target_y, self->m_target->pos_z, 1, 0) == 1) {
        func_001471B0(self, 610);
        return 1;
    }
    return 0;
}

const char *func_0014C910(TradeAction *self, int stance) {
    if (stance == 3) goto L3;
    if (stance == 2) goto L2;
    if (stance == 1) goto L1;
    if (stance == 0) goto L0;
    goto L_def;

L0: return D_4910C0;
L1: return D_4910D0;
L2: return D_4910D8;
L3: return D_4910E8;
L_def: return D_4910F8;
}

int func_0014C990(TradeAction *self, int target_id) {
    void *game = D_004E3180;
    void *mgr = *(void **)((char *)game + 1028);
    void *obj = func_332e60(mgr, target_id);
    if (obj != 0) goto L_ok;
    if (target_id == -1) goto L_ok;
    return 0;

L_ok:
    if (self->m_target->m_timer_id != -1) {
        void *world = self->m_target->m_world;
        void *game_mgr = *(void **)((char *)world + 2968);
        void *timer_obj = func_333b30(game_mgr, self->m_target->m_timer_id);
        if (timer_obj) {
            if (func_1bbe40(timer_obj, 1) == 0) {
                return 0;
            }
            if (*(int *)((char *)timer_obj + 236) != 0) goto L_call;
            return 1;

        L_call:
            func_1b95b0(timer_obj, self->m_target->m_action, target_id);
            return 1;
        }
    }
    if (self->m_field44 != -1) goto L_ret1;
    if (self->m_state == 0) goto L_ret1;
    if (self->m_state == 1) goto L_ret1;
    return 0;

L_ret1:
    return 1;
}

}
