#include "network_send_peers_338b90.h"

extern "C" {
int func_003383B0(void *object, const void *header, int header_size,
                  const void *payload, int size);
}

int func_00338B90(void *object, const void *header, int header_size,
                  const void *payload, int size, int peer_id) {
    char *base = (char *)object;
    if (peer_id != 0) {
        func_003383B0(object, header, header_size, payload, size);
        return 0;
    }
    int local_id = *(int *)base;
    char *slot = base + 4;
    for (int index = 0; index < 8; ++index) {
        int slot_id = *(int *)(slot + 4);
        if (slot_id != 0 && slot_id != local_id) {
            func_003383B0(object, header, header_size, payload, size);
        }
        slot += 136;
    }
    return 0;
}
