#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "kt_libpad.h"

PadWork D_4EA148;
int D_4EA158[4];

const char D_48F1F0[] = "kt_libpad.c";
const char D_48F200[] = "n_pad > 0";
const char D_48F210[] = "p != NULL";
const char D_48F220[] = "n_pad <= numberof( buf )";
const char D_48F240[] = "port_max <= numberof( dummy_slot_data )";
const char D_48F268[] = "pad_number < W.n_pad";
const char D_48F298[] = "pad_number >= 0 && pad_number < W.n_pad";
const char D_48F2C0[] = "act_number < KT_PAD_MAX_ACTUATER";
const char D_48F2E8[] = "channel < 4";
const char D_48F2F8[] = "n_rpd <= KT_PAD_RAPID_GRP";
const char D_48F318[] = "mode >= KT_PAD_PRESS_OFF && mode < N_KT_PAD_PRESS_MODE";
const char D_48F350[] = "offset >= 0 && offset < KT_PAD_N_PRESS";
const char D_48F378[] = "act_number >= -1 && act_number < KT_PAD_MAX_ACTUATER";
const char D_48F3B0[] = "step >= 0 && step < n_func";
const char D_48F3D0[] = "port == -1";
const char D_48F3E0[] = "slot == -1";
const char D_48F3F0[] = "!((int)p->dma_buffer & 63)";
const char D_48F430[] = "offset+length < n_act";
const char D_4E2BC8[] = "src";
const char D_4E2BD0[] = "n_dat";

void (*D_38C7B8[16])(PadSlot *);
const u32 D_38C7C8[4] = {0, 0, 0, 0};
void (*D_10DC08)() = NULL;
void (*D_10DC60)() = NULL;

void func_114320(const char *file, int line, const char *assertion) {}
void func_001143C0(void *ptr, int size) { memset(ptr, 0, size); }
int func_134210(int a, int b, int c) { return 1; }
int func_103358(int a) { return 0; }
int func_10CCB0(int a) { return 1; }
void func_10DEC0(int a) {}
void *func_116D40(int a, int size) { return NULL; }
void func_10DDF0(int a) {}
int func_105748(int a) { return 0; }
int func_104A20(int a, int b) { return 0; }
void func_1057B0(int a) {}
int func_134440(int a) { return 0; }
int func_134500(int a) { return 0; }

static int s_mock_mode_query_count = 0;
static int s_mock_first_mode_call_offset = -999;

int func_10D6C0(int port, int slot, int type, ...) {
    va_list ap;
    va_start(ap, type);
    s_mock_mode_query_count++;
    if (type == 4) {
        int off = va_arg(ap, int);
        if (s_mock_mode_query_count == 1) {
            s_mock_first_mode_call_offset = off;
        }
        va_end(ap);
        if (off == -1) {
            return 2; /* 2 modes in table */
        }
        if (off == 0) {
            return 0x41; /* Digital */
        }
        if (off == 1) {
            return 0x73; /* Analog (DualShock) */
        }
        return 0;
    }
    va_end(ap);
    return 0;
}

int func_001285F8(int port, int slot, int type);

static void test_mode_info_query_conventions(void) {
    s_mock_mode_query_count = 0;
    s_mock_first_mode_call_offset = -999;

    int idx = func_001285F8(0, 0, 0x73);
    assert(s_mock_first_mode_call_offset == -1);
    assert(idx == 1);
}
static void *s_mock_port_open_buffer = NULL;
int func_10CF10(int req_port, int req_slot, void *dma_buffer) {
    (void)req_port;
    (void)req_slot;
    s_mock_port_open_buffer = dma_buffer;
    return 1;
}
static int s_mock_pad_state = 0;
int func_10D2E0(int port, int slot) { return s_mock_pad_state; }
int func_10D0F8(void) { return 0; }
static int s_mock_pad_read_res = 4;
int func_10D260(int port, int slot, void *report) {
    (void)port;
    (void)slot;
    unsigned char *buf = (unsigned char *)report;
    buf[0] = 0x00;
    buf[1] = 0x73;
    buf[2] = 0xFF;
    buf[3] = 0xFF;
    return s_mock_pad_read_res;
}
/* Declarations from kt_libpad.c */
int func_001262E8(int *p_ports, int start, u16 *out_ports, int max_items, int n_ports);
u32 func_00126410(int pad_number);
u32 func_00126488(int pad_number);
PadSlot *func_00125A70(int pad_number);
void func_00125AA8(void);
void func_00125AC8(void);
int func_001275A0(PadSlot *p);
void func_001273D8(PadSlot *p);
void func_00127820(PadSlot *p);
int func_001285F8(int port, int slot, int type);
PadSlot *func_00125A70(int idx);
void func_00125AA8(void);
void func_00125AC8(void);
int func_00125AE8(int a0, int a1);
int func_00125AF8(void);

static int s_mock_act_calls = 0;
static int s_mock_act_last_args[5] = {0};

int func_10D480(int port, int slot, ...) {
    va_list ap;
    va_start(ap, slot);
    s_mock_act_last_args[0] = port;
    s_mock_act_last_args[1] = slot;
    if (s_mock_act_calls == 0) {
        /* First call is max_acts query: (port, slot) */
        s_mock_act_calls++;
        va_end(ap);
        return 1;
    }
    /* Subsequent calls: descriptor query */
    s_mock_act_last_args[2] = va_arg(ap, int);
    s_mock_act_last_args[3] = va_arg(ap, int);
    s_mock_act_calls++;
    va_end(ap);
    return 0x55;
}

static void test_actuator_desc_call_convention(void) {
    PadSlot slot;
    memset(&slot, 0, sizeof(slot));
    slot.port = 1;
    slot.slot = 0;

    s_mock_act_calls = 0;
    func_00127820(&slot);

    /* Verify 4 arguments: (port=1, slot=0, actuator=0, term=1..4) */
    /* If 5 arguments were passed with -1 as arg 2, last_args[2] would be -1 instead of actuator index 0 */
    assert(s_mock_act_last_args[0] == 1);
    assert(s_mock_act_last_args[1] == 0);
    assert(s_mock_act_last_args[2] == 0); /* actuator index */
    assert(s_mock_act_last_args[3] == 4); /* term: 4th term */
}
int func_10D968(void) { return 0; }
int func_10D8B0(void) { return 0; }
int func_10D7F8(void) { return 0; }
int func_10D3F8(int a, int b) { return 0; }
int func_10DBA8(void) { return 0; }
int func_116F68(int a) { return 0; }
int func_128D30(int a, int b, int c, int d) { return 0; }
int func_104B60(int a) { return 0; }
int func_10CE90(void) { return 1; }
void func_1344C0(int a) {}

static PadSlot s_mock_slots[2];

static void test_port_slot_enumeration(void) {
    int p_ports[2] = {1, 1}; /* port 0 has 1 slot, port 1 has 1 slot */
    u16 out_ports[8];

    int count = func_001262E8(p_ports, 0, out_ports, 4, 2);
    assert(count == 2);
    assert(out_ports[0] == 0); /* port 0 */
    assert(out_ports[1] == 0); /* slot 0 */
    assert(out_ports[2] == 1); /* port 1 */
    assert(out_ports[3] == 0); /* slot 0 */
}

static void test_button_accessors(void) {
    memset(s_mock_slots, 0, sizeof(s_mock_slots));
    D_4EA148.n_pad = 2;
    D_4EA148.slots = s_mock_slots;

    s_mock_slots[0].buttons = KT_PAD_CROSS | KT_PAD_START;
    s_mock_slots[0].buttons_pressed = KT_PAD_CROSS;

    assert(func_00126410(0) == (KT_PAD_CROSS | KT_PAD_START));
    assert(func_00126488(0) == KT_PAD_CROSS);
}

int func_001275A0(PadSlot *p);
void func_001273D8(PadSlot *p);

static void test_pad_state_dispatcher(void) {
    PadSlot slot;
    memset(&slot, 0, sizeof(slot));
    slot.port = 0;
    slot.slot = 0;
    slot.req_port = 0;
    slot.req_slot = 0;

    /* State 5: Zera botões (func_001279B8 -> func_00125E30) */
    slot.buttons = 0xFFFF;
    s_mock_pad_state = 5;
    assert(func_001275A0(&slot) == 0);
    assert(slot.buttons == 0);

    /* State 7: Conta erro (func_00127BD8 -> err_count++) */
    slot.err_count = 10;
    s_mock_pad_state = 7;
    assert(func_001275A0(&slot) == 0);
    assert(slot.err_count == 11);

    /* State 0x63: Desconectado -> retorna 1 */
    s_mock_pad_state = 0x63;
    assert(func_001275A0(&slot) == 1);
}

static int s_mock_step_return = 0;
static int mock_step_handler(PadSlot *p) {
    return s_mock_step_return;
}

static void test_step_advancement_logic(void) {
    PadSlot slot;
    memset(&slot, 0, sizeof(slot));
    slot.step = 0;
    slot.flags = 0x40000;

    D_38C7B8[0] = (void (*)(PadSlot *))mock_step_handler;
    D_38C7B8[1] = (void (*)(PadSlot *))mock_step_handler;
    D_38C7B8[2] = (void (*)(PadSlot *))mock_step_handler;

    /* When handler returns 0, step does NOT advance */
    s_mock_step_return = 0;
    func_001273D8(&slot);
    assert(slot.step == 0);
    assert((slot.flags & 0x40000) == 0);

    /* When handler returns 1 (non-zero), step advances to 1 */
    s_mock_step_return = 1;
    func_001273D8(&slot);
    assert(slot.step == 1);

    /* Advance again with return 1 */
    func_001273D8(&slot);
    assert(slot.step == 2);

    /* Step wraps from 2 to 0 when non-zero returned */
    func_001273D8(&slot);
    assert(slot.step == 0);
}

static void test_pad_slot_lookup_and_shutdown(void) {
    memset(&D_4EA148, 0, sizeof(D_4EA148));
    memset(s_mock_slots, 0, sizeof(s_mock_slots));

    D_4EA148.n_pad = 2;
    D_4EA148.slots = s_mock_slots;

    assert(func_00125A70(0) == &s_mock_slots[0]);
    assert(func_00125A70(1) == &s_mock_slots[1]);
    assert(func_00125A70(2) == NULL);

    s_mock_slots[0].port = 0;
    s_mock_slots[0].slot = 0;
    s_mock_slots[1].port = -1;
    s_mock_slots[1].slot = -1;

    int res = func_00125AF8();
    assert(res == 1);
}

void func_00126BC0(PadSlot *p, int ch, int mask, int mode, int speed);
int func_00127488(PadSlot *p);
int func_00127BE8(PadSlot *p);

static void test_rapid_fire_entry_packing(void) {
    PadSlot slot;
    int i;
    memset(&slot, 0, sizeof(slot));
    func_00126BC0(&slot, 0, 0x1234, 2, 5);
    /* In binary: rapid_table at offset 0x38 + ch*4 with packed byte */
    assert(*(u16 *)&slot.rapid_table[0] == 0x1234);
    assert(slot.rapid_table[2] == 0);
    assert(slot.rapid_table[3] == (u8)(((2 + 15) & 0xF0) | (5 & 0x0F)));
    /* Ensure old unk_1C offset was NOT written */
    for (i = 0; i < 24; i++) {
        assert(slot.unk_1C[i] == 0);
    }
}

static void test_port_open_dma_buffer_offset(void) {
    PadSlot slot;
    memset(&slot, 0, sizeof(slot));
    slot.port = -1;
    slot.slot = -1;
    slot.req_port = 0;
    slot.req_slot = 0;
    s_mock_port_open_buffer = NULL;

    int res = func_00127488(&slot);
    assert(res == 1);
    /* In binary: dma_buffer handed to port open is at offset slot + 0x100 */
    assert(s_mock_port_open_buffer == (void *)((char *)&slot + 0x100));
}

static void test_pad_read_fill_and_return(void) {
    PadSlot slot;
    int i;
    memset(&slot, 0, sizeof(slot));
    slot.port = 0;
    slot.slot = 0;
    s_mock_pad_read_res = 4;

    int r = func_00127BE8(&slot);
    assert(r == 4);
    assert(slot.read_len == 4);
    /* Report[4..31] filled with 0xFF */
    for (i = 4; i < 32; i++) {
        assert(slot.report[i] == 0xFF);
    }
}

int main(void) {
    test_port_slot_enumeration();
    test_button_accessors();
    test_pad_state_dispatcher();
    test_step_advancement_logic();
    test_actuator_desc_call_convention();
    test_mode_info_query_conventions();
    test_pad_slot_lookup_and_shutdown();
    test_rapid_fire_entry_packing();
    test_port_open_dma_buffer_offset();
    test_pad_read_fill_and_return();
    printf("All native kt_libpad tests passed successfully.\n");
    return 0;
}
