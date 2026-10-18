# Tactical AI Function 0x342170 Binary Analysis and State Machine

## 1. Function Overview

- **Symbol**: `func_00342170`
- **VRAM Address**: `0x00342170`
- **File Offset**: `0x00242350` (`orig/SLES-50282/AOK.ELF`)
- **Size**: 1584 bytes (`0x630`)
- **Binary Checksum (SHA-1)**: `f478e19f2059d52899b691483ef5c7522e30e17c`
- **Target Platform**: PlayStation 2 (Emotion Engine MIPS R5900, Little Endian)
- **Toolchain**: Metrowerks CodeWarrior PS2 (`mwccps2.exe` 2.3.1.01) with flags:
  `-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`

## 2. Register Allocation and Stack Frame

- Stack frame allocation: `addiu sp, sp, -32` (32 bytes).
- Preserved registers:
  - `sq ra, 16(sp)`
  - `sq s0, 0(sp)` (holds `this` / `self` pointer throughout execution).
- Function arguments:
  - `$a0`: `TacticalObj_341040 *self`
  - `$a1`: `int a1` (widget / subobject ID to match against child widgets)
  - `$a2`: `int a2` (event action / code, checked against 16 and 1)
  - `$a3`: `int a3`
  - `$t0`: `int t0` (parameter used in modes 8, 9, 10, 16 for `0xFFFF` flag)

## 3. Disassembly and Control Flow Structure

### Phase 1: Subobject `field_838` Pre-Dispatch (`0x00 - 0x114`)

```mips
   0:	27bdffe0 	addiu	sp,sp,-32
   4:	7fbf0010 	sq	ra,16(sp)
   8:	7fb00000 	sq	s0,0(sp)
   c:	8c820838 	lw	v0,2104(a0)          # v0 = self->field_838
  10:	10400040 	beqz	v0,114               # if (!field_838) goto Phase 2
  14:	70808628 	paddub	s0,a0,zero           # s0 = self
  18:	14a2003f 	bne	a1,v0,118            # if (a1 != (int)field_838) goto Phase 2
  1c:	24090001 	li	t1,1
  20:	24020010 	li	v0,16
  24:	14c2003b 	bne	a2,v0,114            # if (a2 != 16) goto Phase 2
  28:	00000000 	nop
  2c:	0c000000 	jal	func_339900          # jal func_339900(self, a1)
  30:	00000000 	nop
  34:	1440001d 	bnez	v0,ac                # if (v0 != 0) goto Sub-path B
```

#### Sub-path A: `func_339900` returns 0 (`0x3C - 0xA8`)
- Calls `func_33A5D0(0, 0, 0, 1, 0, 0)`
- Computes screen coordinates: `a1 = self->field_C + 100`, `a2 = self->field_10 + 97`
- Calls `func_339960(0, a1, a2, 168, 22, 8, 6)`
- Calls `func_1F6750(self, self->field_838)`
- Executes virtual method 76 on `self->field_838`: `((VFunc76)(*self->field_838)[76])(field_838, D_4D5508)`
- Epilogue branch to return `1`.

#### Sub-path B: `func_339900` returns non-zero (`0xAC - 0x110`)
- Calls `func_33A730()`
- Calls `func_00340CF0(self)`. If zero:
  - Calls `func_1F6EA0(self, 0xc356)`
  - Executes virtual method 76 on `self->field_838` with return code
- Calls `func_00219BA0(self->field_838)`
- Calls `func_33F8B0(self->field_844, ret_219ba0)`
- Stores state `self->field_84C = 11`
- Calls `func_00341040(self)`
- Epilogue branch to return `1`.

### Phase 2: Action Gate & `field_834` Subobject Dispatch Table (`0x114 - 0x228`)

```mips
 114:	24090001 	li	t1,1
 118:	14c9013f 	bne	a2,t1,618            # if (a2 != 1) return func_1FBD30(self, a1)
 11c:	72002628 	paddub	a0,s0,zero
 120:	8e020834 	lw	v0,2100(s0)          # v0 = self->field_834
 124:	14a20070 	bne	a1,v0,2e8            # if (a1 != field_834) goto Phase 3
```

When `a2 == 1` and `a1 == self->field_834`:
- **Mode 11**: `self->field_84C = 3; func_00341040(self); return 1;`
- **Mode 3**: `func_33A730(); func_00340C30(self); *(int*)(field_844 + 2052) = 2; return 1;`
- **Modes 1, 2, 4, 7**: `func_00340C30(self); *(int*)(field_844 + 2052) = 2; return 1;`
- **Modes 18, 21, 22, 23, 24**: `self->field_84C = 12; func_00341040(self); return 1;`
- **Mode 20**:
  - `field_840` boundary check: if `field_840 == 2 || (unsigned)(field_840 - 4) < 3` (values 2, 4, 5, 6): sets `field_84C = 18; func_00341040(self); return 1;`
  - Otherwise (values 1, 3, 7+): sets `field_84C = 17; func_00341040(self); return 1;`
- **Mode 15**:
  - `field_840` boundary check: if `field_840 == 2 || field_840 == 4`: sets `field_84C = 18; func_00341040(self); return 1;`
  - Otherwise: calls `func_00340C30(self); *(int*)(field_844 + 2052) = 12; return 1;`
- **Mode 14**:
  - `field_840` boundary check: if `field_840 == 2 || (unsigned)(field_840 - 4) < 3` (values 2, 4, 5, 6): sets `field_84C = 18; func_00341040(self); return 1;`
  - Otherwise: sets `field_84C = 17; func_00341040(self); return 1;`
- **Default**: calls `func_00341040(self); return 1;`

### Phase 3: `field_830` Jump-Table Dispatch Table (`0x228 - 0x62C`)

```mips
 2e8:	8e020830 	lw	v0,2096(s0)          # v0 = self->field_830
 2ec:	14a200c9 	bne	a1,v0,614            # if (a1 != field_830) return func_1FBD30(self, a1)
 2f0:	00000000 	nop
 2f4:	8e02084c 	lw	v0,2124(s0)          # v0 = self->field_84C (mode)
 2f8:	2c41001e 	sltiu	at,v0,30             # unsigned mode < 30
 2fc:	102000c1 	beqz	at,604               # if (mode >= 30) call func_00341040 and return 1
 300:	72002628 	paddub	a0,s0,zero
 304:	3c03004d 	lui	v1,%hi(jtbl_4D55F0)  # 0x004D55F0 jump table base
 308:	246355f0 	addiu	v1,v1,%lo(jtbl_4D55F0)
 30c:	00021080 	sll	v0,v0,0x2            # mode * 4
 310:	00431021 	addu	v0,v0,v1
 314:	8c420000 	lw	v0,0(v0)             # v0 = jtbl_4D55F0[mode]
 318:	00400008 	jr	v0                   # Indirect jump register
```

#### Jump Table Targets (`0x4D55F0`, 30 entries for modes 0..29)

| Mode | Target Address | Behavior / Outcome |
|------|---------------|-------------------|
| 0 | `0x00342770` | `func_00341040(self); return 1;` |
| 1 | `0x00342594` | `func_00340C30(self); *(field_844 + 2052) = 5; return 1;` |
| 2, 4 | `0x003425e0` | `func_00340C30(self); *(field_844 + 2052) = 7; return 1;` |
| 3 | `0x003426a8` | Calls `func_33A730`, sub838 handlers, sets `field_84C = 11`, `func_00341040(self); return 1;` |
| 5, 6 | `0x0034262c` | `func_00340C30(self); *(field_844 + 2052) = 1; return 1;` |
| 7 | `0x0034265c` | `func_00340C30(self); *(field_844 + 2052) = 9; return 1;` |
| 8 | `0x003425b0` | If `(unsigned short)t0 == 0xFFFF`: `func_00340C30`, `*(field_844 + 2052) = 6`, return 1; else return 0 |
| 9 | `0x003425fc` | If `(unsigned short)t0 == 0xFFFF`: `func_00340C30`, `*(field_844 + 2052) = 3`, return 1; else return 0 |
| 10 | `0x00342678` | If `(unsigned short)t0 == 0xFFFF`: `field_84C = 12; field_83C = 12; func_00341040`, return 1; else return 0 |
| 11 | `0x0034270c` | `func_00340C30(self); *(field_844 + 2052) = 11; return 1;` |
| 12 | `0x00342728` | `self->field_84C = 13; func_00341040(self); return 1;` |
| 13 | `0x00342734` | `func_00340C30(self); *(field_844 + 2052) = 4; return 1;` |
| 14 | `0x00342490` | If `field_840 in {2, 4, 5, 6}`: `field_84C = 12; func_00341040`, return 1; else `func_00340C30`, `*(field_844 + 2052) = 12`, return 1 |
| 15 | `0x003424d8` | If `field_840 in {2, 4}`: `func_36ACC0(7); field_84C = 16; func_00341040`, return 1; else `field_84C = 17; func_00341040`, return 1 |
| 16 | `0x00342750` | If `(unsigned short)t0 == 0xFFFF`: `field_84C = 12; field_83C = 12; func_00341040`, return 1; else return 0 |
| 17 | `0x00342518` | `self->field_84C = 12; func_00341040(self); return 1;` |
| 18, 21-24 | `0x00342578` | `func_00340C30(self); *(field_844 + 2052) = 3; return 1;` |
| 19 | `0x00342524` | `self->field_84C = 20; func_00341040(self); return 1;` |
| 20 | `0x00342530` | If `field_840 in {2, 4, 5, 6}`: `field_84C = 17; func_00341040`, return 1; else `func_00340C30`, `*(field_844 + 2052) = 12`, return 1 |
| 25 | `0x00342610` | `func_00340C30(self); *(field_844 + 2052) = 3; return 1;` |
| 26 | `0x003425c4` | `func_00340C30(self); *(field_844 + 2052) = 6; return 1;` |
| 27 | `0x00342764` | `self->field_84C = 12; self->field_83C = 12; func_00341040(self); return 1;` |
| 28, 29 | `0x0034269c` | `self->field_84C = self->field_850; func_00341040(self); return 1;` |

#### Modes 30 through 50
- When `mode >= 30`: jumps to `0x00342770` (`func_00341040(self); return 1;`).
- In `func_00341040`, resets `sub830 + 552` and `sub834 + 552` to 0, invokes `func_33A730()`, and preserves `field_84C`.

### Phase 4: Fallthrough
- If `a2 != 1` or `a1` does not match `field_834` or `field_830`: calls `func_1FBD30(self, a1)` and returns the resulting status code.
