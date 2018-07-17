#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
data1 db "mY NAME is jOe"
data2 db 14 DUP (?)

start:
	mov bx,offset data1
	mov si,offset data2
	mov cx,14
	mov al,0
lp:
	mov dl,[bx]
	cmp dl,61h
	jc next
	and dl,0dfh;
	
	cmp dl,7ah
	jnc next
	and dl,0dfh
	
next:	mov [si],dl
	inc bx
	inc si
	loop lp
	ret