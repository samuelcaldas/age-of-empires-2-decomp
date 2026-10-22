#include "network_dplay_3380e0.h"

extern "C" DPlayPlayerSlot *func_00338310(void *self, int player_id) {
    DPlayPlayerSlot *slot = reinterpret_cast<DPlayPlayerSlot *>(static_cast<char *>(self) + 4);
    for (int i = 0; i < 8; i++, slot++) {
        if (slot->id == player_id) {
            return slot;
        }
    }
    return 0;
}
