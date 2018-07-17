#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
grades	db 69,87,96,45,75
highest db ?
start:	mov bx,offset grades
	mov cx,5
	mov di,offset highest
	pushf
	push ax
	push dx
	push si
	call max
	pop si
	pop dx
	pop ax
	popf 
	ret
	
	max proc
	mov ax,0
	
lpp:	mov dl,[bx]
	cmp al,dl
	ja oot
	mov al,dl
oot:
	inc bx
	dec cx
	jnz lpp
	mov [di],al
	ret
	max endp
	