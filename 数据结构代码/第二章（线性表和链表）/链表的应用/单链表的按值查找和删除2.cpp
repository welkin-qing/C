//单链表的按值查找 
//参考代码 
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
		printf("%d\t",p->data);
		p=p->next;
		j++;  //记录链表的长度 
	}
	printf("\n");
	printf("\t共有%d个数据!\n",j);
}
/*LinkList Locate_LinkList(LinkList H, int x)   //按值查找节点所在的位置 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		p=p->next;
		j++;
		if(p->data==x) 
		{
			printf("\t节点所在的位置是第%d位\n",j+1);  break;
		} 
		//else return NULL;
		
	}
	
}
LinkList Get_LinkList(LinkList H,int x)   //按序号查找 
{
	LNode *p=H;
	int a=0;
	while(p!=NULL)
	{
		p=p->next;
		a++;
		if(a==x)
		{
			printf("\t值是%d\n",p->data);  
		}
		else return NULL;
	}
}*/
int Del_LinkList(LinkList H,int i)   //删除单链表上的第i个节点 
{
	
}
void Locate_LinkList(LinkList H, int x)   //按值查找节点所在的位置 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;	
	}
	if(p!=NULL&&p->data==x) printf("\t为第%d个节点\n",j+1);
	else printf("Not found\n");
	
}
void Get_LinkList(LinkList H,int x)   //按序号查找 
{
	LNode *p=H;
	int a=0;
	while(p!=NULL&&a!=x)
	{
		p=p->next;
		a++;
	}
	if(p!=NULL&&a==x) printf("\t值为%d",p->data);
	else printf("Not found\n");
}


main()
{
	int m,n;
	LNode *p=NULL;
	p=creat_Linklist();
	printf("\t输出该链表为：\n");
	Length_LinkList(p);
	printf("请输入要查找的值:\n");
    scanf("%d",&m);
	Locate_LinkList(p,m);
	printf("请输入要查找的序号：\n");
	scanf("%d",&n);
	Get_LinkList(p,n);
 }
