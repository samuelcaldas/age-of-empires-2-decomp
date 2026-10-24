#include "network_dplay_3380e0.h"

struct DPlaySendObject {
    char pad[3388];
    int from_id;
    int to_id;
    int checksum;
    int size;
    char payload[1008];
};

extern "C" {
    extern const char D_004D2110[];
    void func_117AF8(void *dst, const void *src, int size);
    int func_00337840(const void *payload, int size);
    int func_118de0(const char *fmt, ...);
}

extern "C" int func_003383B0(void *self, int from_id, int to_id, const unsigned char *payload, int size) {
    DPlaySendObject *obj = static_cast<DPlaySendObject *>(self);
    int *pkt = &obj->from_id;
    if ((unsigned int)(size + 16) > 1024) {
        return 0;
    }
    pkt[0] = from_id;
    pkt[1] = to_id;
    pkt[3] = size;
    pkt[2] = 0;
    for (unsigned int i = 0; i < (unsigned int)size; i++) {
        pkt[2] += payload[i];
    }
    func_117AF8(pkt + 4, payload, size);
    int res = func_00337840(&obj->from_id, size + 16);
    if (res < 0) {
        func_118de0(D_004D2110, res);
    }
    return res;
}
