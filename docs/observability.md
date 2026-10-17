# Decompilation Observability

Offline-first, verifiable progress tracking for the Age of Empires II decompilation.

## Overview

The observatory provides an immutable, commit-bound measurement of verified C/C++ decompilation. It separates:
1. **Audited Lower Bound**: Verified pure C/C++ matching against the original binary via isolated Docker container verification.
2. **Observed Inventory**: Objdiff report statistics (informational only; not proof of exact matching or pure C++).
3. **Agent Activity**: Session telemetry or heartbeats (distinct from code completion).

## Local Usage

### Status
Check current verification status:
```bash
python -m scripts.observability status
# Or machine-readable JSON:
python -m scripts.observability status --json
```

### Persistent Terminal Watch (tmux)
Keep a live status dashboard running in a tmux pane:
```bash
python -m scripts.observability watch --interval 5
```

### Background Worker
Process queued verification tasks:
```bash
python -m scripts.observability work --watch --interval 5
```

### Optional Post-Commit Hook
An opt-in example is provided in `hooks/observability/post-commit.example`.
It enqueues local commits offline without performing builds or network requests:
```bash
cp hooks/observability/post-commit.example .git/hooks/post-commit
chmod +x .git/hooks/post-commit
```

## Export & Static Site

Generate public artifacts and GitHub Pages assets:
```bash
python -m scripts.observability export --output build/observability/public
python -m scripts.observability site --input build/observability/public --output build/observability/site
```

The resulting `build/observability/site` contains:
- `index.html`, `styles.css`, `app.mjs`, `view_model.mjs`, `chart.mjs`
- `badges/bytes.svg`, `badges/state.svg`, `badges/verified-at.svg`
- `data/latest.json`

## GitHub Publication (Opt-In Dry Run)

Publication to GitHub is **strictly opt-in and dry-run by default**:
```bash
python -m scripts.observability publish --dry-run
```
No git branches or network requests are pushed unless `--apply` is explicitly passed and configured.
No game binaries, compiler files, objects, or raw private logs are ever included in public exports.
