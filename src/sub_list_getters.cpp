#include "sub_list.h"

extern "C" {
    int func_123350(float val);
    void func_1378c0(void *obj, int a1, int a2);
}

Vec3 SubList::func_0013B360() {
    return this->m_field90;
}

float SubList::func_0013B380() {
    return this->m_field7C;
}

short SubList::func_0013B390() {
    return this->m_field8C_short;
}

int SubList::func_0013B3A0() {
    return this->m_fieldB4;
}

int SubList::func_0013B3B0() {
    return this->m_fieldC0;
}

Vec3 SubList::func_0013B3C0() {
    return this->m_field9C;
}

float SubList::func_0013B3E0() {
    return this->m_field68;
}

int SubList::func_0013B3F0() {
    return 0;
}

int SubList::func_0013B400() {
    return 0;
}

int SubList::func_0013B410() {
    return 0;
}

void SubList::func_0013B420(WorldContainer *world) {
    func_123350(this->m_field44);
    int y = func_123350(this->m_field48);
    func_1378c0(world->m_fieldB94, y, y);
}
