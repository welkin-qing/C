#include<stdio.h>
double sum(int a[],double n)
{
	int i;
	double sum=0;
	double ever;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}
	ever=sum/n;
	return(ever);
}
main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},b=0,i;
	double m,n;
	n=10.0;
	m=sum(a,n);
	printf("ƽ��ֵ%f\n",m);
	for(i=0;i<10;i++)
	{
		if(a[i]>m)   b++;
	 } 
	 printf("����ƽ��ֵ������%d\n",b);
	
}