#include <cassert>
#include <cstdlib>
#include <vector>
#include "trade_packet.h"

struct PacketWrite {
    void *packet;
    int destination;
    int format;
    int pitch;
    void *pixels;
    int blocks;
    int x;
    int y;
    int width;
    int height;
};

struct InputCase {
    int format;
    int width;
    int height;
    int blocks;
    bool allocate;
};

static const InputCase INPUTS[] = {
    {0x14, 10, 20, 7, false},
    {0x13, 10, 20, 13, false},
    {2, 10, 20, 25, false},
    {0, 10, 20, 50, false},
    {0, 10, 20, 50, true},
    {0x10014, 0x1000A, 0x20014, 7, false},
    {0xFF14, 10, 20, 50, false},
    {0, -20, 10, -49, false},
    {0, 32767, 32767, -16382, false},
    {0, -32768, -32768, 0, false},
    {0x14, -32768, 32767, 1024, false},
    {0, 0, 20, 0, false},
    {-1, 10, 20, 50, false}
};

static std::vector<int> steps;
static std::vector<PacketWrite> writes;
static char supplied_packet[64];
static char allocated_packet[64];
static void *finalized_packet;

enum Step { ALLOCATE, WRITE, FINALIZE };

extern "C" void *func_123908(void *argument) {
    assert(argument == 0);
    steps.push_back(ALLOCATE);
    return allocated_packet;
}

extern "C" void func_1046D0(void *packet, int destination, int format,
                             int pitch, void *pixels, int blocks, int x,
                             int y, int width, int height) {
    PacketWrite write = {packet, destination, format, pitch, pixels,
                         blocks, x, y, width, height};
    writes.push_back(write);
    steps.push_back(WRITE);
}

extern "C" void *func_21C050(void *packet) {
    finalized_packet = packet;
    steps.push_back(FINALIZE);
    return packet;
}

static void assert_order(bool allocated) {
    if (allocated) {
        assert(steps.size() == 3);
        assert(steps[0] == ALLOCATE);
    }
    if (!allocated) {
        assert(steps.size() == 2);
    }
    assert(steps[steps.size() - 2] == WRITE);
    assert(steps[steps.size() - 1] == FINALIZE);
}

static void assert_write(const InputCase &input, void *packet) {
    assert(writes.size() == 1);
    const PacketWrite &write = writes[0];
    assert(write.packet == packet);
    assert(write.destination == 0x9234);
    assert(write.format == (input.format & 0xFF));
    assert(write.pitch == 0xFEDC);
    assert(write.pixels == reinterpret_cast<void *>(0x100));
    assert(write.blocks == input.blocks);
    assert(write.x == -32768);
    assert(write.y == -1);
    assert(write.width == static_cast<short>(input.width));
    assert(write.height == static_cast<short>(input.height));
}

static void run_case(const InputCase &input) {
    void *packet = input.allocate ? 0 : supplied_packet;
    void *result = func_0021DF50(packet, static_cast<int>(0xABCD9234U), input.format,
                 0x1234FEDC, reinterpret_cast<void *>(0x100),
                 0x12348000, 0x4321FFFF, input.width, input.height);
    void *expected_packet = input.allocate ? allocated_packet : supplied_packet;
    assert(result == expected_packet);
    assert_write(input, expected_packet);
    assert(finalized_packet == expected_packet);
    assert_order(input.allocate);
}

int main(int argument_count, char **arguments) {
    assert(argument_count == 2);
    int index = std::atoi(arguments[1]);
    assert(index >= 0);
    assert(static_cast<unsigned int>(index) < sizeof(INPUTS) / sizeof(INPUTS[0]));
    run_case(INPUTS[index]);
    return 0;
}
