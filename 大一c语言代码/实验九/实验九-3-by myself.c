#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	long num;
	char name[10];
	char sex;
	int age; 
	struct node * next;
}node;
node *crate()
{
	node *p,*head=NULL;
	p=(node *)malloc(sizeof(node));
	printf("num:\n");
	scanf("%d",&p->num);
	fflush(stdin);
	printf("name;\n");
	scanf("%s",p->name);
	fflush(stdin);
	printf("sex:\n");
	scanf("%c",&p->sex);
	fflush(stdin); 
	printf("age:\n");
	scanf("%d",&p->age);
	fflush(stdin);
	while(p->num!=0)
	{
		p->next=NULL;
		head=p;
		p=(node *)malloc(sizeof(node));
		printf("num:\n");
		scanf("%d",&p->num);
		fflush(stdin);
		printf("name;\n");
		scanf("%s",p->name);
		fflush(stdin);
		printf("sex:\n");
		scanf("%c",&p->sex);
		fflush(stdin); 
		printf("age:\n");
		scanf("%d",&p->age);
		fflush(stdin);
	}
	free(p);
	return head;
	
}
node *print(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("\tnum=%d\t",p->num);
		printf("name=%s\t",p->name);
		printf("sex=%c\t",p->sex);
		printf("age=%d\n",p->age);
		p=p->next;
	 } 
}
main()
{
	int n;
	node *head;
	crate();
	print(head);
	//printf("要删出的年龄:\n");
//	scanf("%d",&n}; 
}
