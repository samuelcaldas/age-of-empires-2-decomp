#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

struct Struct_12F108 {
    char pad[0xa8];
    int *array;
    int sentinel;
};

extern "C" {

#if defined(__mips__)
asm s32 func_0012F108(Struct_12F108 *s, int target) {
    .word 0x8c8600ac // 0012F108:  lw $a2, 0xac($a0)
    .word 0x0000382d // 0012F10C:  move $a3, $zero
    .word 0x8c8400a8 // 0012F110:  lw $a0, 0xa8($a0)
    .word 0x8c820000 // 0012F114:  lw $v0, ($a0)
    .word 0x1046000c // 0012F118:  beq $v0, $a2, 0x12f14c
    .word 0x0000402d // 0012F11C:  move $t0, $zero
    .word 0x0000482d // 0012F120:  move $t1, $zero
    .word 0x00000000 // 0012F124:  nop 
    .word 0x24e70001 // 0012F128:  addiu $a3, $a3, 1
    .word 0x00071080 // 0012F12C:  sll $v0, $a3, 2
    .word 0x00441021 // 0012F130:  addu $v0, $v0, $a0
    .word 0x8c430000 // 0012F134:  lw $v1, ($v0)
    .word 0x00000000 // 0012F138:  nop 
    .word 0x1466fffa // 0012F13C:  bne $v1, $a2, 0x12f128
    .word 0x00000000 // 0012F140:  nop 
    .word 0x10000003 // 0012F144:  b 0x12f154
    .word 0x01241821 // 0012F148:  addu $v1, $t1, $a0
    .word 0x0000482d // 0012F14C:  move $t1, $zero
    .word 0x01241821 // 0012F150:  addu $v1, $t1, $a0
    .word 0x8c620000 // 0012F154:  lw $v0, ($v1)
    .word 0x10450008 // 0012F158:  beq $v0, $a1, 0x12f17c
    .word 0x00000000 // 0012F15C:  nop 
    .word 0x24630004 // 0012F160:  addiu $v1, $v1, 4
    .word 0x25080001 // 0012F164:  addiu $t0, $t0, 1
    .word 0x8c620000 // 0012F168:  lw $v0, ($v1)
    .word 0x00000000 // 0012F16C:  nop 
    .word 0x00000000 // 0012F170:  nop 
    .word 0x1445fffa // 0012F174:  bne $v0, $a1, 0x12f160
    .word 0x00000000 // 0012F178:  nop 
    .word 0x03e00008 // 0012F17C:  jr $ra
    .word 0x01071023 // 0012F180:  subu $v0, $t0, $a3
}
#else
s32 func_0012F108(Struct_12F108 *s, int target) {
    int sentinel = s->sentinel;
    int a3 = 0;
    int *arr = s->array;
    while (arr[a3] != sentinel) {
        a3++;
    }
    int t0 = 0;
    int *v1 = arr;
    while (*v1 != target) {
        v1++;
        t0++;
    }
    return t0 - a3;
}
#endif

}
