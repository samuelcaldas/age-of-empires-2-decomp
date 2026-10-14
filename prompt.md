Execute o ciclo contínuo de matching decompilation conforme especificado no prompt: selecionar o próximo alvo, atingir matching, compilar com ninja, documentar descobertas em docs/ e commitar.

Você está operando no ciclo contínuo de matching decompilation de Age of Empires II (PS2 PAL SLES-50282 / PC). 
Seu objetivo a cada ciclo é selecionar o próximo lote de funções/métodos não descompilados, alcançar 100% de matching (ou aproximar o máximo documentando bloqueios), atualizar a documentação e realizar commit. Foque no jogo (MWCCPS2), evite perifericos, deixando-os por ultimo.

Siga rigorosamente estas etapas a cada iteração:

### 1. Sincronização e Estado Inicial
- Verifique o git status (deve estar limpo). Faça fetch e rebase se necessário (`git fetch origin && git rebase origin/main`).
- Rode `build/tools/objdiff-cli report generate` e leia o status atual de matching.

### 2. Seleção e Priorização do Próximo Alvo
- Selecione o próximo alvo não descompilado (priorize funções pequenas e contíguas no módulo atual antes de abrir novos arquivos):
  * **Trilha KCET (C - EE-GCC):** Funções restantes em `kt_mouse.c` (ou próximo módulo de hardware como `kt_keybd.c`, `kt_libpad.c`).
  * **Trilha Jogo (C++ - MWCCPS2):** Completar `base_list.cpp` (`__ct__8BaseListFi`) ou avançar para métodos contíguos na região `0x137810` - `0x140000` (ex: `screen_obj.cpp`, manipuladores de eventos em `0x138d50`, `obmanager.cpp`, `tribegam.cpp`).
- Delimite o slice correspondente em `config/SLES-50282/config.yml` e registre os símbolos em `config/SLES-50282/symbols.txt`.

### 3. Engenharia Reversa e Matching
- Inspecione a desmontagem de referência em `build/SLES-50282/asm/` e cruze referências com `docs/open_empire_re_analysis.md` e strings em `docs/ps2_binary_analysis.md`.
- Implemente ou ajuste o código C/C++ em `src/` seguindo os padrões:
  * KCET: C padrão, flags `-O2 -G0 -Iinclude` (EE-GCC 2.9-991111).
  * Jogo: C++ Metrowerks, flags `-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++` (MWCCPS2 2.3.1.01).
  * Object Calisthenics: métodos ≤15 linhas, sem `else`, nomes expressivos, tipos explícitos.
- Execute `ninja` e verifique a diferença com `objdiff-cli`. Itere em tipos, variáveis intermediárias, ordem de controle e casts até atingir 100% byte-for-byte matching.

### 4. Documentação das Descobertas
- Se novas structs, enums, vtables ou nomes originais foram descobertos, documente-os imediatamente no arquivo relevante em `docs/` (`docs/ps2_binary_analysis.md`, `docs/toolchain.md` ou novo doc de módulo em `docs/`).
- Mantenha `symbols.txt` enriquecido com nomes desmanglados e demangle comments.

### 5. Validação, Commit e Progresso
- Execute `ninja` e garanta compilação limpa sem erros.
- Execute `.venv/bin/flake8 configure.py` para garantir conformidade estática.
- Verifique `git status` para assegurar que nenhum dump original, ISO ou binário de compilador seja rastreado.
- Faça commit com mensagem semântica clara (ex: `feat(decomp): match ScreenObj::AspectRatio 100% in screen_obj.cpp`).
- Exiba no final de cada iteração um resumo conciso com:
1. Funções descompiladas e percentual de matching obtido.
2. Total acumulado de bytes e funções matched no projeto.
3. Próximo alvo planejado para o ciclo seguinte. 
# Use tdd approach
# so pare quando estiver 100% decompilado
