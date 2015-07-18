dseg	segment
buff	db 50 dup(0)
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	
	mov si,offset buff
	mov [si],byte ptr 50
	mov dx,si
	mov ah,0ah
	int 21h
	
	inc si
	mov cx,[si]
	add si,cx
	
	
	mov ah,4ch
	int 21h
cseg	ends
	end start