#ifndef PS2_OSK_H
#define PS2_OSK_H

#ifdef __cplusplus
extern "C" {
#endif

#define OSK_MAX_ROWS 4
#define OSK_MAX_COLS 10

typedef struct {
    char buffer[64];
    int cursor_pos;
    int max_len;
    int cursor_row;
    int cursor_col;
    int shift_mode; /* 1 = uppercase, 0 = lowercase */
    int active;
} OSKState;

void OSK_Init(OSKState *state, int max_len);
int OSK_ProcessInput(OSKState *state, unsigned short pad_buttons, unsigned short pad_pressed);
void OSK_DirectTypingInput(OSKState *state, char c);
int OSK_IsKeyboardActive(void);

#ifdef __cplusplus
}
#endif

#endif /* PS2_OSK_H */
