��һ��ʱ��ֱ�Ӷ�ȡ���ֿ⣬���ڲ��ú���ϵͳҲ����ʾ���֣��Ǻ����еļ���������Ҳ���ڹ�����ҵ�õ����ˡ�����Ӳ����չ�������˷��ڴ�Ľ�������Ҳ��ۣ������ǿ������ֿ⡣
16X16������ֿⰴ������˳�����У�ÿ������32�ֽڣ�256BIT����ŵ�����Ϣ����ʽ���£�

                 ��һ�ֽڵڶ��ֽ�
                 �����ֽڵ����ֽ�
                 �����ֽڵ����ֽ�
                 �����ֽڵڰ��ֽ�



�㿴����ɣ�������ġ�
���ǣ��ֲ���ÿ���ֿⶼһ������������Ϊ��Щ�ֿ��Ӣ����ģҲ����һ��ɡ������õ���UCDOS���ֿ�


#include < io.h>
#include < fcntl.h>
#include < stdio.h>
#include < dos.h>
#define CCLIB "c:\hzk16"

display(unsignedchar *hzmp, int x, int y, int color, int bkcolor)
 { charfar *p; 
 int i, j, k;
 p= (char far *)(0xa0000000+80*y+x/8); 
 for (i= 0; i < 16; i++) 
	for(j = 0; j < 2; j++)
	 { outport(0x3ce, 0x0205);	// kernel here
		k=*(p+80*i+j);
		outportb(0x3ce, 0x08); 
		outportb(0x3cf, hzmp[2*i+j]); 
		*(p+80*i+j)=color; 
		k=*(p+80*i+j);
		outportb(0x3ce, 0x08); 
		outportb(0x3cf, ~hzmp[2*i+j]); 
		*(p+80*i+j)=bkcolor;
		} 
outport(0x3ce, 0x005);	//reset
outport(0x3ce, 0xff08); 
} 

main()
{
 union REGS r;
 int handle, mode;
 int i;
 int qh, wh, col, row;
 long offset;
 unsigned char *hz, hzm[32];
 handle=open(CCLIB, O_RDONLY|O_BINARY);
 r.h.ah=0x0f;int86(0x10, &r, &r);
 mode=r.h.al;
 r.x.ax= 0x0012; 
 int86(0x10, &r, &r);
 for(i=0; i < 20; i++){
	 col=0;row=20*i; 
	 hz="ϣ�����Թ�˾��Ϊ�˼���˳����ִ���ٶ�������˵���û�б�����������д�����"; 
	 
	while(*hz){ /*find theqh, wh*/
		 qh = *hz-0xa0;
		 wh = *(hz+1)-0xa0;
		 offset = (94l*(qh-1)+(wh-1))*32l;
		 lseek(handle, offset, SEEK_SET); 
		 read(handle, hzm, 32);/*display*/
		 display(hzm, col, row, 4, 3);
		 col += 16;
		 hz += 2; 
	 } 
 } 
 r.h.ah=0x00;
 r.h.al= mode;
 int86(0x10, &r, &r);
 } 


