#pragma exceptions off
#include "unit_action_build_rate.h"

extern const int D_00486BB0[8] = { 69, 70, 71, 72, 73, 74, 75, 76 };
extern const int D_00486BD0[8] = { 118, 119, 120, 121, 122, 123, 124, 125 };
extern const int D_00486BF0[8] = { 136, 137, 138, 139, 140, 141, 142, 143 };
extern const int D_00486C10[8] = { 144, 145, 146, 147, 148, 149, 150, 151 };
extern const int D_00486C30[8] = { 110, 111, 112, 113, 114, 115, 116, 117 };
extern const int D_00486C50[8] = { 156, 157, 158, 159, 160, 161, 162, 163 };

typedef void (*Method7C)(void *obj, int stat_id, float val, int zero);

static void call_stat(void *obj, int stat_id, float val) {
    void *vt = *(void**)((char*)obj + 6960);
    Method7C fn = *(Method7C*)((char*)vt + 124);
    fn(obj, stat_id, val, 0);
}

static void record_type_stats(void *player_ptr, void *world, float sum_rate) {
    call_stat(player_ptr, 20, 1.0f);
    call_stat(player_ptr, 170, sum_rate);
    call_stat(world, 154, 1.0f);
    call_stat(world, 152, sum_rate);

    int pidx = *(int*)((char*)world + 2976) - 1;
    call_stat(player_ptr, D_00486BB0[pidx], 1.0f);
    call_stat(world, D_00486BF0[pidx], 1.0f);
    call_stat(player_ptr, 172, sum_rate);
    call_stat(world, 153, sum_rate);
    call_stat(player_ptr, D_00486C30[pidx], sum_rate);
}

static void record_default_stats(void *player_ptr, void *world, float sum_rate) {
    call_stat(player_ptr, 43, 1.0f);
    call_stat(player_ptr, 170, sum_rate);
    call_stat(world, 152, sum_rate);
    call_stat(world, 155, 1.0f);

    int pidx = *(int*)((char*)world + 2976);
    call_stat(player_ptr, D_00486BD0[pidx], 1.0f);
    call_stat(world, D_00486C10[pidx], 1.0f);
    call_stat(player_ptr, 172, sum_rate);
    call_stat(world, 153, sum_rate);
    call_stat(player_ptr, D_00486C50[pidx], sum_rate);
}

void func_0026EF50(ActionRebind *self, int a1, int a2, void *player_ptr, int t0, int has_subactions) {
    (void)a1; (void)a2; (void)t0;
    float time_rem = *(float*)((char*)self + 48);

    if (has_subactions != 0) {
        void *p304 = *(void**)((char*)self + 304);
        if (p304 != 0) {
            typedef void (*Method84)(void *p);
            void *vt = *(void**)p304;
            Method84 fn = *(Method84*)((char*)vt + 132);
            fn(p304);
            return;
        }
    }

    if (time_rem <= 0.0f) {
        return;
    }

    func_195F40(self, player_ptr);

    float cur_time = *(float*)((char*)self + 48);
    if (time_rem - cur_time < 1.0f) {
        *(float*)((char*)self + 48) = time_rem - 1.0f;
    }

    void *world = *(void**)((char*)self + 8);
    int pcount = *(int*)((char*)world + 2976);
    if (pcount <= 0) {
        *(unsigned char*)((char*)self + 59) = 60;
        for (int i = 0; i < 4; ++i) {
            void *child = *(void**)((char*)self + 308 + i * 4);
            if (child != 0) {
                *(float*)((char*)child + 48) = *(float*)((char*)self + 48);
            }
        }
        return;
    }

    if (*(float*)((char*)self + 48) >= 1.0f) {
        void *master = *(void**)((char*)self + 4);
        short mtype = *(short*)((char*)master + 8);

        if (mtype == 82) {
            func_27B700(self, 7, (float)*(int*)((char*)world + 2976), 0.0f, 0);
        }
        if (mtype == 276) {
            func_27B700(self, 5, (float)*(int*)((char*)world + 2976), 0.0f, 0);
        }

        void *p304 = *(void**)((char*)self + 304);
        if (p304 == 0 && mtype != 72 && mtype != 117 && mtype != 155) {
            float sum_rate = 0.0f;
            for (int i = 0; i < 3; ++i) {
                short rid = *(short*)((char*)master + 300 + i * 6);
                if (rid >= 0) {
                    unsigned char mode = *(unsigned char*)((char*)master + 304 + i * 6);
                    if (mode == 1) {
                        sum_rate += (float)*(short*)((char*)master + 302 + i * 6);
                    }
                }
            }

            int is_type = (mtype == 42 || mtype == 331 || mtype == 682 || mtype == 730 || mtype == 683 || mtype == 729);

            if (is_type) {
                record_type_stats(player_ptr, world, sum_rate);
            }
            if (!is_type) {
                record_default_stats(player_ptr, world, sum_rate);
            }
        }
    }

    *(unsigned char*)((char*)self + 59) = 60;
    for (int i = 0; i < 4; ++i) {
        void *child = *(void**)((char*)self + 308 + i * 4);
        if (child != 0) {
            *(float*)((char*)child + 48) = *(float*)((char*)self + 48);
        }
    }
}
