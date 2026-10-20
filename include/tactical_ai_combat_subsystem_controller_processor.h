#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PROCESSOR_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PROCESSOR_H

struct Sub28 {
    char pad00[0x80];
    int m_field_80;
    char pad84[0x88 - 0x84];
    int m_margin_88;
    char pad8C[0x90 - 0x8C];
    float m_max_speed_90;
    unsigned int m_duration_94;
};

struct SystemManager {
    char pad00[0x28];
    Sub28 *m_sub28;
    char pad2C[0x1C8 - 0x2C];
    int m_mode;
};

extern SystemManager *D_004E3180;

struct TargetObj {
    char pad00[0xC6C];
    float m_x;
    float m_y;
};

struct Obj20 {
    char pad00[0x04];
    void *m_field_4;
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
    char pad04[0x20 - 0x04];
    Obj20 *m_obj_20;
    char pad24[0x90 - 0x24];
    int m_field_90;
    char pad94[0x130 - 0x94];
    TargetObj *m_target;
    char pad134[0x190 - 0x134];
    unsigned char m_field_190;
    char pad191[0x3408 - 0x191];
    ViewObj *m_child_3408;
    unsigned int m_time_340C;
    int m_mode_3410;
    char pad3414[0x342C - 0x3414];
    int m_lock_342C;
};

extern "C" {
    int func_185DC0(SystemManager *mgr);
    int func_1F26F0(void *ptr);
    void *func_1F26D0(void *ptr);
    void func_00329350(CombatSubsystemControllerInstance *self, int mode);
    void func_2254D0(void *ptr, void *rect_out);
    void func_225560(void *pos_out);
    int func_225520(int axis);
    unsigned int func_2261C0();
    int func_123350(float val);
    void func_204920(TargetObj *target, int flag, float x, float y);
    int func_00329550(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PROCESSOR_H
