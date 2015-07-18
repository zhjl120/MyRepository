;功能：将用户输入的字符转换为ASCII码显示

cseg	segment
	assume cs:cseg
start:	mov ah,7
	int 21h
	
	push ax ;保存收到的字符
	
	mov dl,al;显示输入的字符
	mov ah,2
	int 21h
	
	call ASCTOHASC
	
	mov dl,10;换行
	int 21h
	
	mov dl,bh ;显示转换为16进制表示后的字符
	int 21h
	mov dl,bl
	int 21h
	
	
	mov dl,10;
	int 21h
	
	mov al,bl
	call ASCTOOASC
	mov dl,bh
	int 21h
	
	mov dl,bl
	int 21h
	
	mov dl,ch
	int 21h
	
	
	
	mov ah,4ch
	int 21h
	
;功能：将字符的ASC码以16进制字符串的形式显示
;入口参数：al存放ASCII码值
;出口参数：bh存放高位16进制数的ASCII字符，bl存放底位16进制数的ASCII字符
ASCTOHASC	PROC
	push cx
	mov bh,al
	and bh,0f0h
	mov cl,4
	rol bh,cl
	cmp bh,9
	ja  letter
	add bh,30h
	jmp second
letter:	sub bh,10
	add bh,41h
	
second:	mov bl,al
	and bl,0fh
	cmp bl,9
	ja  let2
	add bl,30h
	jmp over
let2:	sub bl,10
	add bl,41h
over:	pop cx
	ret

ASCTOHASC endp


;功能：将字符的ASC码以8进制字符串的形式显示
;入口参数：al存放ASCII码值
;出口参数：bh存放第一位8进制ASCII码值，bl存放第二位，ch存放第三位
ASCTOOASC	PROC
	push ax
	push cx
	
	mov ah,al
	and ah,11000000b
	mov cl,2
	rol ah,cl
	add ah,30h
	mov bh,ah
	
	mov ah,al
	and ah,00111000b
	mov cl,3
	ror ah,cl
	add ah,30h
	mov bl,ah
	
	mov ah,al
	and ah,00000111b
	add ah,30h
	mov ch,ah
	
	pop cx
	pop ax
	ret

ASCTOOASC endp


cseg	ends
	end start