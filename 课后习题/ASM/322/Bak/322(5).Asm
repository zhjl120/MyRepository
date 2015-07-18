dseg	segment
result	dd 0
dseg	ends

cseg	segment
	assume cs:cseg,ds:dseg
start:	

cseg	ends
	end start