���Ǹ���ŵ�������ڵ��Ե�ʱ�������������ò�Ҫ����15����Ϊÿ��һ����
���õĽ���Ĳ��趼���һ��������������ĵȴ�����Ļ����⡣��ŵ������ŷ��
���е�һ����Ϸ����a,b,c�����͡�a���������ɸ��ɴ�С��Բ�̣���������棬
С�������棬b,c���ǿոˣ������a���ϵ�Բ�̶�������ĸ��ϣ���b��c���ڵ���
�Ĺ����в����Դ��ѹС�ģ�ʵ���������£�

#include <stdio.h>
int i=0;
main()
{
	unsigned n;
	printf("Please enter the number of discs: ");
	scanf("%d",&n);
	printf("\tneedle:\ta\t b\t c\n");
	movedisc(n,'a','c','b');
	printf("\t Total: %d\n",i);
	getch();
}
movedisc(n,fromneedle,toneedle,usingneedle)
unsigned n;
char fromneedle,toneedle,usingneedle;
{
	if(n>0)
	{
		movedisc(n-1,fromneedle,usingneedle,toneedle);
		i++;
		switch(fromneedle)
		{
		   case 'a':switch(toneedle)
				 {
		            case 'b':printf("\t[%d]:\t%2d------>%2d\n",i,n,n);
						break;
					case 'c':printf("\t[%d]:\t%2d------------->%2d\n",i,n,n);
						break;
				 }
			   break;
            case 'b':switch(toneedle)
				 {
		            case 'a':printf("\t[%d]:\t%2d<----------%2d\n",i,n,n);
						break;
					case 'c':printf("\t[%d]:\t\t%2d------>%2d\n",i,n,n);
						break;
				 }
			   break;
            case 'c':switch(toneedle)
				 {
		            case 'a':printf("\t[%d]:\t%2d<--------------%2d\n",i,n,n);
						break;
					case 'b':printf("\t[%d]:\t\t%2d<--------%2d\n",i,n,n);
						break;
				 }
			   break;
		}
        movedisc(n-1,usingneedle,toneedle,fromneedle);
	}
}