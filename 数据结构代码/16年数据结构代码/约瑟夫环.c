//样本 
#include<stdio.h>
#include<stdlib.h>
typedef struct NodeType{
	int id;
	int password;
	struct NodeType *next;
}NodeType;
void creatlist(NodeType **H,int n)    //创建单向循环链表 
{
	int i=0;
	int password=0;
	NodeType *p=NULL;
	NodeType *q=NULL;
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个人的密码:",i);
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
int GetNode(int ID, int Password)   //得到一个节点，向节点中传递编号和密码 
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
void print(NodeType *H)
{
	NodeType *p=H;
	if(!IsEmptyList(H))   //调用函数进行判断H是否为空，为空则执行 
	{
		printf("----序号---密码---\n");
		do{
			printf("%7d%5d\n",p->id,p->password);
			p=p->next;
		}while(p!=H);
	}
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
		printf("第%d个人出列!(密码%d)\n",o->id,o->password);
		free(o);
	}
	*H=NULL;
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
	do{
		if(n>100)
		{
			printf("人数太多减小数字重新输入!\n");
		}
		printf("请输入人数:");
		scanf("%d",&n);
	}while(n>100);
	printf("请输入初始密码:");
	scanf("%d",&m);
	creatlist(&H,n);
	printf("----------循环链表-------\n");
	print(H);
	printf("----------出列情况-------\n");
	function(&H,m);
	return 1;
}  





/*#include <stdio.h> 
#include<malloc.h>
#include<stdlib.h>
typedef struct list
{
	int num;
	struct list *next;
}List;
int n=0;
List *creat()   //循环链表的建立且带有头结点 
{
   List *head,*p1,*p2;
   int i;
   if((head=(List *)malloc(sizeof(List)))==NULL)
   {
	   printf("Error");
	   exit(0);
   }
   p1=p2=head;
   printf("输入创建链表的长度：");
   scanf("%d",&head->num);//创建列表，带头结点，头结点数据域表示输入的个数
   if(head->num==0)
   {
	   head->next=NULL;
	   printf("已创建带头结点的空链表"); 
   }
   else
   {
      printf("输入数据：\n");
      for(i=0;i<head->num;i++)
	  {
	      if((p1=(List *)malloc(sizeof(List)))==NULL)
		  {
	         printf("Error");
	         exit(0);
		  }
          scanf("%d",&p1->num);
		  p2->next=p1;
		  p2=p1;
	  }
	  p1->next=head;
   }
    return(head);
}

void print(List *head)
{
   List *p;
   p=head->next;
   for(;p!=head;)
   {
	   printf("%d ",p->num);
	   p=p->next;
   }
   printf("\n");
}
int main()
{ 
	List *head;
    head=creat();
    print(head);
}
/*#include <stdio.h>
using namespace std;

typedef struct Node{
 int sort;
 struct Node *next;
}Link,*List;

int Init(List *p);   //初始化双链表
int Insert(List *p,int key); //插入节点
void Print(List p); //打印双链表
void CreateOsep(List p,int n); //初始化约瑟夫环
void osehup(List p,int m,int len,List Re); //计算约瑟夫环出列顺序，并存放在Re链表中

int main()
{
 int m,n;
 List p,Re;

 Init(&p);
 Init(&Re);

 cout<<"输入环大小:  ";
 cin>>n;
 cout<<"输入地几个人出列: ";
 cin>>m;

 CreateOsep(p,n);
 cout<<"输入为: "<<endl;
 Print(p);
 osehup(p,m,n,Re);
 cout<<"出队顺序为:"<<endl;
 Print(Re);
 return 1;
}
//初始化
int Init(List *p)
{
 *p = (List)malloc(sizeof(Link));
 if(!(*p))
 {
  cout<<"初始化失败!"<<endl;
  return 0;
 }
 else
 {
  (*p)->next=*p;
  //(*p)->sort=1;

 }
  return 1;
}
//插入节点
int Insert(List *p,int key)
{
 List tmp = (List)malloc(sizeof(Link));
 if(!tmp)
 {
  cout<<"创建节点失败!"<<endl;
  return 0;
 }
 else
 {
  tmp->sort=key;
  tmp->next=(*p)->next;
  (*p)->next=tmp;
  *p=tmp;
 }
 return 1;
}
//创建约瑟夫环
void CreateOsep(List p,int n)
{
 List tmp=p;
 tmp->sort=1;
 for(int i=2;i<=n;i++)
  Insert(&tmp,i);
}
//约瑟夫环算法
void osehup(List p,int m,int len,List Re)
{
 int count=0;
 int allc=0;
 List tmp1=p;
 List tmp2=Re;
 List temp;
 while(allc<len)
 {
  count++;
  if(count == m)
  {     
   temp = tmp1->next;
   if(allc==0)                //如果是第一次出列
    tmp2->sort=temp->sort;
   else
    Insert(&tmp2,temp->sort); 
   tmp1->next=tmp1->next->next;
  // cout<<temp->sort<<"  ";
   free(temp);
   temp=NULL;
   allc++;
   count=0;
  }
  else
  {
   tmp1=tmp1->next;
  }
 
  
 }
 cout<<endl;

}
//打印链表
void Print(List p)
{
 List tmp=p->next;
 cout<<p->sort<<"  ";
 while(tmp!=p)
 {
  cout<<tmp->sort<<"  ";
  tmp=tmp->next;
 
 }
 cout<<endl;
}*/



