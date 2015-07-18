dseg	segment
string	db '123456',0
num	db 10 dup(0)
dseg	ends 

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	;call SUBA
	;mov si,offset string
	;call SUBA
	
	;call SUBB
	;push ds          ;压入段值
	;mov si,offset string 
	;push si		 ;压入偏移
	;call SUBB 
	
	;call SUBC
	push ds
	mov si,offset string
	push si
	call SUBC
	
	mov ah,4ch
	int 21h


;功能：将十进制数字符串转换为相应的数值
;入口参数：字符串的段值和偏移压入堆栈
;出口参数：传入的入口参数指向转换后的数字，以-1结束
SUBC	PROC
	push bp
	mov  bp,sp
	push ds
	push si
	push ax
	push es
	push di
	
	mov  ds,[bp+6]
	mov  si,[bp+4]
	
	mov  ax,seg num
	mov  es,ax
	mov  di,offset num
	
	mov  al,0
agin:	cmp  [si],al
	jz   over
	mov  ah,[si]
	sub  ah,30h
	mov  es:[di],ah
	inc  si
	inc  di
	loop agin
	
over:   mov  es:[di],byte ptr -1
	pop  di
	pop  es
	pop  ax
	pop  si
	pop  ds
	pop  bp
	ret

SUBC endp


;功能：将十进制数字符串转换为相应的数值
;入口参数：字符串的段值和偏移压入堆栈
;出口参数：前6个字符的数值分别存放在AH,AL,CH,CL,DH,DL
;其它说明：转换长度有限，只支持6个字符
SUBB	PROC
	push bp
	mov  bp,sp
	push ds
	push si
	
	mov  ds,[bp+6]
	mov  si,[bp+4]
	call SUBA
	
	pop  si
	pop  ds
	pop  bp
	ret  4 ;调整栈顶指针，移除主程序中压入的段值和偏移

SUBB endp	


;功能：将十进制数字符串转换为相应的数值
;入口参数：字符串首地址默认在DS:SI
;出口参数：前6个字符的数值分别存放在AH,AL,CH,CL,DH,DL
;其它说明：转换长度有限，只支持6个字符
SUBA	PROC
	mov ah,[si]
	sub ah,30h
	mov al,[si+1]
	sub al,30h
	mov ch,[si+2]
	sub ch,30h
	mov cl,[si+3]
	sub cl,30h
	mov dh,[si+4]
	sub dh,30h
	mov dl,[si+5]
	sub dl,30h
	ret

SUBA endp	

cseg	ends
	end start
	