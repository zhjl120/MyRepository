;ת��Сд�ַ�Ϊ��д�ַ�
dseg	segment
string	db 'hELlo World !',0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	mov ax,dseg
	mov ds,ax
	mov si,offset string
agin:	mov al,[si]
	and al,al ;����ַ����Ƿ������Ϊ0��
	jz  over
	cmp al,'a';����ַ��Ƿ���Сд�ַ�����a��z֮��
	jb  ok
	cmp al,'z'
	ja  ok
	and al,0dfh ;��Сд�ַ�ת��Ϊ��д�ַ�
	mov [si],al ;���ַ�д��ԭ��
ok:	inc si	;�ַ���ָ�����
	jmp agin ;ѭ��
over:	mov ah,4ch
	int 21
cseg	ends
	end start