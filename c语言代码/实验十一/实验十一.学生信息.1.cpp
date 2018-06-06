/*
#include<stdio.h>
struct student{
	char name[10];
	long num;
	int banji;
}stu[3];
main()
{
	FILE *fp;
	int i;
	printf("输入该班信息:\n");
	fp=fopen("class-list.txt","w");
	if(fp==NULL)
	{
		printf("不能打开此文件!\n");
		return 0;
	}
	for(i=0;i<3;i++)
	{
		printf("name:\n");
		gets(stu[i].name);
		//fflush(stdin);
		printf("num:\n");
		fscanf(fp,"%d",&stu[i].num);
		//fflush(stdin);
		printf("class:\n");
		fscanf(fp,"%d",&stu[i].banji);
		//fflush(stdin);
	}
	fclose(fp);
	return 0;
 }*/
 
#include<stdio.h>
#define N 20 
struct student{
	char name[10];
	long num;
	int banji;
}stu[N];
main()
{
	FILE *fp;
	int i,n;
	printf("请输入班级人数:\n");
	scanf("%d",&n);
	printf("输入该班信息:\n");
	fp=fopen("class-list.txt","w");
	if(fp==NULL)
	{
		printf("不能打开此文件!\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		printf("name:\n");
		scanf("%s",stu[i].name);
		
		//fflush(stdin);
		printf("num:\n");
		scanf("%d",&stu[i].num);
	
		//fflush(stdin);
		printf("class:\n");
		scanf("%d",&stu[i].banji);
	printf("%s    %d     %d\n",stu[i].name,stu[i].num,stu[i].banji);
	
		//fflush(stdin);
		fprintf(fp,"%s   %d   %d\n",stu[i].name,stu[i].num,stu[i].banji);
	}
	fclose(fp);
	return 0;
}

