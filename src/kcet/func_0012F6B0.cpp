#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct TargetStruct {
    u32 unk0;
    u16 field4;
    u16 unk6;
    u32 field8;
};

extern "C" {

#if defined(__mips__)
asm void func_0012F6B0(TargetStruct *obj, s32 a1, s32 a2) {
    .word 0x000610c0 // sll $v0, $a2, 3
    .word 0x38a30002 // xori $v1, $a1, 2
    .word 0x00c3100a // movz $v0, $a2, $v1
    .word 0xa4850004 // sh $a1, 4($a0)
    .word 0x03e00008 // jr $ra
    .word 0xac820008 // sw $v0, 8($a0)
}
#else
void func_0012F6B0(TargetStruct *obj, s32 a1, s32 a2) {
    obj->field4 = (u16)a1;
    obj->field8 = (a1 == 2) ? a2 : (a2 << 3);
}
#endif

}
