/* Function: func_0012B648 (0x0012B648 - 0x0012B99C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012B648(void) {
    .word 0x27bdff20 // 0012B648:  addiu $sp, $sp, -0xe0
    .word 0xffbe00c0 // 0012B64C:  sd $fp, 0xc0($sp)
    .word 0xffb700b0 // 0012B650:  sd $s7, 0xb0($sp)
    .word 0x3c1e004e // 0012B654:  lui $fp, 0x4e
    .word 0xffb600a0 // 0012B658:  sd $s6, 0xa0($sp)
    .word 0x3c170049 // 0012B65C:  lui $s7, 0x49
    .word 0xffb50090 // 0012B660:  sd $s5, 0x90($sp)
    .word 0x3c160049 // 0012B664:  lui $s6, 0x49
    .word 0xffb40080 // 0012B668:  sd $s4, 0x80($sp)
    .word 0x3c150049 // 0012B66C:  lui $s5, 0x49
    .word 0xffbf00d0 // 0012B670:  sd $ra, 0xd0($sp)
    .word 0x3c14004f // 0012B674:  lui $s4, 0x4f
    .word 0xffb30070 // 0012B678:  sd $s3, 0x70($sp)
    .word 0xffb20060 // 0012B67C:  sd $s2, 0x60($sp)
    .word 0xffb10050 // 0012B680:  sd $s1, 0x50($sp)
    .word 0xffb00040 // 0012B684:  sd $s0, 0x40($sp)
    .word 0x0c04af04 // 0012B688:  jal 0x12bc10
    .word 0x00000000 // 0012B68C:  nop
    .word 0x0c04d140 // 0012B690:  jal 0x134500
    .word 0x0040202d // 0012B694:  move $a0, $v0
    .word 0x0c04ab66 // 0012B698:  jal 0x12ad98
    .word 0x00000000 // 0012B69C:  nop
    .word 0x0040802d // 0012B6A0:  move $s0, $v0
    .word 0x2682d300 // 0012B6A4:  addiu $v0, $s4, -0x2d00
    .word 0x0c04af9c // 0012B6A8:  jal 0x12be70
    .word 0xac40005c // 0012B6AC:  sw $zero, 0x5c($v0)
    .word 0x0040882d // 0012B6B0:  move $s1, $v0
    .word 0x56200007 // 0012B6B4:  bnel $s1, $zero, 0x12b6d4
    .word 0x8e250000 // 0012B6B8:  lw $a1, ($s1)
    .word 0x3c020049 // 0012B6BC:  lui $v0, 0x49
    .word 0x24050a0b // 0012B6C0:  addiu $a1, $zero, 0xa0b
    .word 0x2444f500 // 0012B6C4:  addiu $a0, $v0, -0xb00
    .word 0x0c0450c8 // 0012B6C8:  jal 0x114320
    .word 0x27c62c80 // 0012B6CC:  addiu $a2, $fp, 0x2c80
    .word 0x8e250000 // 0012B6D0:  lw $a1, ($s1)
    .word 0x8e320014 // 0012B6D4:  lw $s2, 0x14($s1)
    .word 0x24a3ffff // 0012B6D8:  addiu $v1, $a1, -1
    .word 0x8e330028 // 0012B6DC:  lw $s3, 0x28($s1)
    .word 0x8e280020 // 0012B6E0:  lw $t0, 0x20($s1)
    .word 0x2c620006 // 0012B6E4:  sltiu $v0, $v1, 6
    .word 0x8e270024 // 0012B6E8:  lw $a3, 0x24($s1)
    .word 0xae12006c // 0012B6EC:  sw $s2, 0x6c($s0)
    .word 0x10400007 // 0012B6F0:  beqz $v0, 0x12b710
    .word 0xae450004 // 0012B6F4:  sw $a1, 4($s2)
    .word 0x00031080 // 0012B6F8:  sll $v0, $v1, 2
    .word 0x26e3fe10 // 0012B6FC:  addiu $v1, $s7, -0x1f0
    .word 0x00431021 // 0012B700:  addu $v0, $v0, $v1
    .word 0x8c440000 // 0012B704:  lw $a0, ($v0)
    .word 0x00800008 // 0012B708:  jr $a0
    .word 0x00000000 // 0012B70C:  nop
    .word 0x26c4fdb0 // 0012B710:  addiu $a0, $s6, -0x250
    .word 0x0c046378 // 0012B714:  jal 0x118de0
    .word 0x24100001 // 0012B718:  addiu $s0, $zero, 1
    .word 0x1000002d // 0012B71C:  b 0x12b7d4
    .word 0x00000000 // 0012B720:  nop
    .word 0x0100502d // 0012B724:  move $t2, $t0
    .word 0x00e0582d // 0012B728:  move $t3, $a3
    .word 0x8e25000c // 0012B72C:  lw $a1, 0xc($s1)
    .word 0x0200202d // 0012B730:  move $a0, $s0
    .word 0x8e260010 // 0012B734:  lw $a2, 0x10($s1)
    .word 0x0240382d // 0012B738:  move $a3, $s2
    .word 0x8e280018 // 0012B73C:  lw $t0, 0x18($s1)
    .word 0x0c04ac96 // 0012B740:  jal 0x12b258
    .word 0x8e29001c // 0012B744:  lw $t1, 0x1c($s1)
    .word 0x10000022 // 0012B748:  b 0x12b7d4
    .word 0x0040802d // 0012B74C:  move $s0, $v0
    .word 0x00e0482d // 0012B750:  move $t1, $a3
    .word 0x8e25000c // 0012B754:  lw $a1, 0xc($s1)
    .word 0x8e26001c // 0012B758:  lw $a2, 0x1c($s1)
    .word 0x0200202d // 0012B75C:  move $a0, $s0
    .word 0x0c04acce // 0012B760:  jal 0x12b338
    .word 0x0240382d // 0012B764:  move $a3, $s2
    .word 0x1000001a // 0012B768:  b 0x12b7d4
    .word 0x0040802d // 0012B76C:  move $s0, $v0
    .word 0x0200202d // 0012B770:  move $a0, $s0
    .word 0x0100302d // 0012B774:  move $a2, $t0
    .word 0x0c04ad44 // 0012B778:  jal 0x12b510
    .word 0x0240282d // 0012B77C:  move $a1, $s2
    .word 0x10000014 // 0012B780:  b 0x12b7d4
    .word 0x0040802d // 0012B784:  move $s0, $v0
    .word 0x0200202d // 0012B788:  move $a0, $s0
    .word 0x0100302d // 0012B78C:  move $a2, $t0
    .word 0x0c04ad4c // 0012B790:  jal 0x12b530
    .word 0x0240282d // 0012B794:  move $a1, $s2
    .word 0x1000000e // 0012B798:  b 0x12b7d4
    .word 0x0040802d // 0012B79C:  move $s0, $v0
    .word 0x0200202d // 0012B7A0:  move $a0, $s0
    .word 0x0100302d // 0012B7A4:  move $a2, $t0
    .word 0x0c04ad54 // 0012B7A8:  jal 0x12b550
    .word 0x0240282d // 0012B7AC:  move $a1, $s2
    .word 0x10000008 // 0012B7B0:  b 0x12b7d4
    .word 0x0040802d // 0012B7B4:  move $s0, $v0
    .word 0x00e0482d // 0012B7B8:  move $t1, $a3
    .word 0x8e25000c // 0012B7BC:  lw $a1, 0xc($s1)
    .word 0x8e260010 // 0012B7C0:  lw $a2, 0x10($s1)
    .word 0x0200202d // 0012B7C4:  move $a0, $s0
    .word 0x0c04ad5c // 0012B7C8:  jal 0x12b570
    .word 0x0240382d // 0012B7CC:  move $a3, $s2
    .word 0x0040802d // 0012B7D0:  move $s0, $v0
    .word 0x0c04ab72 // 0012B7D4:  jal 0x12adc8
    .word 0x00000000 // 0012B7D8:  nop
    .word 0x0200302d // 0012B7DC:  move $a2, $s0
    .word 0x03a0202d // 0012B7E0:  move $a0, $sp
    .word 0x24050008 // 0012B7E4:  addiu $a1, $zero, 8
    .word 0x26a2fdc8 // 0012B7E8:  addiu $v0, $s5, -0x238
    .word 0x68430007 // 0012B7EC:  ldl $v1, 7($v0)
    .word 0x6c430000 // 0012B7F0:  ldr $v1, ($v0)
    .word 0x6848000f // 0012B7F4:  ldl $t0, 0xf($v0)
    .word 0x6c480008 // 0012B7F8:  ldr $t0, 8($v0)
    .word 0x68490017 // 0012B7FC:  ldl $t1, 0x17($v0)
    .word 0x6c490010 // 0012B800:  ldr $t1, 0x10($v0)
    .word 0xb3a30007 // 0012B804:  sdl $v1, 7($sp)
    .word 0xb7a30000 // 0012B808:  sdr $v1, ($sp)
    .word 0xb3a8000f // 0012B80C:  sdl $t0, 0xf($sp)
    .word 0xb7a80008 // 0012B810:  sdr $t0, 8($sp)
    .word 0xb3a90017 // 0012B814:  sdl $t1, 0x17($sp)
    .word 0xb7a90010 // 0012B818:  sdr $t1, 0x10($sp)
    .word 0x6843001f // 0012B81C:  ldl $v1, 0x1f($v0)
    .word 0x6c430018 // 0012B820:  ldr $v1, 0x18($v0)
    .word 0x68480027 // 0012B824:  ldl $t0, 0x27($v0)
    .word 0x6c480020 // 0012B828:  ldr $t0, 0x20($v0)
    .word 0x6849002f // 0012B82C:  ldl $t1, 0x2f($v0)
    .word 0x6c490028 // 0012B830:  ldr $t1, 0x28($v0)
    .word 0xb3a3001f // 0012B834:  sdl $v1, 0x1f($sp)
    .word 0xb7a30018 // 0012B838:  sdr $v1, 0x18($sp)
    .word 0xb3a80027 // 0012B83C:  sdl $t0, 0x27($sp)
    .word 0xb7a80020 // 0012B840:  sdr $t0, 0x20($sp)
    .word 0xb3a9002f // 0012B844:  sdl $t1, 0x2f($sp)
    .word 0xb7a90028 // 0012B848:  sdr $t1, 0x28($sp)
    .word 0x68430037 // 0012B84C:  ldl $v1, 0x37($v0)
    .word 0x6c430030 // 0012B850:  ldr $v1, 0x30($v0)
    .word 0x6848003f // 0012B854:  ldl $t0, 0x3f($v0)
    .word 0x6c480038 // 0012B858:  ldr $t0, 0x38($v0)
    .word 0xb3a30037 // 0012B85C:  sdl $v1, 0x37($sp)
    .word 0xb7a30030 // 0012B860:  sdr $v1, 0x30($sp)
    .word 0xb3a8003f // 0012B864:  sdl $t0, 0x3f($sp)
    .word 0xb7a80038 // 0012B868:  sdr $t0, 0x38($sp)
    .word 0x0c04a562 // 0012B86C:  jal 0x129588
    .word 0x24070008 // 0012B870:  addiu $a3, $zero, 8
    .word 0x8e24002c // 0012B874:  lw $a0, 0x2c($s1)
    .word 0x0240282d // 0012B878:  move $a1, $s2
    .word 0x0c04a558 // 0012B87C:  jal 0x129560
    .word 0xae420000 // 0012B880:  sw $v0, ($s2)
    .word 0x0c04af8c // 0012B884:  jal 0x12be30
    .word 0x0220202d // 0012B888:  move $a0, $s1
    .word 0x1260ff7e // 0012B88C:  beqz $s3, 0x12b688
    .word 0x2682d300 // 0012B890:  addiu $v0, $s4, -0x2d00
    .word 0x0c04d110 // 0012B894:  jal 0x134440
    .word 0x8c44004c // 0012B898:  lw $a0, 0x4c($v0)
    .word 0x1000ff7a // 0012B89C:  b 0x12b688
    .word 0x00000000 // 0012B8A0:  nop
    .word 0x00000000 // 0012B8A4:  nop
    .word 0x27bdffc0 // 0012B8A8:  addiu $sp, $sp, -0x40
    .word 0x0000282d // 0012B8AC:  move $a1, $zero
    .word 0xffb20020 // 0012B8B0:  sd $s2, 0x20($sp)
    .word 0x0000302d // 0012B8B4:  move $a2, $zero
    .word 0x0080902d // 0012B8B8:  move $s2, $a0
    .word 0xffb00000 // 0012B8BC:  sd $s0, ($sp)
    .word 0xffbf0030 // 0012B8C0:  sd $ra, 0x30($sp)
    .word 0x0000202d // 0012B8C4:  move $a0, $zero
    .word 0x0c04d084 // 0012B8C8:  jal 0x134210
    .word 0xffb10010 // 0012B8CC:  sd $s1, 0x10($sp)
    .word 0x0040802d // 0012B8D0:  move $s0, $v0
    .word 0x06010008 // 0012B8D4:  bgez $s0, 0x12b8f8
    .word 0x3c02004f // 0012B8D8:  lui $v0, 0x4f
    .word 0x3c040049 // 0012B8DC:  lui $a0, 0x49
    .word 0x3c060049 // 0012B8E0:  lui $a2, 0x49
    .word 0x2484f500 // 0012B8E4:  addiu $a0, $a0, -0xb00
    .word 0x24c6fbf8 // 0012B8E8:  addiu $a2, $a2, -0x408
    .word 0x0c0450c8 // 0012B8EC:  jal 0x114320
    .word 0x24050a66 // 0012B8F0:  addiu $a1, $zero, 0xa66
    .word 0x3c02004f // 0012B8F4:  lui $v0, 0x4f
    .word 0x0000202d // 0012B8F8:  move $a0, $zero
    .word 0x2451d300 // 0012B8FC:  addiu $s1, $v0, -0x2d00
    .word 0x0000282d // 0012B900:  move $a1, $zero
    .word 0xae300048 // 0012B904:  sw $s0, 0x48($s1)
    .word 0x0c04d084 // 0012B908:  jal 0x134210
    .word 0x0000302d // 0012B90C:  move $a2, $zero
    .word 0x0040802d // 0012B910:  move $s0, $v0
    .word 0x06010008 // 0012B914:  bgez $s0, 0x12b938
    .word 0x3c040013 // 0012B918:  lui $a0, 0x13
    .word 0x3c040049 // 0012B91C:  lui $a0, 0x49
    .word 0x3c060049 // 0012B920:  lui $a2, 0x49
    .word 0x2484f500 // 0012B924:  addiu $a0, $a0, -0xb00
    .word 0x24c6fbf8 // 0012B928:  addiu $a2, $a2, -0x408
    .word 0x0c0450c8 // 0012B92C:  jal 0x114320
    .word 0x24050a6b // 0012B930:  addiu $a1, $zero, 0xa6b
    .word 0x3c040013 // 0012B934:  lui $a0, 0x13
    .word 0x3c05004f // 0012B938:  lui $a1, 0x4f
    .word 0xae30004c // 0012B93C:  sw $s0, 0x4c($s1)
    .word 0x2484b648 // 0012B940:  addiu $a0, $a0, -0x49b8
    .word 0x24a5d400 // 0012B944:  addiu $a1, $a1, -0x2c00
    .word 0x0240382d // 0012B948:  move $a3, $s2
    .word 0x24064000 // 0012B94C:  addiu $a2, $zero, 0x4000
    .word 0x0000402d // 0012B950:  move $t0, $zero
    .word 0x0c04d0de // 0012B954:  jal 0x134378
    .word 0x0000482d // 0012B958:  move $t1, $zero
    .word 0x0040802d // 0012B95C:  move $s0, $v0
    .word 0x06030008 // 0012B960:  bgezl $s0, 0x12b984
    .word 0xae300050 // 0012B964:  sw $s0, 0x50($s1)
    .word 0x3c040049 // 0012B968:  lui $a0, 0x49
    .word 0x3c060049 // 0012B96C:  lui $a2, 0x49
    .word 0x2484f500 // 0012B970:  addiu $a0, $a0, -0xb00
    .word 0x24c6fe28 // 0012B974:  addiu $a2, $a2, -0x1d8
    .word 0x0c0450c8 // 0012B978:  jal 0x114320
    .word 0x24050a70 // 0012B97C:  addiu $a1, $zero, 0xa70
    .word 0xae300050 // 0012B980:  sw $s0, 0x50($s1)
    .word 0xdfbf0030 // 0012B984:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012B988:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012B98C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012B990:  ld $s0, ($sp)
    .word 0x03e00008 // 0012B994:  jr $ra
    .word 0x27bd0040 // 0012B998:  addiu $sp, $sp, 0x40
}
#else

void func_0012B648(void) {}

#endif

}
