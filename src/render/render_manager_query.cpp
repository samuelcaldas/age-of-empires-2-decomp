#pragma exceptions off

extern "C" {
int func_1C1FD0(void *ctx, char *dest, int size);
extern void *D_004E3110;

void *func_00184c28(void *self, int p1) {
    typedef void (*VMethod10)(void *self, int p1, void *buf, int size);
    VMethod10 fn = *(VMethod10 *)(*(char **)self + 0x28);
    fn(self, p1, (void *)0x00566EC0, 0x200);
    return (void *)0x00566EC0;
}

char *func_00184c70(void *self, int a1, char *dest, int size) {
    (void)self;
    (void)a1;
    void *ctx = D_004E3110;
    if (func_1C1FD0(ctx, dest, size) == 0) {
        dest[0] = 0;
        dest[size - 1] = 0;
    }
    return dest;
}

void *func_00184cc0(void *self, int a1, int a2, int a3, int t0) {
    typedef void *(*VMethod13)(void *self, int a1, int a2, int a3, int t0, int t1);
    VMethod13 fn = *(VMethod13 *)(*(char **)self + 0x34);
    return fn(self, a1, a2, 0, a3, t0);
}
}
