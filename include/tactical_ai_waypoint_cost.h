#ifndef TACTICAL_AI_WAYPOINT_COST_H
#define TACTICAL_AI_WAYPOINT_COST_H

struct WaypointCostCell {
    short m_field00;   // 0 (0x00)
    char pad02[22];    // 2..23
    float m_field18;   // 24 (0x18)
    char pad1C[4];     // 28..31
    float m_field20;   // 32 (0x20)
};

struct WaypointCostManager {
    void *m_vtable;          // 0 (0x00)
    char pad04[8];           // 4..11
    short m_field0C;         // 12 (0x0C)
    char pad0E[2];           // 14..15
    short m_field10;         // 16 (0x10)
    char pad12[2];           // 18..19
    int m_field14;           // 20 (0x14)
    int m_field18;           // 24 (0x18)
    char pad1C[4];           // 28..31
    void *m_field20;         // 32 (0x20)
    char pad24[300];         // 36..335
    void *m_field150;        // 336 (0x150)
    WaypointCostCell *m_grid;// 340 (0x154)
    short m_field158;        // 344 (0x158)
    char pad15A[2];          // 346..347
    short m_field15C;        // 348 (0x15C)
    char pad15E[118];        // 350..467
    int m_array1[5];         // 468 (0x1D4)
    int m_array3[5];         // 488 (0x1E8)
    int m_array2[5];         // 508 (0x1FC)
    float m_array4[5];       // 528 (0x210)
    float m_array5[5];       // 548 (0x224)
    float m_array6[5];       // 568 (0x238)
};

extern "C" {
    int func_123350(float val);
    int func_2261c0();
    void func_1ad450(void *field20, int x, int y, int length, int mark);
    void func_1ad270(void *field20, int x, int y, int length, int mark);

    /**
     * Waypoint path cost and terrain elevation evaluator.
     * VRAM: 0x307640 - 0x307A00 (960 bytes).
     */
    void func_00307640(WaypointCostManager *self);
}

#endif // TACTICAL_AI_WAYPOINT_COST_H
