#include<stdio.h>
main()
{
	int a[10]={1,-1,2,-3,4,-5,6,-7,9,-45};
	int c[5]={0},b[5]={0};
	int i,m=0,n=0,q=0;
	for(i=0;i<10;i++)
	{
		if(a[i]>0)
		{
			b[m]=a[i];
			m++;
		}
		else if(a[i]<0)
		{
			c[n]=a[i];
			n++; 
		}
	}
	for(i=0;i<5;i++)
	{
		a[i]=b[i];
		q++;
	}
	for(i=0;i<5;i++)
	{
		a[q++]=c[i];
	}
	for(i=0;i<10;i++)
	{
		printf("%5d",a[i]);
	}
 } 
