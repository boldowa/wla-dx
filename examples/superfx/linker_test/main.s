
;»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»
; a small example showing the SuperFX syntax
; written by boldowa in 2016
; based on spc-700 example by ville helin <vhelin@cc.hut.fi> in 2001-2005
; the code looks like s*it on purpose ;)
;»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»

.include "defines.i"

;»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»
; main
;»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»

.endasm
	shuteye wouldn't hurt, but the voices tell me to code...
.asm

.macro db32
 .asc (\1>>24)&$ff
 .byt (\1>>16)&$ff
 .asc (\1>>8)&$ff
 .byte (\1>>0)&$ff
.endm

.define CHAOS 0

.struct kero
name byte
age  byt
.endst

.ENUM $C000 DESC EXPORT
bigapple_h db
bigapple_l db
bigapple:  .word
.ENDE

.enum $0100 desc export
l0 instanceof kero 2
l1 db
l2 dw
l3 ds 3
l4 dw
.ende

.deFiNE timmi (7+kostaja)
.def    legion (1+kostaja+7)
.Equ    BAGI legion-timmi+2
.define monster = "terrrmurrrrr"
.dEF    dummy   = "testing", 1, 2, 3
.eQu    kosher  = 102
.redef  kosher  = 103
.RedefinE kosher = 104
.redef  kosher 102

.export kosher monster, legion, timmi, BAGI, dummy

.bank 0 slot 0
.org $0

	.db +
nollasivu:
	nop
+

.byt 1,>KORBA

	blt 1+2+3.1+2

.if 1 >= 2
 ijo oijo
.endif

.if monster >= dummy
.fail
.endif

.printv dec <(>($0402+1*$100))+1-1
.printt " (should be 5)\n"

.word legion, kostaja, BAGI+2, $ffff

.dbsin 0.2, 10, 3.2, 120, 1.3

.dsb 10, 10
.dsw 10, 10

        db32 $12345678

.section "main" force
	.db     "Hello, Undiiiiiiii"
	iwt	r8, #ookoo
	jmp	r8
.ends


.org $100

.define LABELMAIN MAIN+0
.export LABELMAIN

.SECTION "Beginning" FORCE

kostaja	.db	"heippatirallaati"
MAIN:	beq	KORBA
	beq	+
	beq	++
	beq	__
+	dec	r1
__	NoP
	cmp	r5
	CMP	r3
KORBA:
++
-
sorma
	.db	"endoffile"
	.dwsin 0.2, 10, 3.2, 120.1, 1.3
.ENDS


.org $200

.section "more" force
	nop

.sym KEKKONEN
KAKKONEN:
	
	beq	_f
	beq	_F
__	nop
	beq	_B
	beq	_b
	nop
	beq	_B
__	nop

.ends

.section "dd" free

dator:	.incbin "main.s"
dator_end:

.export dator_size
.define dator_size dator_end-dator
.define MAINA 0
.define JUSTICE MAINA+0

.db $de, $ad, $be, $ef
.dw dator_size

.ends


.org $1000
	ibt	R12, #$22
	.db $ff, $ff
ookoo:
