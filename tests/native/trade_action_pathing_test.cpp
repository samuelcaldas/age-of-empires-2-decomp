#include <cassert>
#include <cstdlib>
#include <iostream>
#include "trade_action_pathing.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

#define V_IMP_10(base) \
    virtual int v##base##0() { return 0; } virtual int v##base##1() { return 0; } virtual int v##base##2() { return 0; } virtual int v##base##3() { return 0; } virtual int v##base##4() { return 0; } \
    virtual int v##base##5() { return 0; } virtual int v##base##6() { return 0; } virtual int v##base##7() { return 0; } virtual int v##base##8() { return 0; } virtual int v##base##9() { return 0; }

class MockTargetObj : public TargetObj {
public:
    int m_val_372;
    int m_val_376;
    int m_val_380;
    int m_val_416;
    int m_val_420;
    int m_val_424;

    MockTargetObj() : m_val_372(0), m_val_376(0), m_val_380(0), m_val_416(0), m_val_420(0), m_val_424(0) {
        m_node = nullptr;
        m_game = nullptr;
        m_field24 = 0;
        x = 0; y = 0; z = 0;
    }

    V_IMP_10(0)
    V_IMP_10(1)
    V_IMP_10(2)
    V_IMP_10(3)
    V_IMP_10(4)
    V_IMP_10(5)
    V_IMP_10(6)
    V_IMP_10(7)
    V_IMP_10(8)
    virtual int v90() { return 0; }
    virtual int Method372(int a1) { return m_val_372; }
    virtual int Method376(int a1) { return m_val_376; }
    virtual int Method380(float x, float y, float z) { return m_val_380; }
    virtual int v94() { return 0; }
    virtual int Method388(int a1) { return 0; }
    virtual int Method392(int a1) { return 0; }
    virtual int Method396(int a1) { return 0; }
    virtual int Method400(int a1) { return 0; }
    virtual int Method404(int a1) { return 0; }
    virtual int Method408(int a1) { return 0; }
    virtual int Method412(int a1) { return 0; }
    virtual int Method416(int a1) { return m_val_416; }
    virtual int Method420(float x, float y, float z) { return m_val_420; }
    virtual int Method424(float x, float y, float z) { return m_val_424; }
};

#undef V_IMP_10

static int s_last_code = 0;
static int s_last_bd20_id = 0;
static float s_last_bd20_x = 0;
static float s_last_bd20_y = 0;
static float s_last_bd20_z = 0;

static int s_last_bd90_id = 0;
static int s_last_bd90_target = 0;
static float s_last_bd90_x = 0;
static float s_last_bd90_y = 0;
static float s_last_bd90_z = 0;

static void *s_mock_timer_obj = nullptr;

extern "C" {
void func_001471B0(void *self, int code) {
    s_last_code = code;
}

void func_14BD20(void *self, int id, float x, float y, float z) {
    s_last_bd20_id = id;
    s_last_bd20_x = x;
    s_last_bd20_y = y;
    s_last_bd20_z = z;
}

void func_14bd90(void *self, int id, int target_id, float x, float y, float z) {
    s_last_bd90_id = id;
    s_last_bd90_target = target_id;
    s_last_bd90_x = x;
    s_last_bd90_y = y;
    s_last_bd90_z = z;
}

void *func_332e60(void *timer, int id) {
    return s_mock_timer_obj;
}
}

int main() {
    MockTargetObj mock_target;
    char mock_game[3000];
    mock_target.m_game = mock_game;

    TradeAction action = {};
    action.m_target = &mock_target;
    action.m_field48 = -1;

    // Test func_0014A640:
    // When a2 == 0 and field48 != -1, return 0
    action.m_field48 = 100;
    assert(func_0014A640(&action, 5, 0) == 0);

    // When Method416 returns 1
    action.m_field48 = -1;
    mock_target.m_val_416 = 1;
    assert(func_0014A640(&action, 42, 0) == 1);
    assert(s_last_code == 617);
    assert(s_last_bd20_id == 42);
    assert(s_last_bd20_x == -1.0f);

    // When Method416 returns 0
    mock_target.m_val_416 = 0;
    assert(func_0014A640(&action, 42, 0) == 0);

    // Test func_0014A6E0:
    mock_target.m_val_424 = 1;
    assert(func_0014A6E0(&action, 1, 10.0f, 20.0f, 30.0f) == 1);
    assert(s_last_code == 614);
    assert(s_last_bd20_id == -1);
    assert(s_last_bd20_x == 10.0f);
    assert(s_last_bd20_y == 20.0f);
    assert(s_last_bd20_z == 30.0f);

    // Test func_0014A880 (without mock timer obj -> null branch)
    mock_target.m_val_372 = 1;
    s_mock_timer_obj = nullptr;
    assert(func_0014A880(&action, 77, 1) == 1);
    assert(s_last_code == 610);
    assert(s_last_bd20_id == 77);
    assert(s_last_bd20_x == 0.0f);
    assert(s_last_bd20_y == 0.0f);
    assert(s_last_bd20_z == 0.0f);

    // Test func_0014A880 (with mock timer obj -> non-null branch)
    MockTargetObj timer_target;
    timer_target.x = 12.0f;
    timer_target.y = 34.0f;
    timer_target.z = 56.0f;
    s_mock_timer_obj = &timer_target;
    assert(func_0014A880(&action, 88, 1) == 1);
    assert(s_last_code == 610);
    assert(s_last_bd20_id == 88);
    assert(s_last_bd20_x == 12.0f);
    assert(s_last_bd20_y == 34.0f);
    assert(s_last_bd20_z == 56.0f);

    // Test func_0014A970 (without mock timer obj -> null branch)
    mock_target.m_val_376 = 1;
    s_mock_timer_obj = nullptr;
    assert(func_0014A970(&action, 99, 1) == 1);
    assert(s_last_code == 610);
    assert(s_last_bd20_id == 99);
    assert(s_last_bd20_x == 0.0f);
    assert(s_last_bd20_y == 0.0f);
    assert(s_last_bd20_z == 0.0f);

    // Test func_0014AA60:
    mock_target.m_val_380 = 1;
    assert(func_0014AA60(&action, 1, 1.5f, 2.5f, 3.5f) == 1);
    assert(s_last_code == 610);
    assert(s_last_bd20_id == -1);
    assert(s_last_bd20_x == 1.5f);
    assert(s_last_bd20_y == 2.5f);
    assert(s_last_bd20_z == 3.5f);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
