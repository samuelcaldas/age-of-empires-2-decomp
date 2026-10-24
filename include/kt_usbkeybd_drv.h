#ifndef KT_USBKEYBD_DRV_H
#define KT_USBKEYBD_DRV_H

#include "common.h"

typedef struct {
    u8 pad[0x24];
    u32 status;
} UsbKeybdDevice;
_Static_assert(sizeof(UsbKeybdDevice) == 40, "UsbKeybdDevice size");
_Static_assert(offsetof(UsbKeybdDevice, status) == 0x24, "UsbKeybdDevice status offset");

int func_00137208(void);
int func_00137250(void *info);
int func_001372C0(int a0, void *data);
int func_00137340(int a0, void *location);
int func_001373C0(unsigned char a0, unsigned char a1);
int func_00137420(unsigned char a0, unsigned char a1);

#endif /* KT_USBKEYBD_DRV_H */
