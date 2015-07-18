cseg	segment
	assume cs:cseg
start:	mov al,1111b
	mov bl,0000b
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