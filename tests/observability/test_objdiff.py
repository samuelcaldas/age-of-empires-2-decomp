"""Existing report measures remain observed, never exact-C++ claims."""

import json
import pytest

from scripts.observability.objdiff import read_objdiff_report


def test_numeric_strings_are_diagnostic_only(tmp_path):
    path = tmp_path / "report.json"
    measures = dict(total_code="100", matched_code="90", total_units="3",
                    total_functions="4", fuzzy_match_percent=100)
    path.write_text(json.dumps(dict(measures=measures, units=[])))
    value = read_objdiff_report(path)
    assert value is not None
    assert value["total_code"] == 100
    assert value["matched_code"] == 90
    assert value["verified"] is False
    assert "fuzzy_match_percent" not in value


@pytest.mark.parametrize("invalid", [True, "-1", "9007199254740992", 1.5])
def test_invalid_inventory_sizes_are_rejected(tmp_path, invalid):
    path = tmp_path / "report.json"
    path.write_text(json.dumps(dict(measures=dict(total_code=invalid))))
    with pytest.raises(ValueError):
        read_objdiff_report(path)


def test_missing_report_is_unmeasured(tmp_path):
    assert read_objdiff_report(tmp_path / "absent.json") is None
