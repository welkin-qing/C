#include<string.h>
#include<stdio.h>
void function(char a[][20])
{
	char b[20];
	int i,j; 
	for(i=1;i<3;i++)
	for(j=i;j<3;j++)
	{
		if(strcmp(a[i-1],a[j])==-1)
		{
			strcpy(b,a[i-1]);
			strcpy(a[i-1],a[j]);
			strcpy(a[j],b);
		}
	}
	printf("按从大到小排序好的字符串是:\n");
	for(i=0;i<3;i++)
	{
		printf("%s\n",a[i]);
	}
 }
 main()
 {
 	char a[8][20];
 	int i,j;
	printf("输入字符数组： \n");
	for(i=0;i<3;i++)
	{
		gets(a[i]);
	}
	printf("输出该字符串是:\n");
		for(i=0;i<3;i++)
	{
		printf("%s\n",a[i]);
	}
	function(a);
  } 
