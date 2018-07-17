#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
data db 25h,12h,15h,1fh,2bh
sum db ?

start:
	call subr
ret
subr 	proc
	push bx
	push cx
	push ax
	mov ax,0
	mov bx,offset data
	mov cx,5
lp:
	mov ah,[bx]
	add al,ah
	inc bx
	dec cx
	jnz lp
	mov sum,al
	pop ax
	pop cx
	pop bx
ret
subr endp