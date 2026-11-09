#pragma exceptions off

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {

/* 0x004E3D84: Head of the registered global destructors chain */
extern DestructorChain* D_004E3D84[];

/*
 * 0x00100C20: __register_global_object
 * Registers an object and its destructor into the global destructor chain.
 */
void* func_00100C20(void* object, void* destructor, DestructorChain* chain) {
    chain->next = D_004E3D84[0];
    chain->destructor = destructor;
    chain->object = object;
    D_004E3D84[0] = chain;
    return object;
}

}
