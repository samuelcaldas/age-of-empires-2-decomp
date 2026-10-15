#pragma exceptions off

union StreamStagingWord {
    unsigned char bytes[4];
    int word;
};

extern "C" {
extern StreamStagingWord D_004E2DA0;
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

/** Emit a masked two-byte phase followed by a three-byte phase. */
void func_0015CE90() {
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    stage_masked_input(3, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
}

/** Emit a masked byte at staging index one followed by a four-byte phase. */
void func_0015CF90() {
    D_004E2DA0.bytes[1] = *D_004E2DB0++;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    stage_masked_input(4, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
}

/** Emit a masked four-byte phase followed by a two-byte phase. */
void func_0015D090() {
    stage_masked_input(4, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
}

/** Emit three offset staging bytes followed by a masked three-byte phase. */
void func_0015D1B0() {
    stage_masked_input(3, -1);
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
    stage_masked_input(3, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
}

/** Emit a masked two-byte phase followed by a four-byte phase. */
void func_0015D2D0() {
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    stage_masked_input(4, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
}
}
