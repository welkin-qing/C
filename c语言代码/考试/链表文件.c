#include<stdio.h>
#include<stdlib.h>
struct student{
	long num;
	char name[10];
	struct student *next;
};
struct student *create()  /*创建一个带有头结点的链表*/
{
	struct student *head,*p,*q;
	int i=0;  //计算人数用的变量
	int m;   //选择是否继续用的变量 
	head=(struct student *)malloc(sizeof(struct student));  //创立一个头结点
	head->next=NULL;
	p=head;
	do{
		q=(struct student *)malloc(sizeof(struct student));
		printf("\t第%d人:\n",++i);
		printf("num:");
		fflush(stdin);
		scanf("%d",&q->num);
		printf("name:");
		fflush(stdin);
		scanf("%s",q->name);
		p->next=q;
		p=q;
		printf("\t0-继续or 1-不用\n");
		scanf("%d",&m);
	} while(m==0);
	p->next=NULL;
	return head;
}
save(struct student *head)  //将链表保存到文件里 
{
	struct student *p;
	FILE *fp;
	char filename[20];
	printf("\t请输入要保存的文件名:");
	scanf("%s",filename);
	if((fp=fopen(filename,"wt"))==NULL)
	{
		printf("写入文件错误!\n");
		return 0;
	}
	for(p=head->next;p!=NULL;p=p->next)
	fprintf(fp,"%d %s\n",p->num,p->name);
	printf("文件已保存！\n");
	//return head;
	fclose(fp);
	return 0;
}
struct student *read()  //将文件存入链表中 
{
	struct student *head,*p,*q;
	FILE *fp;
	char filename[20];
	printf("请输入要打开的文件:");
	scanf("%s",filename);
	if((fp=fopen(filename,"rt"))==NULL)
	{
		printf("文件出错！");
		return 0;
	}
	head=(struct student *)malloc(sizeof(struct student));
	head->next=NULL;
	p=head;
	while(!feof(fp))
	{
		q=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%d %s",&q->num,q->name);
		p->next=q;
		p=q; 
	 } 
	 p->next=NULL;
	 fclose(fp);
	 printf("\t文件读取正确!\n");
	 return head;
}
print(struct student *head)  //输出链表 
{
	struct student *p;
	printf("信息为:\n");
	for(p=head->next;p->next!=NULL;p=p->next)
	{
		printf("num:%10d  name:%10s\n",p->num,p->name);
	}	 
}
struct student *addto()
{
	struct student *head=NULL,*p,*q,*pnew;
	int i,j,m;
	char filename[20];
	FILE *fp;
	printf("请输入添加信息:\n");
	//scanf("%d",&j);
	q=(struct student *)malloc(sizeof(struct student));
	pnew=(struct student *)malloc(sizeof(struct student));
	//for(i=0;i<j;i++)
	//{
		printf("num:");
	    fflush(stdin);
    	scanf("%d",&pnew->num);
    	printf("name:");
    	fflush(stdin);
    	scanf("%s",pnew->name);
    	//printf("%d\t%s\n",pnew->num,pnew->name);
     	head=pnew;
    	head->next=NULL;
    	//q->next=head;
    //}
	 q->next=head;
	 printf("请输入你要添加的文件名:");
	 fflush(stdin);
	 scanf("%s",&filename);
	 if((fp=fopen(filename,"a+"))==NULL)
	 {
	 	printf("文件出错!\n");
	 	return 0;
	 }
	 fp=fopen(filename,"a+");
	 for(p=q->next;p!=NULL;p=p->next)
	 {
	 	fprintf(fp,"%d %s\n",p->num,p->name);
	 }
	 fclose(fp);
}
delete(struct student *head)
{
	long m;
	struct student *p;
	printf("请输入要删除学生的学号:\n");
	scanf("%d",&m);
	for(p=head->next;p->next!=NULL;p=p->next)
	{
		if(p->num!=m)
		printf("num:%10d  name:%10s\n",p->num,p->name);
	}	
}
void main()
{
	int m,i;
	struct student *head;
	head=create();
	save(head);
	head=read();
	print(head);
	printf("请输入要添加的人数:");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
	    addto(head);
	    head=read();	
	}
	print(head);
	delete(head);
}
