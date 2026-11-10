#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
char *strcpy(char *dest, const char *src);
void *func_100850(unsigned int size);
void func_2F61F0(void *obj, void *cfg, int arg);
void func_00219F60();

asm void func_0021BDF0() {
    .word 0x3C0200C6 /* lui        $v0, (0xC60000 >> 16) */
    .word 0x2444E318 /* addiu      $a0, $v0, -0x1CE8 */
    .word 0x27BDFFE0 /* addiu      $sp, $sp, -0x20 */
    .word 0x3C020049 /* lui        $v0, (0x490000 >> 16) */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x24452C70 /* addiu      $a1, $v0, 0x2C70 */
    jal strcpy
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x3C0200C6 /* lui        $v0, (0xC60000 >> 16) */
    .word 0x2444E328 /* addiu      $a0, $v0, -0x1CD8 */
    .word 0x3C020049 /* lui        $v0, (0x490000 >> 16) */
    jal strcpy
    .word 0x24452C78 /* addiu      $a1, $v0, 0x2C78 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E300 /* sw         $zero, -0x1D00($at) */
    .word 0x24040001 /* addiu      $a0, $zero, 0x1 */
    .word 0xC7808044 /* lwc1       $f0, -0x7FBC($gp) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E304 /* sw         $a0, -0x1CFC($at) */
    .word 0x24030003 /* addiu      $v1, $zero, 0x3 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E308 /* sw         $v1, -0x1CF8($at) */
    .word 0x24020008 /* addiu      $v0, $zero, 0x8 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC22E338 /* sw         $v0, -0x1CC8($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E33C /* sw         $zero, -0x1CC4($at) */
    .word 0x24020009 /* addiu      $v0, $zero, 0x9 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xA422E340 /* sh         $v0, -0x1CC0($at) */
    .word 0x2402000F /* addiu      $v0, $zero, 0xF */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xA422E342 /* sh         $v0, -0x1CBE($at) */
    .word 0x24020063 /* addiu      $v0, $zero, 0x63 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xA422E344 /* sh         $v0, -0x1CBC($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E348 /* sw         $a0, -0x1CB8($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E34C /* sw         $a0, -0x1CB4($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E350 /* sw         $zero, -0x1CB0($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E354 /* sw         $a0, -0x1CAC($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E358 /* sw         $a0, -0x1CA8($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E35C /* sw         $a0, -0x1CA4($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E360 /* sw         $zero, -0x1CA0($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E364 /* sw         $a0, -0x1C9C($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E368 /* sw         $a0, -0x1C98($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E37C /* sw         $a0, -0x1C84($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24E380 /* sw         $a0, -0x1C80($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E388 /* sw         $v1, -0x1C78($at) */
    .word 0x24030054 /* addiu      $v1, $zero, 0x54 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E38C /* sw         $v1, -0x1C74($at) */
    .word 0x3C023F80 /* lui        $v0, (0x3F800000 >> 16) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC22E390 /* sw         $v0, -0x1C70($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E394 /* sw         $v1, -0x1C6C($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC22E398 /* sw         $v0, -0x1C68($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xE420E39C /* swc1       $f0, -0x1C64($at) */
    .word 0x24020002 /* addiu      $v0, $zero, 0x2 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xA422E3A0 /* sh         $v0, -0x1C60($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E36C /* sw         $zero, -0x1C94($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E370 /* sw         $zero, -0x1C90($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E374 /* sw         $zero, -0x1C8C($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC20E378 /* sw         $zero, -0x1C88($at) */
    .word 0x24030280 /* addiu      $v1, $zero, 0x280 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E3A4 /* sw         $v1, -0x1C5C($at) */
    .word 0x240201C0 /* addiu      $v0, $zero, 0x1C0 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC22E3A8 /* sw         $v0, -0x1C58($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E3B4 /* sw         $v1, -0x1C4C($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC22E3B8 /* sw         $v0, -0x1C48($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23E3AC /* sw         $v1, -0x1C54($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x24041948 /* addiu      $a0, $zero, 0x1948 */
    jal func_100850
    .word 0xAC22E3B0 /* sw         $v0, -0x1C50($at) */
    .word 0x10400006 /* beqz       $v0, .L0021BF98 */
    .word 0x70408628 /* paddub     $s0, $v0, $zero */
    .word 0x3C0200C6 /* lui        $v0, (0xC60000 >> 16) */
    .word 0x2445E300 /* addiu      $a1, $v0, -0x1D00 */
    .word 0x24060001 /* addiu      $a2, $zero, 0x1 */
    jal func_2F61F0
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    jal func_00219F60
    .word 0xAF908B24 /* sw         $s0, -0x74DC($gp) */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0020 /* addiu      $sp, $sp, 0x20 */
}

}

#else

extern "C" {
char *strcpy(char *dest, const char *src);
void *func_100850(unsigned int size);
void func_2F61F0(void *obj, void *cfg, int arg);
void func_00219F60();

extern char D_00C5E300[];
extern void *D_004E32E4;

static void InitConfigStrings(char *cfg) {
    strcpy(cfg + 0x18, "palette");
    strcpy(cfg + 0x28, "mcursors");
}

static void InitConfigFlags(char *cfg) {
    *(int *)(cfg + 0x00) = 0;
    *(int *)(cfg + 0x04) = 1;
    *(int *)(cfg + 0x08) = 3;
    *(int *)(cfg + 0x38) = 8;
    *(int *)(cfg + 0x3C) = 0;
    *(short *)(cfg + 0x40) = 9;
    *(short *)(cfg + 0x42) = 15;
    *(short *)(cfg + 0x44) = 99;
    *(int *)(cfg + 0x48) = 1;
    *(int *)(cfg + 0x4C) = 1;
    *(int *)(cfg + 0x50) = 0;
    *(int *)(cfg + 0x54) = 1;
    *(int *)(cfg + 0x58) = 1;
    *(int *)(cfg + 0x5C) = 1;
    *(int *)(cfg + 0x60) = 0;
    *(int *)(cfg + 0x64) = 1;
    *(int *)(cfg + 0x68) = 1;
    *(int *)(cfg + 0x6C) = 0;
    *(int *)(cfg + 0x70) = 0;
    *(int *)(cfg + 0x74) = 0;
    *(int *)(cfg + 0x78) = 0;
    *(int *)(cfg + 0x7C) = 1;
    *(int *)(cfg + 0x80) = 1;
}

static void InitConfigDisplay(char *cfg) {
    *(int *)(cfg + 0x88) = 3;
    *(int *)(cfg + 0x8C) = 0x54;
    *(float *)(cfg + 0x90) = 1.0f;
    *(int *)(cfg + 0x94) = 0x54;
    *(float *)(cfg + 0x98) = 1.0f;
    *(float *)(cfg + 0x9C) = 0.05f;
    *(short *)(cfg + 0xA0) = 2;
    *(int *)(cfg + 0xA4) = 640;
    *(int *)(cfg + 0xA8) = 448;
    *(int *)(cfg + 0xAC) = 640;
    *(int *)(cfg + 0xB0) = 448;
    *(int *)(cfg + 0xB4) = 640;
    *(int *)(cfg + 0xB8) = 448;
}

static void SetupMasterConfig() {
    InitConfigStrings(D_00C5E300);
    InitConfigFlags(D_00C5E300);
    InitConfigDisplay(D_00C5E300);
}

void func_0021BDF0() {
    SetupMasterConfig();

    void *obj = func_100850(0x1948);
    if (obj != 0) {
        func_2F61F0(obj, D_00C5E300, 1);
    }
    func_00219F60();
    D_004E32E4 = obj;
}
}

#endif
