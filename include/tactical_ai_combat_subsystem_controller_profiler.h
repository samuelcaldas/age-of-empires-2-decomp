#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PROFILER_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PROFILER_H

struct SystemManager;
extern SystemManager *D_004E3180;

extern "C" {
    unsigned int func_2261C0();
    int func_1F60F0(void *a0, void *a1, void *a2, void *a3, void *t0, void *t1);
    void func_184B60(SystemManager *mgr, int channel, unsigned int delta);
    int func_00329F00(void *a0, void *a1, void *a2, void *a3, void *t0, void *t1);
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_PROFILER_H
