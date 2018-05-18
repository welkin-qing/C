#include<stdio.h>
#include<stdlib.h>
#define MALL (node*)malloc(sizeof(node))
typedef struct A
{
	int power,value;
	struct A *next;
}node;
node *head[2],*p,*p1,*out;
int outn=0;
void swap(node *p,node *p1)
{
	node *tp,t;
	t=*p;
	*p=*p1;
	*p1=t;
	tp=p->next;
	p->next=p1->next;
	p1->next=tp;
}
int main()
{
	head[0]=MALL;
	head[1]=MALL;
	int n[2],i,j,k;
	
	for(k=0;k<2;k++)
	{
		scanf("%d",&n[k]);
		getchar();
		p=head[k];
		for(j=0;j<n[k];j++)
		{
			scanf("(%d,%d)",&p->value,&p->power);
			if(p->value==0)
				continue;		//保证没有0项 
			p->next=MALL;
			p=p->next;
		}
	}
	node *op=out=MALL;
	p=head[0];
	for(i=0;i<n[0];i++)		//m
	{
		p1=head[1];
		for(j=0;j<n[1];j++)
		{
			
			op->power=p->power+p1->power;
			op->value=p->value*p1->value;
			//不可能出现0项
			op->next=MALL;
			op=op->next; 
			p1=p1->next;
			outn++;
		}
		p=p->next;
	}
	p=out;				//sort
	for(i=0;i<outn-1;i++)
	{
		p1=p->next;
		for(j=i+1;j<outn;j++)
		{
			if(p->power>p1->power)
			{
				swap(p,p1);
			}
			p1=p1->next;
		}
		p=p->next;
	}
	//合并同类项 
	p=out;
	for(i=0;i<outn-1;i++)
	{
		if(p->power==p->next->power)
		{
			p1=p->next->next;
			p->value+=p->next->value;
			free(p->next);
			p->next=p1;
			outn--;
		}
		else
			p=p->next;
	}
	//输出要预防出现0项 
	p=out;
	int flag=0;	//输出序列是否有项 
	for(i=0;i<outn;i++)
	{
		if(p->value==0)	//0项 
		{
			p=p->next;
			//continue;
		}
		//if(flag==0)	//不输出+号
		//{
			//;
		//}
		if(flag!=0)		//带+符号 
		{
			if(p->value>0)
				printf("+");
		}
		//输出系数	只输出数字不输出符号 
		if(p->value==1 || p->value==-1)
		{
			if(p->power==0)	//常数项才输出，其他一概不输出 
				printf("%d",p->value); 
		}
		else 
			printf("%d",p->value);
		//输出X和指数
		if(p->power==0)
			;
		else if(p->power==1)
		{
			printf("X");
		}
		else
		{
			printf("X^%d",p->power);
		}
		p=p->next;
		flag=1;
	}
	if(flag==0)
		printf("0");
}






