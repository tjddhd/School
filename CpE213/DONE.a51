cseg at 0x00
	mov 0xA4, #0      ;initializes everything to 0
	mov 0x91, #0
	mov 0x84, #0
	mov R2, #0
	setb p2.0
	setb p0.1
	setb p1.4
	setb p0.3
	clr p2.4
	clr p0.5
	clr p0.4
	clr p2.5
	clr p0.7
	clr p2.6
	clr p1.7
loop:			      ;loop which will check for the different button presses
	mov c, p0.1	   
	jnc Up
	clr p2.4
	setb p0.1
	mov c, p2.0
	clr p0.5
	setb p2.0
	jnc Down
	mov c, p1.4
	jnc	Light
	mov c, p0.3
	jnc Se
	sjmp loop		  ;jump back into main loop
Light:				  ;subroutine to call the Lights subroutine
	acall Lights	  
	setb p1.4
	sjmp loop		  ;jump back into main loop
Se:					  ;subroutine to call the Reset subroutine
	acall Reset
	setb p0.3
	sjmp loop		  ;jump back into main loop
Up: 				  ;subroutine which will increment the value siplayed and sound the buzzer, if necessary
	setb c
  	mov p0.5,c        ;red LED
	acall Delay		  ;delay call
	mov a, r2
	cjne a, #15, Cont ;cont call, which increments
	mov a, #255
	acall Buzzer	  ;buzzer call, if necessary
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
	sjmp loop	      ;jump back into main loop
Cont:				  ;subroutine to increment the value displayed
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
	setb p0.1 
	sjmp loop		  ;jump back into main loop
Down:				  ;subroutine which will decrement the value siplayed and sound the buzzer, if necessary
	setb c
	mov p2.4, c		  ;yellow LED
	mov a, R2
	acall Delay
	jnz Co
	acall Buzzer
D:					  ;resets the value displayed to 15
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
	ljmp loop		  ;jump back into main loop
Co:					  ;subroutine to decrement the value displayed
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
	ljmp loop		  ;jump back into main loop
BuzzerD:			  ;buzzer call if transitioning from 15 to 0
	acall Buzzer
	sjmp D
Buzzer:				  ;buzzer subroutine
	mov r5, #50
Back:
	mov r7, #100
Every:
	clr p1.7
	acall DelayB
	setb p1.7
	acall DelayB
	djnz r7, Every
	ret
DelayB:				  ;buzzer delay
	mov r1, #0fh
Toy:
	mov r3, #136
Ship:	
	djnz r3, Ship
	djnz r1, Toy
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
Lights:				  ;subroutine to turn on the LEDs, cycle through blinking them once, then return to original values
 	clr p2.4
	clr p0.5
	clr p2.7
	clr p0.6
	clr p1.6
	clr p0.4
	clr p2.5
	clr p0.7
	clr p2.6
	setb p2.4
	acall Delay
	clr p2.4
	setb p0.5
	acall Delay
	clr p0.5
	setb p2.7
	acall Delay
	clr	 p2.7
	setb p0.6
	acall Delay
	clr p0.6
	setb p1.6
	acall Delay
	clr p1.6
	setb p0.4
	acall Delay
	clr p0.4
	setb p2.5
	acall Delay
	clr p2.5
	setb p0.7
	acall Delay
	clr p0.7
	setb p2.6
	acall Delay
	clr	 p2.6
	acall Delay
	setb p2.4
	setb p0.5
	setb p2.7
	setb p0.6
	setb p1.6
	setb p0.4
	setb p2.5
	setb p0.7
	setb p2.6
	mov c, acc.3 
	mov p0.4, c
	mov c, acc.2
	mov p2.5, c
	mov c, acc.1 
	mov p0.7, c
	mov c, acc.0 
	mov p2.6, c
 	ljmp loop		  ;jump back into main loop
Reset:		   		  ;subroutine to display 15 without losing current value
	mov a, #0
	clr c
	mov c, acc.3 
	mov p0.4, c
	mov c, acc.2
	mov p2.5, c
	mov c, acc.1 
	mov p0.7, c
	mov c, acc.0 
	mov p2.6, c
	ret
end
