#pragma exceptions off
#include "tactical_ai_waypoint_step.h"

static inline void RenderWaypoint(WaypointActionManager *self, unsigned char idx) {
    void *v0 = func_186010(D_004E3180);
    func_204920(v0, 0, self->m_array4[idx], self->m_array5[idx]);

    int v0_idx = (unsigned char)self->m_field1B2;
    void *s2 = func_186010(D_004E3180);
    int tx = func_123350(self->m_array4[v0_idx]);
    int ty = func_123350(self->m_array5[v0_idx]);
    func_204910(s2, tx, ty);
}

void func_00307A00(WaypointActionManager *self) {
    unsigned char idx = self->m_field1B2;
    if (self->m_array1[idx]) {
        RenderWaypoint(self, idx);
    } else {
        if (self->m_field1D0 == -1) {
            return;
        }
        self->m_field1B2 = (unsigned char)self->m_field1D0;
        idx = self->m_field1B2;
        if (self->m_array1[idx]) {
            RenderWaypoint(self, idx);
        }
    }

    self->m_field1B2--;
    if (self->m_field1B2 >= 128) {
        if (self->m_field1B3) {
            self->m_field1B2 = 4;
        } else {
            self->m_field1B2 = (unsigned char)self->m_field1D0;
        }
    }
}
