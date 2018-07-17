#make_COM#

; COM file is loaded at CS:0100h
ORG 100h
start:
   mov BX,0
   mov CX,5
   
 lp:
    mov dl,v1[BX]
    add al,dl
    daa
    adc ah,0
   
   inc BX
   dec CX
   jnz lp
   mov sum,ax
ret
v1 db 45h,67h,34h,45h,23h
sum dw 0;