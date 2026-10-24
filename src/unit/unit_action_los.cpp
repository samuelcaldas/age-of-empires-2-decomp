#pragma exceptions off
#include "unit_action_los.h"

void func_00268A60(ActionRebind *self, void *world, int flag, int radius_override, int arg4) {
    if (world == 0) {
        return;
    }

    void *field4 = self->m_field4;
    if (*(short*)((char*)field4 + 8) == 0x70) {
        flag = 0;
    }

    int radius = radius_override;
    if (radius_override == -1) {
        radius = func_123350(*(float*)((char*)field4 + 0x1C));
    }

    if (radius <= 0) {
        return;
    }

    void *map = *(void**)((char*)world + 0xB98);
    int flag_val = (unsigned char)flag;
    void *zone = *(void**)((char*)world + 0xB94);
    int val_ba0 = *(int*)((char*)world + 0xBA0);
    short map_98 = *(short*)((char*)map + 0x98);
    int diff = (val_ba0 ^ map_98) == 0;

    if (flag_val == 0) {
        int tile_x = func_123350(self->m_x);
        int tile_y = func_123350(self->m_y);
        short field24 = self->m_field24;
        func_00137AA0(zone, tile_x, tile_y, radius, arg4, diff, field24);
    } else {
        float f21 = *(float*)((char*)field4 + 0x20);
        if (f21 <= 0.0f) {
            return;
        }
        float f20 = *(float*)((char*)field4 + 0x24);
        if (f20 <= 0.0f) {
            return;
        }

        float x = self->m_x;
        float y = self->m_y;
        int min_x = func_123350(x - f21);
        int min_y = func_123350(y - f20);
        int max_x = func_123350(x + f21 - 0.01f);
        int max_y = func_123350(y + f20 - 0.01f);
        short field24 = self->m_field24;
        func_00138040(zone, min_x, min_y, max_x, max_y, diff, field24);
    }
}

void func_00268C30(ActionRebind *self, void *world, int flag, int radius_override, int arg4) {
    if (world == 0) {
        return;
    }

    void *field4 = self->m_field4;
    if (*(short*)((char*)field4 + 8) == 0x70) {
        flag = 0;
    }

    int radius = radius_override;
    if (radius_override == -1) {
        radius = func_123350(*(float*)((char*)field4 + 0x1C));
    }

    if (radius <= 0) {
        return;
    }

    void *map = *(void**)((char*)world + 0xB98);
    int flag_val = (unsigned char)flag;
    void *zone = *(void**)((char*)world + 0xB94);
    int val_ba0 = *(int*)((char*)world + 0xBA0);
    short map_98 = *(short*)((char*)map + 0x98);
    int diff = (val_ba0 ^ map_98) == 0;

    if (flag_val == 0) {
        int tile_x = func_123350(self->m_x);
        int tile_y = func_123350(self->m_y);
        short field24 = self->m_field24;
        func_00137EA0(zone, tile_x, tile_y, radius, arg4, diff, field24);
    } else {
        float f21 = *(float*)((char*)field4 + 0x20);
        if (f21 <= 0.0f) {
            return;
        }
        float f20 = *(float*)((char*)field4 + 0x24);
        if (f20 <= 0.0f) {
            return;
        }

        float x = self->m_x;
        float y = self->m_y;
        int min_x = func_123350(x - f21);
        int min_y = func_123350(y - f20);
        int max_x = func_123350(x + f21 - 0.01f);
        int max_y = func_123350(y + f20 - 0.01f);
        short field24 = self->m_field24;
        func_00138320(zone, min_x, min_y, max_x, max_y, diff, field24);
    }
}
