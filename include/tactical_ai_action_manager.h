#ifndef TACTICAL_AI_ACTION_MANAGER_H
#define TACTICAL_AI_ACTION_MANAGER_H

struct TacticalActionManagerObj {
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
    char m_field1B1; // 433 (0x1B1)
    char m_field1B2; // 434 (0x1B2)
    char m_field1B3; // 435 (0x1B3)
    char pad1B4[28];
    int m_field1D0;  // 464 (0x1D0)
    int m_array1[5]; // 468
    int m_array3[5]; // 488
    int m_array2[5]; // 508
    int m_array4[5]; // 528
    int m_array5[5]; // 548
    int m_array6[5]; // 568
};

extern "C" {
    extern void *D_4DE780;
    extern void *D_4DEBF0;
    extern const char D_004D1930[];
    extern void *D_004E3180;

    void *func_3285d0(void *self);
    void func_1a2cf0(void *self, int zero);
    void func_100670(void *ptr);
    void func_1a34d0(void *self);
    void func_242fc0(void *field40, int arg1);
    void func_118de0(const char *msg);

    /**
     * Tactical Action Manager Constructor.
     * VRAM: 0x307320 - 0x3073C0 (160 bytes).
     */
    void *func_00307320(TacticalActionManagerObj *self);

    /**
     * Tactical Action Manager Scalar Deleting Destructor.
     * VRAM: 0x3073C0 - 0x307420 (96 bytes).
     */
    void *func_003073C0(TacticalActionManagerObj *self, int flags);

    /**
     * Tactical Action Manager Status Notification Coordinator.
     * VRAM: 0x307420 - 0x3074B0 (144 bytes).
     */
    void func_00307420(TacticalActionManagerObj *self, int arg1);
}

#endif // TACTICAL_AI_ACTION_MANAGER_H
