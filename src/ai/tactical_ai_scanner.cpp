#include "sub_list.h"

#pragma exceptions off

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x198];
    int field_19C;
    char field_1A0[0x100];
    char *field_2A0;
    char pad_2A4[4];
    char field_2A8[0x400];
    char *field_6A8;
    char pad_6AC[4];
    int field_6B0;
};

extern "C" {

int func_001428B0(TacticalAI2 *self, char *buf);
void func_144340(TacticalAI2 *self, int a1, int a2);

int func_142980(TacticalAI2 *self) {
    self->field_2A0 = self->field_1A0;
    *self->field_2A0 = '\0';
    self->field_19C = 0;

    int done_outer = 0;
    while (!done_outer) {
        char *cur = self->field_6A8;
        char ch = *cur;
        if (ch == '"') goto L_quote;
        if (ch == '\0') goto L_comment;
        if (ch == ';') goto L_comment;
        if (ch == ')') goto L_rparen;
        if (ch == '(') goto L_lparen;
        if (ch == '\r') goto L_space;
        if (ch == '\n') goto L_space;
        if (ch == '\t') goto L_space;
        if (ch == ' ') goto L_space;
        self->field_6A8 = cur + 1;
        goto L_default;

    L_space:
        self->field_6A8++;
        continue;

    L_lparen:
        self->field_6A8 = cur + 1;
        *self->field_2A0++ = *cur;
        *self->field_2A0 = '\0';
        self->field_19C = 2;
        return 2;

    L_rparen:
        self->field_6A8 = cur + 1;
        *self->field_2A0++ = *cur;
        *self->field_2A0 = '\0';
        self->field_19C = 3;
        return 2;

    L_comment:
        self->field_6B0++;
        if (!func_001428B0(self, self->field_2A8)) {
            return 1;
        }
        self->field_6A8 = self->field_2A8;
        continue;

    L_quote:
        self->field_6A8 = cur + 1;
        self->field_19C = 4;
        done_outer = 1;
        continue;

    L_default:
        *self->field_2A0++ = *cur;
        self->field_19C = 1;
        done_outer = 1;
        continue;
    }

    if (self->field_19C == 1) {
        int done = 0;
        while (!done) {
            char *cur = self->field_6A8;
            char ch = *cur;
            if (ch == ';') goto L_id_stop_semi;
            if (ch == '\0') goto L_id_stop;
            if (ch == ')') goto L_id_stop;
            if (ch == '(') goto L_id_stop;
            if (ch == '\r') goto L_id_space;
            if (ch == '\n') goto L_id_space;
            if (ch == '\t') goto L_id_space;
            if (ch == ' ') goto L_id_space;
            self->field_6A8 = cur + 1;
            goto L_id_char;

        L_id_space:
            self->field_6A8++;
            done = 1;
            continue;

        L_id_stop:
            done = 1;
            continue;

        L_id_stop_semi:
            done = 1;
            continue;

        L_id_char:
            *self->field_2A0++ = *cur;
            continue;
        }
    } else {
        int done = 0;
        while (!done) {
            char *cur = self->field_6A8;
            char ch = *cur;
            if (ch == '"') goto L_str_quote;
            if (ch == '\0') goto L_str_err_eof;
            if (ch == '\n') goto L_str_err_nl;
            self->field_6A8 = cur + 1;
            goto L_str_char;

        L_str_err_nl:
        L_str_err_eof:
            func_144340(self, 9, 0);
            return 0;

        L_str_quote:
            self->field_6A8 = cur + 1;
            done = 1;
            continue;

        L_str_char:
            *self->field_2A0++ = *cur;
            continue;
        }
    }

    *self->field_2A0 = '\0';
    return 2;
}

}
