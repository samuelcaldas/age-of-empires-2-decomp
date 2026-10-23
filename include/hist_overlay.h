#ifndef HIST_OVERLAY_H
#define HIST_OVERLAY_H

#include "common.h"

#define HIST_DATA_WORD_COUNT 44816
#define HIST_DATA_BYTE_SIZE (HIST_DATA_WORD_COUNT * 4)

/* 13 History Overlay Functions */
void hist_func_01D98000(void *p);
void hist_func_01D98034(void *p);
void hist_func_01D98200(void *p, int a1, int a2, int a3);
void hist_func_01D984AC(void *p);
void hist_func_01D9879C(void *p, void *a1);
void hist_func_01D98D8C(void *p);
void hist_func_01D98DFC(void *p);
void hist_func_01D98EF8(void *p, int a1);
void hist_func_01D98F44(void *p, int a1);
void hist_func_01D99044(void *p, int a1);
void hist_func_01D992D4(void *p, int a1);
void hist_func_01D99414(void *p);
void hist_func_01D99480(void *p);

/* Historical Encyclopedia Data Table (.rodata, 179,264 bytes) */
extern const unsigned int hist_data[HIST_DATA_WORD_COUNT];

#endif /* HIST_OVERLAY_H */
