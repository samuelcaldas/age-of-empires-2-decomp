# Diretrizes para um decomp utilizável também por recomp/shim nativo

Público: agentes de decomp. Complementa (não substitui) as regras de correspondência de bytes do projeto.

## Por que isso existe

O projeto `aoe2-ps2-recomp` mantém o código do motor gerado automaticamente a partir do ELF e quer substituir, módulo
por módulo, a camada KCET por código nativo escrito a partir **deste** decomp. Para isso o decomp precisa dizer não só
"bate com o binário", mas também **o que a função faz**: tipos, formatos de dados, códigos de retorno, efeitos.

Regra central: **o C que bate 100% continua sendo a fonte de verdade.** Você acrescenta significado ao redor dele; não
reescreve a lógica por legibilidade. A correspondência (`objdiff`/CI) é o juiz e nunca pode regredir.

## O que fazer (por módulo KCET, nesta ordem)

1. **Estruturas nomeadas com layout fixo.** Troque `*(int *)(p + 108)` por campo de `struct`, com
   `_Static_assert(sizeof(...))` e `offsetof` dos campos. Registros em tabelas (ex.: o registro de 8 bytes do módulo de
   arquivos) viram `struct` própria. Se o nome do campo é incerto, use `field_6c` e comente o que se sabe.
2. **Tipos de largura fixa.** Use `u8/u16/u32/s32/u64`. `long` e `void *` têm tamanho diferente no host. Endereços do
   guest (ponteiros de 32 bits) recebem `typedef u32 GuestAddr;` e são distinguidos de ponteiros reais sempre que a
   função só os trata como número.
3. **Símbolos no lugar de endereços absolutos.** `*(volatile int *)0x4F1510` e `(0x4F1508 >> 16) << 16` viram
   `extern` nomeado (`D_4F1510`) com tipo. Sem constantes de endereço soltas em código novo.
4. **Constantes e enums.** Códigos de retorno, tipos (`kind`), comandos e limites (`< 4`, `< 29`) viram `enum`/`#define`
   com nome por papel. O shim precisa devolver exatamente esses valores.
5. **Funções de fronteira primeiro.** Priorize as funções que o motor chama (veja o inventário do projeto consumidor).
   Para as que hoje estão em forma literal do assembly (registradores `r_v0`, `r_a0`, `goto`): tente a versão
   estruturada; **só a aceite se continuar batendo**. Se não bater, mantenha a literal e documente a intenção no
   sidecar.
6. **Sidecar por função** (ver formato abaixo).
7. **Vetores de teste** para funções puras de memória (ver abaixo).
8. **Compilação no host.** O módulo deve compilar (só a lógica, com as chamadas externas como ponteiros/stubs de teste)
   com `-m32` ou com os tipos de largura fixa, sem asm inline fora de `#if defined(__mips__)`.

## O que não fazer

- Não reordenar, fundir ou "simplificar" expressões se isso quebrar a correspondência. Renomear, tipar campos e
  comentar não afeta o objeto; reordenação afeta.
- Não inventar semântica: se não sabe, escreva `unknown` no sidecar e diga qual evidência falta.
- Não remover comentários de endereço (`/* 0x00125A70 */`): o projeto consumidor usa isso para ancorar.
- Não editar `orig/` nem os artefatos de build.

## Formato do sidecar

Um arquivo por módulo: `docs/recomp/<modulo>.yaml` (ex.: `docs/recomp/kt_file.yaml`). Uma entrada por função.

```yaml
module: kt_file
functions:
  func_00125A70:            # mesmo símbolo do C
    role: table_lookup      # table_lookup | disc_io | state_query | dispatch | kernel_wrapper | hw_access | pure_helper
    purity: memory_only     # memory_only | hardware | os_service | pure
    blocking: none          # none | waits_on:<o_que> (semáforo, RPC, vsync, ...)
    args:
      - {name: key, type: s32}
      - {name: table, type: "RecordTable8*", note: "ordenada por id"}
    returns:
      type: GuestAddr
      values: {0: "não encontrado"}
    memory_effects: []       # regiões escritas, ex. "out_buf[0..len]"
    errors: [3]              # códigos que a função pode devolver/gerar
    callers_known: [func_0012D0E0]
    test_vectors: tests/recomp/kt_file/lookup_by_id.json   # opcional
    confidence: high         # high | medium | low
    open_questions: []
```

Regras: `purity: hardware` ou `os_service` exige dizer **qual** efeito (DMA, SIF, semáforo). `blocking` nunca fica em
branco. `confidence: low` exige `open_questions` preenchido.

## Vetores de teste (funções puras)

JSON simples: estado inicial da memória (bytes em hex, com endereço relativo), argumentos, retorno esperado, bytes
escritos. Gere-os rodando a própria função do decomp compilada no host sobre entradas escolhidas (bordas: tabela vazia,
um registro, muitos, chave menor/maior que todos, ponteiro nulo). O projeto consumidor os confere também contra o
original recompilado; divergência vira bug a investigar, não vetor a corrigir.

## Exemplo aplicado (módulo de arquivos)

Antes (padrão encontrado):

```c
entry = (char *)table + (mid << 3);
if (key < func_0012CB10(*(unsigned short *)entry)) { ... }
```

Depois (mesma lógica, mesma geração de código, com significado):

```c
typedef struct { u16 id; u16 aux; u32 payload; } FileRecord;   /* 8 bytes */
_Static_assert(sizeof(FileRecord) == 8, "FileRecord size");
...
entry = (FileRecord *)table + mid;
if (key < func_0012CB10(entry->id)) { ... }
```

Confirme com `objdiff` antes de seguir. Se o objeto mudar, volte à forma anterior e anote no sidecar.

## Critério de pronto de um módulo

- Correspondência de bytes mantida (mesmo resultado do CI).
- Nenhum deslocamento mágico nem endereço absoluto novo nas funções de fronteira.
- Sidecar completo para todas as funções, `confidence` honesto.
- Vetores para toda função `purity: memory_only`/`pure`.
- Compila no host com tipos de largura fixa.

## Prioridade sugerida

`kt_file` e o servidor de CD (acessores e leitura de registros) → `kt_kernel` (já estruturado, falta sidecar) →
`kt_mouse`/`kt_keybd`/`kt_usbkeybd_drv`/`kt_libpad` → `kt_mc_2` → `kt_hd` → `kt_gpu`.
