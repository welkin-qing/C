#include<math.h>
#include<stdio.h>
void function(int m)
{
	int i;
	int k;
	for(i=2;i<=m;)
	{
		if(m%i==0&&i!=m)
		{
			printf("%d,",i);
			m=m/i;
	     }
		 else if(m%i==0&&i==m) 
		 {
		 	printf("%d",i);
		 	m=m/i;
		 }
		 else i++;
	}
}
main()
{
	int m;
	scanf("%d",&m);
	function(m);
}
