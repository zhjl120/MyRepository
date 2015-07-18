dseg	segment
string	db 'hELlo World !',0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov si,offset string
agin:	mov al,[si]
	and al,al ;检查字符串是否结束（为0）
	jz  over
	cmp al,'a';检查字符是否是小写字符，在a到z之间
	jb  ok
	cmp al,'z'
	ja  ok
	and al,0dfh ;将小写字符转换为大写字符
	mov [si],al
ok:	inc si	
	jmp agin
over:	mov ah,4ch
	int 21
cseg	ends
	end start