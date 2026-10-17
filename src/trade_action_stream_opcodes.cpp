#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };
union StagingPtr { unsigned char bytes[4]; unsigned char *ptr; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern StagingPtr D_004E2DA4;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern int D_004E3070, D_004E3084, D_004E3088;

void func_00181e40() {
    D_004E2DA0.word = 0;
    unsigned char ch = *D_004E2DB0++;
    D_004E2DA0.bytes[0] = ch;
    D_004E2DA8 = D_004E2DA0.word;
    D_004E2DA0.word &= 0xF;

    switch (D_004E2DA0.word) {
        case 0:
            D_004E2DA8 >>= 2;
            D_004E2DB0 += D_004E2DA8;
            break;
        case 1:
            D_004E2DA8 >>= 2;
            break;
        case 2:
            D_004E2DA8 <<= 4;
            D_004E2DA8 |= *D_004E2DB0++;
            D_004E2DB0 += D_004E2DA8;
            break;
        case 3:
            D_004E2DA8 <<= 4;
            D_004E2DA8 |= *D_004E2DB0++;
            break;
        case 4:
            D_004E2DA8 >>= 4;
            D_004E3070 = D_004E2DA8;
            if (D_004E3070 == 0) {
                D_004E2DA8 = *D_004E2DB0++;
            }
            D_004E2DB0 += D_004E2DA8;
            D_004E3070 = (int)D_004E2DB0;
            break;
        case 5:
            D_004E2DA8 >>= 4;
            D_004E3070 = D_004E2DA8;
            if (D_004E3070 == 0) {
                D_004E2DA8 = *D_004E2DB0++;
            }
            D_004E2DB0++;
            break;
        case 6:
            D_004E2DA8 >>= 4;
            D_004E3070 = D_004E2DA8;
            if (D_004E3070 == 0) {
                D_004E2DA8 = *D_004E2DB0++;
            }
            break;
        default: {
            D_004E2DA0.word = D_004E2DA8;
            D_004E2DA0.word >>= 4;
            switch (D_004E2DA0.word) {
                case 0: case 1: case 2:
                    D_004E2DA8 = 0;
                    break;
                case 3:
                    D_004E2DA8 = 1;
                    break;
                case 4:
                    D_004E2DA8 = *D_004E2DB0++;
                    break;
                case 5:
                    D_004E2DA8 = *D_004E2DB0;
                    D_004E2DB0 += 1;
                    D_004E2DA8 <<= 1;
                    D_004E2DB0 += D_004E2DA8 - 1;
                    break;
                default:
                    D_004E2DA8 = 0;
                    break;
            }
            break;
        }
    }
}

void func_001820a0(int val) {
    if ((val & 1) != 0) {
        D_004E3088 = 2;
    } else {
        D_004E3088 = 4;
    }
}

void func_001820c0(int val) {
    D_004E3084 = val;
}
}
