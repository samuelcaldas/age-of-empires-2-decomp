#define NULL ((void *)0)
#include "common.h"
#include "kt_libpad.h"

/* External global references */
extern PadWork D_4EA148;
extern int D_4EA158[4];

extern const char D_48F1F0[]; /* "kt_libpad.c" */
extern const char D_48F200[]; /* "n_pad > 0" */
extern const char D_48F210[]; /* "p != NULL" */
extern const char D_48F220[]; /* "n_pad <= numberof( buf )" */
extern const char D_48F240[]; /* "port_max <= numberof( dummy_slot_data )" */
extern const char D_48F268[]; /* "pad_number < W.n_pad" */
extern const char D_48F298[]; /* "pad_number >= 0 && pad_number < W.n_pad" */
extern const char D_48F2C0[]; /* "act_number < KT_PAD_MAX_ACTUATER" */
extern const char D_48F2E8[]; /* "channel < 4" */
extern const char D_48F2F8[]; /* "n_rpd <= KT_PAD_RAPID_GRP" */
extern const char D_48F318[]; /* "mode >= KT_PAD_PRESS_OFF && mode < N_KT_PAD_PRESS_MODE" */
extern const char D_48F350[]; /* "offset >= 0 && offset < KT_PAD_N_PRESS" */
extern const char D_48F378[]; /* "act_number >= -1 && act_number < KT_PAD_MAX_ACTUATER" */
extern const char D_48F3B0[]; /* "step >= 0 && step < n_func" */
extern const char D_48F3D0[]; /* "port == -1" */
extern const char D_48F3E0[]; /* "slot == -1" */
extern const char D_48F3F0[]; /* "!((int)p->dma_buffer & 63)" */
extern const char D_48F430[]; /* "offset+length < n_act" */
extern const char D_4E2BC8[]; /* "src" */
extern const char D_4E2BD0[]; /* "n_dat" */

extern void (*D_38C7B8[])(PadSlot *);
extern const u32 D_38C7C8[];
extern void (*D_10DC08)();
extern void (*D_10DC60)();

/* External library functions */
void *memcpy(void *dest, const void *src, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int func_10D3F8(int port, int slot);
void func_114320(const char *file, int line, const char *assertion);
void func_001143C0(void *ptr, int size);
int func_134210(int, int, int);
int func_103358(int);
int func_10CCB0(int);
int func_10DEC0(int);
void *func_116D40(int, int);
int func_10DDF0(int);
int func_10CF10(int, int, void *);
int func_10D260(int, int, void *);
int func_10D2E0(int, int);
int func_10D0F8(int, int);
int func_10D480(int, int, ...);
int func_10D6C0(int, int, int, ...);
int func_10D7F8(int, int, int, int);
int func_10D8B0(int, int, void *);
int func_10D968(int, int, void *);
int func_10DBA8(int, int);
int func_116F68(int);
int func_128D30(int, int, int, int);
int func_104B60(int);

/* Forward declarations of kt_gpu helper functions referenced */
PadSlot *func_00125A70(int idx);
void func_00125AA8(void);
void func_00125AC8(void);
int func_00125AE8(int, int);

/* Function Prototypes */
void func_00125C38(int rpc_id, int n_pad, PadSlot *buf);
void func_00125C58(int rpc_id, int n_pad, PadSlot *buf, int flag);
void func_00125DB8(PadSlot *p);
void func_00125DC8(PadSlot *p);
void func_00125DD8(PadSlot *p);
void func_00125DE8(PadSlot *p);
void func_00125E20(PadSlot *p);
void func_00125E30(PadSlot *p);
void func_00125E68(PadSlot *p);
void func_00125EC0(PadSlot *p);
void func_00125F48(void);
void func_00125F68(PadSlot *buf, int n_pad, int flag);
void func_00126040(u16 *out_ports, int n_pad, int mode, int flag, int *p_ports);
int func_00126140(u16 *out_ports, int n_pad, int n_ports, int *p_ports);
int func_001261E0(u16 *out_ports, int n_pad, int n_ports, int *p_ports);
int func_00126258(u16 *out_ports, int n_pad, int n_ports, int *p_ports);
void func_00126288(int *p_ports, int count);
int func_001262E8(int *p_ports, int start, u16 *out_ports, int max_items, int n_ports);
void func_00126350(int pad_number, int cmd);
u32 func_00126410(int pad_number);
u32 func_00126488(int pad_number);
u32 func_00126500(int pad_number);
u32 func_00126578(int pad_number);
u32 func_001265F0(int pad_number);
void func_00126668(int pad_number);
void func_001266D8(int pad_number);
void func_00126750(int pad_number, int act_number, int val1, int val2);
void func_00126810(int pad_number, u8 *align_table);
void func_001268C0(PadSlot *p);
void func_001268D0(int pad_number);
void func_00126938(int pad_number, u32 mask);
void func_001269B0(int pad_number, u32 mask);
void func_00126A30(int pad_number, int ch, u8 *data);
void func_00126AE8(int pad_number, u8 *table, int n_rpd);
void func_00126BC0(PadSlot *p, int ch, u16 mask, int mode, int speed);
int func_00126C30(int pad_number);
int func_00126D50(PadSlot *p);
int func_00126D60(int pad_number);
int func_00126DD8(int pad_number);
void func_00126E68(int pad_number, int mode, int param);
int func_00126EF8(int pad_number, int type);
void func_00126FA8(int pad_number, int mode);
int func_00127048(int pad_number);
int func_001270E8(int pad_number, int offset);
int func_00127188(int pad_number, u8 *dest);
int func_001271E8(int pad_number);
void func_00127288(int pad_number, int act_number);
int func_00127370(void);
void func_00127380(void);
void func_001273D8(PadSlot *p);
int func_00127488(PadSlot *p);
int func_001275A0(PadSlot *p);
int func_001276B0(PadSlot *p);
int func_001276B8(PadSlot *p);
int func_00127750(PadSlot *p);
void func_001277E0(PadSlot *p);
void func_001277F8(PadSlot *p);
int func_00127810(PadSlot *p);
void func_00127820(PadSlot *p);
int func_00127900(PadSlot *p);
void func_001279A0(PadSlot *p);
void func_001279A8(PadSlot *p);
void func_001279B0(PadSlot *p);
void func_001279B8(PadSlot *p);
void func_001279C0(PadSlot *p);
void func_001279C8(PadSlot *p, int flag);
void func_00127BD8(PadSlot *p);
int func_00127BE8(PadSlot *p);
int func_00127C68(PadSlot *p);
int func_00127C78(int val);
void func_00127C88(PadSlot *p, int a, int b, int c);
void func_00127C98(PadSlot *p, void *src, int n_dat);
int func_00127D30(int val, int mode, int a, int b, int c);
int func_00127D88(int val, int scale, int min_val, int max_val);
int func_00127DC8(int val, int a, int b);
int func_00127E40(int val, int min_val, int max_val);
int func_00127E68(PadSlot *p, int flag);
int func_00128130(u8 *p, int idx);
int func_001281B0(PadSlot *p);
int func_001281C0(PadSlot *p);
void func_00128390(PadSlot *p);
int func_001285F8(int port, int slot, int type);
int func_00128698(PadSlot *p);
int func_001286A8(PadSlot *p);
int func_001287D8(PadSlot *p);
int func_001287E8(PadSlot *p);
int func_00128820(PadSlot *p);
void func_00128850(PadSlot *p);
int func_00128868(int val);
int func_00128878(PadSlot *p);
u64 func_00128990(u64 val);
void func_001289C0(void);
int func_00128A18(int a);
char *func_00128A20(char *str, int ch);
void func_00128A68(void);
int func_00128A90(void);
int func_00128B08(void);
void func_00128B18(void);
void func_00128B38(void);
int func_00128B68(int *p);

/* Static small data / flags accessed via GP */
static u8 s_act_0 = 0;
static u8 s_act_1 = 0;
static u16 s_vibe_0 = 0;
static u16 s_vibe_1 = 0;
static int s_state_77cc = 0;
static int s_state_77d0 = 0;
static int s_state_77d4 = 0;

/* Function 1: func_00125C38 */
void func_00125C38(int rpc_id, int n_pad, PadSlot *buf) {
    func_00125C58(rpc_id, n_pad, buf, 0);
}

/* Function 2: func_00125C58 */
void func_00125C58(int rpc_id, int n_pad, PadSlot *buf, int flag) {
    PadSlot *p;
    int i;

    if (n_pad <= 0) {
        func_114320(D_48F1F0, 0x166, D_48F200);
    }
    func_001143C0(&D_4EA148, sizeof(D_4EA148));
    D_4EA148.sema = func_134210(1, 1, 0);

    func_103358(0);
    if (func_10CCB0(rpc_id) != 1) {
        return;
    }
    func_10DEC0(0);

    if (buf == NULL) {
        buf = (PadSlot *)func_116D40(0x40, n_pad << 9);
        if (buf == NULL) {
            func_114320(D_48F1F0, 0x17A, D_48F210);
        }
        if (n_pad != 0) {
            D_4EA148.flags |= 1;
        }
    }
    D_4EA148.slots = buf;
    if (buf == NULL) {
        return;
    }
    D_4EA148.n_pad = n_pad;
    if (n_pad <= 0) {
        return;
    }

    p = buf;
    for (i = n_pad; i != 0; i--) {
        func_00125EC0(p);
        p = (PadSlot *)((u8 *)p + 0x200);
    }
    func_00125F68(buf, n_pad, flag);
}

/* Function 3: func_00125DB8 */
void func_00125DB8(PadSlot *p) {
    func_001143C0(&p->act_align, 12);
}

/* Function 4: func_00125DC8 */
void func_00125DC8(PadSlot *p) {
    func_001143C0(&p->unk_1C, 24);
}

/* Function 5: func_00125DD8 */
void func_00125DD8(PadSlot *p) {
    func_001143C0(&p->unk_34, 4);
}

/* Function 6: func_00125DE8 */
void func_00125DE8(PadSlot *p) {
    int i;
    u8 *ptr0 = &p->act_config[0];
    u8 *ptr1 = &p->act_config[1];

    for (i = 5; i >= 0; i--) {
        *ptr0 = 0;
        *ptr1 = 0;
        ptr0 += 3;
        ptr1 += 3;
    }
}

/* Function 7: func_00125E20 */
void func_00125E20(PadSlot *p) {
    p->state = -1;
}

/* Function 8: func_00125E30 */
void func_00125E30(PadSlot *p) {
    p->buttons = 0;
    p->flags |= 0x40;
    p->buttons_pressed = 0;
    p->buttons_released = 0;
    p->unk_08 = 0;
    p->unk_0C = 0;
    p->unk_94 = 0;
    p->err_count = 0;
    p->unk_88 = 0;
    func_00125DE8(p);
}

/* Function 9: func_00125E68 */
void func_00125E68(PadSlot *p) {
    func_00125DB8(p);
    func_00125DC8(p);
    func_00125DD8(p);
    func_00125E30(p);
    if (p->act_mode != 0) {
        p->model = 0;
        p->flags |= 0x20;
    }
}

/* Function 10: func_00125EC0 */
void func_00125EC0(PadSlot *p) {
    int i;
    u8 *ptr;

    func_001143C0(p, 0x200);
    p->act_mode = 0;
    p->flags |= 0x4;
    p->act_param = 0;
    p->unk_68 = 0x90;
    p->req_slot = -1;
    p->port = -1;
    p->slot = -1;
    func_00125E20(p);
    p->req_port = -1;

    ptr = (u8 *)p + 0x63;
    for (i = 5; i >= 0; i--) {
        *ptr = 0;
        ptr -= 3;
    }
}

/* Function 11: func_00125F48 */
void func_00125F48(void) {
    func_10DDF0(0);
}

/* Function 12: func_00125F68 */
void func_00125F68(PadSlot *buf, int n_pad, int flag) {
    int ports[2];
    u16 out_ports[16];
    int count;
    int i;
    PadSlot *p;

    if (n_pad >= 3) {
        func_114320(D_48F1F0, 0x255, D_48F220);
    }
    if (buf == NULL) {
        buf = (PadSlot *)func_00125A70(0);
    }
    func_00126288(ports, 2);
    count = n_pad;
    func_00126040(out_ports, count, 2, flag, ports);

    if (count > 0) {
        p = buf;
        for (i = 0; i < count; i++) {
            p->req_port = (s16)out_ports[i * 2];
            p->req_slot = (s16)out_ports[i * 2 + 1];
            p = (PadSlot *)((u8 *)p + 0x200);
        }
    }
}

/* Function 13: func_00126040 */
void func_00126040(u16 *out_ports, int n_pad, int mode, int flag, int *p_ports) {
    int i;
    u16 *p;

    if (out_ports == NULL) {
        func_114320(D_48F1F0, 0x298, D_48F210);
    }
    if (n_pad > 0) {
        p = out_ports;
        for (i = 0; i < n_pad; i++) {
            p[0] = (u16)-1;
            p[1] = (u16)-1;
            p += 2;
        }
    }

    if (flag == 1) {
        func_001261E0(out_ports, n_pad, mode, p_ports);
    } else if (flag < 2) {
        func_00126140(out_ports, n_pad, mode, p_ports);
    } else if (flag == 2) {
        func_00126258(out_ports, n_pad, mode, p_ports);
    }
}

/* Function 14: func_00126140 */
int func_00126140(u16 *out_ports, int n_pad, int n_ports, int *p_ports) {
    int dummy[8];
    int i;

    if (n_ports >= 3) {
        func_114320(D_48F1F0, 0x2B8, D_48F240);
    }
    if (n_ports > 0) {
        for (i = 0; i < n_ports; i++) {
            dummy[i] = 1;
        }
    }
    return func_001262E8(dummy, 0, out_ports, n_pad, n_ports);
}

/* Function 15: func_001261E0 */
int func_001261E0(u16 *out_ports, int n_pad, int n_ports, int *p_ports) {
    int ret1 = func_00126140(out_ports, n_pad, n_ports, p_ports);
    int ret2 = func_001262E8(p_ports, 1, out_ports + (ret1 * 2), n_pad - ret1, n_ports);
    return ret1 + ret2;
}

/* Function 16: func_00126258 */
int func_00126258(u16 *out_ports, int n_pad, int n_ports, int *p_ports) {
    return func_001262E8(p_ports, 0, out_ports, n_pad, n_ports);
}

/* Function 17: func_00126288 */
void func_00126288(int *p_ports, int count) {
    int i;
    if (count > 0) {
        for (i = 0; i < count; i++) {
            p_ports[i] = func_10DDF0(i);
        }
    }
}

/* Function 18: func_001262E8 */
int func_001262E8(int *p_ports, int start, u16 *out_ports, int max_items, int n_ports) {
    int count = 0;
    int port;

    if (out_ports == NULL) {
        return 0;
    }
    for (port = 0; port < n_ports; port++) {
        int max_slot = p_ports[port];
        int slot;
        for (slot = start; slot < max_slot; slot++) {
            if (count >= max_items) {
                return count;
            }
            out_ports[count * 2] = (u16)port;
            out_ports[count * 2 + 1] = (u16)slot;
            count++;
        }
    }
    return count;
}

/* Function 19: func_00126350 */
void func_00126350(int pad_number, int cmd) {
    if (pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x319, D_48F268);
    }
    switch (cmd) {
        case 0:
            func_00126410(pad_number);
            break;
        case 1:
            func_00126488(pad_number);
            break;
        case 2:
            func_00126500(pad_number);
            break;
        case 3:
            func_00126578(pad_number);
            break;
        case 4:
            func_001265F0(pad_number);
            break;
        default:
            break;
    }
}

/* Function 20: func_00126410 */
u32 func_00126410(int pad_number) {
    PadSlot *p;
    u16 val;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x32C, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    val = p->buttons;
    func_00125AC8();
    return val;
}

/* Function 21: func_00126488 */
u32 func_00126488(int pad_number) {
    PadSlot *p;
    u16 val;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x33B, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    val = p->buttons_pressed;
    func_00125AC8();
    return val;
}

/* Function 22: func_00126500 */
u32 func_00126500(int pad_number) {
    PadSlot *p;
    u16 val;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x34A, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    val = p->buttons_released;
    func_00125AC8();
    return val;
}

/* Function 23: func_00126578 */
u32 func_00126578(int pad_number) {
    PadSlot *p;
    u32 val;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x359, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    val = p->unk_08;
    func_00125AC8();
    return val;
}

/* Function 24: func_001265F0 */
u32 func_001265F0(int pad_number) {
    PadSlot *p;
    u32 val;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x368, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    val = p->unk_0C;
    func_00125AC8();
    return val;
}

/* Function 25: func_00126668 */
void func_00126668(int pad_number) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x378, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    p->flags |= 0x8;
    func_00125AC8();
}

/* Function 26: func_001266D8 */
void func_001266D8(int pad_number) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x386, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    p->flags &= ~0x8;
    func_00125AC8();
}

/* Function 27: func_00126750 */
void func_00126750(int pad_number, int act_number, int val1, int val2) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x398, D_48F298);
    }
    p = func_00125A70(pad_number);
    if (act_number >= 6) {
        func_114320(D_48F1F0, 0x39B, D_48F2C0);
    }
    func_00125AA8();
    p->act_config[act_number * 3] = (u8)val2;
    p->act_config[act_number * 3 + 1] = (u8)val1;
    func_00125AC8();
}

/* Function 28: func_00126810 */
void func_00126810(int pad_number, u8 *align_table) {
    PadSlot *p;
    int i;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x3AD, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    for (i = 0; i < 6; i++) {
        p->act_align[i * 2] = align_table[i];
    }
    func_00125AC8();
    func_001268D0(pad_number);
}

/* Function 29: func_001268C0 */
void func_001268C0(PadSlot *p) {
    p->flags |= 0x10;
}

/* Function 30: func_001268D0 */
void func_001268D0(int pad_number) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x3C7, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    func_001268C0(p);
    func_00125AC8();
}

/* Function 31: func_00126938 */
void func_00126938(int pad_number, u32 mask) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x3D4, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    p->unk_68 |= mask;
    func_00125AC8();
}

/* Function 32: func_001269B0 */
void func_001269B0(int pad_number, u32 mask) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x3E1, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    p->unk_68 &= ~mask;
    func_00125AC8();
}

/* Function 33: func_00126A30 */
void func_00126A30(int pad_number, int ch, u8 *data) {
    PadSlot *p;
    u32 val;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x3EE, D_48F298);
    }
    p = func_00125A70(pad_number);
    if (ch >= 4) {
        func_114320(D_48F1F0, 0x3F1, D_48F2E8);
    }
    func_00125AA8();
    val = *(u32 *)data;
    *(u32 *)(&p->act_data[ch * 4]) = val;
    func_00125AC8();
}

/* Function 34: func_00126AE8 */
void func_00126AE8(int pad_number, u8 *table, int n_rpd) {
    PadSlot *p;
    int i;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x405, D_48F298);
    }
    if (n_rpd >= 4) {
        func_114320(D_48F1F0, 0x406, D_48F2F8);
    }
    p = func_00125A70(pad_number);
    for (i = 0; i < n_rpd; i++) {
        u16 mask = *(u16 *)(table + i * 4);
        u8 mode = *(table + i * 4 + 2);
        u8 speed = *(table + i * 4 + 3);
        func_00126BC0(p, i, mask, mode, speed);
    }
}

/* Function 35: func_00126BC0 */
void func_00126BC0(PadSlot *p, int ch, u16 mask, int mode, int speed) {
    func_00125AA8();
    *(u16 *)(&p->unk_1C[ch * 4]) = mask;
    p->unk_1C[ch * 4 + 2] = (u8)mode;
    p->unk_1C[ch * 4 + 3] = (u8)speed;
    func_00125AC8();
}

/* Function 36: func_00126C30 */
int func_00126C30(int pad_number) {
    PadSlot *p;
    int res = 0;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x429, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();

    if (p->state < 3) {
        if (p->state > 0) {
            res = (func_00126D50(p) != 0) ? 4 : 3;
        } else if (p->state == -1) {
            if (p->req_port == p->state && p->req_slot == p->state) {
                res = 1;
            }
        } else if (p->state == 0) {
            res = 2;
        }
    } else {
        if (p->state == 6) {
            res = 1;
        } else if (p->state < 7) {
            if (p->state == 5) {
                res = (func_00126D50(p) != 0) ? 4 : 3;
            }
        } else {
            if (p->state == 7) {
                res = (func_00126D50(p) != 0) ? 4 : 3;
            } else if (p->state == 0x63) {
                res = 1;
            }
        }
    }
    func_00125AC8();
    return res;
}

/* Function 37: func_00126D50 */
int func_00126D50(PadSlot *p) {
    return p->flags & 0x40000;
}

/* Function 38: func_00126D60 */
int func_00126D60(int pad_number) {
    PadSlot *p;
    int res;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x47C, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    res = func_00126D50(p);
    func_00125AC8();
    return res;
}

/* Function 39: func_00126DD8 */
int func_00126DD8(int pad_number) {
    PadSlot *p;
    int res = 0;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x48B, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    if (p->flags & 0x40000) {
        res = p->unk_94;
    }
    func_00125AC8();
    return res;
}

/* Function 40: func_00126E68 */
void func_00126E68(int pad_number, int mode, int param) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x49E, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00125AA8();
    p->act_mode = mode;
    p->act_param = param;
    p->flags |= 0x20;
    func_00125AC8();
}

/* Function 41: func_00126EF8 */
int func_00126EF8(int pad_number, int type) {
    PadSlot *p;
    int res = -2;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x4B2, D_48F298);
    }
    p = func_00125A70(pad_number);
    if (func_00126D60(pad_number) != 0) {
        func_00125AA8();
        res = func_001285F8(p->port, p->slot, type);
        func_00125AC8();
    }
    return res;
}

/* Function 42: func_00126FA8 */
void func_00126FA8(int pad_number, int mode) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x4C4, D_48F298);
    }
    p = func_00125A70(pad_number);
    if ((u32)mode >= 3) {
        func_114320(D_48F1F0, 0x4C7, D_48F318);
    }
    func_00125AA8();
    p->press_mode = mode;
    p->flags |= 0x40;
    func_00125AC8();
}

/* Function 43: func_00127048 */
int func_00127048(int pad_number) {
    PadSlot *p;
    int res = -1;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x4E8, D_48F298);
    }
    p = func_00125A70(pad_number);
    if (func_00126D60(pad_number) != 0) {
        func_00125AA8();
        res = func_00128868(p->model);
        func_00125AC8();
    }
    return res;
}

/* Function 44: func_001270E8 */
int func_001270E8(int pad_number, int offset) {
    PadSlot *p;
    int res;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x4F9, D_48F298);
    }
    p = func_00125A70(pad_number);
    if ((u32)offset >= 12) {
        func_114320(D_48F1F0, 0x4FC, D_48F350);
    }
    func_00125AA8();
    res = p->data_10[offset];
    func_00125AC8();
    return res;
}

/* Function 45: func_00127188 */
int func_00127188(int pad_number, u8 *dest) {
    PadSlot *p;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x509, D_48F298);
    }
    p = func_00125A70(pad_number);
    func_00127C98(p, dest, 12);
    return 12;
}

/* Function 46: func_001271E8 */
int func_001271E8(int pad_number) {
    PadSlot *p;
    int res = -1;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x515, D_48F298);
    }
    p = func_00125A70(pad_number);
    if (func_00126D60(pad_number) != 0) {
        func_00125AA8();
        res = (p->flags >> 19) & 1;
        func_00125AC8();
    }
    return res;
}

/* Function 47: func_00127288 */
void func_00127288(int pad_number, int act_number) {
    PadSlot *p;
    int start;
    int end;
    int i;

    if (pad_number < 0 || pad_number >= D_4EA148.n_pad) {
        func_114320(D_48F1F0, 0x529, D_48F298);
    }
    p = func_00125A70(pad_number);
    if ((u32)(act_number + 1) >= 7) {
        func_114320(D_48F1F0, 0x52C, D_48F378);
    }
    func_00125AA8();
    if (act_number != -1) {
        start = act_number;
        end = act_number + 1;
    } else {
        start = 0;
        end = 6;
    }
    for (i = start; i < end; i++) {
        p->act_config[i * 3] = 0;
    }
    func_00125AC8();
}

/* Function 48: func_00127370 */
int func_00127370(void) {
    return D_4EA148.n_pad;
}

/* Function 49: func_00127380 */
void func_00127380(void) {
    int i;
    PadSlot *p = D_4EA148.slots;
    int n = D_4EA148.n_pad;

    func_00125AA8();
    for (i = n; i > 0; i--) {
        func_001273D8(p);
        p = (PadSlot *)((u8 *)p + 0x200);
    }
    func_00125AC8();
}

/* Function 50: func_001273D8 */
void func_001273D8(PadSlot *p) {
    int step = p->step;

    if (step < 0 || step >= 3) {
        func_114320(D_48F1F0, 0x568, D_48F3B0);
    }
    p->flags &= ~0x40000;
    D_38C7B8[step](p);

    step++;
    if (step >= 3) {
        step = 0;
    }
    p->step = step;
    func_00125E20(p);
}

/* Function 51: func_00127488 */
int func_00127488(PadSlot *p) {
    int req_port = p->req_port;
    int req_slot = p->req_slot;
    int port = p->port;
    int slot = p->slot;

    if (func_00128A18(req_port) != 0) {
        return 0;
    }
    if (port == req_port && slot == req_slot) {
        return 0;
    }
    if (port != -1) {
        func_114320(D_48F1F0, 0x5B7, D_48F3D0);
    }
    if (slot != -1) {
        func_114320(D_48F1F0, 0x5B8, D_48F3E0);
    }
    if (req_port == -1 || req_slot == -1) {
        return 0;
    }
    if (((u32)p->dma_buffer) & 0x3F) {
        func_114320(D_48F1F0, 0x5BE, D_48F3F0);
    }
    if (func_10CF10(req_port, req_slot, p->dma_buffer) != 1) {
        return 0;
    }
    p->port = req_port;
    p->slot = req_slot;
    return 1;
}

/* Function 52: func_001275A0 */
int func_001275A0(PadSlot *p) {
    int res = 0;
    int st;

    if (func_001276B8(p)) {
        res = 1;
    } else {
        p->state = st = func_10D2E0(p->port, p->slot);
        switch (st) {
            default:
            case 0:
                func_001279A0(p);
                break;
            case 1:
                func_001279A8(p);
                break;
            case 2:
                func_001279B0(p);
                break;
            case 5:
                func_001279B8(p);
                break;
            case 6:
                func_001279C0(p);
                break;
            case 7:
                func_00127BD8(p);
                break;
            case 0x63:
                func_001279A0(p);
                res = 1;
                break;
        }
    }
    return res;
}

/* Function 53: func_001276B0 */
int func_001276B0(PadSlot *p) {
    return 0;
}

/* Function 54: func_001276B8 */
int func_001276B8(PadSlot *p) {
    int cond = 0;

    if (func_00128A18(p->port) != 0) {
        cond = 1;
    }
    if (func_001276B0(p) != 0) {
        cond = 1;
    }
    if (p->port != p->req_port || p->slot != p->req_slot) {
        cond = 1;
    }
    if (cond == 0) {
        return 0;
    }
    p->flags |= 0x2;
    return 1;
}

/* Function 55: func_00127750 */
int func_00127750(PadSlot *p) {
    int cond = 1;

    if (func_10D2E0(p->port, p->slot) != 0x63) {
        if (func_10D0F8(p->port, p->slot) != 1) {
            cond = 0;
        }
    }
    if (cond) {
        p->flags &= ~0x2;
        p->port = -1;
        p->slot = -1;
    }
    return cond;
}

/* Function 56: func_001277E0 */
void func_001277E0(PadSlot *p) {
    p->flags |= 0x10000;
}

/* Function 57: func_001277F8 */
void func_001277F8(PadSlot *p) {
    p->flags &= ~0x10000;
}

/* Function 58: func_00127810 */
int func_00127810(PadSlot *p) {
    return p->flags & 0x10000;
}

/* Function 59: func_00127820 */
void func_00127820(PadSlot *p) {
    int max_acts = func_10D480(p->port, p->slot);
    int i, j;

    if (max_acts > 6) {
        max_acts = 6;
    }
    if (max_acts <= 0) {
        return;
    }
    for (i = 0; i < max_acts; i++) {
        for (j = 0; j < 4; j++) {
            p->unk_1C[i * 4 + j] = (u8)func_10D480(p->port, p->slot, -1, i, j + 1);
        }
    }
}

/* Function 60: func_00127900 */
int func_00127900(PadSlot *p) {
    u8 buf[4];
    int i;

    for (i = 0; i < 4; i++) {
        buf[i] = (u8)func_10D6C0(p->port, p->slot, i + 1);
    }
    if (p->unk_34 != *(u32 *)buf) {
        p->unk_34 = *(u32 *)buf;
        return 1;
    }
    return 0;
}

/* Function 61: func_001279A0 */
void func_001279A0(PadSlot *p) {
    func_00125E68(p);
}

/* Function 62: func_001279A8 */
void func_001279A8(PadSlot *p) {
    func_00125E30(p);
}

/* Function 63: func_001279B0 */
void func_001279B0(PadSlot *p) {
    func_001279C8(p, 0);
}

/* Function 64: func_001279B8 */
void func_001279B8(PadSlot *p) {
    func_00125E30(p);
}

/* Function 65: func_001279C0 */
void func_001279C0(PadSlot *p) {
    func_001279C8(p, 1);
}

/* Function 66: func_001279C8 */
void func_001279C8(PadSlot *p, int flag) {
    int unk_19 = p->unk_88;
    int unk_17 = 0;
    int ret;

    if (func_00127BE8(p) == 0) {
        u8 val4 = p->dma_buffer[5];
        if ((val4 & 0xF0) != (p->model & 0xF0)) {
            p->model = val4;
            unk_19 = 0;
            unk_17 = 1;
        }
    }

    switch (unk_19) {
        case 0:
            p->retry_count = 0;
            func_001277E0(p);
            p->err_count = 0;
            unk_17 |= func_00127900(p);
            if (unk_17 == 0) {
                unk_19++;
                break;
            }
            func_00127820(p);
            p->flags |= 0x10;
            if (flag) {
                p->flags |= 0x20000;
            } else {
                p->flags &= ~0x20000;
            }
            unk_19++;
            break;
        case 1:
            ret = func_001286A8(p);
            /* NOTE: Intentional goto for switch branch convergence to shared post-processing (idiomatic original C). */
            goto check_sub;
        case 2:
            ret = func_001281C0(p);
            /* NOTE: Intentional goto for switch branch convergence to shared post-processing (idiomatic original C). */
            goto check_sub;
        case 3:
            ret = func_00128878(p);
        check_sub:
            if (ret == 0) {
                ret = 2;
            } else if (ret > 0) {
                if (ret != 1) {
                    ret = 0;
                }
            } else {
                ret = 0;
            }
            if (ret > 0) {
                p->unk_A0 = 0;
                unk_19 += ret;
                break;
            }
            ret = func_10D3F8(p->port, p->slot);
            unk_17 = unk_19;
            if (ret == 1) {
                p->unk_A0++;
            } else if (ret < 2) {
                if (ret == 0) {
                    unk_17 = unk_19 + 1;
                } else {
                    unk_17 = unk_19 - 1;
                }
            } else if (ret != 2) {
                unk_17 = unk_19 - 1;
            }
            unk_19 = unk_17;
            break;
        default:
            func_00127E68(p, 1);
            func_00128390(p);
            if (func_00128698(p) == 0 && func_001281B0(p) == 0) {
                if (func_001287D8(p) == 0) {
                    p->flags |= 0x40000;
                    break;
                }
            }
            func_00125E30(p);
            unk_19 = p->unk_88;
            break;
    }
    p->unk_88 = unk_19;
}

/* Function 67: func_00127BD8 */
void func_00127BD8(PadSlot *p) {
    p->err_count++;
}

/* Function 68: func_00127BE8 */
int func_00127BE8(PadSlot *p) {
    int res = func_10D260(p->port, p->slot, &p->dma_buffer[4]);
    if ((u32)(res - 1) >= 0x1F) {
        return 0;
    }
    return res;
}

/* Function 69: func_00127C68 */
int func_00127C68(PadSlot *p) {
    return p->flags & 0x4;
}

/* Function 70: func_00127C78 */
int func_00127C78(int val) {
    return (val ^ 4) != 0;
}

/* Function 71: func_00127C88 */
void func_00127C88(PadSlot *p, int a, int b, int c) {
    p->buttons = (u16)a;
    p->buttons_pressed = (u16)b;
    p->buttons_released = (u16)c;
}

/* Function 72: func_00127C98 */
void func_00127C98(PadSlot *p, void *src, int n_dat) {
    if (src == NULL) {
        func_114320(D_48F1F0, 0x7F4, D_4E2BC8);
    }
    if (n_dat == 0) {
        func_114320(D_48F1F0, 0x7F5, D_4E2BD0);
    }
    memcpy(p->data_10, src, n_dat);
}

/* Function 73: func_00127D30 */
int func_00127D30(int val, int mode, int a, int b, int c) {
    if (mode == 1) {
        return func_00127DC8(val, a, b);
    }
    if (mode == 2) {
        return func_00127E40(val, b, c);
    }
    return val & 0xFF;
}

/* Function 74: func_00127D88 */
int func_00127D88(int val, int scale, int min_val, int max_val) {
    int diff = val - min_val;
    int range;
    int res;

    if (diff < 0) {
        diff = 0;
    }
    range = max_val - min_val;
    if (range == 0) {
        return scale - 1;
    }
    res = (diff * scale) / range;
    if (res >= scale) {
        res = scale - 1;
    }
    return res;
}

/* Function 75: func_00127DC8 */
int func_00127DC8(int val, int a, int b) {
    int threshold;
    if (b < 0x80) {
        threshold = b;
    } else {
        threshold = 0x100 - b;
    }
    if (val < b) {
        if (a < threshold) {
            return 0;
        }
    }
    return func_00127E40(val, a, 0x100);
}

/* Function 76: func_00127E40 */
int func_00127E40(int val, int min_val, int max_val) {
    return func_00127D88(val, 0x100, min_val, max_val) & 0xFF;
}

/* Function 77: func_00127E68 */
int func_00127E68(PadSlot *p, int flag) {
    u32 raw_btn;
    u16 btn;
    int i;
    u32 unk_c = 0;
    u32 unk_10 = 0;
    u32 unk_14 = 0;
    void *src_data;

    if (flag == 0) {
        p->err_count = 0;
        return 0;
    }
    if (p->dma_buffer[4] != 0) {
        p->err_count++;
        func_001277E0(p);
        p->buttons_pressed = 0;
        p->buttons_released = 0;
        p->unk_08 = 0;
        p->unk_0C = 0;
        return 0;
    }

    raw_btn = (u32)p->dma_buffer[5];
    if (!((p->unk_68 >> (raw_btn >> 4)) & 1)) {
        return 0;
    }

    btn = (~((p->dma_buffer[6] << 8) | p->dma_buffer[7])) & 0xFFFF;
    if (btn != 0) {
        for (i = 0; i < 3; i++) {
            u16 mask = *(u16 *)(&p->rapid_table[i * 4]);
            u8 mode = p->rapid_table[i * 4 + 2];
            u8 speed = p->rapid_table[i * 4 + 3];

            if (mask & btn) {
                unk_c |= (mask & btn);
                if ((speed & 0xF0) == 0) {
                    p->rapid_table[i * 4 + 2] = speed & 0xF;
                } else if (mode != 0) {
                    p->rapid_table[i * 4 + 2] = mode - 1;
                } else {
                    unk_c |= (mask & btn);
                    p->rapid_table[i * 4 + 2] = speed & 0xF;
                }
            }
        }
    }

    src_data = &p->dma_buffer[12];
    if (func_00127C68(p) && func_00127C78(raw_btn >> 4)) {
        for (i = 0; i < 4; i++) {
            u8 d = p->dma_buffer[11 - i];
            int r = func_00127D30(d, p->act_data[i * 4 + 2], p->act_data[i * 4], p->act_data[i * 4 + 1], p->act_data[i * 4 + 3]);
            unk_10 = (unk_10 << 8) | d;
            unk_14 = (unk_14 << 8) | (r & 0xFF);
        }
    }

    if (func_00128868(p->dma_buffer[5])) {
        src_data = (void *)D_38C7C8;
    }

    if (func_00127810(p)) {
        func_001277F8(p);
        p->err_count = 0;
    }

    func_00127C88(p, btn, btn & (~p->buttons), p->buttons & (~btn));
    func_00127C98(p, src_data, 12);
    p->unk_94 = raw_btn >> 4;
    p->unk_0C = unk_10;
    p->unk_08 = unk_14;
    return 1;
}

/* Function 78: func_00128130 */
int func_00128130(u8 *p, int idx) {
    if (idx == 0) {
        return 0xFF;
    }
    if (p[0] == s_act_0 && p[1] == s_act_1) {
        return 0;
    }
    return 0xFF;
}

/* Function 79: func_001281B0 */
int func_001281B0(PadSlot *p) {
    return (p->flags & 0x10) != 0;
}

/* Function 80: func_001281C0 */
int func_001281C0(PadSlot *p) {
    int i;
    int unk_19 = 0;
    u8 dummy[6];
    int res = 0;

    if (func_001281B0(p) == 0) {
        return 0;
    }
    memset(dummy, 0xFF, sizeof(dummy));

    for (i = 0; i < 6; i++) {
        p->act_config[i * 3 + 1] = 0;
        dummy[i] = func_00128130(&p->act_align[i * 2], p->unk_1C[i * 4]);
        if (dummy[i] != 0xFF) {
            int step = p->unk_1C[dummy[i] * 4 + 2] ? 1 : p->unk_1C[dummy[i] * 4 + 2];
            if (unk_19 + step < 7) {
                p->act_align[i * 2] = dummy[i];
                p->act_align[i * 2 + 1] = unk_19;
                unk_19 += step;
            } else {
                p->act_align[i * 2] = dummy[i];
            }
        }
    }

    if (p->flags & 0x20000) {
        res = func_10D968(p->port, p->slot, dummy);
        if (res == 1) {
            func_00125AE8(p->port, p->slot);
            res = -1;
        }
    }
    if (res != -1) {
        p->flags ^= 0x10;
    }
    return res;
}

/* Function 81: func_00128390 */
void func_00128390(PadSlot *p) {
    int i;
    u32 buf[2];
    int unk_18 = (p->flags & 0x8) != 0;
    int changed = 0;

    buf[0] = 0;
    buf[1] = 0;

    for (i = 0; i < 6; i++) {
        u8 a = p->act_align[i * 2];
        u8 c = p->act_config[i * 3];
        u8 val = p->act_config[i * 3 + 1];

        if (a != 0xFF) {
            if (!unk_18) {
                val = 0;
            }
            if (p->unk_1C[a * 4 + 2] == 0) {
                val = (val != 0) ? 1 : 0;
            }
            p->act_config[i * 3] = c;
            if (p->act_align[i * 2 + 1] + val < 6) {
                ((u8 *)buf)[p->act_align[i * 2 + 1]] = val;
            } else {
                func_114320(D_48F1F0, 0x9D9, D_48F430);
            }
        }
    }

    if (buf[0] != p->act_exec[0] || buf[1] != p->act_exec[1]) {
        changed = 1;
    }
    if (changed) {
        if (p->flags & 0x20000) {
            func_10D8B0(p->port, p->slot, buf);
            p->act_exec[0] = buf[0];
            p->act_exec[1] = buf[1];
        }
    }
}

/* Function 82: func_001285F8 */
int func_001285F8(int port, int slot, int type) {
    int count = func_10D6C0(port, slot, 4);
    int i;

    for (i = 0; i < count; i++) {
        int t = func_10D6C0(port, slot, 4, i);
        if (t <= 0) {
            break;
        }
        if (t == type) {
            return i;
        }
    }
    return -1;
}

/* Function 83: func_00128698 */
int func_00128698(PadSlot *p) {
    return (p->flags & 0x20) != 0;
}

/* Function 84: func_001286A8 */
int func_001286A8(PadSlot *p) {
    int mode = p->act_mode;
    int param = p->act_param;
    int res = 0;
    int idx;

    if (!func_00128698(p)) {
        return 0;
    }
    if (param == 0) {
        param = p->unk_34 & 0xFF;
    }
    if (mode == 0) {
        mode = p->unk_34 & 0xFF;
    }
    mode ^= param;
    if (mode <= 0) {
        p->flags ^= 0x20;
        return 0;
    }

    idx = func_001285F8(p->port, p->slot, mode);
    if (idx >= 0) {
        if (func_10D7F8(p->port, p->slot, idx, param) != 1) {
            if (p->retry_count < 6) {
                p->retry_count++;
                res = (param != 3) ? 0 : -1;
            } else {
                p->retry_count = 0;
                res = (param != 3) ? -1 : 0;
            }
        } else {
            res = 1;
        }
    }
    if (param == 3 && res == 0) {
        res = -1;
    }
    if (res >= 0) {
        p->flags ^= 0x20;
        if (res == 1) {
            func_001268C0(p);
        }
    }
    return res;
}

/* Function 85: func_001287D8 */
int func_001287D8(PadSlot *p) {
    return (p->flags & 0x40) != 0;
}

/* Function 86: func_001287E8 */
int func_001287E8(PadSlot *p) {
    if (p->press_mode == 1) {
        return 1;
    }
    if (p->press_mode < 2) {
        return 2;
    }
    return 2;
}

/* Function 87: func_00128820 */
int func_00128820(PadSlot *p) {
    if (p->press_mode == 1 || p->press_mode < 2) {
        return 1;
    }
    return 2;
}

/* Function 88: func_00128850 */
void func_00128850(PadSlot *p) {
    p->flags &= ~0x40;
}

/* Function 89: func_00128868 */
int func_00128868(int val) {
    return (val ^ 0x79) < 1;
}

/* Function 90: func_00128878 */
int func_00128878(PadSlot *p) {
    int res = 0;
    int is_dual;

    if (func_10DBA8(p->port, p->slot) != 1) {
        p->flags |= 0x80000;
    } else {
        p->flags &= ~0x80000;
    }
    if (!func_001287D8(p)) {
        return 0;
    }

    is_dual = func_00128868(p->model);
    if (func_001287E8(p) == is_dual) {
        func_00128820(p);
    }
    func_00128850(p);
    return res;
}

/* Function 91: func_00128990 */
u64 func_00128990(u64 val) {
    u64 v0 = s_vibe_0;
    u64 v1 = s_vibe_1;
    val = (val & 0xFFFF0000) | v0;
    val = (val & 0xFFFFFFFF) | (v1 << 16);
    return val;
}

/* Function 92: func_001289C0 */
void func_001289C0(void) {
    int i;
    func_001143C0(D_4EA158, sizeof(D_4EA158));
    for (i = 0; i < 2; i++) {
        D_4EA158[i * 2] = -1;
        D_4EA158[i * 2 + 1] = -1;
    }
}

/* Function 93: func_00128A18 */
int func_00128A18(int a) {
    return 0;
}

/* Function 94: func_00128A20 */
char *func_00128A20(char *str, int ch) {
    char target = (char)ch;
    while (*str != '\0') {
        if (*str == target) {
            return str;
        }
        str++;
    }
    return NULL;
}

/* Function 95: func_00128A68 */
void func_00128A68(void) {
    if (s_state_77cc != 0) {
        func_116F68(s_state_77cc);
        s_state_77cc = 0;
    }
}

/* Function 96: func_00128A90 */
int func_00128A90(void) {
    int val = s_state_77d4;
    int res = 0;

    if (val == 1) {
        res = 0;
    } else if (val < 2) {
        if (val == -1) {
            res = 1;
        }
    } else if (val == 2) {
        res = 1;
    }
    func_00128A68();
    s_state_77d0 = res;
    s_state_77d4 = 0;
    return res;
}

/* Function 97: func_00128B08 */
int func_00128B08(void) {
    return s_state_77d0;
}

/* Function 98: func_00128B18 */
void func_00128B18(void) {
    func_00128A90();
}

/* Function 99: func_00128B38 */
void func_00128B38(void) {
    do {
        func_103358(0);
    } while (func_00128A90() == 0);
}

/* Function 100: func_00128B68 */
int func_00128B68(int *p) {
    int res = func_128D30(p[0], p[1], p[2], p[3]);
    if (res == 0) {
        res = 2;
    } else {
        res = -1;
    }
    s_state_77d4 = res;
    return func_104B60(res);
}
