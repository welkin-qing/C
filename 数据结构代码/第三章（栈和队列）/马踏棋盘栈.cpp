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
	Elemtype data[MAXSIZE];//栈,类型根据情况而定 
	int top;//指向栈顶 
}SeqStack; 

//新建一个空栈
SeqStack *InitStack (){
	//申请空间 
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	//栈顶初始化 
	S->top =-1; 
	return S;
}


//判断是否为空栈 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//入栈
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1)//栈已满，添加失败 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//出栈并返回 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//空栈，出栈失败
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//取出栈顶元素 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//空栈，出栈失败
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;

int book[8][8] ={0};//标记
int next[8][2]={{-2,1}, //下一步走法 
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
			e1.direction = k;//上一步的走法 
			
			if(e2.x<0||e2.x>=8||e2.y<0||e2.y>=8)
				continue;
		
			if(book[e2.x][e2.y]==0){
				book[e1.x][e1.y]=step;//标记
				Push(SS,e1);
				//printf("入(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
				e1 = e2;
				e1.direction=0;
				step++;
				break;
			}
		}
		if(k==8){
			Pop(SS,&e1);	
			//printf("出(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
		 	book[e1.x][e1.y]=0;
			step--;
			e1.direction++;
		}			
	}
	Push(SS,e1);
	book[e1.x][e1.y]=step;
	int i,j;
	if(step==64){//打印 
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
	book[e.x][e.y]=step;//标记起始点
	dfs(e);
}

