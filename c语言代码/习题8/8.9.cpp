#include<stdio.h>
void function(int m)
{
	int s=1,i;
	for(i=1;i<=m;i++)
	{
		s=s*i;
	}
	printf("%d",s);
 } 
 main()
 {
 	int m;
 	scanf("%d",&m);
 	function(m);
 }
