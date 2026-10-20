#ifndef TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_INSTANCE_H
#define TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_INSTANCE_H

struct CombatSubsystemControllerInstance {
    void *m_vtable;                 // 0x00
    char pad04[0xDC - 0x04];        // 0x04..0xDC
    int m_field_DC;                 // 0xDC
    char padE0[0x2398 - 0xE0];      // 0xE0..0x2398
    int m_field_2398;               // 0x2398
    char pad239C[0x3408 - 0x239C];  // 0x239C..0x3408
    int m_field_3408;               // 0x3408
    int m_field_340C;               // 0x340C
    int m_field_3410;               // 0x3410
    int m_field_3414;               // 0x3414
    int m_field_3418;               // 0x3418
    int m_field_341C;               // 0x341C
    int m_field_3420;               // 0x3420
    int m_field_3424;               // 0x3424
    int m_field_3428;               // 0x3428
    int m_field_342C;               // 0x342C
    int m_field_3430;               // 0x3430
    int m_field_3434[10];           // 0x3434
    int m_field_345C[10];           // 0x345C
    int m_field_3484;               // 0x3484
};

extern void *D_004DED20[];

extern "C" {
    void *func_318340(void *self);
    CombatSubsystemControllerInstance *func_003291F0(
        CombatSubsystemControllerInstance *self
    );
}

#endif // TACTICAL_AI_COMBAT_SUBSYSTEM_CONTROLLER_INSTANCE_H
