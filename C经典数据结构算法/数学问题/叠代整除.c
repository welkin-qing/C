#include <stdio.h>
quyu(long int m)
{
 int x=0,y=0,z=0,he=0;
	 if(m%3==0)
		 x=1;
	 if(m%5==0)
		 y=2;
	 if(m%7==0)
		 z=4;
 he=x+y+z;
 return he;
}
main()
{
long int m;
scanf("%d",&m);
switch(quyu(m))
{
case 0:
	printf("���ܱ��κ������� ");
	break;
case 1:
	printf("�ܱ�3���� ");
    break;
case 2:
	printf("�ܱ�5���� ");
	break;
case 3:
	printf("�ܱ�3��5���� ");
    break;
case 4:
	printf("�ܱ�7���� ");
	break;
case 5:
	printf("�ܱ�3��7���� ");
    break;
case 6:
	printf("�ܱ�5��7���� ");
	break;
case 7:
	printf("�ܱ�3��5��7���� ");
    break;
}
}