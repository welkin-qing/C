//约瑟夫环第一题 acm 
/*
样例输入
7 20
3 1 7 2 4 8 4
样例输出
6 1 4 7 2 3 5
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct NodeType{
	int id;
	int password;
	struct NodeType *next;
}NodeType;
void creatlist(NodeType **H,int n)    
{
	int i=0;
	int password=0;
	NodeType *p=NULL;
	NodeType *q=NULL;
	for(i=1;i<=n;i++)
	{
		//printf("输入第%d个人的密码:",i);
		scanf("%d",&password);
		p=GetNode(i,password);
		if(*H==NULL)
		{
			*H=q=p;
			q->next=*H; 
		}
		else{
			p->next=q->next;
			q->next=p;
			q=p;
		} 
	}
}
int GetNode(int ID, int Password)   
{
	NodeType *p=NULL;
	p=(NodeType *)malloc(sizeof(NodeType));
	if(!p)
	{
		printf("错误!\n");
		exit(-1);
	}
	p->id=ID;
	p->password=Password;
	p->next=NULL;
	return p;
} 
int IsEmptyList(NodeType *H)
{
	if(!H)
	{
		printf("该链表为空!\n");
		return 1;
	}
	return 0;
}
void function(NodeType **H,int Password)
{
	int icount=0;
	int flag =1;
	NodeType *p=NULL;
	NodeType *q=NULL;
	NodeType *o=NULL;
	p=q=*H;
	while(p->next!=*H)
	    p=p->next;
	while(flag)
	{
		for(icount=1;icount<Password;icount++)
		{
			p=q;
			q=q->next;
		}
		if(p==q)        flag=0;
		o=q;
		p->next=q->next;
		q=q->next;
		Password=o->password;
		printf("%d ",o->id);
		free(o);
	}
	//*H=NULL;
	getchar();
}
void creatlist(NodeType **,int);
int GetNode(int, int);
void print(NodeType *);
int IsEmptyList(NodeType *);
void function(NodeType **,int);

int main()
{
	int n=0;
	int m=0;
	NodeType *H=NULL;
	scanf("%d %d",&n,&m);
	creatlist(&H,n);
	function(&H,m);
	return 1;
}  



