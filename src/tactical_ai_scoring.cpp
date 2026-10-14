extern "C" {
    extern const char D_490E9C[];
    int func_142980(void *self);
    void func_144340(void *self, int code, int param);
    void* func_11A7BC(char *dst, const char *src);
    void* func_21A4A0(int token);

    int func_00142830(void *self);
    int func_001428B0(void *self, char *str);
}

struct TacticalAIScoring {
    char pad_00[0x19C];
    int m_field19C;
    char pad_1A0[0x6B8 - 0x1A0];
    unsigned short *m_tokens;
    int m_token_idx;
};

int func_00142830(void *self) {
    TacticalAIScoring *ai = (TacticalAIScoring*)self;
    int res = func_142980(ai);
    if (res != 2) {
        if (res == 1) {
            func_144340(ai, 0x1A, 0);
        }
    } else {
        if (ai->m_field19C != 1) {
            func_144340(ai, 0x10, 0);
        }
    }
    return 0;
}

int func_001428B0(void *self, char *str) {
    TacticalAIScoring *ai = (TacticalAIScoring*)self;
    int idx = ai->m_token_idx;
    unsigned short *ptr = ai->m_tokens + idx;
    *str = 0;
    while (1) {
        if (*ptr == 0xFFFF) {
            return 0;
        }
        if (*ptr == 0xFFFE) {
            func_11A7BC(str, D_490E9C);
            ai->m_token_idx++;
            return 1;
        }
        func_11A7BC(str, (char*)func_21A4A0(*ptr));
        ptr++;
        ai->m_token_idx++;
    }
}
