#include<stdio.h>
#include<stdlib.h>
struct student{   /*�����ڵ�ṹ*/ 
	long num;
	char name[10];
	char sex;
	long age;
	struct student *next;
}; 
int icount;   /*�����ڵ�*/
struct student *create()  /* ������Ϣ�ĺ���*/ 
{
	struct student *phead=NULL; /*��ʼ������*/
	struct student *pend,*pnew;
	icount=0;   /*��ʼ��������,��ʾ�ڵ�����*/ 
    pend=pnew=(struct student*)malloc(sizeof(struct student));  /*�����ڴ����*/
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
	while(pnew->num!=0)  /*�ж�ѧ���Ƿ�Ϊ0���Ա���0����������Ľ����������ж�������Ϣ�Ƿ����Ҫ��*/
	{
		icount++;
		if(icount==1)  /*ֻ��һ���ڵ��ʱ��*/
		{
			pnew->next=phead;  
			pend=pnew;   
			phead=pnew; 
		}
		else   /*���ڵ����1ʱ���ڵ������*/
		{
			pnew->next=NULL;
			pend->next=pnew;
			pend=pnew;
		}
		pend=pnew=(struct student*)malloc(sizeof(struct student));  /*�����ڴ����*/
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
	free(pnew);   /*�ͷŽڵ�ռ�*/
	return phead;	 
}
void print(struct student *phead)  /*��������*/
{
	struct student *ptemp;  /*ѭ�����õ���ʱָ��*/
	int identx=1;    /*��ʾѧ���ĸ���*/
	printf("����%d��ѧ��\n",icount);
	ptemp=phead;
	while(ptemp!=NULL)
	{
		printf("��%d��ѧ��\n",identx);
		printf("\t%5d\t%10s\t%c\t%5d\n",ptemp->num,ptemp->name,ptemp->sex,ptemp->age);
		ptemp=ptemp->next;    /*ָ����һ���ڵ�*/
		identx++;
	}
}	
main()
{
	struct student *phead;  /*����ͷ�ڵ�*/ 
	phead=create();   /*�����ڵ�*/
	print(phead);  /*�������*/ 
}
