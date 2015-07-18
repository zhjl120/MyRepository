dseg	segment
result	dd 0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov bx,dseg
	mov ds,bx
	mov si,offset result
	mov dx,10000000b
	mov ax,00000001b
	not dx
	not ax
	inc ax
	adc dx,0	
	mov [si],ax
	mov [si+2],dx
cseg	ends
	end start