#include"stdio.h"
#include"malloc.h"
typedef struct node
{
    int num; 
	struct node *next;
}Node,*Linklist;  
int n;
Linklist CreatFromHead()  
{
     Node *pNew,*pEnd;
     Linklist pHead;
     pHead=pEnd=(Node *)malloc(sizeof(Node));
     pEnd->next=NULL;
     pEnd->num=1; 
     for(int i=2;i<=n;i++)
     {
  	 	 pNew=(Node *)malloc(sizeof(Node));
         pNew->num=i;
         pEnd->next=pNew;
         pEnd=pNew;
  }
     pEnd->next=pHead;
     return pHead;
     

}
int Josephus(int s[],int k)
{
	Linklist L;
	int a[10];
	int i,flage=1,flage0=1; 
	Node *p,*c,*d;
	for(int m=1;m<=n;m++)
	{
		int x=1;
		L=CreatFromHead();
		c=p=L;
		d=NULL;
		flage=1;
		flage0=1;
		while(p->next!=L)
			p=p->next;
		while(flage)
		{
			for(i=1;i<m;i++)
				{
					p=c;
					c=c->next;
				}	
			if(p==c)
	 		flage=0;
	 		d=c;
	 		p->next=c->next;
	 		c=c->next;
	 		a[x]=d->num;
	 		x++;
	 		free(d);	
		}
		for(int j=n,c=k-1;c>=0;j--,c--)
			{
				if(s[c]!=a[j])
		 			flage0=0;
			}	
		if(flage0==1)
			{
				printf("%d\n",m);
				return 0;
			}
	} 
}
 
int main()
{
	int k,o;
	int s[10];	
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		scanf("%d",&s[i]);
    Josephus(s,k);
    
}

