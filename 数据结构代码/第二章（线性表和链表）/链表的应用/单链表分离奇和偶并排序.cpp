//在一无序单链表中，将奇数和偶数分开并按顺序排好 
//此代码存在问题：在于先进行区分再进行排序 会导致在少数组中少一个元素 
#include<stdio.h>
#include<stdlib.h>
#define M 20
typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkList;
LinkList creat_LinkList()  //尾插法建立无头结点的链表 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));
	//H=NULL;
	LNode *s,*r=H;
	int x;
	scanf("%d",&x);
	while(x!=-1)  //输入-1时停止
	{
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	 }
	 r->next=NULL;
	 return H; 
 } 
int Length_LinkList (LNode *H)   //输出该链表 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		//p=p->next;
		printf("%5d",p->data);
		p=p->next;
		j++;  //记录链表的长度 
	}
	printf("\n");
	printf("\t共有%d个数据!\n",j);
}
void function(int a[M],int m)
{
	int i,j;
	int t;
	for(i=0;i<m;i++)
	{
		for(j=i;j<m+1;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<m;i++)
	 printf("%5d",a[i]);
	printf("\n");
}
void paixu(LNode *H,int m)  //排序 
{
	int t;
	int a[M];
	LNode *p=H->next;
	//LNode *p=H;
	for(int i=0;i<m;i++)
	{
		if(p!=NULL)
		{
			a[i]=p->data;
		}
		p=p->next;
	}
	for(int i=0;i<m;i++)
	  printf("%5d",a[i]);
	printf("\n");
   //return a;
   function(a,m);
}

//写一个函数，将链表的前半部分分为奇数，后半部分分为偶数 
void divide(LNode *H)
{
	//LNode *H1,*H2;
	LNode *p;
	int s1=0,s2=0;
	LinkList H1=(LinkList)malloc(sizeof(LNode));
	H1->next=NULL;
	LinkList H2=(LinkList)malloc(sizeof(LNode));
	H2->next=NULL;
	while(H->next)  //遍历链表 
	{
		if(H->next->data%2==0)
		{
			p=H->next;  //将值赋给p，让p指向H->next 
			H->next=p->next;   
			p->next=H1->next;  //将值赋给H1，让H1指向p->next 
			H1->next=p;
			s1++;
		}
		else{
			p=H->next;
			H->next=p->next;
			p->next=H2->next;
			H2->next=p;
			s2++;
		}
	}
	Length_LinkList(H1);
	Length_LinkList(H2);
	paixu(H1,s1);
	paixu(H2,s2); 
}

main()
{
	LNode *p=NULL;
	printf("请输入数据，输入-1时停止！\n");
	p=creat_LinkList();
	printf("\t\t\t-----输出该链表为：-----\n");
	Length_LinkList(p);
	divide(p);
 } 
