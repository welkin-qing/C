#include<stdio.h>
#include<string.h>
#define MAXLEN 50
typedef struct{    //���촮 
	char ch[MAXLEN+1];
	int len;
}SString;

void init(SString *s) //��ʼ�� 
{
	s->len = 0;
}

SString *create(SString *s)  //������
{
	char a;
	scanf("%c",&a);
	while(a!='#')   
	{
		s->len++;
		s->ch[s->len]=a;
		scanf("%c",&a);
	}
	return s;
} 
void output(SString *s)   //������� 
{
	int i;
	
	for(i=1;i<=s->len ;i++)
	{
		printf("%c",s->ch[i]);
	}
} 
int Index_KMP(SString S,int pos,SString T)  //ƥ�亯�� 
{
    int i=pos,j=1;
    int next[MAXLEN];  
    Get_Next(S, next);
	while (i<=S.len&&j<=T.len)
	{
		if(j==0||S.ch[i]==T.ch[j])
		{
			++i;
			++j;
		}
		else   j=next[j];
	}
	if (j>T.len)   return i-T.len;
	else return 0;
}
void Get_Next(SString T,int next[])
{
	int j=1,k=0;
	next[1]=0;
	while(j<T.len)
	{
		if(k==0 ||T.ch[j]==T.ch[k])
		{
			++j;
			++k;
			next[j]=k;
		}
		else k=next[k];
	}
}
int main()
{
	SString *s,*t;
	char  m='abc' ;
	char ch1,ch2;
	s=(SString *)malloc(sizeof(SString));
	init(s);
	printf("������s�Ӵ��ַ�(��#����):\n");
	s=create(s);   //���� 
	printf("��s���ַ�Ϊ:");
	output(s);
	printf("\n");
	t=Index_KMP(s,1,m);
	output(t);
}
