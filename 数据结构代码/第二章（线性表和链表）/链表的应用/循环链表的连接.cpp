//����ѭ������ĺϲ�
//��������������ѭ������ 
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;  //������
	struct Node *next; 
}Node;
Node *creat_list()
{
	Node *H,*p,*r;
	int x;
	p=H=(Node * )malloc(sizeof(Node));
	printf("��������ֵ:\n");
	printf("����0ʱ������\n");
	scanf("%d",&x);
	while(x!=0)
	{
		r=(Node * )malloc(sizeof(Node));
		r->data=x;
		p->next=r;// β�巨�������� 
		p=r;
		scanf("%d",&x);
	}
	r->next=H;  //����ѭ������ 
	return r;
 } 
void print_list(Node *H)  //������� 
{
	Node *p;
	p=H->next->next;
	while(p!=H->next)   //�ж��Ƿ����ͷָ�� 
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
Node *merge(Node *L1,Node *L2)  //������������ 
{
	Node *p;
	p=L1->next;
	L1->next=L2->next->next;   //��l2������l1�� 
	L2->next=p;
	return L2;
}
main()
{
	Node *p1,*p2,*t;
	//p=(Node *)malloc(sizeof(Node));
	printf("����1Ϊ��\n");
	p1=creat_list();
	print_list(p1);
	printf("����2Ϊ��\n");
	p2=creat_list();
	print_list(p2);
	t=merge(p1,p2);
	print_list(t);
	return 0;
}
 
