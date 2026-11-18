#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceGsDrawEnv {
    u64 frame1;
    u64 frame1addr;
    u64 zbuf1;
    u64 zbuf1addr;
    u64 xyoffset1;
    u64 xyoffset1addr;
    u64 scissor1;
    u64 scissor1addr;
    u64 prmodecont;
    u64 prmodecontaddr;
    u64 colclamp;
    u64 colclampaddr;
    u64 dthe;
    u64 dtheaddr;
    u64 test1;
    u64 test1addr;
};

extern "C" {

s32 func_00102BC0(s16 a0, s16 a1, s16 a2);

#if defined(__mips__)
asm s32 func_00102C88(sceGsDrawEnv *env, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm) {
    .word 0x27bdff90 // 00102C88:  addiu $sp, $sp, -0x70
    .word 0x00063400 // 00102C8C:  sll $a2, $a2, 0x10
    .word 0xffb20020 // 00102C90:  sd $s2, 0x20($sp)
    .word 0x00052c00 // 00102C94:  sll $a1, $a1, 0x10
    .word 0x00069403 // 00102C98:  sra $s2, $a2, 0x10
    .word 0xffb40040 // 00102C9C:  sd $s4, 0x40($sp)
    .word 0x2642003f // 00102CA0:  addiu $v0, $s2, 0x3f
    .word 0x0005a403 // 00102CA4:  sra $s4, $a1, 0x10
    .word 0x00021183 // 00102CA8:  sra $v0, $v0, 6
    .word 0x3283000f // 00102CAC:  andi $v1, $s4, 0xf
    .word 0x3042003f // 00102CB0:  andi $v0, $v0, 0x3f
    .word 0xffb00000 // 00102CB4:  sd $s0, ($sp)
    .word 0x00031e38 // 00102CB8:  dsll $v1, $v1, 0x18
    .word 0x00021438 // 00102CBC:  dsll $v0, $v0, 0x10
    .word 0x0080802d // 00102CC0:  move $s0, $a0
    .word 0x00431025 // 00102CC4:  or $v0, $v0, $v1
    .word 0xffb50050 // 00102CC8:  sd $s5, 0x50($sp)
    .word 0x00073c00 // 00102CCC:  sll $a3, $a3, 0x10
    .word 0xffb30030 // 00102CD0:  sd $s3, 0x30($sp)
    .word 0x00084400 // 00102CD4:  sll $t0, $t0, 0x10
    .word 0xffb10010 // 00102CD8:  sd $s1, 0x10($sp)
    .word 0x00094c00 // 00102CDC:  sll $t1, $t1, 0x10
    .word 0xffbf0060 // 00102CE0:  sd $ra, 0x60($sp)
    .word 0x2403004c // 00102CE4:  addiu $v1, $zero, 0x4c
    .word 0x2404004e // 00102CE8:  addiu $a0, $zero, 0x4e
    .word 0x00078c03 // 00102CEC:  sra $s1, $a3, 0x10
    .word 0x0008ac03 // 00102CF0:  sra $s5, $t0, 0x10
    .word 0x00099c03 // 00102CF4:  sra $s3, $t1, 0x10
    .word 0xfe030008 // 00102CF8:  sd $v1, 8($s0)
    .word 0xfe020000 // 00102CFC:  sd $v0, ($s0)
    .word 0x16a0000e // 00102D00:  bnez $s5, 0x102d3c
    .word 0xfe040018 // 00102D04:  sd $a0, 0x18($s0)
    .word 0x0280202d // 00102D08:  move $a0, $s4
    .word 0x0240282d // 00102D0C:  move $a1, $s2
    .word 0x0c040af0 // 00102D10:  jal func_00102BC0
    .word 0x0220302d // 00102D14:  move $a2, $s1
    .word 0x0002143c // 00102D18:  dsll32 $v0, $v0, 0x10
    .word 0x3263000f // 00102D1C:  andi $v1, $s3, 0xf
    .word 0x0002143f // 00102D20:  dsra32 $v0, $v0, 0x10
    .word 0x00031e38 // 00102D24:  dsll $v1, $v1, 0x18
    .word 0x00431025 // 00102D28:  or $v0, $v0, $v1
    .word 0x34048000 // 00102D2C:  ori $a0, $zero, 0x8000
    .word 0x00042478 // 00102D30:  dsll $a0, $a0, 0x11
    .word 0x1000000a // 00102D34:  b 0x102d60
    .word 0x00441025 // 00102D38:  or $v0, $v0, $a0
    .word 0x0280202d // 00102D3C:  move $a0, $s4
    .word 0x0240282d // 00102D40:  move $a1, $s2
    .word 0x0c040af0 // 00102D44:  jal func_00102BC0
    .word 0x0220302d // 00102D48:  move $a2, $s1
    .word 0x0002143c // 00102D4C:  dsll32 $v0, $v0, 0x10
    .word 0x3263000f // 00102D50:  andi $v1, $s3, 0xf
    .word 0x0002143f // 00102D54:  dsra32 $v0, $v0, 0x10
    .word 0x00031e38 // 00102D58:  dsll $v1, $v1, 0x18
    .word 0x00431025 // 00102D5C:  or $v0, $v0, $v1
    .word 0xfe020010 // 00102D60:  sd $v0, 0x10($s0)
    .word 0x00111043 // 00102D64:  sra $v0, $s1, 1
    .word 0x00121843 // 00102D68:  sra $v1, $s2, 1
    .word 0x0002143c // 00102D6C:  dsll32 $v0, $v0, 0x10
    .word 0x24040800 // 00102D70:  addiu $a0, $zero, 0x800
    .word 0x00031c3c // 00102D74:  dsll32 $v1, $v1, 0x10
    .word 0x0002143f // 00102D78:  dsra32 $v0, $v0, 0x10
    .word 0x00031c3f // 00102D7C:  dsra32 $v1, $v1, 0x10
    .word 0x0082102f // 00102D80:  dsubu $v0, $a0, $v0
    .word 0x0083202f // 00102D84:  dsubu $a0, $a0, $v1
    .word 0x0002113c // 00102D88:  dsll32 $v0, $v0, 4
    .word 0x2646ffff // 00102D8C:  addiu $a2, $s2, -1
    .word 0x2625ffff // 00102D90:  addiu $a1, $s1, -1
    .word 0x00042138 // 00102D94:  dsll $a0, $a0, 4
    .word 0xde030040 // 00102D98:  ld $v1, 0x40($s0)
    .word 0xde070050 // 00102D9C:  ld $a3, 0x50($s0)
    .word 0x00052c3c // 00102DA0:  dsll32 $a1, $a1, 0x10
    .word 0x00822025 // 00102DA4:  or $a0, $a0, $v0
    .word 0x00063438 // 00102DA8:  dsll $a2, $a2, 0x10
    .word 0x240b0001 // 00102DAC:  addiu $t3, $zero, 1
    .word 0x00c53025 // 00102DB0:  or $a2, $a2, $a1
    .word 0x24020018 // 00102DB4:  addiu $v0, $zero, 0x18
    .word 0x006b1825 // 00102DB8:  or $v1, $v1, $t3
    .word 0x00eb3825 // 00102DBC:  or $a3, $a3, $t3
    .word 0x24050040 // 00102DC0:  addiu $a1, $zero, 0x40
    .word 0x2408001a // 00102DC4:  addiu $t0, $zero, 0x1a
    .word 0x24090046 // 00102DC8:  addiu $t1, $zero, 0x46
    .word 0x240a0045 // 00102DCC:  addiu $t2, $zero, 0x45
    .word 0xfe020028 // 00102DD0:  sd $v0, 0x28($s0)
    .word 0xfe040020 // 00102DD4:  sd $a0, 0x20($s0)
    .word 0x32820002 // 00102DD8:  andi $v0, $s4, 2
    .word 0xfe050038 // 00102DDC:  sd $a1, 0x38($s0)
    .word 0xfe060030 // 00102DE0:  sd $a2, 0x30($s0)
    .word 0xfe080048 // 00102DE4:  sd $t0, 0x48($s0)
    .word 0xfe030040 // 00102DE8:  sd $v1, 0x40($s0)
    .word 0xfe090058 // 00102DEC:  sd $t1, 0x58($s0)
    .word 0xfe070050 // 00102DF0:  sd $a3, 0x50($s0)
    .word 0x10400004 // 00102DF4:  beqz $v0, 0x102e08
    .word 0xfe0a0068 // 00102DF8:  sd $t2, 0x68($s0)
    .word 0xde020060 // 00102DFC:  ld $v0, 0x60($s0)
    .word 0x10000004 // 00102E00:  b 0x102e14
    .word 0x004b1025 // 00102E04:  or $v0, $v0, $t3
    .word 0xde020060 // 00102E08:  ld $v0, 0x60($s0)
    .word 0x2403fffe // 00102E0C:  addiu $v1, $zero, -2
    .word 0x00431024 // 00102E10:  and $v0, $v0, $v1
    .word 0xfe020060 // 00102E14:  sd $v0, 0x60($s0)
    .word 0x24020047 // 00102E18:  addiu $v0, $zero, 0x47
    .word 0x12a00006 // 00102E1C:  beqz $s5, 0x102e38
    .word 0xfe020078 // 00102E20:  sd $v0, 0x78($s0)
    .word 0x32a20003 // 00102E24:  andi $v0, $s5, 3
    .word 0x3c030001 // 00102E28:  lui $v1, 1
    .word 0x00021478 // 00102E2C:  dsll $v0, $v0, 0x11
    .word 0x10000002 // 00102E30:  b 0x102e3c
    .word 0x00431025 // 00102E34:  or $v0, $v0, $v1
    .word 0x3c020003 // 00102E38:  lui $v0, 3
    .word 0xfe020070 // 00102E3C:  sd $v0, 0x70($s0)
    .word 0x0000000f // 00102E40:  sync
    .word 0xdfbf0060 // 00102E44:  ld $ra, 0x60($sp)
    .word 0x24020008 // 00102E48:  addiu $v0, $zero, 8
    .word 0xdfb50050 // 00102E4C:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 00102E50:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 00102E54:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 00102E58:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 00102E5C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 00102E60:  ld $s0, ($sp)
    .word 0x03e00008 // 00102E64:  jr $ra
    .word 0x27bd0070 // 00102E68:  addiu $sp, $sp, 0x70
}
#else
s32 func_00102C88(sceGsDrawEnv *env, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm) {
    u64 v_frame;
    u64 v_zbuf;
    u64 v_xyoffset;
    u64 v_scissor;
    
    v_frame = ((u64)(psm & 0xf) << 24) | ((u64)(((w + 0x3f) >> 6) & 0x3f) << 16);
    env->frame1 = v_frame;
    env->frame1addr = 0x4c;
    env->zbuf1addr = 0x4e;

    if (ztest == 0) {
        v_zbuf = (u64)(u32)func_00102BC0(psm, w, h) | ((u64)(zpsm & 0xf) << 24) | 0x100000000ULL;
    } else {
        v_zbuf = (u64)(u32)func_00102BC0(psm, w, h) | ((u64)(zpsm & 0xf) << 24);
    }
    env->zbuf1 = v_zbuf;

    v_xyoffset = ((u64)(2048 - (h >> 1)) << 36) | ((u64)(2048 - (w >> 1)) << 4);
    env->xyoffset1 = v_xyoffset;
    env->xyoffset1addr = 0x18;

    v_scissor = ((u64)(h - 1) << 48) | ((u64)(w - 1) << 16);
    env->scissor1 = v_scissor;
    env->scissor1addr = 0x40;

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

    env->test1addr = 0x47;
    if (ztest != 0) {
        env->test1 = 0x10000 | ((u64)(ztest & 3) << 17);
    } else {
        env->test1 = 0x30000;
    }

    return 8;
}
#endif

}
