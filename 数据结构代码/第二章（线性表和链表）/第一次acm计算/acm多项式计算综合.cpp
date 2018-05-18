#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
 }
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
	return pc;
	//printpolyn(pc);
}
polyn AddPolyn(polyn pa,polyn pb)  //多项式相加 
{
	//Polyn *pa,*pb;
	polyn H,pc,qc;
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
	//printpolyn(pd);
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
	Polynomial *PC=NULL;
	int m,n;
	printf(" 1-输出\n 2-相加\n 3-相减\n 4-相乘\n 5-求值\n 6-求导\n ");
	scanf("%d",&m);
	switch(m)
	{
		case 1://printf("创建A\n"); 
 	           PA=creatpoly();
               printpolyn(PA);  //输出   
			   break;
        case 2:PA=creatpoly();
			   PB=creatpoly();
			   PC=AddPolyn(PA,PB);  //相加
			   printpolyn(PC);
			   break;
		case 3:PA=creatpoly();
			   PB=creatpoly();
			   PC=SubtractPolyn(PA,PB);   //相减
			   printpolyn(PC);
			   break;
		case 4:PA=creatpoly();
			   PB=creatpoly();
			   PC=Product_Polyn(PA,PB);   //相乘
			   printpolyn(PC);
			   break;
		case 5:PA=creatpoly();  //求值 
			   scanf("%d",&n);
			   function(PA,n);
			   break;
		case 6:PA=creatpoly();     //求导 
			   PC=derivation_Polyn(PA);
			   printpolyn(PC); 
			   break;
	}
}
