#include<stdio.h>
#include<stdlib.h>
struct student{
	int age;
	struct student *next;  /*指向下一个节点*/
};
int icount;
struct student *create()  /*创建链表的函数*/
{
	struct student *phead=NULL; /*表头指针，一开始没有节点所以为null*/
//	struct student *pend=*phead;  /*表尾指针，一开始没有节点所以指向头部*/ 
	struct student *pnew;  /*创建节点时用的指针*/ 
	icount=0;
	pnew=(struct student*)malloc(sizeof(struct student));
	printf("age:\n");
	scanf("%d",&pnew->age);
	while(pnew->age!=0)
	{
		icount++;
		pnew->next=phead;   /*头插法*/ 
		phead=pnew;
		pnew=(struct student*)malloc(sizeof(struct student));
	    printf("age:\n");
	    scanf("%d",&pnew->age);
	}
	free(pnew);
	return phead;
}
void print(struct student *phead)
{
	struct student *ptept;
	printf("共%d个数据\n",icount);
	ptept=phead;
	while(ptept!=NULL)
	{
		printf("%5d\n",ptept->age);
		ptept=ptept->next;
	 } 
}
void delete(struct student *phead,int a)
{
	int i;
	struct student *p;
	struct student *p1;
	p=phead;
	p1=p;
	for(i=1;i<a;i++)
	{
		p1=p;
		p=p->next;
	}
	p1->next=p->next;
	free(p);
	icount--;
 } 
struct student *tianjia(struct student *phead,int num)
{
	struct student *p=phead,*p1;
	while(p&&p->age!=num)  p=p->next;
    printf("age:\n");
    p1=(struct student*)malloc(sizeof(struct student));
    scanf("%d",&p1->age);  /*添加新的数据为新输入的*/ 
    p1->next=p->next;
    p->next=p1;
    icount++;
    return phead;
}
main()
{
	struct student *phead;
	printf("输入0时结束：\n");
	phead=create();
	print(phead);
	printf("删除第二个元素：\n");
	delete(phead,2);
	print(phead);
	printf("在年龄为56后面添加：\n");
	phead=tianjia(phead,56);/*在56后边添加数据*/
	print(phead);
}
