#include <cassert>
#include <cstdlib>
#include <vector>
#include "trade_packet.h"

enum Step { RESERVE, ALLOCATE, WRITE, FINALIZE, FINISH };
static std::vector<int> steps;
static char reserved_packet[64];
static char allocated_packet[64];
static char other_packet[64];
static char pixels[1024];
static bool allocate_packet;
static int reservation_count;

static void *expected_packet() {
    return allocate_packet ? allocated_packet : reserved_packet;
}

extern "C" void *func_221B60(int size) {
    steps.push_back(RESERVE);
    ++reservation_count;
    if (reservation_count == 1) {
        assert(size == 12);
        return allocate_packet ? 0 : reserved_packet;
    }
    assert(reservation_count == 2);
    assert(size == 256);
    return other_packet;
}

extern "C" void *func_123908(void *argument) {
    assert(argument == 0);
    steps.push_back(ALLOCATE);
    return allocated_packet;
}

extern "C" void func_1046D0(void *packet, int destination, int format,
                            int pitch, void *data, int blocks, int x,
                            int y, int width, int height) {
    assert(packet == expected_packet());
    assert(destination == 0x9234 && format == 0x14 && pitch == 0xFEDC);
    assert(data == pixels);
    assert(blocks == 7);
    assert(x == 32767 && y == -1);
    assert(width == 10 && height == 20);
    steps.push_back(WRITE);
}

extern "C" void *func_21C050(void *packet) {
    assert(packet == expected_packet());
    steps.push_back(FINALIZE);
    return packet;
}

extern "C" void func_221AC0() {
    steps.push_back(FINISH);
}

static void assert_steps() {
    const int offset = allocate_packet ? 1 : 0;
    assert(steps.size() == static_cast<unsigned int>(5 + offset));
    assert(steps[0] == RESERVE);
    if (allocate_packet) {
        assert(steps[1] == ALLOCATE);
    }
    assert(steps[1 + offset] == WRITE);
    assert(steps[2 + offset] == FINALIZE);
    assert(steps[3 + offset] == RESERVE);
    assert(steps[4 + offset] == FINISH);
}

int main(int argument_count, char **arguments) {
    assert(argument_count == 2);
    allocate_packet = std::atoi(arguments[1]) == 1;
    func_0021DE90(static_cast<int>(0xABCD9234U), 0x10014, 0x1234FEDC,
                   pixels, -32769, 65535, 10, 20);
    assert_steps();
    return 0;
}
