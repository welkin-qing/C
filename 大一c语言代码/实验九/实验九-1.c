
#define N 5
#include<stdio.h>
typedef struct student{
	long num;
	char name[10];
	int score;
}STUDENT,*STU;
main()
{
	int i,j,t;
	int n;
	int zan[N],a[N];
	STUDENT st[N];
	STUDENT *p=&st;
	printf("请输入人数n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("num:\n");
		scanf("%d",&st[i].num);
		zan[i]=st[i].num;
		fflush(stdin);
		printf("name:\n");
		scanf("%s",st[i].name);
		fflush(stdin);
		printf("score:\n");
		scanf("%d",&st[i].score);
		a[i]=st[i].score;
		fflush(stdin);
	}
	printf("按学号顺序排列：\n");
    for(i=1;i<n;i++)
    for(j=i;j<n;j++)
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
        if(zan[i]==st[j].num) 
    	{
            printf("\t%5d\t%10s\t%5d\n" ,zan[i],(p+j)->name,(p+j)->score);
    	}
    }
    printf("按成绩排序有:\n");
    for(i=1;i<n;i++)
    for(j=i;j<n;j++)
    {
        if(a[i-1]<a[j])
    	{
            t=a[i-1];
            a[i-1]=a[j];
            a[j]=t;
    	}
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if(a[i]==st[j].score) 
    	{
            printf("\t%5d\t%10s\t%5d\n" ,(p+j)->num,(p+j)->name,a[i]);
    	}
    }
}



/*#include <stdio.h>
#define N 100
typedef struct student
{
 int id;        //学号
 char name[20]; //姓名
 int gender;   //性别（0代表男生，1代表女生）
 float score;   //成绩
}stu;
stu s[N];
main()
{
 int i,j;
 int n;
 printf("请输入人数n:\n");
scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("请输入第%d个学生的学号:",i+1);
  scanf("%d",&s[i].id);
  printf("请输入第%d个学生的姓名:",i+1);
  scanf("%s",&s[i].name);
  printf("请输入第%d个学生的性别:",i+1);
  scanf("%d",&s[i].gender);
  printf("请输入第%d个学生的成绩:",i+1);
  scanf("%f",&s[i].score);
 }
 stu ss[N];
 stu* p=ss;
 for(i=0;i<n;i++)
  ss[i]=s[i];
 for(i=0;i<n-1;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(ss[i].score<ss[j].score)
   {
    stu temp=*(p+i);
    *(p+i)=*(p+j);
    *(p+j)=temp;
   }
  }
 }
 printf("所有学生的信息按成绩由高到低排名如下:\n");
 printf("学号\t姓名\t性别\t成绩\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t%s\t%d\t%.1f\n",(p+i)->id,(p+i)->name,(p+i)->gender,(p+i)->score);
 }
}
*/
