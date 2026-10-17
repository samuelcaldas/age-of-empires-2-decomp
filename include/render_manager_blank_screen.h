#ifndef RENDER_MANAGER_BLANK_SCREEN_H
#define RENDER_MANAGER_BLANK_SCREEN_H

struct RenderManagerBlank {
    void *vtable;
    char pad_04[0x6C];
    void *field_70;
    char pad_74[0x4D8];
    int field_54C;
    char pad_550[0x18];
    int field_568;
    char pad_56C[0x1C];
    int field_588;
    char pad_58C[0x1C];
    int field_5A8;
    char pad_5AC[0x20];
    int field_5CC;
    char pad_5D0[0xB8];
    int field_688;
    char pad_68C[0x5C];
    int field_6E8;
};

extern const char D_00491A18[];

extern "C" {
void func_00A80BB0();
void *func_100850(int size);
void func_215910(void *obj, const char *name);
int func_215A00(void *obj, void *f70, int zero, int neg1, int t0);
void func_1F2900(void *arg0, const char *name, int zero);
void func_188A40(RenderManagerBlank *self);

int func_001859a0(RenderManagerBlank *self);
void func_00185a50(RenderManagerBlank *self);
}

#endif
