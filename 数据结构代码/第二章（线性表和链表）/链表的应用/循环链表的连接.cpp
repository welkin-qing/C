//有序循环链表的合并
//仅仅是连接两个循环链表 
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;  //数据域
	struct Node *next; 
}Node;
Node *creat_list()
{
	Node *H,*p,*r;
	int x;
	p=H=(Node * )malloc(sizeof(Node));
	printf("请输入数值:\n");
	printf("输入0时结束！\n");
	scanf("%d",&x);
	while(x!=0)
	{
		r=(Node * )malloc(sizeof(Node));
		r->data=x;
		p->next=r;// 尾插法建立坐标 
		p=r;
		scanf("%d",&x);
	}
	r->next=H;  //建立循环链表 
	return r;
 } 
void print_list(Node *H)  //输出链表 
{
	Node *p;
	p=H->next->next;
	while(p!=H->next)   //判断是否等于头指针 
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
Node *merge(Node *L1,Node *L2)  //连接两个链表 
{
	Node *p;
	p=L1->next;
	L1->next=L2->next->next;   //将l2连接在l1上 
	L2->next=p;
	return L2;
}
main()
{
	Node *p1,*p2,*t;
	//p=(Node *)malloc(sizeof(Node));
	printf("链表1为：\n");
	p1=creat_list();
	print_list(p1);
	printf("链表2为：\n");
	p2=creat_list();
	print_list(p2);
	t=merge(p1,p2);
	print_list(t);
	return 0;
}
 
