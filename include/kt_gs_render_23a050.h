#ifndef KT_GS_RENDER_23A050_H
#define KT_GS_RENDER_23A050_H

#ifdef __cplusplus
extern "C" {
#endif

struct Struct23A050 {
    char pad_00[0x1050];
    char *field_1050;
    int field_1054;
};

void func_0023A050(Struct23A050 *self, const char *str);
int func_0023A080(Struct23A050 *self);

#ifdef __cplusplus
}
#endif

#endif // KT_GS_RENDER_23A050_H
