



cseg	segment
	assume cs:cseg
start:
	mov ax,-1
	call COMPCODE32
	mov ah,4ch
	int 21h


;功能：求32位补码
;入口参数：AX
;出口参数：BX
COMPCODE32	PROC
	mov bx,ax
	and bx,8000h
	not ax
	inc ax
	and ax,7fffh
	add bx,ax
	ret
COMPCODE32	ENDP

cseg	ends
	end start