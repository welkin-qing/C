#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int a[100];
	int length;
}seqList;

void creat(seqList *p)
{
	int m;
	p=(seqList*)malloc(sizeof(seqList));
	printf("\t\t���������õ�Ԫ�ظ�����\n");
	scanf("%d",&m);
	p->length=m;
	printf("\t\t���������ݣ�\n");
	for(int i=0;i<p->length;i++)
	{
		scanf("%d",&p->a[i]);
	}
}

void printf_list(seqList *p)
{
	int i=0;
	seqList *q;
	//p=(seqList*)malloc(sizeof(seqList)); �������� 
	//p=p->a;    ����ָ�� 
	printf("\t\t�����˳���Ϊ��\n");
	//printf("%d",q->length);
	for(i=0;i<q->length;i++)
	{
		printf("\t");
		printf("%d\t",q->a[i]);
	}
	printf("\n\t\t��ͳ�ƣ�����%d�����ݣ�\n",q->length);
}

void  reverse(seqList *p)
{
	/*
		int i, n=L->length;
		int t;
		for(i=1;i<=n/2;i++)
		{
			t=L->a[i];
			L->a[i]=L->a[n-i+1];
			L->a[n-i+1]=t;
		}*/
	int m;
	seqList *q;
	m=q->length;
	printf("\n\t\t������ú��˳���Ϊ:\n");
	for(m=q->length-1;m>=0;m--)
	{
		printf("\t");
		printf("%d\t",q->a[m]);
	}
}

main()
{
	seqList *a;
	a=(seqList*)malloc(sizeof(seqList));
	creat(a);
	printf_list(a);
	reverse(a);
	//printf_list(a);
} 
