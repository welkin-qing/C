#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;   //������ 
	struct node *next;   //ָ���� 
}LNode,*LinkList;
//β�巨����һ�����Ա�
LinkList creat_LinkList2()
{
	LinkList H=(LinkList)malloc(sizeof(LNode));
	H->next=NULL;
	LNode *s,*r=H;
	int x,i;
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->next=r->next;
		r->next=s;
		//r=s;    //rָ���µ�β�ڵ� 
		scanf("%d",&x);
	 }
	 return H;
 } /*
LinkList creat_LinkList1()   //ͷ�巨�������� 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));
	H->next=NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->next=H->next;
		H->next=s;
		scanf("%d",&x);
	}
	return H;
}*/
int Length_LinkList (LNode *H)   //��������� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
		j++;
	}
	printf("\n");
	printf("����%d������!\n",j);
}
/*void PrintList(node *p)
{
	node *q=p;
	if(IsEmptyList(p))
	{
		do
		{
			printf("%d\t",q->data);
			q=q->next;
		}while(q!=p);
	}
}
int IsEmptyList(node *p)
{
	if(!p)
	{
		printf("��!\n");
		return 1;
	}
	return 0;
}*/
void reverse(LinkList H)  //���ú��� 
{
	LNode *p,*q;
	p=H->next;
	H->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next=H->next;
		H->next=q;
	}
}
int main()
{
    int i,j;
    LNode *p=NULL;
	printf("������10������:\n");
	printf("����-1ʱֹͣ���룡\n");
	p=creat_LinkList2(); //β�巨�������� 
	printf("���������Ϊ��\n");
	Length_LinkList(p);// ������� 
	reverse(p);
	printf("����û��������Ϊ��\n");
	Length_LinkList(p);
	//PrintList(p);	
}
