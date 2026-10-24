#pragma exceptions off

#include "zone_spatial_entity_deserialize.h"

extern "C" {
void func_194F00(void *self, void *arg1, void *arg2);
void func_226D90(void *stream, void *dst, int size);
}

struct SpatialEntityState {
    char pad[0x100];
    int field_100;
    short field_104;
    char field_106;
    char field_107;
};

extern "C" int func_001D8550(SpatialEntityState *self, void *stream, void *arg2) {
    self->field_106 = 1;
    func_194F00(self, stream, arg2);

    func_226D90(stream, &self->field_100, 4);

    int temp_val;
    func_226D90(stream, &temp_val, 4);
    self->field_104 = (short)temp_val;

    func_226D90(stream, &self->field_107, 1);

    return 1;
}
