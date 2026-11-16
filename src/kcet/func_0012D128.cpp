/* Function: func_0012D128
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
asm void *func_0012D128(int key, void *table, int count) {
    .word 0x27bdff70 // 0012d128:  addiu $sp, $sp, -0x90
    .word 0xffb70070 // 0012d12c:  sd $s7, 0x70($sp)
    .word 0xffb60060 // 0012d130:  sd $s6, 0x60($sp)
    .word 0x0000b82d // 0012d134:  move $s7, $zero
    .word 0xffb50050 // 0012d138:  sd $s5, 0x50($sp)
    .word 0x00a0b02d // 0012d13c:  move $s6, $a1
    .word 0xffb40040 // 0012d140:  sd $s4, 0x40($sp)
    .word 0x0000a82d // 0012d144:  move $s5, $zero
    .word 0xffb30030 // 0012d148:  sd $s3, 0x30($sp)
    .word 0x0080a02d // 0012d14c:  move $s4, $a0
    .word 0xffbf0080 // 0012d150:  sd $ra, 0x80($sp)
    .word 0x00c0982d // 0012d154:  move $s3, $a2
    .word 0xffb20020 // 0012d158:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012d15c:  sd $s1, 0x10($sp)
    .word 0x12c00017 // 0012d160:  beqz $s6, 0x12d1c0
    .word 0xffb00000 // 0012d164:  sd $s0, ($sp)
    .word 0x02751023 // 0012d168:  subu $v0, $s3, $s5
    .word 0x00000000 // 0012d16c:  nop
    .word 0x00021fc2 // 0012d170:  srl $v1, $v0, 0x1f
    .word 0x00431021 // 0012d174:  addu $v0, $v0, $v1
    .word 0x00029043 // 0012d178:  sra $s2, $v0, 1
    .word 0x02558021 // 0012d17c:  addu $s0, $s2, $s5
    .word 0x001010c0 // 0012d180:  sll $v0, $s0, 3
    .word 0x00568821 // 0012d184:  addu $s1, $v0, $s6
    .word 0x0c04b2c4 // 0012d188:  jal 0x12cb10
    .word 0x96240000 // 0012d18c:  lhu $a0, ($s1)
    .word 0x0040182d // 0012d190:  move $v1, $v0
    .word 0x0283102a // 0012d194:  slt $v0, $s4, $v1
    .word 0x10400003 // 0012d198:  beqz $v0, 0x12d1a8
    .word 0x0074102a // 0012d19c:  slt $v0, $v1, $s4
    .word 0x10000005 // 0012d1a0:  b 0x12d1b8
    .word 0x0200982d // 0012d1a4:  move $s3, $s0
    .word 0x14400003 // 0012d1a8:  bnez $v0, 0x12d1b8
    .word 0x26150001 // 0012d1ac:  addiu $s5, $s0, 1
    .word 0x10000003 // 0012d1b0:  b 0x12d1c0
    .word 0x0220b82d // 0012d1b4:  move $s7, $s1
    .word 0x1640ffed // 0012d1b8:  bnez $s2, 0x12d170
    .word 0x02751023 // 0012d1bc:  subu $v0, $s3, $s5
    .word 0x02e0102d // 0012d1c0:  move $v0, $s7
    .word 0xdfbf0080 // 0012d1c4:  ld $ra, 0x80($sp)
    .word 0xdfb70070 // 0012d1c8:  ld $s7, 0x70($sp)
    .word 0xdfb60060 // 0012d1cc:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012d1d0:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012d1d4:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012d1d8:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012d1dc:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012d1e0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012d1e4:  ld $s0, ($sp)
    .word 0x03e00008 // 0012d1e8:  jr $ra
    .word 0x27bd0090 // 0012d1ec:  addiu $sp, $sp, 0x90
}
#else

int func_0012CB10(u16);

struct FileRecord {
    u16 id;
    u16 pad[3];
};

void *func_0012D128(int key, void *table, int count) {
    void *res = 0;
    int low = 0;
    int high = count;

    if (table != 0) {
        int half;
        do {
            half = (high - low) / 2;
            int mid = low + half;
            FileRecord *entry = (FileRecord *)table + mid;
            int val = func_0012CB10(entry->id);
            if (key < val) {
                high = mid;
            } else {
                if (val >= key) {
                    res = entry;
                    break;
                }
                low = mid + 1;
            }
        } while (half != 0);
    }
    return res;
}

#endif

}
