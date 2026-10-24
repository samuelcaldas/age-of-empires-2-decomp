#include "network_dplay_3380e0.h"

extern "C" int func_00338B90(void *self, int from_id, int to_id, int flags, const unsigned char *data, int size) {
    (void)flags;
    if (to_id == 0) {
        int i = 0;
        DPlayPlayerSlot *slot = reinterpret_cast<DPlayPlayerSlot *>(static_cast<char *>(self) + 4);
        for (; i < 8; i++, slot++) {
            int dest_id = slot->id;
            if (dest_id != 0 && dest_id != *static_cast<int *>(self)) {
                func_003383B0(self, dest_id, from_id, data, size);
            }
        }
    } else {
        func_003383B0(self, to_id, from_id, data, size);
    }
    return 0;
}
