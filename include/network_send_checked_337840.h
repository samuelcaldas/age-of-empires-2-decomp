#ifndef NETWORK_SEND_CHECKED_337840_H
#define NETWORK_SEND_CHECKED_337840_H

extern "C" {
    /** Send wrapper: rejects a payload size of 493 bytes or more with -1 and logs. */
    int func_00337840(void *self, int size);
}

#endif
