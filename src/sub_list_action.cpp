#include "sub_list.h"

extern "C" {
void func_0013A280(SubList *self, void *other, int a2, int mode, float x, float y, float z);
void func_0013A6A0(SubList *self);
void func_0013A6C0();
void func_0013A6D0(SubList *self);
void func_0013A6F0();

int CallMethod15__8BaseListFv(void *list, void *other, float x, float y, float z);
}

struct VBaseList {
    virtual void* v0();
    virtual void* v1();
    virtual void* CreateItem(void *s0, void *other, float x, float y, float z);
};

struct SpatialObjV8 {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual int v8();
};

void func_0013A280(SubList *self, void *other, int a2, int mode, float x, float y, float z) {
    if (other == self) {
        return;
    }

    SpatialObj1 *s0 = (SpatialObj1*)self->m_field4->m_fieldC8->Method3(self, self->m_field4, other, x, y, z, mode, 0);
    NodeItem *item;
    int i;
    SpatialObj1 *s3;
    if (!s0 || s0->type == 7) {
        s3 = s0;
        if (self->m_field4->m_fieldCE) {
            for (i = 0; i < self->m_field8->m_count; i++) {
                item = self->m_field8->m_items[i];
                if (!item) {
                    continue;
                }
                if (item->m_fieldE == self->m_field4->m_fieldE &&
                    item->m_field0 == self->m_field4->m_field0 &&
                    item->m_fieldCE == self->m_field4->m_fieldCE) {
                    s0 = (SpatialObj1*)item->m_fieldC8->Method3(self, self->m_field4, other, x, y, z, mode, 0);
                    if (s0) {
                        if (!s3 || s3->type != s0->type) {
                            self->v24(item);
                            break;
                        }
                    }
                }
            }
        }
        if (!s0) {
            s0 = s3;
        }
    }

    if (!s0 && (short)mode != -1) {
        return;
    }

    int headField30 = self->m_fieldCC->GetHeadItemField30();
    int s1 = 0;
    if (headField30 && (int)s0 == headField30) {
        if (CallMethod15__8BaseListFv(self->m_fieldCC, other, x, y, z)) {
            ListItem *head = (ListItem*)self->m_fieldCC->GetHeadItem();
            self->v197(head->v8(), other, x, y, z);
            s1 = 1;
        }
    }

    if (self->m_fieldCC->HasItems()) {
        ListItem *head = (ListItem*)self->m_fieldCC->GetHeadItem();
        if (head->v21() == other) {
            ListItem *head2 = (ListItem*)self->m_fieldCC->GetHeadItem();
            if ((short)head2->v8() == 9) {
                ListItem *head3 = (ListItem*)self->m_fieldCC->GetHeadItem();
                if (head3->Method15(other, x, y, z)) {
                    ListItem *head4 = (ListItem*)self->m_fieldCC->GetHeadItem();
                    self->v197(head4->v8(), other, x, y, z);
                    s1 = 1;
                }
            }
        }
    }

    if (s1) {
        return;
    }

    s0 = s0 ? (SpatialObj1*)((VBaseList*)self->m_fieldCC)->CreateItem(s0, other, x, y, z) : 0;

    if (s0) {
        self->v197(((SpatialObjV8*)s0)->v8(), other, x, y, z);
        self->v194(s0);
        return;
    }

    if (self->m_field4->m_fieldA4 <= 0.0f) {
        return;
    }

    self->v197(1, other, x, y, z);
    self->v42(other, x, y, z);
}

asm void func_0013A6A0(SubList *self) {
    lw a1, 8(a0)
    lw a0, 4(a0)
    lw t9, 160(a0)
    lw t9, 72(t9)
    jr t9
    nop
}

void func_0013A6C0() {
}

asm void func_0013A6D0(SubList *self) {
    lw a1, 8(a0)
    lw a0, 4(a0)
    lw t9, 160(a0)
    lw t9, 76(t9)
    jr t9
    nop
}

void func_0013A6F0() {
}
