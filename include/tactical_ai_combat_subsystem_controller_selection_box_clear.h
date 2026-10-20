#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_SELECTION_BOX_CLEAR_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_SELECTION_BOX_CLEAR_H

class CombatSubsystemControllerInstance {
public:
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14();
    virtual void func_18();
    virtual void func_1C();
    virtual void func_28(int a1);
};

inline void CombatSubsystemControllerInstance::func_00() {}
inline void CombatSubsystemControllerInstance::func_04() {}
inline void CombatSubsystemControllerInstance::func_08() {}
inline void CombatSubsystemControllerInstance::func_0C() {}
inline void CombatSubsystemControllerInstance::func_10() {}
inline void CombatSubsystemControllerInstance::func_14() {}
inline void CombatSubsystemControllerInstance::func_18() {}
inline void CombatSubsystemControllerInstance::func_1C() {}
inline void CombatSubsystemControllerInstance::func_28(int) {}

extern "C" {
    void sub_31A720(void *self, int a1, int a2, int a3, int t0);
    int func_0032E460(CombatSubsystemControllerInstance *self);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_SELECTION_BOX_CLEAR_H
