#include "tactical_ai_combat_subsystem_controller_render_profiler.h"

void func_0032C500(CombatSubsystemControllerInstance *self) {
    int start_time = func_2261C0();
    int start_metric = func_184BF0(D_004E3180, 11);

    if (self->m_field_12C == 0 || self->m_target == 0) {
        self->m_vtable->func_30(self, 0);
        func_1ABD90(self->m_field_20, &self->m_field_24, self->m_field_10B);
        self->m_vtable->func_34(self);
    } else {
        func_31AAB0(self);
    }

    int end_metric = func_184BF0(D_004E3180, 11);
    int end_time = func_2261C0();
    int metric_delta = end_metric - start_metric;
    int elapsed_time = end_time - start_time;

    func_184B60(D_004E3180, 6, elapsed_time - metric_delta);
    func_184BB0(D_004E3180);
    func_184B60(D_004E3180, 12, metric_delta);
}
