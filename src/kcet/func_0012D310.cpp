/* Function: func_0012D310 (0x0012D310 - 0x0012D400)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
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
asm void *func_0012D310(void *arg) {
    .word 0x27bdff60 // 0012d310:  addiu $sp, $sp, -0xa0
    .word 0xffb70070 // 0012d314:  sd $s7, 0x70($sp)
    .word 0xffb60060 // 0012d318:  sd $s6, 0x60($sp)
    .word 0x24970004 // 0012d31c:  addiu $s7, $a0, 4
    .word 0xffb50050 // 0012d320:  sd $s5, 0x50($sp)
    .word 0xffb40040 // 0012d324:  sd $s4, 0x40($sp)
    .word 0x0000a82d // 0012d328:  move $s5, $zero
    .word 0xffbf0090 // 0012d32c:  sd $ra, 0x90($sp)
    .word 0xffbe0080 // 0012d330:  sd $fp, 0x80($sp)
    .word 0xffb30030 // 0012d334:  sd $s3, 0x30($sp)
    .word 0xffb20020 // 0012d338:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012d33c:  sd $s1, 0x10($sp)
    .word 0x0c04b2b8 // 0012d340:  jal 0x12cae0
    .word 0xffb00000 // 0012d344:  sd $s0, ($sp)
    .word 0x0c04b2bc // 0012d348:  jal 0x12caf0
    .word 0x0040a02d // 0012d34c:  move $s4, $v0
    .word 0x1280001d // 0012d350:  beqz $s4, 0x12d3c8
    .word 0x0040b02d // 0012d354:  move $s6, $v0
    .word 0x0000982d // 0012d358:  move $s3, $zero
    .word 0x0000902d // 0012d35c:  move $s2, $zero
    .word 0x10000004 // 0012d360:  b 0x12d374
    .word 0x3c1e0049 // 0012d364:  lui $fp, 0x49
    .word 0x0c04b308 // 0012d368:  jal 0x12cc20
    .word 0x26520001 // 0012d36c:  addiu $s2, $s2, 1
    .word 0x02629821 // 0012d370:  addu $s3, $s3, $v0
    .word 0x0256102a // 0012d374:  slt $v0, $s2, $s6
    .word 0x10400013 // 0012d378:  beqz $v0, 0x12d3c8
    .word 0x02938821 // 0012d37c:  addu $s1, $s4, $s3
    .word 0x0c04b312 // 0012d380:  jal 0x12cc48
    .word 0x0220202d // 0012d384:  move $a0, $s1
    .word 0x0040802d // 0012d388:  move $s0, $v0
    .word 0x16000007 // 0012d38c:  bnez $s0, 0x12d3ac
    .word 0x0200282d // 0012d390:  move $a1, $s0
    .word 0x3c020049 // 0012d394:  lui $v0, 0x49
    .word 0x24050269 // 0012d398:  addiu $a1, $zero, 0x269
    .word 0x2444fea0 // 0012d39c:  addiu $a0, $v0, -0x160
    .word 0x0c0450c8 // 0012d3a0:  jal 0x114320
    .word 0x27c6fec8 // 0012d3a4:  addiu $a2, $fp, -0x138
    .word 0x0200282d // 0012d3a8:  move $a1, $s0
    .word 0x0c046a9e // 0012d3ac:  jal 0x11aa78
    .word 0x02e0202d // 0012d3b0:  move $a0, $s7
    .word 0x1440ffec // 0012d3b4:  bnez $v0, 0x12d368
    .word 0x0220202d // 0012d3b8:  move $a0, $s1
    .word 0x0c04b2fe // 0012d3bc:  jal 0x12cbf8
    .word 0x0220202d // 0012d3c0:  move $a0, $s1
    .word 0x0040a82d // 0012d3c4:  move $s5, $v0
    .word 0x0c04b2c4 // 0012d3c8:  jal 0x12cb10
    .word 0x02a0202d // 0012d3cc:  move $a0, $s5
    .word 0xdfbf0090 // 0012d3d0:  ld $ra, 0x90($sp)
    .word 0xdfbe0080 // 0012d3d4:  ld $fp, 0x80($sp)
    .word 0xdfb70070 // 0012d3d8:  ld $s7, 0x70($sp)
    .word 0xdfb60060 // 0012d3dc:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012d3e0:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012d3e4:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012d3e8:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012d3ec:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012d3f0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012d3f4:  ld $s0, ($sp)
    .word 0x03e00008 // 0012d3f8:  jr $ra
    .word 0x27bd00a0 // 0012d3fc:  addiu $sp, $sp, 0xa0
}
#else

int func_0012CAE0(void);
void *func_0012CAF0(void);
int func_0012CC20(void *);
char *func_0012CC48(void *);
u32 func_0012CBF8(void *);
u32 func_0012CB10(u32);
int strcmp(const char *, const char *);
void func_114320(const char *, int, const char *);

extern const char D_48FEA0[];
extern const char D_48FEC8[];

void *func_0012D310(void *arg) {
    int count = func_0012CAE0();
    char *table = (char *)func_0012CAF0();
    u32 result = 0;

    if (table != 0) {
        int offset = 0;
        int i;
        for (i = 0; i < count; i++) {
            char *entry = table + offset;
            char *name = func_0012CC48(entry);
            if (name == 0) {
                func_114320(D_48FEA0, 0x269, D_48FEC8);
            }
            if (strcmp((char *)arg + 4, name) == 0) {
                result = func_0012CBF8(entry);
                break;
            }
            offset += func_0012CC20(entry);
        }
    }
    return (void *)func_0012CB10(result);
}

#endif

}
