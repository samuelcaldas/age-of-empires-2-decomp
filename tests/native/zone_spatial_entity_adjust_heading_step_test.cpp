#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_adjust_heading_step.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

static float s_received_heading = -999.0f;
static int s_vcall_count = 0;

struct SpatialEntity {
    virtual void pad00();
    // 0xC4 is offset 196, so 196/4 = 49 vtable slots. First is 0, so slot 49 is methodC4
    virtual void pad01(); virtual void pad02(); virtual void pad03(); virtual void pad04();
    virtual void pad05(); virtual void pad06(); virtual void pad07(); virtual void pad08();
    virtual void pad09(); virtual void pad0a(); virtual void pad0b(); virtual void pad0c();
    virtual void pad0d(); virtual void pad0e(); virtual void pad0f(); virtual void pad10();
    virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14();
    virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18();
    virtual void pad19(); virtual void pad1a(); virtual void pad1b(); virtual void pad1c();
    virtual void pad1d(); virtual void pad1e(); virtual void pad1f(); virtual void pad20();
    virtual void pad21(); virtual void pad22(); virtual void pad23(); virtual void pad24();
    virtual void pad25(); virtual void pad26(); virtual void pad27(); virtual void pad28();
    virtual void pad29(); virtual void pad2a(); virtual void pad2b(); virtual void pad2c();
    virtual void pad2d(); virtual void pad2e(); virtual void pad2f(); virtual void pad30();
    virtual void methodC4(float heading) {
        s_vcall_count++;
        s_received_heading = heading;
    }

    char pad_after_vptr[0x0C]; // 0x04 to 0x10
    void *field_10;            // 0x10
    char pad_14[0x68];         // 0x14 to 0x7C
    float heading;             // 0x7C
};

void SpatialEntity::pad00() {}
void SpatialEntity::pad01() {} void SpatialEntity::pad02() {} void SpatialEntity::pad03() {} void SpatialEntity::pad04() {}
void SpatialEntity::pad05() {} void SpatialEntity::pad06() {} void SpatialEntity::pad07() {} void SpatialEntity::pad08() {}
void SpatialEntity::pad09() {} void SpatialEntity::pad0a() {} void SpatialEntity::pad0b() {} void SpatialEntity::pad0c() {}
void SpatialEntity::pad0d() {} void SpatialEntity::pad0e() {} void SpatialEntity::pad0f() {} void SpatialEntity::pad10() {}
void SpatialEntity::pad11() {} void SpatialEntity::pad12() {} void SpatialEntity::pad13() {} void SpatialEntity::pad14() {}
void SpatialEntity::pad15() {} void SpatialEntity::pad16() {} void SpatialEntity::pad17() {} void SpatialEntity::pad18() {}
void SpatialEntity::pad19() {} void SpatialEntity::pad1a() {} void SpatialEntity::pad1b() {} void SpatialEntity::pad1c() {}
void SpatialEntity::pad1d() {} void SpatialEntity::pad1e() {} void SpatialEntity::pad1f() {} void SpatialEntity::pad20() {}
void SpatialEntity::pad21() {} void SpatialEntity::pad22() {} void SpatialEntity::pad23() {} void SpatialEntity::pad24() {}
void SpatialEntity::pad25() {} void SpatialEntity::pad26() {} void SpatialEntity::pad27() {} void SpatialEntity::pad28() {}
void SpatialEntity::pad29() {} void SpatialEntity::pad2a() {} void SpatialEntity::pad2b() {} void SpatialEntity::pad2c() {}
void SpatialEntity::pad2d() {} void SpatialEntity::pad2e() {} void SpatialEntity::pad2f() {} void SpatialEntity::pad30() {}

struct SubObj {
    char pad[0x3A];
    unsigned char count;
};

static void test_null_subobj() {
    SpatialEntity ent;
    ent.field_10 = 0;
    ent.heading = 1.0f;

    s_vcall_count = 0;
    s_received_heading = -999.0f;

    // delta_steps = 1. divisor defaults to 8. heading = 1.0 + (TWO_PI * 1) / 8 = 1.0 + 6.2831853 / 8 = 1.785398
    func_001DF350(&ent, 1);
    assert(s_vcall_count == 1);
    assert(std::fabs(s_received_heading - (1.0f + 6.283185307179586f / 8.0f)) < 0.0001f);
}

static void test_custom_count_and_wrap() {
    SpatialEntity ent;
    SubObj sub;
    sub.count = 16;
    ent.field_10 = &sub;
    ent.heading = 6.0f;

    s_vcall_count = 0;
    s_received_heading = -999.0f;

    // delta = 2. divisor = 16. heading = 6.0 + (TWO_PI * 2) / 16 = 6.0 + 0.785398 = 6.785398
    // Since 6.785398 >= TWO_PI (6.2831853), it wraps by subtracting TWO_PI -> ~0.502213
    func_001DF350(&ent, 2);
    assert(s_vcall_count == 1);
    float expected = 6.0f + (6.283185307179586f * 2.0f) / 16.0f - 6.283185307179586f;
    assert(std::fabs(s_received_heading - expected) < 0.0001f);
}

int main() {
    test_null_subobj();
    test_custom_count_and_wrap();
    std::printf("zone_spatial_entity_adjust_heading_step_test passed\n");
    return 0;
}
