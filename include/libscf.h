#ifndef LIBSCF_H
#define LIBSCF_H

#include "common.h"

/* Sony CDVD Real-Time Clock Structure */
typedef struct {
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 pad;
    u8 day;
    u8 month;
    u8 year;
} sceCdCLOCK;
_Static_assert(sizeof(sceCdCLOCK) == 8, "sceCdCLOCK size");
_Static_assert(offsetof(sceCdCLOCK, stat) == 0, "sceCdCLOCK stat offset");
_Static_assert(offsetof(sceCdCLOCK, second) == 1, "sceCdCLOCK second offset");
_Static_assert(offsetof(sceCdCLOCK, minute) == 2, "sceCdCLOCK minute offset");
_Static_assert(offsetof(sceCdCLOCK, hour) == 3, "sceCdCLOCK hour offset");
_Static_assert(offsetof(sceCdCLOCK, day) == 5, "sceCdCLOCK day offset");
_Static_assert(offsetof(sceCdCLOCK, month) == 6, "sceCdCLOCK month offset");
_Static_assert(offsetof(sceCdCLOCK, year) == 7, "sceCdCLOCK year offset");

/* Function Declarations */
unsigned char func_00389570(unsigned char c);
unsigned char func_003895D8(unsigned char c);
void func_00389630(sceCdCLOCK *prtc);
void func_003896B8(sceCdCLOCK *prtc);
void func_00389740(sceCdCLOCK *prtc);
void func_00389828(sceCdCLOCK *prtc);
void func_00389900(sceCdCLOCK *prtc);
void func_00389970(sceCdCLOCK *prtc);
void func_003899D8(sceCdCLOCK *prtc, int diff);
void func_00389AA8(sceCdCLOCK *prtc);
void func_00389AF0(sceCdCLOCK *prtc);

/* Aliases / Macros for known function names */
#define sceScfDec2Bcd            func_00389570
#define sceScfBcd2Dec            func_003895D8
#define sceScfRtcBcd2Dec         func_00389630
#define sceScfRtcDec2Bcd         func_003896B8
#define sceScfRtcIncDay          func_00389740
#define sceScfRtcDecDay          func_00389828
#define sceScfRtcIncHour         func_00389900
#define sceScfRtcDecHour         func_00389970
#define sceScfRtcAdjustMinutes   func_003899D8
#define sceScfGetLocalTime       func_00389AA8
#define sceScfReadRtcAndAdjust   func_00389AF0

#endif /* LIBSCF_H */
