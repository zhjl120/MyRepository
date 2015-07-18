dseg	segment
result	db 0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov si,offset result
	mov dx,1h
	mov cx,10h
abc:	mov bx,ax
	and bx,dx
	jbe bcd
	inc byte ptr [si]
bcd:	shl dx,1
	loop abc
	
	mov ah,4ch
	int 21h
cseg	ends
	end start