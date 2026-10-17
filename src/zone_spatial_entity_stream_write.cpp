#pragma exceptions off

#include "zone_spatial_entity_stream_write.h"

extern "C" {
void func_226F70(void *stream, const void *buf, int size);
}

struct SpatialEntity {
    char pad[0x70];
    float f70;
    float f74;
    float f78;
    float f7C;
};

extern "C" void func_001DBC70(SpatialEntity *self, void *stream) {
    func_226F70(stream, &self->f70, 0x10);
}
