#ifndef LIBSCF_H
#define LIBSCF_H

#include "common.h"

/* Sony CDVD Real-Time Clock Structure */
typedef struct {
    unsigned char stat;
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char pad;
    unsigned char day;
    unsigned char month;
    unsigned char year;
} sceCdCLOCK;

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

#endif /* LIBSCF_H */
