//单链表的按值查找和删除 (perfect)
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;  //指针域 
}LNode,*LinkList;
LinkList creat_Linklist()  //尾插法建立一个链表 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));   //申请内存空间 
	H->next=NULL;  //置空
	LNode *s,*r=H; //将头结点赋给r 
	int x;
	printf("请输入要排列的数：\n");
	printf("当数为-1的时候停止\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LinkList)malloc(sizeof(LNode)); 
		s->data=x;//赋值
		s->next=r->next;//移动
		r->next=s;
		r=s;
		scanf("%d",&x); 
	 } 
	return H;
 }
 int Length_LinkList (LNode *H)   //输出该链表 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		//p=p->next;
		printf("\t%d\t\t",p->data);
		p=p->next;
		j++;  //记录链表的长度 
	}
	printf("\n");
	printf("\t共有%d个数据!\n",j);
}
LinkList Locate_LinkList(LinkList H, int x)   //按值查找节点所在的位置 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;
		
	}
	if(p!=NULL&&p->data==x) 
	{
	    printf("\t节点所在的位置是第%d位\n",j+1);  
	} 
	else printf("\t没有找到!\n");
	
}
LinkList Get_LinkList(LinkList H,int x)   //按序号查找 
{
	LNode *p=H;
	int a=0;
	while(p!=NULL&&a!=x)
	{
		p=p->next;
		a++;
	}
	if(p!=NULL&&a==x)
	{
	    printf("\t值是%d\n",p->data);  
	}
	else printf("\t没有找到!\n");
}
/*void Del_LinkList1(LinkList H,int j)   //按节点序号删除 
{
	int i;
	LNode *p;
	LNode *q;
	p=H;
	q=p;
	
	for(i=0;i<j;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
	
}*/
void Del_LinkList1(LinkList H,int x)   //按节点序号删除 （完善） 
{
	LNode *p=H;
	LNode *q; 
	int a=0;
	//q=p;
	while(p!=NULL&&a!=x)
	{
		p=p->next;
		a++;
	}
	if(p!=NULL&&a==x)
	{
	    printf("\t找到了!\n");  
	}
	else 
	{
		printf("\t没有找到!\n"); 
		//syetem("pause");
	    getchar();
	}
	p=H;
	q=p;
	for(int i=0;i<x;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
}
void Del_LinkList2(LinkList H,int x)   //按值删除
{
	LNode *p=H->next;
	LNode *q;
	int j=0;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;
		
	}
	if(p!=NULL&&p->data==x) 
	{
	    printf("\t找到了!\n");   
	} 
	else 
	{
		printf("\t没有找到!\n"); 
	    getchar();
	}
	p=H;
	q=p;
	for(int i=0;i<j+1;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
} 
main()
{
	int m,n,k,b;
	LNode *p=NULL;
	p=creat_Linklist();
	printf("\t\t\t-----输出该链表为：-----\n");
	Length_LinkList(p);
	
	printf("\t\t\t-----请输入要查找的值:-----\n");
    scanf("%d",&m);
	Locate_LinkList(p,m);
	//Length_LinkList(p);
	
	printf("\t\t\t-----请输入要查找的序号：-----\n");
	scanf("%d",&n);
	Get_LinkList(p,n);
	//Length_LinkList(p);
	
	printf("\t\t\t-----请输入要删除的节点:-----\n");
	scanf("%d",&k);
	Del_LinkList1(p,k);
	Length_LinkList(p);
	
	printf("\t\t\t-----请输入要删除的值:-----\n");
	scanf("%d",&b);
	Del_LinkList2(p,b);
	Length_LinkList(p);
 }
