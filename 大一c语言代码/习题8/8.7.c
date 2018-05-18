#include<stdio.h>
void function(int n)
{
	int i;
	int s,m;
	for(m=1;m<n;m++)
	{
		s=0;
		for(i=1;i<=m/2;i++)  if(m%i==0) s+=i;
		if(m==s)  printf("%5d\t",m);
	}
}
main()
{
	int n;
	printf("求n以内的完全数");
	scanf("%d",&n);
	function(n);
}
