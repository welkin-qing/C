//16年所写 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}CrLinkList;

CrLinkList creat_Circular()
{
	int i;
	CrLinkList *p1,*p2,*H;
   // H=(CrLinkList)malloc(sizeof(CrLinkList));
	if((H=(CrLinkList *)malloc(sizeof(CrLinkList)))==NULL)
	{
		printf("error!");
		exit(0);
	}
	p1=p2=H;
	printf("输入链表的长度:");
	scanf("%d",H->data);//创建列表，带头结点，头结点数据域表示输入的个数
	if(H->data==0)
	{
		H->next=NULL;
		printf("已创建带有头结点的空链表!");
	}
	else
	{
		printf("请输入数据:\n");
		for(i=0;i<H->data;i++)
		{
			if((p1=(CrLinkList *)malloc(sizeof(CrLinkList)))==NULL)
			{
				printf("error!");
				exit(0);
			}
			scanf("%d",&p1->data);
			p2->next=p1;
			p2=p1;
		}
		p1->next=H;
	}
	return H;
}
void print(CrLinkList *H)
{
	CrLinkList *p;
	p=H->next;
	while(p!=H)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	CrLinkList *p;
	p=creat_Circular();
	print(p);
}
/*#include <stdio.h> 
#include<malloc.h>
#include<stdlib.h>
typedef struct list
{
	int num;
	struct list *next;
}List;
int n=0;
List *creat()
{
   List *head,*p1,*p2;
   int i;
   if((head=(List *)malloc(sizeof(List)))==NULL)
   {
	   printf("Error");
	   exit(0);
   }
   p1=p2=head;
   printf("输入创建链表的长度：");
   scanf("%d",&head->num);//创建列表，带头结点，头结点数据域表示输入的个数
   if(head->num==0)
   {
	   head->next=NULL;
	   printf("已创建带头结点的空链表"); 
   }
   else
   {
      printf("输入数据：\n");
      for(i=0;i<head->num;i++)
	  {
	      if((p1=(List *)malloc(sizeof(List)))==NULL)
		  {
	         printf("Error");
	         exit(0);
		  }
          scanf("%d",&p1->num);
		  p2->next=p1;
		  p2=p1;
	  }
	  p1->next=head;
   }
    return(head);
}
void print(List *head)
{
   List *p;
   p=head->next;
   for(;p!=head;)
   {
	   printf("%d ",p->num);
	   p=p->next;
   }
   printf("\n");
}
int main()
{ 
	List *head;
    head=creat();
    print(head);
}*/

