#include "network_dplay_3380e0.h"

extern "C" int func_00338A10(void *self, int player_id, int *out_count, int flags) {
    (void)player_id;
    (void)flags;
    *out_count = *reinterpret_cast<int *>( static_cast<char *>(self) + 3372 );
    return 0;
}
