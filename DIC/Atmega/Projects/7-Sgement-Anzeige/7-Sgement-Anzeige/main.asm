;
; 7-Sgement-Anzeige.asm
;
; Created: 05.12.2018 14:42:13
; Author : jakim
;


; Replace with your application code

//Groß-/Kein-Schreibung is in Assembler immer egal
.EQU InputPort = PINB
.Equ InputDDR = DDRB
.Equ OutputPort = PORTA
.EQU OutputDDR = DDRA
.EQU InputMask = 0x0F

.DEF input = R16
.DEF output = R17
.DEF help = R18
.DEF zeroReg = R19
.DEF ff_reg = R20

//Segment DECODER
.CSEG	
.ORG  	0

start:
    ldi help,0xFF
	out outputddr,help

	ldi help, 0x00
	out inputddr,help

	clr zeroreg
	ldi ff_reg,0xFF	

	
loop:
	in input, inputport
	andi input, inputmask
	
	ldi zl, low(segtable*2)
	ldi zh, high(segtable*2)

	add zl,input
	adc zh,zeroreg
	lpm						//load programm memory -> z-register

	//eor r0,dd_reg			common Anode
	out outputport,r0

	rjmp loop



segtable:
	.db 0x3F, 0x06	// 0 und 1
	.db 0x58, 0x24  // 2 und 3
	



