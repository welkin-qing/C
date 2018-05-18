#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;  //指针域 
}LNode,*LinkList;
LinkList creat_Linklist()  //尾插法建立一个链表 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));   //申请内存空间 
	H->next=NULL;  //置空
	LNode *s,*r=H; //将头结点赋给r 
	int x;
	printf("请输入要排列的数：\n");
	printf("当数为-1的时候停止\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LinkList)malloc(sizeof(LNode)); 
		s->data=x;//赋值
		s->next=r->next;//移动
		r->next=s;
		r=s;
		scanf("%d",&x); 
	 } 
	return H;
 } 
int Length_LinkList (LNode *H)   //输出该链表 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		//p=p->next;
		printf("%d\t",p->data);
		p=p->next;
		j++;  //记录链表的长度 
	}
	printf("\n");
	printf("共有%d个数据!\n",j);
}
void reveres(LinkList H)
{
	LNode *p,*q;
	p=H->next;
	H->next=NULL;
	while(p)
	{
		q=p;  //将值放在q中暂存
		p=p->next;  //p后移寻找下一个元素
		q->next=H->next;     //将当前结点插在头结点的后面（以下两步都是）
		H->next=q; 
	}
} 
main()
{
	LNode *p=NULL;
	p=creat_Linklist();
	printf("\t输出该链表为：\n");
	Length_LinkList(p);
	printf("\n\t输出置换后的链表为：\n");
	reveres(p);
	Length_LinkList(p);
 } 
