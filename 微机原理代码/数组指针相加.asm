#make_COM#

; COM file is loaded at CS:0100h
ORG 100h
jmp start
	cost db 20h,28h,15h,26h,19h,27h,16h,29h,39h,42h;
	price db ?,?,?,?,?,?,?,?,?,?;
start: 	mov di,offset cost;
	mov bx,offset price;
	mov dl,10;
lp:	mov al,[di];
	add al,15h;
	daa
	mov [bx],al;
	inc bx;
	inc di;
	dec dl;
	jnz lp;
	ret;