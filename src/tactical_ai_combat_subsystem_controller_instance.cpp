#include "tactical_ai_combat_subsystem_controller_instance.h"

static inline void init_controller_flags(CombatSubsystemControllerInstance *self) {
    self->m_field_DC = 10;
    self->m_field_3408 = 0;
    self->m_field_340C = 0;
    self->m_field_3410 = 0;
    self->m_field_3414 = -1;
    self->m_field_3418 = -1;
    self->m_field_3428 = 0;
    self->m_field_342C = 0;
    self->m_field_341C = 1;
    self->m_field_3420 = 0;
    self->m_field_3424 = 0;
    self->m_field_3430 = 0;
}

static inline void init_controller_tables(CombatSubsystemControllerInstance *self) {
    for (int i = 0; i < 10; ++i) {
        self->m_field_3434[i] = 0;
        self->m_field_345C[i] = -1;
    }
    self->m_field_3484 = 0;
    self->m_field_2398 = 41;
}

CombatSubsystemControllerInstance *func_003291F0(CombatSubsystemControllerInstance *self) {
    func_318340(self);
    self->m_vtable = D_004DED20;
    init_controller_flags(self);
    init_controller_tables(self);
    return self;
}
