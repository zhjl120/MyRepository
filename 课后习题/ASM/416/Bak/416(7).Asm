cseg	segment
	assume cs:cseg
start:	mov dl,30h
	mov cx,5
agin:	push cx
	mov cx,13
agin2:	mov ah,2
	int 21	
	inc dl
	cmp dl,39h
	jbe go
	mov dl,30h
go:	loop agin2
	pop cx
	loop agin

	mov ah,4ch
	int 21h
cseg	ends
	end start