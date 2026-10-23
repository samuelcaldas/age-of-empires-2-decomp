#include "common.h"
#include "libscf.h"

#define NULL ((void *)0)

extern const char D_4D6298[];
extern const char D_4D62A8[];
extern const char D_4D62B0[];
extern const char D_4D62C0[];
extern const char D_4D62D0[];
extern const char D_4D62E0[];

void func_114320(const char *file, int line, const char *expr);
int func_389388(sceCdCLOCK *clock);
int func_389470(void);

/* func_00389570: Decimal to BCD */
unsigned char func_00389570(unsigned char c) {
    if (c > 99) {
        func_114320(D_4D6298, 0x119, D_4D62A8);
    }
    return (unsigned char)(c + (c / 10) * 6);
}

/* func_003895D8: BCD to Decimal */
unsigned char func_003895D8(unsigned char c) {
    if (c > 0x99) {
        func_114320(D_4D6298, 0x126, D_4D62B0);
    }
    return (unsigned char)(c - (c >> 4) * 6);
}

/* func_00389630: RTC BCD to Decimal */
void func_00389630(sceCdCLOCK *prtc) {
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x132, D_4D62C0);
    }
    prtc->year   = func_003895D8(prtc->year);
    prtc->month  = func_003895D8(prtc->month);
    prtc->day    = func_003895D8(prtc->day);
    prtc->hour   = func_003895D8(prtc->hour);
    prtc->minute = func_003895D8(prtc->minute);
    prtc->second = func_003895D8(prtc->second);
}

/* func_003896B8: RTC Decimal to BCD */
void func_003896B8(sceCdCLOCK *prtc) {
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x141, D_4D62C0);
    }
    prtc->year   = func_00389570(prtc->year);
    prtc->month  = func_00389570(prtc->month);
    prtc->day    = func_00389570(prtc->day);
    prtc->hour   = func_00389570(prtc->hour);
    prtc->minute = func_00389570(prtc->minute);
    prtc->second = func_00389570(prtc->second);
}

/* func_00389740: RTC Increment Day with Leap Year Calculation */
void func_00389740(sceCdCLOCK *prtc) {
    char table[12];
    int i;
    const char *src = D_4D62D0;
    for (i = 0; i < 12; i++) {
        table[i] = src[i];
    }

    if (prtc == NULL) {
        func_114320(D_4D6298, 0x150, D_4D62C0);
    }
    prtc->day++;
    if ((prtc->year & 3) == 0) {
        table[1] = 29;
    }
    if (prtc->day > table[prtc->month - 1]) {
        prtc->day = 1;
        prtc->month++;
        if (prtc->month == 13) {
            prtc->year = (prtc->year == 99) ? 0 : prtc->year + 1;
            prtc->month = 1;
        }
    }
}

/* func_00389828: RTC Decrement Day with Leap Year Calculation */
void func_00389828(sceCdCLOCK *prtc) {
    char table[12];
    int i;
    const char *src = D_4D62D0;
    for (i = 0; i < 12; i++) {
        table[i] = src[i];
    }

    if (prtc == NULL) {
        func_114320(D_4D6298, 0x168, D_4D62C0);
    }
    prtc->day--;
    if ((prtc->year & 3) == 0) {
        table[1] = 29;
    }
    if (prtc->day == 0) {
        prtc->month--;
        if (prtc->month == 0) {
            prtc->year = (prtc->year == 0) ? 99 : prtc->year - 1;
            prtc->month = 12;
        }
        prtc->day = table[prtc->month - 1];
    }
}

/* func_00389900: RTC Increment Hour */
void func_00389900(sceCdCLOCK *prtc) {
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x181, D_4D62C0);
    }
    prtc->hour++;
    if (prtc->hour == 24) {
        prtc->hour = 0;
        func_00389740(prtc);
    }
}

/* func_00389970: RTC Decrement Hour */
void func_00389970(sceCdCLOCK *prtc) {
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x190, D_4D62C0);
    }
    if (prtc->hour == 0) {
        prtc->hour = 23;
        func_00389828(prtc);
    } else {
        prtc->hour--;
    }
}

/* func_003899D8: Adjust RTC by timezone difference (in minutes) */
void func_003899D8(sceCdCLOCK *prtc, int diff) {
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x1A0, D_4D62C0);
    }
    if (diff < -1440 || diff > 1440) {
        func_114320(D_4D6298, 0x1A1, D_4D62E0);
    }
    func_00389630(prtc);
    diff += prtc->minute;
    if (diff < 0) {
        do {
            func_00389970(prtc);
            diff += 60;
        } while (diff < 0);
        prtc->minute = diff;
    } else {
        while (diff > 60) {
            func_00389900(prtc);
            diff -= 60;
        }
        prtc->minute = diff;
    }
    func_003896B8(prtc);
}

/* func_00389AA8: Get Local Time from RTC with -540 min default offset */
void func_00389AA8(sceCdCLOCK *prtc) {
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x1BC, D_4D62C0);
    }
    func_003899D8(prtc, -540);
}

/* func_00389AF0: Read RTC, query TimeZone and adjust */
void func_00389AF0(sceCdCLOCK *prtc) {
    int tz;
    int diff;
    func_389388(prtc);
    tz = func_389470();
    diff = tz * 60 - 540;
    if (prtc == NULL) {
        func_114320(D_4D6298, 0x1C7, D_4D62C0);
    }
    func_003899D8(prtc, diff);
}
