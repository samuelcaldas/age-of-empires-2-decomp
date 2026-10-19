#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_coord_clamp.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static ViewBounds s_bounds;

static void setup_instance(CombatSubsystemControllerInstance &inst, int max_x, int max_y) {
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_bounds, 0, sizeof(s_bounds));
    s_bounds.max_x = max_x;
    s_bounds.max_y = max_y;
    inst.m_bounds = &s_bounds;
}

static void test_clamp_negative_to_zero() {
    CombatSubsystemControllerInstance inst;
    setup_instance(inst, 100, 200);

    float coords[2] = {-15.5f, -8.25f};
    func_0032E580(&inst, coords);

    TEST_ASSERT(coords[0] == 0.0f, "negative x must clamp to zero");
    TEST_ASSERT(coords[1] == 0.0f, "negative y must clamp to zero");
}

static void test_clamp_upper_to_max_minus_one() {
    CombatSubsystemControllerInstance inst;
    setup_instance(inst, 100, 200);

    float coords[2] = {150.0f, 250.0f};
    func_0032E580(&inst, coords);

    TEST_ASSERT(coords[0] == 99.0f, "upper x must clamp to max_x - 1.0f");
    TEST_ASSERT(coords[1] == 199.0f, "upper y must clamp to max_y - 1.0f");
}

static void test_in_range_preservation() {
    CombatSubsystemControllerInstance inst;
    setup_instance(inst, 100, 200);

    float coords[2] = {45.25f, 120.75f};
    func_0032E580(&inst, coords);

    TEST_ASSERT(coords[0] == 45.25f, "in-range x must be preserved");
    TEST_ASSERT(coords[1] == 120.75f, "in-range y must be preserved");
}

static void test_boundary_edges() {
    CombatSubsystemControllerInstance inst;
    setup_instance(inst, 100, 200);

    float coords[2] = {0.0f, 199.0f};
    func_0032E580(&inst, coords);

    TEST_ASSERT(coords[0] == 0.0f, "zero x boundary must be preserved");
    TEST_ASSERT(coords[1] == 199.0f, "max_y minus one boundary must be preserved");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "clamp_neg") == 0) { test_clamp_negative_to_zero(); return 0; }
        if (std::strcmp(argv[1], "clamp_upper") == 0) { test_clamp_upper_to_max_minus_one(); return 0; }
        if (std::strcmp(argv[1], "in_range") == 0) { test_in_range_preservation(); return 0; }
        if (std::strcmp(argv[1], "boundary") == 0) { test_boundary_edges(); return 0; }
    }
    test_clamp_negative_to_zero();
    test_clamp_upper_to_max_minus_one();
    test_in_range_preservation();
    test_boundary_edges();
    return 0;
}
