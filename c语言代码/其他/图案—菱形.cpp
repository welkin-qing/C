#include<stdio.h>
main()
{
	int i,j;
	int n;
	printf("number n ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		printf("*");                    /*����i��ֵ�����*�ĸ���*/ 
		printf("\n");
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)  printf(" ");        /*����i��ֵ����ո�ĸ���*/ 
		for(j=1;j<=n-i;j++)  printf("*");      /*��ʱ*�ĸ�������4-i�仯*/ 
		printf("\n");
	}

	

}
