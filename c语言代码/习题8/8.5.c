#include<stdio.h>
void function(int m,int n)
{
	int a,b,c,i;
	for(i=m;i<n;i++)
	{
		a=i%10;
		b=i/10%10;
		c=i/100;
		if(i==a*a*a+b*b*b+c*c*c)
			printf("%d\n",i);
	}
}
main()
{
	int m,n;
	printf("´Ómµ½n");
	scanf("%d,%d",&m,&n);
	function(m,n);
}




