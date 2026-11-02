#include <cassert>
#include <cstdio>
#include <cstring>

struct MockTarget {
    void *vtable;
    int pad04;
    void *m_game;
    int pad10[5];
    short m_field24;
    short pad26;
    int pad28[15];
    int m_field64;
};

struct MockAction {
    void *vtable;
    char route[0x28];
    unsigned char m_field2C;
    char m_field2D;
    char m_field2E;
    char m_field2F;
    char pad30[8];
    MockTarget *m_target;
};

static int s_entity_query_id = 0;
static short s_forward_field24 = 0;
static short s_forward_param0 = 0;
static int s_forward_calls = 0;

static int s_dummy_entity = 0x1234;

extern "C" {
void* func_333B30(void *timer, int field64) {
    s_entity_query_id = field64;
    return &s_dummy_entity;
}

void func_001BCE20(void *entity, short field24, int a2, short a3, int t0, int t1) {
    assert(entity == &s_dummy_entity);
    assert(a2 == 0);
    assert(t0 == 0);
    assert(t1 == 0);
    s_forward_field24 = field24;
    s_forward_param0 = a3;
    s_forward_calls++;
}

void func_00147CD0(MockAction *self, short *param1);
}

// Minimal implementation of func_00147CD0 for native harness
void func_00147CD0(MockAction *self, short *param1) {
    if (self->m_target->m_field64 == -1) {
        return;
    }

    void *timer = *(void **)((char *)self->m_target->m_game + 0xB98);
    void *entity = func_333B30(timer, self->m_target->m_field64);
    if (!entity) {
        return;
    }

    switch (param1[2]) {
    case 0x20F:
    case 0x1F4:
        func_001BCE20(entity, self->m_target->m_field24, 0, param1[0], 0, 0);
        break;
    }
}

int main() {
    char game_mem[0xC00];
    *(void **)(game_mem + 0xB98) = (void *)0xCAFE;

    MockTarget target;
    memset(&target, 0, sizeof(target));
    target.m_game = game_mem;
    target.m_field24 = 42;
    target.m_field64 = 100;

    MockAction action;
    memset(&action, 0, sizeof(action));
    action.m_target = &target;

    // Test case 1: target m_field64 == -1 ignores callback
    target.m_field64 = -1;
    short params[4] = { 10, 0, 0x1F4, 0 };
    func_00147CD0(&action, params);
    assert(s_forward_calls == 0);

    // Test case 2: action 0x1F4 triggers func_001BCE20
    target.m_field64 = 777;
    func_00147CD0(&action, params);
    assert(s_forward_calls == 1);
    assert(s_entity_query_id == 777);
    assert(s_forward_field24 == 42);
    assert(s_forward_param0 == 10);

    // Test case 3: action 0x20F triggers func_001BCE20
    params[2] = 0x20F;
    params[0] = 99;
    func_00147CD0(&action, params);
    assert(s_forward_calls == 2);
    assert(s_forward_param0 == 99);

    // Test case 4: unsupported action does not trigger
    params[2] = 0x100;
    func_00147CD0(&action, params);
    assert(s_forward_calls == 2);

    printf("trade_action_callbacks_test passed\n");
    return 0;
}
