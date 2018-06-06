#define N 10
#include<stdio.h>
main()
{
	int a[N];
	int i=0,t,j=8,n; 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(i<j)
	{
		t=a[i];
		a[i]=a[j-1];
		a[j-1]=t;
		i++;
		j--;
	}
	for(i=0;i<n;i++)  printf("%5d",a[i]);
 }
