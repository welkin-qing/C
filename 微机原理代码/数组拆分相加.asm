#make_COM#

; COM file is loaded at CS:0100h
ORG 100h

jmp start:
	data1 db 54h,8fh,0b9h,96h,3ch,0e7h;
	data2 db 3fh,0cdh,4fh,0a2h,3bh,8dh;
	sum db ?,?,?,?,?,?,?;
start:
	mov di,offset data1+5;
	mov bx,offset data2+5;
	mov dl,6;
lp:	mov al,[di];
	mov ah,[bx];
	add al,ah;
	daa
	dec di;
	dec bx;
	dec dl;
	jnz lp;
	ret;