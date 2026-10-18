#pragma exceptions off
#include "unit_action_build_7c390.h"

extern "C" {
    void func_1C1350(void *self, int category, int index, int code);
}

struct ActionCodeMapping {
    int category;
    int index;
    int code;
};

static const ActionCodeMapping s_mappings[113] = {
    {1, 20, 0x4a3c},
    {1, 21, 0x4a3d},
    {1, 22, 0x4a4f},
    {1, 41, 0x4a7c},
    {1, 23, 0x4a50},
    {1, 24, 0x4d18},
    {1, 25, 0x4a51},
    {1, 26, 0x4a52},
    {1, 27, 0x4a53},
    {1, 28, 0x4a54},
    {1, 29, 0x4a55},
    {1, 30, 0x4b44},
    {1, 31, 0x4b45},
    {1, 32, 0x4b46},
    {1, 33, 0x4b47},
    {1, 34, 0x4b48},
    {1, 35, 0x4b49},
    {1, 36, 0x4b4a},
    {1, 37, 0x4b4b},
    {1, 38, 0x4b4c},
    {1, 39, 0x4b4d},
    {1, 42, 0x4b59},
    {1, 43, 0x4b5a},
    {1, 44, 0x4b5b},
    {1, 45, 0x4b5c},
    {1, 46, 0x4b5d},
    {1, 47, 0x4b5e},
    {1, 48, 0x4b5f},
    {1, 51, 0x4b62},
    {1, 53, 0x4b64},
    {1, 54, 0x4b65},
    {1, 55, 0x4b7b},
    {0, 0, 0x4b0e},
    {0, 1, 0x4b0f},
    {0, 2, 0x4b18},
    {0, 5, 0x4b10},
    {0, 6, 0x4b19},
    {0, 7, 0x4b29},
    {0, 8, 0x4b2a},
    {0, 9, 0x4b15},
    {0, 10, 0x4b16},
    {0, 11, 0x4a44},
    {0, 12, 0x4a38},
    {0, 13, 0x4a3a},
    {0, 14, 0x4b14},
    {2, 0, 0x4a3e},
    {2, 1, 0x4a3f},
    {2, 0, 0x4a40},
    {2, 3, 0x4a41},
    {3, 0, 0x4b0d},
    {3, 1, 0x4b24},
    {3, 2, 0x4a77},
    {3, 0, 0x4a7b},
    {3, 4, 0x4a78},
    {3, 5, 0x4b0a},
    {3, 6, 0x4b25},
    {3, 7, 0x4b0b},
    {3, 8, 0x4b01},
    {3, 9, 0x4b04},
    {3, 20, 0x4a7a},
    {3, 10, 0x4b40},
    {3, 12, 0x4b00},
    {3, 13, 0x4a76},
    {3, 14, 0x4b06},
    {3, 15, 0x4a79},
    {3, 16, 0x4b26},
    {3, 17, 0x4b05},
    {3, 18, 0x4b08},
    {3, 19, 0x4b09},
    {3, 23, 0x4b53},
    {3, 24, 0x4b58},
    {3, 25, 0x4b02},
    {3, 26, 0x4b03},
    {3, 27, 0x4b2b},
    {4, 0, 0x4a6e},
    {4, 6, 0x4b77},
    {4, 7, 0x4b7c},
    {5, 0, 0x4a65},
    {5, 1, 0x4a64},
    {5, 2, 0x4a73},
    {5, 3, 0x4a6f},
    {5, 0, 0x4b50},
    {5, 4, 0x4b4f},
    {5, 7, 0x4b54},
    {5, 8, 0x4b78},
    {6, 0, 0x4a5b},
    {6, 1, 0x4a5a},
    {7, 0, 0x4a5e},
    {7, 1, 0x4a63},
    {7, 2, 0x4a60},
    {7, 3, 0x4a61},
    {8, 0, 0x4a74},
    {8, 1, 0x4a57},
    {8, 2, 0x4a56},
    {9, 0, 0x4a70},
    {9, 2, 0x4b55},
    {9, 3, 0x4a67},
    {9, 1, 0x4a69},
    {10, 0, 0x4a6b},
    {11, 0, 0x4b56},
    {12, 5, 0x4b70},
    {12, 6, 0x4b71},
    {12, 7, 0x4b72},
    {12, 8, 0x4b73},
    {12, 9, 0x4b74},
    {12, 10, 0x4b75},
    {12, 11, 0x4b76},
    {12, 1, 0x4b67},
    {12, 2, 0x4b68},
    {12, 3, 0x4b69},
    {12, 4, 0x4b6a},
    {13, 0, 0x4b79},
    {13, 1, 0x4b7a},
};

#ifdef UNIT_TEST
static ActionCodeMapping s_mutable_mappings[113];
static bool s_initialized_mutable = false;

extern "C" {
    void func_0027C390_mutate_mapping(int i, int category, int index, int code) {
        if (!s_initialized_mutable) {
            for (int j = 0; j < 113; ++j) {
                s_mutable_mappings[j] = s_mappings[j];
            }
            s_initialized_mutable = true;
        }
        if (i >= 0 && i < 113) {
            s_mutable_mappings[i].category = category;
            s_mutable_mappings[i].index = index;
            s_mutable_mappings[i].code = code;
        }
    }
    void func_0027C390_reset_mapping() {
        s_initialized_mutable = false;
    }
}
#endif

void func_0027C390(void *self) {
#ifdef UNIT_TEST
    const ActionCodeMapping *mappings = s_initialized_mutable ? s_mutable_mappings : s_mappings;
#else
    const ActionCodeMapping *mappings = s_mappings;
#endif
    for (int i = 0; i < 113; ++i) {
        func_1C1350(self, mappings[i].category, mappings[i].index, mappings[i].code);
    }
}

void func_27C390(void *self) {
    func_0027C390(self);
}
