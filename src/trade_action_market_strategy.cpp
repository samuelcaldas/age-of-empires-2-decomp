#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern void *D_004E3180;
extern unsigned char D_514DF0[64];

void func_118E30(void *base, unsigned int num, unsigned int size, int (*compar)(const void *, const void *));
void *memset(void *dst, int val, unsigned int size);
int func_00149610(const void *a, const void *b);
int func_202B10(void *ptr);
void *func_332e60(void *mgr, short id);
}

struct TradeAction {
    char pad_00[0x21];
    unsigned char m_max_routes; // 0x21 (33)
    char pad_22[0x0E];
    unsigned char m_route_count; // 0x30 (48)
    unsigned char m_selected_routes[1]; // 0x31 (49)
    char pad_32[0x46];
    char m_routes[1][32]; // 0x78 (120)
};

extern "C" {

void func_00149660(TradeAction *self, void *player, int mode) {
    func_118E30(self->m_routes, self->m_route_count, 32, func_00149610);
    memset(D_514DF0, 0, 64);

    int count = 0;
    if ((unsigned char)mode == 1) {
        for (int i = 0; i < self->m_route_count; i++) {
            if (D_514DF0[i] == 1) continue;
            char *r = (char *)self + (i * 32);
            if ((unsigned char)r[123] == 0) continue;
            if (*(float *)(r + 148) == 0.0f) continue;
            if (count >= self->m_max_routes) break;
            self->m_selected_routes[count++] = i;
            D_514DF0[i] = 1;
        }
    }

    if (func_202B10(*(void **)((char *)player + 8)) == 1) {
        for (int i = 0; i < self->m_route_count; i++) {
            if (D_514DF0[i] == 1) continue;
            char *r = (char *)self + (i * 32);
            if ((unsigned char)r[123] == 1) continue;
            if (*(float *)(r + 148) == 0.0f) continue;
            if (count >= self->m_route_count) break;
            self->m_selected_routes[count++] = i;
            D_514DF0[i] = 1;
        }
    }

    for (int i = 0; i < self->m_route_count; i++) {
        if (D_514DF0[i] == 1) continue;
        char *r = (char *)self + (i * 32);
        if ((unsigned char)r[123] == 1) continue;
        if (*(float *)(r + 148) == 0.0f) continue;
        void *game = D_004E3180;
        void *mgr = *(void **)((char *)game + 1028);
        void *market = func_332e60(mgr, *(short *)(r + 120));
        void *sub = *(void **)((char *)market + 4);
        short bldg_type = *(short *)((char *)sub + 14);
        if (bldg_type == 49) continue;
        if (count >= self->m_route_count) break;
        self->m_selected_routes[count++] = i;
        D_514DF0[i] = 1;
    }

    for (int i = 0; i < self->m_route_count; i++) {
        if (D_514DF0[i] == 1) continue;
        char *r = (char *)self + (i * 32);
        if ((unsigned char)r[123] == 1) continue;
        if (*(float *)(r + 148) == 0.0f) continue;
        void *game = D_004E3180;
        void *mgr = *(void **)((char *)game + 1028);
        void *market = func_332e60(mgr, *(short *)(r + 120));
        void *sub = *(void **)((char *)market + 4);
        short bldg_type = *(short *)((char *)sub + 14);
        if (bldg_type != 49) continue;
        if (count >= self->m_route_count) break;
        self->m_selected_routes[count++] = i;
        D_514DF0[i] = 1;
    }

    if ((unsigned char)mode == 0) {
        for (int i = 0; i < self->m_route_count; i++) {
            if (D_514DF0[i] == 1) continue;
            char *r = (char *)self + (i * 32);
            if ((unsigned char)r[123] == 0) continue;
            if (*(float *)(r + 148) == 0.0f) continue;
            if (count >= self->m_route_count) break;
            self->m_selected_routes[count++] = i;
            D_514DF0[i] = 1;
        }
    }
}

}
