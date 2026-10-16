#ifndef TACTICAL_AI_PLAYER_DISPATCH_H
#define TACTICAL_AI_PLAYER_DISPATCH_H

struct DispatchItem {
    char pad[66];
    char m_field42;
    char m_field43;
};

struct DispatchPlayer {
    char pad00[108];
    int m_item_count;
    DispatchItem **m_items;
    char pad78[2860];
    int m_player_id; // 2976 (0xBA0)
    char padBA4[8];
    void *m_fieldBAC; // 2988 (0xBAC)
    char padBB0[3972];
    void *m_field1B34; // 6964 (0x1B34)
};

struct DispatchField04 {
    char pad[80];
    short m_count;
    short pad82;
    void **m_items;
};

struct DispatchManager {
    char pad[4];
    DispatchField04 *m_field04;
    char pad08[19664];
    int m_data3[16][20]; // 19672 (0x4CD8)
    char pad51D8[12];
    int m_mode[16]; // 20964 (0x51E4)
    char pad5224[12];
    int m_counts[16]; // 21040 (0x5230)
    int m_data[16][30]; // 21104 (0x5270)
    int m_counts2[16]; // 23024 (0x59F0)
    int m_data2[16][30]; // 23088 (0x5A30)
    int m_counts3[16]; // 25008 (0x61B0)
};

extern "C" {
    extern void *D_004E3180;
    void func_2e05f0(void *player, int cmd, int zero);
    void func_2d42a0(void *field1B34);
    void func_2e0630(void *player, int cmd);

    /**
     * Dispatch player commands and update status flags.
     * VRAM: 0x305CB0 - 0x305F30 (640 bytes).
     */
    void func_00305CB0(DispatchManager *self, DispatchPlayer *player);
}

#endif // TACTICAL_AI_PLAYER_DISPATCH_H
