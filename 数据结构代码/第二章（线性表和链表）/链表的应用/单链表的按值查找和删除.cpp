//������İ�ֵ���Һ�ɾ�� (perfect)
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
		printf("\t%d\t\t",p->data);
		p=p->next;
		j++;  //��¼����ĳ��� 
	}
	printf("\n");
	printf("\t����%d������!\n",j);
}
LinkList Locate_LinkList(LinkList H, int x)   //��ֵ���ҽڵ����ڵ�λ�� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;
		
	}
	if(p!=NULL&&p->data==x) 
	{
	    printf("\t�ڵ����ڵ�λ���ǵ�%dλ\n",j+1);  
	} 
	else printf("\tû���ҵ�!\n");
	
}
LinkList Get_LinkList(LinkList H,int x)   //����Ų��� 
{
	LNode *p=H;
	int a=0;
	while(p!=NULL&&a!=x)
	{
		p=p->next;
		a++;
	}
	if(p!=NULL&&a==x)
	{
	    printf("\tֵ��%d\n",p->data);  
	}
	else printf("\tû���ҵ�!\n");
}
/*void Del_LinkList1(LinkList H,int j)   //���ڵ����ɾ�� 
{
	int i;
	LNode *p;
	LNode *q;
	p=H;
	q=p;
	
	for(i=0;i<j;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
	
}*/
void Del_LinkList1(LinkList H,int x)   //���ڵ����ɾ�� �����ƣ� 
{
	LNode *p=H;
	LNode *q; 
	int a=0;
	//q=p;
	while(p!=NULL&&a!=x)
	{
		p=p->next;
		a++;
	}
	if(p!=NULL&&a==x)
	{
	    printf("\t�ҵ���!\n");  
	}
	else 
	{
		printf("\tû���ҵ�!\n"); 
		//syetem("pause");
	    getchar();
	}
	p=H;
	q=p;
	for(int i=0;i<x;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
}
void Del_LinkList2(LinkList H,int x)   //��ֵɾ��
{
	LNode *p=H->next;
	LNode *q;
	int j=0;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;
		
	}
	if(p!=NULL&&p->data==x) 
	{
	    printf("\t�ҵ���!\n");   
	} 
	else 
	{
		printf("\tû���ҵ�!\n"); 
	    getchar();
	}
	p=H;
	q=p;
	for(int i=0;i<j+1;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
} 
main()
{
	int m,n,k,b;
	LNode *p=NULL;
	p=creat_Linklist();
	printf("\t\t\t-----���������Ϊ��-----\n");
	Length_LinkList(p);
	
	printf("\t\t\t-----������Ҫ���ҵ�ֵ:-----\n");
    scanf("%d",&m);
	Locate_LinkList(p,m);
	//Length_LinkList(p);
	
	printf("\t\t\t-----������Ҫ���ҵ���ţ�-----\n");
	scanf("%d",&n);
	Get_LinkList(p,n);
	//Length_LinkList(p);
	
	printf("\t\t\t-----������Ҫɾ���Ľڵ�:-----\n");
	scanf("%d",&k);
	Del_LinkList1(p,k);
	Length_LinkList(p);
	
	printf("\t\t\t-----������Ҫɾ����ֵ:-----\n");
	scanf("%d",&b);
	Del_LinkList2(p,b);
	Length_LinkList(p);
 }
