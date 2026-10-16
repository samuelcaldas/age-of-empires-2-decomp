#pragma exceptions off
#include "unit_action_resolve.h"

int func_002699A0(ActionRebind *self, int arg1, float *out_x, float *out_y, void *child_f4, ActionRebind *child, float coord_x, float coord_y, float ext_x, float ext_y) {
    float c_ext_x = *(float*)((char*)child_f4 + 0x20);
    float c_ext_y = *(float*)((char*)child_f4 + 0x24);
    float delta_x = 2.0f * ext_x;
    float delta_y = 2.0f * ext_y;

    float step_x = ext_x + c_ext_x + 0.01f;
    float step_y = ext_y + c_ext_y + 0.01f;

    float right_x = coord_x + step_x;
    float left_x = coord_x - step_x;
    float top_y = coord_y + step_y;
    float bottom_y = coord_y - step_y;

    for (int attempt = 0; attempt < 50; ++attempt) {
        int side = ((unsigned int)func_001AAB30() * 4) / 0x7FFF;

        if (side == 0) {
            *out_x = right_x;
            float offset = ((float)(long)func_001AAB30() * delta_y) / 32767.0f - ext_y;
            *out_y = coord_y + offset;
        } else if (side == 1) {
            *out_x = left_x;
            float offset = ((float)(long)func_001AAB30() * delta_y) / 32767.0f - ext_y;
            *out_y = coord_y + offset;
        } else if (side == 2) {
            *out_y = top_y;
            float offset = ((float)(long)func_001AAB30() * delta_x) / 32767.0f - ext_x;
            *out_x = coord_x + offset;
        } else if (side == 3) {
            *out_y = bottom_y;
            float offset = ((float)(long)func_001AAB30() * delta_x) / 32767.0f - ext_x;
            *out_x = coord_x + offset;
        }

        if (*out_x < 0.0f || *out_y < 0.0f) {
            continue;
        }

        void *map_zone = *(void**)((char*)*(void**)((char*)self->m_world + 0xB98) + 0x3C);
        float map_w = (float)*(int*)((char*)map_zone + 0x8);
        float map_h = (float)*(int*)((char*)map_zone + 0xC);
        if (*out_x >= map_w || *out_y >= map_h) {
            continue;
        }

        if (arg1 != -1) {
            int tile_x = func_123350(*out_x);
            int tile_y = func_123350(*out_y);
            unsigned char res = func_00269E50(self, tile_x, tile_y);
            if ((int)res != arg1) {
                if (func_00269F30(self, (int)res, (int)(unsigned char)arg1) == 0) {
                    continue;
                }
            }
        }

        void *sub = *(void**)((char*)child_f4 + 0xA0);
        typedef int (*Method3CFn)(void *child_f4, void *world, float x, float y,
                                  int a2, int a3, int t0, int t1, int t2, int t3,
                                  int stack0, int stack8, int stack16, void *stack24_self);
        Method3CFn m3c = *(Method3CFn*)((char*)sub + 0x3C);
        int obs = m3c(child_f4, self->m_world, *out_x, *out_y, 0, 1, 1, 1, 0, 1, 1, 0, 0, self);
        if ((obs & 0xFF) != 0) {
            continue;
        }

        typedef int (*Method75Fn)(void *child_obj, float x, float y);
        void **vtable = *(void***)child;
        Method75Fn m75 = (Method75Fn)vtable[75];
        if (m75(child, *out_x, *out_y) != 0) {
            return 1;
        }
    }

    return 0;
}
