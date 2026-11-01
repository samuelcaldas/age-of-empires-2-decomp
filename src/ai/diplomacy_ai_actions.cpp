#include "sub_list.h"

#pragma exceptions off

class OtherPlayer {
public:
    char pad_00[0x54];
    char pad_54[0xB90 - 0x54];
    void *m_fieldB90;
    char pad_B94[0xBA6 - 0xB94];
    unsigned char m_status;
};

struct PlayerMgr {
    char pad_00[0x50];
    short m_num_players;
    short pad_52;
    OtherPlayer **m_players;
};

struct TribePlayer {
    char pad_00[0xB98];
    PlayerMgr *m_mgr;
    char pad_B9C[4];
    int m_player_id;
};

struct AIObj {
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3(); virtual void* v4();
    virtual void* v5(); virtual void* v6(); virtual void* v7(); virtual void* v8(); virtual void* v9();
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16(); virtual void* v17(); virtual void* v18(); virtual void* v19();
    virtual void* v20(); virtual void* v21(); virtual void* v22(); virtual void* v23();
    virtual int Method24(int player);
};

struct TribeAI {
    char pad_00[0xAC];
    TribePlayer *m_player;
};

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    AIObj *m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    unsigned char m_field100[10];
};

extern "C" {
int func_140280(void*, int);
int func_140220(void*, int);
int func_318280(void*);
int func_1401C0(void*, int);
}

#if defined(__mips__)
extern "C" {
asm int func_13FEF0(DiplomacyAI *self, int a1, int a2, int a3, int t0) {
    .word 0x27BDFF60 /* 0013FEF0: addiu      $sp, $sp, -0xA0 */
    .word 0x7FBF0090 /* 0013FEF4: sq         $ra, 0x90($sp) */
    .word 0x7FBE0080 /* 0013FEF8: sq         $fp, 0x80($sp) */
    .word 0x7FB70070 /* 0013FEFC: sq         $s7, 0x70($sp) */
    .word 0x7FB60060 /* 0013FF00: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 0013FF04: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 0013FF08: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 0013FF0C: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 0013FF10: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 0013FF14: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 0013FF18: sq         $s0, 0x0($sp) */
    .word 0x2410FFFF /* 0013FF1C: addiu      $s0, $zero, -0x1 */
    .word 0x24120001 /* 0013FF20: addiu      $s2, $zero, 0x1 */
    .word 0x7080BE28 /* 0013FF24: paddub     $s7, $a0, $zero */
    .word 0x70A0B628 /* 0013FF28: paddub     $s6, $a1, $zero */
    .word 0x70C0AE28 /* 0013FF2C: paddub     $s5, $a2, $zero */
    .word 0x70E0F628 /* 0013FF30: paddub     $fp, $a3, $zero */
    .word 0x7100A628 /* 0013FF34: paddub     $s4, $t0, $zero */
    .word 0x10000049 /* 0013FF38: b          .L00140060 */
    .word 0x72008E28 /* 0013FF3C: paddub    $s1, $s0, $zero */
    .word 0x8C620BA0 /* 0013FF40: lw         $v0, 0xBA0($v1) */
    .word 0x52420046 /* 0013FF44: beql       $s2, $v0, .L00140060 */
    .word 0x26520001 /* 0013FF48: addiu     $s2, $s2, 0x1 */
    .word 0x8C830054 /* 0013FF4C: lw         $v1, 0x54($a0) */
    .word 0x00129880 /* 0013FF50: sll        $s3, $s2, 2 */
    .word 0x24020002 /* 0013FF54: addiu      $v0, $zero, 0x2 */
    .word 0x00731821 /* 0013FF58: addu       $v1, $v1, $s3 */
    .word 0x8C630000 /* 0013FF5C: lw         $v1, 0x0($v1) */
    .word 0x90630BA6 /* 0013FF60: lbu        $v1, 0xBA6($v1) */
    .word 0x1062003D /* 0013FF64: beq        $v1, $v0, .L0014005C */
    .word 0x00000000 /* 0013FF68: nop */
    .word 0x1AC00009 /* 0013FF6C: blez       $s6, .L0013FF94 */
    .word 0x72E02628 /* 0013FF70: paddub    $a0, $s7, $zero */
    .word 0x16B20006 /* 0013FF74: bne        $s5, $s2, .L0013FF90 */
    .word 0x00000000 /* 0013FF78: nop */
    .word 0x72E02628 /* 0013FF7C: paddub     $a0, $s7, $zero */
    jal        func_140280 /* 0013FF80 */
    .word 0x72402E28 /* 0013FF84: paddub    $a1, $s2, $zero */
    .word 0x14400034 /* 0013FF88: bnez       $v0, .L0014005C */
    .word 0x00000000 /* 0013FF8C: nop */
    .word 0x72E02628 /* 0013FF90: paddub     $a0, $s7, $zero */
    jal        func_140280 /* 0013FF94 */
    .word 0x72402E28 /* 0013FF98: paddub    $a1, $s2, $zero */
    .word 0x24030001 /* 0013FF9C: addiu      $v1, $zero, 0x1 */
    .word 0x1043002E /* 0013FFA0: beq        $v0, $v1, .L0014005C */
    .word 0x00000000 /* 0013FFA4: nop */
    .word 0x72E02628 /* 0013FFA8: paddub     $a0, $s7, $zero */
    jal        func_140220 /* 0013FFAC */
    .word 0x72402E28 /* 0013FFB0: paddub    $a1, $s2, $zero */
    .word 0x24030001 /* 0013FFB4: addiu      $v1, $zero, 0x1 */
    .word 0x10430028 /* 0013FFB8: beq        $v0, $v1, .L0014005C */
    .word 0x00000000 /* 0013FFBC: nop */
    .word 0x8EE400AC /* 0013FFC0: lw         $a0, 0xAC($s7) */
    .word 0x8C990000 /* 0013FFC4: lw         $t9, 0x0($a0) */
    .word 0x8F390060 /* 0013FFC8: lw         $t9, 0x60($t9) */
    .word 0x0320F809 /* 0013FFCC: jalr       $t9 */
    .word 0x72402E28 /* 0013FFD0: paddub    $a1, $s2, $zero */
    .word 0x10400021 /* 0013FFD4: beqz       $v0, .L0014005C */
    .word 0x00000000 /* 0013FFD8: nop */
    .word 0x8EE200AC /* 0013FFDC: lw         $v0, 0xAC($s7) */
    .word 0x8C4200AC /* 0013FFE0: lw         $v0, 0xAC($v0) */
    .word 0x8C420B98 /* 0013FFE4: lw         $v0, 0xB98($v0) */
    .word 0x8C420054 /* 0013FFE8: lw         $v0, 0x54($v0) */
    .word 0x00531021 /* 0013FFEC: addu       $v0, $v0, $s3 */
    .word 0x8C420000 /* 0013FFF0: lw         $v0, 0x0($v0) */
    jal        func_318280 /* 0013FFF4 */
    .word 0x8C440B90 /* 0013FFF8: lw        $a0, 0xB90($v0) */
    .word 0x02F31821 /* 0013FFFC: addu       $v1, $s7, $s3 */
    .word 0x2A810002 /* 00140000: slti       $at, $s4, 0x2 */
    .word 0x14200010 /* 00140004: bnez       $at, .L00140048 */
    .word 0x8C6400B0 /* 00140008: lw        $a0, 0xB0($v1) */
    .word 0x24030001 /* 0014000C: addiu      $v1, $zero, 0x1 */
    .word 0x57C30008 /* 00140010: bnel       $fp, $v1, .L00140034 */
    .word 0x0054001A /* 00140014: div       $zero, $v0, $s4 */
    .word 0x16800002 /* 00140018: bnez       $s4, .L00140024 */
    .word 0x0054001A /* 0014001C: div       $zero, $v0, $s4 */
    .word 0x000001CD /* 00140020: break      0, 7 */
    .word 0x00001012 /* 00140024: mflo       $v0 */
    .word 0x10000007 /* 00140028: b          .L00140048 */
    .word 0x00822021 /* 0014002C: addu      $a0, $a0, $v0 */
    .word 0x0054001A /* 00140030: div        $zero, $v0, $s4 */
    .word 0x16800002 /* 00140034: bnez       $s4, .L00140040 */
    .word 0x00000000 /* 00140038: nop */
    .word 0x000001CD /* 0014003C: break      0, 7 */
    .word 0x00001012 /* 00140040: mflo       $v0 */
    .word 0x00822023 /* 00140044: subu       $a0, $a0, $v0 */
    .word 0x0224082A /* 00140048: slt        $at, $s1, $a0 */
    .word 0x10200003 /* 0014004C: beqz       $at, .L0014005C */
    .word 0x00000000 /* 00140050: nop */
    .word 0x70808E28 /* 00140054: paddub     $s1, $a0, $zero */
    .word 0x72408628 /* 00140058: paddub     $s0, $s2, $zero */
    .word 0x26520001 /* 0014005C: addiu      $s2, $s2, 0x1 */
    .word 0x8EE200AC /* 00140060: lw         $v0, 0xAC($s7) */
    .word 0x8C4300AC /* 00140064: lw         $v1, 0xAC($v0) */
    .word 0x8C640B98 /* 00140068: lw         $a0, 0xB98($v1) */
    .word 0x84820050 /* 0014006C: lh         $v0, 0x50($a0) */
    .word 0x0242102A /* 00140070: slt        $v0, $s2, $v0 */
    .word 0x1440FFB2 /* 00140074: bnez       $v0, .L0013FF40 */
    .word 0x00000000 /* 00140078: nop */
    .word 0x72001628 /* 0014007C: paddub     $v0, $s0, $zero */
    .word 0x7BBF0090 /* 00140080: lq         $ra, 0x90($sp) */
    .word 0x7BBE0080 /* 00140084: lq         $fp, 0x80($sp) */
    .word 0x7BB70070 /* 00140088: lq         $s7, 0x70($sp) */
    .word 0x7BB60060 /* 0014008C: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 00140090: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 00140094: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 00140098: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 0014009C: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001400A0: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001400A4: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001400A8: jr         $ra */
    .word 0x27BD00A0 /* 001400AC: addiu     $sp, $sp, 0xA0 */
}

asm int func_001400B0() {
    .word 0x03E00008 /* 001400B0: jr         $ra */
    .word 0x70001628 /* 001400B4: paddub    $v0, $zero, $zero */
}

asm int func_001400C0(DiplomacyAI *self, int a1, int a2) {
    .word 0x27BDFF80 /* 001400C0: addiu      $sp, $sp, -0x80 */
    .word 0x7FBF0070 /* 001400C4: sq         $ra, 0x70($sp) */
    .word 0x7FB60060 /* 001400C8: sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* 001400CC: sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* 001400D0: sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* 001400D4: sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001400D8: sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001400DC: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001400E0: sq         $s0, 0x0($sp) */
    .word 0x2410FFFF /* 001400E4: addiu      $s0, $zero, -0x1 */
    .word 0x24120001 /* 001400E8: addiu      $s2, $zero, 0x1 */
    .word 0x7080B628 /* 001400EC: paddub     $s6, $a0, $zero */
    .word 0x70A0AE28 /* 001400F0: paddub     $s5, $a1, $zero */
    .word 0x70C0A628 /* 001400F4: paddub     $s4, $a2, $zero */
    .word 0x1000001D /* 001400F8: b          .L00140170 */
    .word 0x72008E28 /* 001400FC: paddub    $s1, $s0, $zero */
    .word 0x8C620BA0 /* 00140100: lw         $v0, 0xBA0($v1) */
    .word 0x5242001A /* 00140104: beql       $s2, $v0, .L00140170 */
    .word 0x26520001 /* 00140108: addiu     $s2, $s2, 0x1 */
    .word 0x8C830054 /* 0014010C: lw         $v1, 0x54($a0) */
    .word 0x00129880 /* 00140110: sll        $s3, $s2, 2 */
    .word 0x24020002 /* 00140114: addiu      $v0, $zero, 0x2 */
    .word 0x00731821 /* 00140118: addu       $v1, $v1, $s3 */
    .word 0x8C630000 /* 0014011C: lw         $v1, 0x0($v1) */
    .word 0x90630BA6 /* 00140120: lbu        $v1, 0xBA6($v1) */
    .word 0x10620011 /* 00140124: beq        $v1, $v0, .L0014016C */
    .word 0x00000000 /* 00140128: nop */
    .word 0x1AA00009 /* 0014012C: blez       $s5, .L00140154 */
    .word 0x02D31021 /* 00140130: addu      $v0, $s6, $s3 */
    .word 0x16920006 /* 00140134: bne        $s4, $s2, .L00140150 */
    .word 0x00000000 /* 00140138: nop */
    .word 0x72C02628 /* 0014013C: paddub     $a0, $s6, $zero */
    jal        func_1401C0 /* 00140140 */
    .word 0x72402E28 /* 00140144: paddub    $a1, $s2, $zero */
    .word 0x14400008 /* 00140148: bnez       $v0, .L0014016C */
    .word 0x00000000 /* 0014014C: nop */
    .word 0x02D31021 /* 00140150: addu       $v0, $s6, $s3 */
    .word 0x8C4200D8 /* 00140154: lw         $v0, 0xD8($v0) */
    .word 0x0222082A /* 00140158: slt        $at, $s1, $v0 */
    .word 0x10200003 /* 0014015C: beqz       $at, .L0014016C */
    .word 0x00000000 /* 00140160: nop */
    .word 0x70408E28 /* 00140164: paddub     $s1, $v0, $zero */
    .word 0x72408628 /* 00140168: paddub     $s0, $s2, $zero */
    .word 0x26520001 /* 0014016C: addiu      $s2, $s2, 0x1 */
    .word 0x8EC200AC /* 00140170: lw         $v0, 0xAC($s6) */
    .word 0x8C4300AC /* 00140174: lw         $v1, 0xAC($v0) */
    .word 0x8C640B98 /* 00140178: lw         $a0, 0xB98($v1) */
    .word 0x84820050 /* 0014017C: lh         $v0, 0x50($a0) */
    .word 0x0242102A /* 00140180: slt        $v0, $s2, $v0 */
    .word 0x1440FFDE /* 00140184: bnez       $v0, .L00140100 */
    .word 0x00000000 /* 00140188: nop */
    .word 0x72001628 /* 0014018C: paddub     $v0, $s0, $zero */
    .word 0x7BBF0070 /* 00140190: lq         $ra, 0x70($sp) */
    .word 0x7BB60060 /* 00140194: lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* 00140198: lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* 0014019C: lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* 001401A0: lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001401A4: lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001401A8: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001401AC: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001401B0: jr         $ra */
    .word 0x27BD0080 /* 001401B4: addiu     $sp, $sp, 0x80 */
}
}
#else
extern "C" {
int func_13FEF0(DiplomacyAI *self, int a1, int a2, int t0, int a3) {
    int best_player = -1;
    int best_score = best_player;

    for (int player = 1; player < ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_num_players; player++) {
        if (player == ((TribeAI*)self->m_fieldAC)->m_player->m_player_id) {
            continue;
        }
        if (((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_players[player]->m_status == 2) {
            continue;
        }
        if (a1 > 0) {
            if (a2 == player && func_140280(self, player)) {
                continue;
            }
        }
        if (func_140280(self, player) == 1) {
            continue;
        }
        if (func_140220(self, player) == 1) {
            continue;
        }
        if (!self->m_fieldAC->Method24(player)) {
            continue;
        }
        int val = func_318280(((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_players[player]->m_fieldB90);
        int score = self->m_fieldB0[player];
        if (a3 >= 2) {
            if (t0 == 1) {
                score += val / a3;
            } else {
                score -= val / a3;
            }
        }
        if (score > best_score) {
            best_score = score;
            best_player = player;
        }
    }
    return best_player;
}

int func_001400B0() {
    return 0;
}

int func_001400C0(DiplomacyAI *self, int a1, int a2) {
    int best_player = -1;
    int best_val = best_player;

    for (int player = 1; player < ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_num_players; player++) {
        if (player == ((TribeAI*)self->m_fieldAC)->m_player->m_player_id) {
            continue;
        }
        OtherPlayer *other = ((TribeAI*)self->m_fieldAC)->m_player->m_mgr->m_players[player];
        if (other->m_status == 2) {
            continue;
        }
        if (a1 > 0) {
            if (a2 == player && func_1401C0(self, player)) {
                continue;
            }
        }
        int val = self->m_fieldD8[player];
        if (val > best_val) {
            best_val = val;
            best_player = player;
        }
    }
    return best_player;
}

}

#endif
