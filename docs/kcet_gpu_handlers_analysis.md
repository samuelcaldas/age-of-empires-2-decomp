# Análise e Auditoria dos Handlers KCET GPU (D_38C740)

## Visão Geral

O driver KCET GPU (`src/kcet/kt_gpu.c` e `include/kt_gpu.h`) utiliza uma tabela de despacho indexada (`D_38C740`) contendo exatamente 29 ponteiros de funções (`KT_GPU_MAX_HANDLERS = 29`).
A rotina despachante `ktGpuDispatchCommand` (`func_001259C8`) valida se `kind < 29` e invoca `D_38C740[kind](p, cmd)`.

A tabela reside em VRAM `0x0038C740` (offset em arquivo `0x28C920` no ELF).

## Mapeamento Completo da Tabela de Despacho

| Handler | Endereço VRAM | Tamanho | Função / Papel |
|---|---|---|---|
| **0** | `0x123AC8` | 0x130 | Inicialização de contexto DMA / setup primário |
| **1** | `0x123BF8` | 0x128 | Configuração de modo de vídeo e resolução |
| **2** | `0x123D20` | 0x160 | Setup de buffers de visualização (display buffers) |
| **3** | `0x123E80` | 0x148 | Sincronização e controle de interrupção VSYNC |
| **4** | `0x123FC8` | 0x190 | Limpeza de tela e registradores GS |
| **5** | `0x124158` | 0x180 | Configuração do canal GIF DMA (CH 2) |
| **6** | `0x1242D8` | 0x1D0 | Configuração do canal VIF1 DMA (CH 1) |
| **7** | `0x1244A8` | 0x1A0 | Troca de buffers de frame (page flip) |
| **8** | `0x124648` | 0x200 | Transmissão de blocos de textura para eDRAM |
| **9** | `0x124848` | 0x320 | Setup de CLUT / tabelas de paleta de 16/256 cores |
| **10** | `0x124B68` | 0x3E8 | Configuração de primitivas de corte (scissor rect / clip) |
| **11** | `0x124F50` | 0x290 | Configuração de modo alfa / blending registers |
| **12** | `0x1251E0` | 0x328 | Configuração de registradores de teste Z / alpha |
| **13** | `0x125508` | 0x050 | Registrador auxiliar GS |
| **14** | `0x125558` | 0x050 | Registrador auxiliar GS |
| **15** | `0x1255A8` | 0x048 | Registrador auxiliar GS |
| **16** | `0x1255F0` | 0x050 | Registrador auxiliar GS |
| **17** | `0x125640` | 0x048 | Registrador auxiliar GS |
| **18** | `0x125688` | 0x048 | Registrador auxiliar GS |
| **19** | `0x1256D0` | 0x050 | Registrador auxiliar GS |
| **20** | `0x125720` | 0x050 | Registrador auxiliar GS |
| **21** | `0x125770` | 0x048 | Registrador auxiliar GS |
| **22** | `0x1257B8` | 0x050 | Registrador auxiliar GS |
| **23** | `0x125808` | 0x050 | `ktGpuSetFrame1` (`func_00125808`) |
| **24** | `0x125858` | 0x050 | `ktGpuSetFrame2` (`func_00125858`) |
| **25** | `0x1258A8` | 0x050 | `ktGpuSetZbuf1` (`func_001258A8`) |
| **26** | `0x1258F8` | 0x048 | `ktGpuSetZbuf2` (`func_001258F8`) |
| **27** | `0x125940` | 0x048 | `ktGpuSetDrawRegisters` (`func_00125940`) |
| **28** | `0x125988` | 0x040 | `ktGpuResetTestRegister` (`func_00125988`) |

## Localização no Binário Original

- Handlers 0 a 22 ocupam a faixa contígua `0x00123AC8` - `0x00125808` (offset em arquivo `0x23CA8` - `0x259E8`).
- Handlers 23 a 28 e o despachante ocupam a faixa `0x00125808` - `0x00125A70` (segmento `kt_gpu` em `src/kcet/kt_gpu.c`).
- Ambas as seções foram compiladas com `EE-GCC 2.9-991111` (`-O2 -G0`).
