#ifndef TACTICAL_AI_MODE_OPS_H
#define TACTICAL_AI_MODE_OPS_H

struct TacticalModeManager {
    char pad00[404];
    int m_field194; // 404 (0x194)
};

extern "C" {
    /**
     * Tactical AI set operational mode.
     * VRAM: 0x309310 - 0x309320 (16 bytes slice, 8 bytes code).
     */
    void func_00309310(TacticalModeManager *self, int mode);

    /**
     * Tactical AI get operational mode.
     * VRAM: 0x309320 - 0x309330 (16 bytes slice, 8 bytes code).
     */
    int func_00309320(TacticalModeManager *self);
}

#endif // TACTICAL_AI_MODE_OPS_H
