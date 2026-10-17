#pragma exceptions off
#include "unit_action_build_78660.h"

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET   0x8
#define UNIT_SPRITE_OFFSET  0x20
#else
#define UNIT_PROTO_OFFSET   0x4
#define UNIT_SPRITE_OFFSET  0x10
#endif

static unsigned char determine_construction_facet(float progress) {
    if (progress < 26.0f) return 2;
    if (progress < 51.0f) return 1;
    return 0;
}

static void apply_facet_update(void *self, unsigned char facet) {
    void *sprite = *(void **)((char *)self + UNIT_SPRITE_OFFSET);
    unsigned char max_facet = *(unsigned char *)((char *)sprite + 0x3A);
    if (facet >= max_facet) return;
    unsigned char current_facet = *(unsigned char *)((char *)self + 0x35);
    if (facet == current_facet) return;
    *(unsigned char *)((char *)self + 0x35) = facet;
}

void func_00278660(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    if (*(short *)((char *)proto + 0xE) != 0x28) return;
    float progress = *(float *)((char *)self + 0x40);
    unsigned char facet = determine_construction_facet(progress);
    apply_facet_update(self, facet);
}
