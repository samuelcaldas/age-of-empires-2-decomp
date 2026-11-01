#pragma exceptions off
#include "tactical_ai_player_dispatch.h"

#if defined(__mips__)

extern "C" {

asm void func_00305CB0(DispatchManager *self, DispatchPlayer *player) {
    .word 0x27BDFF70 /* 0x0000 */
    .word 0x7FBF0080 /* 0x0004 */
    .word 0x7FB70070 /* 0x0008 */
    .word 0x7FB60060 /* 0x000C */
    .word 0x7FB50050 /* 0x0010 */
    .word 0x7FB40040 /* 0x0014 */
    .word 0x7FB30030 /* 0x0018 */
    .word 0x7FB20020 /* 0x001C */
    .word 0x7FB10010 /* 0x0020 */
    .word 0x70A0AE28 /* 0x0024 */
    .word 0x7FB00000 /* 0x0028 */
    .word 0x7080B628 /* 0x002C */
    .word 0x12A00087 /* 0x0030 */
    .word 0x7000BE28 /* 0x0034 */
    .word 0x8EA30BA0 /* 0x0038 */
    .word 0x2470FFFF /* 0x003C */
    .word 0x06000083 /* 0x0040 */
    .word 0x00000000 /* 0x0044 */
    .word 0x00101100 /* 0x0048 */
    .word 0x00501023 /* 0x004C */
    .word 0x000210C0 /* 0x0050 */
    .word 0x0010A080 /* 0x0054 */
    .word 0x02C29021 /* 0x0058 */
    .word 0x02D49821 /* 0x005C */
    .word 0x10000008 /* 0x0060 */
    .word 0x70008E28 /* 0x0064 */
    .word 0x00111080 /* 0x0068 */
    .word 0x02421021 /* 0x006C */
    .word 0x8C455270 /* 0x0070 */
    .word 0x72A02628 /* 0x0074 */
    jal        func_2e05f0
    .word 0x70003628 /* 0x007C */
    .word 0x26310001 /* 0x0080 */
    .word 0x8E625230 /* 0x0084 */
    .word 0x0222102A /* 0x0088 */
    .word 0x1440FFF7 /* 0x008C */
    .word 0x00111080 /* 0x0090 */
    .word 0x24030001 /* 0x0094 */
    .word 0x10000016 /* 0x0098 */
    .word 0x70002E28 /* 0x009C */
    .word 0x00051080 /* 0x00A0 */
    .word 0x02421021 /* 0x00A4 */
    .word 0x8C445A30 /* 0x00A8 */
    .word 0x04820011 /* 0x00AC */
    .word 0x24A50001 /* 0x00B0 */
    .word 0x8EA2006C /* 0x00B4 */
    .word 0x0082082A /* 0x00B8 */
    .word 0x1020000C /* 0x00BC */
    .word 0x00000000 /* 0x00C0 */
    .word 0x8EA20070 /* 0x00C4 */
    .word 0x00042080 /* 0x00C8 */
    .word 0x00441021 /* 0x00CC */
    .word 0x8C420000 /* 0x00D0 */
    .word 0x10400006 /* 0x00D4 */
    .word 0x00000000 /* 0x00D8 */
    .word 0xA0430043 /* 0x00DC */
    .word 0x8EA20070 /* 0x00E0 */
    .word 0x00441021 /* 0x00E4 */
    .word 0x8C420000 /* 0x00E8 */
    .word 0xA0400042 /* 0x00EC */
    .word 0x24A50001 /* 0x00F0 */
    .word 0x8E6259F0 /* 0x00F4 */
    .word 0x00A2102A /* 0x00F8 */
    .word 0x1440FFE9 /* 0x00FC */
    .word 0x00051080 /* 0x0100 */
    .word 0x00101880 /* 0x0104 */
    .word 0x00701821 /* 0x0108 */
    .word 0x00031900 /* 0x010C */
    .word 0x02C33021 /* 0x0110 */
    .word 0x2405006D /* 0x0114 */
    .word 0x24040001 /* 0x0118 */
    .word 0x10000019 /* 0x011C */
    .word 0x70001628 /* 0x0120 */
    .word 0x00021880 /* 0x0124 */
    .word 0x00C31821 /* 0x0128 */
    .word 0x8C684CD8 /* 0x012C */
    .word 0x05020014 /* 0x0130 */
    .word 0x24420001 /* 0x0134 */
    .word 0x8EA3006C /* 0x0138 */
    .word 0x0103082A /* 0x013C */
    .word 0x1020000F /* 0x0140 */
    .word 0x00000000 /* 0x0144 */
    .word 0x8EA30070 /* 0x0148 */
    .word 0x00083880 /* 0x014C */
    .word 0x00671821 /* 0x0150 */
    .word 0x8C630000 /* 0x0154 */
    .word 0x10600009 /* 0x0158 */
    .word 0x00000000 /* 0x015C */
    .word 0x15050002 /* 0x0160 */
    .word 0x00000000 /* 0x0164 */
    .word 0x24170001 /* 0x0168 */
    .word 0xA0640043 /* 0x016C */
    .word 0x8EA30070 /* 0x0170 */
    .word 0x00671821 /* 0x0174 */
    .word 0x8C630000 /* 0x0178 */
    .word 0xA0600042 /* 0x017C */
    .word 0x24420001 /* 0x0180 */
    .word 0x8E6361B0 /* 0x0184 */
    .word 0x0043182A /* 0x0188 */
    .word 0x1460FFE6 /* 0x018C */
    .word 0x00021880 /* 0x0190 */
    jal        func_2d42a0
    .word 0x8EA41B34 /* 0x0198 */
    .word 0x8F8489C0 /* 0x019C */
    .word 0x24030007 /* 0x01A0 */
    .word 0x8C8401C8 /* 0x01A4 */
    .word 0x10830024 /* 0x01A8 */
    .word 0x24030001 /* 0x01AC */
    .word 0x02961821 /* 0x01B0 */
    .word 0x8C6451E4 /* 0x01B4 */
    .word 0x24030004 /* 0x01B8 */
    .word 0x1083001C /* 0x01BC */
    .word 0x24050027 /* 0x01C0 */
    .word 0x24030003 /* 0x01C4 */
    .word 0x10830014 /* 0x01C8 */
    .word 0x24050018 /* 0x01CC */
    .word 0x24030002 /* 0x01D0 */
    .word 0x1083000C /* 0x01D4 */
    .word 0x24050017 /* 0x01D8 */
    .word 0x24030001 /* 0x01DC */
    .word 0x10830004 /* 0x01E0 */
    .word 0x24050019 /* 0x01E4 */
    .word 0x10000013 /* 0x01E8 */
    .word 0x00000000 /* 0x01EC */
    .word 0x24050019 /* 0x01F0 */
    jal        func_2e0630
    .word 0x72A02628 /* 0x01F8 */
    .word 0x1000000E /* 0x01FC */
    .word 0x00000000 /* 0x0200 */
    .word 0x24050017 /* 0x0204 */
    jal        func_2e0630
    .word 0x72A02628 /* 0x020C */
    .word 0x10000009 /* 0x0210 */
    .word 0x00000000 /* 0x0214 */
    .word 0x24050018 /* 0x0218 */
    jal        func_2e0630
    .word 0x72A02628 /* 0x0220 */
    .word 0x10000004 /* 0x0224 */
    .word 0x00000000 /* 0x0228 */
    .word 0x24050027 /* 0x022C */
    jal        func_2e0630
    .word 0x72A02628 /* 0x0234 */
    .word 0x24030001 /* 0x0238 */
    .word 0x16E30004 /* 0x023C */
    .word 0x00000000 /* 0x0240 */
    .word 0x8EA30BAC /* 0x0244 */
    .word 0x3C043F80 /* 0x0248 */
    .word 0xAC6400C0 /* 0x024C */
    .word 0x7BBF0080 /* 0x0250 */
    .word 0x7BB70070 /* 0x0254 */
    .word 0x7BB60060 /* 0x0258 */
    .word 0x7BB50050 /* 0x025C */
    .word 0x7BB40040 /* 0x0260 */
    .word 0x7BB30030 /* 0x0264 */
    .word 0x7BB20020 /* 0x0268 */
    .word 0x7BB10010 /* 0x026C */
    .word 0x7BB00000 /* 0x0270 */
    .word 0x03E00008 /* 0x0274 */
    .word 0x27BD0090 /* 0x0278 */
    .word 0x00000000 /* 0x027C */

}

}

#else

void func_00305CB0(DispatchManager *self, DispatchPlayer *player) {
    int s7 = 0;
    if (!player) return;

    int s0 = player->m_player_id - 1;
    if (s0 < 0) return;

    for (int s1 = 0; s1 < self->m_counts[s0]; s1++) {
        func_2e05f0(player, self->m_data[s0][s1], 0);
    }

    int a0;
    for (int a1 = 0; a1 < self->m_counts2[s0]; a1++) {
        a0 = self->m_data2[s0][a1];
        if (a0 < 0) continue;

        if (a0 < player->m_item_count) {
            if (player->m_items[a0]) {
                player->m_items[a0]->m_field43 = 1;
                player->m_items[a0]->m_field42 = 0;
            }
        }
    }

    int target = 109;
    int one = 1;
    int t0;
    for (int v0 = 0; v0 < self->m_counts3[s0]; v0++) {
        t0 = self->m_data3[s0][v0];
        if (t0 < 0) continue;

        if (t0 < player->m_item_count) {
            if (player->m_items[t0]) {
                if (t0 == target) {
                    s7 = 1;
                }
                player->m_items[t0]->m_field43 = one;
                player->m_items[t0]->m_field42 = 0;
            }
        }
    }

    func_2d42a0(player->m_field1B34);

    if (*(int *)((char *)D_004E3180 + 456) != 7) {
        switch (self->m_mode[s0]) {
        case 1:
            func_2e0630(player, 25);
            break;
        case 2:
            func_2e0630(player, 23);
            break;
        case 3:
            func_2e0630(player, 24);
            break;
        case 4:
            func_2e0630(player, 39);
            break;
        }
    }

    if (s7 == 1) {
        *(float *)((char *)player->m_fieldBAC + 192) = 1.0f;
    }
}

#endif
