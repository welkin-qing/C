#include<stdio.h>
#include<stdlib.h>
typedef struct Polynomial
{
	float coef;  //ϵ��
	int expn;  //ָ��
	struct Polynomial *next; 
}Polyn,*Polynomial;
Polyn *Create_Poly()   //����ʽ�Ľ��� 
{
	Polyn *H,*p,*s;
	int c,e;
	H=(Polynomial *)malloc(sizeof(Polynomial));
	p=H;  //β�巨����
	printf("���������ʽ��ϵ����ָ����\n");
	printf("ϵ��Ϊ0ʱ����!\n");
	printf("������ϵ����\n");
	scanf("%d",&c);
	printf("������ָ��:\n");
	scanf("%d",&e);
	while(c!=0)
	{
		s=(Polynomial *)malloc(sizeof(Polynomial));
		s->coef=c;
		s->expn=e;
		p->next=s;
		p=s;
		printf("������ϵ����\n");
	    scanf("%d",&c);
    	printf("������ָ��:\n");
    	scanf("%d",&e);
	} 
	p->next=NULL;
	return  H; 
}
void print(Polyn *P)    //����ʽ����� 
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
Polyn *AddPolyn(Polyn *pa,Polyn *pb)  //����ʽ��� 
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
Polyn *SubtrsctPolyn(Polyn *pa,Polyn *pb)    //����ʽ��� 
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
	printf("����PA����ʽ!\n");
	pa=Create_Poly();
	printf("����ö���ʽΪ:\n");
	print(pa);
	printf("����PB����ʽ!\n");
	pb=Create_Poly();
	printf("����ö���ʽΪ:\n");
	print(pb);
	printf("0-���or1-���");
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
