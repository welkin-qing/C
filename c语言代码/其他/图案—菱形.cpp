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
		printf("*");                    /*随着i的值来输出*的个数*/ 
		printf("\n");
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)  printf(" ");        /*随着i的值输出空格的个数*/ 
		for(j=1;j<=n-i;j++)  printf("*");      /*此时*的个数随着4-i变化*/ 
		printf("\n");
	}

	

}
