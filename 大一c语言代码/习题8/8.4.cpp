#define PI 3.14
#include<stdio.h>
void function(int r1,int r2,int h) 
{
	double v;
	v=PI*r1*r1*h-PI*r2*r2*h;
	printf("%4.2f",v);	
}
main()
{
	int r1,r2,h;
	double v;
	scanf("%d,%d,%d",&r1,&r2,&h);
	function(r1,r2,h);
}
