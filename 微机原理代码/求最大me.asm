#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
	grades db 69,87,96,45,75;
	highest db ?;
start	
	call func
	ret
	
func	prec
	pushf
	
	mov cx,5;
	mov bx,0;
lp	mov ax,grades[bx];
	mov dx,grades[bx+1];
again	cmp ax,dx;
	ja next;
	mov dx,ax;
next	inc bx;
	
	