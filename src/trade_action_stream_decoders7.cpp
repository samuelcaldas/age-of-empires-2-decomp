#pragma exceptions off

union StreamStagingWord {
    unsigned char bytes[4];
    int word;
};

extern "C" {
extern StreamStagingWord D_004E2DA0;
extern int D_004E2DA8;
extern int D_004E30A8;
extern int D_004E30B0;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *destination, unsigned char *source);

static inline void stage_masked_input(int input_advance, int source_offset) {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 + source_offset);
    D_004E2DB0 = D_004E2DB0 + input_advance;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
}

static inline void emit_staging_word() {
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
}

/** Continuous 4-byte block copy loop decremented by 4 until counter reaches zero. */
void func_0015DA70() {
    do {
        stage_masked_input(4, 0);
        emit_staging_word();
    } while (D_004E2DA8 -= 4);
}

/** 1-byte prefix staging followed by continuous 4-byte block copy loop. */
void func_0015DB30() {
    D_004E2DA0.bytes[1] = *D_004E2DB0++;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    D_004E2DA8 -= 1;

    do {
        stage_masked_input(4, 0);
        emit_staging_word();
    } while (D_004E2DA8 -= 4);
}

/** 2-byte prefix staging followed by continuous 4-byte block copy loop. */
void func_0015DC50() {
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    D_004E2DA8 -= 2;

    do {
        stage_masked_input(4, 0);
        emit_staging_word();
    } while (D_004E2DA8 -= 4);
}

/** Offset -1 3-byte prefix staging followed by continuous 4-byte block copy loop. */
void func_0015DD80() {
    stage_masked_input(3, -1);
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
    D_004E2DA8 -= 3;

    do {
        stage_masked_input(4, 0);
        emit_staging_word();
    } while (D_004E2DA8 -= 4);
}

/** Counter decrement, continuous 4-byte block copy loop, and 1-byte trailer. */
void func_0015DED0() {
    D_004E2DA8 -= 1;

    do {
        stage_masked_input(4, 0);
        emit_staging_word();
    } while (D_004E2DA8 -= 4);

    D_004E2DA0.bytes[0] = *D_004E2DB0++;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
}
}
