//������İ�ֵ���� 
//�ο����� 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;  //ָ���� 
}LNode,*LinkList;
LinkList creat_Linklist()  //β�巨����һ������ 
{
	LinkList H=(LinkList)malloc(sizeof(LNode));   //�����ڴ�ռ� 
	H->next=NULL;  //�ÿ�
	LNode *s,*r=H; //��ͷ��㸳��r 
	int x;
	printf("������Ҫ���е�����\n");
	printf("����Ϊ-1��ʱ��ֹͣ\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LinkList)malloc(sizeof(LNode)); 
		s->data=x;//��ֵ
		s->next=r->next;//�ƶ�
		r->next=s;
		r=s;
		scanf("%d",&x); 
	 } 
	return H;
 }
 int Length_LinkList (LNode *H)   //��������� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		//p=p->next;
		printf("%d\t",p->data);
		p=p->next;
		j++;  //��¼����ĳ��� 
	}
	printf("\n");
	printf("\t����%d������!\n",j);
}
/*LinkList Locate_LinkList(LinkList H, int x)   //��ֵ���ҽڵ����ڵ�λ�� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL)
	{
		p=p->next;
		j++;
		if(p->data==x) 
		{
			printf("\t�ڵ����ڵ�λ���ǵ�%dλ\n",j+1);  break;
		} 
		//else return NULL;
		
	}
	
}
LinkList Get_LinkList(LinkList H,int x)   //����Ų��� 
{
	LNode *p=H;
	int a=0;
	while(p!=NULL)
	{
		p=p->next;
		a++;
		if(a==x)
		{
			printf("\tֵ��%d\n",p->data);  
		}
		else return NULL;
	}
}*/
int Del_LinkList(LinkList H,int i)   //ɾ���������ϵĵ�i���ڵ� 
{
	
}
void Locate_LinkList(LinkList H, int x)   //��ֵ���ҽڵ����ڵ�λ�� 
{
	LNode *p=H->next;
	int j=0;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;	
	}
	if(p!=NULL&&p->data==x) printf("\tΪ��%d���ڵ�\n",j+1);
	else printf("Not found\n");
	
}
void Get_LinkList(LinkList H,int x)   //����Ų��� 
{
	LNode *p=H;
	int a=0;
	while(p!=NULL&&a!=x)
	{
		p=p->next;
		a++;
	}
	if(p!=NULL&&a==x) printf("\tֵΪ%d",p->data);
	else printf("Not found\n");
}


main()
{
	int m,n;
	LNode *p=NULL;
	p=creat_Linklist();
	printf("\t���������Ϊ��\n");
	Length_LinkList(p);
	printf("������Ҫ���ҵ�ֵ:\n");
    scanf("%d",&m);
	Locate_LinkList(p,m);
	printf("������Ҫ���ҵ���ţ�\n");
	scanf("%d",&n);
	Get_LinkList(p,n);
 }
