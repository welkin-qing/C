#include<stdio.h>
#include<stdlib.h>
struct student{   /*创建节点结构*/ 
	long num;
	char name[10];
	char sex;
	long age;
	struct student *next;
}; 
int icount;   /*创建节点*/
struct student *create()  /* 输入信息的函数*/ 
{
	struct student *phead=NULL; /*初始化链表*/
	struct student *pend,*pnew;
	icount=0;   /*初始化链表长度,表示节点数量*/ 
    pend=pnew=(struct student*)malloc(sizeof(struct student));  /*进行内存分配*/
    	printf("num:\n");
	    scanf("%d",pnew->num);
	    fflush(stdin);
	    printf("name:\n");
	    scanf("%s",pnew->name);
	    fflush(stdin);
	    printf("sex:\n");
	    scanf("%c",pnew->sex);
	    fflush(stdin);
	    printf("age:\n");
	    scanf("%d",pnew->age);
	    fflush(stdin);
	while(pnew->num!=0)  /*判断学号是否为0，以便用0来结束链表的建立，并且判断输入信息是否符合要求*/
	{
		icount++;
		if(icount==1)  /*只有一个节点的时候*/
		{
			pnew->next=phead;  
			pend=pnew;   
			phead=pnew; 
		}
		else   /*当节点大于1时，节点的延伸*/
		{
			pnew->next=NULL;
			pend->next=pnew;
			pend=pnew;
		}
		pend=pnew=(struct student*)malloc(sizeof(struct student));  /*进行内存分配*/
    	printf("num:\n");
	    scanf("%d",pnew->num);
	    fflush(stdin);
	    printf("name:\n");
	    scanf("%s",pnew->name);
	    fflush(stdin);
	    printf("sex:\n");
	    scanf("%c",pnew->sex);
	    fflush(stdin);
	    printf("age:\n");
	    scanf("%d",pnew->age);
	    fflush(stdin);
	}
	free(pnew);   /*释放节点空间*/
	return phead;	 
}
void print(struct student *phead)  /*链表的输出*/
{
	struct student *ptemp;  /*循环所用的临时指针*/
	int identx=1;    /*表示学生的个数*/
	printf("共有%d个学生\n",icount);
	ptemp=phead;
	while(ptemp!=NULL)
	{
		printf("第%d个学生\n",identx);
		printf("\t%5d\t%10s\t%c\t%5d\n",ptemp->num,ptemp->name,ptemp->sex,ptemp->age);
		ptemp=ptemp->next;    /*指向下一个节点*/
		identx++;
	}
}	
main()
{
	struct student *phead;  /*定义头节点*/ 
	phead=create();   /*创建节点*/
	print(phead);  /*输出链表*/ 
}
