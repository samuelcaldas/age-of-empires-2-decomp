"""Audited original-code interval accounting."""

MAX_INTEGER = 2**53 - 1


def _bounds(value):
    start, end = value["start"], value["end"]
    if type(start) is not int or type(end) is not int:
        raise ValueError("range boundaries must be integers")
    if not 0 <= start < end <= MAX_INTEGER:
        raise ValueError("invalid code range")
    return start, end


def _merge(ranges):
    merged = []
    for start, end in sorted(_bounds(value) for value in ranges):
        _append_interval(merged, start, end)
    return merged


def _append_interval(merged, start, end):
    if not merged or start > merged[-1][1]:
        merged.append([start, end])
        return
    merged[-1][1] = max(merged[-1][1], end)


def union_code_bytes(ranges):
    """Return unique half-open code bytes; reject invalid boundaries."""
    return sum(end - start for start, end in _merge(ranges))


def function_count(ranges):
    """Count distinct explicitly bounded functions, never delivery events."""
    return len({_bounds(value) for value in ranges if value["function"]})


def _conflicts(left, right):
    overlap = max(left["start"], right["start"]) < min(left["end"], right["end"])
    return overlap and left["owner"] != right["owner"]


def validate_ownership(ranges):
    """Reject overlapping original-code claims from different owners."""
    union_code_bytes(ranges)
    pairs = ((left, right) for index, left in enumerate(ranges)
             for right in ranges[index + 1:])
    if any(_conflicts(left, right) for left, right in pairs):
        raise ValueError("conflicting range overlap")
