#define N 10
#include<stdio.h>
void function(int a,int n)
{
	int i,j,t;
	int *p;
	*p=a;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
		{
			if(*(p+i)>*(p+j))
			{
				t=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=t;
			}
		}
		for(i=0;i<n;i++)
		printf("%d",*(p+i));
}
main()
{
	int b[N];
    int i,n;
	printf("请输入数组长度");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	function(b,n);
}


