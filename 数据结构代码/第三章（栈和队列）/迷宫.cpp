//迷宫求解问题acm计算 
/* 
样例输入
9 8
00100010
00100010
00001101
01110010
00010000
01000101
01111001
11000101
11000000
样例输出
(1,1,1)
(1,2,2)
(2,2,2)
(3,2,3)
(3,1,2)
(4,1,2)
(5,1,1)
(5,2,1)
(5,3,2)
(6,3,1)
(6,4,1)
(6,5,4)
(5,5,1)
(5,6,1)
(5,7,2)
(6,7,2)
(7,7,2)
(8,7,2)
(9,7,1)
(9,8,0)*/ 
#include<stdio.h>
#include<stdlib.h>
#define N 100
#define M 100
#define MAXSIZE N*M
int a[M][N],book[M][N];
int m,n;
typedef struct{	
	int x;
	int y;
	int dire;
}Unit;                      
Unit point[MAXSIZE];         //结构体数组
int top=1,base=0;
void dfs(int x,int y)       // DFS核心函数
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	if(x==m&&y==n)        //判断边界
	    {  point[top].dire=0;
		   while(base<top)
           {
    	   printf("(%d,%d,%d)",point[base].x,point[base].y,point[base].dire);
    	   base++;
	       }
	       exit(0);
		}
	for(k=0;k<=3;k++)     //尝试每个方向
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			point[top-1].dire=k+1;
			point[top].x=tx;
			point[top].y=ty;
			top++;
			dfs(tx,ty);       //递归dfs函数
			book[tx][ty]=0;
			top--;
		}
	}
	return;
 } 
void Arr(int a[][100],int m,int n)				//获取迷宫 
{
	int i,j;
	char t;
	for(i=0;i<=m+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			if(i==0||i==m+1||j==0||j==n+1)
				a[i][j]=1;
			else
			{
				scanf("%c",&t);
				a[i][j]=t-'0';
			}
 		}
 		if(i&&i-(n+1)) 	
		 	getchar();
	}
}
int main()
{   
	scanf("%d%d",&m,&n);
	getchar();
	Arr(a,m,n);
    int sx=1,sy=1;
    book[1][1]=1;
	point[0].dire=1; point[0].x=1; point[0].y=1;
    dfs(sx,sy);   
}
