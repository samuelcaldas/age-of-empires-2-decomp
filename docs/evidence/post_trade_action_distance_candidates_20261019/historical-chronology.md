# Historical chronology: host evidence, not Docker TDD

The session transcript establishes a host assertion failure against a temporary
repository stub. It also establishes implementation work in scratch files before
the test was written. Historical Red-before-implementation is therefore **not
established**.

The source transcript is
`/home/samuelcaldas/.claude/projects/-home-samuelcaldas-source-repos-aoe/b162784f-672f-46c8-87e6-647c57df0faf.jsonl`.
Event numbers below are JSONL line numbers. Timestamps are UTC. The original
behavioral Red output is retained separately in
[historical-host-red.txt](historical-host-red.txt), without transcript metadata.

## Recorded order

1. Event `69014`, `2026-10-19T08:15:10.753Z`, wrote
   `/tmp/test_8e30.cpp` and invoked MWCC. Events `69024`, `69032`, `69046`,
   and `69050` created and compiled subsequent scratch candidates, ending with
   `/tmp/test_8e30_5.cpp`.
2. Event `69079`, `2026-10-19T08:18:20.589Z`, wrote the native fixture.
3. Event `69095`, `2026-10-19T08:18:44.619Z`, wrote a repository placeholder
   with signature `int func_002B8E30(void *self, int *coords)` and body
   `return -1;`. This was an uncommitted harness placeholder, not source present
   in parent commit `1ebe519ec4b15af59e9043a2bb758e83804b30e0`.
4. Event `69100`, `2026-10-19T08:18:55.424Z`, invoked:

   ```sh
   .venv/bin/pytest tests/test_post_trade_action_distance_candidates.py
   ```

   Result `69101` failed compilation because the fixture assigned to function
   symbols. That setup failure is **not** a behavioral Red.
5. Event `69122`, `2026-10-19T08:19:33.242Z`, repeated the same command after
   fixing the fixture. Its matching tool result, event `69123`, records the
   executed assertion `res1 == 42` failing at native fixture line `93`.
   The native process returned `-6`; pytest exited with `1` and reported
   **1 failed in 1.50s**. The result event has no independent timestamp; the
   timestamp here belongs to its invocation.
6. Event `69191`, `2026-10-19T08:22:14.556Z`, copied
   `/tmp/test_8e30_5.cpp` into the repository source and ran the target verifier.
   Result `69192` reported a 616-byte function and six relocations.
7. The first post-copy pytest attempt, event `69207`, failed compilation because
   the fixture still passed `char *` after the public signature changed to
   `TradeActionState *`. That failure is not Green.
8. Event `69234`, `2026-10-19T08:23:26.016Z`, invoked:

   ```sh
   .venv/bin/pytest tests/test_post_trade_action_distance_candidates.py -v
   ```

   Result `69235` reported **5 passed** after the fixture correction.
9. Commit result event `69369`, `2026-10-19T08:29:22.278Z`, records
   `1b1e7acccc5dea13a7702143c82660551c8869ce`, which includes both the candidate
   and its tests.

## What this proves

The host repository-stub failure preceded copying the final scratch candidate
into the repository. It did **not** precede implementation and tuning in scratch
files. The transcript does not precisely establish when the scratch candidate
became complete. No historical Docker Red was found.

The separately retained Docker reproduction confirms that the current fixture
rejects an explicit `-1` placeholder and accepts the committed candidate. It
cannot retroactively establish test-first chronology. See the
[Docker evidence report](README.md) for exact commands and scope.
