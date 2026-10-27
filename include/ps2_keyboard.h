#ifndef PS2_KEYBOARD_H
#define PS2_KEYBOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#define VK_BACK       0x08
#define VK_TAB        0x09
#define VK_RETURN     0x0D
#define VK_SHIFT      0x10
#define VK_CONTROL    0x11
#define VK_MENU       0x12
#define VK_PAUSE      0x13
#define VK_CAPITAL    0x14
#define VK_ESCAPE     0x1B
#define VK_SPACE      0x20
#define VK_LWIN       0x5B
#define VK_RWIN       0x5C

/* Scancode translation table from AOK.ELF 0x0048A470 */
extern const unsigned short g_usb_scancode_table[256];

/* Active modifier states in memory at AOK.ELF 0x0048A280-0x0048A282 */
extern unsigned char g_keybd_shift_state;
extern unsigned char g_keybd_ctrl_state;
extern unsigned char g_keybd_alt_state;
extern unsigned char g_keybd_modifier_byte;

/* Active key pressed state array at AOK.ELF 0x0048A270 */
extern unsigned char g_key_pressed_state[256];

/* Repeat key tracking in gp storage */
extern unsigned short s_repeat_key;
extern unsigned int s_repeat_time;

/* Win32 GetAsyncKeyState implementation for PS2 USB keyboard (0x0036DF30) */
int func_0036DF30(int vkey);

/* USB HID modifier byte evaluator (0x0036DFB0) */
int func_0036DFB0(int mode);

/* Scancode translation and layout mapping (0x0036E010) */
int func_0036E010(int scancode);

/* Key-down event processor (0x0036E0A8) */
void func_0036E0A8(int scancode);

/* Typematic key repeat handler (0x0036E160) */
void func_0036E160(void);

/* Key-up event detector (0x0036E1F0) */
void func_0036E1F0(const unsigned char *current_packet);

/* Modifier transition and LED update (0x0036E350) */
void func_0036E350(void);

/* Packet polling loop (0x0036E510) */
int func_0036E510(int reset_flag);

/* Subsystem update tick (0x0036E5E0) */
int func_0036E5E0(void);

#ifdef __cplusplus
}
#endif

#endif /* PS2_KEYBOARD_H */
