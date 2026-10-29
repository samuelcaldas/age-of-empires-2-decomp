#pragma exceptions off

#include "zone_spatial_pyramid_alloc_node.h"

extern "C" {
void *func_100850(int size);
}

struct Node {
    void *cell;      // 0x0
    int x;           // 0x4
    int y;           // 0x8
    int level;       // 0xC
    void *t2;        // 0x10
    void *t3;        // 0x14
    float total;     // 0x18
    float g;         // 0x1C
    void *next;      // 0x20
    void *parent;    // 0x24
    char dir;        // 0x28
};

struct Manager {
    void ***root;    // 0x0
    char pad[0x7C];  // 0x4..0x7F
    Node *free_list; // 0x80
};

extern "C" void *func_001D4330(
    void *self, int x, int y, int level, float g_score, float h_score,
    void *parent, int dir, void *t2, void *t3
) {
    Manager *mgr = (Manager *)self;
    Node *node = mgr->free_list;
    if (node) {
        mgr->free_list = (Node *)node->next;
    }
    if (!node) {
        node = (Node *)func_100850(0x2C);
    }

    node->x = x;
    node->y = y;
    node->level = level;
    node->g = g_score;
    node->total = g_score + h_score;
    node->parent = parent;
    node->dir = (char)dir;
    node->cell = (char *)mgr->root[level][x] + y * 2;
    node->t2 = t2;
    node->t3 = t3;
    node->next = 0;

    return node;
}
