#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012EAB8(void) {
    .word 0x27bdfff0 // 0012EAB8:  addiu , , -0x10
    .word 0xffbf0000 // 0012EABC:  sd , ()
    .word 0x0c04bac0 // 0012EAC0:  jal 0x12eb00
    .word 0x00000000 // 0012EAC4:  nop 
    .word 0xdfbf0000 // 0012EAC8:  ld , ()
    .word 0x0804bb78 // 0012EACC:  j 0x12ede0
    .word 0x27bd0010 // 0012EAD0:  addiu , , 0x10
    .word 0x00000000 // 0012EAD4:  nop 
    .word 0x3c030050 // 0012EAD8:  lui , 0x50
    .word 0x24040001 // 0012EADC:  addiu , , 1
    .word 0x8c6297f4 // 0012EAE0:  lw , -0x680c()
    .word 0x10440003 // 0012EAE4:  beq , , 0x12eaf4
    .word 0x3c020050 // 0012EAE8:  lui , 0x50
    .word 0x8c439700 // 0012EAEC:  lw , -0x6900()
    .word 0x0003200a // 0012EAF0:  movz , , 
    .word 0x03e00008 // 0012EAF4:  jr 
    .word 0x0080102d // 0012EAF8:  move , 
}
#else

void func_0012EB00(void);
void func_0012EDE0(void);

void func_0012EAB8(void) {
    func_0012EB00();
    func_0012EDE0();
}

#endif

}
