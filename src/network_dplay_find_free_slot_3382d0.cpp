#include "network_dplay_3380e0.h"

extern "C" DPlayPlayerSlot *func_003382D0(void *self, int unused) {
    (void)unused;
    DPlayPlayerSlot *slot = reinterpret_cast<DPlayPlayerSlot *>(static_cast<char *>(self) + 4);
    for (int i = 0; i < 8; i++, slot++) {
        if (slot->id == 0) {
            return slot;
        }
    }
    return 0;
}
