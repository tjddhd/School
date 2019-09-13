 



cseg at 0x00
	mov 0xA4, #0
	mov 0x91, #0
	mov 0x84, #0
	mov R2, #0
	setb p2.0
	setb p0.1
	clr p2.4
	clr p0.5
	clr p0.4
	clr p2.5
	clr p0.7
	clr p2.6

loop:
	 ;add button
	mov c, p0.1
	
	jnc Up
	clr p2.4
	setb p0.1 ;add
	
	mov c, p2.0
; 	delay
	clr p0.5
	setb p2.0
	jnc Down
	sjmp loop


Up: 
	setb c
  	mov p0.5,c ;red LED
	acall Delay
	mov a, r2
	cjne a, #15, Cont
	mov a, #255
	acall Buzzer
	addc a,#01
	clr c
	mov c, acc.3
	mov p0.4, c
	mov c, acc.2
	mov p2.5, c
	mov c, acc.1 
	mov p0.7, c
	mov c, acc.0 
	mov p2.6, c
	mov r2, a
	setb p0.1
	sjmp loop
Cont:
	mov a, r2
   	clr c
	addc a,#01
	clr c
	mov c, acc.3
	mov p0.4, c
	mov c, acc.2
	mov p2.5, c
	mov c, acc.1 
	mov p0.7, c
	mov c, acc.0 
	mov p2.6, c
	mov r2, a
	setb p0.1 ;
	sjmp loop

Down:
	setb c
	mov p2.4, c
	  ;yellow
	mov a, R2
	acall Delay
	jnz Co
	acall Buzzer
D:
	mov R2, #15
	mov a, r2
	mov c, acc.3 
	mov p0.4, c
	mov c, acc.2
	mov p2.5, c
	mov c, acc.1 
	mov p0.7, c
	mov c, acc.0 
	mov p2.6, c
	mov r2, a

	ljmp loop
Co:
	clr c
	mov a, r2
	addc a, #255
	mov c, acc.3 
	mov p0.4, c
	mov c, acc.2
	mov p2.5, c
	mov c, acc.1 
	mov p0.7, c
	mov c, acc.0 
	mov p2.6, c
	mov r2, a
	setb p0.1
	ljmp loop	


BuzzerD:
	acall Buzzer
	sjmp D
Buzzer:
	; buzzer crap here
	ret


Delay: 
	mov r5, #50
Here:
	mov r1, #100
There:
	mov r3, #100
Everywhere:
	djnz r3, Everywhere
	djnz r1, There
	djnz r5, Here
	ret
end
