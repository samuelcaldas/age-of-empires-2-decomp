# Plano: `scripts/ralph_decomp.sh` — loop de decompilação estilo Ralph

## Context
O repo decompila AoE2 PS2 (SLES-50282) slice a slice (`kt_gs_render_*`), hoje de forma manual, via `scripts/decomp_pipeline.py` (stage → compile → diff → promote). Queremos um loop bash no estilo "Ralph" (sessão nova do agente a cada iteração, estado em disco) que só deixa a geração de código para a IA. Todo o resto (fatiamento, prompt, compilação, medição, avanço, promoção, commit) é determinístico. Para só quando todo o `.text` estiver decompilado.

## Descobertas (CLIs)
| CLI | Invocação não-interativa (prompt) |
|---|---|
| agy (padrão) | `agy -p "<prompt>" --dangerously-skip-permissions --model <m> --effort high` (`-p`=`--print`) |
| codex | `codex exec --dangerously-bypass-approvals-and-sandbox -m <m> -` (prompt via stdin) |
| claude | `claude -p --dangerously-skip-permissions --model <m>` (prompt via stdin) |

Todos recebem o prompt por **stdin** (`cat prompt.md | <cli>`); evita limite de argv com dumps grandes. agy: confirmar leitura de stdin na implementação; senão `-p "$(cat prompt.md)"`.

## Arquivos
- **Novo** `scripts/ralph_decomp.sh` — o loop (bash, `set -euo pipefail`).
- **Novo** `scripts/ralph_slice.py` — helper estático chamado pelo bash: próximo slice, hexdump/disasm, medição. Reusa `get_original_bytes`, `diff_draft`, `compile_draft`, `promote_to_project` de `scripts/decomp_pipeline.py` (não duplicar).
- **Novo** `scripts/ralph_prompt.tmpl.md` — template do prompt (política caveman do CLAUDE.md, regras: só C/C++, sem stubs, sem asm, MWCC pragmas das memórias, escrever só em `staging/<func>.cpp`).
- **Novo** `tests/test_ralph_slice.py` (TDD, exigido pelo repo) + `docs/ralph_decomp.md`; linkar em `docs/decomp_pipeline.md` e `CLAUDE.md` (Layout).
- Estado: `build/ralph/state.json` (gitignored via `build/`), logs por iteração em `build/ralph/<func>/attempt-N/{prompt.md,agent.log,diff.txt}`.

## Fluxo do loop
Pré-validação (aborta antes de qualquer trabalho): `.venv/bin/python`, `orig/SLES-50282/AOK.ELF` com sha1 de `config/SLES-50282/build.sha1`, compilador/wibo presente, CLI escolhido no PATH, `git status` limpo de arquivos rastreados. Lock com `flock` (idempotência/uma instância).

Por iteração:
1. **Fatiamento automático** (`ralph_slice.py next`): intervalos cobertos = entradas `type:func size:` de `config/SLES-50282/symbols.txt` + segmentos asm de libs em `config.yml`. Próximo slice = primeira lacuna não coberta no `.text` (vram `0x100000`–`0x4E2FE0`, offset = vram − 0x100000 + 0x1E0). Fim do slice: `jr $ra` (`0x03E00008`) + delay slot, respeitando retornos múltiplos (continua até o próximo prólogo `addiu sp,sp,-N`) e teto de tamanho (padrão 0x800). Emite nome `func_XXXXXXXX`, vram, tamanho. Parciais ≥90% entram em `state.json` e contam como cobertos para o cursor.
2. **Estático**: `decomp_pipeline.py stage` + monta prompt = template + bytes crus (hexdump) + disassembly MIPS (`mips-linux-gnu-objdump`/`llvm-objdump`, verificar disponível) + assinaturas/símbolos vizinhos de `symbols.txt` + (retry) diff e erros de compilação da tentativa anterior.
3. **Único passo não estático**: `invoke_agent` — `case "$AGENT" in agy|codex|claude)` com `AGENT=${AGENT:-agy}`; flags acima; timeout configurável (`RALPH_TIMEOUT`).
4. **Estático**: `compile` → se falhar, conta como tentativa com erro no feedback; senão `diff` → % de similaridade (`match_percentage` do `diff_draft`).
5. **Gate**:
   - `== 100%`: `promote` (src/kcet, config.yml, symbols.txt, configure.py), `ninja` do objeto, commit `decomp(ps2): match <func> slice (0x… - 0x…)`; sem PRs; só `git add` de caminhos explícitos.
   - `>= 90%` e `< 100%`: mantém rascunho em `staging/`, marca "parcial" no estado, **avança** o cursor (não promove — regra do repo).
   - `< 90%`: retry com feedback do diff (até `RALPH_MAX_ATTEMPTS`, padrão 5); depois marca "bloqueado" e pula; bloqueados e parciais são revisitados em passe final, em ordem, até 100%.
6. **Parada**: só quando não há lacunas, parciais nem bloqueados (todo o `.text` 100% promovido). Sem limite global de iterações; Ctrl-C seguro (estado atômico via `mv` de tmp).

Variáveis: `AGENT`, `RALPH_MODEL`, `RALPH_MIN_PCT=90`, `RALPH_MAX_ATTEMPTS=5`, `RALPH_MAX_SLICE=0x800`, `RALPH_TIMEOUT`, `RALPH_DRY_RUN=1` (só mostra slice+prompt, não chama IA).

## Ressalvas
- Cobertura completa de ~3,9 MB de `.text` é trabalho de milhares de iterações; o script é retomável por design.
- Escopo: só SLES-50282 (único target com pipeline). Parametrizar versão fica fora.
- Premissa "contabilidade de cobertura": se `symbols.txt` não cobrir tudo que já foi decompilado, ajustar `ralph_slice.py` para também ler `configure.py` (verificar na implementação).
- Segurança: flags de skip-permissions só rodam dentro do worktree do repo; segredos não entram em prompt/log.

## Verificação
1. TDD: `tests/test_ralph_slice.py` — red primeiro: fronteira de função (`jr ra`+delay), retorno múltiplo, teto de tamanho, lacuna vs. cobertura, 0/1/muitos slices, ELF ausente → erro específico. Rodar com `.venv/bin/python -m pytest tests/test_ralph_slice.py`, depois a suíte completa e comparar com baseline.
2. `bash -n scripts/ralph_decomp.sh` e `shellcheck` se disponível.
3. `RALPH_DRY_RUN=1 scripts/ralph_decomp.sh` — conferir slice, prompt e que o próximo slice coincide com o fim de `kt_gs_render_259ab0` (0x259BB0).
4. Um agente falso (`AGENT=fake` apontando para script que copia um slice já casado, p.ex. `kt_gs_render_259ab0`) para exercitar compile → diff → gate 100%/90%/<90% sem custo de IA.
5. Uma iteração real com `AGENT=agy` num slice pequeno; inspecionar `git status`/`git diff` e rodar o diff independentemente.
