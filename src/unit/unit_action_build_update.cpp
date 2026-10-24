#pragma exceptions off
#include "unit_action_build_update.h"

static void update_footprint(ActionRebind *self, void *zone) {
    void *v1 = self->m_field4;
    float x = self->m_x;
    float y = self->m_y;
    float ext_x = *(float*)((char*)v1 + 0x20);
    float ext_y = *(float*)((char*)v1 + 0x24);

    int min_x = func_123350(x - ext_x - 1.0f);
    int min_y = func_123350(y - ext_y - 1.0f);
    int max_x = func_123350(x + ext_x);
    int max_y = func_123350(y + ext_y);

    func_1C9E00(zone, min_x, min_y, max_x, max_y, 0);
}

static void update_children(ActionRebind *self) {
    if (func_00268500(self) == 0) {
        return;
    }
    int count = func_00268530(self);
    for (int i = count - 1; i >= 0; --i) {
        ActionRebind *child = func_00268590(self, i);
        if (child != 0) {
            func_26F590(child);
        }
    }
}

static void cleanup_and_notify(ActionRebind *self) {
    void *item1 = *(void**)((char*)self + 0x128);
    if (item1 != 0) {
        Free__8BaseListFv(item1);
    }
    void *item2 = *(void**)((char*)self + 0x12C);
    if (item2 != 0) {
        Free__8BaseListFv(item2);
    }
    func_00270530(self);
    func_280680(self, 1);
    func_280680(self, 2);
    func_270660(self);
}

void func_0026D010(ActionRebind *self) {
    if (self == 0 || self->m_field4 == 0) {
        return;
    }
    void *f4 = self->m_field4;
    short master_type = *(short*)((char*)f4 + 0xE);
    short unit_class = *(short*)((char*)f4 + 0x8);

    if (master_type != 0x1B && unit_class == 0x46) {
        if (self->m_field39 == 0) {
            short max_work = *(short*)((char*)f4 + 0x13E);
            if (max_work > 0 && self->m_fieldC != 0 && self->m_field10 != 0) {
                float work = *(float*)((char*)self + 0x170);
                float target_state = (float)*(unsigned char*)((char*)self->m_field10 + 0x39);
                int progress = func_1233E0((work * target_state) / (float)max_work);
                if (progress < (int)*(unsigned char*)((char*)self->m_field10 + 0x39)) {
                    void *zone = self->m_fieldC;
                    update_footprint(self, zone);
                }
                if (work >= (float)max_work) {
                    typedef void (*Method28Fn)(void *action, int state);
                    void **vtable = *(void***)self;
                    Method28Fn m28 = (Method28Fn)vtable[26];
                    m28(self, 2);
                    func_2734F0(self);
                }
            }
        }
    }

    update_children(self);
    cleanup_and_notify(self);
}
