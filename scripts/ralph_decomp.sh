#!/usr/bin/env bash
# Ralph-style loop: decompile the whole PS2 .text, slice by slice.
# Only the code generation step (invoke_agent) is non-static.
# Usage: AGENT=agy|codex|claude [RALPH_MODEL=..] scripts/ralph_decomp.sh
# See docs/ralph_decomp.md.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

AGENT="${AGENT:-agy}"
RALPH_MODEL="${RALPH_MODEL:-}"
RALPH_MIN_PCT="${RALPH_MIN_PCT:-90}"
RALPH_MAX_ATTEMPTS="${RALPH_MAX_ATTEMPTS:-5}"
RALPH_MAX_SLICE="${RALPH_MAX_SLICE:-0x800}"
RALPH_TIMEOUT="${RALPH_TIMEOUT:-1800}"
RALPH_DRY_RUN="${RALPH_DRY_RUN:-0}"
RALPH_DIR="${RALPH_DIR:-build/ralph}"
PY=".venv/bin/python"
SLICE="$PY scripts/ralph_slice.py"
PIPELINE="$PY scripts/decomp_pipeline.py"
STATE="$RALPH_DIR/state.json"

log() { printf '[ralph %s] %s\n' "$(date +%H:%M:%S)" "$*"; }
die() { printf '[ralph] ERROR: %s\n' "$*" >&2; exit 1; }

preflight() {
  [[ -x "$PY" ]] || die "missing $PY"
  [[ -f orig/SLES-50282/AOK.ELF ]] || die "missing orig/SLES-50282/AOK.ELF"
  local expected actual
  expected="$(tr -d '[:space:]' < config/SLES-50282/build.sha1 | cut -c1-40)"
  actual="$(sha1sum orig/SLES-50282/AOK.ELF | cut -c1-40)"
  [[ "$expected" == "$actual" ]] || die "AOK.ELF sha1 mismatch ($actual != $expected)"
  [[ -f compilers/PS2/mwcc-2.3.1.01/mwccps2.exe ]] || die "missing MWCC compiler"
  [[ -x build/tools/wibo ]] || die "missing build/tools/wibo"
  [[ "$RALPH_MIN_PCT" =~ ^[0-9]+(\.[0-9]+)?$ ]] || die "RALPH_MIN_PCT must be numeric"
  [[ "$RALPH_MAX_ATTEMPTS" =~ ^[0-9]+$ ]] || die "RALPH_MAX_ATTEMPTS must be an integer"
  case "$AGENT" in
    agy|codex|claude) command -v "$AGENT" >/dev/null || die "$AGENT not in PATH" ;;
    *) [[ -x "$AGENT" ]] || die "AGENT must be agy|codex|claude or an executable (got: $AGENT)" ;;
  esac
}

json_get() { "$PY" -c 'import json,sys; print(json.loads(sys.argv[1])[sys.argv[2]])' "$1" "$2"; }

build_prompt() { # func vram size attempt feedback_file
  local func="$1" vram="$2" size="$3" feedback_file="$4"
  local staging="staging/${func}.cpp" hexdump disasm neighbours feedback=""
  hexdump="$("$PY" -c 'import sys;sys.path.insert(0,"scripts");import decomp_pipeline as d;b=d.get_original_bytes(int(sys.argv[1],0),int(sys.argv[2],0));print("\n".join(" ".join(b[i:i+16][j:j+4].hex() for j in range(0,len(b[i:i+16]),4)) for i in range(0,len(b),16)))' "$vram" "$size")"
  disasm="$($SLICE disasm --vram "$vram" --size "$size")"
  neighbours="$(grep -E 'type:func' config/SLES-50282/symbols.txt | tail -n 8 || true)"
  [[ -s "$feedback_file" ]] && feedback=$'\n## Previous attempt feedback (fix this)\n'"$(cat "$feedback_file")"
  "$PY" - "$func" "$vram" "$size" "$staging" "$hexdump" "$disasm" "$neighbours" "$feedback" <<'PYEOF'
import sys
func, vram, size, staging, hexdump, disasm, neighbours, feedback = sys.argv[1:9]
text = open("scripts/ralph_prompt.tmpl.md").read()
for key, value in {
    "FUNC": func, "VRAM": vram, "SIZE": size, "STAGING_FILE": staging,
    "STAGING_FILE_OBJ": staging[:-4] + ".o", "HEXDUMP": hexdump,
    "DISASM": disasm, "NEIGHBOURS": neighbours, "FEEDBACK": feedback,
}.items():
    text = text.replace("{{" + key + "}}", value)
sys.stdout.write(text)
PYEOF
}

# The only non-static step. Prompt goes in via stdin (agy: --print reads the prompt arg).
invoke_agent() { # prompt_file log_file
  local prompt_file="$1" log_file="$2" model_args=()
  case "$AGENT" in
    agy)
      [[ -n "$RALPH_MODEL" ]] && model_args=(--model "$RALPH_MODEL")
      timeout "$RALPH_TIMEOUT" agy --print "$(cat "$prompt_file")" --dangerously-skip-permissions \
        --effort high "${model_args[@]}" >"$log_file" 2>&1 ;;
    codex)
      [[ -n "$RALPH_MODEL" ]] && model_args=(-m "$RALPH_MODEL")
      timeout "$RALPH_TIMEOUT" codex exec --dangerously-bypass-approvals-and-sandbox \
        "${model_args[@]}" - <"$prompt_file" >"$log_file" 2>&1 ;;
    claude)
      [[ -n "$RALPH_MODEL" ]] && model_args=(--model "$RALPH_MODEL")
      timeout "$RALPH_TIMEOUT" claude -p --dangerously-skip-permissions \
        "${model_args[@]}" <"$prompt_file" >"$log_file" 2>&1 ;;
    *) timeout "$RALPH_TIMEOUT" "$AGENT" <"$prompt_file" >"$log_file" 2>&1 ;;
  esac
}

# Static: compile + measure. Prints pct; writes feedback to $3.
measure_attempt() { # func vram size feedback_file
  local func="$1" vram="$2" size="$3" feedback_file="$4" source="staging/${1}.cpp" result
  : >"$feedback_file"
  if [[ ! -s "$source" ]]; then echo "0"; echo "No file written at $source." >"$feedback_file"; return; fi
  local compile_output
  if ! compile_output="$($PIPELINE compile --source "$source" 2>&1)"; then
    echo "0"; printf 'Compilation failed:\n%s\n' "$compile_output" >"$feedback_file"; return
  fi
  result="$($SLICE measure --func "$func" --vram "$vram" --size "$size" --obj "staging/${func}.o" 2>&1)" || {
    echo "0"; printf 'Measure failed:\n%s\n' "$result" >"$feedback_file"; return; }
  printf 'Measured: %s\n' "$result" >"$feedback_file"
  json_get "$result" pct
}

pct_at_least() { "$PY" -c 'import sys; sys.exit(0 if float(sys.argv[1])>=float(sys.argv[2]) else 1)' "$1" "$2"; }

promote_and_commit() { # func vram size
  local func="$1" vram="$2" size="$3" offset end
  offset=$(( vram - 0x100000 + 0x1E0 ))
  $PIPELINE promote --func "$func" --module kcet --source "staging/${func}.cpp" \
    --header "${func}.h" --vram "$vram" --offset "$offset" --size "$size"
  printf -v end '0x%08X' $(( vram + size ))
  git add -- "src/kcet/${func}.cpp" config/SLES-50282/config.yml config/SLES-50282/symbols.txt configure.py
  git commit -q -m "decomp(ps2): match ${func} slice ($(printf '0x%08X' "$vram") - ${end})

Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>"
}

process_slice() { # json
  local info="$1" func vram size attempt=0 pct=0 feedback attempt_dir prompt
  func="$(json_get "$info" func)"; vram="$(json_get "$info" vram)"; size="$(json_get "$info" size)"
  vram="$(printf '0x%X' "$vram")"; size="$(printf '0x%X' "$size")"
  $PIPELINE stage --func "$func" --vram "$vram" --size "$size" >/dev/null
  while (( attempt < RALPH_MAX_ATTEMPTS )); do
    attempt=$(( attempt + 1 ))
    attempt_dir="$RALPH_DIR/$func/attempt-$attempt"; mkdir -p "$attempt_dir"
    feedback="$RALPH_DIR/$func/feedback.txt"; touch "$feedback"
    prompt="$attempt_dir/prompt.md"
    build_prompt "$func" "$vram" "$size" "$feedback" >"$prompt"
    if [[ "$RALPH_DRY_RUN" == "1" ]]; then log "dry run: $func $vram $size -> $prompt"; return 0; fi
    log "$func attempt $attempt/$RALPH_MAX_ATTEMPTS via $AGENT"
    invoke_agent "$prompt" "$attempt_dir/agent.log" || log "agent exited non-zero (see agent.log)"
    pct="$(measure_attempt "$func" "$vram" "$size" "$feedback")"
    cp "$feedback" "$attempt_dir/diff.txt"
    log "$func similarity ${pct}%"
    pct_at_least "$pct" "$RALPH_MIN_PCT" && break
  done
  $SLICE record --state "$STATE" --func "$func" --vram "$vram" --size "$size" --pct "$pct" \
    --attempts "$attempt" --min-pct "$RALPH_MIN_PCT" --max-attempts "$RALPH_MAX_ATTEMPTS"
  if pct_at_least "$pct" 100; then
    promote_and_commit "$func" "$vram" "$size"; log "$func promoted"
  elif pct_at_least "$pct" "$RALPH_MIN_PCT"; then
    log "$func partial (${pct}%), kept in staging, advancing"
  else
    log "$func blocked (${pct}%), skipping; revisited at the end"
  fi
}

main() {
  preflight
  mkdir -p "$RALPH_DIR"
  exec 9>"$RALPH_DIR/lock"; flock -n 9 || die "another ralph_decomp.sh is running"
  while true; do
    local info kind
    info="$($SLICE next --state "$STATE" --max-slice "$RALPH_MAX_SLICE")"
    kind="$(json_get "$info" kind)"
    if [[ "$kind" == "done" ]]; then log "all slices at 100%: .text fully decompiled"; break; fi
    process_slice "$info"
    [[ "$RALPH_DRY_RUN" == "1" ]] && break
  done
}

main "$@"
