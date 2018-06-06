#include<stdio.h>
#include<stdlib.h>
struct student{
	long num;
	char name[10];
	struct student *next;
};
struct student *create()  /*����һ������ͷ��������*/
{
	struct student *head,*p,*q;
	int i=0;  //���������õı���
	int m;   //ѡ���Ƿ�����õı��� 
	head=(struct student *)malloc(sizeof(struct student));  //����һ��ͷ���
	head->next=NULL;
	p=head;
	do{
		q=(struct student *)malloc(sizeof(struct student));
		printf("\t��%d��:\n",++i);
		printf("num:");
		fflush(stdin);
		scanf("%d",&q->num);
		printf("name:");
		fflush(stdin);
		scanf("%s",q->name);
		p->next=q;
		p=q;
		printf("\t0-����or 1-����\n");
		scanf("%d",&m);
	} while(m==0);
	p->next=NULL;
	return head;
}
save(struct student *head)  //�������浽�ļ��� 
{
	struct student *p;
	FILE *fp;
	char filename[20];
	printf("\t������Ҫ������ļ���:");
	scanf("%s",filename);
	if((fp=fopen(filename,"wt"))==NULL)
	{
		printf("д���ļ�����!\n");
		return 0;
	}
	for(p=head->next;p!=NULL;p=p->next)
	fprintf(fp,"%d %s\n",p->num,p->name);
	printf("�ļ��ѱ��棡\n");
	//return head;
	fclose(fp);
	return 0;
}
struct student *read()  //���ļ����������� 
{
	struct student *head,*p,*q;
	FILE *fp;
	char filename[20];
	printf("������Ҫ�򿪵��ļ�:");
	scanf("%s",filename);
	if((fp=fopen(filename,"rt"))==NULL)
	{
		printf("�ļ�����");
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
	 printf("\t�ļ���ȡ��ȷ!\n");
	 return head;
}
print(struct student *head)  //������� 
{
	struct student *p;
	printf("��ϢΪ:\n");
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
	printf("�����������Ϣ:\n");
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
	 printf("��������Ҫ��ӵ��ļ���:");
	 fflush(stdin);
	 scanf("%s",&filename);
	 if((fp=fopen(filename,"a+"))==NULL)
	 {
	 	printf("�ļ�����!\n");
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
	printf("������Ҫɾ��ѧ����ѧ��:\n");
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
	printf("������Ҫ��ӵ�����:");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
	    addto(head);
	    head=read();	
	}
	print(head);
	delete(head);
}
