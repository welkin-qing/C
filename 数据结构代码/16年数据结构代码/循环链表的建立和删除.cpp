//16����д 
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
	printf("��������ĳ���:");
	scanf("%d",H->data);//�����б���ͷ��㣬ͷ����������ʾ����ĸ���
	if(H->data==0)
	{
		H->next=NULL;
		printf("�Ѵ�������ͷ���Ŀ�����!");
	}
	else
	{
		printf("����������:\n");
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
   printf("���봴������ĳ��ȣ�");
   scanf("%d",&head->num);//�����б���ͷ��㣬ͷ����������ʾ����ĸ���
   if(head->num==0)
   {
	   head->next=NULL;
	   printf("�Ѵ�����ͷ���Ŀ�����"); 
   }
   else
   {
      printf("�������ݣ�\n");
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

