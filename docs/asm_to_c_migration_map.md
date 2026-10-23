# Inventário e Mapa de Migração de Código Assembly (ASM) para C/C++

Mapeamento abrangente de todos os arquivos, módulos e funções na codebase que atualmente residem como **código assembly MIPS (`__asm__` / `.word`)** e que ainda precisam ser reescritos em código legível e portável em C/C++.

---

## 1. Resumo Executivo da Codebase

A codebase de *Age of Empires II: The Age of Kings* (PS2 PAL `SLES-50282`) encontra-se dividida em três estados estruturais:

1. **C / C++ Puro (100% Descompilado e Bit-Exact)**:
   - Toda a suíte de Rede e DirectPlay (`src/network_dplay_*.cpp`, `network_message_handler_3385c0.cpp`, etc.).
   - Drivers de periféricos KCET USB (`src/kt_mouse.c`, `src/kt_keybd.c`, `src/kt_usbkeybd_drv.c`).
   - Subsistemas do motor Genie: Grade Espacial (`zone_spatial_grid_*`), Pool de Nós (`node_pool_*`), Malhas de Elevação (`elevation_mesh_*`), Controladores e Rotas Comerciais.
   - Biblioteca Padrão C Metrowerks MSL (`msl/atoi.c`, `msl/atol.c`, `msl/rand.c`, `msl/srand.c`, `msl/strcpy.c`, `msl/strcmp.c`, `msl/strcat.c`).
2. **Código Assembly MIPS com Matching Preservado (Alvo Desta Migração)**:
   - **16 arquivos** em `src/`.
   - **519.736 linhas de código**.
   - **1.906 funções**.
   - Preservados como blocos inline `__asm__` (`.word 0x...` ou mnemônicos MIPS diretos) garantindo 100% de paridade binária com o original, mas ainda não descompilados para C/C++ de alto nível.
3. **Lacunas Binárias no ELF (`type: bin`)**:
   - **26 blocos residuais** no `AOK.ELF` mapeados em `config.yml` aguardando fatiamento.

---

## 2. Inventário Completo dos 16 Arquivos ASM em `src/`

```mermaid
pie title Distribuição de Funções em Assembly (Total: 1.906 funções)
    "Lobby Overlay (lobby_overlay.c)": 814
    "Memory Card 2 (kt_mc_2.c)": 337
    "CD/DVD Server (kt_libcdvd_server.c)": 150
    "Setup Menu (smenu_overlay.c)": 144
    "Tech Tree Help (thelp_overlay.c)": 119
    "DualShock Pad (kt_libpad.c)": 100
    "Random Map Script (dcomp_overlay.c)": 71
    "Demais 9 Módulos": 171
```

### Tabela Geral Consolidada

| Arquivo Fonte | Subcutâneo / Domínio | Linhas | Funções | Tamanho (.text) | Status de Teste |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **`src/mo_ov_overlay.c`** | Overlay (Vídeo PSS) | 311 | 2 | 192 B | 100% Matched |
| **`src/rmmmem_overlay.c`** | Overlay (Heap RMS) | 495 | 5 | 832 B | 100% Matched |
| **`src/kt_gpu.c`** | KCET Hardware (GS) | 252 | 5 | 1.072 B | 100% Matched |
| **`src/libscf.c`** | Sony SCF (Config/Idioma) | 541 | 11 | 2.144 B | 100% Matched |
| **`src/hist_overlay.c`** | Overlay (História) | 92.649 | 13 | 5.440 B | 100% Matched |
| **`src/multim_overlay.c`** | Overlay (Slideshow) | 42.221 | 19 | 7.872 B | 100% Matched |
| **`src/kt_hd.c`** | KCET Hardware (PS2 HDD) | 1.020 | 27 | 2.600 B | 100% Matched |
| **`src/kt_kernel.c`** | KCET Hardware (Kernel/OS) | 496 | 39 | 3.172 B | Decompilado (C Puro + Testes Nativos) |
| **`src/kt_file.c`** | KCET Hardware (I/O VFS) | 1.677 | 50 | 5.760 B | 100% Matched |
| **`src/dcomp_overlay.c`** | Overlay (Gerador RMS) | 23.589 | 71 | 40.128 B | 100% Matched |
| **`src/kt_libpad.c`** | KCET Hardware (DualShock) | 4.486 | 100 | 12.144 B | 100% Matched |
| **`src/thelp_overlay.c`** | Overlay (Tech Tree) | 38.213 | 119 | 70.848 B | 100% Matched |
| **`src/smenu_overlay.c`** | Overlay (Setup/Menus) | 49.515 | 144 | 90.560 B | 100% Matched |
| **`src/kt_libcdvd_server.c`** | KCET Hardware (CD/DVD) | 5.530 | 150 | 14.072 B | 100% Matched |
| **`src/kt_mc_2.c`** | KCET Hardware (Memory Card)| 10.800 | 337 | 35.808 B | 100% Matched |
| **`src/lobby_overlay.c`** | Overlay (Multiplayer) | 247.103 | 814 | 337.472 B | 100% Matched |
| **TOTAL** | — | **519.736** | **1.906** | **631.328 B** *(~616 KB)* | **16 arquivos** |

---

## 3. Grupo 1: Os 8 Overlays Dinâmicos (`*_CD.BIN`)

Estes arquivos contêm o código carregado dinamicamente do CD pelo CodeWarrior para a memória RAM (`0x01D98000` e adjacentes).

### 1. `src/mo_ov_overlay.c` (2 funções / 311 linhas)
* **VRAM**: `0x01ED7000`
* **Descrição**: Ponte de controle para execução de vídeos cinemáticos em segundo plano via subsistema PSS.
* **Complexidade**: Muito Baixa. Apenas rotinas de sincronização e chamadas de interrupção.

### 2. `src/rmmmem_overlay.c` (5 funções / 495 linhas)
* **VRAM**: `0x01D98000`
* **Descrição**: Gerenciador de alocação de memória (Heap) dedicado para geração procedural de mapas aleatórios.
* **Complexidade**: Baixa. Estrutura de pool de blocos e controle de ponteiros de memória.

### 3. `src/hist_overlay.c` (13 funções / 92.649 linhas)
* **VRAM**: `0x01D98000`
* **Descrição**: Visualizador da enciclopédia histórica e tela de contexto de missões. A maior parte das 92k linhas é composta por dados brutos `.rodata` (textos e tabelas).
* **Complexidade**: Média. Poucas funções lógicas (13 funções) manipulando grandes tabelas de strings.

### 4. `src/multim_overlay.c` (19 funções / 42.221 linhas)
* **VRAM**: `0x01D98000`
* **Descrição**: Controlador de apresentação de slides de campanhas e sincronização de dublagens.
* **Complexidade**: Média. Controle de temporizadores e paginação de imagens.

### 5. `src/dcomp_overlay.c` (71 funções / 23.589 linhas)
* **VRAM**: `0x01D98000`
* **Descrição**: Motor de interpretação de scripts RMS (*Random Map Script* — lê `arabia.rms`, `black_forest.rms`) e gerador procedural de relevo, florestas e recursos.
* **Complexidade**: Alta. Algoritmos matemáticos de colocação de terreno e geração de sementes randômicas.

### 6. `src/thelp_overlay.c` (119 funções / 38.213 linhas)
* **VRAM**: `0x01F68000`
* **Descrição**: Navegador interativo da Árvore Tecnológica (*Tech Tree*) e janelas de ajuda em tempo real durante a partida.
* **Complexidade**: Média-Alta. Lógica de UI de grafos de tecnologias, botões e renderização de ícones.

### 7. `src/smenu_overlay.c` (144 funções / 49.515 linhas)
* **VRAM**: `0x01D98000`
* **Descrição**: Menus principais, carrossel de campanhas, telas de configuração de áudio/vídeo e opções de jogo.
* **Complexidade**: Alta. Gerenciamento extensivo de estados de interface do usuário, eventos de cursor e fluxo de menus.

### 8. `src/lobby_overlay.c` (814 funções / 247.103 linhas)
* **VRAM**: `0x01D98000`
* **Descrição**: Sistema de saguão multiplayer completo para console (criação de salas, seleção de facções, ping, serialização de pacotes via `ps2_DataTrans`).
* **Complexidade**: Muito Alta. É o maior componente individual de overlay do jogo.

---

## 4. Grupo 2: A Camada de Hardware KCET & Sistema Sony (HAL)

Módulos desenvolvidos pela Konami Tokyo para adaptar o motor de PC ao hardware do PlayStation 2.

### 1. `src/kt_gpu.c` (5 funções / 252 linhas)
* **Descrição**: Inicialização de baixo nível do Graphics Synthesizer (GS), configuração de buffers de exibição e modos de vídeo.
* **Prioridade**: Alta / Fácil.

### 2. `src/libscf.c` (11 funções / 541 linhas)
* **Descrição**: *System Configuration Framework* da Sony. Lê as configurações da EEPROM/OSD do console (idioma, fuso horário, formato de tela 4:3 / 16:9).
* **Prioridade**: Alta / Fácil.

### 3. `src/kt_hd.c` (27 funções / 1.020 linhas)
* **Descrição**: Interface de comunicação com o disco rígido oficial do PS2 (HDD) e sistema de arquivos PFS (`pfs0:`).
* **Prioridade**: Média.

### 4. `src/kt_kernel.c` (39 funções / 1.334 linhas)
* **Descrição**: Abstração de chamadas do sistema operacional do Emotion Engine (criação de threads, semáforos, manipuladores de interrupção e DMA).
* **Prioridade**: Alta (fundamental para substituir por pthreads ou C++ std::thread no port nativo).

### 5. `src/kt_file.c` (50 funções / 1.677 linhas)
* **Descrição**: Camada de I/O de arquivos (*Virtual File System*) unificando acesso a CD-ROM (`cdrom0:`), Memory Card (`mc0:`), HDD e porta Host.
* **Prioridade**: Alta (ponto focal para redirecionar arquivos para o disco local no PC).

### 6. `src/kt_libpad.c` (100 funções / 4.486 linhas)
* **Descrição**: Biblioteca completa de controle do DualShock 2 (mapeamento de botões, sensibilidade analógica e acionadores de vibração).
* **Prioridade**: Média.

### 7. `src/kt_libcdvd_server.c` (150 funções / 5.530 linhas)
* **Descrição**: Servidor de leitura do leitor de CD/DVD do console, leitura assíncrona de setores e tratamento de erros do drive óptico.
* **Prioridade**: Média.

### 8. `src/kt_mc_2.c` (337 funções / 10.800 linhas)
* **Descrição**: Gerenciador avançado de Memory Cards (leitura/escrita de saves, verificação de espaço livre, ícones de save 3D e cabeçalhos de arquivo).
* **Prioridade**: Média.

---

## 5. Roteiro Recomendado de Migração (Faseamento)

```mermaid
flowchart TD
    FASE1["Fase 1: Módulos Rápidos e Críticos<br/>(kt_gpu, libscf, mo_ov, rmmmem)<br/>17 funções"]
    FASE2["Fase 2: Infraestrutura de I/O e Overlays Estáticos<br/>(kt_kernel, kt_file, kt_hd, hist, multim)<br/>148 funções"]
    FASE3["Fase 3: Lógica de Menus e Gerador de Mapas<br/>(dcomp, smenu, thelp)<br/>334 funções"]
    FASE4["Fase 4: Subsistemas Pesados de Periféricos e Lobby<br/>(kt_libpad, kt_libcdvd, kt_mc_2, lobby)<br/>1.401 funções"]

    FASE1 --> FASE2 --> FASE3 --> FASE4
```

1. **Fase 1 (Micro-módulos e HAL básico — 17 funções)**:
   - `src/kt_gpu.c` (5 fns)
   - `src/libscf.c` (11 fns)
   - `src/mo_ov_overlay.c` (2 fns)
   - `src/rmmmem_overlay.c` (5 fns)
2. **Fase 2 (I/O, Kernel e Apresentação — 148 funções)**:
   - `src/kt_kernel.c` (39 fns)
   - `src/kt_file.c` (50 fns)
   - `src/kt_hd.c` (27 fns)
   - `src/hist_overlay.c` (13 fns)
   - `src/multim_overlay.c` (19 fns)
3. **Fase 3 (Geração de Mapas e Menus de Jogo — 334 funções)**:
   - `src/dcomp_overlay.c` (71 fns)
   - `src/smenu_overlay.c` (144 fns)
   - `src/thelp_overlay.c` (119 fns)
4. **Fase 4 (Periféricos Complexos e Saguão Multijogador — 1.401 funções)**:
   - `src/kt_libpad.c` (100 fns)
   - `src/kt_libcdvd_server.c` (150 fns)
   - `src/kt_mc_2.c` (337 fns)
   - `src/lobby_overlay.c` (814 fns)
