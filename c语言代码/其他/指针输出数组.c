#include <stdio.h>  
main()
{
	int b[10];
	int a[3][4]={
	{5,2,3,4},
	{10,20,30,40},
	{11,12,13,14}};
	int i,j;
	int *p=*a;
	
	for(i=0;i<3;i++)
	for(j=0;j<4;j++)
	{
		printf("%5d",*(p+i*4+j));
	}
	printf("\n%5d",a==&a);
	printf("\n%5d",b==&b);
	printf("\n%d",a);
	printf("\n%d",a+1);
	printf("\n%d",&a+1); 
}
	 
	/*for(p = *a;p<*a+12;++p)
	{
		printf("%5d",*p);
	 } */


