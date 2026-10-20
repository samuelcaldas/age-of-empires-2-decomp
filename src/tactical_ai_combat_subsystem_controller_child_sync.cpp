#include "tactical_ai_combat_subsystem_controller_child_sync.h"

int func_0032C420(CombatSubsystemControllerInstance *self) {
    if (func_00323B50(self) == 0) {
        return 0;
    }
    ViewObj *view = self->m_view;
    if (view != 0) {
        view->m_vtable->func_28(view, 1);
    }
    return 1;
}
