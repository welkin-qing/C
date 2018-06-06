#include<stdio.h>
void function(int *p(),int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)  
	{
	for(j=i+1;j<n;j++)   
		if(p[i]>p[j])   
		{
		t=p[i];
		p[i]=p[j];
		p[j]=t;
		}
		
	}
	for(i=0;i<n-1;i++)  
	{
		printf("%d",*p(i));
	}
}
main()
{
	int *p()={0};
	int n=0,i;
	printf("请输入要排列的数n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",p(i));
	}
	function(*p(),n)
	
	
}
