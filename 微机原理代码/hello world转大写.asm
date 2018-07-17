#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start
data1 db "HEllo WorlD"
data2 db 11 dup (?)

start:
	mov bx,offset data1
	mov si,offset data2
	mov cx,11
	mov al,0
lp:
	mov dl,[bx]
	cmp dl,61h ;小写十六进制a
	jc next
	and dl,0dfh ;dl与DF(1101 1111)就是把左边第三位清0
	
	cmp dl,7ah ;小写十六进制z
	jnc next
	and dl,0dfh
next:
	mov [si],dl
	inc bx
	inc si
	loop lp
	ret