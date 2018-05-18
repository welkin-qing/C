//���� 
#include<stdio.h>
#include<stdlib.h>
typedef struct NodeType{
	int id;
	int password;
	struct NodeType *next;
}NodeType;
void creatlist(NodeType **H,int n)    //��������ѭ������ 
{
	int i=0;
	int password=0;
	NodeType *p=NULL;
	NodeType *q=NULL;
	for(i=1;i<=n;i++)
	{
		printf("�����%d���˵�����:",i);
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
int GetNode(int ID, int Password)   //�õ�һ���ڵ㣬��ڵ��д��ݱ�ź����� 
{
	NodeType *p=NULL;
	p=(NodeType *)malloc(sizeof(NodeType));
	if(!p)
	{
		printf("����!\n");
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
	if(!IsEmptyList(H))   //���ú��������ж�H�Ƿ�Ϊ�գ�Ϊ����ִ�� 
	{
		printf("----���---����---\n");
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
		printf("������Ϊ��!\n");
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
		printf("��%d���˳���!(����%d)\n",o->id,o->password);
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
			printf("����̫���С������������!\n");
		}
		printf("����������:");
		scanf("%d",&n);
	}while(n>100);
	printf("�������ʼ����:");
	scanf("%d",&m);
	creatlist(&H,n);
	printf("----------ѭ������-------\n");
	print(H);
	printf("----------�������-------\n");
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
List *creat()   //ѭ������Ľ����Ҵ���ͷ��� 
{
   List *head,*p1,*p2;
   int i;
   if((head=(List *)malloc(sizeof(List)))==NULL)
   {
	   printf("Error");
	   exit(0);
   }
   p1=p2=head;
   printf("���봴������ĳ��ȣ�");
   scanf("%d",&head->num);//�����б���ͷ��㣬ͷ����������ʾ����ĸ���
   if(head->num==0)
   {
	   head->next=NULL;
	   printf("�Ѵ�����ͷ���Ŀ�����"); 
   }
   else
   {
      printf("�������ݣ�\n");
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

int Init(List *p);   //��ʼ��˫����
int Insert(List *p,int key); //����ڵ�
void Print(List p); //��ӡ˫����
void CreateOsep(List p,int n); //��ʼ��Լɪ��
void osehup(List p,int m,int len,List Re); //����Լɪ�򻷳���˳�򣬲������Re������

int main()
{
 int m,n;
 List p,Re;

 Init(&p);
 Init(&Re);

 cout<<"���뻷��С:  ";
 cin>>n;
 cout<<"����ؼ����˳���: ";
 cin>>m;

 CreateOsep(p,n);
 cout<<"����Ϊ: "<<endl;
 Print(p);
 osehup(p,m,n,Re);
 cout<<"����˳��Ϊ:"<<endl;
 Print(Re);
 return 1;
}
//��ʼ��
int Init(List *p)
{
 *p = (List)malloc(sizeof(Link));
 if(!(*p))
 {
  cout<<"��ʼ��ʧ��!"<<endl;
  return 0;
 }
 else
 {
  (*p)->next=*p;
  //(*p)->sort=1;

 }
  return 1;
}
//����ڵ�
int Insert(List *p,int key)
{
 List tmp = (List)malloc(sizeof(Link));
 if(!tmp)
 {
  cout<<"�����ڵ�ʧ��!"<<endl;
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
//����Լɪ��
void CreateOsep(List p,int n)
{
 List tmp=p;
 tmp->sort=1;
 for(int i=2;i<=n;i++)
  Insert(&tmp,i);
}
//Լɪ���㷨
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
   if(allc==0)                //����ǵ�һ�γ���
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
//��ӡ����
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



