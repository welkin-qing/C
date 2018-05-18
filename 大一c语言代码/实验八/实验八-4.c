#define N 5
#include<stdio.h>
struct{
	char name[20];
	long num;
	int age;
	union{
		float score;
		char grade;
	}result;
}employee[N];
main()
{
	int n,i;
	printf("请输入考生人数n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("name:\n"); 
		scanf("%s",employee[i].name);
		fflush(stdin);
		printf("num:\n");
		scanf("%d",&employee[i].num);
		fflush(stdin);
		printf("age:\n");
		scanf("%d",&employee[i].age);
		fflush(stdin);
		if(employee[i].age<=30)  
		{
			printf("score:\n");
			scanf("%f",&employee[i].result.score) ;
		    fflush(stdin);
		}
		if(employee[i].age>30)  
		{
			printf("grade:\n");
			scanf("%c",&employee[i].result.grade);
			fflush(stdin);
		}
		
	}
	for(i=0;i<n;i++)
	{
		printf("\t%10s\t%5d%5d\t",employee[i].name,employee[i].num,employee[i].age);
		if(employee[i].age<=30)  printf("%f\n",employee[i].result.score) ;
		if(employee[i].age>30)  printf("%c\n",employee[i].result.grade);
	}
}
