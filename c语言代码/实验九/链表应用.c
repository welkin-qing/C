#include<stdio.h>
#include<stdlib.h>
struct student{
	int age;
	struct student *next;  /*ָ����һ���ڵ�*/
};
int icount;
struct student *create()  /*��������ĺ���*/
{
	struct student *phead=NULL; /*��ͷָ�룬һ��ʼû�нڵ�����Ϊnull*/
//	struct student *pend=*phead;  /*��βָ�룬һ��ʼû�нڵ�����ָ��ͷ��*/ 
	struct student *pnew;  /*�����ڵ�ʱ�õ�ָ��*/ 
	icount=0;
	pnew=(struct student*)malloc(sizeof(struct student));
	printf("age:\n");
	scanf("%d",&pnew->age);
	while(pnew->age!=0)
	{
		icount++;
		pnew->next=phead;   /*ͷ�巨*/ 
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
	printf("��%d������\n",icount);
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
    scanf("%d",&p1->age);  /*����µ�����Ϊ�������*/ 
    p1->next=p->next;
    p->next=p1;
    icount++;
    return phead;
}
main()
{
	struct student *phead;
	printf("����0ʱ������\n");
	phead=create();
	print(phead);
	printf("ɾ���ڶ���Ԫ�أ�\n");
	delete(phead,2);
	print(phead);
	printf("������Ϊ56������ӣ�\n");
	phead=tianjia(phead,56);/*��56����������*/
	print(phead);
}
