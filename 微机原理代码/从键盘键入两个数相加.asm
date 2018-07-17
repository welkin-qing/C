#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

	mov ah,9;显示器显示一个字符串
	mov dx,offset op1
	int 21h   ;中断
	
	mov dl,0
	call lin
	
	sub al,48
	add dl,al
	push dx
	mov dx,offset op2
	mov ah,9  
	int 21h
	pop dx
	
	call lin
	add dl,al
	
	push dx
	mov dx,offset op3
	mov ah,9
	int 21h
	pop dx
	mov ah,2  ;显示器显示一个字符
	int 21h
	ret
	
lin	proc
	mov ah,1   ;键入并显示一个字符
	int 21h
	ret
	lin endp
op1 db 'input the first number:$'
op2 db 0dh,0ah,'input the second number:$'
op3 db 0dh,0ah,'the sum is:$'
sum db ?