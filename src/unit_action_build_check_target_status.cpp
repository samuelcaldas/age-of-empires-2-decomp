#pragma exceptions off
#include "unit_action_build_check_target_status.h"

typedef void* (*TargetCheckFn)(void *world, void *target_ba0);

int func_00271500(ActionRebind *self, int target_player_id) {
    void *master = self->m_field4;
    short fieldE = *(short*)((char*)master + 0xE);
    if (fieldE != 39) {
        return 0;
    }
    short field1A2 = *(short*)((char*)master + 0x1A2);
    if (field1A2 == -1) {
        return 0;
    }
    if (func_26AD20(self, 0x2000) != 0) {
        return 0;
    }

    void *actor = *(void**)((char*)self + 8);
    TargetCheckFn m1 = (TargetCheckFn)(*(void***)((char*)actor + 0x1B30))[9];
    if (!m1(actor, (void*)target_player_id)) {
        return 0;
    }

    void *world = *(void**)((char*)actor + 0xB98);
    void **players = *(void***)((char*)world + 0x54);
    void *target_player = players[target_player_id];
    void *actor_ba0 = *(void**)((char*)actor + 0xBA0);
    TargetCheckFn m2 = (TargetCheckFn)(*(void***)((char*)target_player + 0x1B30))[9];
    if (m2(target_player, actor_ba0)) {
        return 1;
    }
    return 0;
}
