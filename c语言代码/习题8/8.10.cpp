#include<stdio.h>
void function(int m,int n)
{
	int i,s=1;
	for(i=1;i<=n;i++)
	{
		s*=m;
	}
	printf("%d",s);
}
main()
{
	int m,n;
	scanf("%d,%d",&m,&n);
	function(m,n);
}
