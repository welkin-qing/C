//求导求值 
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
	 	if(q->coef==0) q=q->next;
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
 }
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
}

polyn 	derivation_Polyn(polyn pa)  //求导 
{
	polyn 	ptemp=pa->next;
	
	polyn 	pc,t,s;
	pc=(Polynomial *)malloc(sizeof(Polynomial));
	pc->next=NULL;
	
	while(ptemp){
			s=(Polynomial *)malloc(sizeof(Polynomial));
			s->next=NULL;
			s->coef=ptemp->coef*ptemp->expn;
			s->expn=ptemp->expn-1;
			
			if(pc->next==NULL){
				pc->next=t=s;
			}
			else{
				t=t->next=s;
			}
		ptemp=ptemp->next;
	}
	return pc;
} 

void function(polyn p,int x)  //求值 
{
	int sum=0;
	polyn q;
	polyn H=p->next;
	for(p=H->next;p;p=p->next)
	{
		sum+=H->coef*pow(x,H->expn);
		H=H->next;
		//p=p->next;
	}
	sum=sum+H->coef*pow(x,H->expn); 
	printf("%d",sum);
}
 main()
 {
 	Polynomial *PA=NULL;
 	Polynomial *PB=NULL;
 	int m;
	Polynomial *PC=NULL;
	//printf("创建A\n"); 
 	PA=creatpoly();
 	printpolyn(PA);
 	//printf("创建B\n");
 	//PB=creatpoly();
 	//printpolyn(PB); 
 	//AddPolyn(PA,PB); // 多项式相加 
 	//printf("创建C\n");
 	//printpolyn(PC);
 	//printf("输入x的值:\n");
 	scanf("%d",&m);
 	function(PA,m);  //求值函数 
 	printf("求导有：\n");
 	PB=derivation_Polyn(PA);// 求导函数 
    printpolyn(PB);
 }
