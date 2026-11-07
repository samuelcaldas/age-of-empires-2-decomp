#ifndef KT_GS_RENDER_23A370_H
#define KT_GS_RENDER_23A370_H

#ifdef __cplusplus
extern "C" {
#endif

struct Struct23A370 {
    char pad_00[0x18F0];
    int field_18F0[16];
    int field_1930[16];
    int field_1970[16];
    int field_19B0[16];
};

int func_0023A370(Struct23A370 *self, int a1);
char *func_0023A400(char *self, int a1);
int func_0023A410(Struct23A370 *self, int a1);
int func_0023A450(Struct23A370 *self, int a1);
int func_0023A490(Struct23A370 *self, int a1);
void func_0023A4D0(void **self);

#ifdef __cplusplus
}
#endif

#endif // KT_GS_RENDER_23A370_H
