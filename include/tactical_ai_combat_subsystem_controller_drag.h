#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_DRAG_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_DRAG_H

struct Sub28 {
    char pad00[0x94];
    unsigned int m_duration_94;
    float m_max_speed_98;
    float m_margin_9C;
};

struct SystemManager {
    char pad00[0x28];
    Sub28 *m_sub28;
    char pad2C[0x1C8 - 0x2C];
    int m_mode;
    int m_field_1CC;
};

extern SystemManager *D_004E3180;

struct TargetSubVtable {
    char pad00[0x44];
    void (*func_44)(void *self, float a1, float a2);
};

struct TargetSubCA8 {
    TargetSubVtable *m_vtable;
    char pad04[0x44 - 0x04];
    float m_x;
    float m_y;
};

struct TargetObj {
    char pad00[0xC6C];
    float m_x;
    float m_y;
    char padC74[0xCA8 - 0xC74];
    TargetSubCA8 *m_sub_ca8;
};

struct ViewVtable {
    char pad00[0x28];
    void (*func_28)(void *self, int a1);
};

struct ViewObj {
    ViewVtable *m_vtable;
};

struct CombatSubsystemControllerInstance {
    ViewVtable *m_vtable;
    char pad04[0x90 - 0x04];
    int m_field_90;
    char pad94[0x130 - 0x94];
    TargetObj *m_target;
    char pad134[0x3408 - 0x134];
    ViewObj *m_child_3408;
    char pad340C[0x3428 - 0x340C];
    unsigned int m_time_3428;
    int m_lock_342C;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    void func_00329450(CombatSubsystemControllerInstance *self, int lock);
    void sub_0036ddf0(void *buf);
    unsigned int func_2261C0();
    int func_123350(float val);
    void func_204920(TargetObj *target, int flag, float x, float y);
    int func_003299F0(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_DRAG_H
