#include<stdio.h>
#define maxn 9
typedef struct coor
{
	int x,y;
//	int p;
//	int next;
}coor;
int wide,height;
int end;
int book[8][8];
int map[8][8];
coor oneMove[8]={{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int check(int x,int y)
{
	if(x<0 || y<0 || x>=wide || y >=height)
		return 0;
	if(book[y][x]==1)
		return 0;
//	if(map[y][x]=='1')
//		return 0;
	return 1;
}
coor step[maxn*maxn];
int move()
{
	if(end==63)
	{
		return 1;	//’“µΩ 
	}
	int i;
	book[step[end].y][step[end].x]=1;
	for(i=0;i<8;i++)
	{
		step[end+1].x=step[end].x+oneMove[i].x;
		step[end+1].y=step[end].y+oneMove[i].y;
	//	step[end].p=i+1;
		
		
		if(check(step[end+1].x,step[end+1].y))
		{
			end++;
			if(move()) 
				//’“µΩ
				return 1; 
			end--;
		}
		//ªÿÀ›
		 
	}
	book[step[end].y][step[end].x]=0;
	return 0;
}
int main()
{
	int i,j;
	height=wide=8;
//	scanf("%d %d",&height,&wide);
//	while(getchar()!='\n');
	for(i=0;i<height;i++)
	{
		for(j=0;j<wide;j++)
		{
			book[i][j]=0;
	//		scanf("%c",&map[i][j]); 
		}
	//	while(getchar()!='\n');
		
	}
	end=0;
	scanf("%d %d",&step[0].x,&step[0].y);
	step[0].x--;
	step[0].y--;
	//step[end].p=0;
	move();
	for(i=0;i<64;i++)
	{
		map[step[i].y][step[i].x]=i+1;
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%2d ",map[i][j]);
		printf("\n");
	}
			
}

