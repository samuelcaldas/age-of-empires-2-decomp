#ifndef PS2_INPUT_MULTIPLEXER_H
#define PS2_INPUT_MULTIPLEXER_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * func_0036D5F0: Unified Input Multiplexer
 * Combines Gamepad buttons (ktPadGetButtons), Mouse buttons, and USB Keyboard
 * modifiers (func_0036DF30) into unified output flag mask at *out_flags.
 * Matches AOK.ELF 0x0036D5F0 - 0x0036D700 (272 bytes)
 */
void func_0036D5F0(int *out_flags);

#ifdef __cplusplus
}
#endif

#endif /* PS2_INPUT_MULTIPLEXER_H */
