dseg	segment
string	db 'hELlo World !',0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	
over:	mov ah,4ch
	int 21
cseg	ends
	end start