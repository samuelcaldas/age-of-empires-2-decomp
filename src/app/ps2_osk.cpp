#include <string.h>
#include "ps2_osk.h"
#include "kt_libpad.h"

#ifdef __cplusplus
extern "C" {
#endif

int func_2263F0(int msg, int wParam, int lParam);
int func_136230(int port);

/* Standard 4x10 On-Screen Keyboard character layout */
static const char s_osk_matrix_upper[OSK_MAX_ROWS][OSK_MAX_COLS] = {
    {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
    {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', '-'},
    {'Z', 'X', 'C', 'V', 'B', 'N', 'M', '.', '_', ' '}
};

static const char s_osk_matrix_lower[OSK_MAX_ROWS][OSK_MAX_COLS] = {
    {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '-'},
    {'z', 'x', 'c', 'v', 'b', 'n', 'm', '.', '_', ' '}
};

void OSK_Init(OSKState *state, int max_len) {
    if (!state) {
        return;
    }
    memset(state, 0, sizeof(OSKState));
    state->max_len = (max_len > 0 && max_len < 64) ? max_len : 63;
    state->cursor_row = 0;
    state->cursor_col = 0;
    state->shift_mode = 1; // Default to Uppercase
    state->active = 1;
}

int OSK_ProcessInput(OSKState *state, unsigned short pad_buttons, unsigned short pad_pressed) {
    (void)pad_buttons;
    if (!state || !state->active) {
        return 0;
    }

    /* 1. D-Pad / Analog Navigation */
    if (pad_pressed & KT_PAD_UP) {
        state->cursor_row = (state->cursor_row + OSK_MAX_ROWS - 1) % OSK_MAX_ROWS;
    }
    if (pad_pressed & KT_PAD_DOWN) {
        state->cursor_row = (state->cursor_row + 1) % OSK_MAX_ROWS;
    }
    if (pad_pressed & KT_PAD_LEFT) {
        state->cursor_col = (state->cursor_col + OSK_MAX_COLS - 1) % OSK_MAX_COLS;
    }
    if (pad_pressed & KT_PAD_RIGHT) {
        state->cursor_col = (state->cursor_col + 1) % OSK_MAX_COLS;
    }

    /* 2. Character Input (Cross) */
    if (pad_pressed & KT_PAD_CROSS) {
        char c = state->shift_mode ?
                 s_osk_matrix_upper[state->cursor_row][state->cursor_col] :
                 s_osk_matrix_lower[state->cursor_row][state->cursor_col];
        if (state->cursor_pos < state->max_len) {
            state->buffer[state->cursor_pos++] = c;
            state->buffer[state->cursor_pos] = '\0';
            func_2263F0(0x102, c, 1); // Post WM_CHAR
        }
    }

    /* 3. Backspace (Square) */
    if (pad_pressed & KT_PAD_SQUARE) {
        if (state->cursor_pos > 0) {
            state->buffer[--state->cursor_pos] = '\0';
            func_2263F0(0x102, 0x08, 1); // Post WM_CHAR (VK_BACK)
        }
    }

    /* 4. Shift / Case Toggle (Triangle) */
    if (pad_pressed & KT_PAD_TRIANGLE) {
        state->shift_mode = !state->shift_mode;
    }

    /* 5. Confirm / Submit (Start or Circle) */
    if (pad_pressed & (KT_PAD_START | KT_PAD_CIRCLE)) {
        state->active = 0;
        return 1; // Submitted
    }

    return 0;
}

void OSK_DirectTypingInput(OSKState *state, char c) {
    if (!state) {
        return;
    }
    if (c == 0x08) { // Backspace
        if (state->cursor_pos > 0) {
            state->buffer[--state->cursor_pos] = '\0';
            func_2263F0(0x102, 0x08, 1);
        }
    } else if (state->cursor_pos < state->max_len) {
        state->buffer[state->cursor_pos++] = c;
        state->buffer[state->cursor_pos] = '\0';
        func_2263F0(0x102, c, 1);
    }
}

int OSK_IsKeyboardActive(void) {
    return func_136230(0) > 0 ? 1 : 0;
}

#ifdef __cplusplus
}
#endif
