dseg	segment
result	dw 0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov cx,8
abc:	rol al,1
	rcl dh,1
	loop abc
	mov cx,8
bcd:	rol al,1
	rcl dl,1
	loop bcd
	mov si,offset result
	mov [si],dx
	mov ah,4ch
	int 21
cseg	ends
	end start