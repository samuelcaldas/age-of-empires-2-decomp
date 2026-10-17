"""Small public-safe evidence records for behavioral tests."""


def snapshot(commit="a", sequence=1, state="verified", ranges=None):
    """Return a fresh schema-complete synthetic evidence snapshot."""
    return {
        "schema_version": 1, "collector_version": "1", "policy_version": "cpp-exact-v1",
        "series_id": "1" * 64, "edition": "SLES-50282", "commit": commit * 40,
        "tree": commit * 40, "producer": "2" * 32, "sequence": sequence,
        "attempt_id": f"{sequence:064x}", "state": state, "profile": "audited",
        "times": {"started": "2026-10-17T00:00:00Z", "finished": "2026-10-17T00:01:00Z",
                  "collected": "2026-10-17T00:01:00Z"},
        "fingerprints": {"config": "3" * 64, "registry": "4" * 64,
                         "inventory": None, "original": "5" * 40,
                         "compiler": "6" * 64, "verifier": "7" * 64},
        "scope": {"kind": "audited_lower_bound", "complete": False,
                  "enrolled_units": 1, "observed_units": None, "integrated": True,
                  "linked_executable": "not-run"},
        "gates": {"behavior": "passed", "matching": "passed", "regression": "not-run"},
        "ranges": ranges if ranges is not None else [
            {"start": 100, "end": 140, "owner": "unit", "function": True}],
        "denominator": {"bytes": None, "kind": "unknown", "confidence": "unknown",
                        "source": "unknown"},
        "observed": None, "evidence": ["8" * 64], "errors": [],
    }
