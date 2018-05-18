#include<stdio.h>
#include<stdlib.h>
typedef struct Polynomial
{
	float coef;  //系数
	int expn;  //指数
	struct Polynomial *next; 
}Polyn,*Polynomial;
Polyn *Create_Poly()   //多项式的建立 
{
	Polyn *H,*p,*s;
	int c,e;
	H=(Polynomial *)malloc(sizeof(Polynomial));
	p=H;  //尾插法建立
	printf("请输入多项式的系数和指数：\n");
	printf("系数为0时结束!\n");
	printf("请输入系数：\n");
	scanf("%d",&c);
	printf("请输入指数:\n");
	scanf("%d",&e);
	while(c!=0)
	{
		s=(Polynomial *)malloc(sizeof(Polynomial));
		s->coef=c;
		s->expn=e;
		p->next=s;
		p=s;
		printf("请输入系数：\n");
	    scanf("%d",&c);
    	printf("请输入指数:\n");
    	scanf("%d",&e);
	} 
	p->next=NULL;
	return  H; 
}
void print(Polyn *P)    //多项式的输出 
{
	Polyn *q;
	q=P->next;
	int flag=1;
	printf("\t");
	if(!q)
	{
		putchar('0');
		printf("\n");
		return;
	}
	while(q)
	{
		if(q->coef>0&&flag!=1) putchar('+');
		if(q->coef>0&&flag!=-1)
		{
			printf("%g",q->coef);
			if(q->expn==1) putchar('X');
			else if(q->expn)  printf("X^%d",q->expn);
		}
		else
		{
			if(q->coef==1)
			{
				if(!q->expn) putchar('1');
				else if(q->expn==1) putchar('X');
				else printf("X^%d",q->expn);
			}
			if(q->coef==-1)
			{
				if(!q->expn) putchar('-1');
				else if(q->expn==1) putchar('-X');
				else printf("-X^%d",q->expn);
			}
		}
		q=q->next;
	    flag++;
	}
	printf("\n");
}
Polyn *AddPolyn(Polyn *pa,Polyn *pb)  //多项式相加 
{
	//Polyn *pa,*pb;
	Polyn *H,*pc,*qc;
    Polynomial qa=pa->next;
	Polynomial qb=pb->next;
	pc=(Polynomial *)malloc(sizeof(Polynomial));
	pc->next=NULL;
	H=pc;
	while(qa!=NULL&&qb!=NULL)
	{
		qc=(Polynomial *)malloc(sizeof(Polynomial));
		if(qa->expn < qb->expn)
		{
			qc->coef=qa->coef;
			qc->expn=qa->expn;
			qa=qa->next;
		}
		else if(qa->expn==qb->expn)
		{
			qc->coef=qa->coef+qb->coef;
			qc->expn=qa->expn;
			qa=qa->next;
			qb=qb->next;
		}
		else
		{
			qc->coef=qb->coef;
			qc->expn=qb->expn;
			qb=qb->next;
		}
		if(qc->coef!=0)
		{
			qc->next=pc->next;
			pc->next=qc;
			pc=qc; 
		}
		else free(qc);
	}
	while(qa!=NULL)
	{
		qc=(Polynomial *)malloc(sizeof(Polynomial));
		qc->coef=qa->coef;
		qc->expn=qa->expn;
		qa=qa->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	while(qb!=NULL)
	{
		qc=(Polynomial *)malloc(sizeof(Polynomial));
		qc->coef=qb->coef;
		qc->expn=qb->expn;
		qb=qb->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	return H;
}
Polyn *SubtrsctPolyn(Polyn *pa,Polyn *pb)    //多项式相减 
{
	Polyn *pd;
	Polynomial h=pb;
	Polynomial p=pb->next;
	//Polyn *pd;
	while(p)
	{
		p->coef*=-1;
		p=p->next;
	}
	pd=AddPolyn(pa,h);
	for(p=h->next;p;p=p->next)
	p->coef*=-1;
	return pd;
	//print(pd);
}
int main()
{
	int i,j;
	Polyn *pa=NULL;
	Polyn *pb=NULL;
	Polyn *pc=NULL;
	printf("建立PA多项式!\n");
	pa=Create_Poly();
	printf("输出该多项式为:\n");
	print(pa);
	printf("建立PB多项式!\n");
	pb=Create_Poly();
	printf("输出该多项式为:\n");
	print(pb);
	printf("0-相加or1-相减");
	scanf("%d",&i);
	if(i==0)
	{
		pc=AddPolyn(pa,pb);
		print(pc);
	}
	else if(i==1)
	{
		printf("pa-pb\n");
		pc=SubtrsctPolyn(pa,pb);
		print(pc);
	}
}
