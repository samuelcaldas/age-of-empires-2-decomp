#ifndef NETWORK_SESSION_DISPATCH_3378D0_H
#define NETWORK_SESSION_DISPATCH_3378D0_H

extern "C" {
    /**
     * Dispatch one fixed-size session-control message.
     *
     * @param message 512-byte message buffer with an integer field at offset 12.
     * @return 1 after handling JOINED or SESSION, otherwise 0.
     */
    int func_003378D0(const char *message);
}

#endif
