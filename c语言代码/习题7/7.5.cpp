#include "stdio.h"
#define N 10 //ԭ������Ԫ�ظ���
int a[100]={1,2,3,4,5,6,7,8,9,10};
main()
{
	int n,i,j,k;
	int x,y;
	y=N;
	for(i=0;i<5;i++)
	{
		printf("�������%d����",i+1);
		scanf("%d",&x);	/*����Ԫ�صĲ���,�����һ��Ԫ�ؿ�ʼ�������ƶ�*/
		for(j=0;j<y+1;j++)
		{
			if(x<a[j]||j==y)
			{
				for(k=y+1;k>j;k--)
					a[k]=a[k-1];
				a[j]=x;
				break;
			}
		}
		y++;
	}
	for(i=0;i<y;i++) printf("%d ",a[i]);
	return 0;
}
