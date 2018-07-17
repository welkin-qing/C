#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
	cost db 20h,28h,15h,26h,19h
	prices db 5 dup(?)

start:	
	call func
	ret

func	proc
	mov bx,0
	mov cx,5
lp:	mov al,cost[bx]
	add al,15h
	daa
	mov prices[bx],al
	inc bx
	dec cx
	jnz lp
	ret
func endp