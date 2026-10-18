#ifndef TRADE_PACKET_H
#define TRADE_PACKET_H

extern "C" {

/** Swizzle the supplied palette and dispatch its upload without promising a result. */
void func_0021B560(void *palette_object, const char *palette_data);

/** Reserve packet space, forward all image arguments, and finalize the dispatch. */
void func_0021DE90(int destination, int format, int pitch, void *pixels,
                   int x, int y, int width, int height);

/** Return the current packet storage after reserving the requested size. */
void *func_221B60(int size);

/** Finalize the current dispatch without consuming an argument. */
void func_221AC0();

/** Build one packet; allocate only for a null packet and return the finalized packet. */
void *func_0021DF50(void *packet, int destination, int format, int pitch,
                    void *pixels, int x, int y, int width, int height);

/** Return packet storage for the supplied allocation argument. */
void *func_123908(void *argument);

/** Write all eight register arguments and both dimension stack arguments. */
void func_1046D0(void *packet, int destination, int format, int pitch,
                 void *pixels, int blocks, int x, int y, int width, int height);

/** Finalize the packet and return its address. */
void *func_21C050(void *packet);

}

#endif
