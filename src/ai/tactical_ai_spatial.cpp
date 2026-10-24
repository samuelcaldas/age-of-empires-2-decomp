#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x30];
    void *field_34;
    char pad_38[0x4];
    void **field_3C;
};

struct SpatialBuf {
    char tag;
    char pad;
    short id;
};

extern "C" {

void *func_26AF90(void *ptr, int a1, void *a2);
void func_26AD90(void *ptr, int id);
void func_26AE00(void *ptr, int val);
int func_001411E0(void *self, int a1, int a2);
int func_00141500(void *self, int a1);
int func_00141630(void *self, int a1);
void *func_100850(int size);

int func_001422F0(TacticalAI2 *self, int a1, int a2, int a3) {
    int id = func_001411E0(self, a2, a3);
    if (id == -1) {
        return 0;
    }
    SpatialBuf buf;
    buf.tag = 0;
    buf.id = id;
    void *item = func_26AF90(&self->field_34, a1, &buf);
    if (*(short *)((char *)item + 2) == buf.id) goto ret1;
    return 0;
ret1:
    return 1;
}

int func_00142380(TacticalAI2 *self, int a1) {
    int id = func_00141500(self, a1);
    if (id == -1) goto ret;
    {
        void *obj = 0;
        if (obj = func_100850(8)) {
            func_26AD90(obj, 0xD3);
        }
        self->field_3C[id] = obj;
    }
ret:
    return id;
}

int func_00142400(TacticalAI2 *self, int a1) {
    if (!func_00141630(self, a1)) {
        return 0;
    }
    void *old_obj = self->field_3C[a1];
    if (old_obj) {
        func_26AE00(old_obj, 1);
    }
    void *obj;
    if (obj = func_100850(8)) {
        func_26AD90(obj, 0xD3);
    }
    self->field_3C[a1] = obj;
    return 1;
}

}
