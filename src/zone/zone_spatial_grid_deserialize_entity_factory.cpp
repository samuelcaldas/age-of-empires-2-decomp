#pragma exceptions off
#include "zone_spatial_grid_deserialize_entity_factory.h"

extern "C" {
void *func_00367230(int type);
int func_3671F0(void *entity);
}

struct Entity {
    virtual void v0();
    virtual void v1();
    virtual void deserialize(void *stream, void *p3, int flag);
};

extern "C" void func_001EBCD0(void *self, int type, void *stream, void *p3) {
    switch ((unsigned char)type) {
    case 0x19: {
        Entity *ent = (Entity *)func_00367230(type);
        if (ent != 0) {
            ent->deserialize(stream, p3, 1);
        }
        break;
    }
    case 0x3C: {
        Entity *ent = (Entity *)func_00367230(type);
        if (ent != 0) {
            ent->deserialize(stream, p3, 1);
        }
        break;
    }
    case 0x0A: {
        Entity *ent = (Entity *)func_00367230(type);
        if (ent != 0) {
            if (func_3671F0(ent) != 0) {
                ent->deserialize(stream, p3, 1);
            } else {
                ent->deserialize(stream, p3, 1);
            }
        }
        break;
    }
    case 0x14:
    case 0x1E:
    case 0x28:
    case 0x32:
    case 0x46:
    case 0x50: {
        Entity *ent = (Entity *)func_00367230(type);
        if (ent != 0) {
            ent->deserialize(stream, p3, 1);
        }
        break;
    }
    }
}
