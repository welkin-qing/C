#include<stdio.h>
main()
{
	int n,i,j,num=1,c=0;
	int line;
	int a[20][20];
	scanf("%d",&line);
	for(n=0;n<=line/2;n++)
	{
		for(j=n;j<line-n;j++)     a[n][j]=num++;
		for(i=n+1;i<line-n;i++)    a[i][line-n-1]=num++;
		for(j=line-n-2;j>=n;j--)    a[line-n-1][j]=num++;
		for(i=line-n-2;i>n;i--)     a[i][n]=num++;
	 } 
	 for(i=0;i<line;i++)
	 for(j=0;j<line;j++)
	 {
	 	printf("%d",a[i][j]);
	 	printf(" ");
	 	c++;
	 	if(c%line==0) printf("\n");
	 }
 } 
