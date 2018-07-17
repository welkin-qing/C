#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

	push ax
	mov bx,offset data
	push cx
	mov di,offset sum
	push dx
	push si
	call fun
	pop si
	pop dx
	pop ax
	ret
data db 25h,12h,15h,1fh
sum db ?
	fun proc
	mov ax,0
	mov cx,5
	
lp:	mov dl,[bx]
	add al,dl
	inc bx
	dec cx
	jnz lp
	mov [di],al
	ret
	fun endp