#include <cassert>
#include <cstdlib>
#include <vector>
#include "trade_packet.h"

struct DispatchInput {
    int destination;
    int format;
    int pitch;
    void *pixels;
    int x;
    int y;
    int width;
    int height;
};

struct ForwardedPacket {
    void *packet;
    DispatchInput input;
};

static std::vector<int> steps;
static std::vector<int> reservations;
static std::vector<ForwardedPacket> forwarded;
static char first_packet[64];
static char second_packet[64];
static char pixels[16];
static bool null_first_packet;

enum Step { RESERVE, BUILD, FINISH };

extern "C" void *func_221B60(int size) {
    steps.push_back(RESERVE);
    reservations.push_back(size);
    if (reservations.size() == 1) {
        return null_first_packet ? 0 : first_packet;
    }
    return second_packet;
}

extern "C" void *func_0021DF50(void *packet, int destination, int format,
                             int pitch, void *data, int x, int y,
                             int width, int height) {
    ForwardedPacket record = {packet, {destination, format, pitch, data,
                                      x, y, width, height}};
    forwarded.push_back(record);
    steps.push_back(BUILD);
    return second_packet;
}

extern "C" void func_221AC0() {
    steps.push_back(FINISH);
}

static void assert_order() {
    assert(steps.size() == 4);
    assert(steps[0] == RESERVE);
    assert(steps[1] == BUILD);
    assert(steps[2] == RESERVE);
    assert(steps[3] == FINISH);
    assert(reservations.size() == 2);
    assert(reservations[0] == 0xC);
    assert(reservations[1] == 0x100);
}

static void assert_forwarded(const DispatchInput &input) {
    assert(forwarded.size() == 1);
    const ForwardedPacket &actual = forwarded[0];
    assert(actual.packet == (null_first_packet ? 0 : first_packet));
    assert(actual.input.destination == static_cast<short>(input.destination));
    assert(actual.input.format == static_cast<short>(input.format));
    assert(actual.input.pitch == static_cast<short>(input.pitch));
    assert(actual.input.pixels == input.pixels);
    assert(actual.input.x == input.x);
    assert(actual.input.y == input.y);
    assert(actual.input.width == input.width);
    assert(actual.input.height == input.height);
}

static void run_case(int index) {
    const DispatchInput inputs[] = {
        {0x1F00, 0, 4, pixels, 0x12345678, -2, 10, 20},
        {0x1234FFFF, static_cast<int>(0xABCD8000U), 0x17FFF,
         pixels, 0x12348000, 0x4321FFFF, 0x1000A, 0x20014},
        {0x1F00, 0, 4, pixels, 1, 2, 3, 4},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    const DispatchInput &input = inputs[index];
    null_first_packet = index == 2;
    func_0021DE90(input.destination, input.format, input.pitch,
                   input.pixels, input.x, input.y, input.width, input.height);
    assert_order();
    assert_forwarded(input);
}

int main(int argument_count, char **arguments) {
    assert(argument_count == 2);
    int index = std::atoi(arguments[1]);
    assert(index >= 0 && index < 4);
    run_case(index);
    return 0;
}
