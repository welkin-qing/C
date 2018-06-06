#include<stdio.h>
struct student
{
	char num[10];
	char name[10];
	int age;
}; 
main()
{
	struct student stu;
	printf("num:\n");
	scanf("%s",stu.num);
	fflush(stdin);
	printf("name:\n");
	scanf("%s",stu.name);
	fflush(stdin);
	printf("age:\n");
//	flushall();
	scanf("%d",&stu.age);
	fflush(stdin);
	printf("%s\t%s\t%d\t",stu.num,stu.name,stu.age);
}
