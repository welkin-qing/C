#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
	function:计算器 （完成） 
	time:2017年3月26日10:58:55
	nature:
	by：王宝彤 
	note：
	
	*	+-* /（） 
		
	ps： 
		 
		要考虑第一个字符是左括号，nHead不能从0开始而是-1开始（从零开始默认第一个字符前面有个数字，而如果第一个是括号，前面就没有数字） 
		其实默认在前面加一个“0+”就能防止第一个字符是左括号或负号的情况。 
*/ 
typedef struct priority
{
	char symb;
	int pri;
}priority;

priority kuPriority[7]={{'+',1},{'-',1},{'*',2},{'/',2},{'(',3},{')',3},{'\0',0}};
char co[100];
char symbol[100];
int numb[100];
int sPoint,nPoint;
int sHead,nHead;

int findPri(char symb)
{
	for(int i=0;i<7;i++)
	{
		if(kuPriority[i].symb==symb)
			return kuPriority[i].pri;
	}
	return -1;
}
int calc(int a,int b,char symb)
{
	switch(symb)
	{
		case '+':return a+b; 
		case '-':return a-b;
		case '*':return a*b; 
		case '/':
			if(b==0)
			{
				printf("除数为0\n");
				system("pause");
				exit(0);
			}
			else 
			{
				return a/b;
			}
	}
}
void f()
{
	int len;
	int i,a;
	int flag,negative;
	scanf("%s",co);//scanf能解决行末空格问题，gets不行 
	len=strlen(co);
	sPoint=nPoint=0;
	//栈的准备
	int sum=0;
	flag=-1;
	negative=1;
	
	for(i=0;i<len;i++)
	{
		if(i==0 && co[0]=='-')
		{
			negative=-1;
			continue;
		}
		if(co[i]<='9' && co[i]>='0')
		{
			if(i!=0)
			{
				if(co[i-1]==')')
				{
					printf("不合法：右括号后面不能是数字\n");
					system("pause");
					return;
				}
			}
			flag=0;
			sum=sum*10+co[i]-'0';
			if(i==len-1)
			{
				numb[nPoint++]=sum*negative;
				sum=0;
				negative=1;
			}
			else if(!(co[i+1]<='9' && co[i+1]>='0'))
			{
				numb[nPoint++]=sum*negative;
				sum=0;
				negative=1;
			}
		}
		else //是运算符 
		{
			if(co[i]=='(' ||co[i]==')')
			{
				if(co[i]=='('&&flag==0)
				{
					printf("不合法：左括号前面不能是数字\n");
					system("pause");
					return;
					
				}
				else if(co[i]==')'&&flag!=0&&co[i-1]!=')') 
				{
					printf("不合法：右括号前面不能是非右括号运算符\n") ;
					system("pause");
					return;
				}
				flag=2;
			}
			else//不是括号 
			{
				
				if(sPoint!=0)
				{
					if(co[i-1]=='('&&co[i]!='(')//非左括号运算符前面不能是左括号
					{
						if(co[i]=='-')//负号
						{
							negative=-1;
							continue; 
						} 
						else if(co[i]=='+')
						{
							continue;
						}
						if(co[i]!='(')
						{
							printf("不合法：左括号后面不能有非括号运算符\n") ;
							system("pause");
							return;
						 } 
					} 
				}
				if(flag==1)
				{
					printf("不合法：运算符前后不能有除括号以外的运算符\n") ;
					system("pause");
					return;
				}
				flag=1; 
			}

			symbol[sPoint++]=co[i];
		}
	}
	//栈准备完毕 
	a=0; 
	for(i=0;i<=sPoint;i++)
	{
		if(symbol[i]=='(')
		{
			a++;
		}
		else if(symbol[i]==')')
		{
			a--;
		}
		if(a==-1)
		{
			printf("括号符不匹配\n");
			system("pause");
			return;
		}
	}
	if(a!=0)
	{
		printf("括号符不匹配\n");
		system("pause");
		return;
	}
	//检查匹配括号完毕 
	if(sPoint!=0)
	{
		sPoint--;
	}
	if(nPoint!=0)
	{
		nPoint--;
	}
	
	//开始计算
	int formal,current;
	
	sHead=-1;
	nHead=0;
	if(symbol[0]=='(')
	{
		nHead--;
	}
	while(1)
	{
		sHead++;
		
		if(nPoint==0)
		{
			printf("%d",numb[0]);
			break;
		}
		if(sHead==0)
		{
			continue;
		}
		formal=findPri(symbol[sHead-1]);
		current=findPri(symbol[sHead]);

		if(formal==-1 || current==-1)
		{
			printf("非法字符\n");
			system("pause");
			return;
		}
		
		
		if(symbol[sHead]!='(')//非左括号
		{
			nHead++; 
		} 
		if(current==3) //括号
		{
			if(symbol[sHead]=='(')
			{
				continue;
			}
			else
			{
				//消掉括号 
				if(symbol[sHead-1]!='(')
				{
					numb[nHead-1]=calc(numb[nHead-1],numb[nHead],symbol[sHead-1]);
					for(a=nHead;a<nPoint;a++)
					{
						numb[a]=numb[a+1];
					}
					numb[a]=0;
					nPoint--;
					
					for(a=sHead-1;a<sPoint;a++)
					{
						symbol[a]=symbol[a+1];
					}
					symbol[sPoint]='\0';
					sPoint--;
					nHead=0;
					sHead=-1;
					if(symbol[0]=='(')
					{
						nHead--;
					}
					continue;//重新开始 
				}
				else
				{
					for(a=sHead-1;a<=sPoint-2;a++)
					{
						symbol[a]=symbol[a+2];
					}
					symbol[sPoint-1]=symbol[sPoint]='\0';
					sPoint-=2;
					sHead=-1;
					nHead=0;
					if(symbol[0]=='(')
					{
						nHead--;
					}
					continue;//重新开始 
				}
				
			}
		} 
		if(formal<current)
		{
			continue;
		}
		else if(formal>=current && formal!=3)//且不是括号 
		{
			numb[nHead-1]=calc(numb[nHead-1],numb[nHead],symbol[sHead-1]);
			for(a=nHead;a<nPoint;a++)
			{
				numb[a]=numb[a+1];
			}
			numb[nPoint]=0;
			nPoint--;
			
			for(a=sHead-1;a<sPoint;a++)
			{
				symbol[a]=symbol[a+1];
			}
			symbol[sPoint]='\0';
			sPoint--;
			sHead=-1;
			nHead=0;
			if(symbol[0]=='(')
			{
				nHead--;
			}
			continue; 
		}
	}
}
int main()
{
	while(1)
	{
		f();
		printf("\n");
	 } 
}




















