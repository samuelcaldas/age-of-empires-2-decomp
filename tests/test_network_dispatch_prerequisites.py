"""Missing private matching inputs must be reported as skips, not compiler errors."""

from pathlib import Path

import pytest

import test_network_session_dispatch_3378d0_matching as dispatch_matching


def test_session_dispatch_skips_before_compilation_without_compiler(
        monkeypatch, tmp_path_factory):
    """The dispatch fixture rejects a missing MWCC binary before launching wibo."""
    monkeypatch.setattr(dispatch_matching, "COMPILER", Path("/nonexistent/mwccps2.exe"))
    with pytest.raises(pytest.skip.Exception, match="requires original ELF and PS2 tools"):
        dispatch_matching.relocated_code.__wrapped__(tmp_path_factory)
