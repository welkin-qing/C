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
	cmp dl,61h ;Сдʮ������a
	jc next
	and dl,0dfh ;dl��DF(1101 1111)���ǰ���ߵ���λ��0
	
	cmp dl,7ah ;Сдʮ������z
	jnc next
	and dl,0dfh
next:
	mov [si],dl
	inc bx
	inc si
	loop lp
	ret