#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lh,*rh;
	int ltag,rtag;
}*pr,*t,*s[30];

struct node* creat()
{
	struct node *t,*q;
	int i,x,j;
	printf("i,x=");
	scanf("%d%d",&i,&x);
	while((i!=0)&&(x!=0))
	{
		q=(struct node *)malloc(sizeof(struct node));
		q->data=x;
		q->lh=NULL;
		q->rh=NULL;
		s[i ]=q;
		if(i==1)
			t=q;
		else
		{
			j=i/2;
			if((i%2)==0)
				s[j]->lh=q;
			else
				s[j]->rh=q;
		}
		printf("i,x=");
		scanf("%d%d",&i,&x);
	}
	return(t);
}

/*void inthread(struct node *p) //�ݹ��㷨
{
	if(p!=NULL)
	{
		inthread(p->lh);
		printf("%6d\t",p->data);
		if(p->lh!=NULL)
			p->ltag=0;
		else
		{
			p->ltag=1;
			p->lh=pr;
		} //����P�ڵ����������ָ��ǰ���ڵ�PR
		if(pr!=NULL)
		{
			if(pr->rh!=NULL)
				pr->rtag=0;
			else
			{
				pr->rtag=1;
				pr->rh=p;
			}//ǰ���ڵ�PR������������ָ��ڵ�P
		}
		pr=p;//pr����p,�Ա�p����ƶ�
		inthread(p->rh);
	}
}*/

void inthread(struct node *t)//�ǵݹ��㷨
{
	int top,bools;
	struct node *p;
	pr=NULL;p=t;top=0;bools=1;
	do{
		while(p!=NULL)
		{
			top++;
			s[top]=p;
			p=p->lh;
		}
		if(top==0)bools=0;
		else
		{
			p=s[top];
			top--;
			printf("%6d",p->data);
			if(p->lh!=NULL)
				p->ltag=0;
			else
			{
				p->ltag=1;
				p->lh=pr;
			} //����P�ڵ����������ָ��ǰ���ڵ�PR
			if(pr!=NULL)
			{
				if(pr->rh!=NULL)
					pr->rtag=0;
				else
				{
					pr->rtag=1;
					pr->rh=p;
				}//ǰ���ڵ�PR������������ָ��ڵ�P
			}
			pr=p;//pr����p,�Ա�p����ƶ�
			p=p->rh;
		}//END else
	}while(bools);
	pr->rh=NULL;
}

main()
{
	pr=NULL;
	t=creat();
	inthread(t);
	pr->rh=NULL;
}