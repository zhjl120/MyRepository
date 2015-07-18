dseg	segment
value	dw 0aaaah
result	db 16 dup(0)
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov si,offset value
	mov di,offset result
	add di,10h
	mov ax,[si]
	mov cx,10h
	mov bx,1h
	
agin:	mov dx,ax
	and dx,bx
	jz  zero
	mov [di],byte ptr 1
	jmp over
zero:	mov [di],byte ptr 0
over:	shl bx,1
	dec di
	loop agin
	
	mov ah,4ch
	int 21h
cseg	ends
	end start