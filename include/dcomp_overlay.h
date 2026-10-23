/* PS2 DCOMP_CD.BIN Overlay Header */
#ifndef DCOMP_OVERLAY_H
#define DCOMP_OVERLAY_H

#include "common.h"

#define DCOMP_DATA_WORD_COUNT 976
#define DCOMP_DATA_BYTE_SIZE (DCOMP_DATA_WORD_COUNT * 4)

extern const unsigned int dcomp_data[DCOMP_DATA_WORD_COUNT];

/* All 71 DCOMP Overlay Functions */
void dcomp_func_01D98000(void *p, ...);
void dcomp_func_01D98024(void *p, ...);
void dcomp_func_01D9805C(void *p, ...);
void dcomp_func_01D98084(void *p, ...);
void dcomp_func_01D98110(void *p, ...);
void dcomp_func_01D981F4(void *p, ...);
void dcomp_func_01D983FC(void *p, ...);
void dcomp_func_01D98520(void *p, ...);
void dcomp_func_01D9862C(void *p, ...);
void dcomp_func_01D987D4(void *p, ...);
void dcomp_func_01D98A40(void *p, ...);
void dcomp_func_01D98A78(void *p, ...);
void dcomp_func_01D98AF0(void *p, ...);
void dcomp_func_01D98BFC(void *p, ...);
void dcomp_func_01D98CE4(void *p, ...);
void dcomp_func_01D98FCC(void *p, ...);
void dcomp_func_01D990F0(void *p, ...);
void dcomp_func_01D9911C(void *p, ...);
void dcomp_func_01D991B4(void *p, ...);
void dcomp_func_01D99290(void *p, ...);
void dcomp_func_01D995F8(void *p, ...);
void dcomp_func_01D99840(void *p, ...);
void dcomp_func_01D99B00(void *p, ...);
void dcomp_func_01D99B44(void *p, ...);
void dcomp_func_01D99D9C(void *p, ...);
void dcomp_func_01D9A248(void *p, ...);
void dcomp_func_01D9A2D4(void *p, ...);
void dcomp_func_01D9AAD8(void *p, ...);
void dcomp_func_01D9B09C(void *p, ...);
void dcomp_func_01D9B744(void *p, ...);
void dcomp_func_01D9B7B4(void *p, ...);
void dcomp_func_01D9B910(void *p, ...);
void dcomp_func_01D9BA78(void *p, ...);
void dcomp_func_01D9BC5C(void *p, ...);
void dcomp_func_01D9BE50(void *p, ...);
void dcomp_func_01D9BE70(void *p, ...);
void dcomp_func_01D9BF88(void *p, ...);
void dcomp_func_01D9BFA8(void *p, ...);
void dcomp_func_01D9BFC8(void *p, ...);
void dcomp_func_01D9C02C(void *p, ...);
void dcomp_func_01D9C058(void *p, ...);
void dcomp_func_01D9C088(void *p, ...);
void dcomp_func_01D9C0C8(void *p, ...);
void dcomp_func_01D9C11C(void *p, ...);
void dcomp_func_01D9C138(void *p, ...);
void dcomp_func_01D9C190(void *p, ...);
void dcomp_func_01D9C1E8(void *p, ...);
void dcomp_func_01D9C23C(void *p, ...);
void dcomp_func_01D9C27C(void *p, ...);
void dcomp_func_01D9CC54(void *p, ...);
void dcomp_func_01D9CD90(void *p, ...);
void dcomp_func_01D9CF04(void *p, ...);
void dcomp_func_01D9D048(void *p, ...);
void dcomp_func_01D9D184(void *p, ...);
void dcomp_func_01D9D26C(void *p, ...);
void dcomp_func_01D9D320(void *p, ...);
void dcomp_func_01D9D40C(void *p, ...);
void dcomp_func_01D9D588(void *p, ...);
void dcomp_func_01D9D6C4(void *p, ...);
void dcomp_func_01D9DB3C(void *p, ...);
void dcomp_func_01D9DE08(void *p, ...);
void dcomp_func_01D9E0D8(void *p, ...);
void dcomp_func_01D9E318(void *p, ...);
void dcomp_func_01D9EC84(void *p, ...);
void dcomp_func_01D9FBCC(void *p, ...);
void dcomp_func_01DA0748(void *p, ...);
void dcomp_func_01DA0910(void *p, ...);
void dcomp_func_01DA0F24(void *p, ...);
void dcomp_func_01DA117C(void *p, ...);
void dcomp_func_01DA17D8(void *p, ...);
void dcomp_func_01DA1C18(void *p, ...);

#endif /* DCOMP_OVERLAY_H */
