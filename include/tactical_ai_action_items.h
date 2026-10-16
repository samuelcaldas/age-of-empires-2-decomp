#ifndef TACTICAL_AI_ACTION_ITEMS_H
#define TACTICAL_AI_ACTION_ITEMS_H

struct TacticalActionItem {
    unsigned char m_type;
    char pad01[31];
    int m_arg2;
    char pad24[10];
    unsigned char m_field2E;
};

struct TacticalActionPlayer {
    char pad00[6964];
    void *m_field1B34;
};

struct TacticalActionManager {
    char pad00[8];
    TacticalActionPlayer *m_player;
};

extern "C" {
    void func_00307270(TacticalActionManager *self, TacticalActionItem *item);
    void func_316130(void *self, TacticalActionItem *item);
    int func_2d33e0(void *field1B34, short arg1);
    TacticalActionItem *func_316ea0(void *self, int arg1, int zero);

    /**
     * Action item validator and dispatcher.
     * VRAM: 0x307220 - 0x307270 (80 bytes).
     */
    void func_00307220(void *self, TacticalActionItem *item);

    /**
     * Action item creator.
     * VRAM: 0x3072D0 - 0x307320 (80 bytes).
     */
    int func_003072D0(void *self, int arg1, int arg2);
}

#endif // TACTICAL_AI_ACTION_ITEMS_H
