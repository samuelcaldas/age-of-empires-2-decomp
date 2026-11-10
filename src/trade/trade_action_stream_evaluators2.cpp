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

void func_0015C920() {
    stage_masked_input(4, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
}

void func_0015C9D0() {
    stage_masked_input(3, -1);
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
    D_004E2DA0.bytes[0] = *D_004E2DB0++;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
}

void func_0015CAC0() {
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
}

void func_0015CBB0() {
    D_004E2DA0.bytes[1] = *D_004E2DB0++;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    stage_masked_input(3, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
}

void func_0015CC90() {
    stage_masked_input(4, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
    D_004E2DA0.bytes[0] = *D_004E2DB0++;
    D_004E2DA0.word = D_004E2DA0.word & D_004E30A8;
    D_004E2DA0.word = D_004E2DA0.word | D_004E30B0;
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
}

void func_0015CD90() {
    stage_masked_input(3, -1);
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
    *D_004E2DB4++ = D_004E2DA0.bytes[2];
    *D_004E2DB4++ = D_004E2DA0.bytes[3];
    stage_masked_input(2, 0);
    *D_004E2DB4++ = D_004E2DA0.bytes[0];
    *D_004E2DB4++ = D_004E2DA0.bytes[1];
}

}
