#pragma exceptions off

#include "render_manager_status.h"

extern "C" {

#define LOG_AND_RETURN(line) do { \
    D_004E3180->LogError((line), D_568560, 32); \
    return D_568560; \
} while (0)

const char *func_00189c80(void *self, int arg1) {
    if (func_00191050(self, arg1)) {
        LOG_AND_RETURN(1201);
    }
    if (!func_00190FF0(self, arg1)) {
        LOG_AND_RETURN(1202);
    }
    int type = *(int *)((char *)(arg1 * 4) + (int)self + 0x2038);
    if ((unsigned int)type < 4) {
        LOG_AND_RETURN(1203);
    }
    unsigned int limit = *(unsigned int *)((char *)self + 0x10C8);
    if ((unsigned int)type < limit) {
        LOG_AND_RETURN(1204);
    }
    if ((unsigned int)type >= limit) {
        LOG_AND_RETURN(1200);
    }
    func_11A498(D_568560, D_491BA8);
    return D_568560;
}

}
