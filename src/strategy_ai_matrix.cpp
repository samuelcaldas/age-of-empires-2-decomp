#include "sub_list.h"

struct MatrixManager {
    char m_pad[0x18];
    int *m_items;
};

struct MatrixTable {
    int m_count;
    int m_grid[8][10];
};

extern "C" {

void func_00226D90(void *stream, void *dst, int size);
void func_00226F70(void *stream, void *dst, int size);
void func_00100670(void *ptr);

MatrixTable *func_00145960(MatrixTable *self, void *stream, int val) {
    self->m_count = val;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            func_00226D90(stream, &self->m_grid[i][j], 4);
        }
    }
    return self;
}

void *func_00145A10(void *self, int flag) {
    if (self != 0) {
        short f = (short)flag;
        *(int *)self = 0;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

int func_00145A60(MatrixTable *self, void *stream) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            func_00226F70(stream, &self->m_grid[i][j], 4);
        }
    }
    return 1;
}

void func_00145B00(int (*grid)[10], int a1, int a2) {
    grid[a1 - 1][a2] = -1;
}

void func_00145B30(int (*grid)[10], int a1, int a2, int a3) {
    MatrixManager *mgr = *(MatrixManager **)grid;
    int *items = mgr->m_items;
    grid[a1 - 1][a2] = (int)&items[a3 * 250];
}

int func_00145B70(int (*grid)[10], int a1, int a2) {
    int v1 = grid[a1 - 1][a2];
    if (v1 == -1) {
        return 0;
    }
    MatrixManager *mgr = *(MatrixManager **)grid;
    return (unsigned int)v1 <= (unsigned int)mgr->m_items;
}

}
