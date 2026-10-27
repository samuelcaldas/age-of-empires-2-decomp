# Plano de Decompilação Completa do Subsistema Gráfico (Full Graphics Decomp)

## Contexto

O subsistema gráfico do Age of Empires II (PS2 PAL `SLES-50282`) é composto por duas camadas interligadas:
1. **Camada de Alto Nível (`src/render/`)**: Originária da base de código do PC, gerencia superfícies, viewports, decodificação de `.SLP`, tabelas de paletas e o ciclo de vida do `RenderManager`. Cerca de 80-90% desse código já se encontra em C++ estruturado e com testes comportamentais.
2. **Camada de Baixo Nível / Hardware (`src/kcet/kt_gpu.c` e `render_packet_builder_*.cpp` + `post_21CD20`)**: Implementada pela Konami (KCET), responsável pela inicialização dos registradores do Graphics Synthesizer (GS), canais DMA (GIF/VIF) e empacotamento de primitivas gráficas (GIFtag, RGBAQ, XYZ2, UV).

O objetivo deste plano é atingir o **Full Decomp Puro**: 100% de cobertura e matching exato (bit-for-bit no MWCC PS2 2.3.1.01 e EE-GCC 2.9-991111) de todas as rotinas gráficas no repositório `age-of-empires-2-decomp`.

---

## Estado Atual do Subsistema

| Componente | Total de Módulos | Status Atual | Compilador Alvo |
|---|---|---|---|
| **KCET GPU Driver** (`src/kcet/kt_gpu.c`) | 7 funções (0x125808 - 0x125A70) | **Matching** | EE-GCC 2.9-991111 |
| **Render Manager Core / Subsystems** (`src/render/render_manager_*.cpp`) | 40 módulos | ~33 Matching, 7 NonMatching | MWCC PS2 2.3.1.01 |
| **Render Helpers** (`src/render/render_helper_*.cpp`) | 24 módulos (0x117910 - 0x11A4F0) | Funcional (NonMatching) | MWCC PS2 2.3.1.01 |
| **Render Viewports** (`src/render/render_viewport_*.cpp`) | 9 módulos (0x11A700 - 0x11B310) | Funcional (NonMatching) | MWCC PS2 2.3.1.01 |
| **Palette Helpers & DRS** (`src/render/render_palette_helper_*.cpp`, DRS) | 8 módulos (0x11B4E0 - 0x11BFD0) | Funcional (NonMatching) | MWCC PS2 2.3.1.01 |
| **Packet Builders** (`src/render/render_packet_builder_*.cpp`) | 5 módulos (0x11C1B0 - 0x11CF00) | Funcional (NonMatching) | MWCC PS2 2.3.1.01 |
| **GS Primitive Pipeline Bruto** (`post_21CD20`, 0x21CFB0 - 0x224000) | ~10 funções críticas não fatiadas | Binário Bruto (`bin`) | MWCC PS2 2.3.1.01 |

---

## Fases de Execução

### Fase 1: Fatiamento e Decompilação do Pipeline de Primitivas GS (`post_21CD20`)
A área atualmente contida no bloco `post_21CD20` (entre `0x11D190` e `0x166960` em arquivo, correspondendo a VRAM `0x21CF30` em diante) contém as rotinas cruciais que pegam coordenadas de tela e geram comandos GS:
- **1.1 Fatiamento no Splat (`config/SLES-50282/config.yml` e `symbols.txt`)**:
  - `func_0021CFB0`: Blit de textura / desenho de quads com retângulos de origem/destino.
  - `func_0021D2C0`: Preenchimento de retângulos sólidos (clear rect / solid fill).
  - `func_0021DE90`: Upload de CLUT / tabelas de paleta para a memória eDRAM do GS.
  - `func_0021DF50`: Configuração de textura e parâmetros de render context.
  - `func_0021E350` e `func_0021E370`: Configuração de viewport de saída e blit final para a tela.
  - `func_00221B60`: Alocação/obtenção do buffer de pacotes DMA ativo.
  - `func_0021FEC0` e `func_0021FED0`: Renderizadores de fontes e glifos na tela.
- **1.2 Criação dos Testes Comportamentais TDD**:
  - Implementar testes nativos (`tests/native/*_test.cpp` e harnesses pytest em `tests/test_*.py`) validando os parâmetros recebidos e a estrutura dos pacotes DMA/GIF gerados.
- **1.3 Implementação em C++**:
  - Criar arquivos dedicados em `src/render/` (ex: `render_packet_quad_21cfb0.cpp`, `render_rect_fill_21d2c0.cpp`, `render_gs_clut_21de90.cpp`, etc.).
  - Registrar no `configure.py`.

### Fase 2: Fechamento dos Módulos Restantes do RenderManager
Harmonizar e levar a 100% Matching os 7 módulos do `RenderManager` que ainda estão como `NonMatching`:
- `render/render_manager_core.cpp` (0x84520)
- `render/render_manager_screen.cpp` (0x849A0)
- `render/render_manager_methods.cpp` (0x84C68)
- `render/render_manager_query.cpp` (0x84E08)
- `render/render_manager_messages.cpp` (0x84EC0)
- `render/render_manager_palette_table.cpp` (0x89660)
- `render/render_manager_error.cpp` (0x89A10)
- `trade/trade_action_stream_render.cpp` (0x82A70)

**Ação:** Ajustar alocação de variáveis locais, inlining e ordem de registradores usando `objdiff` até a flag mudar de `NonMatching` para `Matching`.

### Fase 3: Matching das Camadas Auxiliares e Viewports
Refinar o código C++ existente nos módulos já funcionais:
- **3.1 Render Helpers (`render_helper_*.cpp`)**: 24 arquivos cobrindo cálculos de projeção 2D, clip rects e conversões de coordenadas.
- **3.2 Render Viewports (`render_viewport_*.cpp`)**: 9 arquivos lidando com scroll do mapa, posicionamento da câmera e bounding boxes de visão.
- **3.3 Palette Helpers (`render_palette_helper_*.cpp`)**: 6 arquivos de mesclagem de cores e mapeamento de índices de jogadores.
- **3.4 DRS Loader (`render_drs_loader_21bc30.cpp`)**: Carregamento de sprites e recursos DRS do disco.

### Fase 4: Matching dos Packet Builders e Auditoria do KCET GPU
- **4.1 Matching de `render_packet_builder_*.cpp`**:
  - `render_packet_builder_21bfd0`
  - `render_packet_builder_21c410`
  - `render_packet_builder_21c710`
  - `render_packet_builder_21c990`
  - `render_packet_builder_21cd20`
  - Refinar literais de 64/128 bits e empacotamento de bitfields (`PackBitfield42`, `PackBitfield48`, `BuildLineTag`) para coincidir com a saída exata do compilador CodeWarrior.
- **4.2 Auditoria da Tabela de Despacho KCET (`D_38C740`)**:
  - Mapear handlers 0 a 22 chamados por `ktGpuDispatchCommand` para garantir que todas as funções KCET GPU estejam registradas e verificadas.

---

## Verificação e Regras TDD

Todas as alterações devem seguir estritamente as regras de desenvolvimento do repositório:
1. **Red**: Escrever teste unitário comportamental em `tests/native/*_test.cpp` e executar via harness `pytest` (verificando falha esperada).
2. **Green**: Implementar código C++ necessário em `src/render/` até o teste passar.
3. **Refactor & Match**: Compilar com `ninja` / CodeWarrior PS2 (`docker-dev`) e inspecionar diff binário via `objdiff` até 100% de coincidência.
4. **Regression Gate**: Executar `pytest -q -ra` e `python -m scripts.observability status` garantindo zero regressões.
