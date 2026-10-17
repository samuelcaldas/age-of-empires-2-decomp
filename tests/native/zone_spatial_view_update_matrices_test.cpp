#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct Matrix3x4 {
    float m[12];
};

struct SpatialViewObj {
    char pad0[4];
    Matrix3x4 matrix;
    Matrix3x4 matrix_34;
    float field_64;
    float field_68;
    float field_6C;
    char pad1[0x78 - 0x70];
    float field_78;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

static GlobalContext g_ctx;
void *D_004E3180 = &g_ctx;

static int g_func_1d9430_calls = 0;
static int g_func_1dae20_calls = 0;
static int g_func_1dae30_calls = 0;
static int g_func_1daf50_calls = 0;
static int g_func_1daec0_calls = 0;

extern "C" {
void func_1D9430(void *self) {
    g_func_1d9430_calls++;
}

float func_333EB0(void *obj) {
    assert(obj == g_ctx.field_404);
    return 2.0f;
}

float func_1DAE20(void *self, void *field_4, float f12, float f13, float f14) {
    g_func_1dae20_calls++;
    return 123.0f;
}

void func_1DAE30(void *self, float f12) {
    g_func_1dae30_calls++;
}

void func_1DAF50(void *self, float f12) {
    g_func_1daf50_calls++;
}

void func_1DAEC0(void *self, float f12) {
    g_func_1daec0_calls++;
}

int func_001D92F0(SpatialViewObj *self);
}

static void test_update_matrices() {
    SpatialViewObj view;
    std::memset(&view, 0, sizeof(view));

    int dummy = 10;
    g_ctx.field_404 = &dummy;

    for (int i = 0; i < 12; i++) {
        view.matrix_34.m[i] = (float)(i + 1);
    }

    int res = func_001D92F0(&view);
    assert(res == 1);
    assert(g_func_1d9430_calls == 1);
    assert(g_func_1dae20_calls == 1);
    assert(g_func_1dae30_calls == 1);
    assert(g_func_1daf50_calls == 1);
    assert(g_func_1daec0_calls == 1);
    assert(view.field_6C == 123.0f);

    for (int i = 0; i < 12; i++) {
        assert(view.matrix.m[i] == (float)(i + 1));
    }
}

int main(int argc, char **argv) {
    test_update_matrices();
    return 0;
}
