#define N 5
#include<stdio.h>
#include<string.h>
struct{
	char name[10];
	long num;
	char sex;
	int age;
}student[N];
main()
{
	int n,i,j,t;
	int zan[N];
	char yingwen[N][10];
	printf("请输入学生人数n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("name:\n");
		scanf("%s",student[i].name);
		yingwen[i][20]=student[i].name;
		fflush(stdin);
		printf("num:\n");
		scanf("%d",&student[i].num);
		zan[i]=student[i].num;
		fflush(stdin);
		printf("sex:\n");
		scanf("%c",&student[i].sex);
		fflush(stdin);
		printf("age:\n");
		scanf("%d",&student[i].age);
		fflush(stdin);
	}
	printf("按学号顺序排列：\n");
	for(i=1;i<n;i++)
	for(i=j;j<n;j++)
	{
		/*if(student[i-1].num<student[j].num)
		{
			t=student[i-1].num;
			student[i-1].num=student[j].num;
			student[j].num=t;
		}*/
		if(zan[i-1]<zan[j])
		{
			t=zan[i-1];
			zan[i-1]=zan[j];
			zan[j]=t;
		}
	}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(zan[i]==student[j].num) 
		{
			printf("\t%10s\t%5d\t%c\t%5d\n",student[j].name,student[j].num,student[j].sex,student[j].age);
		}
	}
	/*printf("按姓名排序有：\n");
	for(i=1;i<n;i++)
	for(i=j;j<n;j++)
	{
		/*if(sizeof(student[i-1].name)<sizeof(student[j].name))
		{
			t=sizeof(student[i-1].name);
			sizeof(student[i-1].name)=sizeof(student[j].name);
			sizeof(student[j].name)=t;
		}*/
	/*	if(strcmp(yingwen[i-1],yingwen[j]))
		{
			
		}
	}*/
	
}
