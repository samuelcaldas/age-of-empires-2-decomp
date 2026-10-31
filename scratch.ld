_gp = 0x4ea7c0;
D_004E2DA0 = 0x4e2da0;
D_004E2DA4 = 0x4e2da4;
D_004E2DA8 = 0x4e2da8;
D_004E2DAC = 0x4e2dac;
D_004E2DB4 = 0x4e2db4;
func_001522C0 = 0x1522c0;
SECTIONS {
  .text 0x160b70 : { *(.text) . = ALIGN(16); }
  /DISCARD/ : { *(*) }
}
