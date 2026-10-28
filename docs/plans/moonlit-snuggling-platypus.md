# Plano de Descompilação do Layout dos Painéis de HUD (Comando e Recursos - PC Demo & PS2)

## Contexto

No Age of Empires II (tanto na versão PC Demo/Trial quanto na versão PS2 PAL `SLES-50282`), a interface do usuário in-game (HUD) é composta por duas estruturas principais:
1. **Barra Superior de Recursos (`Top Resource Bar`)**:
   - Exibe os contadores dos 4 recursos primários (madeira, comida, ouro, pedra).
   - Exibe o limite e ocupação populacional (`atual/teto`), além do ícone e nome da Era atual.
   - Botões de sistema e interação social (Menu, Diplomacia, Chat, Objetivos).
2. **Painel Inferior de Comando e Status (`Bottom Command & Status Panel`)**:
   - **Seção Esquerda (Minimapa)**: Área de projeção do mapa do mundo (radar 2:1) com alternadores de modo (econômico, militar, padrão).
   - **Seção Central (Status da Unidade/Edifício)**: Retrato da entidade ativa, indicador e barra de vida (HP), posturas/formações, guarnição e atributos de combate (ataque, armadura física, armadura contra perfuração, alcance, abates).
   - **Seção Direita (Matriz de Comandos e Ações)**: No PC, uma grade de 3 linhas por 5 colunas (15 botões de comando, tarefas de aldeão, construções e treinamento de unidades); no PS2, mapeamento adaptado com prompts para o DualShock 2 (D-pad, Cross, Circle, Square, Triangle).

Com as rotinas de rasterização SLP (`slp_rasterizer`), blitters (`render_blit_converter`) e clipper matemático (`render_clip_math`) já descompiladas e integradas no `main`, este plano visa formalizar e implementar as estruturas de geometria, hit-testing, estados de botões e composição gráfica dos painéis de HUD para as edições PC e PS2.

---

## Módulos e Objetivos

### Módulo 1: Geometria e Layout dos Painéis (`src/render/hud_panel_layout.cpp`)
- **Objetivo**: Formalizar as especificações de geometria e caixas delimitadoras de HUD para PC e PS2:
  - Suporte aos presets de resolução:
    - **PC 640x480**: Barra superior (640x22), Painel inferior (640x120 em Y=360: minimap 0..199, status 200..439, comando 440..639).
    - **PC 800x600**: Barra superior (800x24), Painel inferior com áreas estendidas de status e comando.
    - **PS2 640x448 / 640x512**: Barra superior e inferior ajustadas para safe area do GS de TV e limites de framebuffer.
  - Função de mapeamento de resolução: `hud_layout_init(HudLayoutConfig *cfg, HudPreset preset, int screen_w, int screen_h)`.
- **Arquivos**:
  - `include/hud_panel_layout.h`
  - `src/render/hud_panel_layout.cpp`
  - `tests/native/hud_panel_layout_test.cpp`
  - `tests/test_hud_panel_layout.py`

### Módulo 2: Apresentador e Hit-Testing da Barra de Recursos (`src/render/hud_resource_bar.cpp`)
- **Objetivo**: Gestão de dados, formatação e interação da barra de recursos:
  - Formatação e limites dos recursos do jogador (Wood, Food, Gold, Stone, Pop, Age).
  - Hit-testing de cliques do mouse ou ponteiro nos botões de sistema do topo (Menu, Diplomacia, Chat).
  - Verificação de visibilidade e clipping contra bordas da tela.
- **Arquivos**:
  - `include/hud_resource_bar.h`
  - `src/render/hud_resource_bar.cpp`
  - `tests/native/hud_resource_bar_test.cpp`
  - `tests/test_hud_resource_bar.py`

### Módulo 3: Matriz de Ações e Painel de Comando (`src/render/hud_command_bar.cpp`)
- **Objetivo**: Lógica da matriz de 15 botões de comando (3x5) e painel de status:
  - Configuração de slots de ação: ID de comando, ícone SLP, hotkey e estados (`NORMAL`, `HOVER`, `PRESSED`, `DISABLED`, `HIDDEN`).
  - Mapeamento PC (teclado/mouse) vs. PS2 (Gamepad: D-pad e botões de face).
  - Cálculo de coordenadas e hit-testing do clique de mouse em cada um dos 15 slots da matriz.
  - Cálculo da porcentagem da barra de HP (preenchimento verde/amarelo/vermelho proporcional) e alinhamento do retrato.
- **Arquivos**:
  - `include/hud_command_bar.h`
  - `src/render/hud_command_bar.cpp`
  - `tests/native/hud_command_bar_test.cpp`
  - `tests/test_hud_command_bar.py`

### Módulo 4: Renderizador e Compositor de HUD (`src/render/hud_panel_renderer.cpp`)
- **Objetivo**: Compor o HUD final no buffer de tela utilizando as rotinas gráficas já existentes:
  - Renderização da barra de vida com gradiente de cor dependendo do percentual de HP restante.
  - Desenho das molduras de botões (bordas normais, pressionadas e desabilitadas).
  - Blit das regiões de HUD sobre o framebuffer usando `render_clip_math` para prevenir qualquer escrita fora dos limites de tela.
- **Arquivos**:
  - `include/hud_panel_renderer.h`
  - `src/render/hud_panel_renderer.cpp`
  - `tests/native/hud_panel_renderer_test.cpp`
  - `tests/test_hud_panel_renderer.py`

---

## Ciclo de Desenvolvimento TDD (Mandatory Rules)

Para cada módulo:
1. **Red**: Criar teste comportamental em `tests/native/<module>_test.cpp` e harness `pytest` em `tests/test_<module>.py`. Executar no container Docker (`docker-dev` / `aoe-tests:verification`) e comprovar a falha esperada.
2. **Green**: Implementar código em `src/render/<module>.cpp` e `include/<module>.h`. Re-executar o teste e comprovar aprovação (`PASS`).
3. **Refactor**: Otimizar a lógica mantendo total aderência a C++03 / C linkage e regras de compilação sem warnings.
4. **Regression Gate**: Executar a suite completa `python -m pytest -q -ra tests/test_hud_*.py tests/test_render_*.py tests/test_slp_*.py` garantindo zero regressões.
