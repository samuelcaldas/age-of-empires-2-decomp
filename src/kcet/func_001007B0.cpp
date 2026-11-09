#pragma exceptions on

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct Exception {
    void *vtable;
};

struct BadAlloc : public Exception {
};

extern "C" {

extern void *D_004D71E0[];
extern void *D_004D71D0[];

void func_00100670(void *self) throw();

static inline void destroy_exception(Exception *self) {
    if (self != 0) {
        self->vtable = D_004D71D0;
    }
}

BadAlloc *func_001007B0(BadAlloc *self, s16 flag) throw() {
    if (self != 0) {
        self->vtable = D_004D71E0;
        destroy_exception(self);
        if (flag > 0) {
            func_00100670(self);
        }
    }
    return self;
}

}
