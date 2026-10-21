# Receive queue dequeue at `0x338A20`

The function takes the queue semaphore, resets invalid empty queue state, reads the current 2048-byte ring entry, returns its player, type, and masked payload length, optionally copies payload bytes, then advances the read offset. A high marker bit resets the offset to zero. Empty and misaligned entries return `0x887700BE`; successful dequeue returns zero.

The target extent is 368 bytes and ends at the return delay slot before `0x338B90`.

Native coverage checks successful field extraction, payload copying, queue count and offset mutation, and the empty-queue error. This implementation preserves the target's unchecked payload-length copy behavior. Oversized wire lengths can overrun the caller's buffer; the matched routine adds no safety validation.
