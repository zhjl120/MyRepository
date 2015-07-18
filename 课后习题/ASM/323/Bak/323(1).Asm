dseg	segment
result	dw 0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov cx,8
abc:	rol al
	rcl dh
	loop abc
	mov cx,8
bcd:	rol al
	rcl dl
	loop bcd
	mov si,offset result
	mov [si],dx
	mov ah,4ch
	int 21
cseg	ends
	end start