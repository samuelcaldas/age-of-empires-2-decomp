#pragma exceptions off
#include "sub_list.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

class TargetObj {
public:
    void *m_vtable;
    char pad_04[0x4];
    void *m_game;
};

struct TradeAction {
    void *m_vtable;
    char pad_04[0x34];
    TargetObj *m_target;
    char pad_3C[0xC];
    short m_field48;
    short m_field4A;
    char pad_4C[0x1C];
    short m_field68;
    char pad_6A[0x6];
    int m_field70;
};

extern "C" {

float func_149A00(TradeAction *self);
void* func_332e60(void *timer, short a1);

int func_00148FC0() {
    return 0;
}

int func_00148FD0() {
    return 0;
}

float func_00148FE0() {
    return 0.0f;
}

int func_00148040(TradeAction *self, Vector3 *pos, float f12, int a2, int a3,
                  int t0, int t1, unsigned char t2, unsigned char t3) {
    Vector3 local_pos = *pos;
    typedef void (*Method2C)(TradeAction *self, float x, float z, int a1);
    Method2C m2C = *(Method2C *)((char *)*(void **)self + 0x2C);
    m2C(self, local_pos.x, local_pos.z, 1);

    float f20 = func_149A00(self);
    void *s0 = 0;
    if (self->m_field4A != -1) {
        void *game = self->m_target->m_game;
        void *timer = *(void **)((char *)game + 0xB98);
        s0 = func_332e60(timer, self->m_field4A);
    }

    char buf[0x30];
    memset(buf, 0, sizeof(buf));

    return 0;
}

}
