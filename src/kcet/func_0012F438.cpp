#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

void func_0012EFD8(void *a0, s32 a1, s32 a2);

#if defined(__mips__)
asm s32 func_0012F438(s32 *a0, s32 a1, void *a2) {
    .word 0x00a0402d // 0012F438:  move , 
    .word 0x0000102d // 0012F43C:  move , 
    .word 0x2405fff5 // 0012F440:  addiu , , -0xb
    .word 0x29070001 // 0012F444:  slti , , 1
    .word 0x00a8282a // 0012F448:  slt , , 
    .word 0x0107100b // 0012F44C:  movn , , 
    .word 0x2403fff6 // 0012F450:  addiu , , -0xa
    .word 0x27bdffe0 // 0012F454:  addiu , , -0x20
    .word 0x0065100a // 0012F458:  movz , , 
    .word 0xffbf0010 // 0012F45C:  sd , 0x10()
    .word 0x00021080 // 0012F460:  sll , , 2
    .word 0xffb00000 // 0012F464:  sd , ()
    .word 0x00822023 // 0012F468:  subu , , 
    .word 0x8c900000 // 0012F46C:  lw , ()
    .word 0x2602007d // 0012F470:  addiu , , 0x7d
    .word 0x2c420002 // 0012F474:  sltiu , , 2
    .word 0x14400005 // 0012F478:  bnez , 0x12f490
    .word 0x00c0202d // 0012F47c:  move , 
    .word 0x2402ff81 // 0012F480:  addiu , , -0x7f
    .word 0x16020006 // 0012F484:  bne , , 0x12f4a0
    .word 0x0200102d // 0012F488:  move , 
    .word 0x00c0202d // 0012F48c:  move , 
    .word 0x0100282d // 0012F490:  move , 
    .word 0x0c04bbf6 // 0012F494:  jal 0x12efd8
    .word 0x2406ffff // 0012F498:  addiu , , -1
    .word 0x0200102d // 0012F49c:  move , 
    .word 0xdfbf0010 // 0012F4a0:  ld , 0x10()
    .word 0xdfb00000 // 0012F4a4:  ld , ()
    .word 0x03e00008 // 0012F4a8:  jr 
    .word 0x27bd0020 // 0012F4ac:  addiu , , 0x20
}
#else
s32 func_0012F438(s32 *a0, s32 a1, void *a2) {
    s32 offset = 0;
    if (a1 < 1) {
        offset = a1;
    }
    if (a1 <= -11) {
        offset = -10;
    }
    s32 s0 = a0[-offset];
    if (s0 == -0x7D || s0 == -0x7E || s0 == -0x7F) {
        func_0012EFD8(a2, a1, -1);
    }
    return s0;
}
#endif

}
