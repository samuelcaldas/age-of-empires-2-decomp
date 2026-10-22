# Session request at `0x338CE0`

`func_00338CE0` spans 700 bytes, from `0x338CE0` through the return delay
slot at `0x338F98`. Four zero alignment bytes follow, then the next function
starts at `0x338FA0`.

## Observed behavior

With the enumeration flag set, the function clears the host flag and request
queue fields, places the session request marker in the 24-byte request, and
sends it. It polls the shared receive staging buffer and timer until data arrives
or elapsed time exceeds 5000 units. Timeout returns `0x8877000A`. On a reply, it
copies 512 bytes into local storage, copies the 216-byte session description,
sets session state, and sends the joined marker. It waits for the follow-up reply,
then initializes eight player slots from four 112-byte records and marks the
session joined.

With the hosting flag set, it copies session information, sets host and joined
state, and returns zero. Other flag combinations return zero without action.

## Verification

- `tests/test_network_session_request_338ce0.py` executes the C++ function with
  stubbed platform calls. It checks timeout code, queue reset, request length,
  send buffer, and timer/poll order.
- `tests/test_network_session_request_338ce0_matching.py` requires all 700 bytes,
  resolves 52 relocations, and checks four zero padding bytes. Current MWCC
  candidate emits 760 bytes, so the exact comparison blocks on extent mismatch.
  Twenty-five shape trials did not match; the best trial compared 179/700 bytes.

## Limits

The function copies the received 512-byte staging buffer and trusts its contents.
It does not validate the serialized record lengths before copying. This preserves
the original behavior and is unsafe for untrusted network data. No stronger
claims about peer identity or delivery guarantees are established here.
