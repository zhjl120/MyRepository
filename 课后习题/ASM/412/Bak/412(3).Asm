dseg	segment
table	db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,41h,42h,43h,44h,45h,46h
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov al,100
	call HTOASC
	mov ah,4ch
	int 21h
	
;功能：将1位16进制数转换为对应的ASCII码
;入口参数：AL存放1位16进制数
;出口参数：AH存放ASCII码值
;其它说明：如果传入不是16进制数，则AX值为0xFF
HTOASC	PROC
	cmp al,0
	jb  ERR
	cmp al,0fh
	ja  ERR
	mov si,offset table
	and ah,0
	add si,ax
	mov ah,[si]
	jmp RETURN
ERR:	mov ah,0ffh
RETURN:	ret

HTOASC endp

cseg	ends
	end start