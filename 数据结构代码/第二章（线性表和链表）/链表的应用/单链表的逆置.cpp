#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;  //ָ���� 
}LNode,*LinkList;
LinkList creat_Linklist()  //β�巨����һ������ 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));   //�����ڴ�ռ� 
	H->next=NULL;  //�ÿ�
	LNode *s,*r=H; //��ͷ��㸳��r 
	int x;
	printf("������Ҫ���е�����\n");
	printf("����Ϊ-1��ʱ��ֹͣ\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LinkList)malloc(sizeof(LNode)); 
		s->data=x;//��ֵ
		s->next=r->next;//�ƶ�
		r->next=s;
		r=s;
		scanf("%d",&x); 
	 } 
	return H;
 } 
int Length_LinkList (LNode *H)   //��������� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		//p=p->next;
		printf("%d\t",p->data);
		p=p->next;
		j++;  //��¼����ĳ��� 
	}
	printf("\n");
	printf("����%d������!\n",j);
}
void reveres(LinkList H)
{
	LNode *p,*q;
	p=H->next;
	H->next=NULL;
	while(p)
	{
		q=p;  //��ֵ����q���ݴ�
		p=p->next;  //p����Ѱ����һ��Ԫ��
		q->next=H->next;     //����ǰ������ͷ���ĺ��棨�����������ǣ�
		H->next=q; 
	}
} 
main()
{
	LNode *p=NULL;
	p=creat_Linklist();
	printf("\t���������Ϊ��\n");
	Length_LinkList(p);
	printf("\n\t����û��������Ϊ��\n");
	reveres(p);
	Length_LinkList(p);
 } 
