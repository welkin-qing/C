#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
	function:������ ����ɣ� 
	time:2017��3��26��10:58:55
	nature:
	by������ͮ 
	note��
	
	*	+-* /���� 
		
	ps�� 
		 
		Ҫ���ǵ�һ���ַ��������ţ�nHead���ܴ�0��ʼ����-1��ʼ�����㿪ʼĬ�ϵ�һ���ַ�ǰ���и����֣��������һ�������ţ�ǰ���û�����֣� 
		��ʵĬ����ǰ���һ����0+�����ܷ�ֹ��һ���ַ��������Ż򸺺ŵ������ 
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
				printf("����Ϊ0\n");
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
	scanf("%s",co);//scanf�ܽ����ĩ�ո����⣬gets���� 
	len=strlen(co);
	sPoint=nPoint=0;
	//ջ��׼��
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
					printf("���Ϸ��������ź��治��������\n");
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
		else //������� 
		{
			if(co[i]=='(' ||co[i]==')')
			{
				if(co[i]=='('&&flag==0)
				{
					printf("���Ϸ���������ǰ�治��������\n");
					system("pause");
					return;
					
				}
				else if(co[i]==')'&&flag!=0&&co[i-1]!=')') 
				{
					printf("���Ϸ���������ǰ�治���Ƿ������������\n") ;
					system("pause");
					return;
				}
				flag=2;
			}
			else//�������� 
			{
				
				if(sPoint!=0)
				{
					if(co[i-1]=='('&&co[i]!='(')//�������������ǰ�治����������
					{
						if(co[i]=='-')//����
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
							printf("���Ϸ��������ź��治���з����������\n") ;
							system("pause");
							return;
						 } 
					} 
				}
				if(flag==1)
				{
					printf("���Ϸ��������ǰ�����г���������������\n") ;
					system("pause");
					return;
				}
				flag=1; 
			}

			symbol[sPoint++]=co[i];
		}
	}
	//ջ׼����� 
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
			printf("���ŷ���ƥ��\n");
			system("pause");
			return;
		}
	}
	if(a!=0)
	{
		printf("���ŷ���ƥ��\n");
		system("pause");
		return;
	}
	//���ƥ��������� 
	if(sPoint!=0)
	{
		sPoint--;
	}
	if(nPoint!=0)
	{
		nPoint--;
	}
	
	//��ʼ����
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
			printf("�Ƿ��ַ�\n");
			system("pause");
			return;
		}
		
		
		if(symbol[sHead]!='(')//��������
		{
			nHead++; 
		} 
		if(current==3) //����
		{
			if(symbol[sHead]=='(')
			{
				continue;
			}
			else
			{
				//�������� 
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
					continue;//���¿�ʼ 
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
					continue;//���¿�ʼ 
				}
				
			}
		} 
		if(formal<current)
		{
			continue;
		}
		else if(formal>=current && formal!=3)//�Ҳ������� 
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




















