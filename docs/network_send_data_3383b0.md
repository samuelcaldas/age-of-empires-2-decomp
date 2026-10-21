# Data send at `0x3383B0`

The function builds a packet in the object's 1024-byte send buffer. It writes two header words, a byte-sum checksum, and payload length, then copies the payload and delegates transmission to the checked-send wrapper. Payloads above the buffer cap return zero. A negative wrapper result is logged and returned unchanged.

The target extent is 188 bytes, including the `jr ra` delay slot. Four zero bytes follow before `0x338470`.

Native coverage checks packet fields, byte checksum, copied data, wrapper result propagation, and the 1008-byte payload-cap boundary. Target byte matching remains nonmatching; see its test and task report for the measured compiler extent.
