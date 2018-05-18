#include<stdio.h>
main()
{
	int a[5];
	int t;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<5;i++)
	for(int j=i;j<5;j++)
	{
		if(a[i]>a[j])
		{
			t=a[i];
			a[i]=a[j]; 
			a[j]=t;
		}
	}
	printf("最小是%d\n",a[0]);
	printf("最大是%d\n",a[4]);
	printf("和为%d",a[0]+a[4]);
 } 
