#include "sub_list.h"

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x30];
    void *field_34;
    char pad_38[0x4];
    void **field_3C;
    char pad_40[0x150];
    int field_190;
    char pad_194[0x8];
    int field_19C;
};

struct CandidateBuf {
    char tag;
    char pad;
    short val;
};

extern "C" {

void *func_26B0A0(void *ptr, int a1, int a2);
void *func_26AF90(void *ptr, int a1, void *a2);
int func_00141370(void *self, int a1);
int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);

int func_00142680(TacticalAI2 *self, int a1) {
    int val;
    void *item = func_26B0A0(self->field_3C[self->field_190], a1, 4);
    if (item) {
        return *(short *)((char *)item + 2);
    }
    val = func_00141370(self, self->field_190);
    if (val == -1) goto done;
    {
        CandidateBuf buf;
        buf.tag = 4;
        buf.val = val;
        func_26AF90(self->field_3C[self->field_190], a1, &buf);
    }
done:
    return val;
}

void *func_00142730(TacticalAI2 *self, int a1, int a2) {
    void *res = func_26B0A0(self->field_3C[self->field_190], a1, a2);
    if (!res) goto second_call;
    return res;
second_call:
    return func_26B0A0(&self->field_34, a1, a2);
}

int func_001427A0(TacticalAI2 *self) {
    int status = func_142980(self);
    if (status != 2) {
        if (status == 1) {
            func_144340(self, 0x1A, 0);
        }
        return 0;
    }
    if (self->field_19C == 3) goto ok;
    func_144340(self, 8, 0);
    return 0;
ok:
    return 1;
}

}
