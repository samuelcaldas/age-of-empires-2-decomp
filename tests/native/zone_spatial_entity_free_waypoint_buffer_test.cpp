#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_free_waypoint_buffer.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct ListNode {
    void *pad0;
    ListNode *next;
    char pad_08[0x8];
    void *val_10;
};

struct SpatialEntity {
    char pad_00[0xB4];
    ListNode *field_B4;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

static int s_calls_fce30 = 0;
static int s_calls_fce00 = 0;
static int s_calls_3334a0 = 0;
static int s_calls_1fc6c0 = 0;
static int s_calls_1fdad0 = 0;

static GlobalContext s_mock_ctx;
extern "C" {
void *D_004E3180 = &s_mock_ctx;

void *func_1FCE30(void *sub) {
    s_calls_fce30++;
    return (void *)0x1234;
}

int func_1FCE00(void *sub) {
    s_calls_fce00++;
    return 1;
}

void *func_3334A0(void *obj, int id) {
    s_calls_3334a0++;
    return (void *)0x5678;
}

void *func_1FC6C0(int arg) {
    s_calls_1fc6c0++;
    return (void *)0xABCD;
}

void func_1FDAD0(void *sub, void *buf) {
    s_calls_1fdad0++;
}
}

static void test_null_field_b4() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_B4 = 0;

    void *out = (void *)0xDEADBEEF;
    void *ret = func_001DEEE0(&ent, &out);

    assert(ret == 0);
    assert(out == 0);
}

static void test_valid_chain() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    ListNode n2;
    std::memset(&n2, 0, sizeof(n2));
    n2.next = 0;
    n2.val_10 = (void *)0x9999;

    ListNode n1;
    std::memset(&n1, 0, sizeof(n1));
    n1.next = &n2;
    n1.val_10 = (void *)0x1111;

    ent.field_B4 = &n1;

    s_calls_fce30 = 0;
    s_calls_1fc6c0 = 0;
    s_calls_1fdad0 = 0;

    void *out = 0;
    void *ret = func_001DEEE0(&ent, &out);

    assert(s_calls_fce30 == 1);
    assert(s_calls_1fc6c0 == 1);
    assert(s_calls_1fdad0 == 1);
    assert(ret == (void *)0xABCD);
    assert(out == (void *)0x9999);
}

int main() {
    test_null_field_b4();
    test_valid_chain();
    std::printf("zone_spatial_entity_free_waypoint_buffer_test passed\n");
    return 0;
}
