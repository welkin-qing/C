//顺序表的按值删除 
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int a[100];
	int length;
}seqList;

void creat(seqList *p)
{
	int m;
		printf("输入线性表的大小\n");
	scanf("%d",&m);
	p->length=m;
	printf("\t\t请输入数据：\n");
	for(int i=0;i<p->length;i++)
	{
		scanf("%d",&p->a[i]);
	}
}

void printf_list(seqList *p)
{
	int i=0;
	printf("\t\t输出该顺序表为：\n");
	for(i=0;i<p->length;i++)
	{
		printf("\t");
		printf("%d\t",p->a[i]);
	}
	printf("\n\t\t据统计，共有%d组数据！\n",p->length);
}

void Delete(seqList *A,int x)
{
    int temp=A->length-1;
    int i=0;
    
    while(i!=temp)
    {
    	
        for(int j=0;j<A->length;j++)
        {
        	
            if(A->a[j]==x)
            {
            
                for(int m=j;m<A->length-1;m++)
                    A->a[m]=A->a[m+1];
                   
                A->length=A->length-1;
            }
        }
        i++;
    }
}
main()
{
	int n,m;
	seqList *q;
	q=(seqList*)malloc(sizeof(seqList));
	creat(q);
	printf_list(q);
	printf("请输入要删除的元素:\n");
	scanf("%d",&n);
	Delete(q,n);
	printf_list(q);
}

