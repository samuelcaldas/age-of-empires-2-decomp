#ifndef RENDER_MANAGER_STATS_OVERLAY_H
#define RENDER_MANAGER_STATS_OVERLAY_H

struct RenderTimer {
    int total_time;
    int frame_time;
    int last_tick;
    int is_active;
    int is_paused;
    int last_delta;
    int max_delta;
    int last_max_delta;
};

struct RenderManagerStatsOverlay {
    char pad_00[0x1AC];
    void *field_1AC;
    char pad_1B0[0x268];
    char field_418[0x100];
    int field_518;
    char pad_51C[0x14];
    int field_530;
    char pad_534[8];
    RenderTimer timers[30];
    char pad_8FC[0x10];
    char field_90C[0xB0];
};

extern const char D_00491AE0[];

extern "C" {
int func_11A498(char *buf, const char *fmt, ...);
void func_192B30(void *obj, void *data, int size);

void func_00187b40(RenderManagerStatsOverlay *self);
void func_00187c40();
void func_00187c50();
void func_00187c60();
void func_00187c70(RenderManagerStatsOverlay *self);
}

#endif // RENDER_MANAGER_STATS_OVERLAY_H
