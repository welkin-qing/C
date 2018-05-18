#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;   //数据域 
	struct node *next;   //指针域 
}LNode,*LinkList;
//尾插法建立一个线性表
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
		//r=s;    //r指向新的尾节点 
		scanf("%d",&x);
	 }
	 return H;
 } /*
LinkList creat_LinkList1()   //头插法建立链表 
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
int Length_LinkList (LNode *H)   //输出该链表 
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
	printf("共有%d个数据!\n",j);
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
		printf("空!\n");
		return 1;
	}
	return 0;
}*/
void reverse(LinkList H)  //逆置函数 
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
	printf("请输入10个数据:\n");
	printf("输入-1时停止输入！\n");
	p=creat_LinkList2(); //尾插法建立链表 
	printf("输出该链表为：\n");
	Length_LinkList(p);// 输出函数 
	reverse(p);
	printf("输出置换后的链表为：\n");
	Length_LinkList(p);
	//PrintList(p);	
}
