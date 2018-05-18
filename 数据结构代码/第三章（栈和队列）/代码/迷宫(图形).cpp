
#include <stdio.h>
#include <graphics.h>
//是TC的针对DOS下的一个C语言图形库，如果要用的话应该用TC的编译器来编译，VC++环境有其它的针对windows的图形库
typedef struct StackNode 
{
	int x,y,direction;
	struct StackNode *next;
}StackNode;
typedef struct
{
	StackNode *top;
}LinkStack;
#define MAXLEN 20
#define RL 400/MAXLEN
int maze[MAXLEN][MAXLEN]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},{0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0},{0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0},{0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},{0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},{0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},{0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
//int maze[MAXLEN][MAXLEN]={{0,0,0,0,0,0,0,0,0,0},{0,1,0,1,1,1,1,0,0,0},{0,1,0,0,1,0,1,0,0,0},{0,1,1,1,1,0,1,0,1,0},{0,0,0,0,0,0,1,0,1,0},{0,1,1,1,1,1,1,1,1,0},{0,1,0,1,0,0,0,0,0,0},{0,0,0,1,1,1,1,1,0,0},{0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0}};
//ar maze[MAXLEN][MAXLEN]={{'#','#','#','#','#','#','#','#','#','#'},{'#','*','#','*','*','*','*','#','#','#'},{'#','*','#','#','*','#','*','#','#','#'},{'#','*','*','*','*','#','*','#','*','#'},{'#','#','#','#','#','#','*','#','*','#'},{'#','*','*','*','*','*','*','*','*','#'},{'#','*','#','*','#','#','#','#','#','#'},{'#','#','#','*','*','*','*','*','#','#'},{'#','#','#','#','#','#','#','*','*','#'},{'#','#','#','#','#','#','#','#','#','#'}};
//direction ? 0、1、2、3 右、下、左、上
void advance(LinkStack &s);
void back(LinkStack &s);
void Push(LinkStack &s,int x,int y,int direction);
void Pop(LinkStack &s);
void InStack(LinkStack &s,int x,int y,int direction);
int getx(int x);
int gety(int x);
int li(int x);
void main()
{
	int i,j;
	initgraph(RL*MAXLEN,RL*MAXLEN);
	setcolor(RED);
	setfillcolor(RED);
	for(i=0;i<MAXLEN;i++)
		for(j=0;j<MAXLEN;j++)
			if(maze[j][i])
				fillrectangle(RL*i,RL*j,RL*i+RL,RL*j+RL);
			LinkStack s,d;
			s.top=NULL;
			d.top=NULL;
			StackNode *p=new StackNode;
			s.top=p;
			p->x=1;
			p->y=1;
			p->direction=1;
			p->next=NULL;
			setfillcolor(WHITE);
			fillcircle(p->x*RL+RL/2,p->y*RL+RL/2,RL/2);
			//运算过程
			printf("寻找过程：\n");
			while(s.top->x!=18 || s.top->y!=18)
				advance(s);
			printf("建立x=%2d y=%2d d=%2d \n",s.top->x,s.top->y,s.top->direction);
			printf("\n--------------\n\n");
			//逆序输出结果
			printf("最简结果：\n");
			p=s.top;
			while(p)
			{
				InStack(d,p->x,p->y,p->direction);
				p=p->next;
			}
			p=d.top;
			while(p)
			{
				printf("x=%2d y=%2d d=%d\n",p->x,p->y,p->direction);
				p=p->next;
			}
			outtext("按任意键查看过程");
			system("pause");
			closegraph();
}
void advance(LinkStack &s)
{
	StackNode *p=s.top;
	int i=0;
	while(1)
	{
		if(li(p->direction)!=i)
			if(maze[p->y+gety(i)][p->x+getx(i)] == 1)
			{
				Push(s,(p->x+getx(i)),(p->y+gety(i)),i);
				break;
			}
			i++;
			if(i == 4)
			{
				Pop(s);
				back(s);
				break;
			}
	}
}


void back(LinkStack &s)
{
	StackNode *p=s.top;
	int i=++p->direction;
	while(1)
	{
		if(i == 4)
		{
			Pop(s);
			back(s);
			break;
		}
		if(li(p->next->direction) != i)
			if(maze[p->y+gety(i)][p->x+getx(i)] == 1)
			{
				Push(s,(p->x+getx(i)),(p->y+gety(i)),i);
				break;
			}
			i++;
			
			
			
	}
}


void Push(LinkStack &s,int x,int y,int direction)
{
	StackNode *p=new StackNode; 
	p->x=x;
	p->y=y;
	p->direction=direction;
	p->next=s.top;
	s.top=p;
	if(p->next)
		p->next->direction=direction;
	printf("建立x=%2d y=%2d d=%d\n",p->next->x,p->next->y,p->next->direction);
	Sleep(200);
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillcircle(p->x*RL+RL/2,p->y*RL+RL/2,RL/2);
}


void Pop(LinkStack &s)
{
	StackNode *p=s.top;
	if(p)
	{
		Sleep(200);
		setcolor(RED);
		setfillcolor(RED);
		fillcircle(p->x*RL+RL/2,p->y*RL+RL/2,RL/2);
		s.top=p->next;
		printf("撤销x=%2d y=%2d d=%d \n",s.top->x,s.top->y,s.top->direction);
		delete p;
	}
	
	
}


void InStack(LinkStack &s,int x,int y,int direction)
{
	StackNode *p=new StackNode; 
	p->x=x;
	p->y=y;
	p->direction=direction;
	p->next=s.top;
	s.top=p;
}


int getx(int x)
{
	int a[]={1,0,-1,0};
	return a[x];
}


int gety(int x)
{
	int a[]={0,1,0,-1};
	return a[x];
}


int li(int x)
{
	int a[]={2,3,0,1};
	return a[x];
}



