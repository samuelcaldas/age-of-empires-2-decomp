#include <cstdint>
#include <cassert>
#include <cstring>
#include <iostream>

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
    GridNode** grid; // offset 48 (pointer to array of GridNode pointers)
};

extern "C" {
    void func_00227C20(GridCtx* ctx);
}

int main() {
    GridCtx ctx;
    std::memset(&ctx, 0, sizeof(ctx));
    ctx.width = 2;
    ctx.height = 2;

    GridNode nodes[4];
    std::memset(nodes, 0, sizeof(nodes));
    nodes[0].next = (GridNode*)0x1234;
    nodes[0].prev = (GridNode*)0x5678;

    GridNode* rows[2] = { &nodes[0], &nodes[2] };
    ctx.grid = rows;

    func_00227C20(&ctx);

    assert(nodes[0].next == nullptr);
    assert(nodes[0].prev == nullptr);

    std::cout << "kt_gs_render_227c20 native behavioral test passed!" << std::endl;
    return 0;
}
