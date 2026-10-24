#include <assert.h>
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

int func_10D6C0(void) { return 0; }
int func_10CF10(void) { return 0; }
static int s_mock_pad_state = 0;
int func_10D2E0(int port, int slot) { return s_mock_pad_state; }
int func_10D0F8(void) { return 0; }
int func_10D480(void) { return 0; }
int func_10D260(void) { return 0; }
int func_10D968(void) { return 0; }
int func_00125AE8(void) { return 0; }
int func_10D8B0(void) { return 0; }
int func_10D7F8(void) { return 0; }
int func_10D3F8(int a, int b) { return 0; }
int func_10DBA8(void) { return 0; }
int func_116F68(void) { return 0; }
int func_128D30(void) { return 0; }
int func_104B60(void) { return 0; }

/* Declarations from kt_libpad.c */
int func_001262E8(int *p_ports, int start, u16 *out_ports, int max_items, int n_ports);
u32 func_00126410(int pad_number);
u32 func_00126488(int pad_number);
PadSlot *func_00125A70(int pad_number);
void func_00125AA8(void);
void func_00125AC8(void);

static PadSlot s_mock_slots[2];

PadSlot *func_00125A70(int pad_number) {
    return &s_mock_slots[pad_number];
}
void func_00125AA8(void) {}
void func_00125AC8(void) {}

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

    s_mock_slots[0].buttons = KT_PAD_CROSS | KT_PAD_START;
    s_mock_slots[0].buttons_pressed = KT_PAD_CROSS;

    assert(func_00126410(0) == (KT_PAD_CROSS | KT_PAD_START));
    assert(func_00126488(0) == KT_PAD_CROSS);
}

int func_001275A0(PadSlot *p);

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

int main(void) {
    test_port_slot_enumeration();
    test_button_accessors();
    test_pad_state_dispatcher();
    printf("All native kt_libpad tests passed successfully.\n");
    return 0;
}
