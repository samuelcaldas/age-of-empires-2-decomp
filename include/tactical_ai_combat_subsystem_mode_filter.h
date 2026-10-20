#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_FILTER_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_FILTER_H

struct SystemSub28 {
    char pad00[0xA0];
    short m_state;
};

struct SystemManager {
    char pad00[0x28];
    SystemSub28 *m_sub28;
    char pad2C[0x1C8 - 0x2C];
    int m_mode;
    int m_subtype;
};

extern SystemManager *D_004E3180;

extern "C" {
    int func_185DC0(void *mgr, int flag);
    void func_1A5200(void *self, int a1, int a2);
    void func_1F6510(void *self);
    int func_003286C0(void *self, int a1, int a2);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_MODE_FILTER_H
