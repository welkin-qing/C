#include <stdio.h>
#define N 100
main()
{
    int a[N];
	int i,q,k;
	int n,m;
	printf("请输入n的值:\n");
	scanf("%d",&n);
	printf("请输入m的值:\n");
	scanf("%d",&m);
    for(i=0;i<n;i++)
	a[i]=i+1;

    q=0;
    i=0;
    k=0;
    while(q<n-1)
	{
	if(a[i]!=0)
	k++;
	if(k==m)
	{
		a[i]=0;
		q++;
        k=0;
	}
    i++;
    if(i==n)
    i=0;
    }
   for(i=0;i<n;i++)
    if(a[i]!=0)
    printf("最后保留的人为%d号\n",a[i]);
 }
 
