#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceGsDrawEnv2 {
    u64 frame2;
    u64 frame2addr;
    u64 zbuf2;
    u64 zbuf2addr;
    u64 xyoffset2;
    u64 xyoffset2addr;
    u64 scissor2;
    u64 scissor2addr;
    u64 prmodecont;
    u64 prmodecontaddr;
    u64 colclamp;
    u64 colclampaddr;
    u64 dthe;
    u64 dtheaddr;
    u64 test2;
    u64 test2addr;
};

extern "C" {

s32 func_00102BC0(s16 a0, s16 a1, s16 a2);

#if defined(__mips__)
asm s32 func_00103708(sceGsDrawEnv2 *env, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm) {
    .word 0x27bdff90 // 00103708:  addiu $sp, $sp, -0x70
    .word 0x00063400 // 0010370C:  sll $a2, $a2, 0x10
    .word 0xffb20020 // 00103710:  sd $s2, 0x20($sp)
    .word 0x00052c00 // 00103714:  sll $a1, $a1, 0x10
    .word 0xffb40040 // 00103718:  sd $s4, 0x40($sp)
    .word 0x00069403 // 0010371C:  sra $s2, $a2, 0x10
    .word 0x0005a403 // 00103720:  sra $s4, $a1, 0x10
    .word 0x00063583 // 00103724:  sra $a2, $a2, 0x16
    .word 0x3282000f // 00103728:  andi $v0, $s4, 0xf
    .word 0x30c6003f // 0010372C:  andi $a2, $a2, 0x3f
    .word 0x00021638 // 00103730:  dsll $v0, $v0, 0x18
    .word 0x00063438 // 00103734:  dsll $a2, $a2, 0x10
    .word 0xffb00000 // 00103738:  sd $s0, ($sp)
    .word 0x00c23025 // 0010373C:  or $a2, $a2, $v0
    .word 0xffb50050 // 00103740:  sd $s5, 0x50($sp)
    .word 0x0080802d // 00103744:  move $s0, $a0
    .word 0xffb30030 // 00103748:  sd $s3, 0x30($sp)
    .word 0x00073c00 // 0010374C:  sll $a3, $a3, 0x10
    .word 0xffb10010 // 00103750:  sd $s1, 0x10($sp)
    .word 0x00084400 // 00103754:  sll $t0, $t0, 0x10
    .word 0xffbf0060 // 00103758:  sd $ra, 0x60($sp)
    .word 0x00094c00 // 0010375C:  sll $t1, $t1, 0x10
    .word 0x2402004d // 00103760:  addiu $v0, $zero, 0x4d
    .word 0x2403004f // 00103764:  addiu $v1, $zero, 0x4f
    .word 0x00078c03 // 00103768:  sra $s1, $a3, 0x10
    .word 0x0008ac03 // 0010376C:  sra $s5, $t0, 0x10
    .word 0x00099c03 // 00103770:  sra $s3, $t1, 0x10
    .word 0xfe020008 // 00103774:  sd $v0, 8($s0)
    .word 0xfe060000 // 00103778:  sd $a2, ($s0)
    .word 0x16a0000e // 0010377C:  bnez $s5, 0x1037b8
    .word 0xfe030018 // 00103780:  sd $v1, 0x18($s0)
    .word 0x0280202d // 00103784:  move $a0, $s4
    .word 0x0240282d // 00103788:  move $a1, $s2
    .word 0x0c040af0 // 0010378C:  jal func_00102BC0
    .word 0x0220302d // 00103790:  move $a2, $s1
    .word 0x0002143c // 00103794:  dsll32 $v0, $v0, 0x10
    .word 0x3263000f // 00103798:  andi $v1, $s3, 0xf
    .word 0x0002143f // 0010379C:  dsra32 $v0, $v0, 0x10
    .word 0x00031e38 // 001037A0:  dsll $v1, $v1, 0x18
    .word 0x00431025 // 001037A4:  or $v0, $v0, $v1
    .word 0x34048000 // 001037A8:  ori $a0, $zero, 0x8000
    .word 0x00042478 // 001037AC:  dsll $a0, $a0, 0x11
    .word 0x1000000a // 001037B0:  b 0x1037dc
    .word 0x00441025 // 001037B4:  or $v0, $v0, $a0
    .word 0x0280202d // 001037B8:  move $a0, $s4
    .word 0x0240282d // 001037BC:  move $a1, $s2
    .word 0x0c040af0 // 001037C0:  jal func_00102BC0
    .word 0x0220302d // 001037C4:  move $a2, $s1
    .word 0x0002143c // 001037C8:  dsll32 $v0, $v0, 0x10
    .word 0x3263000f // 001037CC:  andi $v1, $s3, 0xf
    .word 0x0002143f // 001037D0:  dsra32 $v0, $v0, 0x10
    .word 0x00031e38 // 001037D4:  dsll $v1, $v1, 0x18
    .word 0x00431025 // 001037D8:  or $v0, $v0, $v1
    .word 0xfe020010 // 001037DC:  sd $v0, 0x10($s0)
    .word 0x00111043 // 001037E0:  sra $v0, $s1, 1
    .word 0x00121843 // 001037E4:  sra $v1, $s2, 1
    .word 0x0002143c // 001037E8:  dsll32 $v0, $v0, 0x10
    .word 0x24040800 // 001037EC:  addiu $a0, $zero, 0x800
    .word 0x00031c3c // 001037F0:  dsll32 $v1, $v1, 0x10
    .word 0x0002143f // 001037F4:  dsra32 $v0, $v0, 0x10
    .word 0x00031c3f // 001037F8:  dsra32 $v1, $v1, 0x10
    .word 0x0082102f // 001037FC:  dsubu $v0, $a0, $v0
    .word 0x0083202f // 00103800:  dsubu $a0, $a0, $v1
    .word 0x0002113c // 00103804:  dsll32 $v0, $v0, 4
    .word 0x2646ffff // 00103808:  addiu $a2, $s2, -1
    .word 0x2625ffff // 0010380C:  addiu $a1, $s1, -1
    .word 0x00042138 // 00103810:  dsll $a0, $a0, 4
    .word 0xde030040 // 00103814:  ld $v1, 0x40($s0)
    .word 0xde070050 // 00103818:  ld $a3, 0x50($s0)
    .word 0x00052c3c // 0010381C:  dsll32 $a1, $a1, 0x10
    .word 0x00822025 // 00103820:  or $a0, $a0, $v0
    .word 0x00063438 // 00103824:  dsll $a2, $a2, 0x10
    .word 0x240b0001 // 00103828:  addiu $t3, $zero, 1
    .word 0x00c53025 // 0010382C:  or $a2, $a2, $a1
    .word 0x24020019 // 00103830:  addiu $v0, $zero, 0x19
    .word 0x006b1825 // 00103834:  or $v1, $v1, $t3
    .word 0x00eb3825 // 00103838:  or $a3, $a3, $t3
    .word 0x24050041 // 0010383C:  addiu $a1, $zero, 0x41
    .word 0x2408001a // 00103840:  addiu $t0, $zero, 0x1a
    .word 0x24090046 // 00103844:  addiu $t1, $zero, 0x46
    .word 0x240a0045 // 00103848:  addiu $t2, $zero, 0x45
    .word 0xfe020028 // 0010384C:  sd $v0, 0x28($s0)
    .word 0xfe040020 // 00103850:  sd $a0, 0x20($s0)
    .word 0x32820002 // 00103854:  andi $v0, $s4, 2
    .word 0xfe050038 // 00103858:  sd $a1, 0x38($s0)
    .word 0xfe060030 // 0010385C:  sd $a2, 0x30($s0)
    .word 0xfe080048 // 00103860:  sd $t0, 0x48($s0)
    .word 0xfe030040 // 00103864:  sd $v1, 0x40($s0)
    .word 0xfe090058 // 00103868:  sd $t1, 0x58($s0)
    .word 0xfe070050 // 0010386C:  sd $a3, 0x50($s0)
    .word 0x10400004 // 00103870:  beqz $v0, 0x103884
    .word 0xfe0a0068 // 00103874:  sd $t2, 0x68($s0)
    .word 0xde020060 // 00103878:  ld $v0, 0x60($s0)
    .word 0x10000004 // 0010387C:  b 0x103890
    .word 0x004b1025 // 00103880:  or $v0, $v0, $t3
    .word 0xde020060 // 00103884:  ld $v0, 0x60($s0)
    .word 0x2403fffe // 00103888:  addiu $v1, $zero, -2
    .word 0x00431024 // 0010388C:  and $v0, $v0, $v1
    .word 0xfe020060 // 00103890:  sd $v0, 0x60($s0)
    .word 0x24020048 // 00103894:  addiu $v0, $zero, 0x48
    .word 0x12a00006 // 00103898:  beqz $s5, 0x1038b4
    .word 0xfe020078 // 0010389C:  sd $v0, 0x78($s0)
    .word 0x32a20003 // 001038A0:  andi $v0, $s5, 3
    .word 0x3c030001 // 001038A4:  lui $v1, 1
    .word 0x00021478 // 001038A8:  dsll $v0, $v0, 0x11
    .word 0x10000002 // 001038AC:  b 0x1038b8
    .word 0x00431025 // 001038B0:  or $v0, $v0, $v1
    .word 0x3c020003 // 001038B4:  lui $v0, 3
    .word 0xfe020070 // 001038B8:  sd $v0, 0x70($s0)
    .word 0x0000000f // 001038BC:  sync
    .word 0xdfbf0060 // 001038C0:  ld $ra, 0x60($sp)
    .word 0x24020008 // 001038C4:  addiu $v0, $zero, 8
    .word 0xdfb50050 // 001038C8:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 001038CC:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 001038D0:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 001038D4:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 001038D8:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 001038DC:  ld $s0, ($sp)
    .word 0x03e00008 // 001038E0:  jr $ra
    .word 0x27bd0070 // 001038E4:  addiu $sp, $sp, 0x70
}
#else
s32 func_00103708(sceGsDrawEnv2 *env, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm) {
    u64 v_frame;
    u64 v_zbuf;
    u64 v_xyoffset;
    u64 v_scissor;
    
    v_frame = ((u64)(psm & 0xf) << 24) | ((u64)((w >> 6) & 0x3f) << 16);
    env->frame2 = v_frame;
    env->frame2addr = 0x4d;
    env->zbuf2addr = 0x4f;

    if (ztest == 0) {
        v_zbuf = (u64)(u32)func_00102BC0(psm, w, h) | ((u64)(zpsm & 0xf) << 24) | 0x100000000ULL;
    } else {
        v_zbuf = (u64)(u32)func_00102BC0(psm, w, h) | ((u64)(zpsm & 0xf) << 24);
    }
    env->zbuf2 = v_zbuf;

    v_xyoffset = ((u64)(2048 - (h >> 1)) << 36) | ((u64)(2048 - (w >> 1)) << 4);
    env->xyoffset2 = v_xyoffset;
    env->xyoffset2addr = 0x19;

    v_scissor = ((u64)(h - 1) << 48) | ((u64)(w - 1) << 16);
    env->scissor2 = v_scissor;
    env->scissor2addr = 0x41;

    env->prmodecont |= 1;
    env->prmodecontaddr = 0x1a;

    env->colclamp |= 1;
    env->colclampaddr = 0x46;

    env->dtheaddr = 0x45;
    if ((psm & 2) != 0) {
        env->dthe |= 1;
    } else {
        env->dthe &= ~1ULL;
    }

    env->test2addr = 0x48;
    if (ztest != 0) {
        env->test2 = 0x10000 | ((u64)(ztest & 3) << 17);
    } else {
        env->test2 = 0x30000;
    }

    return 8;
}
#endif

}
