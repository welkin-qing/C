#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
typedef struct{
	int x;
	int y;
	int direction;
}Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];
	int top;
}SeqStack; 

//�½�һ����ջ
SeqStack *InitStack (){
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack)); 
	S->top =-1; 
	return S;
}


//�ж��Ƿ�Ϊ��ջ 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//��ջ
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1)
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ������ 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1)
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;
int book[10][10];
char a[20][20]={0};
int m,n; 
int dfs(Elemtype e)
{
	int k;
	int next[4][2]={{0,1},//�� 
	                {1,0},//�� 
			        {0,-1},//�� 
	                {-1,0}};//��
	Elemtype e1,e2;
	e1 = e;
	e1.direction=0;
	while(e1.x!=(n-1)||e1.y!=(m-1))
	{	
			
		for(k=e1.direction;k<4;k++)
		{
			
			e2.x=e1.x+next[k][0];//��һ�� 
			e2.y=e1.y+next[k][1];
			e1.direction=k;
			if(e2.x<0||e2.y<0||e2.y>=m||e2.x>=n)//�ж��Ƿ�Խ�� 
				continue;	
			if(a[e2.x][e2.y]!='1'&&book[e2.x][e2.y]==0)//�ж���һ���Ƿ��߹����Ƿ����ϰ���
			{
				Push(SS,e1);
				book[e1.x][e1.y]=1;//���
				e1=e2; 
				e1.direction=0;
				//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction);
				break;				
			} 
		}
		
		if(k==4){
			Pop(SS,&e1);
			book[e1.x][e1.y]=0;
			//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction); 
			e1.direction++;
		}
		//printf("%d %d\n",e1.x,e1.y);
	}
	int i;
	if(e1.x==(n-1)&&e1.y==(m-1)){
		for(i=0;i<SS->top+1;i++){
			printf("(%d,%d,%d)",SS->data[i].x+1,SS->data[i].y+1,SS->data[i].direction+1); 
		}
		printf("(%d,%d,0)",n,m);
	}
}
int main(void)
{
	Elemtype e;
	SS=InitStack();
	e.x=0;
	e.y=0;
	e.direction=0;
	book[0][0]=1;//�����ʼ��
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		getchar();
		for(j=0;j<m;j++){
			scanf("%c",&a[i][j]);
		}		
	}
	dfs(e);
}


