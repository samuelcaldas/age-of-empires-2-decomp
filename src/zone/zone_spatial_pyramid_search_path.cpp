#pragma exceptions off

#include "zone_spatial_pyramid_search_path.h"

extern "C" {
void *func_117CAC(void *dest, int c, int n);
void *func_100850(int size);
}

#if defined(__mips__)

extern "C" asm void func_001D51B0(void *self, void *result) {
    .word 0x27BDFF10 /* 001D51B0: addiu      $sp, $sp, -0xF0 */
    .word 0x7FBF0090 /* 001D51B4: sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* 001D51B8: sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* 001D51BC: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 001D51C0: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001D51C4: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001D51C8: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001D51CC: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001D51D0: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001D51D4: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001D51D8: sq         $s0, 0x0($sp) */
    .word 0x7080B628 /* 001D51DC: paddub     $s6, $a0, $zero */
    .word 0xAFA500EC /* 001D51E0: sw         $a1, 0xEC($sp) */
    .word 0x10000009 /* 001D51E4: b          .L001D520C */
    .word 0x70008628 /* 001D51E8: paddub    $s0, $zero, $zero */
/* .L001D51EC: */
    .word 0x8EC2011C /* 001D51EC: lw         $v0, 0x11C($s6) */
    .word 0x00101880 /* 001D51F0: sll        $v1, $s0, 2 */
    .word 0x8EC600E8 /* 001D51F4: lw         $a2, 0xE8($s6) */
    .word 0x00431021 /* 001D51F8: addu       $v0, $v0, $v1 */
    .word 0x8C440000 /* 001D51FC: lw         $a0, 0x0($v0) */
    jal        func_117CAC /* 001D5200: jal        func_117CAC */
    .word 0x24050001 /* 001D5204: addiu     $a1, $zero, 0x1 */
    .word 0x26100001 /* 001D5208: addiu      $s0, $s0, 0x1 */
/* .L001D520C: */
    .word 0x8EC300E4 /* 001D520C: lw         $v1, 0xE4($s6) */
    .word 0x0203182A /* 001D5210: slt        $v1, $s0, $v1 */
    .word 0x1460FFF5 /* 001D5214: bnez       $v1, .L001D51EC */
    .word 0x00000000 /* 001D5218: nop */
    .word 0x100000EA /* 001D521C: b          .L001D55C8 */
    .word 0x7000AE28 /* 001D5220: paddub    $s5, $zero, $zero */
    .word 0x70008628 /* 001D5224: paddub     $s0, $zero, $zero */
/* .L001D5228: */
    .word 0x100000E2 /* 001D5228: b          .L001D55B4 */
    .word 0x0015A080 /* 001D522C: sll       $s4, $s5, 2 */
/* .L001D5230: */
    .word 0x8EC3011C /* 001D5230: lw         $v1, 0x11C($s6) */
    .word 0x02831821 /* 001D5234: addu       $v1, $s4, $v1 */
    .word 0x8C630000 /* 001D5238: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D523C: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D5240: lbu        $v1, 0x0($v1) */
    .word 0x506000DB /* 001D5244: beql       $v1, $zero, .L001D55B4 */
    .word 0x26100001 /* 001D5248: addiu     $s0, $s0, 0x1 */
    .word 0x8EC30120 /* 001D524C: lw         $v1, 0x120($s6) */
    .word 0x02831821 /* 001D5250: addu       $v1, $s4, $v1 */
    .word 0x8C630000 /* 001D5254: lw         $v1, 0x0($v1) */
    .word 0x00701821 /* 001D5258: addu       $v1, $v1, $s0 */
    .word 0x90630000 /* 001D525C: lbu        $v1, 0x0($v1) */
    .word 0x106000D3 /* 001D5260: beqz       $v1, .L001D55B0 */
    .word 0x00000000 /* 001D5264: nop */
    .word 0x306400FF /* 001D5268: andi       $a0, $v1, 0xFF */
    .word 0x00101840 /* 001D526C: sll        $v1, $s0, 1 */
    .word 0x7000F628 /* 001D5270: paddub     $fp, $zero, $zero */
    .word 0x100000CB /* 001D5274: b          .L001D55A4 */
    .word 0xAFA300C0 /* 001D5278: sw        $v1, 0xC0($sp) */
    .word 0x308300FF /* 001D527C: andi       $v1, $a0, 0xFF */
/* .L001D5280: */
    .word 0xAFA300D0 /* 001D5280: sw         $v1, 0xD0($sp) */
    .word 0x8FA300D0 /* 001D5284: lw         $v1, 0xD0($sp) */
    .word 0x30640001 /* 001D5288: andi       $a0, $v1, 0x1 */
    .word 0x24030001 /* 001D528C: addiu      $v1, $zero, 0x1 */
    .word 0x148300C0 /* 001D5290: bne        $a0, $v1, .L001D5594 */
    .word 0x00000000 /* 001D5294: nop */
    .word 0x03C31004 /* 001D5298: sllv       $v0, $v1, $fp */
    .word 0xA3A200B0 /* 001D529C: sb         $v0, 0xB0($sp) */
    .word 0x27C20001 /* 001D52A0: addiu      $v0, $fp, 0x1 */
    .word 0x8EC300EC /* 001D52A4: lw         $v1, 0xEC($s6) */
    .word 0xAFA200A0 /* 001D52A8: sw         $v0, 0xA0($sp) */
    .word 0x8EC20000 /* 001D52AC: lw         $v0, 0x0($s6) */
    .word 0x8FA400C0 /* 001D52B0: lw         $a0, 0xC0($sp) */
    .word 0x72A09628 /* 001D52B4: paddub     $s2, $s5, $zero */
    .word 0x72009E28 /* 001D52B8: paddub     $s3, $s0, $zero */
    .word 0x02A3082A /* 001D52BC: slt        $at, $s5, $v1 */
    .word 0x7000BE28 /* 001D52C0: paddub     $s7, $zero, $zero */
    .word 0x8C420000 /* 001D52C4: lw         $v0, 0x0($v0) */
    .word 0x02821021 /* 001D52C8: addu       $v0, $s4, $v0 */
    .word 0x8C450000 /* 001D52CC: lw         $a1, 0x0($v0) */
    .word 0x00852021 /* 001D52D0: addu       $a0, $a0, $a1 */
    .word 0x90850000 /* 001D52D4: lbu        $a1, 0x0($a0) */
    .word 0x10200014 /* 001D52D8: beqz       $at, .L001D532C */
    .word 0x0005882B /* 001D52DC: sltu      $s1, $zero, $a1 */
    .word 0x93A500B0 /* 001D52E0: lbu        $a1, 0xB0($sp) */
    .word 0x70A03628 /* 001D52E4: paddub     $a2, $a1, $zero */
    .word 0x8EC50120 /* 001D52E8: lw         $a1, 0x120($s6) */
    .word 0x02852821 /* 001D52EC: addu       $a1, $s4, $a1 */
    .word 0x8CA50004 /* 001D52F0: lw         $a1, 0x4($a1) */
    .word 0x02052821 /* 001D52F4: addu       $a1, $s0, $a1 */
    .word 0x90A50000 /* 001D52F8: lbu        $a1, 0x0($a1) */
    .word 0x14C5000C /* 001D52FC: bne        $a2, $a1, .L001D5330 */
    .word 0x02A3082A /* 001D5300: slt       $at, $s5, $v1 */
    .word 0x8C460004 /* 001D5304: lw         $a2, 0x4($v0) */
    .word 0x8FA500C0 /* 001D5308: lw         $a1, 0xC0($sp) */
    .word 0x322700FF /* 001D530C: andi       $a3, $s1, 0xFF */
    .word 0x00A62821 /* 001D5310: addu       $a1, $a1, $a2 */
    .word 0x90A50000 /* 001D5314: lbu        $a1, 0x0($a1) */
    .word 0x0005282B /* 001D5318: sltu       $a1, $zero, $a1 */
    .word 0x14E50003 /* 001D531C: bne        $a3, $a1, .L001D532C */
    .word 0x00000000 /* 001D5320: nop */
    .word 0x10000046 /* 001D5324: b          .L001D5440 */
    .word 0x64170004 /* 001D5328: daddiu    $s7, $zero, 0x4 */
/* .L001D532C: */
    .word 0x02A3082A /* 001D532C: slt        $at, $s5, $v1 */
/* .L001D5330: */
    .word 0x10200018 /* 001D5330: beqz       $at, .L001D5394 */
    .word 0x00000000 /* 001D5334: nop */
    .word 0x8EC500F0 /* 001D5338: lw         $a1, 0xF0($s6) */
    .word 0x0205082A /* 001D533C: slt        $at, $s0, $a1 */
    .word 0x10200014 /* 001D5340: beqz       $at, .L001D5394 */
    .word 0x00000000 /* 001D5344: nop */
    .word 0x93A500B0 /* 001D5348: lbu        $a1, 0xB0($sp) */
    .word 0x70A03628 /* 001D534C: paddub     $a2, $a1, $zero */
    .word 0x8EC50120 /* 001D5350: lw         $a1, 0x120($s6) */
    .word 0x02852821 /* 001D5354: addu       $a1, $s4, $a1 */
    .word 0x8CA50004 /* 001D5358: lw         $a1, 0x4($a1) */
    .word 0x02052821 /* 001D535C: addu       $a1, $s0, $a1 */
    .word 0x90A50001 /* 001D5360: lbu        $a1, 0x1($a1) */
    .word 0x14C5000B /* 001D5364: bne        $a2, $a1, .L001D5394 */
    .word 0x00000000 /* 001D5368: nop */
    .word 0x8C460004 /* 001D536C: lw         $a2, 0x4($v0) */
    .word 0x8FA500C0 /* 001D5370: lw         $a1, 0xC0($sp) */
    .word 0x322700FF /* 001D5374: andi       $a3, $s1, 0xFF */
    .word 0x00A62821 /* 001D5378: addu       $a1, $a1, $a2 */
    .word 0x90A50002 /* 001D537C: lbu        $a1, 0x2($a1) */
    .word 0x0005282B /* 001D5380: sltu       $a1, $zero, $a1 */
    .word 0x14E50003 /* 001D5384: bne        $a3, $a1, .L001D5394 */
    .word 0x00000000 /* 001D5388: nop */
    .word 0x1000002C /* 001D538C: b          .L001D5440 */
    .word 0x6417000C /* 001D5390: daddiu    $s7, $zero, 0xC */
/* .L001D5394: */
    .word 0x8EC500F0 /* 001D5394: lw         $a1, 0xF0($s6) */
    .word 0x0205082A /* 001D5398: slt        $at, $s0, $a1 */
    .word 0x10200011 /* 001D539C: beqz       $at, .L001D53E4 */
    .word 0x00000000 /* 001D53A0: nop */
    .word 0x93A500B0 /* 001D53A4: lbu        $a1, 0xB0($sp) */
    .word 0x70A03628 /* 001D53A8: paddub     $a2, $a1, $zero */
    .word 0x8EC50120 /* 001D53AC: lw         $a1, 0x120($s6) */
    .word 0x02852821 /* 001D53B0: addu       $a1, $s4, $a1 */
    .word 0x8CA50000 /* 001D53B4: lw         $a1, 0x0($a1) */
    .word 0x02052821 /* 001D53B8: addu       $a1, $s0, $a1 */
    .word 0x90A50001 /* 001D53BC: lbu        $a1, 0x1($a1) */
    .word 0x14C50008 /* 001D53C0: bne        $a2, $a1, .L001D53E4 */
    .word 0x00000000 /* 001D53C4: nop */
    .word 0x90840002 /* 001D53C8: lbu        $a0, 0x2($a0) */
    .word 0x322500FF /* 001D53CC: andi       $a1, $s1, 0xFF */
    .word 0x0004202B /* 001D53D0: sltu       $a0, $zero, $a0 */
    .word 0x14A40003 /* 001D53D4: bne        $a1, $a0, .L001D53E4 */
    .word 0x00000000 /* 001D53D8: nop */
    .word 0x10000018 /* 001D53DC: b          .L001D5440 */
    .word 0x64170008 /* 001D53E0: daddiu    $s7, $zero, 0x8 */
/* .L001D53E4: */
    .word 0x1A000017 /* 001D53E4: blez       $s0, .L001D5444 */
    .word 0x2404001C /* 001D53E8: addiu     $a0, $zero, 0x1C */
    .word 0x02A3082A /* 001D53EC: slt        $at, $s5, $v1 */
    .word 0x10200013 /* 001D53F0: beqz       $at, .L001D5440 */
    .word 0x00000000 /* 001D53F4: nop */
    .word 0x93A300B0 /* 001D53F8: lbu        $v1, 0xB0($sp) */
    .word 0x70602628 /* 001D53FC: paddub     $a0, $v1, $zero */
    .word 0x8EC30120 /* 001D5400: lw         $v1, 0x120($s6) */
    .word 0x02831821 /* 001D5404: addu       $v1, $s4, $v1 */
    .word 0x8C630004 /* 001D5408: lw         $v1, 0x4($v1) */
    .word 0x02031821 /* 001D540C: addu       $v1, $s0, $v1 */
    .word 0x9063FFFF /* 001D5410: lbu        $v1, -0x1($v1) */
    .word 0x1483000A /* 001D5414: bne        $a0, $v1, .L001D5440 */
    .word 0x00000000 /* 001D5418: nop */
    .word 0x8C430004 /* 001D541C: lw         $v1, 0x4($v0) */
    .word 0x322400FF /* 001D5420: andi       $a0, $s1, 0xFF */
    .word 0x8FA200C0 /* 001D5424: lw         $v0, 0xC0($sp) */
    .word 0x00431021 /* 001D5428: addu       $v0, $v0, $v1 */
    .word 0x9042FFFE /* 001D542C: lbu        $v0, -0x2($v0) */
    .word 0x0002102B /* 001D5430: sltu       $v0, $zero, $v0 */
    .word 0x14820002 /* 001D5434: bne        $a0, $v0, .L001D5440 */
    .word 0x00000000 /* 001D5438: nop */
    .word 0x64170005 /* 001D543C: daddiu     $s7, $zero, 0x5 */
/* .L001D5440: */
    .word 0x2404001C /* 001D5440: addiu      $a0, $zero, 0x1C */
/* .L001D5444: */
    jal        func_100850 /* 001D5444: jal        func_100850 */
    .word 0x00000000 /* 001D5448: nop */
    .word 0x93A300B0 /* 001D544C: lbu        $v1, 0xB0($sp) */
    .word 0x32E600FF /* 001D5450: andi       $a2, $s7, 0xFF */
    .word 0xAC550008 /* 001D5454: sw         $s5, 0x8($v0) */
    .word 0xAC50000C /* 001D5458: sw         $s0, 0xC($v0) */
    .word 0xAC400000 /* 001D545C: sw         $zero, 0x0($v0) */
    .word 0x30C40008 /* 001D5460: andi       $a0, $a2, 0x8 */
    .word 0x70604628 /* 001D5464: paddub     $t0, $v1, $zero */
    .word 0x30C30004 /* 001D5468: andi       $v1, $a2, 0x4 */
    .word 0x30C50002 /* 001D546C: andi       $a1, $a2, 0x2 */
    .word 0xA0510004 /* 001D5470: sb         $s1, 0x4($v0) */
    .word 0x322700FF /* 001D5474: andi       $a3, $s1, 0xFF */
    .word 0x10000029 /* 001D5478: b          .L001D5520 */
    .word 0x30C60001 /* 001D547C: andi      $a2, $a2, 0x1 */
/* .L001D5480: */
    .word 0x8ECA011C /* 001D5480: lw         $t2, 0x11C($s6) */
    .word 0x70005E28 /* 001D5484: paddub     $t3, $zero, $zero */
    .word 0x01494821 /* 001D5488: addu       $t1, $t2, $t1 */
    .word 0x8D290000 /* 001D548C: lw         $t1, 0x0($t1) */
    .word 0x01334821 /* 001D5490: addu       $t1, $t1, $s3 */
    .word 0xA1200000 /* 001D5494: sb         $zero, 0x0($t1) */
    .word 0xAC520010 /* 001D5498: sw         $s2, 0x10($v0) */
    .word 0xAC530014 /* 001D549C: sw         $s3, 0x14($v0) */
    .word 0x8C490000 /* 001D54A0: lw         $t1, 0x0($v0) */
    .word 0x25290001 /* 001D54A4: addiu      $t1, $t1, 0x1 */
    .word 0x10600007 /* 001D54A8: beqz       $v1, .L001D54C8 */
    .word 0xAC490000 /* 001D54AC: sw        $t1, 0x0($v0) */
    .word 0x8EC900EC /* 001D54B0: lw         $t1, 0xEC($s6) */
    .word 0x0249082A /* 001D54B4: slt        $at, $s2, $t1 */
    .word 0x10200003 /* 001D54B8: beqz       $at, .L001D54C8 */
    .word 0x00000000 /* 001D54BC: nop */
    .word 0x26520001 /* 001D54C0: addiu      $s2, $s2, 0x1 */
    .word 0x640B0001 /* 001D54C4: daddiu     $t3, $zero, 0x1 */
/* .L001D54C8: */
    .word 0x10800007 /* 001D54C8: beqz       $a0, .L001D54E8 */
    .word 0x00000000 /* 001D54CC: nop */
    .word 0x8EC900F0 /* 001D54D0: lw         $t1, 0xF0($s6) */
    .word 0x0269082A /* 001D54D4: slt        $at, $s3, $t1 */
    .word 0x10200003 /* 001D54D8: beqz       $at, .L001D54E8 */
    .word 0x00000000 /* 001D54DC: nop */
    .word 0x26730001 /* 001D54E0: addiu      $s3, $s3, 0x1 */
    .word 0x640B0001 /* 001D54E4: daddiu     $t3, $zero, 0x1 */
/* .L001D54E8: */
    .word 0x10A00005 /* 001D54E8: beqz       $a1, .L001D5500 */
    .word 0x00000000 /* 001D54EC: nop */
    .word 0x1A400003 /* 001D54F0: blez       $s2, .L001D5500 */
    .word 0x00000000 /* 001D54F4: nop */
    .word 0x2652FFFF /* 001D54F8: addiu      $s2, $s2, -0x1 */
    .word 0x640B0001 /* 001D54FC: daddiu     $t3, $zero, 0x1 */
/* .L001D5500: */
    .word 0x10C00005 /* 001D5500: beqz       $a2, .L001D5518 */
    .word 0x00000000 /* 001D5504: nop */
    .word 0x1A600003 /* 001D5508: blez       $s3, .L001D5518 */
    .word 0x00000000 /* 001D550C: nop */
    .word 0x2673FFFF /* 001D5510: addiu      $s3, $s3, -0x1 */
    .word 0x640B0001 /* 001D5514: daddiu     $t3, $zero, 0x1 */
/* .L001D5518: */
    .word 0x11600014 /* 001D5518: beqz       $t3, .L001D556C */
    .word 0x00000000 /* 001D551C: nop */
/* .L001D5520: */
    .word 0x8ECA0120 /* 001D5520: lw         $t2, 0x120($s6) */
    .word 0x00124880 /* 001D5524: sll        $t1, $s2, 2 */
    .word 0x01495021 /* 001D5528: addu       $t2, $t2, $t1 */
    .word 0x8D4A0000 /* 001D552C: lw         $t2, 0x0($t2) */
    .word 0x01535021 /* 001D5530: addu       $t2, $t2, $s3 */
    .word 0x914A0000 /* 001D5534: lbu        $t2, 0x0($t2) */
    .word 0x010A5024 /* 001D5538: and        $t2, $t0, $t2 */
    .word 0x150A000B /* 001D553C: bne        $t0, $t2, .L001D556C */
    .word 0x00000000 /* 001D5540: nop */
    .word 0x8ECA0000 /* 001D5544: lw         $t2, 0x0($s6) */
    .word 0x00135840 /* 001D5548: sll        $t3, $s3, 1 */
    .word 0x8D4A0000 /* 001D554C: lw         $t2, 0x0($t2) */
    .word 0x01495021 /* 001D5550: addu       $t2, $t2, $t1 */
    .word 0x8D4A0000 /* 001D5554: lw         $t2, 0x0($t2) */
    .word 0x014B5021 /* 001D5558: addu       $t2, $t2, $t3 */
    .word 0x914A0000 /* 001D555C: lbu        $t2, 0x0($t2) */
    .word 0x000A502B /* 001D5560: sltu       $t2, $zero, $t2 */
    .word 0x10EAFFC6 /* 001D5564: beq        $a3, $t2, .L001D5480 */
    .word 0x00000000 /* 001D5568: nop */
/* .L001D556C: */
    .word 0x8FA300A0 /* 001D556C: lw         $v1, 0xA0($sp) */
    .word 0x000320C0 /* 001D5570: sll        $a0, $v1, 3 */
    .word 0x8FA300EC /* 001D5574: lw         $v1, 0xEC($sp) */
    .word 0x00642021 /* 001D5578: addu       $a0, $v1, $a0 */
    .word 0x8C830004 /* 001D557C: lw         $v1, 0x4($a0) */
    .word 0xAC430018 /* 001D5580: sw         $v1, 0x18($v0) */
    .word 0xAC820004 /* 001D5584: sw         $v0, 0x4($a0) */
    .word 0x8C830000 /* 001D5588: lw         $v1, 0x0($a0) */
    .word 0x24630001 /* 001D558C: addiu      $v1, $v1, 0x1 */
    .word 0xAC830000 /* 001D5590: sw         $v1, 0x0($a0) */
/* .L001D5594: */
    .word 0x8FA300D0 /* 001D5594: lw         $v1, 0xD0($sp) */
    .word 0x27DE0001 /* 001D5598: addiu      $fp, $fp, 0x1 */
    .word 0x00031843 /* 001D559C: sra        $v1, $v1, 1 */
    .word 0x306400FF /* 001D55A0: andi       $a0, $v1, 0xFF */
/* .L001D55A4: */
    .word 0x2BC30008 /* 001D55A4: slti       $v1, $fp, 0x8 */
    .word 0x1460FF35 /* 001D55A8: bnez       $v1, .L001D5280 */
    .word 0x308300FF /* 001D55AC: andi      $v1, $a0, 0xFF */
/* .L001D55B0: */
    .word 0x26100001 /* 001D55B0: addiu      $s0, $s0, 0x1 */
/* .L001D55B4: */
    .word 0x8EC300E4 /* 001D55B4: lw         $v1, 0xE4($s6) */
    .word 0x0203182A /* 001D55B8: slt        $v1, $s0, $v1 */
    .word 0x1460FF1C /* 001D55BC: bnez       $v1, .L001D5230 */
    .word 0x00000000 /* 001D55C0: nop */
    .word 0x26B50001 /* 001D55C4: addiu      $s5, $s5, 0x1 */
/* .L001D55C8: */
    .word 0x8EC300E4 /* 001D55C8: lw         $v1, 0xE4($s6) */
    .word 0x02A3182A /* 001D55CC: slt        $v1, $s5, $v1 */
    .word 0x1460FF15 /* 001D55D0: bnez       $v1, .L001D5228 */
    .word 0x70008628 /* 001D55D4: paddub    $s0, $zero, $zero */
    .word 0x7BBF0090 /* 001D55D8: lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* 001D55DC: lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* 001D55E0: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 001D55E4: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 001D55E8: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 001D55EC: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001D55F0: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001D55F4: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001D55F8: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001D55FC: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001D5600: jr         $ra */
    .word 0x27BD00F0 /* 001D5604: addiu     $sp, $sp, 0xF0 */
}

#else

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_001D51B0(void *self, void *result) {
    char *zm = (char *)self;
    int w = *(int *)(zm + 0xE4);
    int h = *(int *)(zm + 0xE8);
    char **buf11c = *(char ***)(zm + 0x11C);
    char **buf120 = *(char ***)(zm + 0x120);

    for (int col = 0; col < w; ++col) {
        func_117CAC(buf11c[col], 1, h);
    }

    for (int s5 = 0; s5 < w; ++s5) {
        for (int s0 = 0; s0 < w; ++s0) {
            u8 v11c = (u8)buf11c[s5][s0];
            if (v11c == 0) continue;
            u8 v120 = (u8)buf120[s5][s0];
            if (v120 == 0) continue;

            for (int fp = 0; fp < 8; ++fp) {
                if (!(v120 & (1 << fp))) continue;

                char *node = (char *)func_100850(0x1C);
                *(int *)(node + 0x8) = s5;
                *(int *)(node + 0xC) = s0;

                char *res_bucket = (char *)result + (fp + 1) * 8;
                void *head = *(void **)(res_bucket + 4);
                *(void **)(node + 0x18) = head;
                *(void **)(res_bucket + 4) = node;
                *(int *)res_bucket += 1;
            }
        }
    }
}

#endif
