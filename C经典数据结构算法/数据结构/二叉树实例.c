#include<stdio.h>
#include<stdlib.h>
#define ELEMTP int

struct node
{
	ELEMTP data;
	struct node *lc,*rc;
};

struct node *root;
int m=0;

main()
{
	int cord;
	struct node* creat();
	void preorderz(struct node *t);
	void inorder(struct node *t);
	void postorder(struct node *t);
	void deletes(struct node *t,struct node *p,struct node *f);
	do
	{
		printf("\n         ���˵�                   \n");
		printf("      1    ����������               \n");
		printf("      2    ����ǵݹ����           \n");
		printf("      3    ����ݹ����             \n");
		printf("      4    ����ݹ��������Ҷ�ڵ��� \n");
		printf("      5    ɾ���ڵ�                 \n");
		printf("      6    ������������             \n");
		printf("---------------------------------------\n");
		printf("����������ѡ��(1, 2, 3, 4, 5, 6)");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
				{
					root=creat();  // ����������
					printf("����������������ִ���꣬\n");
					printf("�뷵�����˵����ñ����㷨��֤�������ȷ��  \n");
				}break;
			case 2:
				{
					preorderz(root);
				}break;
			case 3:
				{
					inorder(root);
				}break;
			case 4:
				{
					postorder(root);
				}break;
			case 5:
				{
					//deletes(root)
				}
			case 6:
				{
					printf("����������ִ���꣬�ټ���\n");
					exit(0);
				}
		}
	}while(cord<=6);
}

struct node* creat()
{
	struct node *t,*q,*s[30];
	int i,j,x;
	printf("i,x=");
	scanf("%d%d",&i,&x);//i�ǰ�����������ţ�x�ڵ�Ӧ�е���ţ�x�ǽڵ������
	while((i!=0)&&(x!=0))
	{
		q=(struct node*)malloc(sizeof(struct node));
		q->data=x;
		q->lc=NULL;	q->rc=NULL;
		s[i]=q;
		if(i==1)
			t=q;    //t���������ڵ�
		else
		{
			j=i/2; //˫�׽ڵ�ı��
			if((i%2)==0)
				s[j]->lc=q;
			else
				s[j]->rc=q;
		}
		printf("i,x=");
		scanf("%d%d",&i,&x);
	}
	return(t);
}

/*void preorderz(struct node* p)//ǰ��ǵݹ��㷨
{
	struct node *q,*s[30]; //s����ջ
	int top,bools;
	q=p;top=0;  //ջ��ָ��
	bools=1;  //bools=1Ϊ��ֵ����ѭ����bools=0Ϊ��ʱջ�գ�����ѭ��
	do
	{
		while(q!=NULL)
		{
			printf("%6d",q->data);     //���ʽڵ�
			top++;
			s[top]=q;
			q=q->lc;
		}
		if(top==0)
			bools=0;
		else
		{
			q=s[top];
			top--;
			q=q->rc;
		}
	}while(bools);
	printf("\n");
}//////////////////////////����preorderz*/

void preorderz(struct node* p)//ǰ��ݹ����
{
	if(p!=NULL)
	{
		printf("%6d",p->data);
		inorder(p->lc);
		inorder(p->rc);
	}
}

void inorder(struct node* p)//����ǵݹ����
{
	struct node *s[30],*q;
	int top,bools;
	q=p;top=0;
	bools=1;
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			q=q->lc;
		}
		if(top==0)
			bools=0;
		else
		{
			q=s[top];
			top--;
			printf("%6d",q->data);
			q=q->rc;
		}	
	}while(bools);
}

/*void inorder(struct node* p)
{
	if(p!=NULL)
	{
		inorder(p->lc);
		printf("%6d",p->data);
		inorder(p->rc);
	}
}//////////////////////////����inorder*/

void postorder(struct node* p)
{
	struct node *s[30],*s2[30],*q;
	int top,bools;
	q=p;top=0;
	bools=1;
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			s2[top]=1;
			q=q->lc;
		}
		if(top==0)
			bools=0;
		else
		{
			if(s2[top]==1)
			{
					s2[top]=2;
					q=s[top];
					q=q->rc;
				}
			else
			{
				q=s[top];
				s2[top]=0;
				top--;
				printf("%6d",q->data);
				q=NULL;
			}
		}
	}while(bools);
}

void deletes(struct node *t,struct node *p,struct node *f)
{
	struct node *s,*q;
	int bools=1;
	if(p->lc==NULL)
		s=p->rc;
	else if(p->rc==NULL)
	{
		s=p->rc;
		while(s->lc!=NULL)
		{
			q=s;
			s=s->rc;
		}
		if(q==p)
			q->rc=s->rc;
		else
			q->lc=s->rc;
		p->data=s->data;
		free(s);
		bools=0;
	}
	if(bools==1)
	{
		if(f==NULL)
			t=s;
		else if(f->lc==p)
			f->lc=s;
		else
			f->rc=s;
		free(p);
	}
}

/*void postorder(struct node* p)
{
	if(p!=NULL)
	{
		postorder(p->lc);
		postorder(p->rc);
		printf("%6d",p->data);
		if(p->lc==NULL&&p->rc==NULL)
			m++;    //ͳ��Ҷ�ӽڵ�
	}
}//////////////////////////����postorder*/