typedef signed int s32;
typedef unsigned char u8;

extern "C" {

#if defined(__mips__)
asm void *func_0012ED08(void *a0, s32 a1) {
    .word 0x8c83001c // lw $v1, 0x1c($a0)
    .word 0x10600003 // beqz $v1, 0x12ed1c
    .word 0x0000102d // move $v0, $zero
    .word 0x00051140 // sll $v0, $a1, 5
    .word 0x00621021 // addu $v0, $v1, $v0
    .word 0x03e00008 // jr $ra
    .word 0x00000000 // nop
}
#else
struct Item {
    u8 data[32];
};

struct Container {
    u8 pad[0x1C];
    Item *items;
};

Item *func_0012ED08(Container *container, s32 index) {
    Item *items = container->items;
    if (items == 0) {
        return 0;
    }
    return &items[index];
}
#endif

}
