#pragma exceptions off

#include "zone_screen_to_world.h"

extern "C" {
typedef long long int64_t;

int64_t func_122690(int x);
int64_t func_1223C0(int64_t a, int64_t b);
int64_t func_122118(int64_t a, int64_t b);
int64_t func_1220B0(int64_t a, int64_t b);
int64_t func_122058(int64_t a, int64_t b);
int func_100120(int64_t a, int64_t b);
int func_100170(int64_t a, int64_t b);
float func_1228E8(int64_t a);
int64_t func_1234E0(float f);
}

// 64-bit IEEE double constants used in Fixed calculations
static const int64_t FP_HALF  = 0x3FE0000000000000LL; // 0.5
static const int64_t FP_ONE   = 0x3FF0000000000000LL; // 1.0
static const int64_t FP_TWO   = 0x4000000000000000LL; // 2.0
static const int64_t FP_NEG2  = 0xC000000000000000LL; // -2.0
static const int64_t FP_NEG1  = 0xBFF0000000000000LL; // -1.0
static const int64_t FP_SIGN  = 0x8000000000000000LL; // sign bit

struct CmdPacket {
    char pad[4];
    unsigned char cmd;
};

extern "C" void func_001CEA60(
    void *self,
    int screen_x,
    int screen_y,
    void *cmd_pkt,
    float *out_y,
    float *out_x
) {
    char *zm = (char *)self;
    int scale_x = *(short *)(zm + 0x8EAE);
    int scale_y = *(short *)(zm + 0x8EB0);

    int64_t fx = func_1223C0(func_122690(screen_x), func_122690(scale_x));
    int64_t fy = func_1223C0(func_122690(screen_y), func_122690(scale_y));

    unsigned char cmd = ((CmdPacket *)cmd_pkt)->cmd;
    if (cmd > 16) {
        return;
    }

    int64_t s2 = 0;
    int64_t s5_fp;

    switch (cmd) {
    case 0:
        s2 = 0;
        break;
    case 1:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_1220B0(func_122118(FP_TWO, fy), func_122118(FP_TWO, func_1220B0(fx, FP_HALF)));
        } else {
            s2 = func_1220B0(func_122118(FP_TWO, fy), func_122118(FP_TWO, func_1220B0(FP_HALF, fx)));
        }
        break;
    case 2:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_1220B0(func_1223C0(fx, FP_NEG2), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_NEG2), func_1220B0(fy, FP_HALF));
        }
        break;
    case 3:
        s5_fp = func_122690(screen_y);
        if (func_100120(func_1223C0(fx, FP_TWO), s5_fp)) {
            s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_TWO), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_122058(func_1220B0(func_122118(FP_TWO, func_1220B0(FP_ONE, fx)), FP_ONE), func_122118(FP_TWO, fy));
        }
        break;
    case 4:
        s5_fp = func_122690(screen_y);
        if (func_100120(func_1223C0(func_1220B0(FP_ONE, fx), FP_TWO), s5_fp)) {
            s2 = func_1220B0(func_1223C0(fx, FP_TWO), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_122058(func_1220B0(func_122118(FP_TWO, fx), FP_ONE), func_122118(FP_TWO, fy));
        }
        break;
    case 5:
        s2 = func_122058(func_1220B0(FP_ONE, func_122118(FP_TWO, fx)), func_122118(FP_TWO, fy));
        break;
    case 6:
        s2 = func_1220B0(func_1223C0(fx, FP_NEG2), func_1220B0(fy, FP_HALF));
        break;
    case 7:
        s2 = func_122058(func_1220B0(func_122118(FP_TWO, fx), FP_ONE), func_122118(FP_TWO, fy));
        break;
    case 8:
        s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_NEG2), func_1220B0(fy, FP_HALF));
        break;
    case 9:
        s2 = FP_TWO;
        break;
    case 10:
        if (func_100120(fy, FP_ONE)) {
            s2 = fy ^ FP_SIGN;
        } else {
            s2 = FP_NEG1;
        }
        break;
    case 11:
        if (func_100170(fx, FP_HALF)) {
            s2 = 0;
        } else {
            s2 = func_122118(FP_TWO, func_1220B0(FP_HALF, fx));
        }
        break;
    case 12:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_122118(FP_TWO, func_1220B0(fx, FP_HALF));
        } else {
            s2 = 0;
        }
        break;
    case 13:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_122058(func_122118(FP_TWO, fy), func_122118(FP_TWO, func_1220B0(fx, FP_HALF)));
        } else {
            s2 = func_122058(func_122118(FP_TWO, fy), func_122118(FP_TWO, func_1220B0(FP_HALF, fx)));
        }
        break;
    case 14:
        if (func_100170(fx, FP_HALF)) {
            s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_NEG2), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_1220B0(func_1223C0(fx, FP_NEG2), func_1220B0(fy, FP_HALF));
        }
        break;
    case 15:
        s5_fp = func_122690(screen_y);
        if (func_100170(s5_fp, func_1220B0(FP_ONE, func_1223C0(fx, FP_TWO)))) {
            s2 = func_1220B0(func_1223C0(func_1220B0(FP_ONE, fx), FP_NEG2), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_122058(func_1220B0(func_122118(FP_TWO, fx), FP_ONE), func_122118(FP_TWO, fy));
        }
        break;
    case 16:
        s5_fp = func_122690(screen_y);
        if (func_100170(func_1220B0(FP_ONE, func_1223C0(func_1220B0(FP_ONE, fx), FP_TWO)), s5_fp)) {
            s2 = func_1220B0(func_1223C0(fx, FP_NEG2), func_1220B0(fy, FP_HALF));
        } else {
            s2 = func_122058(func_1220B0(FP_ONE, func_122118(FP_TWO, fx)), func_122118(FP_TWO, fy));
        }
        break;
    }

    s2 = func_122058(s2, func_122118(FP_TWO, fy));
    int64_t sum_term = func_122058(func_122118(func_1220B0(func_122118(FP_TWO, fy), FP_ONE), fx), s2);
    int64_t x_fp = func_1223C0(sum_term, FP_TWO);

    *out_x = func_1228E8(x_fp);
    *out_y = func_1228E8(func_1220B0(fx, func_1234E0(*out_x)));
}
