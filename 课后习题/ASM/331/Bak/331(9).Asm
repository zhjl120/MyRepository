data	segment
value	db '3456',0
fbcd	db 4 dup(0)
ybcd	db 2 dup(0),0,0,0,0,0
data	ends

code	segment
	assume cs:code,ds:data
start:	mov ax,data
	mov ds,ax
	mov si,offset value
	mov di,offset fbcd
	
	mov cx,4
	xor al,al
agin:	mov al,[si]
	sub al,30h
	mov [di],al
	inc si
	inc di
	loop agin
	
	mov si,offset value
	mov di,offset ybcd	
	mov cx,2
agin2:	mov al,[si]
	sub al,30h
	mov cl,4
	shl al,cl
	and al,0f0h
	inc si
	mov ah,[si]
	sub ah,30h
	and ah,0fh
	add al,ah
	mov [di],al
	inc si
	inc di
	loop agin2
	
	mov ah,4ch
	int 21h
code	ends
	end start
