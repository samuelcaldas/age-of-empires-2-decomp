#pragma exceptions off
#include "unit_action_build_retry.h"

struct ZoneStubLayout {
    char pad[0x8ECD];
    unsigned char f_8ECD;
    unsigned char f_8ECE;
};

void func_00270A20(ActionRebind *self, int status) {
    if (*(int*)((char*)D_004E3180 + 0x1C8) == 7) {
        if (*(short*)((char*)self->m_field4 + 8) != 50) {
            return;
        }
    }

    void *actor = self->m_world;
    void *world = *(void**)((char*)actor + 0xB98);
    short player_id = *(short*)((char*)world + 0x98);
    void **player_array = *(void***)((char*)world + 0x54);
    void *player = player_array[player_id];

    if ((unsigned char)status == 8) {
        if (player != actor) {
            status = 27;
        }
    }

    int flag = 0;
    if (player == actor || (unsigned char)status == 1 || (unsigned char)status == 28 || (unsigned char)status == 14) {
        flag = 15;
    }
    if (flag == 0) {
        int tile_x = func_123350(self->m_x);
        int tile_y = func_123350(self->m_y);
        void *map_zone = *(void**)((char*)player + 0xB94);
        flag = (unsigned char)func_1378c0(map_zone, tile_x, tile_y);

        if (flag != 15) {
            void *player_world = *(void**)((char*)player + 0xB98);
            ZoneStubLayout *zone = *(ZoneStubLayout**)((char*)player_world + 0x3C);
            unsigned char f_8ECE = zone->f_8ECE;
            unsigned char f_8ECD = zone->f_8ECD;

            if (f_8ECD != 0 && f_8ECE == 0) {
                flag = 15;
            }
            if (f_8ECE == 0 && flag == 0x80) {
                flag = 15;
            }
        }
    }

    if ((unsigned char)flag == 15) {
        func_270BA0(self, status);
        return;
    }

    *(char*)((char*)self + 0x15A) = (char)status;
}
