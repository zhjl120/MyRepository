dseg	segment
result	db 10 dup(0)
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	
	mov ax,0ffffh
	push ax
	call BTOASC16
	
	mov ah,4ch
	int 21h
	
	
;功能：求16位2进制补转换为对应10进制数的ASCII码
;入口参数：ax
;出口参数：ax
BTOASC16	PROC
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	
	mov ax,[bp+4]
	mov cx,ax
	and cx,8000h;判断是正数还是负数
	jz  take ;正数则直接转换asc码，如果是负数则先将其补码转换为原码
	
	call COMPCODE16
	mov cx,ax 
	and cx,8000h;此处cx的值应该永远都不为0，即ax是一个负数
	and ax,7fffh;取绝对值
	
take:	mov bx,offset result
	mov si,5
	push cx
	mov cx,10
agin:	xor dx,dx
	div cx
	add dl,30h
	mov [bx][si],dl
	dec si
	or si,si
	jnz agin
	
	pop cx
	and cx,cx
	jz  return ;根据最高位判断是正数还是负数
	mov [bx][si],byte ptr 2dh	
	
return:	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret

BTOASC16 endp	
	

;功能：将16位负数的补码转换为原码
;入口参数：ax
;出口参数：ax
COMPCODE16	PROC
	push bx
	mov bx,ax
	and bx,8000h
	not ax
	inc ax
	and ax,7fffh
	add ax,bx
	pop bx
	ret

COMPCODE16 endp
	
cseg	ends
	end start