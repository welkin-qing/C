/*�ҳ�6*6����ÿ�о���ֵ���ֵ��Ԫ�أ�����ͬ�жԽ���Ԫ�ؽ���*/
#include<stdio.h>
#include<math.h>
#define n 6
void main()
{
	int i,j,t;
	long max,a[n][n],change;
	printf("���������(6x6):\n");
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	{
		max=fabs(a[i][0]);
	    t=0;
		for(j=1;j<n;j++)
			if(max<fabs(a[i][j]))
			{
				max=fabs(a[i][j]);
				t=j;
			}
			change=a[i][t];
			a[i][t]=a[i][i];
			a[i][i]=change;
	}
	printf("������ľ���Ϊ:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
				printf(" %3d",a[i][j]);
		printf("\n");
	}
}