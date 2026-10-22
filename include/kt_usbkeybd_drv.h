#ifndef KT_USBKEYBD_DRV_H
#define KT_USBKEYBD_DRV_H

typedef struct {
    char pad[0x24];
    unsigned int status;
} UsbKeybdDevice;

int func_00137208(void);
int func_00137250(void *info);
int func_001372C0(int a0, void *data);
int func_00137340(int a0, void *location);
int func_001373C0(unsigned char a0, unsigned char a1);
int func_00137420(unsigned char a0, unsigned char a1);

#endif /* KT_USBKEYBD_DRV_H */
