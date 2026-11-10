#pragma exceptions off

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

struct BadException : public Exception {
};

extern "C" {

extern const char D_0048D3D8[];

/* 0x00102300: std::bad_exception::what() const */
const char *func_00102300(const BadException *self) throw() {
    return D_0048D3D8;
}

}
