# Pipeline Programático de Decompilação Iterativa

Este documento estabelece o fluxo oficial e idempotente para agentes realizarem o processo de engenharia reversa, staging de rascunhos em C/C++, compilação local via MWCC e validação de 100% bit-match antes da promoção oficial ao repositório.

## Estrutura e Ferramental

O script central `scripts/decomp_pipeline.py` implementa todas as etapas de forma determinística:

1. **Staging isolado (`staging/`):**
   * Cria scaffolds de rascunho em `staging/<func_name>.cpp`.
   * Pasta ignorada pelo git para evitar poluição da árvore de código de produção e respeitar a regra de que `configure.py` só registra objetos prontos para match.
   * Preserva alterações existentes caso o arquivo já tenha sido criado (idempotente).

   ```sh
   .venv/bin/python scripts/decomp_pipeline.py stage --func func_00220C60 --vram 0x220C60 --size 0x70
   ```

2. **Compilação do rascunho:**
   * Invoca o compilador CodeWarrior MIPS PS2 (`mwccps2.exe`) via `wibo` com as flags oficiais do projeto (`-O3 -inline on -msext on -char signed -sym off -lang=c++`).
   
   ```sh
   .venv/bin/python scripts/decomp_pipeline.py compile --source staging/func_00220C60.cpp
   ```

3. **Verificação de Diff e Cálculo de Match:**
   * Extrai o símbolo e suas realocações do objeto `.o` recém-compilado.
   * Compara com os bytes exatos do segmento correspondente no ELF original (`orig/SLES-50282/AOK.ELF`).
   * Retorna status booleano de match, porcentagem e os offsets dos primeiros mismatches encontrados.

   ```sh
   .venv/bin/python scripts/decomp_pipeline.py diff --func func_00220C60 --vram 0x220C60 --size 0x64 --obj staging/func_00220C60.o
   ```

4. **Refinamento e Estruturação de Tipos:**
   * Iterar no arquivo de staging seguindo [`recomp_ready_decomp_guidelines.md`](recomp_ready_decomp_guidelines.md):
     - Substituir acessos numéricos diretos por `struct` tipada.
     - Tipos fixos `u8/u16/u32/s32`.
     - Preservar bit-match durante todo o refatoramento.

5. **Promoção para a Codebase Oficial:**
   * Uma vez atingido o match de 100%, o comando `promote` move o código para `src/<module>/`, atualiza `config/SLES-50282/config.yml`, `config/SLES-50282/symbols.txt` e `configure.py` de maneira idempotente.

   ```sh
   .venv/bin/python scripts/decomp_pipeline.py promote \
     --func func_00220C60 \
     --module kcet \
     --source staging/func_00220C60.cpp \
     --header kt_thread_spawn.h \
     --vram 0x220C60 \
     --offset 0x120E40 \
     --size 0x70
   ```
