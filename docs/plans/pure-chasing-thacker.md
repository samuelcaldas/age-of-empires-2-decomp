# Plano: usar o `agy` como subagente orquestrado

## Contexto

Hoje o `agy` é chamado à mão (`agy -p "..."`), em segundo plano, com prompts longos
reescritos a cada vez. Isso gerou problemas reais nesta sessão:

- O `agy` foi além do pedido: baixou um ISO de 551 MB e editou `configure.py`,
  `config.yml` e docs, quando o pedido era só o binário PC.
- Duas tarefas "somente leitura" só eram somente leitura por texto no prompt.
  Nada impedia escrita.
- Não há registro dos resultados: a saída fica em `/tmp/*.txt` e se perde.
- Não dá para rodar várias instâncias em paralelo sem colidir nos mesmos arquivos.

Objetivo: dar ao projeto um jeito repetível e seguro de delegar tarefas ao `agy`,
rodar várias instâncias ao mesmo tempo e verificar o que cada uma fez antes de
aceitar. O Claude continua sendo o orquestrador e a autoridade final.

## O que já existe e será reutilizado

- Flags do `agy` (confirmadas com `agy --help`): `-p`, `--model`, `--effort`,
  `--mode plan|accept-edits`, `--sandbox`, `--add-dir`, `--output-format json`,
  `--json-schema`, `--log-file`, `--print-timeout`, `--conversation`.
- Modelos (`agy models`): `gemini-3.8-flash-*`, `gemini-3.1-pro-*`, entre outros.
- `~/.claude/agents/decomp-worker.md`: padrão de definição de agente do Claude.
  Ele é do projeto nfsmw (GameCube, `gemini-3.5-flash-lite`). **Não será copiado.**
- Fluxo de worktree das regras globais (`git worktree add .worktrees/<nome>`).

Não existe `~/.claude/bin/agy-delegate`, que as regras globais citam. Este plano o
cria dentro do projeto, sem depender do global.

## Abordagem

Um wrapper único `scripts/agy/delegate` (Python, sem dependências novas) mais
perfis de tarefa. O Claude chama o wrapper; o wrapper chama o `agy`.

### 1. Wrapper `scripts/agy/delegate.py`

Entrada: `--task <perfil>` e argumentos do perfil. Faz, nesta ordem (fail-fast):

1. Valida `agy` no PATH, perfil existente e diretório de trabalho.
2. Cria um diretório de execução `build/agy/<id>/` com `prompt.md`, `result.json`,
   `stdout.log`, `meta.json` (perfil, modelo, hashes de entrada, hora).
3. Para perfis que escrevem, cria um worktree `.worktrees/agy-<id>` e roda lá.
   Para perfis somente leitura, roda com `--mode plan` e `--sandbox`.
4. Chama `agy -p` com `--output-format json`, `--json-schema` do perfil e
   `--log-file`, em segundo plano, com `--print-timeout` do perfil.
5. Ao terminar, valida a saída contra o esquema. Se inválida, marca `failed`.
6. Para perfis de escrita, roda `git diff --stat` do worktree e grava em
   `meta.json`. Não faz merge.

Nunca usa `--dangerously-skip-permissions`.

### 2. Perfis (`scripts/agy/profiles/*.yml`)

Cada perfil define: modelo, esforço, modo, timeout, caminhos permitidos, esquema
de saída e o texto do prompt com marcadores. Perfis iniciais:

| Perfil | Escreve? | Uso |
|---|---|---|
| `research` | não | pesquisa web e relatório com fontes (o que fizemos 4 vezes à mão) |
| `fetch-official` | só `orig/<VERSÃO>/` | baixar binário de fonte oficial, com SHA-1 e URL |
| `binary-analysis` | não | `pefile`, `readelf`, `strings`; relatório estruturado |
| `splat-split` | sim, em worktree | rodar/ajustar o split do PS2 e propor `config.yml` |
| `doc-draft` | sim, só `docs/` em worktree | rascunho de doc a partir de achados |

Cada perfil de escrita lista caminhos permitidos. O wrapper rejeita a execução se
o `git diff` tocar fora deles.

### 3. Orquestração de várias instâncias

`scripts/agy/orchestrate.py` lê um arquivo de lote (YAML com lista de tarefas) e:

- Roda até N instâncias em paralelo (padrão 3), cada uma em seu diretório de
  execução e, se escreve, em seu worktree.
- Cada tarefa declara `depends_on`, para ordenar etapas (por exemplo
  `binary-analysis` antes de `splat-split`).
- Grava `build/agy/batch-<id>/summary.json` com estado de cada tarefa
  (`queued|running|done|failed|rejected`).
- Reexecutar o mesmo lote é idempotente: tarefa `done` com mesmos hashes de
  entrada é pulada; nada é baixado ou escrito em duplicidade.

### 4. Integração com o Claude Code

- `.claude/agents/agy-worker.md` (projeto): agente fino que só chama o wrapper e
  devolve o `result.json`. Não executa trabalho por conta própria.
- `.claude/skills/agy-delegate/SKILL.md`: quando e como delegar, com as regras de
  verificação abaixo.
- Regras de verificação (do `CLAUDE.md` global): depois que um worker escreve, o
  Claude inspeciona `git status` e `git diff`, roda os testes e valida contra os
  critérios de aceitação. Não confia no relato do worker.

### 5. Segurança e regras do projeto

- Sem rede por padrão para perfis de análise. Só `research` e `fetch-official`
  usam web.
- `fetch-official` só aceita fontes de uma lista em `scripts/agy/allowed_sources.yml`
  (Microsoft, archive.org de lançamentos oficiais). Alfa/beta vazados, cracks e
  repacks ficam fora, como no ADR 0001.
- Nenhum perfil mexe em `configure.py`, `tools/` ou `config/` sem estar
  explicitamente na lista de caminhos do perfil.
- Segredos só por variáveis de ambiente; o wrapper não os registra em log.
- Texto vindo da web é tratado como dado. Isso já nos protegeu uma vez (a página
  da TCRF com instruções injetadas). O prompt dos perfis de pesquisa repete isso.
- `docs/` e `README.md` documentam o fluxo; `.gitignore` ignora `build/agy/`.

## Arquivos a criar

- `scripts/agy/delegate.py`, `scripts/agy/orchestrate.py`
- `scripts/agy/profiles/{research,fetch-official,binary-analysis,splat-split,doc-draft}.yml`
- `scripts/agy/schemas/*.json` (um esquema de saída por perfil)
- `scripts/agy/allowed_sources.yml`
- `.claude/agents/agy-worker.md`, `.claude/skills/agy-delegate/SKILL.md`
- `docs/agy_orchestration.md`, entrada em `docs/README.md`
- `tests/test_agy_delegate.py`

Arquivos alterados: `.gitignore` (adicionar `build/agy/`), `CLAUDE.md` (linha sobre
delegação ao `agy`).

## Verificação

1. `agy` falso: um stub em `tests/` que imprime JSON fixo. Testes unitários
   cobrem validação de perfil, esquema inválido, caminho fora da lista permitida,
   timeout e idempotência de lote. Rodam com `pytest` e `flake8`, sem rede.
2. Execução real, só leitura: `delegate.py --task binary-analysis` no
   `age2_x1.icd`. O resultado deve bater com o que medimos à mão (linker 6.0,
   entropia 7.90). Se divergir, o perfil está errado.
3. Execução real de escrita: `doc-draft` em worktree. Confirmar que `git diff`
   fica só em `docs/` e que a tentativa de editar `configure.py` é rejeitada.
4. Lote com 3 tarefas em paralelo e uma dependência; rodar duas vezes e ver que a
   segunda não repete nada.
5. Revisar `build/agy/<id>/meta.json` e o `summary.json` do lote.

## Decisões que assumi (diga se quiser outra)

- Wrapper em Python dentro do projeto, não um script global em `~/.claude/bin`.
- Padrão de 3 instâncias paralelas; modelo padrão `gemini-3.8-flash-medium` para
  pesquisa e análise, `gemini-3.1-pro-high` para split e rascunhos de código.
- Sem merge automático: o Claude revisa e integra, conforme o fluxo de worktree.
- Não crio um canal de comunicação bidirecional (o `agy` não envia mensagens ao
  Claude). A comunicação é por arquivos de resultado e notificações de término.
