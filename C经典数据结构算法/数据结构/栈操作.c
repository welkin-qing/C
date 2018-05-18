#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define ElemType int
#define S  (*p)

struct SqStack
{
	ElemType elem[MAX];
	int top;
};

main()
{
	struct SqStack *q;
	int i,y,cord;ElemType a;
	void OutStack(struct SqStack S);
	void InitStack(struct SqStack *p);
	void Push(struct SqStack *p,ElemType x);
	ElemType Pop(struct SqStack *p);
	ElemType GetTop(struct SqStack *p);
	do{
		printf("\n");
		printf("\n           ���˵�          \n");
		printf("\n     1     ��ʼ��˳��ջ    \n");
		printf("\n     2     ����һ��Ԫ��    \n");
		printf("\n     3     ɾ��ջ��Ԫ��    \n");
		printf("\n     4     ȡջ��Ԫ��      \n");
		printf("\n     5     ������������    \n");
		printf("\n--------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4, 5)");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
				{
					q=(struct SqStack*)malloc(sizeof(struct SqStack));
					InitStack(q);
					OutStack(q);
				}break;
			case 2:
				{
					printf("������Ҫ��������� a=");
					scanf("%d",&a);
					Push(q,a);
					OutStack(q);
				}break;
			case 3:
				{
					Pop(q);
					OutStack(q);
				}break;
			case 4:
				{
					y=GetTop(q);
					printf("\ny=%d\n",y);
					OutStack(q);
				}break;
			case 5:
				exit(0);
		}
	}while (cord<=5);
}

void InitStack(struct SqStack *p)
{
	if(!p)
		printf("Eorror");
	S.top=0;
}

void Push(struct SqStack *p,ElemType x)
{
	if(S.top<MAX-1)
	{
		S.top=S.top+1;
		S.elem[S.top]=x;
	}
	else
		printf("Overflow!\n");
}

ElemType Pop(struct SqStack *p)
{
	ElemType x;
	if(S.top!=0)
	{
		x=S.elem[S.top];
		S.top=S.top-1;
		return(x);
	}
	else
	{
		printf("Underflow!\n");
		return(0);
	}
}

ElemType GetTop(struct SqStack *p)
{
	ElemType x;
	if(S.top!=0)
	{
		x=S.elem[S.top];
		return(x);
	}
	else
	{
		printf("Underflow!\n");
		return(0);
	}
}

void OutStack(struct SqStack *p)
{
	int i,j;
	if(S.top==0)
		printf("The stack is null");
	for(i=S.top;i>0;i--)
		printf("%2d %6d\n",i,S.elem[i]);
}