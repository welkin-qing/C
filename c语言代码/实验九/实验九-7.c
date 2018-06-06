#include<stdio.h>
#include<stdlib.h>
struct student{
	long num;
	char name[10];
	char sex;
	int age;
	struct student *next; 
};
int icount;
struct student *create() 
{
	struct student *phead=NULL; 
	struct student *pnew;  
	icount=0;
	pnew=(struct student*)malloc(sizeof(struct student));
	printf("num:\n");
	scanf("%d",&pnew->num);
	fflush(stdin);
	printf("name;\n");
	scanf("%s",pnew->name);
	fflush(stdin);
	printf("sex:\n");
	scanf("%c",&pnew->sex);
	fflush(stdin); 
	printf("age:\n");
	scanf("%d",&pnew->age);
	fflush(stdin);
	while(pnew->num!=0)
	{
		icount++;
		pnew->next=phead;   /*头插法*/ 
		phead=pnew;
		pnew=(struct student*)malloc(sizeof(struct student));
	    printf("num:\n");
		scanf("%d",&pnew->num);
		fflush(stdin);
		printf("name;\n");
		scanf("%s",pnew->name);
		fflush(stdin);
		printf("sex:\n");
		scanf("%c",&pnew->sex);
		fflush(stdin); 
		printf("age:\n");
		scanf("%d",&pnew->age);
		fflush(stdin);
	}
	free(pnew);
	return phead;
}
void print(struct student *phead)
{
	struct student *ptept;
	printf("共%d个学生\n",icount);
	ptept=phead;
	while(ptept!=NULL)
	{
		printf("\tnum=%d\t",ptept->num);
		printf("name=%s\t",ptept->name);
		printf("sex=%c\t",ptept->sex);
		printf("age=%d\n",ptept->age);
		ptept=ptept->next;
	 } 
}
struct   student   *delete(struct  student *phead,int n)
{
	struct  student  *ptemp;
	struct  student  *pre;
	for(ptemp=phead;ptemp;pre=ptemp,ptemp=pre->next)
	{
		if(ptemp->num==n)
		{
		   if(ptemp==phead)
		   {
		        phead=ptemp->next;
		   }
		   else  
		   {
		   		pre->next=ptemp->next;
		   		free(ptemp);
		   }
		}
	} 
	return  phead;
} 
main()
{
	int a;
	struct student *phead;
	phead=create();
	print(phead);
	printf("请输入要删去的学号a:\n");
	scanf("%d",&a);
	phead=delete(phead,a);
	print(phead);
}
