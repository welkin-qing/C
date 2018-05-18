#include<stdio.h>
#include<stdlib.h>
struct student{
	long num;
	char name[10];
	struct student *next;
};
struct student *create()  /*未带有头结点*/ 
{
	struct student *head=NULL;
	struct student *p;
	p=(struct student *)malloc(sizeof(struct student));
	printf("num:"); 
	fflush(stdin);
	scanf("%d",&p->num);
	printf("name:");
	fflush(stdin);
	scanf("%s",p->name);
	while(p->num!=0)
	{
		p->next=head;
		head=p;
		p=(struct student*)malloc(sizeof(struct student));
		printf("num:");
		fflush(stdin);
		scanf("%d",&p->num);
		printf("name:");
		fflush(stdin);
		scanf("%s",p->name);
	}
	free(p);
	return head;
}
void print(struct student *head)
{
	struct student *p;
	p=head;
	while(p!=NULL)
	{
		printf("num:%10d\t",p->num);
		printf("name:%10s\n",p->name);
		p=p->next;
	}
}
struct student *delete(struct student *head,long n)
{
	struct student *p,*q;
	for(p=head;p;q=p,p=q->next)
	{
		if(p->num==n)
		{
			if(p==head)
			{
				head=p->next;
			}
			else
			{
				q->next=p->next;
				free(p);
			}
		}
	}
	return head;
}
struct student *insert(struct student *head,long n)
{
	struct student *p=head,*q;
	while(p&&p->num!=n)  p=p->next;
	q=(struct student *)malloc(sizeof(struct student));
	printf("num:");
	fflush(stdin);
	scanf("%d",&q->num);
	printf("name:");
	fflush(stdin);
	scanf("%s",q->name);
	q->next=p->next;
	p->next=q;
	return head;
}
main()
{
	long m,n;
	struct student *head;
	head=create();
	print(head);
	printf("请输入要删除的学号：");
	scanf("%d",&m);
	head=delete(head,m);
	print(head);
	printf("请输入要插入那个学生的后边；请输入学号:");
	scanf("%d",&n);
	head=insert(head,n);
	print(head);
}
