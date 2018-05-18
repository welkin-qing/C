//acm 下多项式的建立和输出 
#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
	float coef;
	int expn;
	struct node *next;
}node;
 //建立多项式
node *createpoly(int m)
{
 	node *head,*s,*r;
 	int e;
 	float c;
 	head = (node *)malloc(sizeof(node));
 	r = head;
 	scanf("(%f,%d)",&c,&e);
 	while(c != 0)
 	{
 		s = (node *)malloc(sizeof(node));
 		s->coef = c;
 		s->expn = e;
 		r->next = s;
 		r = s;
 		scanf("(%f,%d)",&c,&e);
	 }
	 r->next = NULL;
	 return head;
} 
//输出多项式 
void printpoly(node *head)
{
	node *q=head->next;
	int flag=1;
	if(!q)
	{
		putchar('0');
		printf("\n");
		return ;
	}
	while(q)
	{
		if(q->coef>0&&flag!=1)
		putchar('+');
		if(q->coef!=1&&q->coef!=-1)
		{
			printf("%.0f",q->coef);
			if(q->expn ==1)
			putchar('X');
			else if(q->expn)
			printf("X^%d",q->expn);
		}
		else
		{
			if(q->coef==1)
			{
				if(!q->expn)
				{
					putchar('1');
				}
				else if(q->expn==1)
				putchar('X');
				else
				printf("X^%d",q->expn);
			}
			if(q->coef==-1)
			{
				if(!q->expn)
				{
					printf("-1");
				}
				else if(q->expn==1)
				printf("-X");
				else
				printf("-X^%d",q->expn);
			}		
		}
		q=q->next;
			flag++;
	}
	printf("\n");
}
int main()
{
  	 node *a;
  	 int d;
  	 a=(node *)malloc(sizeof(node));
  	 a->next=NULL;
  	 scanf("%d",&d);
  	 a=createpoly(d);
	 printpoly(a);
}
