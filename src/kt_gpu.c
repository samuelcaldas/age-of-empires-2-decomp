#include "common.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef void (*FuncPtr)(void *, void *);

extern const u128 D_38C730;
extern FuncPtr D_38C740[];
extern const char D_48F1B8[];
extern const char D_48F1C8[];

void func_1045E8(void *p, u128 q);
int func_123A70(void *p);
void func_1046A8(void *p, int reg, u64 val);
void func_114320(const char *file, int line, const char *expr);
void func_104448(void *p, int, int, int);
void func_104600(void *p);

/* 0x00125808 (handler 23) */
void func_00125808(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 6, data[1]);
}

/* 0x00125858 (handler 24) */
void func_00125858(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 20, data[1]);
}

/* 0x001258A8 (handler 25) */
void func_001258A8(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, func_123A70(data) + 22, data[1]);
}

/* 0x001258F8 (handler 26) */
void func_001258F8(void *p, u64 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x3B, data[1]);
}

/* 0x00125940 (handler 27) */
void func_00125940(void *p, u32 *data) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x1C, data[1]);
}

/* 0x00125988 (handler 28) */
void func_00125988(void *p) {
    func_1045E8(p, D_38C730);
    func_1046A8(p, 0x3F, 0);
}

/* 0x001259C8 (dispatcher) */
void func_001259C8(void *p, u8 *cmd, int flag) {
    u8 kind = *cmd;
    if (kind >= 29) {
        func_114320(D_48F1B8, 630, D_48F1C8);
    }
    if (!flag) {
        func_104448(p, 0, 0, 0);
    }
    D_38C740[kind](p, cmd);
    func_104600(p);
}

/* 0x00125A70 */
void *func_00125A70(int idx);
__asm__(
    ".text\n\t"
    ".p2align 3\n\t"
    ".globl func_00125A70\n\t"
    ".ent func_00125A70\n"
    "func_00125A70:\n\t"
    ".set noreorder\n\t"
    "lui   $2, %hi(D_4EA148)\n\t"
    "daddu $6, $4, $0\n\t"
    "addiu $4, $2, %lo(D_4EA148)\n\t"
    "lw    $3, 4($4)\n\t"
    "sltu  $3, $6, $3\n\t"
    "beqz  $3, 1f\n\t"
    "lw    $5, %lo(D_4EA148)($2)\n\t"
    "sll   $2, $6, 9\n\t"
    "b     2f\n\t"
    "addu  $5, $5, $2\n"
    "1:\n\t"
    "daddu $5, $0, $0\n"
    "2:\n\t"
    "jr    $31\n\t"
    "daddu $2, $5, $0\n\t"
    "nop\n\t"
    ".set reorder\n\t"
    ".end func_00125A70\n"
);

/* 0x00125AA8 */
void func_00125AA8(void);
__asm__(
    ".text\n\t"
    ".p2align 3\n\t"
    ".globl func_00125AA8\n\t"
    ".ent func_00125AA8\n"
    "func_00125AA8:\n\t"
    ".set noreorder\n\t"
    "lui   $2, %hi(D_4EA148+8)\n\t"
    "lw    $4, %lo(D_4EA148+8)($2)\n\t"
    "bltz  $4, 1f\n\t"
    "nop\n\t"
    "j     func_134500\n\t"
    "nop\n"
    "1:\n\t"
    "jr    $31\n\t"
    "nop\n\t"
    ".set reorder\n\t"
    ".end func_00125AA8\n"
);

/* 0x00125AC8 */
void func_00125AC8(void);
__asm__(
    ".text\n\t"
    ".p2align 3\n\t"
    ".globl func_00125AC8\n\t"
    ".ent func_00125AC8\n"
    "func_00125AC8:\n\t"
    ".set noreorder\n\t"
    "lui   $2, %hi(D_4EA148+8)\n\t"
    "lw    $4, %lo(D_4EA148+8)($2)\n\t"
    "bltz  $4, 1f\n\t"
    "nop\n\t"
    "j     func_134440\n\t"
    "nop\n"
    "1:\n\t"
    "jr    $31\n\t"
    "nop\n\t"
    ".set reorder\n\t"
    ".end func_00125AC8\n"
);

/* 0x00125AE8 */
void func_00125AE8(int a0, int a1);
__asm__(
    ".text\n\t"
    ".globl func_00125AE8\n\t"
    ".ent func_00125AE8\n"
    "func_00125AE8:\n\t"
    "addiu $6, $28, -0x7c00\n\t"
    "j func_10D8B0\n\t"
    "nop\n\t"
    ".end func_00125AE8\n"
);

/* 0x00125AF8 */
int func_00125AF8(void);
__asm__(
    ".text\n\t"
    ".p2align 3\n\t"
    ".globl func_00125AF8\n\t"
    ".ent func_00125AF8\n"
    "func_00125AF8:\n\t"
    ".set noreorder\n\t"
    "addiu $29, $29, -160\n\t"
    "sd $23, 112($29)\n\t"
    "sd $22, 96($29)\n\t"
    "lui $23, %hi(D_4EA148)\n\t"
    "sd $19, 48($29)\n\t"
    "addiu $2, $23, %lo(D_4EA148)\n\t"
    "sd $31, 144($29)\n\t"
    "addiu $22, $0, 1\n\t"
    "sd $30, 128($29)\n\t"
    "sd $20, 64($29)\n\t"
    "sd $18, 32($29)\n\t"
    "sd $17, 16($29)\n\t"
    "sd $16, 0($29)\n\t"
    "sd $21, 80($29)\n\t"
    "lw $21, 4($2)\n\t"
    "blez $21, 2f\n\t"
    "daddu $19, $0, $0\n\t"
    "addiu $20, $0, -1\n\t"
    "addiu $30, $0, 1\n\t"
    "nop\n"
    "1:\n\t"
    "jal func_00125A70\n\t"
    "daddu $4, $19, $0\n\t"
    "daddu $16, $2, $0\n\t"
    "lw $17, 108($16)\n\t"
    "beq $17, $20, 3f\n\t"
    "lw $18, 112($16)\n\t"
    "beq $18, $20, 3f\n\t"
    "lui $3, 2\n\t"
    "lw $2, 176($16)\n\t"
    "and $2, $2, $3\n\t"
    "beqz $2, 4f\n\t"
    "daddu $4, $17, $0\n\t"
    "jal func_00125AE8\n\t"
    "daddu $5, $18, $0\n"
    "4:\n\t"
    "daddu $4, $17, $0\n\t"
    "jal func_10D0F8\n\t"
    "daddu $5, $18, $0\n\t"
    "bnel $2, $30, 3f\n\t"
    "daddu $22, $0, $0\n\t"
    "sw $20, 112($16)\n\t"
    "sw $20, 108($16)\n"
    "3:\n\t"
    "addiu $19, $19, 1\n\t"
    "slt $2, $19, $21\n\t"
    "bnez $2, 1b\n\t"
    "nop\n"
    "2:\n\t"
    "beqz $22, 5f\n\t"
    "daddu $2, $22, $0\n\t"
    "jal func_10CE90\n\t"
    "nop\n\t"
    "addiu $3, $0, 1\n\t"
    "beq $2, $3, 6f\n\t"
    "lui $2, %hi(D_4EA148)\n\t"
    "b 7f\n\t"
    "daddu $22, $0, $0\n"
    "6:\n\t"
    "addiu $16, $2, %lo(D_4EA148)\n\t"
    "lw $2, 12($16)\n\t"
    "andi $2, $2, 1\n\t"
    "beqz $2, 8f\n\t"
    "nop\n\t"
    "jal func_116F68\n\t"
    "lw $4, -24248($23)\n\t"
    "lw $2, 12($16)\n\t"
    "addiu $3, $0, -2\n\t"
    "and $2, $2, $3\n\t"
    "sw $2, 12($16)\n"
    "8:\n\t"
    "jal func_1344C0\n\t"
    "lw $4, 8($16)\n"
    "7:\n\t"
    "daddu $2, $22, $0\n"
    "5:\n\t"
    "ld $31, 144($29)\n\t"
    "ld $30, 128($29)\n\t"
    "ld $23, 112($29)\n\t"
    "ld $22, 96($29)\n\t"
    "ld $21, 80($29)\n\t"
    "ld $20, 64($29)\n\t"
    "ld $19, 48($29)\n\t"
    "ld $18, 32($29)\n\t"
    "ld $17, 16($29)\n\t"
    "ld $16, 0($29)\n\t"
    "jr $31\n\t"
    "addiu $29, $29, 160\n\t"
    ".set reorder\n\t"
    ".end func_00125AF8\n"
);
