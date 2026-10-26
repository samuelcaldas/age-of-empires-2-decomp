#ifndef KT_SOUND_H
#define KT_SOUND_H

#include <stddef.h>
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* SIF RPC services used by KCET Sound */
#define KT_SOUND_SIF_SDCD_DEV 0x00000020
#define KT_SOUND_SIF_SDD_DEV  0x00000030

/* SDD Status Query response codes */
#define SDD_STATUS_BUSY  1
#define SDD_STATUS_READY 4

/* SifRpcClientData structure layout (PS2 EE libcdvd/libpad/sifrpc standard: 64 bytes) */
typedef struct SifRpcClientData {
    void *header;          /* +0x00 */
    u32 command;           /* +0x04 */
    void *buff;            /* +0x08 */
    void *gp;              /* +0x0C */
    void *func;            /* +0x10 */
    void *para;            /* +0x14 */
    void *serve;           /* +0x18 */
    u32 pad[9];            /* +0x1C .. +0x40 (total 64 bytes) */
} SifRpcClientData;

_Static_assert(sizeof(SifRpcClientData) == 64, "SifRpcClientData size");

/* SIF RPC Communication Layer (0x0012D648 - 0x0012D888) */
int func_0012D648(void);
int func_0012D7E0(const char *name);
int func_0012D840(int cmd);
int func_0012D888(void);

/* Sound Synchronization & Multi-stage Init (0x00220F70 - 0x00220FF0) */
int func_00220F70(void);
int func_00220FF0(void);

/* Sound Channel & Dispatch Management (0x0025D060 - 0x0025D600) */
int func_0025D060(int cmd);
int func_0025D320(int channel, int volume);
int func_0025D430(int cmd);
int func_0025D540(void);

#ifdef __cplusplus
}
#endif

#endif /* KT_SOUND_H */
