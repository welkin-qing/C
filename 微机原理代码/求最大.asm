#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
grades	db 69,87,96,45,75
highest db ?
start:  call func  ;�ӳ��������
	ret
	
func	proc       ;�ӳ���Ŀ�ʼ
	pushf
	push bx
	push ax
	push cx
	push dx
	mov cx,5
	mov bx,0
	mov al,0
lp:	cmp al,grades[bx]
	ja else
	mov al,grades[bx]
else:	inc bx
	loop lp
	mov highest,al
	pop dx
	pop cx
	pop ax
	pop bx
	popf
	ret
func	endp       ;�ӳ������