dseg	segment
buff	db 20 dup('$')
buff2	db 20 dup('$')
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	
	mov bx,offset buff
	mov [bx],byte ptr 20 ;存放数组长度
	mov dx,bx  ;录入字符串
	mov ah,0ah
	int 21h
	
	mov dx,offset buff2
	add bx,2
	call STRCPY
	sub bx,2
	
	xor dh,dh
	mov dl,[bx+1] ;dx保存字符串在整个数组中的偏移
	add dx,2      ;加2是相对于数组偏移，而不是字符串偏移
	add bx,2      ;bx指向字符串首地址
	mov si,bx   
agin:	mov al,[si]
	cmp al,0dh     
	jz  over
	cmp al,'a'
	jb  next
	cmp al,'z'
	ja  next
	jmp take
	
next:	cmp al,'A'
	jb  go
	cmp al,'Z'
	ja  go
	
take:	push si
	mov cx,dx
	sub cx,si
agin2:	mov al,[si+1]
	mov [si],al
	inc si
	loop agin2
	pop si
	dec dx
	jmp agin
	
go:	inc si
	jmp agin
	
over:	mov [si],byte ptr '$'

	mov ah,2
	mov dl,10
	int 21h
	
	mov ah,9
	mov dx,bx
	int 21h
	
;**********************************
	
	mov si,offset buff2
agin5:	mov al,[si]
	cmp al,'$'
	jz  over
	cmp al,'a'
	jb  lab
	cmp al,'z'
	ja  lab
	and al,0dfh
	mov [si],al
	jmp lab2
lab:	cmp al,'A'
	jb  lab2
	cmp al,'Z'
	ja  lab2
	or  al,20h
	mov [si],al
lab2:	inc si
	jmp agin5
		
over：	mov ah,2
	mov dl,10
	int 21h
	
	mov ah,9
	mov dx,offset buff2
	int 21h
	
	mov ah,4ch
	int 21h
	
;功能：将数组1中的内容拷贝到数组2中
;入口参数：数组1的地址为DS:BX , 数组2的地址为DS:DX
;其它说明：复制后的字符串以'$'符号结尾
STRCPY	PROC
	push si
	push ax
	push bx
	
	mov si,dx
agin3:	mov al,[bx]
	cmp al,0dh
	jz  over2
	mov [si],al
	inc si
	inc bx
	jmp agin3
	
over2:	mov [si],byte ptr '$'
	pop bx
	pop ax
	pop si
	ret

STRCPY endp

cseg	ends
	end start