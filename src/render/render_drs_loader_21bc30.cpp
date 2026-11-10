#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

extern "C" {
int func_12C388(int lba, int num_sectors, void *target_buffer, int *out_status);
void *func_117AF8(void *dst, const void *src, int len);

asm int func_0021BC30(void *stream_info, void *dest, int offset, int count, int direct_flag) {
    .word 0x27BDFF40 /* addiu      $sp, $sp, -0xC0 */
    .word 0x7FBF0090 /* sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x8C910004 /* lw         $s1, 0x4($a0) */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x70A08628 /* paddub     $s0, $a1, $zero */
    .word 0x12800004 /* beqz       $s4, .L0021BC7C */
    .word 0x70E0AE28 /* paddub     $s5, $a3, $zero */
    .word 0x001412C2 /* srl        $v0, $s4, 11 */
    .word 0x02228821 /* addu       $s1, $s1, $v0 */
    .word 0x329407FF /* andi       $s4, $s4, 0x7FF */
    .word 0x16A00004 /* bnez       $s5, .L0021BC90 */
    .word 0x02B49021 /* addu       $s2, $s5, $s4 */
    .word 0x8C950000 /* lw         $s5, 0x0($a0) */
    .word 0x00000000 /* nop */
    .word 0x02B49021 /* addu       $s2, $s5, $s4 */
    .word 0x324207FF /* andi       $v0, $s2, 0x7FF */
    .word 0x10400005 /* beqz       $v0, .L0021BCAC */
    .word 0x7000B628 /* paddub     $s6, $zero, $zero */
    .word 0x2402F800 /* addiu      $v0, $zero, -0x800 */
    .word 0x02421024 /* and        $v0, $s2, $v0 */
    .word 0x24520800 /* addiu      $s2, $v0, 0x800 */
    .word 0x7000B628 /* paddub     $s6, $zero, $zero */
    .word 0x15000007 /* bnez       $t0, .L0021BCCC */
    .word 0x7200BE28 /* paddub     $s7, $s0, $zero */
    .word 0x16800008 /* bnez       $s4, .L0021BCD8 */
    .word 0x3C0201E9 /* lui        $v0, (0x1E98000 >> 16) */
    .word 0x32A207FF /* andi       $v0, $s5, 0x7FF */
    .word 0x14400004 /* bnez       $v0, .L0021BCD4 */
    .word 0x00000000 /* nop */
    .word 0x7200BE28 /* paddub     $s7, $s0, $zero */
    .word 0x10000004 /* b          .L0021BCE0 */
    .word 0x00000000 /* nop */
    .word 0x3C0201E9 /* lui        $v0, (0x1E98000 >> 16) */
    .word 0x24160001 /* addiu      $s6, $zero, 0x1 */
    .word 0x34578000 /* ori        $s7, $v0, (0x1E98000 & 0xFFFF) */
    .word 0x12C00009 /* beqz       $s6, .L0021BD08 */
    .word 0x72409E28 /* paddub     $s3, $s2, $zero */
    .word 0x3C010010 /* lui        $at, (0x100001 >> 16) */
    .word 0x34210001 /* ori        $at, $at, (0x100001 & 0xFFFF) */
    .word 0x0241082B /* sltu       $at, $s2, $at */
    .word 0x14200003 /* bnez       $at, .L0021BD04 */
    .word 0x00000000 /* nop */
    .word 0x10000002 /* b          .L0021BD08 */
    .word 0x3C130010 /* lui        $s3, (0x100000 >> 16) */
    .word 0x72409E28 /* paddub     $s3, $s2, $zero */
    .word 0x8F828B20 /* lw         $v0, -0x74E0($gp) */
    .word 0x1440000E /* bnez       $v0, .L0021BD48 */
    .word 0x00000000 /* nop */
    .word 0x0013F2C3 /* sra        $fp, $s3, 11 */
    .word 0x26227FFF /* addiu      $v0, $s1, 0x7FFF */
    .word 0x24444351 /* addiu      $a0, $v0, 0x4351 */
    .word 0x27A700A0 /* addiu      $a3, $sp, 0xA0 */
    .word 0x73C02E28 /* paddub     $a1, $fp, $zero */
    jal func_12C388
    .word 0x72E03628 /* paddub     $a2, $s7, $zero */
    .word 0x1040FFFA /* beqz       $v0, .L0021BD1C */
    .word 0x26227FFF /* addiu      $v0, $s1, 0x7FFF */
    .word 0x8FA300A0 /* lw         $v1, 0xA0($sp) */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x1462FFF5 /* bne        $v1, $v0, .L0021BD18 */
    .word 0x00000000 /* nop */
    .word 0x12C0000D /* beqz       $s6, .L0021BD80 */
    .word 0x001312C3 /* sra        $v0, $s3, 11 */
    .word 0x02F42821 /* addu       $a1, $s7, $s4 */
    .word 0x0274A023 /* subu       $s4, $s3, $s4 */
    .word 0x02B4082B /* sltu       $at, $s5, $s4 */
    .word 0x10200003 /* beqz       $at, .L0021BD6C */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x72A0A628 /* paddub     $s4, $s5, $zero */
    .word 0x72002628 /* paddub     $a0, $s0, $zero */
    .word 0x72803628 /* paddub     $a2, $s4, $zero */
    jal func_117AF8
    .word 0x02B4A823 /* subu       $s5, $s5, $s4 */
    .word 0x02148021 /* addu       $s0, $s0, $s4 */
    .word 0x001312C3 /* sra        $v0, $s3, 11 */
    .word 0x02539023 /* subu       $s2, $s2, $s3 */
    .word 0x02228821 /* addu       $s1, $s1, $v0 */
    .word 0x1640FFD5 /* bnez       $s2, .L0021BCE0 */
    .word 0x7000A628 /* paddub     $s4, $zero, $zero */
    .word 0x7BBF0090 /* lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD00C0 /* addiu      $sp, $sp, 0xC0 */
}

asm int func_0021BDD0() {
    .word 0x3C020001 /* lui        $v0, (0x175E9 >> 16) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x344275E9 /* ori        $v0, $v0, (0x175E9 & 0xFFFF) */
}

asm void func_0021BDE0(int val) {
    .word 0x03E00008 /* jr         $ra */
    .word 0xAF848B20 /* sw         $a0, -0x74E0($gp) */
}

}

#else

extern "C" {
int func_12C388(int lba, int num_sectors, void *target_buffer, int *out_status);
void *func_117AF8(void *dst, const void *src, int len);

extern int D_004E32E0;
extern char D_01E98000[];

int func_0021BDD0() {
    return 0x175E9;
}

void func_0021BDE0(int val) {
    D_004E32E0 = val;
}

static void ReadSectorsBlocking(int lba, int num_sectors, void *target_buffer) {
    int status = 0;
    while (!func_12C388(lba, num_sectors, target_buffer, &status) || status != 1) {
    }
}

static void CopyStagedData(char **dest_ptr, const char *src_buffer, int intra_sector_offset, int chunk_size, int *remaining_count) {
    int available = chunk_size - intra_sector_offset;
    int to_copy = *remaining_count;
    if (available < to_copy) {
        to_copy = available;
    }
    func_117AF8(*dest_ptr, src_buffer + intra_sector_offset, to_copy);
    *remaining_count -= to_copy;
    *dest_ptr += to_copy;
}

static int CalculateTotalRounded(int count, int intra_sector_offset) {
    int total = count + intra_sector_offset;
    if ((total & 0x7FF) == 0) {
        return total;
    }
    return (total & ~0x7FF) + 0x800;
}

static int DetermineStaging(int direct_flag, int intra_sector_offset, int count) {
    if (direct_flag != 0) {
        return 0;
    }
    if (intra_sector_offset != 0) {
        return 1;
    }
    if ((count & 0x7FF) != 0) {
        return 1;
    }
    return 0;
}

int func_0021BC30(void *stream_info, void *dest, int offset, int count, int direct_flag) {
    char *stream = (char *)stream_info;
    int sector_base = *(int *)(stream + 4);
    int intra_sector_offset = 0;

    if (offset != 0) {
        sector_base += offset >> 11;
        intra_sector_offset = offset & 0x7FF;
    }

    if (count == 0) {
        count = *(int *)stream;
    }

    int remaining_total = CalculateTotalRounded(count, intra_sector_offset);
    int use_staging = DetermineStaging(direct_flag, intra_sector_offset, count);

    char *target_buffer = (char *)dest;
    if (use_staging != 0) {
        target_buffer = D_01E98000;
    }

    char *dest_ptr = (char *)dest;

    while (remaining_total != 0) {
        int chunk_size = remaining_total;
        if (use_staging != 0 && chunk_size > 0x100000) {
            chunk_size = 0x100000;
        }

        if (D_004E32E0 == 0) {
            int num_sectors = chunk_size >> 11;
            ReadSectorsBlocking(sector_base + 0xC350, num_sectors, target_buffer);
        }

        if (use_staging != 0) {
            CopyStagedData(&dest_ptr, target_buffer, intra_sector_offset, chunk_size, &count);
        }

        int sectors_done = chunk_size >> 11;
        remaining_total -= chunk_size;
        sector_base += sectors_done;
        intra_sector_offset = 0;
    }

    return 1;
}
}

#endif
