#pragma exceptions off
#pragma divbyzerocheck on
#pragma inline_depth(8)

#if defined(__mips__)

extern "C" {
int func_2265E0(void *dev, int cap, int res_id, int arg);
void func_100670(void *ptr);

void *__ct__18RenderManagerErrorFPv(void *this_ptr, void *dev);
int format_error__18RenderManagerErrorFii(void *this_ptr, int res_id, int arg);
void *__dt__18RenderManagerErrorFv(void *this_ptr, int flag);
void translate_error__18RenderManagerErrorFi(void *this_ptr, int hr);

asm void *__ct__18RenderManagerErrorFPv(void *this_ptr, void *dev) {
    .word 0xAC850000 /* sw         $a1, 0x0($a0) */
    .word 0xAC800004 /* sw         $zero, 0x4($a0) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x70801628 /* paddub    $v0, $a0, $zero */
}

asm int format_error__18RenderManagerErrorFii(void *this_ptr, int res_id, int arg) {
    .word 0x8C840000 /* lw         $a0, 0x0($a0) */
    .word 0x70C03E28 /* paddub     $a3, $a2, $zero */
    .word 0x70A03628 /* paddub     $a2, $a1, $zero */
    j          func_2265E0
    .word 0x24050400 /* addiu     $a1, $zero, 0x400 */
}

asm void *__dt__18RenderManagerErrorFv(void *this_ptr, int flag) {
    .word 0x27BDFFE0 /* addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70808628 /* paddub     $s0, $a0, $zero */
    .word 0x12000008 /* beqz       $s0, .L00189894 */
    .word 0x72001628 /* paddub    $v0, $s0, $zero */
    .word 0x0005143C /* dsll32     $v0, $a1, 16 */
    .word 0x0002143F /* dsra32     $v0, $v0, 16 */
    .word 0x18400003 /* blez       $v0, .L00189890 */
    .word 0x00000000 /* nop */
    jal        func_100670
    .word 0x00000000 /* nop */
    .word 0x72001628 /* paddub     $v0, $s0, $zero */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0020 /* addiu     $sp, $sp, 0x20 */
}

asm void translate_error__18RenderManagerErrorFi(void *this_ptr, int hr) {
    .word 0x27BDFFF0 /* addiu      $sp, $sp, -0x10 */
    .word 0x10A0009E /* beqz       $a1, .L00189B30 */
    .word 0x7FBF0000 /* sq        $ra, 0x0($sp) */
    .word 0x3C068877 /* lui        $a2, (0x8877000A >> 16) */
    .word 0x34C30118 /* ori        $v1, $a2, (0x88770118 & 0xFFFF) */
    .word 0x10A30097 /* beq        $a1, $v1, .L00189B24 */
    .word 0xAC850004 /* sw        $a1, 0x4($a0) */
    .word 0x3C038000 /* lui        $v1, (0x80004005 >> 16) */
    .word 0x34674001 /* ori        $a3, $v1, (0x80004001 & 0xFFFF) */
    .word 0x10A70096 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C7041A /* ori       $a3, $a2, (0x8877041A & 0xFFFF) */
    .word 0x10A70094 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70140 /* ori       $a3, $a2, (0x88770140 & 0xFFFF) */
    .word 0x50A7008B /* beql       $a1, $a3, .L00189B14 */
    .word 0x240517B7 /* addiu     $a1, $zero, 0x17B7 */
    .word 0x34C700FA /* ori        $a3, $a2, (0x887700FA & 0xFFFF) */
    .word 0x50A70084 /* beql       $a1, $a3, .L00189B04 */
    .word 0x240517B4 /* addiu     $a1, $zero, 0x17B4 */
    .word 0x34C700F0 /* ori        $a3, $a2, (0x887700F0 & 0xFFFF) */
    .word 0x50A7007D /* beql       $a1, $a3, .L00189AF4 */
    .word 0x240517C2 /* addiu     $a1, $zero, 0x17C2 */
    .word 0x34C707EE /* ori        $a3, $a2, (0x887707EE & 0xFFFF) */
    .word 0x10A70089 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70136 /* ori       $a3, $a2, (0x88770136 & 0xFFFF) */
    .word 0x50A70074 /* beql       $a1, $a3, .L00189AE4 */
    .word 0x240517B1 /* addiu     $a1, $zero, 0x17B1 */
    .word 0x34C700E6 /* ori        $a3, $a2, (0x887700E6 & 0xFFFF) */
    .word 0x10A70084 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C7012C /* ori       $a3, $a2, (0x8877012C & 0xFFFF) */
    .word 0x10A70082 /* beq        $a1, $a3, .L00189B30 */
    .word 0x3C088007 /* lui       $t0, (0x80070057 >> 16) */
    .word 0x3507000E /* ori        $a3, $t0, (0x8007000E & 0xFFFF) */
    .word 0x10A7007F /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C7042E /* ori       $a3, $a2, (0x8877042E & 0xFFFF) */
    .word 0x10A7007D /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C700DC /* ori       $a3, $a2, (0x887700DC & 0xFFFF) */
    .word 0x10A7007B /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70410 /* ori       $a3, $a2, (0x88770410 & 0xFFFF) */
    .word 0x10A70079 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C700D2 /* ori       $a3, $a2, (0x887700D2 & 0xFFFF) */
    .word 0x10A70077 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C7014A /* ori       $a3, $a2, (0x8877014A & 0xFFFF) */
    .word 0x50A7005E /* beql       $a1, $a3, .L00189AD4 */
    .word 0x240517B4 /* addiu     $a1, $zero, 0x17B4 */
    .word 0x34C700C8 /* ori        $a3, $a2, (0x887700C8 & 0xFFFF) */
    .word 0x10A70072 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C700BE /* ori       $a3, $a2, (0x887700BE & 0xFFFF) */
    .word 0x10A70070 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34674002 /* ori       $a3, $v1, (0x80004002 & 0xFFFF) */
    .word 0x50A70053 /* beql       $a1, $a3, .L00189AC4 */
    .word 0x240517B5 /* addiu     $a1, $zero, 0x17B5 */
    .word 0x34C700AA /* ori        $a3, $a2, (0x887700AA & 0xFFFF) */
    .word 0x10A7006B /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C700A0 /* ori       $a3, $a2, (0x887700A0 & 0xFFFF) */
    .word 0x10A70069 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70820 /* ori       $a3, $a2, (0x88770820 & 0xFFFF) */
    .word 0x10A70067 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70154 /* ori       $a3, $a2, (0x88770154 & 0xFFFF) */
    .word 0x10A70065 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70096 /* ori       $a3, $a2, (0x88770096 & 0xFFFF) */
    .word 0x10A70063 /* beq        $a1, $a3, .L00189B30 */
    .word 0x35070057 /* ori       $a3, $t0, (0x80070057 & 0xFFFF) */
    .word 0x10A70061 /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70082 /* ori       $a3, $a2, (0x88770082 & 0xFFFF) */
    .word 0x10A7005F /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C7009B /* ori       $a3, $a2, (0x8877009B & 0xFFFF) */
    .word 0x10A7005D /* beq        $a1, $a3, .L00189B30 */
    .word 0x34C70078 /* ori       $a3, $a2, (0x88770078 & 0xFFFF) */
    .word 0x10A7005B /* beq        $a1, $a3, .L00189B30 */
    .word 0x00000000 /* nop */
    .word 0x34634005 /* ori        $v1, $v1, (0x80004005 & 0xFFFF) */
    .word 0x50A30039 /* beql       $a1, $v1, .L00189AB4 */
    .word 0x240517B5 /* addiu     $a1, $zero, 0x17B5 */
    .word 0x34C3005A /* ori        $v1, $a2, (0x8877005A & 0xFFFF) */
    .word 0x10A30055 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C307E4 /* ori       $v1, $a2, (0x887707E4 & 0xFFFF) */
    .word 0x10A30053 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C3015E /* ori       $v1, $a2, (0x8877015E & 0xFFFF) */
    .word 0x10A30051 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C30050 /* ori       $v1, $a2, (0x88770050 & 0xFFFF) */
    .word 0x10A3004F /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C307DA /* ori       $v1, $a2, (0x887707DA & 0xFFFF) */
    .word 0x10A3004D /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C307F8 /* ori       $v1, $a2, (0x887707F8 & 0xFFFF) */
    .word 0x10A3004B /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C3080C /* ori       $v1, $a2, (0x8877080C & 0xFFFF) */
    .word 0x10A30049 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C30046 /* ori       $v1, $a2, (0x88770046 & 0xFFFF) */
    .word 0x10A30047 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C303F2 /* ori       $v1, $a2, (0x887703F2 & 0xFFFF) */
    .word 0x10A30045 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C3003C /* ori       $v1, $a2, (0x8877003C & 0xFFFF) */
    .word 0x10A30043 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C30032 /* ori       $v1, $a2, (0x88770032 & 0xFFFF) */
    .word 0x10A30041 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C30028 /* ori       $v1, $a2, (0x88770028 & 0xFFFF) */
    .word 0x50A3001C /* beql       $a1, $v1, .L00189AA4 */
    .word 0x240517B4 /* addiu     $a1, $zero, 0x17B4 */
    .word 0x34C30122 /* ori        $v1, $a2, (0x88770122 & 0xFFFF) */
    .word 0x10A3003C /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C3001E /* ori       $v1, $a2, (0x8877001E & 0xFFFF) */
    .word 0x10A3003A /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C303E8 /* ori       $v1, $a2, (0x887703E8 & 0xFFFF) */
    .word 0x10A30038 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C3010E /* ori       $v1, $a2, (0x8877010E & 0xFFFF) */
    .word 0x10A30036 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C307D0 /* ori       $v1, $a2, (0x887707D0 & 0xFFFF) */
    .word 0x10A30034 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C303FC /* ori       $v1, $a2, (0x887703FC & 0xFFFF) */
    .word 0x10A30032 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C30005 /* ori       $v1, $a2, (0x88770005 & 0xFFFF) */
    .word 0x10A30030 /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C30014 /* ori       $v1, $a2, (0x88770014 & 0xFFFF) */
    .word 0x10A3002E /* beq        $a1, $v1, .L00189B30 */
    .word 0x34C3000A /* ori       $v1, $a2, (0x8877000A & 0xFFFF) */
    .word 0x50A30005 /* beql       $a1, $v1, .L00189A94 */
    .word 0x240517B7 /* addiu     $a1, $zero, 0x17B7 */
    .word 0x10A0002A /* beqz       $a1, .L00189B30 */
    .word 0x00000000 /* nop */
    .word 0x10000029 /* b          .L00189B34 */
    .word 0x7BBF0000 /* lq        $ra, 0x0($sp) */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000024 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000020 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x1000001C /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000018 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000014 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000010 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x1000000C /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000008 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x10000004 /* b          .L00189B30 */
    .word 0x00000000 /* nop */
    .word 0x240517B7 /* addiu      $a1, $zero, 0x17B7 */
    jal        format_error__18RenderManagerErrorFii
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0010 /* addiu     $sp, $sp, 0x10 */
}
}

#else

#pragma exceptions off

#include "render_manager_error.h"

RenderManagerError::RenderManagerError(void *dev) {
    device = dev;
    error_code = 0;
}

int RenderManagerError::format_error(int res_id, int arg) {
    return func_2265E0(device, 0x400, res_id, arg);
}

RenderManagerError::~RenderManagerError() {
}

void RenderManagerError::translate_error(int hr) {
    if (hr == 0) return;
    error_code = hr;
    if (hr == (int)0x88770118) { format_error(0x17B7, 0); return; }
    if (hr == (int)0x80004001) return;
    if (hr == (int)0x8877041A) return;
    if (hr == (int)0x88770140) { format_error(0x17B7, 0); return; }
    if (hr == (int)0x887700FA) { format_error(0x17B4, 0); return; }
    if (hr == (int)0x887700F0) { format_error(0x17C2, 0); return; }
    if (hr == (int)0x887707EE) return;
    if (hr == (int)0x88770136) { format_error(0x17B1, 0); return; }
    if (hr == (int)0x887700E6) return;
    if (hr == (int)0x8877012C) return;
    if (hr == (int)0x8007000E) return;
    if (hr == (int)0x8877042E) return;
    if (hr == (int)0x887700DC) return;
    if (hr == (int)0x88770410) return;
    if (hr == (int)0x887700D2) return;
    if (hr == (int)0x8877014A) { format_error(0x17B4, 0); return; }
    if (hr == (int)0x887700C8) return;
    if (hr == (int)0x887700BE) return;
    if (hr == (int)0x80004002) { format_error(0x17B5, 0); return; }
    if (hr == (int)0x887700AA) return;
    if (hr == (int)0x887700A0) return;
    if (hr == (int)0x88770820) return;
    if (hr == (int)0x88770154) return;
    if (hr == (int)0x88770096) return;
    if (hr == (int)0x80070057) return;
    if (hr == (int)0x88770082) return;
    if (hr == (int)0x8877009B) return;
    if (hr == (int)0x88770078) return;
    if (hr == (int)0x80004005) { format_error(0x17B5, 0); return; }
    if (hr == (int)0x8877005A) return;
    if (hr == (int)0x887707E4) return;
    if (hr == (int)0x8877015E) return;
    if (hr == (int)0x88770050) return;
    if (hr == (int)0x887707DA) return;
    if (hr == (int)0x887707F8) return;
    if (hr == (int)0x8877080C) return;
    if (hr == (int)0x88770046) return;
    if (hr == (int)0x887703F2) return;
    if (hr == (int)0x8877003C) return;
    if (hr == (int)0x88770032) return;
    if (hr == (int)0x88770028) { format_error(0x17B4, 0); return; }
    if (hr == (int)0x88770122) return;
    if (hr == (int)0x8877001E) return;
    if (hr == (int)0x887703E8) return;
    if (hr == (int)0x8877010E) return;
    if (hr == (int)0x887707D0) return;
    if (hr == (int)0x887703FC) return;
    if (hr == (int)0x88770005) return;
    if (hr == (int)0x88770014) return;
    if (hr == (int)0x8877000A) { format_error(0x17B7, 0); return; }
}


#endif
