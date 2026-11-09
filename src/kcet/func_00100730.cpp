#pragma exceptions on

typedef unsigned int u32;

extern "C" {

void *func_00100850(u32 size);

void *func_00100730(u32 size) {
    return func_00100850(size);
}

}
