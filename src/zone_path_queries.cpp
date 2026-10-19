#pragma exceptions off
#include "sub_list.h"
#include "zone_path_queries.h"

extern "C" {

int func_123350(float val);
int func_1234E0(float val);
int func_122058(int a0, int a1);
int func_1220B0(int a0, int a1);
int func_122690(int a0, int a1 = 0);
int func_122118(int a0, int a1 = 0);
int func_122748(int a0);

int func_262570(
    void *internal_obj,
    int a5,
    int a6,
    int py1,
    int target1,
    int py2,
    int target2,
    int mode,
    float *px,
    int ten
);
int func_001D0350(
    void *a0,
    short *out_x,
    short *out_y,
    float x,
    float y,
    int a5 = 0,
    int a6 = 0
);
int func_326F60(
    void *a0,
    int a1,
    int a2,
    short c1_x,
    short c1_y,
    short c2_x,
    short c2_y,
    short c3_x,
    short c3_y,
    short c4_x,
    short c4_y,
    int a12,
    unsigned char a13,
    int a14
);

extern void *D_004E3180;
extern void *D_4E3400;
extern void *D_4E3408;

void func_001C8490(void *obj, char val) {
    if (!*(unsigned char *)((char *)obj + 0x43)) {
        *(char *)((char *)obj + 0x42) = val;
    }
}

int func_001C84B0(MasterInfo *master, float *p_x, float *p_y, void *map, int snap) {
    void *s0 = *(void **)((char *)map + 0x3C);
    int map_w = *(int *)((char *)s0 + 0x8);
    int map_h = *(int *)((char *)s0 + 0xC);

    float rx = master->rx;
    float min_bound_x = *p_x - rx;
    float max_x = (float)map_w - 0.00001f;
    float ry = master->ry;
    float min_bound_y = *p_y - ry;
    float max_y = (float)map_h - 0.00001f;
    float max_bound_x = *p_x + rx;
    float max_bound_y = *p_y + ry;

    if (min_bound_x < 0.0f) {
        *p_x = *p_x - min_bound_x;
        max_bound_x -= min_bound_x;
    }
    if (min_bound_y < 0.0f) {
        max_bound_y -= min_bound_y;
        *p_y = *p_y - min_bound_y;
    }
    if (max_bound_x >= max_x) {
        *p_x += (max_x - max_bound_x);
    }
    if (max_bound_y >= max_y) {
        *p_y += (max_y - max_bound_y);
    }

    if (snap) {
        float snap_rx = master->rx;
        float frac_rx = snap_rx - (float)func_123350(snap_rx);
        if (frac_rx == 0.0f) {
            float cur_x = *p_x;
            float frac_x = cur_x - (float)func_123350(cur_x);
            if (frac_x > 0.5f) {
                *p_x = (float)func_123350(cur_x) + 1.0f;
            } else {
                *p_x = (float)func_123350(cur_x);
            }
        } else {
            *p_x = (float)func_123350(*p_x) + 0.5f;
        }

        float snap_ry = master->ry;
        float frac_ry = snap_ry - (float)func_123350(snap_ry);
        if (frac_ry == 0.0f) {
            float cur_y = *p_y;
            float frac_y = cur_y - (float)func_123350(cur_y);
            if (frac_y > 0.5f) {
                *p_y = (float)func_123350(cur_y) + 1.0f;
            } else {
                *p_y = (float)func_123350(cur_y);
            }
        } else {
            *p_y = (float)func_123350(*p_y) + 0.5f;
        }
    }

    return 1;
}

int func_001C8780(
    MasterInfo *master,
    void *map,
    short *out0,
    short *out1,
    short *out2,
    short *out3,
    short *out4,
    short *out5,
    short *out6,
    short *out7,
    float x,
    float y
) {
    float f20 = master->rx + (x - (float)func_123350(x));
    float f21 = master->ry + (y - (float)func_123350(y));

    void *ctx = *(void **)((char *)map + 0x3C);
    short half_w = *(short *)((char *)ctx + 0x8EB4);
    short half_h = *(short *)((char *)ctx + 0x8EB2);

    // Corner 0 (+rx, +ry)
    *out0 = (short)func_123350((float)half_w * (f21 + f20));
    int s2 = func_122058(0x3FF00000, func_1234E0(f21));
    int s7 = func_1220B0(s2, func_1234E0(f20));
    *out1 = (short)func_122748(func_122118(func_122690(half_h, s7)));

    // Corner 1 (-rx, +ry)
    f20 -= 2.0f * master->rx;
    *out2 = (short)func_123350((float)half_w * (f21 + f20));
    int s4 = func_122690(half_h);
    int step1 = func_1220B0(s2, func_1234E0(f20));
    *out3 = (short)func_122748(func_122118(s4, step1));

    // Corner 2 (-rx, -ry)
    f21 -= 2.0f * master->ry;
    *out4 = (short)func_123350((float)half_w * (f21 + f20));
    s2 = func_122058(0x3FF00000, func_1234E0(f21));
    int s3 = func_1220B0(s2, func_1234E0(f20));
    *out5 = (short)func_122748(func_122118(func_122690(half_h, s3)));

    // Corner 3 (+rx, -ry)
    f20 += 2.0f * master->rx;
    *out6 = (short)func_123350((float)half_w * (f21 + f20));
    int s0_val = func_122690(half_h);
    int step3 = func_1220B0(s2, func_1234E0(f20));
    *out7 = (short)func_122748(func_122118(s0_val, step3));

    return 1;
}
void func_001C8A50(
    void *self,
    float *p_x,
    float *p_y,
    void *target_info,
    int mode,
    int a5,
    int a6,
    int a7,
    unsigned char a8
) {
    void *internal_obj = *(void **)((char *)self + 0x10);
    if (!internal_obj) {
        return;
    }

    func_262570(
        internal_obj,
        a5,
        a6,
        (int)p_y,
        (int)target_info,
        (int)p_y,
        (int)target_info,
        mode,
        p_x,
        10
    );

    if (!a7) {
        return;
    }

    float rx = *(float *)((char *)self + 0x94);
    float ry = *(float *)((char *)self + 0x98);

    void *sub_mgr = *(void **)((char *)D_004E3180 + 0x404);
    void *ctx = *(void **)((char *)sub_mgr + 0x3C);

    short c1_x, c1_y;
    short c2_x, c2_y;
    short c3_x, c3_y;
    short c4_x, c4_y;

    // Corner 1: (+rx, -ry)
    func_001D0350(ctx, &c1_x, &c1_y, rx, -ry, (int)p_y, (int)target_info);
    // Corner 2: (+rx, +ry)
    func_001D0350(ctx, &c2_x, &c2_y, rx, ry, (int)p_y, (int)target_info);
    // Corner 3: (-rx, +ry)
    func_001D0350(ctx, &c3_x, &c3_y, -rx, ry, (int)p_y, (int)target_info);
    // Corner 4: (-rx, -ry)
    func_001D0350(ctx, &c4_x, &c4_y, -rx, -ry, (int)p_y, (int)target_info);

    func_326F60(
        D_4E3408,
        1,
        (int)target_info,
        c1_x,
        c1_y,
        c2_x,
        c2_y,
        c3_x,
        c3_y,
        c4_x,
        c4_y,
        11,
        a8,
        (int)D_4E3400
    );
}

void *func_001C8C00(void *self) {
    return *(void **)((char *)self + 0x84);
}

void *func_001C8C10(void *self) {
    return *(void **)((char *)self + 0x88);
}

}
