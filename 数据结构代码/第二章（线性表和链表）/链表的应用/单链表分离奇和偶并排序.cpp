//��һ���������У���������ż���ֿ�����˳���ź� 
//�˴���������⣺�����Ƚ��������ٽ������� �ᵼ��������������һ��Ԫ�� 
#include<stdio.h>
#include<stdlib.h>
#define M 20
typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkList;
LinkList creat_LinkList()  //β�巨������ͷ�������� 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));
	//H=NULL;
	LNode *s,*r=H;
	int x;
	scanf("%d",&x);
	while(x!=-1)  //����-1ʱֹͣ
	{
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	 }
	 r->next=NULL;
	 return H; 
 } 
int Length_LinkList (LNode *H)   //��������� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		//p=p->next;
		printf("%5d",p->data);
		p=p->next;
		j++;  //��¼����ĳ��� 
	}
	printf("\n");
	printf("\t����%d������!\n",j);
}
void function(int a[M],int m)
{
	int i,j;
	int t;
	for(i=0;i<m;i++)
	{
		for(j=i;j<m+1;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<m;i++)
	 printf("%5d",a[i]);
	printf("\n");
}
void paixu(LNode *H,int m)  //���� 
{
	int t;
	int a[M];
	LNode *p=H->next;
	//LNode *p=H;
	for(int i=0;i<m;i++)
	{
		if(p!=NULL)
		{
			a[i]=p->data;
		}
		p=p->next;
	}
	for(int i=0;i<m;i++)
	  printf("%5d",a[i]);
	printf("\n");
   //return a;
   function(a,m);
}

//дһ���������������ǰ�벿�ַ�Ϊ��������벿�ַ�Ϊż�� 
void divide(LNode *H)
{
	//LNode *H1,*H2;
	LNode *p;
	int s1=0,s2=0;
	LinkList H1=(LinkList)malloc(sizeof(LNode));
	H1->next=NULL;
	LinkList H2=(LinkList)malloc(sizeof(LNode));
	H2->next=NULL;
	while(H->next)  //�������� 
	{
		if(H->next->data%2==0)
		{
			p=H->next;  //��ֵ����p����pָ��H->next 
			H->next=p->next;   
			p->next=H1->next;  //��ֵ����H1����H1ָ��p->next 
			H1->next=p;
			s1++;
		}
		else{
			p=H->next;
			H->next=p->next;
			p->next=H2->next;
			H2->next=p;
			s2++;
		}
	}
	Length_LinkList(H1);
	Length_LinkList(H2);
	paixu(H1,s1);
	paixu(H2,s2); 
}

main()
{
	LNode *p=NULL;
	printf("���������ݣ�����-1ʱֹͣ��\n");
	p=creat_LinkList();
	printf("\t\t\t-----���������Ϊ��-----\n");
	Length_LinkList(p);
	divide(p);
 } 
