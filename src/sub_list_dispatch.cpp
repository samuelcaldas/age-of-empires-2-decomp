#include "sub_list.h"

extern "C" {
    void func_147180(void *obj, short s0);
    void func_1471b0(void *obj, short s1);
    void func_14bd90(void *obj, short id1, short id2, float x, float y, float z);
    void func_151490(void *obj, short s0, short s1, Vec3 *v1, short target_id, Vec3 *v2);
    void func_14bef0(void *obj);
}

void SubList::func_0013B0B0(short action_id, SubList *other, float x, float y, float z) {
    if (!this->m_fieldC8) {
        return;
    }
    short s0 = -1;
    short s1 = -1;
    switch (action_id) {
    case 0x6A: s1 = 0x26A; s0 = 0x2CE; break;
    case 0x69: s1 = 0x25B; s0 = 0x2BF; break;
    case 0x68: s1 = 0x25C; s0 = 0x2C0; break;
    case 0x6F: s1 = 0x267; s0 = 0x2CB; break;
    case 0x0C: s1 = 0x266; s0 = 0x2CA; break;
    case 0x6E: s1 = 0x265; s0 = 0x2C9; break;
    case 0x01: s1 = 0x262; s0 = 0x2C6; break;
    case 0x05: s1 = 0x261; s0 = 0x2C5; break;
    case 0x04: s1 = 0x25D; s0 = 0x2C1; break;
    case 0x03: s1 = 0x269; s0 = 0x2CD; break;
    case 0x65: s1 = 0x25A; s0 = 0x2BE; break;
    case 0x09: s1 = 0x258; s0 = 0x2BC; break;
    }
    void *c8 = *(void**)this->m_fieldC8;
    func_147180(c8, s0);
    func_1471b0(c8, s1);
    if (other) {
        func_14bd90(c8, other->m_field24_short, other->m_field4->m_fieldE, x, y, z);
        Vec3 v1 = this->v136();
        Vec3 v2 = other->v136();
        func_151490(c8, s0, s1, &v1, other->m_field24_short, &v2);
    } else {
        func_14bd90(c8, -1, -1, x, y, z);
        Vec3 pos;
        pos.x = x;
        pos.y = z;
        pos.z = y;
        Vec3 v1 = this->v136();
        func_151490(c8, s0, s1, &v1, -1, &pos);
    }
    func_14bef0(c8);
}
