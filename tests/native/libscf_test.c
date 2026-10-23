#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libscf.h"

/* Strings and Constants */
const char D_4D6298[] = "libscf.c";
const char D_4D62A8[] = "c <=99";
const char D_4D62B0[] = "c <= 0x99";
const char D_4D62C0[] = "prtc != NULL";
const char D_4D62D0[] = "\x1f\x1c\x1f\x1e\x1f\x1e\x1f\x1f\x1e\x1f\x1e\x1f";
const char D_4D62E0[] = "-60*24<=diff && diff <= 60*24";

/* Mock state */
static int mock_read_clock_called = 0;
static int mock_tz_minutes = 9; /* +9h JST */
static int mock_assert_called = 0;

void func_114320(const char *file, int line, const char *expr) {
    (void)file;
    (void)line;
    (void)expr;
    mock_assert_called++;
}

int func_389388(sceCdCLOCK *clock) {
    mock_read_clock_called++;
    if (clock) {
        clock->stat = 0;
        clock->second = 0x30;
        clock->minute = 0x15;
        clock->hour = 0x12;
        clock->pad = 0;
        clock->day = 0x23;
        clock->month = 0x10;
        clock->year = 0x26;
    }
    return 1;
}

int func_389470(void) {
    return mock_tz_minutes;
}

static void test_bcd_conversions(void) {
    /* Test Dec to BCD */
    assert(func_00389570(0) == 0x00);
    assert(func_00389570(9) == 0x09);
    assert(func_00389570(10) == 0x10);
    assert(func_00389570(25) == 0x25);
    assert(func_00389570(99) == 0x99);

    /* Test BCD to Dec */
    assert(func_003895D8(0x00) == 0);
    assert(func_003895D8(0x09) == 9);
    assert(func_003895D8(0x10) == 10);
    assert(func_003895D8(0x25) == 25);
    assert(func_003895D8(0x99) == 99);
}

static void test_clock_bcd_dec_conversion(void) {
    sceCdCLOCK clock;
    clock.stat = 0;
    clock.second = 0x45;
    clock.minute = 0x30;
    clock.hour = 0x14;
    clock.pad = 0;
    clock.day = 0x23;
    clock.month = 0x10;
    clock.year = 0x26;

    func_00389630(&clock); /* BCD to Dec */
    assert(clock.second == 45);
    assert(clock.minute == 30);
    assert(clock.hour == 14);
    assert(clock.day == 23);
    assert(clock.month == 10);
    assert(clock.year == 26);

    func_003896B8(&clock); /* Dec to BCD */
    assert(clock.second == 0x45);
    assert(clock.minute == 0x30);
    assert(clock.hour == 0x14);
    assert(clock.day == 0x23);
    assert(clock.month == 0x10);
    assert(clock.year == 0x26);
}

static void test_rtc_day_increment_and_leap_year(void) {
    sceCdCLOCK clock;
    memset(&clock, 0, sizeof(clock));

    /* Normal month day increment */
    clock.day = 30;
    clock.month = 1; /* Jan (31 days) */
    clock.year = 23;
    func_00389740(&clock);
    assert(clock.day == 31 && clock.month == 1);

    /* Month overflow */
    func_00389740(&clock);
    assert(clock.day == 1 && clock.month == 2);

    /* Leap year test: 2024 (year 24 divisible by 4) */
    clock.day = 28;
    clock.month = 2;
    clock.year = 24;
    func_00389740(&clock);
    assert(clock.day == 29 && clock.month == 2);

    /* Leap year overflow to March */
    func_00389740(&clock);
    assert(clock.day == 1 && clock.month == 3);

    /* Year overflow: Dec 31 to Jan 1 */
    clock.day = 31;
    clock.month = 12;
    clock.year = 99;
    func_00389740(&clock);
    assert(clock.day == 1 && clock.month == 1 && clock.year == 0);
}

static void test_rtc_day_decrement(void) {
    sceCdCLOCK clock;
    memset(&clock, 0, sizeof(clock));

    /* March 1 in leap year -> Feb 29 */
    clock.day = 1;
    clock.month = 3;
    clock.year = 24;
    func_00389828(&clock);
    assert(clock.day == 29 && clock.month == 2);

    /* Jan 1 year 00 -> Dec 31 year 99 */
    clock.day = 1;
    clock.month = 1;
    clock.year = 0;
    func_00389828(&clock);
    assert(clock.day == 31 && clock.month == 12 && clock.year == 99);
}

static void test_adjust_time(void) {
    sceCdCLOCK clock;
    memset(&clock, 0, sizeof(clock));
    clock.day = 0x23;
    clock.month = 0x10;
    clock.year = 0x26;
    clock.hour = 0x10;
    clock.minute = 0x00;

    /* Add 90 minutes -> 11:30 */
    func_003899D8(&clock, 90);
    assert(clock.hour == 0x11);
    assert(clock.minute == 0x30);
}

int main(void) {
    test_bcd_conversions();
    test_clock_bcd_dec_conversion();
    test_rtc_day_increment_and_leap_year();
    test_rtc_day_decrement();
    test_adjust_time();
    printf("All native libscf tests passed successfully.\n");
    return 0;
}
