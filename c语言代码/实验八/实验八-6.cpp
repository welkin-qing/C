#define N 5 
#include<stdio.h>
#include<string.h>
struct{
	char name[10];
	long num;
	char sex;
	int  age;
	union{
		long position;
		char zhiwu[10]; 
	}qubie;
}employee[N];
main()
{
	int n,i;
	char work[N][20];
    char	str1[20]="yuangong";
	char    str2[20]="laoban";
	printf("请输入员工人数n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("name:\n"); 
		scanf("%s",employee[i].name);
		fflush(stdin);
		printf("num:\n");
		scanf("%d",&employee[i].num);
		fflush(stdin);
		printf("sex:\n");
		scanf("%c",&employee[i].sex);
		fflush(stdin);
		printf("age:\n");
		scanf("%d",&employee[i].age);
		fflush(stdin);
		printf("work is yuangong or laoban \n");
        scanf("%s",work[i]);
        if(strcmp(work[i],str1)==0) 
        {
        	printf("position:\n");
        	scanf("%d",&employee[i].qubie.position);
        	fflush(stdin);
		}
		if(strcmp(work[i],str2)==0) 
        {
        	printf("zhiwwu:\n");
        	scanf("%s",&employee[i].qubie.zhiwu);
        	fflush(stdin);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\t%10s\t%5d%5d\t%c\t",employee[i].name,employee[i].num,employee[i].age,employee[i].sex);
        if(strcmp(work[i],str1)==0)  printf("%5d\n",employee[i].qubie.position);
        if(strcmp(work[i],str2)==0)    printf("%10s\n",employee[i].qubie.zhiwu);
	}
}
	
