cseg	segment
	assume cs:cseg
start:	mov cx,8
abc:	rol al
	rcl dh
	loop abc
	mov cx,8
bcd:	rol al
	rcl dl
	loop bcd
	mov ah,4ch
	int 21
cseg	ends
	end start