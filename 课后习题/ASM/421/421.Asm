dseg	segment
buff	db 100 dup(0)
deci	db 0,0,0,'$'
dseg	ends
	
cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	
	mov si,offset buff
	mov [si],byte ptr 100
	mov dx,si
	mov ah,0ah
	int 21h
	
	inc si
	xor dl,dl
	
agin:	inc si
	mov al,[si]
	cmp al,13
	je  over
	cmp al,'0'
	jb  go
	cmp al,'9'
	ja  go
	jmp agin
go:	cmp al,'a'
	jb  go1
	cmp al,'z'
	ja  go1
	jmp agin
go1:	cmp al,'A'
	jb  go2
	cmp al,'Z'
	ja  go2
	jmp agin
go2:	inc dl
	jmp agin
	
over:	mov al,dl
	mov bx,offset deci
	push bx
	call BTODASC8
	
	mov dl,10
	mov ah,2
	int 21h
	
	mov dx,bx
	mov ah,9
	int 21h
	
	mov ah,4ch
	int 21h
	

;功能：将8位2进制转换10进制ASCII码
;入口参数：al存放需要转换的二进制，转换后的ASCII码存放的首地址通过栈传递
;出口参数：将转换后的ASCII码存放在传入的内存地址中
BTODASC8		PROC
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	
	mov bx,[bp+4]
	
	xor ah,ah
	mov si,2
	mov dl,10
	mov cx,3
	
agin2:	div dl
	add ah,30h
	mov [bx+si],ah
	dec si
	xor ah,ah
	loop agin2
	
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret

BTODASC8 endp
	
	
cseg	ends
	end start