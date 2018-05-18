#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
#define N  8//���̴�С
int weight [N][N];//�����Ȩ��
int Board[N][N][8];//���ո����Ȩֵ���淽���߷���ÿ��8��

typedef struct//λ��
{
	int x;
	int y;
}DirType;

typedef struct//ջ��Ԫ��
{
	int ord;
	DirType seat;//��
	int dir;//��ķ���
}ElemType;

typedef struct //����ջ
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

SqStack s;


int Init_Stack()//��ʼ��һ����ջ
{
	s.base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if(!s.base)
		return 0;
	s.top = s.base;
	s.stacksize = STACK_SIZE;
	return 1;
}

DirType NextPos(DirType location/*λ��*/,int direction)//8�����ߵķ���
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
	return location;//�����ߵ����µ�
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
					weight[i][j]++;//(i,j)�м�����������ƶ�
			}
		}
	}
}

void setmap()//����İ˸�����Ȩֵ��������
{
	int a[8];
	int i,j,k,m,n,h,min;
	DirType n1,n2;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<8;k++)//������a[8]��¼��ǰλ�õ���һ��λ�õĿ���·��������
			{
				n2.x = i;
				n2.y = j;
				n1 = NextPos(n2,k+1);
				if(n1.x>=0&&n1.x<N&&n1.y>=0&&n1.y<N)
					a[k] = weight[n1.x][n1.y];
				else
					a[k] = 0;
			}
			//�Է�������Ȩֵ�������д���Board[N][N][8]�����ܵ���ĵط��������
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
					a[n] = 9;//ѡ������Ϊ9
			}
		}
	}
}

int Ok(DirType location)//�ж�λ���Ƿ�Ϸ�
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

void Push(ElemType elem)//��Ԫ��ѹ��ջ
{
	*s.top++=elem;
}

int StackEmpty()//�ж�ջ�Ƿ�Ϊ��
{
	if(s.top == s.base)
		return 1;
	else
		return 0;
}

int Pop(ElemType *elem)//��ջ��Ԫ��ѹ��
{
	if(s.top == s.base)
		return 0;
	*elem=*--s.top;
	return 1;
}

ElemType GetTop()//ȡ��ջ����ֵ
{
	if(s.top == s.base)
		exit(0);
	return *(s.top-1);
}


int HorsePath(DirType start)//���߹���·��
{
	DirType location;
	int horsestep = 0,off;
	ElemType elem;
	location = start;
	do
	{
		if(Ok(location))   //�ж�λ���Ƿ�Ϸ�
		{
			horsestep++;
			elem.dir = 0;
			elem.ord = horsestep;
			elem.seat = location;
			Push(elem);
			if(N*N == horsestep)
				return 1;
			off = Board[elem.seat.x][elem.seat.y][elem.dir]+1;
			location = NextPos(elem.seat,off);//ȡ����һ�������
		}
		else 
		{
			if(!StackEmpty()) //ջs�ǿ�
			{
				while(!StackEmpty()&&elem.dir==8)
				{
					Pop(&elem);//��ջ��Ԫ��ѹ��
					if(!StackEmpty())//�ж��Ƿ�Ϊ��
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
	printf("�߲�ͨ!");
	return 0;
}

void OutputPath()//������ߵ�·��
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
	printf("��������ʼλ��(0~7)\nX:");
	scanf("%d",&start.x);
	printf("Y:");
	scanf("%d",&start.y);
	setwight();//�����Ȩֵ
	setmap();
	HorsePath(start);
	OutputPath();
}