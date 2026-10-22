#include "network_dplay_3380e0.h"

extern "C" int func_00338970(void *self, int player_id, void *out_name, int *size_ptr) {
    if (!out_name) {
        *size_ptr = 16;
        return 0;
    }
    int *out = static_cast<int *>(out_name);
    DPlayPlayerSlot *slot = func_00338310(self, player_id);
    if (!slot) {
        return static_cast<int>(0x88770096u);
    }
    if (static_cast<unsigned int>(*size_ptr) < 16u) {
        return static_cast<int>(0x8877001Eu);
    }
    out[0] = 16;
    out[1] = 0;
    *reinterpret_cast<char **>(out + 2) = reinterpret_cast<char *>(slot) + 24;
    *reinterpret_cast<char **>(out + 3) = reinterpret_cast<char *>(slot) + 40;
    return 0;
}
