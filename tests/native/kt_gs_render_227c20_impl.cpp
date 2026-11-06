#include <cstdint>

struct GridNode {
    int32_t val0;
    int32_t val4;
    float fval8;
    float fval12;
    GridNode* next;
    GridNode* prev;
};

struct GridCtx {
    uint8_t pad0[16];
    int32_t width;   // offset 16
    int32_t height;  // offset 20
    uint8_t pad24[24];
    GridNode** grid; // offset 48
};

extern "C" {

void func_00227C20(GridCtx* ctx) {
    for (int y = 0; y < ctx->height; y++) {
        for (int x = 0; x < ctx->width; x++) {
            GridNode* row = ctx->grid[y];
            row[x].next = nullptr;
            row[x].prev = nullptr;
        }
    }
}

}
