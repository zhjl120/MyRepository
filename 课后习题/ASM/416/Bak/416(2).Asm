;功能：在屏幕上依次循环显示数字字符0-9，一共5行13列
cseg	segment
	assume cs:cseg
start:	mov dl,30h
	mov cx,5 
agin:	push cx
	mov cx,13
agin2:	mov ah,2
	int 21h	
	inc dl
	cmp dl,39h
	jbe go
	mov dl,30h
go:	loop agin2
	pop cx
	
	push dx
	mov dl,10
	mov ah,2
	int 21h
	pop dx
	
	loop agin

	mov ah,4ch
	int 21h
cseg	ends
	end start