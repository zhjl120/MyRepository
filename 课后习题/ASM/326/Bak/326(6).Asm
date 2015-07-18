dseg	segment
string	db 'hELlo World !',0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov si,offset string
agin	mov al,[si]
	and al,al
	jz  over
	cmp al,'a'
	jb  ok
	cmp al,'z'
	ja  ok
	or  al,20h
	mov [si],al
ok:	jmp agin
over:	mov ah,4ch
	int 21
cseg	ends
	end start