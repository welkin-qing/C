/*������������в������ɸ�����ʹ�����ڲ��������ʼ�ձ�������*/
#include <stdio.h>
#define N 10 
int a[N];
int main()
{
	int n,i,j,k;
	int x,y;
	y=N;
	printf("����n����:n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
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

