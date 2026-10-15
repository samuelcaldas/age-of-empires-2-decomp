#ifndef TACTICAL_AI_PLAYER_OPS_H
#define TACTICAL_AI_PLAYER_OPS_H

struct Field04 {
    char pad[80];
    short m_count;
    short pad82;
    void **m_items;
};

struct Manager {
    char pad[4];
    Field04 *m_field04;
    char pad08[21032];
    int m_counts[16];
    int m_data[16][30];
};

extern "C" {
    void *func_332e60(void *manager, int identifier);
    void func_2e05f0(void *player, int cmd, int zero);

    /**
     * Stub virtual method for Tactical AI Player Operations.
     */
    void func_00305B90(Manager *self);

    /**
     * Retrieve target object / player by identifier from manager.
     */
    void *func_00305BA0(Manager *self, int identifier);

    /**
     * Dispatch buffered commands to all active players.
     */
    void func_00305BD0(Manager *self);
}

#endif // TACTICAL_AI_PLAYER_OPS_H
