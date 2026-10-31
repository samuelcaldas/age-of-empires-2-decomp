#pragma exceptions off
#include "unit_action_targets.h"

float func_00267380(ActionExtended *self, float val) {
    switch (((unsigned char*)self->m_field4)[2]) {
    case 0:
        self->m_z = val;
        break;
    case 1:
        if (self->m_z < val) {
            self->m_z = val;
        }
        break;
    }
    return self->m_z;
}

void func_002673D0(ActionExtended *self, int target_id) {
    if (target_id == 0) {
        target_id = *(int*)((char*)self->m_field4 + 16);
    }
    if (self->m_field10 == target_id) {
        return;
    }
    self->m_field14 = self->m_field10;
    if (self->m_fieldC != 0) {
        func_001827b0(self->m_fieldC, self->m_field10);
        self->m_field10 = target_id;
    } else {
        if (self->m_field10 != 0 && func_2634a0(self->m_field10) != 0) {
            func_0026A460(self);
        }
        self->m_field10 = target_id;
    }

    if (self->m_fieldC != 0) {
        func_00182610(self->m_fieldC, self->m_field10, 60, 0, 0, self->m_field35);
        self->m_field35 = 0;
    } else {
        if (self->m_field10 != 0 && func_2634a0(self->m_field10) != 0) {
            func_0026A460(self);
        }
        self->m_field35 = 0;
    }
}

void func_002674C0(ActionExtended *self, int arg1, int arg2) {
    if (self->m_fieldC != 0) {
        func_00182610(self->m_fieldC, arg1, arg2, 0, 0, self->m_field35);
    }
}

void func_00267500(ActionExtended *self, int arg1) {
    if (self->m_fieldC != 0) {
        func_001827b0(self->m_fieldC, arg1);
    }
}

#if defined(__mips__)
asm void func_00267530(ActionExtended *self, WorldExtended *world) {
    .word 0x27BDFFA0 /* 00 */
    .word 0x7FBF0050 /* 04 */
    .word 0x7FB30040 /* 08 */
    .word 0x7FB20030 /* 0C */
    .word 0x7FB10020 /* 10 */
    .word 0x7FB00010 /* 14 */
    .word 0xE7B40000 /* 18 */
    .word 0x70809628 /* 1C */
    .word 0x8C840004 /* 20 */
    .word 0x8CA30070 /* 24 */
    .word 0x84840008 /* 28 */
    .word 0x00042080 /* 2C */
    .word 0x00641821 /* 30 */
    .word 0x8C700000 /* 34 */
    .word 0x1200006F /* 38 */
    .word 0x70A08E28 /* 3C */
    .word 0x92420036 /* 40 */
    .word 0x30420001 /* 44 */
    .word 0x10400004 /* 48 */
    .word 0x00000000 /* 4C */
    .word 0x8E440008 /* 50 */
    jal func_205f70  /* 54 */
    .word 0x72402E28 /* 58 */
    .word 0x8603003E /* 5C */
    .word 0x8E420004 /* 60 */
    .word 0xC6400030 /* 64 */
    .word 0x72402628 /* 68 */
    .word 0x44830800 /* 6C */
    .word 0x8442003E /* 70 */
    .word 0x46800860 /* 74 */
    .word 0x46000842 /* 78 */
    .word 0x44820000 /* 7C */
    .word 0x00000000 /* 80 */
    .word 0x46800020 /* 84 */
    jal func_2643c0  /* 88 */
    .word 0x46000D03 /* 8C */
    .word 0x92430039 /* 90 */
    .word 0x24020002 /* 94 */
    .word 0x1462000A /* 98 */
    .word 0x24050001 /* 9C */
    .word 0x8E590000 /* A0 */
    .word 0x8E450008 /* A4 */
    .word 0x2407FFFF /* A8 */
    .word 0x72402628 /* AC */
    .word 0x70003628 /* B0 */
    .word 0x8F3900F8 /* B4 */
    .word 0x0320F809 /* B8 */
    .word 0x70004628 /* BC */
    .word 0x24050001 /* C0 */
    jal func_26AD20  /* C4 */
    .word 0x72402628 /* C8 */
    .word 0x24050004 /* CC */
    .word 0x305300FF /* D0 */
    jal func_26AD20  /* D4 */
    .word 0x72402628 /* D8 */
    .word 0x8E440008 /* DC */
    .word 0x86480026 /* E0 */
    .word 0x304700FF /* E4 */
    .word 0x72603628 /* E8 */
    .word 0x8C991B30 /* EC */
    .word 0x8F390114 /* F0 */
    .word 0x0320F809 /* F4 */
    .word 0x72402E28 /* F8 */
    .word 0x24050001 /* FC */
    jal func_26AD20  /* 100 */
    .word 0x72402628 /* 104 */
    .word 0x24050004 /* 108 */
    .word 0x305300FF /* 10C */
    jal func_26AD20  /* 110 */
    .word 0x72402628 /* 114 */
    .word 0x8E391B30 /* 118 */
    .word 0x72603628 /* 11C */
    .word 0x304700FF /* 120 */
    .word 0x72202628 /* 124 */
    .word 0x8F390110 /* 128 */
    .word 0x0320F809 /* 12C */
    .word 0x72402E28 /* 130 */
    .word 0xA6420026 /* 134 */
    .word 0x8E430004 /* 138 */
    .word 0x8E440010 /* 13C */
    .word 0x8C620010 /* 140 */
    .word 0x14820003 /* 144 */
    .word 0x00000000 /* 148 */
    .word 0x10000008 /* 14C */
    .word 0x8E050010 /* 150 */
    .word 0x8C620018 /* 154 */
    .word 0x14820003 /* 158 */
    .word 0x00000000 /* 15C */
    .word 0x10000003 /* 160 */
    .word 0x8E050018 /* 164 */
    .word 0x8E050010 /* 168 */
    .word 0x00000000 /* 16C */
    .word 0x10A00005 /* 170 */
    .word 0x00000000 /* 174 */
    .word 0x8E590000 /* 178 */
    .word 0x8F39004C /* 17C */
    .word 0x0320F809 /* 180 */
    .word 0x72402628 /* 184 */
    .word 0xAE510008 /* 188 */
    .word 0xAE500004 /* 18C */
    .word 0xE6540030 /* 190 */
    .word 0x92430039 /* 194 */
    .word 0x24020002 /* 198 */
    .word 0x1462000A /* 19C */
    .word 0x72402628 /* 1A0 */
    .word 0x8E590000 /* 1A4 */
    .word 0x8E450008 /* 1A8 */
    .word 0x2407FFFF /* 1AC */
    .word 0x72402628 /* 1B0 */
    .word 0x70003628 /* 1B4 */
    .word 0x8F3900F4 /* 1B8 */
    .word 0x0320F809 /* 1BC */
    .word 0x70004628 /* 1C0 */
    .word 0x72402628 /* 1C4 */
    jal func_264290  /* 1C8 */
    .word 0x00000000 /* 1CC */
    .word 0x8E590000 /* 1D0 */
    .word 0x86450024 /* 1D4 */
    .word 0x8E280BA0 /* 1D8 */
    .word 0x2407020B /* 1DC */
    .word 0x72402628 /* 1E0 */
    .word 0x8F390168 /* 1E4 */
    .word 0x70004E28 /* 1E8 */
    .word 0x70A03628 /* 1EC */
    .word 0x0320F809 /* 1F0 */
    .word 0x70005628 /* 1F4 */
    .word 0x7BBF0050 /* 1F8 */
    .word 0x7BB30040 /* 1FC */
    .word 0x7BB20030 /* 200 */
    .word 0x7BB10020 /* 204 */
    .word 0x7BB00010 /* 208 */
    .word 0xC7B40000 /* 20C */
    .word 0x03E00008 /* 210 */
    .word 0x27BD0060 /* 214 */
}
#else
void func_00267530(ActionExtended *self, WorldExtended *world) {
    short id = *(short*)((char*)self->m_field4 + 8);
    void *entity = world->m_entities[id];
    if (entity == 0) {
        return;
    }

    if ((self->m_field36 & 1) != 0) {
        func_205F70(self->m_world, self);
    }

    float f20 = ((float)*(short*)((char*)entity + 62) * self->m_field30) / (float)*(short*)((char*)self->m_field4 + 62);
    func_2643C0(self);

    if (self->m_field39 == 2) {
        self->Method62(self->m_world, 0, -1, 0);
    }

    int a2 = (unsigned char)func_26AD20(self, 1);
    int a3 = (unsigned char)func_26AD20(self, 4);
    self->m_world->m_field1B30->Method114(self->m_world, self, a2, a3, self->m_field26);

    a2 = (unsigned char)func_26AD20(self, 1);
    a3 = (unsigned char)func_26AD20(self, 4);
    self->m_field26 = world->m_field1B30->Method110(world, self, a2, a3);

    int target = 0;
    if (self->m_field10 == *(int*)((char*)self->m_field4 + 16)) {
        target = *(int*)((char*)entity + 16);
    } else if (self->m_field10 == *(int*)((char*)self->m_field4 + 24)) {
        target = *(int*)((char*)entity + 24);
    } else {
        target = *(int*)((char*)entity + 16);
    }

    if (target != 0) {
        self->Method19(target);
    }

    self->m_world = world;
    self->m_field4 = entity;
    self->m_field30 = f20;

    if (self->m_field39 == 2) {
        self->Method61(self->m_world, 0, -1, 0);
    }

    func_264290(self);

    self->Method90(self->m_field24, self->m_field24, 523, world->m_fieldBA0, 0, 0);
}
#endif
