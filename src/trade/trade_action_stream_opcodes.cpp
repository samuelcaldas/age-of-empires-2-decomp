#pragma exceptions off

union BufferWord {
    unsigned char bytes[4];
    unsigned int word;
};

extern "C" {
extern BufferWord D_004E2DA0;
extern BufferWord D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern int D_004E3070, D_004E3084, D_004E3088;

void func_00181E40() {
    D_004E2DA0.word = 0;
    D_004E2DA0.bytes[0] = *D_004E2DB0++;
    D_004E2DA8.word = D_004E2DA0.word;
    D_004E2DA0.word &= 0xF;

    switch (D_004E2DA0.word) {
        case 0:
        case 4:
        case 8:
        case 12:
            D_004E2DA8.word >>= 2;
            D_004E2DB0 += D_004E2DA8.word;
            break;

        case 1:
        case 5:
        case 9:
        case 13:
            D_004E2DA8.word >>= 2;
            break;

        case 2:
            D_004E2DA8.word <<= 4;
            D_004E2DA8.bytes[0] = *D_004E2DB0++;
            D_004E2DB0 += D_004E2DA8.word;
            break;

        case 3:
            D_004E2DA8.word <<= 4;
            D_004E2DA8.bytes[0] = *D_004E2DB0++;
            break;

        case 6:
            D_004E2DA8.word >>= 4;
            D_004E3070 = D_004E2DA8.word;
            if (D_004E3070 == 0) {
                D_004E2DA8.bytes[0] = *D_004E2DB0++;
            }
            D_004E2DB0 += D_004E2DA8.word;
            D_004E3070 = (int)D_004E2DB0;
            break;

        case 7:
        case 10:
            D_004E2DA8.word >>= 4;
            D_004E3070 = D_004E2DA8.word;
            if (D_004E3070 == 0) {
                D_004E2DA8.bytes[0] = *D_004E2DB0++;
            }
            D_004E2DB0++;
            break;

        case 11:
            D_004E2DA8.word >>= 4;
            D_004E3070 = D_004E2DA8.word;
            if (D_004E3070 == 0) {
                D_004E2DA8.bytes[0] = *D_004E2DB0++;
            }
            break;

        case 14:
            D_004E2DA0.word = D_004E2DA8.word;
            D_004E2DA0.word >>= 4;
            switch (D_004E2DA0.word) {
                case 0:
                case 1:
                case 2:
                case 3:
                    D_004E2DA8.word = 0;
                    break;
                case 4:
                case 6:
                    D_004E2DA8.word = 1;
                    break;
                case 5:
                case 7:
                    D_004E2DA8.bytes[0] = *D_004E2DB0++;
                    break;
                case 8: {
                    D_004E2DA8.bytes[0] = *D_004E2DB0++;
                    unsigned int a1 = D_004E2DA8.word;
                    D_004E2DA8.word = a1 + a1;
                    D_004E2DB0 += a1;
                    D_004E2DA8.word -= 1;
                    break;
                }
                default:
                    D_004E2DA8.word = 0;
                    break;
            }
            break;

        default:
            D_004E2DA8.word = 0;
            break;
    }
}

void func_001820A0(int val) {
    switch (val & 1) {
        case 0:
            D_004E3088 = 2;
            break;
        default:
            D_004E3088 = 4;
            break;
    }
}

void func_001820C0(int val) {
    D_004E3084 = val;
}
}
