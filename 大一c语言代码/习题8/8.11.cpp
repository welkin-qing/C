#include<stdio.h>
void function(int x,int n)
{
	int i,s=1,j=1;
	int sum=0;
	for(i=1;i<=n;i++)
	{
		s*=x;
		sum+=s*j;
		j=-j;
	}
	printf("%d",sum);
}
main()
{
	int x,n;
	scanf("%d,%d",&x,&n);
	function(x,n);
}
