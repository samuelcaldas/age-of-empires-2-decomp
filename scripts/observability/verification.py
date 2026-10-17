"""Independent behavioral and exact-match evidence gates."""

from .source_policy import classify_source

REQUIRED_IDENTITIES = {"commit", "tree", "original", "compiler", "config", "verifier"}


def _matches(node, selector):
    return node == selector or node.startswith(selector + "::") or node.startswith(selector + "[")


def _selected_nodes(report, selectors):
    nodes = report.get("collected", [])
    if not selectors or any(not any(_matches(node, selector) for node in nodes) for selector in selectors):
        return []
    return [node for node in nodes if any(_matches(node, selector) for selector in selectors)]


def _node_status(outcomes):
    if any(value.get("xfail") for value in outcomes):
        return "skipped"
    states = {value["outcome"] for value in outcomes}
    if "failed" in states:
        return "failed"
    if "skipped" in states:
        return "skipped"
    phases = [value["when"] for value in outcomes]
    if sorted(phases) != ["call", "setup", "teardown"] or states != {"passed"}:
        return "unavailable"
    return "passed"


def _exit_allows_gate(report, nodes):
    if report.get("exit_code") == 0:
        return True
    other_failures = any(value["outcome"] == "failed" and value["nodeid"] not in nodes
                         for value in report.get("outcomes", []))
    return report.get("exit_code") == 1 and other_failures


def collect_gate_results(report, declared_nodeids):
    """Assess all required nodes/phases; exit status alone cannot certify ranges."""
    nodes = _selected_nodes(report, declared_nodeids)
    if not nodes:
        return "unavailable"
    states = {_node_status([value for value in report.get("outcomes", []) if value["nodeid"] == node])
              for node in nodes}
    if "failed" in states:
        return "failed"
    if states == {"passed"} and _exit_allows_gate(report, nodes):
        return "passed"
    if "skipped" in states:
        return "skipped"
    return "unavailable"


def _blocked(code, gates):
    return dict(state="blocked", ranges=[], errors=[code], gates=gates)


def assess_evidence(entry, checkout, before, after, reports):
    """Certify fresh reviewed C++ only after both independent gates pass."""
    gates = {name: collect_gate_results(reports.get(name, {}), entry[name])
             for name in ("behavior", "matching")}
    if classify_source(entry, checkout) != "eligible":
        return _blocked("SOURCE_NOT_REVIEWED", gates)
    if "failed" in gates.values():
        return dict(state="failed", ranges=[], errors=["GATE_FAILED"], gates=gates)
    if set(gates.values()) != {"passed"}:
        return _blocked("GATE_INCOMPLETE", gates)
    if before != after or not REQUIRED_IDENTITIES.issubset(before):
        return _blocked("INPUT_CHANGED", gates)
    return dict(state="verified", ranges=entry["ranges"], errors=[], gates=gates)
