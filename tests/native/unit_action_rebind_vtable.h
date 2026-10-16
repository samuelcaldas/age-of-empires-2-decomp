#ifndef UNIT_ACTION_REBIND_VTABLE_H
#define UNIT_ACTION_REBIND_VTABLE_H

#include <cassert>

static void mock_method19(void *self, int target);

static void poison_trap_slot18(void *self, int target) {
    (void)self; (void)target;
    assert(!"Wrong vtable slot 18 executed instead of slot 17");
}

static void poison_trap_slot19(void *self, int target) {
    (void)self; (void)target;
    assert(!"Wrong vtable slot 19 executed instead of slot 17");
}

static void poison_trap_generic(void *self, ...) {
    (void)self;
    assert(!"Unintended vtable slot executed in ActionMock");
}

static void* dummy_vtable[120] = {nullptr};

static void init_vtable() {
    for (int i = 0; i < 120; i++) {
        dummy_vtable[i] = (void*)poison_trap_generic;
    }
    dummy_vtable[17] = (void*)mock_method19;
    dummy_vtable[18] = (void*)poison_trap_slot18;
    dummy_vtable[19] = (void*)poison_trap_slot19;
}

#endif
