;去除字符串中的空格符
dseg	segment
string 	db 'hello world !',0
len	db 0
dseg	ends

sseg	segment
	dw 0,0,0,0
sseg	ends

cseg	segment
	assume cs:cseg,ds:dseg,ss:sseg
start:	mov ax,dseg
	mov ds,ax
	mov ax,sseg
	mov ss,ax
	xor cx,cx
	mov si,offset string
agin:	mov al,[si]
	and al,al
	jz  over
	inc cx
	inc si
	jmp agin
	
over:	mov si,offset len
	mov [si],cx
		
	xor di,di
	mov si,offset string
agin2:	mov al,[si]
	and al,al
	jz  over2
	cmp al,20h
	jz  forward
	inc si
	inc di
	jmp agin2
over2:	mov ah,4ch
	int 21

forward:push si
	mov  ax,offset len
	mov  cx,[ax]
agin3:	mov  al,[si+1]
	mov  [si],al	
	inc  si
	loop agin3
	pop  si
	dec  cx
	jmp  agin2

cseg 	ends
	end start