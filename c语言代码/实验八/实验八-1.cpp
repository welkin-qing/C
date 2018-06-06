#define N 5
#include<stdio.h>
struct{
	long num;
	char name[10];
	int chinese;
	int english;
	int math;
}student[N];
main()
{
	int n;
	int i,j;
	double ever[N],t;
	double ave[N];
	printf("请输入学生人数n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("num:\n");
		scanf("%d",&student[i].num);
		fflush(stdin);
		printf("name:\n");
		scanf("%s",student[i].name);
		fflush(stdin);
		printf("chinese:\n");
		scanf("%d",&student[i].chinese);
		fflush(stdin);
		printf("english:\n");
		scanf("%d",&student[i].english);
		fflush(stdin);
		printf("math:\n");
		scanf("%d",&student[i].math);
		fflush(stdin);
	}
	for(i=0;i<n;i++)
	{
		ever[i]=(student[i].chinese+student[i].english+student[i].math)/3.0;
		ave[i]=ever[i];
		printf("%f\n",ever[i]);
	}
	for(i=0;i<n;i++)
	{
			printf("\t%5d\t%10s\t",student[i].num,student[i].name);
	    	printf("%8.2f\n",ever[i]);
		
	}
	for(i=1;i<n;i++)
	for(j=i;j<n;j++)
	{
		if(ever[i-1]<ever[j])
		{
			t=ever[i-1];
			ever[i-1]=ever[j];
			ever[j]=t;
		}
	} 
	for(i=0;i<n;i++)
	{
		if(ever[0]==(student[i].chinese+student[i].english+student[i].math)/3.0)
		{
			printf("最高分学生信息:\n");
			printf("\t%5d\t%s\t",student[i].num,student[i].name);
	    	printf("%8.2f\n",ever[i]);
		}
		
	}
	
}
