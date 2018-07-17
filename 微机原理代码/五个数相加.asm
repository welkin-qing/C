#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

start:
   mov bl,v1[0]
   mov al,v1[1];
   add al,bl
   daa
   adc ah,0
   
   mov bl,v1[2]
   add al,bl
   daa
   adc ah,0
   

   mov bl,v1[3]
   add al,bl
   daa
   adc ah,0
   
   mov bl,v1[4]
   add al,bl
   daa
   adc ah,0
   
   mov sum,ax
  ret
v1 db 23h,34h,33h,43h,57h
sum dw 0;