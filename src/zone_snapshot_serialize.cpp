#pragma once
#pragma exceptions off

#include "zone_snapshot_serialize.h"

extern "C" {
void *func_1143F8(int pool, int size);
void *func_117AF8(void *dst, void *src, int size);
int func_226F70(void *stream, void *src, int size);
void func_229940(void *sub, void *stream);
void func_116F68(void *ptr);
}

struct EntityRef {
    char pad_0[8];
    short id;               // 0x8
};

struct ZoneLayout {
    char pad_0[0x8EE4];     // 0x0..0x8EE3
    void *f_8EE4;           // 0x8EE4 (-0x711C)
};

extern "C" void func_001CDBB0(void *self, void *stream) {
    char *snapshot = (char *)func_1143F8(1, 0x9158);
    func_117AF8(snapshot, self, 0x9158);

    for (int i = 0; i < 32; i++) {
        int offset = i * 416;
        char *src_entry = (char *)self + offset;
        char *dst_entry = snapshot + offset;

        if (*(unsigned char *)(src_entry + 0x8C) != 0) {
            EntityRef *entity = *(EntityRef **)(src_entry + 0xB0);
            if (entity != 0) {
                *(int *)(dst_entry + 0xB0) = (int)entity->id;
            } else {
                *(int *)(dst_entry + 0xB0) = -1;
            }
        }
    }

    for (int j = 0; j < 16; j++) {
        int offset = j * 1440;
        char *src_entry = (char *)self + offset;
        char *dst_entry = snapshot + offset;

        EntityRef *entity = *(EntityRef **)(src_entry + 0x34B0);
        if (entity != 0) {
            if (*(unsigned char *)(dst_entry + 0x348C) != 0) {
                *(int *)(dst_entry + 0x34B0) = (int)entity->id;
            } else {
                *(int *)(dst_entry + 0x34B0) = -1;
            }
        }
    }

    func_226F70(stream, snapshot, 0x9158);

    ZoneLayout *zm = (ZoneLayout *)self;
    func_229940(zm->f_8EE4, stream);

    func_116F68(snapshot);
}
