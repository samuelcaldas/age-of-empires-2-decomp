#pragma exceptions off
#include "unit_action_build_3810.h"

extern "C" {
    void func_00267750(void *self, int param_id, float val);
    void func_002678A0(void *self, int param_id, float val);
    void func_002679A0(void *self, int param_id, float val);

    int func_00268530(void *self);
    void func_001827B0(void *arg0, void *arg1);
    void func_00182610(void *arg0, void *arg1, int a2, int a3, int t0, int t1);
    void func_0014C7F0(void *obj, int zero);
    void func_00196A60(void *self, void *new_proto);
}

void func_00273810(void *self, int param_id, float val) {
    if ((param_id & 0xFF) == 0x66) {
        *(float *)((char *)self + 0x120) = val;
    }
    func_00267750(self, param_id, val);
}

void func_00273840(void *self, int param_id, float val) {
    if ((param_id & 0xFF) == 0x66) {
        *(float *)((char *)self + 0x120) += val;
    }
    func_002678A0(self, param_id, val);
}

void func_00273870(void *self, int param_id, float val) {
    if ((param_id & 0xFF) == 0x66) {
        *(float *)((char *)self + 0x120) *= val;
    }
    func_002679A0(self, param_id, val);
}

static void update_active_proto_attachment(void *self, void *old_proto, void *new_proto) {
    if (*(void **)((char *)old_proto + 0x164) == 0) {
        return;
    }

    if (func_00268530(self) <= 0) {
        return;
    }

#if defined(__LP64__) || defined(_LP64)
    void *c_ptr = *(void **)((char *)self + 0x18);
    func_001827B0(c_ptr, *(void **)((char *)old_proto + 0x164));

    *(void **)((char *)self + 0x8) = new_proto;
    void *cur_proto = *(void **)((char *)self + 0x8);
    func_00182610(c_ptr, *(void **)((char *)cur_proto + 0x164), 0x5A, 0, 0, 0);
    *(void **)((char *)self + 0x8) = old_proto;
#else
    void *c_ptr = *(void **)((char *)self + 0xC);
    func_001827B0(c_ptr, *(void **)((char *)old_proto + 0x164));

    *(void **)((char *)self + 0x4) = new_proto;
    void *cur_proto = *(void **)((char *)self + 0x4);
    func_00182610(c_ptr, *(void **)((char *)cur_proto + 0x164), 0x5A, 0, 0, 0);
    *(void **)((char *)self + 0x4) = old_proto;
#endif
}

static void check_building_cleanup(void *self, void *old_proto, void *new_proto) {
    if (*(short *)((char *)old_proto + 0xE) != 0x2F) {
        return;
    }
    if (*(short *)((char *)new_proto + 0xE) == 0x2F) {
        return;
    }

    void *c8 = *(void **)((char *)self + 0xC8);
    if (c8 != 0) {
        func_0014C7F0(*(void **)c8, 0);
    }
}

void func_002738A0(void *self, void *new_proto) {
#if defined(__LP64__) || defined(_LP64)
    void *old_proto = *(void **)((char *)self + 0x8);
#else
    void *old_proto = *(void **)((char *)self + 0x4);
#endif

    update_active_proto_attachment(self, old_proto, new_proto);
    check_building_cleanup(self, old_proto, new_proto);
    func_00196A60(self, new_proto);
}
