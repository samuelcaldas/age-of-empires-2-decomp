#pragma exceptions off
#include "trade_action_target_management.h"

int func_001512A0(TradeAction *self) {
    if (!self->m_route_obj) {
        return 0;
    }

    self->m_target->Method488();

    RouteObj *route = self->m_route_obj;
    int count = route->m_count;
    Vector3 pos1;
    Vector3 pos2;
    Vector3 pos3;

    for (int i = 0; i < count; i++) {
        func_1fd4e0(&pos1, self->m_route_obj, i);
        func_1fd4e0(&pos2, self->m_route_obj, i);
        func_1fd4e0(&pos3, self->m_route_obj, i);
        self->m_target->Method484(pos1.x, pos2.y, pos3.z);
    }

    Vector3 final_pos1;
    Vector3 final_pos2;
    Vector3 final_pos3;
    func_1fd4e0(&final_pos1, route, count - 1);
    func_1fd4e0(&final_pos2, self->m_route_obj, count - 1);
    func_1fd4e0(&final_pos3, self->m_route_obj, count - 1);
    self->m_target->Method484(final_pos1.x, final_pos2.y, final_pos3.z);

    return 1;
}

int func_001513E0(void *self) {
    return 0;
}

void func_001513F0(void *self) {
}

int func_00151400(TradeAction *self) {
    if (self->m_route_obj) {
        if (self->m_route_obj->m_flags & *(int*)0x00491024) {
            return 1;
        }
    }
    return 0;
}

void func_00151440(TradeAction *self) {
    if (self->m_route_obj) {
        func_1FC810(self->m_route_obj);
        self->m_route_obj = 0;
    }
    self->m_field168 = 0;
}

int func_00151480(TradeAction *self, short a1, short a2, Vector3 *p1, short t0, Vector3 *p2) {
    Vector3 v1 = *p1;
    Vector3 v0 = *p2;

    if (t0 < 0) {
        return 0;
    }

    void *game = self->m_target->m_game;
    void *timer = *(void**)((char*)game + 2968);
    void *entity = func_332e60(timer, t0);
    if (!entity) {
        return 0;
    }

    self->m_field68 = -1;
    self->m_field6A = -1;
    self->m_field70 = 0;
    self->m_field74 = 0;
    self->m_field78 = 0;
    self->m_field7C = 0;
    self->m_field6C = -1;
    self->m_field6E = 255;
    self->m_field80 = 0;
    self->m_field84 = 0;
    self->m_field88 = 0;
    self->m_field68 = a1;
    self->m_field6A = a2;

    void *world = *(void**)((char*)timer + 24);
    func_00145E30(world, &v1, &v0);

    return 1;
}
