#include "network_dplay_3380e0.h"

extern "C" {
    void func_117AF8(void *dst, const void *src, int size);
}

extern "C" int func_003390D0(void *self, int player_id, void *caps, int flags) {
    (void)flags;
    DPlayPlayerSlot *slot = func_00338310(self, player_id);
    if (!slot) {
        return static_cast<int>(0x88770096u);
    }
    func_117AF8(caps, reinterpret_cast<char *>(slot) + 72, 40);
    int *out = static_cast<int *>(caps);
    out[1] = 64;
    out[9] = 6000;
    out[4] = 8;
    return 0;
}
