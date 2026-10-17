"""Private structured pytest outcomes; never publish raw diagnostic output."""

import json
from pathlib import Path

COLLECTED = []
OUTCOMES = []


def pytest_addoption(parser):
    """Register the private report destination supplied by the local executor."""
    parser.addoption("--observability-report", default=None)


def pytest_collection_finish(session):
    """Record exactly the collected node identities, including parameter cases."""
    COLLECTED[:] = [item.nodeid for item in session.items]


def pytest_runtest_logreport(report):
    """Record phase outcomes without code, paths from failures or diagnostics."""
    OUTCOMES.append(dict(nodeid=report.nodeid, when=report.when,
                         outcome=report.outcome, xfail=hasattr(report, "wasxfail")))


def pytest_sessionfinish(session, exitstatus):
    """Write the private report even when tests fail or collect no cases."""
    destination = session.config.getoption("--observability-report")
    if destination:
        data = dict(collected=COLLECTED, outcomes=OUTCOMES, exit_code=int(exitstatus))
        Path(destination).write_text(json.dumps(data))
