dseg	segment
result  db 10 dup(0)
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	
	mov ax,1
	push ax
	mov ax,200
	push ax
	call BTOASC32
	
	mov ah,4ch
	int 21h
	
;功能：将32位无符号二进制数转换为对应十进制数的ASCII码
;入口参数：通过栈传递，先压入高16位，再压入低16位
;出口参数：先前的高16位指向ASCII码字符串所在段值，底16位指向偏移
BTOASC32	PROC
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	push si
	
	mov ax,[bp+4]
	mov dx,[bp+6]
	mov bx,offset result
	mov si,10
	
	mov cx,10
agin:	div cx
	add dl,30h
	mov [bx+si],dl
	dec si
	xor dx,dx
	or  si,si
	jnz agin
	
	mov [bp+6],seg dseg
	mov [bp+4],bx
	
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret

BTOASC32 endp	

cseg	ends
	end start
