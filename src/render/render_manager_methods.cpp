#pragma exceptions off

extern "C" {
extern const char D_004D7DB0[];
void func_100670(void *);

void func_00184a88(void *self, int val) {
    *(int *)((char *)self + 0x1C8) = val;
}

void *func_00184a98(void *self, int flags) {
    if (self != 0) {
        *(const void **)self = D_004D7DB0;
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

void func_00184aec(void *self) {
    char *p = (char *)self;
    *(int *)(p + 0x20) = 10;
    *(int *)(p + 0x518) = 0;
    *(int *)(p + 0x51C) = 0;
    *(int *)(p + 0x520) = 0;
    *(int *)(p + 0x524) = 0;
    *(int *)(p + 0x528) = 0;
    *(int *)(p + 0x52C) = 0;
    *(int *)(p + 0x530) = 0;
    *(int *)(p + 0x534) = 0;
    *(int *)(p + 0x538) = 0;
    for (int i = 0; i < 30; i++) {
        char *el = p + i * 32;
        *(int *)(el + 0x53C) = 0;
        *(int *)(el + 0x540) = 0;
        *(int *)(el + 0x544) = 0;
        *(int *)(el + 0x550) = 0;
        *(int *)(el + 0x554) = 0;
        *(int *)(el + 0x558) = 0;
    }
}

void func_00184b5c(void *self, int idx, int val) {
    char *el = (char *)self + idx * 32;
    int cur = *(int *)(el + 0x53C) + val;
    *(int *)(el + 0x53C) = cur;
    *(int *)(el + 0x550) = val;
    if (*(unsigned int *)(el + 0x554) < (unsigned int)val) {
        *(int *)(el + 0x554) = val;
    }
}

void func_00184b94(void *self) {
    *(int *)((char *)self + 0x51C) += 1;
}

void func_00184bb0(void *self) {
    *(int *)((char *)self + 0x520) += 1;
}

void func_00184bc0(void *self, int idx, int val) {
    *(int *)((char *)self + idx * 32 + 0x550) = val;
}

int func_00184bd0(void *self, int idx) {
    return *(int *)((char *)self + idx * 32 + 0x540);
}

int func_00184be0(void *self, int idx) {
    return *(int *)((char *)self + idx * 32 + 0x550);
}

int func_00184bf0(void *self, int idx) {
    return *(int *)((char *)self + idx * 32 + 0x53C);
}

int func_00184c00(void *self) {
    return *(int *)((char *)self + 0x528);
}

int func_00184c08(void *self) {
    return *(int *)((char *)self + 0x51C);
}

int func_00184c18(void *self) {
    return *(int *)((char *)self + 0x64);
}
}
