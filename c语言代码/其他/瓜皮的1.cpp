#include<stdio.h>
#include<string.h>
int main(void)
{
	int a[10][10]={1},i=0,j=0;
	for(;i<=9;i++)
		a[i][0]=1;
	for(;i<=9;i++)
		a[i][i]=1;
	for(i=1,j=1;1<=i&&i<=9,1<=j&&j<=9;i++,j++)
	{
		a[i+1][j+1]=a[i][j]+a[i][j+1];
	}
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9&&a[i][j]!=0;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
	return 0;
}
