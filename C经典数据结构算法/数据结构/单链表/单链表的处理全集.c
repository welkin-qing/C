/*˭����Ȥһ�����ḻ�������ĵĹ��ܣ���*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define ELEMTP int

#define v (*p)

struct node
{
	ELEMTP data;
	struct node *next;
};

struct node *p,*q,*s,*head;
int j=0,i,k;
main()
{
	int x,y,cord;
	void outlin(struct node *h);
	void create();
	void insert(struct node *h,int x,int y);
	void deletes(struct node *h,int x);
	struct node *MaxCompare(struct node *h);
	struct node *MinCompare(struct node *h);
	int delIterance(struct node *h);
	void batchInsert(struct node *h,int x);
	void batchDelete(struct node *h,int x,int y);
	void Cz(struct node*  h);
	void Xg(struct node * h);
	printf("������������-999�������: \n");
	create();
	i=j;
	outlin(head);
	do{
		printf("\n        ���˵�        \n");
		printf("     1   ����һ��Ԫ��   \n");
		printf("     2   ɾ��һ��Ԫ��   \n");
		printf("     3   ��������       \n");
		printf("     4   ��������       \n");
		printf("     5   ����Ԫ��       \n");
		printf("     6   �޸�Ԫ��       \n");
		printf("     7   ɾ���ظ�Ԫ��   \n");
		printf("     8   ��������Ԫ��   \n");
		printf("     9   ����ɾ��Ԫ��   \n");
		printf("     0   ������������   \n");
		printf("-----------------------------------------\n");
		printf(" ����������ѡ��(1, 2, 3, 4, 5, 6, 7, 8, 9, 0) ");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
			{
				printf("����������λ�� i: ");
				scanf("%d",&x);
				printf("�������������� y: ");
				scanf("%d",&y);
				insert(head,x,y);
				i=j;
				outlin(head);
			}break;
			case 2:
			{
				printf("x=?");
				scanf("%d",&x);
				deletes(head,x);
				i=j;
				outlin(head);
			}break;
			case 3:
			{
				printf("�����ɴ�С��");
				s=MaxCompare(head);
				j=i;
				outlin(s);
				//outlin(head);
			}break;
			case 4:
			{
				printf("�����ɴ�С��");
				s=MinCompare(head);
				j=i;
				outlin(s);
			}break;
			case 5:
			{
				Cz(head);
				outlin(head);
			}break;
			case 6:
			{
				Xg(head);
				outlin(head);
			}break;
			case 7:
			{
				k=delIterance(head);
				i=i-k;
				j=i;
				outlin(head);
			}break;
			case 8:
			{
				printf("����������λ�� i: ");
				scanf("%d",&x);
				batchInsert(head,x);
				i=j;
				outlin(head);
			}break;
			case 9:
			{
				printf("������ɾ������ʼλ�� i: ");
				scanf("%d",&x);
				printf("������ɾ���Ľ���λ�� y: ");
				scanf("%d",&y);
				batchDelete(head,x,y);
				i=j;
				outlin(head);
			}break;
			case 0:
			{
				exit(0);
			}break;
		}
	}while(cord<=9&&cord>=0);
}

void outlin(struct node *h)
{
	p=h->next;
	while(p!=NULL)
	{
		printf(" data=%4d ",p->data);
		p=p->next;
	}
	printf("\n�������\n\n");
}

void deletes(struct node *h,int x)//ɾ���ڵ�
{
	p=h;
	while(p->next!=NULL&&p->next->data!=x)		p=p->next;
	if(p->next==NULL)
		printf("x ������ !");
	else
	{
		q=p->next;
		p->next=q->next;
		free(q);
		--j;
	}

}

void insert(struct node *h,int x,int y)
{
	s=(struct node*)malloc(sizeof(struct node));
	s->data=y;
	q=h;p=h->next;
	while(p!=NULL&&p->data!=x)
	{
		q=p;
		p=p->next;
	}
	q->next=s;
	s->next=p;
	++j;
}

void create()//��������
{
	int x;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	p=head;
	printf("x=?");
	scanf("%d",&x);
	while(x!=-999)
	{
		s=(struct node*)malloc(sizeof(struct node));
		s->data=x;
		s->next=NULL;
		p->next=s;
		p=s;
		printf("x=?");++j;
		scanf("%d",&x);
	}
}

/////////////���º������߾���ұ�д/////////////

struct node *MaxCompare(struct node *h)//�ɴ�С����
{        
	struct node *t;
	int x;
	t=h;s=NULL;
	while(j!=0)
	{
	x=t->next->data;
	q=t->next;
	while(q!=NULL)
	{
		if(q->data<=x)
			x=q->data;
		else
			x=x;
		q=q->next;	
	}
	p=t;
	while(p->next!=NULL&&p->next->data!=x)
		p=p->next;
	q=p->next;
	p->next=q->next;
	t=p;t=h;
	p=q;p->next=s;
	s=p;
	j--;
	}
	t->next=s;
	head=t;
	return (t);
}

struct node *MinCompare(struct node *h)//��С��������
{
	struct node *t;
	int x;
	t=h;s=NULL;
	while(j!=0)
	{
	x=t->next->data;
	q=t->next;
	while(q!=NULL)
	{
		if(q->data>=x)
			x=q->data;
		else
			x=x;
		q=q->next;	
	}
	p=t;
	while(p->next!=NULL&&p->next->data!=x)
		p=p->next;
	q=p->next;
	p->next=q->next;
	t=p;t=h;
	p=q;p->next=s;
	s=p;
	j--;
	}
	t->next=s;
	head=t;
	return (t);
}

int delIterance(struct node *h)//ɾ���ظ�Ԫ��
{
	int x,y=0;
	--j;
	s=h->next;
	while(j>0)
	{	
		x=s->data;
		p=s;
		while(p->next!=NULL)
		{
			if(p->next==NULL)
			{
				x=x;
			}
			else if(p->next->data==x)
			{
				q=p->next;
				p->next=q->next;
				free(q);
				--j;
				++y;
			}
			else
			{
				p=p->next;
			}
		}
		s=s->next;
		--j;
	}
	return y;
}

void batchInsert(struct node *h,int x)//��������
{
	int y=0;
	q=h;p=h->next;
	while(p!=NULL&&p->data!=x)
	{
		q=p;
		p=p->next;
	}
	printf("y=?");
	scanf("%d",&y);
	while(y!=-999)
	{
	s=(struct node*)malloc(sizeof(struct node));
	s->data=y;
	q->next=s;
	s->next=p;
	q=s;
	printf("y=?");
	scanf("%d",&y);
	++j;
	}
}

void batchDelete(struct node *h,int x,int y)//����ɾ��
{
	int k=0,w=0;
	struct node *t;
	p=h;q=h;
	while(p->next!=NULL&&p->next->data!=x)
	{
		++k;
		p=p->next;
	}
	while(q->next!=NULL&&q->next->data!=y)
	{
		++w;
		q=q->next;
	}
	if(p->next==NULL||q->next==NULL)
		printf("�����λ�ò���ȷ�������¿�ʼ��");
	else if(k<w)
	{
		s=q->next;
		while(p->next!=s)
		{
			t=p->next;
			p->next=t->next;
			free(t);
			--j;
		}

	}
	else if(w=k)
	{
		printf("û��ɾ��Ԫ��");
	}
	else
	{
		s=p->next;
		while(q->next!=s)
		{
			t=q->next;
			q->next=t->next;
			free(t);
			--j;
		}
	}
}

//////////////�߾���ұ�д����//////////////

//////////////���º�����lihk��д////////////
void Cz(struct node*  h)            //����// 
{
	struct node * num;int i; 
	num=head ; 
	printf("������Ҫ���ҵĺ���:"); 
	scanf("%d",&i); 
	while(i!=num->data && num->next!=NULL) 
	{   
		num=num->next; 
	} 
	if (i==num->data) 
 		printf("����:%d",num->data); 
	else 
 		printf("�ú��벻��������."); 
} 

void Xg(struct node * h) //�޸�// 
{ 
	struct node * num; int i; 
	num=head; 
	printf("������Ҫ�޸ĵĺ���:"); 
	scanf("%d",&i); 
	while(i!=num->data&&num->next!=NULL){ 
		num=num->next;} 
	if (i==num->data)
	{ 
   		printf(":%d\n",num->data); 
   		printf("������Ҫ�޸ĵ�����Ϣ:"); 
		printf("����:"); 
   		scanf("%d",&num->data); 
   		printf("\n�޸ĳɹ�!");
   	} 
	else 	
   		printf("�ú��벻��������!");  
} 

//////////////lihk��д����/////////////////