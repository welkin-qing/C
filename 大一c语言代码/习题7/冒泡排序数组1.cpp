#include<stdio.h>
main()
{
	
	int a[5]={5,3,6,9,8};
	int i,j,t;
	for(j=1;j<5;j++)          /*�˵Ĵ���*/ 
	{
	for(i=1;i<=5-j;i++)           /*�ȽϵĴ���*/ 

	if(a[i-1]>a[i])              /*���ıȽ� ��С����*/ 
	{
	    t=a[i-1];
		a[i-1]=a[i];
		a[i]=t;
	}
	}
	for(i=0;i<5;i++)
	printf("%d\n",a[i]);
	
	



} 

