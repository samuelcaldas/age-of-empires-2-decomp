#include "tactical_ai_combat_subsystem_controller_entity_bind.h"

int func_0032E4B0(CombatSubsystemControllerInstance *self, int x, int y, char *out_name, int a4) {
    char buf[64];
    int pick_res = func_0032D400(self, 41, 2, x, y, buf, 0, 1);

    if ((pick_res & 0xFF) == 52) {
        void **entity_ptr_slot = (void**)(buf + 12);
        void *entity = 0;
        if (entity_ptr_slot != 0 && *entity_ptr_slot != 0) {
            void **deref = (void**)*entity_ptr_slot;
            entity = deref[1];
        }

        void *handle = sub_1C8C00(entity);
        char *str = sub_1F6EA0(self, handle);
        if (out_name != 0 && str != 0) {
            strcpy(out_name, str);
        }
        sub_1C8C10(entity);

        return 1;
    }

    return sub_1F6EF0(self, x, y, out_name, a4);
}
