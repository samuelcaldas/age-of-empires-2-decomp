#include "tactical_ai_combat_subsystem_controller_destructor.h"

void *func_003292A0(CombatSubsystemControllerInstance *self, int flags) {
    if (self != 0) {
        self->m_vtable = D_004DED20;
        func_32E820(self);
        func_318760(self, 0);
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}
