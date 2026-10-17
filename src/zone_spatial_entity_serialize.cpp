#pragma exceptions off

#include "zone_spatial_entity_serialize.h"

extern "C" {
void func_195000(void *self, void *stream);
void func_226F70(void *stream, const void *src, int size);
}

struct SpatialEntityState {
    char pad[0x100];
    int field_100;
    short field_104;
    char field_106;
    char field_107;
};

extern "C" void func_001D85E0(SpatialEntityState *self, void *stream) {
    func_195000(self, stream);

    func_226F70(stream, &self->field_100, 4);

    int temp_val = (int)self->field_104;
    func_226F70(stream, &temp_val, 4);

    func_226F70(stream, &self->field_107, 1);
}
