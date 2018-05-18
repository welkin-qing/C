//中缀转后缀
#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct node
{
	char data;
	struct node *next;
}SeqStake;

//初始化栈 



//初始化栈 
SeqStake* Build_SeqStake()
{
	SeqStake *top;
	top=(SeqStake *)malloc(sizeof(SeqStake));
	top->next=NULL;
	return top;
} 

//入栈
void In_SeqStake(SeqStake *top,char x)
{
	SeqStake *p;
	if((p = (SeqStake *)malloc(sizeof(SeqStake)))!=NULL)
	{
		p->data = x;
		p->next = top->next;
		top->next = p;     
	} 
	else
	printf("栈满\n");  
}

char Out_SeqStake(SeqStake *top)
{
	SeqStake *p;
	char x;
	p = top->next;
	top->next = p->next;
	x = p->data;
	free(p);
	return x;
}

char Top_SeqStake(SeqStake *top)
{
	char x;
	x = top->next->data;
	return x;
}

//优先级比较 
int Compare(char a,char b)
{
	if(a == '*' || a == '/')
	{
		if(b == '*' || b == '/')
		return 0;
		if(b == '+' || b == '-' || b == '(')
		return 1;
	}
	if(a == '+' || a == '-')
	{
		if(b == '*' || b == '/' || b == '+' || b == '-' )
		return 0;
		if(b == '(')
		return 1;
	}
}

int main()
{
	//A为数字栈，B为符号栈 
    char c[MAXSIZE];
    char t,s;
    int pos=1,com,k=0,flag;
	SeqStake *A = Build_SeqStake(),*B =Build_SeqStake();
	printf("请输入算式：");
	scanf("%s",&c);
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]>='a'&&c[i]<='z')
		{
			In_SeqStake(A,c[i]);
		}
		else{
			switch(c[i])
			{
				case '+': 
				case '-':	
				case '*': 
				case '/':
				if(B->next==NULL)
					In_SeqStake(B,c[i]);
				else
				{
					t = Top_SeqStake(B);
					if((com = Compare(c[i],t) == 1))
					{
						In_SeqStake(B,c[i]);
					}
					else
					{
						while((com = Compare(c[i],t)!=1 && B->next!=NULL))
						{
							In_SeqStake(A,(s=Out_SeqStake(B)));
							if(B->next!=NULL)
								t = Top_SeqStake(B);
						}
						In_SeqStake(B,c[i]);
					}
					break;	
				case '(':
					In_SeqStake(B,c[i]); 
					break;
				case ')':
					t = Top_SeqStake(B);
					while(t!='(')
					{
						s = Out_SeqStake(B);
						In_SeqStake(A,s);
						t = Top_SeqStake(B);
					}
					s=Out_SeqStake(B);
					break;
				}
			}
		}
	}
	while(A->next!=NULL)
	{
		s = Out_SeqStake(A);
        In_SeqStake(B,s);
    }
	while(B->next != NULL)
	{
		s=Out_SeqStake(B);
		printf("%c",s);
	}
	return 0;	
} 



 


