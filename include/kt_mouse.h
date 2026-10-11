#ifndef KT_MOUSE_H
#define KT_MOUSE_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

/* KCET Mouse device structure (176 bytes / 0xB0 bytes per mouse) */
typedef struct KT_MOUSE {
    s32 state;
    s32 buttons;
    s32 x;
    s32 y;
    s32 wheel;
    u8 raw_data[156];
} KT_MOUSE;

/* Global mouse context structure */
typedef struct KT_MOUSE_WORK {
    s32 pad0;
    s32 n_mouse;
    KT_MOUSE *mice;
    s32 flags;
} KT_MOUSE_WORK;

/* Function declarations */
void ktMouseDummy(void);
void ktMousePoll(void);
int ktMouseCheck(void);
void ktMouseFuncA(void);
void ktMouseFuncB(void);

#endif /* KT_MOUSE_H */
