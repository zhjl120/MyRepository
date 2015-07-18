cseg	segment
	assume cs:cseg
start:	mov cx,8
	mov si,0
abc:	rol al,1
	rcl dx,1
	rol bl,1
	rcl dx,1
	loop cx
	mov ah,4ch
	int 21
cseg	ends
	end start