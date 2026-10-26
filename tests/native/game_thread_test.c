#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "game_thread.h"
#include "kt_libcdvd_server.h"

/* Trace / Mock structures */
static int s_cdvd_request_called = 0;
static const char *s_cdvd_last_path = NULL;
static void *s_cdvd_last_dest = NULL;
static void *s_cdvd_last_status = NULL;

static int s_overlay_entry1_called = 0;
static int s_overlay_entry2_called = 0;

static int s_trace_index = 0;
static const char *s_call_trace[32];

static void record_call(const char *name) {
    if (s_trace_index < 32) {
        s_call_trace[s_trace_index++] = name;
    }
}

/* Mock capture for func_0012C128 */
static void *s_c128_a0 = NULL;
static void *s_c128_a1 = NULL;
static void *s_c128_a2 = NULL;
static void *s_c128_a3 = NULL;
static void *s_c128_t0 = NULL;
static void *s_c128_t1 = NULL;
static void *s_c128_t2 = NULL;
static void *s_c128_t3 = NULL;
static int s_c128_call_count = 0;

void *func_00129F58(void *a0, void *a1, void *a2, void *a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    record_call("func_00129F58");
    return (void *)0x1111;
}

void *func_00129FD0(void *a0, void *a1, void *a2, void *a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    record_call("func_00129FD0");
    return (void *)0x2222;
}

void *func_0012C128(void *a0, void *a1, void *a2, void *a3, void *t0, void *t1, void *t2, void *t3) {
    record_call("func_0012C128");
    s_c128_call_count++;
    s_c128_a0 = a0;
    s_c128_a1 = a1;
    s_c128_a2 = a2;
    s_c128_a3 = a3;
    s_c128_t0 = t0;
    s_c128_t1 = t1;
    s_c128_t2 = t2;
    s_c128_t3 = t3;
    return (void *)0xABCD;
}

/* Cache invalidate mock */
static int s_cache_inv_called = 0;
static u32 s_cache_inv_size = 0;
static void *s_cache_inv_dest = NULL;

int func_100270(u32 size, void *dest) {
    record_call("func_100270");
    s_cache_inv_called++;
    s_cache_inv_size = size;
    s_cache_inv_dest = dest;
    return 1;
}

static int s_c1d0_poll_count = 0;
static char s_captured_request_path[128] = {0};

/* Mock implementation of func_0012C1D0 when testing func_002240B0 */
static int s_use_mock_c1d0 = 0;
static void *mock_func_0012C1D0(void *a0, void *a1, void *a2) {
    s_c1d0_poll_count++;
    /* Save request header and path */
    memcpy(s_captured_request_path, a0, 64);
    int *status = (int *)a2;
    if (s_c1d0_poll_count == 1) {
        status[0] = 0; /* Still loading / pending */
        return (void *)1;
    }
    status[0] = 1; /* Complete */
    status[4] = 0x54320; /* Loaded size at offset 0x10 (sp+0x90) */
    return (void *)1;
}

void *func_0012C1D0(void *a0, void *a1, void *a2, void *a3) {
    if (s_use_mock_c1d0) {
        return mock_func_0012C1D0(a0, a1, a2);
    }
    void *token1 = func_00129F58(NULL, NULL, NULL, NULL);
    void *token2 = func_00129FD0(NULL, NULL, NULL, NULL);
    return func_0012C128(a0, a1, a2, NULL, NULL, token1, token2, (void *)1);
}

/* State machine mock counters and flags */
static int s_func_220e90_calls = 0;
static int s_func_220ff0_calls = 0;
static int s_func_2249c0_calls = 0;
static int s_func_224b30_ready = 1;
static int s_func_223ff0_calls = 0;
static int s_func_25d060_calls = 0;
static int s_func_21bdf0_calls = 0;
static int s_func_21bfb0_calls = 0;
static int s_func_33b680_calls = 0;

void func_220E90(void) {
    record_call("func_220E90");
    s_func_220e90_calls++;
}

void func_220FF0(void) {
    record_call("func_220FF0");
    s_func_220ff0_calls++;
}

void func_2249C0(int a0, void *a1, int a2) {
    (void)a0; (void)a1; (void)a2;
    record_call("func_2249C0");
    s_func_2249c0_calls++;
}

int func_224B30(void) {
    record_call("func_224B30");
    return s_func_224b30_ready;
}

void func_223FF0(void) {
    record_call("func_223FF0");
    s_func_223ff0_calls++;
}

void func_25D060(int a0) {
    (void)a0;
    record_call("func_25D060");
    s_func_25d060_calls++;
}

void func_21BDF0(void) {
    record_call("func_21BDF0");
    s_func_21bdf0_calls++;
}

void func_21BFB0(void) {
    record_call("func_21BFB0");
    s_func_21bfb0_calls++;
}

void func_33B680(void) {
    record_call("func_33B680");
    s_func_33b680_calls++;
}

void func_1C1FD0(int a0, int a1, void *a2, int a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
}

void func_223DE0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)t0; (void)t1; (void)t2; (void)t3;
}

void func_222370(void *a0, void *a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)t0; (void)t1; (void)t2; (void)t3;
}

void func_223670(void *a0, int a1) {
    (void)a0; (void)a1;
}

/* Loop mocks */
void func_220940(void) { record_call("func_220940"); }
void func_220BA0(void) { record_call("func_220BA0"); }
void func_220C60(void) { record_call("func_220C60"); }
void func_221110(void) { record_call("func_221110"); }
void func_221410(void) { record_call("func_221410"); }
void func_103358(int a0) { (void)a0; record_call("func_103358"); }
void func_2208F0(void) { record_call("func_2208F0"); }
void func_2263A0(int a0) { (void)a0; record_call("func_2263A0"); }

void func_2204D0(s32 sema_id) { (void)sema_id; record_call("func_2204D0"); }
int func_104D40(s32 sema_id) { (void)sema_id; record_call("func_104D40"); return 0; }
int func_104D60(s32 sema_id) { (void)sema_id; record_call("func_104D60"); return 0; }
void func_226260(void) { record_call("func_226260"); }
int func_2204E0(s32 sema_id) { (void)sema_id; record_call("func_2204E0"); return 1; }
void func_2207B0(void) { record_call("func_2207B0"); }
void func_221790(void) { record_call("func_221790"); }
void func_3379F0(int a0) { (void)a0; record_call("func_3379F0"); }
void func_36F800(int a0) { (void)a0; record_call("func_36F800"); }
void func_221C00(void) { record_call("func_221C00"); }
void func_224A10(void) { record_call("func_224A10"); }

void func_222B00(void) {}
void func_2230D0(void *a0) { (void)a0; }

/* Stubs for overlay entry points */
void func_1DE9900(void) {
    record_call("func_1DE9900");
    s_overlay_entry1_called++;
}

void func_1DE9B00(void) {
    record_call("func_1DE9B00");
    s_overlay_entry2_called++;
}

/* Red Test: Check presence and basic symbols */
static void test_initial_signatures_and_constants(void) {
    assert(BOOT_PHASE_INIT_START == 0x00);
    assert(BOOT_PHASE_AUDIO_POLL == 0x06);
    assert(BOOT_PHASE_PREPARE_OVERLAY == 0x08);
    assert(BOOT_PHASE_LOAD_OVERLAY == 0x0C);
    assert(BOOT_PHASE_OVERLAY_ENTRY1 == 0x10);
    assert(BOOT_PHASE_OVERLAY_ENTRY2 == 0x11);
    assert(OVERLAY_LOAD_ADDR == 0x01D98000);
    assert(OVERLAY_ENTRY_POINT_1 == 0x01DE9900);
    assert(OVERLAY_ENTRY_POINT_2 == 0x01DE9B00);
    printf("PASS: test_initial_signatures_and_constants\n");
}

static void test_func_0012C1D0_packaging(void) {
    s_c128_call_count = 0;
    s_c128_a0 = NULL;
    s_c128_a1 = NULL;
    s_c128_a2 = NULL;
    s_c128_a3 = NULL;
    s_c128_t0 = NULL;
    s_c128_t1 = NULL;
    s_c128_t2 = NULL;
    s_c128_t3 = NULL;

    const char *test_path = "EN\\lobby_cd.bin";
    void *test_dest = (void *)0x01D98000;
    int test_status_buf[8] = {0};

    void *result = func_0012C1D0((void *)test_path, test_dest, (void *)test_status_buf, NULL);

    assert(result == (void *)0xABCD);
    assert(s_c128_call_count == 1);
    assert(s_c128_a0 == (void *)test_path);
    assert(s_c128_a1 == test_dest);
    assert(s_c128_a2 == (void *)test_status_buf);
    assert(s_c128_a3 == NULL);
    assert(s_c128_t0 == NULL);
    assert(s_c128_t1 == (void *)0x1111);
    assert(s_c128_t2 == (void *)0x2222);
    assert(s_c128_t3 == (void *)1);
    printf("PASS: test_func_0012C1D0_packaging\n");
}

static void test_func_002240B0_overlay_loader(void) {
    s_c1d0_poll_count = 0;
    s_cache_inv_called = 0;
    s_cache_inv_size = 0;
    s_cache_inv_dest = NULL;
    memset(s_captured_request_path, 0, sizeof(s_captured_request_path));

    s_use_mock_c1d0 = 1;
    int res = func_002240B0("lobby_cd.bin", (void *)0x01D98000);
    s_use_mock_c1d0 = 0;

    assert(res == 1);
    assert(s_c1d0_poll_count == 2);
    /* Verify prefix byte at [0] is '0' (0x30) */
    assert(s_captured_request_path[0] == '0');
    assert(s_captured_request_path[1] == '\0');
    /* Verify path at offset 4 is "EN\\lobby_cd.bin" */
    assert(strcmp(&s_captured_request_path[4], "EN\\lobby_cd.bin") == 0);
    /* Verify cache invalidation */
    assert(s_cache_inv_called == 1);
    assert(s_cache_inv_size == 0x54320);
    assert(s_cache_inv_dest == (void *)0x01D98000);
    printf("PASS: test_func_002240B0_overlay_loader\n");
}

static void test_func_00221F40_jump_table(void) {
    g_boot_phase_init = 0;
    g_boot_phase = 0;
    g_boot_subphase = 0;

    s_func_220e90_calls = 0;
    s_func_220ff0_calls = 0;
    s_func_2249c0_calls = 0;
    s_func_223ff0_calls = 0;
    s_func_224b30_ready = 1;

    /* Case 0 -> subphase increments to 1 */
    func_00221F40();
    assert(g_boot_subphase == 1);

    /* Case 1 -> calls func_220E90, increments to 2 */
    func_00221F40();
    assert(s_func_220e90_calls == 1);
    assert(g_boot_subphase == 2);

    /* Cases 2..5 -> each frame increments */
    func_00221F40();
    assert(g_boot_subphase == 3);
    func_00221F40();
    assert(g_boot_subphase == 4);
    func_00221F40();
    assert(g_boot_subphase == 5);
    func_00221F40();
    assert(g_boot_subphase == 6);

    /* Case 6 -> calls func_220FF0, increments to 7 */
    func_00221F40();
    assert(s_func_220ff0_calls == 1);
    assert(g_boot_subphase == 7);

    /* Case 7 -> calls func_2249C0, increments to 8 */
    func_00221F40();
    assert(s_func_2249c0_calls == 1);
    assert(g_boot_subphase == 8);

    /* Case 8 -> if 224B30 not ready, stays at 8 */
    s_func_224b30_ready = 0;
    func_00221F40();
    assert(g_boot_subphase == 8);
    assert(s_func_223ff0_calls == 0);

    /* Case 8 -> ready, calls 223FF0, increments to 9 */
    s_func_224b30_ready = 1;
    func_00221F40();
    assert(s_func_223ff0_calls == 1);
    assert(g_boot_subphase == 9);

    /* Case 9 -> transition to phase 0x10, subphase reset to 0 */
    func_00221F40();
    assert(g_boot_phase == 0x10);
    assert(g_boot_subphase == 0);

    printf("PASS: test_func_00221F40_jump_table\n");
}

static void test_func_002221A0_phase12_handoff(void) {
    g_boot_phase = BOOT_PHASE_LOAD_OVERLAY; /* 0x0C */
    s_overlay_entry1_called = 0;
    s_overlay_entry2_called = 0;
    s_use_mock_c1d0 = 1;

    /* Execute Phase 12 */
    int res = func_002221A0();
    assert(res == 0);

    /* Verify overlay entry 1 was called */
    assert(s_overlay_entry1_called == 1);
    /* Verify phase transitioned to 0x11 */
    assert(g_boot_phase == BOOT_PHASE_OVERLAY_ENTRY2);

    /* Execute Phase 0x11 */
    res = func_002221A0();
    assert(res == 0);
    /* Verify overlay entry 2 was called */
    assert(s_overlay_entry2_called == 1);

    s_use_mock_c1d0 = 0;
    printf("PASS: test_func_002221A0_phase12_handoff\n");
}

static void test_game_thread_loop_order(void) {
    s_trace_index = 0;
    g_frame_counter_1 = 0;
    g_frame_counter_2 = 0;
    g_boot_phase_init = 1; /* Return directly from state machine */

    func_002206F0_iter();

    assert(g_frame_counter_1 == 1);
    assert(g_frame_counter_2 == 1);

    /* Verify call order */
    assert(s_trace_index >= 13);
    assert(strcmp(s_call_trace[0], "func_2204D0") == 0);
    assert(strcmp(s_call_trace[1], "func_104D40") == 0);
    assert(strcmp(s_call_trace[2], "func_104D60") == 0);
    assert(strcmp(s_call_trace[3], "func_226260") == 0);
    assert(strcmp(s_call_trace[4], "func_2204E0") == 0);
    assert(strcmp(s_call_trace[5], "func_2207B0") == 0);
    assert(strcmp(s_call_trace[6], "func_104D40") == 0);
    assert(strcmp(s_call_trace[7], "func_221790") == 0);
    assert(strcmp(s_call_trace[8], "func_3379F0") == 0);
    /* state machine is invoked at step 9, returning immediately */
    assert(strcmp(s_call_trace[9], "func_3379F0") == 0);
    assert(strcmp(s_call_trace[10], "func_36F800") == 0);
    assert(strcmp(s_call_trace[11], "func_221C00") == 0);
    assert(strcmp(s_call_trace[12], "func_224A10") == 0);

    printf("PASS: test_game_thread_loop_order\n");
}

static void test_func_002206A0_init_sequence(void) {
    s_trace_index = 0;
    g_game_loop_break = 1;

    func_002206A0();

    assert(s_trace_index >= 8);
    assert(strcmp(s_call_trace[0], "func_220940") == 0);
    assert(strcmp(s_call_trace[1], "func_220BA0") == 0);
    assert(strcmp(s_call_trace[2], "func_220C60") == 0);
    assert(strcmp(s_call_trace[3], "func_221110") == 0);
    assert(strcmp(s_call_trace[4], "func_221410") == 0);
    assert(strcmp(s_call_trace[5], "func_103358") == 0);
    assert(strcmp(s_call_trace[6], "func_2208F0") == 0);
    assert(strcmp(s_call_trace[7], "func_2263A0") == 0);

    printf("PASS: test_func_002206A0_init_sequence\n");
}

int main(void) {
    test_initial_signatures_and_constants();
    test_func_0012C1D0_packaging();
    test_func_002240B0_overlay_loader();
    test_func_00221F40_jump_table();
    test_func_002221A0_phase12_handoff();
    test_game_thread_loop_order();
    test_func_002206A0_init_sequence();
    printf("All game_thread tests passed successfully!\n");
    return 0;
}
