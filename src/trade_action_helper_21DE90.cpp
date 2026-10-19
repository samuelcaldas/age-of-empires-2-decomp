#pragma exceptions off
#include "trade_packet.h"

extern "C" void func_0021DE90(int destination, int format, int pitch, void *pixels,
                              int x, int y, int width, int height) {
    void *packet = func_221B60(0xC);
    func_0021DF50(packet, static_cast<short>(destination),
                   static_cast<short>(format), static_cast<short>(pitch),
                   pixels, x, y, width, height);
    func_221B60(0x100);
    func_221AC0();
}
