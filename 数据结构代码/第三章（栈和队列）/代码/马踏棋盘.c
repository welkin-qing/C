#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
#define N  8//棋盘大小
int weight [N][N];//各点的权重
int Board[N][N][8];//按照各点的权值升存方带走方向，每点8个

typedef struct//位置
{
	int x;
	int y;
}DirType;

typedef struct//栈的元素
{
	int ord;
	DirType seat;//点
	int dir;//马的方向
}ElemType;

typedef struct //定义栈
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

SqStack s;


int Init_Stack()//初始化一个空栈
{
	s.base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if(!s.base)
		return 0;
	s.top = s.base;
	s.stacksize = STACK_SIZE;
	return 1;
}

DirType NextPos(DirType location/*位置*/,int direction)//8个可走的方向
{
	switch(direction)
	{
		case 1:location.x-=2;location.y+=1;break;
		case 2:location.x-=1;location.y+=2;break;
		case 3:location.x+=1;location.y+=2;break;
		case 4:location.x+=2;location.y+=1;break;
		case 5:location.x+=2;location.y-=1;break;
		case 6:location.x+=1;location.y-=2;break;
		case 7:location.x-=1;location.y-=2;break;
		case 8:location.x-=2;location.y-=1;break;
	}
	return location;//返回走到的新点
}

void setwight()
{
	int i,j,k;
	DirType m;
	ElemType elem;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			elem.seat.x = i;
			elem.seat.y = j;
			weight[i][j] = 0;
			for(k=0;k<8;k++)
			{
				m = NextPos(elem.seat,k+1);
				if(m.x>=0&&m.x<N&&m.y>=0&&m.y<N)
					weight[i][j]++;//(i,j)有几个方向可以移动
			}
		}
	}
}

void setmap()//各点的八个方向按权值递增排列
{
	int a[8];
	int i,j,k,m,n,h,min;
	DirType n1,n2;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<8;k++)//用数组a[8]记录当前位置的下一个位置的可行路径的条数
			{
				n2.x = i;
				n2.y = j;
				n1 = NextPos(n2,k+1);
				if(n1.x>=0&&n1.x<N&&n1.y>=0&&n1.y<N)
					a[k] = weight[n1.x][n1.y];
				else
					a[k] = 0;
			}
			//对方向索引权值升序排列存入Board[N][N][8]，不能到达的地方排在最后
			for(m=0;m<8;m++)
			{
				min = 9;
				for(h=0;h<8;h++)
					if(min>a[h])
					{
						min = a[h];
						Board[i][j][m] = h;
						n = h;
					}
					a[n] = 9;//选过的设为9
			}
		}
	}
}

int Ok(DirType location)//判断位置是否合法
{
	SqStack s1 = s;
	if(location.x<0||location.x>(N-1)||location.y<0||location.y>(N-1))
		return 0;
	for(;s1.top != s1.base;)
	{
		--s1.top;
		if(location.x==(*s1.top).seat.x&&location.y==(*s1.top).seat.y)
			return 0;
	}
	return 1;
}

void Push(ElemType elem)//将元素压入栈
{
	*s.top++=elem;
}

int StackEmpty()//判断栈是否为空
{
	if(s.top == s.base)
		return 1;
	else
		return 0;
}

int Pop(ElemType *elem)//将栈顶元素压出
{
	if(s.top == s.base)
		return 0;
	*elem=*--s.top;
	return 1;
}

ElemType GetTop()//取得栈顶的值
{
	if(s.top == s.base)
		exit(0);
	return *(s.top-1);
}


int HorsePath(DirType start)//马走过的路径
{
	DirType location;
	int horsestep = 0,off;
	ElemType elem;
	location = start;
	do
	{
		if(Ok(location))   //判断位置是否合法
		{
			horsestep++;
			elem.dir = 0;
			elem.ord = horsestep;
			elem.seat = location;
			Push(elem);
			if(N*N == horsestep)
				return 1;
			off = Board[elem.seat.x][elem.seat.y][elem.dir]+1;
			location = NextPos(elem.seat,off);//取得下一点的坐标
		}
		else 
		{
			if(!StackEmpty()) //栈s非空
			{
				while(!StackEmpty()&&elem.dir==8)
				{
					Pop(&elem);//将栈顶元素压出
					if(!StackEmpty())//判断是否为空
					{
						elem = GetTop();
						horsestep = elem.ord;
					}
				}
				if(!StackEmpty()&&elem.dir<8)
				{
					Pop(&elem);
					off = Board[elem.seat.x][elem.seat.y][++elem.dir];
					location = NextPos(elem.seat,off+1);
					Push(elem);
				}
			}
		}
	}while(!StackEmpty());
	printf("走不通!");
	return 0;
}

void OutputPath()//输出马走的路径
{
	int i,j,k;
	SqStack s1=s;
	int path[N][N];
	for(i=0;s1.top!=s1.base;i++)
	{
		path[(*s1.base).seat.x][(*s1.base).seat.y]=i+1;
		++s1.base;
	}
	for(j=0;j<N;j++)
	{
		printf("\n");
		for(k=0;k<N;k++)
			printf("\t%d",(path[j][k]));
	}
	printf("\n");
}

void main()
{
	DirType start;
	Init_Stack();
	printf("请输入起始位置(0~7)\nX:");
	scanf("%d",&start.x);
	printf("Y:");
	scanf("%d",&start.y);
	setwight();//求各点权值
	setmap();
	HorsePath(start);
	OutputPath();
}