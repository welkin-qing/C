#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jMP start
num dw 550h
sum dw 0
start:
   mov ax,num
   mov bx,num
   add ax,bx
   daa
   adc ah,0
   mov cl,al
   mov al,ah
   daa
   mov ah,al
   mov al,cl
   mov sum,ax
   ret