dseg	segment
str1	db 'hello',10 dup(0)
str2	db 'world',0
len	dw 0
dseg 	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	xor cx,cx
	mov si,offset str2
agin:	mov al,[si]
	and al,al
	jz  over
	inc cx
	inc si
	jmp agin	
over:	mov si,offset len
	mov [si],cx
	
	mov si,offset str1
agin2:	mov al,[si]
	and al,al
	jz  handle
	inc si
	jmp agin2
		
handle:	mov di,offset str2
agin3:	mov al,[di]
	mov [si],al
	inc si
	inc di
	loop handle
	
	mov [si],byte ptr 0
	
	mov ah,4ch
	int 21h
cseg	ends
	end start