
/*#include<stdio.h>
main()
{
	int a[6];
	int i,j=0;
	int sum=0;
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<6;i++)
	{
		sum+=a[i];
		j++;
	}
	printf("%d",sum/j);
}*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n ;
	int sum = 0;
	scanf("%d",&n);
	int *p = (int *)malloc(sizeof(int)*n);
	if(p == NULL)
		return 0;
	for(int i = 0 ; i < n ;++i)
	{
		scanf("%d",p+i);
	}
	for(int i = 0 ; i < n ;++i)
	{
		sum+=p[i];
	}
	printf("%d\n",sum/n);
	free(p);
	p = NULL;
	return 0;
}

