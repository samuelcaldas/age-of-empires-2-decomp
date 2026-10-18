#pragma exceptions off
#pragma inline_depth(4)
#pragma divbyzerocheck on
#include "trade_packet.h"

static inline int packet_divisor(int format) {
    if (static_cast<short>(format) == 20) {
        return 512;
    }
    if (static_cast<short>(format) == 19) {
        return 256;
    }
    if (static_cast<short>(format) == 2) {
        return 128;
    }
    return 64;
}

static inline int packet_blocks(int format, int width, int height) {
    int divisor = packet_divisor(format);
    int product = static_cast<short>(width) * static_cast<short>(height);
    unsigned int numerator = static_cast<unsigned int>(product) << 4;
    numerator += static_cast<unsigned int>(divisor - 1);
    return static_cast<int>(numerator) / divisor;
}

extern "C" void *func_0021DF50(void *packet, int destination, int format, int pitch,
                               void *pixels, int x, int y, int width, int height) {
    if (packet == 0) {
        packet = func_123908(0);
    }
    int blocks = packet_blocks(format, width, height);
    func_1046D0(packet, static_cast<unsigned short>(destination),
                 static_cast<unsigned char>(format), static_cast<unsigned short>(pitch),
                 pixels, blocks, static_cast<short>(x), static_cast<short>(y),
                 static_cast<short>(width), static_cast<short>(height));
    return func_21C050(packet);
}
