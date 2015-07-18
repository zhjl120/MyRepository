;功能：在屏幕上依次循环显示数字字符0-9，一共5行13列

cseg	segment
	assume cs:cseg
start:	mov dl,30h ;起始字符0
	mov dh,0
agin:	mov ah,2
	int 21h
	inc dl
	cmp dh,13
	jbe go
	mov dh,0
	push dl
	mov dl,10
	int 21h
	pop dl
go:	cmp dl,39h
	jbe go1
	mov dl,30h
go1:	jmp agin

	mov ah,4ch
	int 21h
cseg	ends
	end start