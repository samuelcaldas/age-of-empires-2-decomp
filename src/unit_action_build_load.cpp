#pragma exceptions off
#include "unit_action_build_load.h"

static void process_active_resources(ActionRebind *self) {
    if (self->m_field4 == 0) {
        return;
    }
    void *f4 = self->m_field4;
    for (int i = 0; i < 3; ++i) {
        unsigned char attr = *(unsigned char*)((char*)f4 + 0x70 + i);
        if (attr < 4) {
            short val_5a = *(short*)((char*)f4 + 0x5A + i * 2);
            if (val_5a >= 0 && self->m_world != 0) {
                float val_60 = *(float*)((char*)f4 + 0x60 + i * 4);
                typedef void (*NotifyFn)(void *world, short id, int a2, float delta);
                void *sub = *(void**)((char*)self->m_world + 0x1B30);
                NotifyFn notify = *(NotifyFn*)((char*)sub + 0x7C);
                if (notify != 0) {
                    notify(self->m_world, val_5a, 0, -val_60);
                }
            }
        }
    }
}

static void update_child_lists(ActionRebind *self) {
    int count = func_00268530(self);
    for (int i = count - 1; i >= 0; --i) {
        ActionRebind *child = func_00268590(self, i);
        if (child != 0) {
            func_26F590(child);
        }
    }

    count = func_00268530(self);
    for (int i = count - 1; i >= 0; --i) {
        ActionRebind *child = func_00268590(self, i);
        if (child != 0) {
            typedef void (*ChildMethodFn)(void *action);
            void **vtable = *(void***)child;
            ChildMethodFn fn = (ChildMethodFn)vtable[12];
            if (fn != 0) fn(child);
            fn = (ChildMethodFn)vtable[13];
            if (fn != 0) fn(child);
        }
    }
}

void func_0026DE90(ActionRebind *self, void *stream) {
    if (self == 0 || stream == 0) {
        return;
    }

    if (self->m_field39 == 2) {
        process_active_resources(self);
    }

    if (*(short*)((char*)self + 0x3C) == 4 && self->m_world != 0) {
        typedef void (*Method62Fn)(void *action, void *world, int a2, int a3, int a4);
        void **vtable = *(void***)self;
        Method62Fn m62 = (Method62Fn)vtable[60];
        if (m62 != 0) {
            m62(self, self->m_world, 1, -1, 0);
        }
    }

    void *item_cc = *(void**)((char*)self + 0xCC);
    if (item_cc != 0) Free__8BaseListFv(item_cc);
    void *item_128 = *(void**)((char*)self + 0x128);
    if (item_128 != 0) Free__8BaseListFv(item_128);
    void *item_12c = *(void**)((char*)self + 0x12C);
    if (item_12c != 0) Free__8BaseListFv(item_12c);

    func_00270530(self);
    func_274970(self, stream);

    if (self->m_field39 == 0) {
        typedef void (*Method61Fn)(void *action, void *world, int a2, int a3, int a4);
        void **vtable = *(void***)self;
        Method61Fn m61 = (Method61Fn)vtable[59];
        if (m61 != 0) {
            m61(self, self->m_world, 1, -1, 0);
        }
    }

    func_002D34A0(self);
    update_child_lists(self);

    if (*(unsigned char*)((char*)self + 0x38) == 1) {
        func_2E00D0(self->m_world, self);
    }
}
