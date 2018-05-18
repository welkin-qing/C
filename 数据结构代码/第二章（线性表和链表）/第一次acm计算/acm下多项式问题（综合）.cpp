/*
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
 	int e,i=0;
 	float c;
 	head = (node *)malloc(sizeof(node));
 	r = head;
 	scanf("(%f,%d)",&c,&e);
 	while(i!=m)
 	{
 		
 		s = (node *)malloc(sizeof(node));
 		s->coef = c;
 		s->expn = e;
 		r->next = s;
 		r = s;
 		scanf("(%f,%d)",&c,&e);
 		i++;
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
  	 printf("请输入多项式的项数:\n");
  	 scanf("%d",&d);
	 a=createpoly(d);
  	 printpoly(a);
} */
#include<stdio.h>
#include<stdlib.h>

typedef   struct  Polynomial
{
	int    coef;  //系数 
	int      expn;  //指数 
	struct   Polynomial    *next;;
}*polyn,Polynomial;
//创建多项式
polyn creatpoly()
{
	Polynomial *H,*rear,*s;
	int c,e;  //c作为系数 
	int m;
	int i=0;
	H=(Polynomial *)malloc(sizeof(Polynomial));
	rear=H;
//	printf("个数：");
	scanf("%d ",&m);
	scanf("(%d,%d) ",&c,&e);
	while(i<m)
	{
		s=(Polynomial *)malloc(sizeof(Polynomial));
		s->coef = c;
		s->expn = e;
		rear->next=s;
		rear = s;
		scanf("(%d,%d) ",&c,&e);
		i++;
	}
	rear->next=NULL;
	return H;
 } 
 void printpolyn(polyn P)  //输出 
 {
 	polyn q=P->next;
 	int flag=1;
 	if(!q)
 	{
 		putchar('0');
 		printf("\n");
 		return;
	 }
	 while(q)
	 {
	 	if(q->coef==0)  q=q->next; 
	 	if(q->coef>0&&flag!=1)  putchar('+');
	 	if(q->coef!=1&&q->coef!=-1)
	 	{
	 		printf("%d",q->coef);
	 		if(q->expn==1) putchar('X');
	 		else if(q->expn)  printf("X^%d",q->expn);
		 }
		 else
		 {
		 	if(q->coef==1)
		 	{
		 		if(!q->expn) putchar('1');
		 		else if(q->expn==1)  putchar('X');
		 		else printf("X^%d",q->expn);
			 }
			 if(q->coef==-1)
			 {
			 	if(!q->expn) printf("-1");
			 	else if(q->expn==1)  printf("-X");
			 	else printf("-X^%d",q->expn);
			 }
		 }
		 q=q->next;
		 flag++;
	 }
	 printf("\n");
 }/*
polyn AddPolyn(polyn pa,polyn pb)  //多项式相加 
{
	//Polyn *pa,*pb;
	Polynomial *H,*pc,*qc;
    polyn qa=pa->next;
	polyn qb=pb->next;
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
}*/

polyn	AddPolyn(polyn pa,polyn pb)  //相加 
{
	 polyn    qa=pa->next;
	 polyn    qb=pb->next;
	 polyn    dc,qc,pc;
	 pc=(Polynomial *)malloc(sizeof(Polynomial));
	 pc->next=NULL;
	 while(qa&&qb)
	 {
	 	 qc=(Polynomial *)malloc(sizeof(Polynomial));
		 if(qa->expn<qb->expn)
		 {
		 	qc->coef=qa->coef;
		 	qc->expn=qa->expn;
		 	qa=qa->next;
		 } 
		 else if(qa->expn>qb->expn) 
		 {
		 	qc->coef=qb->coef;
		 	qc->expn=qb->expn;
		 	qb=qb->next;
		 }
		 else
		 {
		 	qc->coef=qa->coef+qb->coef;
		 	qc->expn=qa->expn;
		 	qa=qa->next;
		 	qb=qb->next;
		 }	
		 qc->next=NULL;
		 if(qc->coef!=0)
		 {
		 	if(pc->next==NULL)
		    {
		     	 dc=pc->next=qc;
		    }
		 	else
		 	{
		 		dc=dc->next=qc;
		 	}
		 }
		 else
		 {
		 	free(qc);
		 }
	 }
	 if(qa)
	 {
	 	dc->next=qa;
	 }
	 else
	 {
	 	dc->next=qb;
	 }
	 return pc; 
//	printpolyn(pc);
}
polyn SubtractPolyn(polyn pa,polyn pb)  //相减 
{
	polyn h=pb;
	polyn p=pb->next;
	polyn pd;
	while(p)
	{
		p->coef*=-1;
		p=p->next;
	}
	pd=AddPolyn(pa,h);
	for(p=h->next;p;p=p->next)
	{
		p->coef*=-1;
	}
	return pd;
	printpolyn(pd);
}  
/*
polyn	Product_Polyn(polyn pa,polyn pb)  //相乘 
{
	polyn 	qa=pa->next;
	polyn	qb;
	polyn 	pc;
	polyn 	s;
	polyn 	t;
	polyn 	ptemp;
	
	pc=(Polynomial *)malloc(sizeof(Polynomial));
	pc->next=NULL;
	
	while(qa){
		qb=pb->next;
		while(qb){
			s=(Polynomial *)malloc(sizeof(Polynomial));
			s->next=NULL;
			s->coef=qa->coef*qb->coef;
			s->expn=qa->expn+qb->expn;
			
			if(pc->next==NULL){
				pc->next=t=s;
			}
			else{ 
				for(ptemp=pc;ptemp->next;ptemp=ptemp->next){
					if(s->expn==ptemp->next->expn){
					   break;
					}
				}
				if(ptemp->next){
					ptemp->next->coef+=s->coef;
					free(s);	
				}
				else{
					for(ptemp=pc;ptemp->next;ptemp=ptemp->next){
						if(s->expn<ptemp->next->expn){
					   		break;
						}
					}
					s->next=ptemp->next;
					ptemp->next=s;
				}
			}
			qb=qb->next;
		}
		qa=qa->next; 
	}
	//return pc;
	printpolyn(pc);
}
*/
main()
{
 	Polynomial *PA=NULL;
 	Polynomial *PB=NULL;
	Polynomial *PC=NULL;
//	printf("创建A\n"); 
 	PA=creatpoly();
 //	printpolyn(PA);
 //	printf("创建B\n");
 	PB=creatpoly();
 	//PC=Product_Polyn(PA,PB);
 //	printpolyn(PB);
    PC=SubtractPolyn(PA,PB);
 	//printf("输出C\n");
 	printpolyn(PC);
 }
