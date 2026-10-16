#ifndef TACTICAL_AI_ACTION_WAYPOINTS_H
#define TACTICAL_AI_ACTION_WAYPOINTS_H

struct Waypoint {
    char pad00[36];
    short m_id;      // 36 (0x24)
    char pad26[28];
    float x;         // 68 (0x44)
    float y;         // 72 (0x48)
    float z;         // 76 (0x4C)
};

struct WaypointActionManager {
    void *m_vtable; // 0
    char pad04[60];
    void *m_field40; // 64 (0x40)
    char pad44[64];
    void *m_field84; // 132 (0x84)
    void *m_field88; // 136 (0x88)
    char pad8C[264];
    int m_field194;  // 404 (0x194)
    char m_field198; // 408 (0x198)
    char pad199[3];
    int m_field19C;  // 412 (0x19C)
    int m_field1A0;  // 416 (0x1A0)
    int m_field1A4;  // 420 (0x1A4)
    int m_field1A8;  // 424 (0x1A8)
    int m_field1AC;  // 428 (0x1AC)
    char m_field1B0; // 432 (0x1B0)
    unsigned char m_field1B1; // 433 (0x1B1)
    unsigned char m_field1B2; // 434 (0x1B2)
    unsigned char m_field1B3; // 435 (0x1B3)
    char pad1B4[4];
    float m_floatX;  // 440 (0x1B8)
    float m_floatY;  // 444 (0x1BC)
    float m_floatZ;  // 448 (0x1C0)
    char pad1C4[12];
    int m_field1D0;  // 464 (0x1D0)
    int m_array1[5]; // 468
    int m_array3[5]; // 488
    int m_array2[5]; // 508
    float m_array4[5]; // 528
    float m_array5[5]; // 548
    float m_array6[5]; // 568
};

extern "C" {
    int func_2261c0();

    /**
     * Action manager waypoint FIFO cache coordinator.
     * VRAM: 0x3074B0 - 0x307640 (400 bytes).
     */
    void func_003074B0(WaypointActionManager *self, Waypoint *wp);
}

#endif // TACTICAL_AI_ACTION_WAYPOINTS_H
