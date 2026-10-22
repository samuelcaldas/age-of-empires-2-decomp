#ifndef NETWORK_SEND_CHECKED_337840_H
#define NETWORK_SEND_CHECKED_337840_H

extern "C" {
    /**
     * Send one fixed 492-byte datagram on the transmit socket under the send mutex.
     *
     * @param payload buffer of at least 492 bytes; always sent in full.
     * @param size caller's message size; only gates the send.
     * @return 492 on success, -1 (after logging) when size exceeds 492,
     *         -2 (after logging) when the socket sends anything other than 492 bytes.
     */
    int func_00337840(const void *payload, int size);
}

#endif
