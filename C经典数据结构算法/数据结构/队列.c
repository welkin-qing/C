#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define Q (*qe)

struct quenode 
{
	ElemType data;
	struct quenode *next;
}*p,*s,*h;

struct quefr
{
	struct quenode *front,*rear;
};

main()
{
	struct quefr *que;
	int x,cord;
	void Outlin(struct quefr qq);
	void creat(struct quefr *qe);
	void insert(struct quefr *p,ElemType x);
	ElemType deletes(struct quefr *qe);
	do
	{
		printf("\n");
		printf("           ���˵�           \n");
		printf("      1    �����������     \n");
		printf("      2    ���һ��Ԫ��     \n");
		printf("      3    ����һ��Ԫ��     \n");
		printf("      4    ������������     \n");
		printf("-------------------------------\n");
		printf("����������ѡ��(1, 2, 3, 4) ");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
				{
					que=(struct quefr *)malloc(sizeof(struct quefr));
					creat(que);
					Outlin(*que);
				}break;
			case 2:
				{
					printf("x=?");
					scanf("%d",&x);
					insert(que,x);
					Outlin(*que);
				}break;
			case 3:
				{
					printf("x=%d\n",deletes(que));
					Outlin(*que);
				}break;
			case 4:
				{
					exit (0);
				}
		}
	}while (cord<=4);
}

void Outlin(struct quefr qq)
{
	p=qq.front->next;      /*ָ���һ������Ԫ�ؽڵ� */
	while(p!=NULL)
	{
		printf("data=%d\n",p->data);
		p=p->next;
	}
	printf("\n outend \n");
}

void insert(struct quefr *qe,int x)/*���xֵ�Ľڵ�*/
{
	s=(struct quenode *)malloc(sizeof(struct quenode));
	s->data=x;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}

ElemType deletes(struct quefr *qe)
{
	ElemType x;
	if(Q.front==Q.rear)
	{
		printf("����Ϊ�ա� \n");
		x=0;
	}
	else
	{
		p=Q.front->next;
		Q.front->next=p->next;
		if(p->next==NULL)
			Q.rear=Q.front;
		x=p->data;
		free(p);
	}
	return(x);
}

void creat(struct quefr *qe)
{
	int i,n,x;
	printf("n= ");
	scanf("%d",&n);
	h=(struct quenode*)malloc(sizeof(struct quenode));
	h->next=NULL;
	Q.front=h;
	Q.rear=h;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		insert(qe,x);
	}
}