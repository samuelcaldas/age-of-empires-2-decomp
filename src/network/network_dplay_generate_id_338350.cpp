#include "network_dplay_3380e0.h"

struct DPlayPlayerList {
    int pad;
    DPlayPlayerSlot slots[8];
};

extern "C" {
    int func_1AAB30(void);
}

extern "C" int func_00338350(void *self) {
    DPlayPlayerSlot *slot;
    DPlayPlayerList *list = static_cast<DPlayPlayerList *>(self);
    int id;
    int i;
retry:
    slot = list->slots;
    id = func_1AAB30();
    if (id == 0) {
        goto retry;
    }
    for (i = 0; i < 8; i++, slot++) {
        if (slot->id == id) {
            goto retry;
        }
    }
    return id;
}
