#include "sub_list.h"

extern "C" {
int func_00139EA0(SubList *self, void *other, float *out, float x, float y, float z);
float func_0013A090();
int func_0013A0A0(SubList *self, void *other, float *out, float x, float y, float z);
void func_0013A230(SubList *self, void *other);

int CallMethod14__8BaseListFv(void*);
void* func_366c30(void*);
void func_34fb10(void*, void*, void*, int, float);
void func_34fa60(void*, void*, float, float, float, int, float);
void func_147180(void*, int);
void func_1471b0(void*, int);
void func_14bd90(void*, int, int, float, float, float);
extern int D_4E35DC;
}

int func_00139EA0(SubList *self, void *other, float *out, float x, float y, float z) {
    *out = 0.0f;
    if (other == self) {
        return -1;
    }

    SpatialObj1 *s0 = (SpatialObj1*)self->m_field4->m_fieldC8->Method3(self, self->m_field4, other, -1, x, y, z, 0);
    if (!s0 && self->m_field4->m_fieldCE) {
        for (int i = 0; i < self->m_field8->m_count; i++) {
            NodeItem *item = self->m_field8->m_items[i];
            if (!item) {
                continue;
            }
            if (item->m_fieldE == self->m_field4->m_fieldE &&
                item->m_field0 == self->m_field4->m_field0 &&
                item->m_fieldCE == self->m_field4->m_fieldCE) {
                s0 = (SpatialObj1*)item->m_fieldC8->Method3(self, self->m_field4, other, -1, x, y, z, 0);
                if (s0) {
                    break;
                }
            }
        }
    }

    if (s0) {
        if (s0->type == 104) {
            short otherType = ((OtherObj*)other)->m_field4->m_fieldE;
            if ((otherType == 3 || otherType == 52) && self->m_field8->m_fieldBAC->m_scale <= 1.0f) {
                *out = 1.0f;
            } else {
                *out = self->GetRange();
            }
        } else {
            *out = s0->f24;
        }
        return s0->type;
    }

    return -1;
}

float func_0013A090() {
    return 0.0f;
}

int func_0013A0A0(SubList *self, void *other, float *out, float x, float y, float z) {
    if (other == self) {
        return 0;
    }

    if (CallMethod14__8BaseListFv(self->m_fieldCC)) {
        return 1;
    }

    void *s1 = func_366c30(&D_4E35DC);
    if (other) {
        if (s1) {
            func_34fb10(s1, self, other, 0, 0.0f);
        }
    } else if (s1) {
        func_34fa60(s1, self, x, y, z, 0, 0.0f);
    }

    if (self->m_fieldC8) {
        func_147180(*(void**)self->m_fieldC8, 0x2C6);
        func_1471b0(*(void**)self->m_fieldC8, 0x262);
        if (other) {
            func_14bd90(*(void**)self->m_fieldC8, ((OtherObj*)other)->m_field24_short, ((OtherObj*)other)->m_field4->m_fieldE, x, y, z);
        } else {
            func_14bd90(*(void**)self->m_fieldC8, -1, -1, x, y, z);
        }
    }

    if (s1) {
        self->v194(s1);
    }

    self->m_fieldC5++;
    return 0;
}

void func_0013A230(SubList *self, void *other) {
    if (other != self) {
        self->v190(other, 1, -1);
        self->m_fieldC5++;
    }
}
