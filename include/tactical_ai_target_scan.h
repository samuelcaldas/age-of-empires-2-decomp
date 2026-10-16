#ifndef TACTICAL_AI_TARGET_SCAN_H
#define TACTICAL_AI_TARGET_SCAN_H

#if defined(__cplusplus) && __cplusplus >= 201103L
#include <cstddef>
#define SCAN_ASSERT(cond, msg) static_assert(cond, msg)
#else
#define SCAN_ASSERT(cond, msg)
#endif

struct TargetTypeDesc {
    unsigned char m_type_code; // 0
    char pad01[7];
    short m_id;                // 8
    char pad0A[4];
    short m_category;          // 14 (0x0E)
    char pad10[103];
    unsigned char m_tag77;     // 119 (0x77)
    unsigned char m_tag78;     // 120 (0x78)
    char pad79[303];
    unsigned char m_flag424;   // 424 (0x1A8)
};

SCAN_ASSERT(offsetof(TargetTypeDesc, m_type_code) == 0, "m_type_code offset");
SCAN_ASSERT(offsetof(TargetTypeDesc, m_id) == 8, "m_id offset");
SCAN_ASSERT(offsetof(TargetTypeDesc, m_category) == 14, "m_category offset");
SCAN_ASSERT(offsetof(TargetTypeDesc, m_tag77) == 119, "m_tag77 offset");
SCAN_ASSERT(offsetof(TargetTypeDesc, m_tag78) == 120, "m_tag78 offset");
SCAN_ASSERT(offsetof(TargetTypeDesc, m_flag424) == 424, "m_flag424 offset");

struct TargetEntity {
    void *m_vtable;            // 0
    TargetTypeDesc *m_type_desc; // 4
    char pad08[46];
    unsigned char m_field36;   // 54 (0x36)
    char pad37[13];
    float m_posX;              // 68 (0x44)
    float m_posY;              // 72 (0x48)
    char pad4C[271];
    unsigned char m_flag347;   // 347 (0x15B)
    float m_coord348;          // 348 (0x15C)
    float m_coord352;          // 352 (0x160)
    char pad164[4];
    short m_field364;          // 364 (0x16C)
    float m_field368;          // 368 (0x170)
};

SCAN_ASSERT(offsetof(TargetEntity, m_field36) == 54, "m_field36 offset");
SCAN_ASSERT(offsetof(TargetEntity, m_posX) == 68, "m_posX offset");
SCAN_ASSERT(offsetof(TargetEntity, m_posY) == 72, "m_posY offset");
SCAN_ASSERT(offsetof(TargetEntity, m_flag347) == 347, "m_flag347 offset");

struct TargetEntityList {
    char pad00[116];
    TargetEntity **m_entities; // 116 (0x74)
    short m_count;             // 120 (0x78)
};

struct TargetPlayerManager {
    TargetEntityList *m_list;  // 0 (0x00)
    char pad04[112];
    TargetEntity **m_units;    // 116 (0x74)
    short m_unit_count;        // 120 (0x78)
    char pad7A[6];
    TargetEntity **m_items128; // 128 (0x80)
    short m_count132;          // 132 (0x84)
    char pad86[6];
    TargetEntity **m_items140; // 140 (0x8C)
    short m_count144;          // 144 (0x90)
    char pad92[2830];
    int m_player_id;           // 2976 (0xBA0)
    char padBA4[196];
    void *m_color_info;        // 3176 (0xC68)
    char padC6C[64];
    TargetEntity *m_table3244[40]; // 3244 (0xCAC)
    char padCD4[4];
    int m_fieldD50;            // 3408 (0xD50)
    char padD54[3548];
    void *m_diplomacy_vtable;  // 6960 (0x1B30)
};

SCAN_ASSERT(offsetof(TargetPlayerManager, m_items128) == 128, "m_items128 offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_count132) == 132, "m_count132 offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_items140) == 140, "m_items140 offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_count144) == 144, "m_count144 offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_player_id) == 2976, "m_player_id offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_color_info) == 3176, "m_color_info offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_table3244) == 3244, "m_table3244 offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_fieldD50) == 3408, "m_fieldD50 offset");
SCAN_ASSERT(offsetof(TargetPlayerManager, m_diplomacy_vtable) == 6960, "m_diplomacy_vtable offset");

struct TargetEntityContainer {
    TargetEntityList *m_list;  // 0
};

struct TargetEntitySubsystem {
    char pad00[80];
    short m_player_count;      // 80 (0x50)
    char pad52[2];
    TargetPlayerManager **m_players; // 84 (0x54)
    char pad58[64];
    short m_my_player_index;   // 152 (0x98)
};

SCAN_ASSERT(offsetof(TargetEntitySubsystem, m_my_player_index) == 152, "m_my_player_index offset");

struct TargetScanManager {
    void *m_vtable;                 // 0
    char pad04[28];
    void *m_field20;                // 32 (0x20)
    char pad24[252];
    TargetEntitySubsystem *m_field11C; // 284 (0x11C)
    TargetPlayerManager *m_player;  // 288 (0x120)
    char pad124[96];
    int m_field184;                 // 388 (0x184)
    char pad188[12];
    int m_field194;                 // 404 (0x194)
    char pad198[4];
    int m_field19C;                 // 412 (0x19C)
    int m_field1A0;                 // 416 (0x1A0)
};

extern "C" {
    int func_2261c0();
    int func_1ab8f0(void *field20, int one);
    void func_1ab9d0(void *field20);
    void func_309500(void *self, TargetEntity *ent, int mark, int a3, int t0);
    void func_309330(void *self, TargetEntity *ent, int a2, int a3, int t0);
    int func_00268500(TargetEntity *ent);
    int func_00268530(TargetEntity *ent);
    int func_00268610(TargetEntity *ent, int a1, int a2, int a3, int t0, int t1, int t2, int t3);
    int func_26ad20(TargetEntity *ent, int sixteen);
    int func_123350(float val);
    void func_00308A70(void *self, int x, int y, int mark, int four);
    void func_00307640(void *self);

    void func_00307B80(TargetScanManager *self);
}

#endif // TACTICAL_AI_TARGET_SCAN_H
