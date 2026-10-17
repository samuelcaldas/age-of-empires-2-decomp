"""Exercise actual original-code interval accounting."""

import pytest

from scripts.observability.ranges import (
    function_count, union_code_bytes, validate_ownership,
)


def interval(start, end, owner="unit", function=True):
    return dict(start=start, end=end, owner=owner, function=function)


@pytest.mark.parametrize("ranges,expected", [
    ((), 0), ((interval(100, 140),), 40),
    ((interval(100, 140), interval(120, 160)), 60),
    ((interval(100, 140), interval(100, 140)), 40),
    ((interval(100, 140), interval(140, 160)), 60),
])
def test_unique_bytes(ranges, expected):
    assert union_code_bytes(ranges) == expected


@pytest.mark.parametrize("start,end", [
    (-1, 4), (4, 4), (5, 4), (True, 4), (1, 2**53), (1.5, 4),
])
def test_invalid_ranges_are_rejected(start, end):
    with pytest.raises(ValueError):
        union_code_bytes((interval(start, end),))


def test_function_identity_is_not_delivery_count():
    ranges = (interval(100, 140), interval(100, 140),
              interval(140, 160, function=False))
    assert function_count(ranges) == 1


def test_conflicting_ownership_is_not_certified():
    with pytest.raises(ValueError, match="overlap"):
        validate_ownership((interval(100, 140, "one"),
                            interval(120, 160, "two")))
