# Peer send dispatch at `0x338B90`

A zero selector visits eight player slots at 136-byte strides. Empty slots and the local player are skipped; each remaining slot triggers the data-send routine. A nonzero selector triggers one data-send call. The dispatcher returns zero.

The target extent is 196 bytes, including the return delay slot. Twelve zero bytes follow before `0x338C60`.

Native coverage checks the broadcast recipient count and single-send path. Target byte matching remains nonmatching; see its test and task report for the measured compiler extent. The native tests do not prove transport delivery or remote acknowledgement.
