# Plano de Descompilação da Camada Gráfica da Demo de PC (Genie Graphics Reference)

## Contexto

O binário `EMPIRES2.EXE` da demo de PC (`orig/AOE2_TRIAL_1999/EMPIRES2.EXE`, build de 18/10/1999) foi construído com MSVC 6.0 SP3 e utiliza o pipeline de software rasterizer 2D da Ensemble Studios (Genie Engine):
1. **Paletas e Misturas de Cores**: Tabelas de 256 cores, mapeamento por menor distância euclidiana, cálculo de brilho e mistura alfa em software (`RenderPaletteTable`, `RenderPaletteBlend`).
2. **Sprites .SLP**: Decodificação de comandos de linha (runs de pixels literais, saltos transparentes, sombreamento/transparência de contorno e sombras com dithering). Atualmente o repositório possui validação de cabeçalhos em `src/render/slp_decoder.cpp`, mas ainda não possui a rotina de rasterização dos comandos de pixel.
3. **Superfícies e Conversão de Cores (Blits 8-bit -> 16/32-bit)**: O jogo renderiza nativamente em 8bpp paletizado e converte (ou blita diretamente via DirectDraw) para o formato do display (RGB555, RGB565 ou ARGB8888).
4. **Cálculo de Clip Rectangles e Viewports**: Recorte de coordenadas de sprites e tiles contra a área de tela visível (`render_viewport_21ae90.cpp` e afins).

Este plano visa extrair, implementar e validar essas rotinas fundamentais do Genie Engine em C++ sob `src/render/` usando a metodologia TDD rigorosa com testes nativos (`-m32` g++), servindo de referência formal para o recompilador moderno (`aoe2-ps2-recomp` / `IRenderer`).

---

## Módulos e Objetivos

### Módulo 1: Rasterizador de Comandos de Linha SLP (`src/render/slp_rasterizer.cpp`)
- **Objetivo**: Completar `src/render/slp_decoder.cpp` com a máquina de estados de desenho de pixels de uma linha SLP:
  - `CMD 0x00..0x03` / Block runs: Saltos transparentes (skip X pixels).
  - `CMD 0x06` / Player color runs: Substituição por paleta de jogador.
  - `CMD 0x07` / Shadow / Dither: Blit com tabela de sombreamento (50% alpha dither).
  - `CMD 0x0A..0x0F` / Extended commands: Literal pixel copying para o buffer de destino.
- **Arquivos**:
  - `include/slp_rasterizer.h`
  - `src/render/slp_rasterizer.cpp`
  - `tests/native/slp_rasterizer_test.cpp`
  - `tests/test_slp_rasterizer.py`

### Módulo 2: Conversor e Blitter de Superfície 8bpp -> 16bpp / 32bpp (`src/render/render_blit_converter.cpp`)
- **Objetivo**: Implementar o software blitter do Genie Engine que transfere retângulos de 8-bit paletizados para buffers de visualização modernos:
  - Blit paletizado 8bpp -> RGB565 (16-bit com stride ajustado).
  - Blit paletizado 8bpp -> ARGB8888 (32-bit padrão de host moderno / textura OpenGL/Vulkan).
  - Suporte a color key transparente e clip bounds (min_x, max_x, min_y, max_y).
- **Arquivos**:
  - `include/render_blit_converter.h`
  - `src/render/render_blit_converter.cpp`
  - `tests/native/render_blit_converter_test.cpp`
  - `tests/test_render_blit_converter.py`

### Módulo 3: Clipper de Retângulos e Viewport 2D (`src/render/render_clip_math.cpp`)
- **Objetivo**: Formalizar as rotinas de interseção e corte retangular de tela encontradas em `render_viewport_21ae90.cpp`:
  - Recorte de caixas delimitadoras de sprites contra janelas de UI.
  - Ajuste de ponteiros de origem e offsets de destino quando partes do sprite saem da tela (coordenadas negativas ou superiores à resolução).
- **Arquivos**:
  - `include/render_clip_math.h`
  - `src/render/render_clip_math.cpp`
  - `tests/native/render_clip_math_test.cpp`
  - `tests/test_render_clip_math.py`

---

## Ciclo de Desenvolvimento TDD (Mandatory Rules)

Para cada módulo:
1. **Red**: Criar teste comportamental em `tests/native/<module>_test.cpp` e harness `pytest` em `tests/test_<module>.py`. Executar no container Docker (`docker-dev` / `aoe-tests:verification`) e comprovar a falha de compilação ou assertion esperada.
2. **Green**: Implementar código mínimo necessário em `src/render/<module>.cpp` e `include/<module>.h`. Re-executar o teste e comprovar 100% de aprovação (`PASS`).
3. **Refactor**: Otimizar laços de pixels, simplificar ramificações e manter código dentro das regras do repositório (estilo C++03, tipagem explícita, sem warnings).
4. **Regression Gate**: Executar a suite completa `python -m pytest -q -ra tests/test_render_*.py` garantindo zero regressões nos testes existentes.
