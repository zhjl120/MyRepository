dseg	segment
string	db 'hELlo World !',0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov cx,0
	mov si,offset string
agin:	mov al,[si]
	and al,al
	jz  over
	inc  cx
	jmp agin
over:	mov ah,4ch
	int 21
cseg	ends
	end start