cseg	segment
	assume cs:cseg
start:	mov ah,7
	int 21h
	
	cmp al,10
	je  
	
	cmp al,'a'
	jb  go
	cmp al,'z'
	ja  go
	and al,0dfh
	
	mov dl,al
	mov ah,2
	int 21h
	
over:	mov ah,4ch
	int 21h
cseg	ens
	end start
	