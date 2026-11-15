typedef unsigned char u8;
typedef unsigned int u32;

struct Struct_00127810 {
    u8 pad[0xb0];
    u32 flags;
};

extern "C" u32 func_00127810(const Struct_00127810* ptr) {
    return ptr->flags & 0x10000;
}
