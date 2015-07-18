cseg	segment
	assume cs:cseg
start:	xor dx,dx
	mov al,0ffh
	mov bl,0h
	mov cx,8
abc:	rol al,1
	rcl dx,1
	rol bl,1
	rcl dx,1
	loop abc
	mov ah,4ch
	int 21
cseg	ends
	end start