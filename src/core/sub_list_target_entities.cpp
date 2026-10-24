#include "sub_list.h"

extern "C" {
    void* func_332e60(void *mgr, int id);
}

extern "C" {

TargetEntity* func_0013C470(SubList *self) {
    if (self->m_field18 >= 0) {
        void *world = *(void**)((char*)self->m_field8 + 8);
        void *mgr = *(void**)((char*)world + 0xB98);
        return (TargetEntity*)func_332e60(mgr, self->m_field18);
    }
    return 0;
}

TargetEntity* func_0013C4B0(SubList *self) {
    if (self->m_field1C >= 0) {
        void *world = *(void**)((char*)self->m_field8 + 8);
        void *mgr = *(void**)((char*)world + 0xB98);
        return (TargetEntity*)func_332e60(mgr, self->m_field1C);
    }
    return 0;
}

}
