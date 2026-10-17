#include <cassert>
#include <vector>
#include "zone_spatial_view_serialize.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct Node {
    char pad[0x4];
    Node *next;
};

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

static int s_bytes_written = 0;
static int s_nodes_visited = 0;

extern "C" void func_226F70(void *stream, const void *buf, int size) {
    s_bytes_written += size;
}

extern "C" void func_1FD120(void *node, void *stream) {
    s_nodes_visited++;
}

static void test_serialize() {
    SpatialViewObj obj;
    for (int i = 0; i < sizeof(obj); i++) ((char *)&obj)[i] = 0;

    Node n1; n1.next = nullptr;
    Node n2; n2.next = &n1;
    obj.head_A8 = &n2;

    s_bytes_written = 0;
    s_nodes_visited = 0;

    func_001DB120((::SpatialViewObj *)&obj, nullptr);
    assert(s_nodes_visited == 2);
    assert(s_bytes_written > 100);
}

int main(int argc, char **argv) {
    test_serialize();
    return 0;
}
