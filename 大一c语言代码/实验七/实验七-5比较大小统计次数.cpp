#include<stdio.h>
main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},b[10]={0,4,3,2,1,5,8,1,4,3};
	int i,j;
	int m=0,n=0,p=0;
	for(i=0;i<10;i++)
	{
		if(a[i]>b[i])          m++;
		else if (a[i]==b[i])   n++;
		else if (a[i]<b[i])    p++;
	}
	printf("a[10]>b[10]=%d\n",m);
	printf("a[10]=b[10]=%d\n",n);
	printf("a[10]<b[10]=%d\n",p);
 } 
