#include <cassert>
#include "zone_spatial_view_deserialize.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

float D_004E2F24 = 2.0f;
float D_004E281C = 1.0f;

static int s_bytes_read = 0;
static int s_node_allocs = 0;

struct Node {
    char pad[0x4];
    Node *next;
};

static Node s_nodes[5];

extern "C" void func_226D90(void *stream, void *buf, int size) {
    s_bytes_read += size;
    if (size == 4 && s_bytes_read == 0x30 + 0x30 + 0xC + 0xC + 0xC + 0xC + 4*5 + 4) {
        // Mock count = 2
        *(int *)buf = 2;
    }
}

extern "C" void *func_1FC4F0() {
    if (s_node_allocs < 2) {
        return &s_nodes[s_node_allocs++];
    }
    return nullptr;
}

extern "C" void func_1FD230(void *node, void *stream) {
}

struct SpatialViewObj {
    char pad_0[0x4];
    char f4[0x30];
    char f34[0x30];
    char f64[0xC];
    char f70[0xC];
    char f7C[0xC];
    char f88[0xC];
    int f94;
    int f98;
    int f9C;
    int fA0;
    int fA4;
    Node *head_A8;
    int fAC;
    int fB0;
    int fB4;
};

static void test_deserialize() {
    SpatialViewObj obj;
    for (int i = 0; i < sizeof(obj); i++) ((char *)&obj)[i] = 0;

    s_bytes_read = 0;
    s_node_allocs = 0;

    func_001DB2C0((::SpatialViewObj *)&obj, nullptr);
    assert(s_node_allocs == 2);
    assert(obj.head_A8 != nullptr);
}

int main(int argc, char **argv) {
    test_deserialize();
    return 0;
}
