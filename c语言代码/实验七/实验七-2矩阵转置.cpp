#include<stdio.h>
void function(int a[4][4]) 
{
	int i,j,t;
		for(i=0;i<4;i++)
	{
		for(j=i;j<4;j++)
		{
		t=a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=t;
		
		}
 
	}
}
main()
{
	int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int i,j;
	printf("Ô­¾ØÕóÊÇ:\n"); 
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
/*	printf("ÇëÊäÈë¾ØÕó");
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	{
		scanf("%d",&a[i][j]);
	 } */
	 printf("ÐÂ¾ØÕóÊÇ£º\n");
	function(a); 
		for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
