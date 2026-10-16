#pragma exceptions off
#include "tactical_ai_action_waypoints.h"

void func_003074B0(WaypointActionManager *self, Waypoint *wp) {
    if (!wp) return;

    if (self->m_field1D0 != -1) {
        int idx = self->m_field1D0;
        if (self->m_array1[idx] == 1 && self->m_array3[idx] == wp->m_id) {
            int v0 = func_2261c0();
            int v1 = self->m_field1D0;
            self->m_array2[v1] = v0;

            float x = wp->x;
            self->m_array4[self->m_field1D0] = x;
            self->m_floatX = x;

            float y = wp->y;
            self->m_array5[self->m_field1D0] = y;
            self->m_floatY = y;

            float z = wp->z;
            self->m_array6[self->m_field1D0] = z;
            self->m_floatZ = z;

            self->m_field1B2 = (unsigned char)self->m_field1D0;
            return;
        }
    }

    int idx = self->m_field1B1;
    float x = wp->x;
    self->m_array4[idx] = x;
    self->m_floatX = x;

    idx = self->m_field1B1;
    float y = wp->y;
    self->m_array5[idx] = y;
    self->m_floatY = y;

    idx = self->m_field1B1;
    float z = wp->z;
    self->m_array6[idx] = z;
    self->m_floatZ = z;

    int v0 = func_2261c0();

    idx = self->m_field1B1;
    self->m_array2[idx] = v0;

    idx = self->m_field1B1;
    self->m_array3[idx] = wp->m_id;

    idx = self->m_field1B1;
    self->m_array1[idx] = 1;

    idx = self->m_field1B1;
    self->m_field1B2 = idx;

    idx = self->m_field1B1;
    self->m_field1D0 = idx;

    idx = self->m_field1B1;
    self->m_field1B1 = idx + 1;

    idx = self->m_field1B1;
    if (idx >= 5) {
        self->m_field1B3 = 1;
        self->m_field1B1 = 0;
    }
}
