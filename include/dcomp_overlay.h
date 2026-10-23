/* PS2 DCOMP_CD.BIN Overlay Header */
#ifndef DCOMP_OVERLAY_H
#define DCOMP_OVERLAY_H

#include "common.h"

#define DCOMP_DATA_WORD_COUNT 976
#define DCOMP_DATA_BYTE_SIZE (DCOMP_DATA_WORD_COUNT * 4)

extern const unsigned int dcomp_data[DCOMP_DATA_WORD_COUNT];

/* All 71 DCOMP Overlay Functions */
void *dcomp_func_01D98000(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98024(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9805C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98084(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98110(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D981F4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D983FC(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98520(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9862C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D987D4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98A40(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98A78(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98AF0(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98BFC(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98CE4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D98FCC(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D990F0(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9911C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D991B4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D99290(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D995F8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D99840(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D99B00(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D99B44(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D99D9C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9A248(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9A2D4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9AAD8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9B09C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9B744(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9B7B4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9B910(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BA78(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BC5C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BE50(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BE70(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BF88(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BFA8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9BFC8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C02C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C058(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C088(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C0C8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C11C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C138(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C190(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C1E8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C23C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9C27C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9CC54(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9CD90(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9CF04(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D048(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D184(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D26C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D320(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D40C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D588(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9D6C4(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9DB3C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9DE08(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9E0D8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9E318(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9EC84(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01D9FBCC(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01DA0748(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01DA0910(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01DA0F24(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01DA117C(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01DA17D8(void *a0, void *a1, void *a2, void *a3);
void *dcomp_func_01DA1C18(void *a0, void *a1, void *a2, void *a3);

#endif /* DCOMP_OVERLAY_H */
