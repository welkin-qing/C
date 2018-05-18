#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
typedef struct{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];//ջ,���͸���������� 
	int top;//ָ��ջ�� 
}SeqStack; 

//�½�һ����ջ
SeqStack *InitStack (){
	//����ռ� 
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	//ջ����ʼ�� 
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
	if(S->top==MAXSIZE-1)//ջ���������ʧ�� 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ������ 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//��ջ����ջʧ��
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//��ջ����ջʧ��
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;

int book[8][8] ={0};//���
int next[8][2]={{-2,1}, //��һ���߷� 
				{-1,2}, 
			    {1,2},
	            {2,1}, 
				{2,-1},
				{1,-2}, 
			    {-1,-2},
	            {-2,-1}};
int step=0;	            
int dfs(Elemtype e){

	 int k,step=1;
	 Elemtype e1=e,e2;
	 e1.direction=0;
	 
	while(step!=64){
			
		for(k=e1.direction;k<8;k++){
			
			e2.x=e1.x+next[k][0];
			e2.y=e1.y+next[k][1];
			e1.direction = k;//��һ�����߷� 
			
			if(e2.x<0||e2.x>=8||e2.y<0||e2.y>=8)
				continue;
		
			if(book[e2.x][e2.y]==0){
				book[e1.x][e1.y]=step;//���
				Push(SS,e1);
				//printf("��(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
				e1 = e2;
				e1.direction=0;
				step++;
				break;
			}
		}
		if(k==8){
			Pop(SS,&e1);	
			//printf("��(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
		 	book[e1.x][e1.y]=0;
			step--;
			e1.direction++;
		}			
	}
	Push(SS,e1);
	book[e1.x][e1.y]=step;
	int i,j;
	if(step==64){//��ӡ 
		for(i=0;i<8;i++){ 
		
			for(j=0;j<8;j++)
					printf("%2d ",book[i][j]);
			 	printf("\n");
			} 
			return 0;
	}		
}

int main(void)
{
	Elemtype e;
	SS=InitStack();
	scanf("%d%d",&e.x,&e.y);
	e.x--;
	e.y--;
	book[e.x][e.y]=step;//�����ʼ��
	dfs(e);
}

