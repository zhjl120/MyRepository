;功能：在屏幕上依次循环显示数字字符0-9，一共5行13列

cseg	segment
	assume cs:cseg
start:	mov dl,30h ;起始字符0
	mov cx,5 ;控制行号
agin:	push cx
	mov cx,13 ;控制列号
agin2:	mov ah,2
	int 21h	
	inc dl
	cmp dl,39h
	jbe go
	mov dl,30h ;如果字符超过9，则将其重新置为0
go:	loop agin2
	pop cx
	
	push dx  ;临时保护dl，用于输出换行符
	mov dl,10
	mov ah,2
	int 21h  
	pop dx
	
	loop agin

	mov ah,4ch
	int 21h
cseg	ends
	end start