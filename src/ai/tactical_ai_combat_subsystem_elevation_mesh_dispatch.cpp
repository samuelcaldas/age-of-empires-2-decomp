#include "tactical_ai_combat_subsystem_elevation_mesh_dispatch.h"

int func_00328610(void *self, int a1, int a2, int a3, int a4, int a5) {
    int s_78;
    short s_7C;
    short s_7E;

    if (!func_1A5010(self, a2, a3, &s_7C, &s_7E, &s_78)) {
        return 0;
    }

    return func_1F5C80(self, a1, a2, a3, a4, a5);
}
