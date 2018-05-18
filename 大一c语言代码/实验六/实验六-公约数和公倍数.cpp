#include<stdio.h>
int max(int x,int y)
{
	int r,ji,bei;
	r=x%y;
	ji=x*y;
	while(r!=0)
	{
		x=y;
		y=r;
		r=x%y; 
	}
    bei=ji/y;
	return(y);
}
/*int min(int x,int y)
{
    int r,ji,bei;
	ji=x*y;
	r=x%y;
	while(r!=0)
	{
		x=y;
		y=r;
		r=x%y; 
	}
    bei=ji/y;
	return(bei);
}*/
main()
{
	int a,b,m,n;
	scanf("%d%d",&a,&b);
    m=max(a,b);
	printf("最大公约数是%5d\n",m);
	n=a*b/m;
    printf("最小公倍数是%5d\n",n);
}
 
