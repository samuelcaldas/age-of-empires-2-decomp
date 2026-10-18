#pragma exceptions off
#include "unit_action_build_7e110.h"

extern "C" {
    int func_1C14D0(void *self, int category);
    int func_001C0F90(void *self, int category, int index, unsigned char *f1, unsigned char *f2, unsigned char *f3);
}

int func_0027E110(void *self, int *out_cat, int expected_res, int expected_f2, int expected_f1, int expected_f3) {
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;

    if (out_cat == 0) {
        return 0;
    }

    int count = func_1C14D0(self, *out_cat);

    if (*out_cat != 1) {
        for (int i = 0; i < count; ++i) {
            unsigned char res = func_001C0F90(self, *out_cat, i, &f1, &f2, &f3);
            if (res == expected_res &&
                expected_f2 == f2 && f1 == expected_f1 && expected_f3 == f3) {
                return i;
            }
        }

        for (int i = 0; i < 56; ++i) {
            unsigned char res = func_001C0F90(self, 1, i, &f1, &f2, &f3);
            if (res == expected_res &&
                expected_f2 == f2 && f1 == expected_f1 && expected_f3 == f3) {
                *out_cat = 1;
                return i;
            }
        }

        for (int i = 0; i < 16; ++i) {
            unsigned char res = func_001C0F90(self, 2, i, &f1, &f2, &f3);
            if (res == expected_res &&
                expected_f2 == f2 && f1 == expected_f1 && expected_f3 == f3) {
                *out_cat = 2;
                return i;
            }
        }
    } else {
        for (int cat = 0; cat < 14; ++cat) {
            if (cat == 1) {
                continue;
            }
            int cat_count = func_1C14D0(self, cat);
            for (int i = 0; i < cat_count; ++i) {
                unsigned char res = func_001C0F90(self, cat, i, &f1, &f2, &f3);
                if (res == expected_res &&
                    expected_f2 == f2 && f1 == expected_f1 && expected_f3 == f3) {
                    *out_cat = cat;
                    return i;
                }
            }
        }

        for (int i = 0; i < 56; ++i) {
            unsigned char res = func_001C0F90(self, 1, i, &f1, &f2, &f3);
            if (res == expected_res &&
                expected_f2 == f2 && f1 == expected_f1 && expected_f3 == f3) {
                *out_cat = 1;
                return i;
            }
        }

        for (int i = 0; i < 16; ++i) {
            unsigned char res = func_001C0F90(self, 2, i, &f1, &f2, &f3);
            if (res == expected_res &&
                expected_f2 == f2 && f1 == expected_f1 && expected_f3 == f3) {
                *out_cat = 2;
                return i;
            }
        }
    }

    return -1;
}
