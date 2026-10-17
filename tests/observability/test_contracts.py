"""Reject unsupported or misleading public evidence claims."""

import pytest

from scripts.observability.model import validate_snapshot
from .fixtures import snapshot


def test_valid_unknown_denominator_stays_unknown():
    assert validate_snapshot(snapshot())["denominator"]["bytes"] is None


@pytest.mark.parametrize("mutation", [
    lambda value: value.update(private_path="/home/private/secret"),
    lambda value: value["scope"].update(log="password=secret"),
    lambda value: value.update(errors=["/tmp/private.log"]),
    lambda value: value.update(sequence=True),
    lambda value: value.update(commit="not-a-commit"),
    lambda value: value["ranges"][0].update(end=2**53),
    lambda value: value["times"].update(collected="yesterday"),
])
def test_unknown_or_unsafe_fields_are_rejected(mutation):
    value = snapshot()
    mutation(value)
    with pytest.raises(ValueError):
        validate_snapshot(value)


def test_verified_claim_requires_independent_matching_and_behavior():
    value = snapshot()
    value["gates"]["matching"] = "skipped"
    with pytest.raises(ValueError, match="gates"):
        validate_snapshot(value)


def test_failed_attempt_cannot_claim_new_verified_ranges():
    with pytest.raises(ValueError, match="ranges"):
        validate_snapshot(snapshot(state="failed"))


def test_load_range_is_not_verified_game_code_denominator():
    value = snapshot()
    value["denominator"] = dict(bytes=4075488, kind="load_range",
                                confidence="verified", source="elf_load")
    with pytest.raises(ValueError, match="denominator"):
        validate_snapshot(value)
