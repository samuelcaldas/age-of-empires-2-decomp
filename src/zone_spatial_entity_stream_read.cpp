#pragma exceptions off

#include "zone_spatial_entity_stream_read.h"

extern "C" {
void func_226D90(void *stream, void *buf, int size);
}

struct SpatialEntity {
    char pad[0x70];
    float f70;
    float f74;
    float f78;
    float f7C;
};

extern "C" void func_001DBB90(SpatialEntity *self, void *stream) {
    func_226D90(stream, &self->f70, 0x10);
}
