#ifndef MULTIM_OVERLAY_H
#define MULTIM_OVERLAY_H

#include "common.h"

#define MULTIM_DATA_WORD_COUNT 18928
#define MULTIM_DATA_BYTE_SIZE  75712

extern const unsigned int multim_data[MULTIM_DATA_WORD_COUNT];

/* MULTIMCD.BIN Overlay Function Prototypes */
void *multim_func_01D98000(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D9842C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D98504(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D985A8(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D985E4(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D9865C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D987C0(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D9880C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D98848(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D98D5C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D98D98(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D9916C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D995A8(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D996A4(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D9978C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D99CA4(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D99D3C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D99E2C(void *a0, void *a1, void *a2, void *a3);
void *multim_func_01D99E78(void *a0, void *a1, void *a2, void *a3);

#endif /* MULTIM_OVERLAY_H */
