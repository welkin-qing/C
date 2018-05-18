#include<stdio.h>
main()
{
	int c[3][5],i,j;
	int *p=&c[3][5];
	printf("ÇëÊäÈë15¸öÊı×Ö");
	for(i=0;i<3;i++)
	for(j=0;j<5;j++)
	{
		scanf("%d",&c[i][j]);
		
	}
	for(i=0;i<3;i++)
	for(j=0;j<5;j++)
	{
		p=&c[i][j];
	 
		printf("%d\n",p);
	}
	
}
