/*#include <stdio.h>
#define M 10
#define N 10

main() 
{   
    int a[M];
    int b[N];
    int c[M+N];
    int m,n;
	int i=0,j=0,k=0,min;
	scanf("%d，%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&b[i]);
	}
	while(i<m||j<n)
	{
		if(a[i]>b[j])
		{
			min=b[j];
			j++;
			if(j>=n) 
				b[j]=65535; //置为最大值
		}
		else
		{
			min=a[i];
			i++;
			if(i>=m) 
				a[i]=65535;
		}
		c[k]=min;
		k++;	
	}
	for(i=0;i<m+n;i++)	
		printf("%5d",c[i]);	
}*/

#include <stdio.h>
#define M 10
#define N 10
int a[M]={1,2,3,4,5,6,7,8,9,10};
int b[N]={2,4,6,8,10,12,14,16,18,20};
int c[M+N];
void main()
{
	int i=0,j=0,k=0,min;
	while(i<M||j<N)
	{
		if(a[i]>b[j])
		{
			min=b[j];
			j++;
			if(j>=N) 
				b[j]=65535; //置为最大值
		}
		else
		{
			min=a[i];
			i++;
			if(i>=M) 
				a[i]=65535;
		}
		c[k]=min;
		k++;	
	}
	for(i=0;i<M+N;i++)	
		printf("%5d",c[i]);	
}


