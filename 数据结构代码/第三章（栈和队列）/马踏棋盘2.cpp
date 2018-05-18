//¥ÌŒÛ 
//¥ÀÃ‚Œ™√‘π¨ 
#include<stdio.h>
#pragma warning(disable:4996)£ª
int n,m,p,q,min=99999999;
int a[1000][1000], book[1000][1000] = {0};
int flag=0;
int p1[10000];
int p2[10000];
int p3[10000];
int top;
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	if(flag==1)
	{
		return;
	}
	if(x==n&&y==m)
	{
		flag=1;
		top=step;
		return;
	}
	for(k=0;k<4;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<1||tx>n||ty<1||ty>m)
		continue;
		
		if(a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			p1[step]=x;
			p2[step]=y;
			p3[step]=k+1;
			dfs(tx,ty,step+1);
			if (flag == 1)
			{
				return;
			}
			
			book[tx][ty]=0;
		}
			
	}
	return;
 }
  int main(void)
{
	int i,j;
	scanf("%d%d\n",&n,&m);
	char ls[1000];
	for(i=1;i<=n;i++)
	{
		gets(ls);
		for(j=1;j<=m;j++)
		{
			a[i][j]=ls[j-1]-'0';
		}
	}
	book[1][1]=1;
	p1[top]=1;
	p2[top]=1;
	p3[top]=1;
	
	
	
	
	dfs(1,1,1);
	
	if (flag == 1)
	{
		for (i = 1; i < top; i++)
		{
			printf("(%d,%d,%d)", p1[i], p2[i], p3[i]);
			
		}
		printf("(%d,%d,%d)", n, m, 0);
	}
	else
	{
	}
	return 0;
	
#include<stdio.h>
#pragma warning(disable:4996)£ª
int n,m,p,q,min=99999999;
int a[1000][1000], book[1000][1000] = {0};
int flag=0;
int p1[10000];
int p2[10000];
int p3[10000];
int top;
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	if(flag==1)
	{
		return;
	}
	if(x==n&&y==m)
	{
		flag=1;
		top=step;
		return;
	}
	for(k=0;k<4;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<1||tx>n||ty<1||ty>m)
		continue;
		
		if(a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			p1[step]=x;
			p2[step]=y;
			p3[step]=k+1;
			dfs(tx,ty,step+1);
			if (flag == 1)
			{
				return;
			}
			
			book[tx][ty]=0;
		}
			
	}
	return;
 }
int main(void)

{
	int i,j;
	scanf("%d%d\n",&n,&m);
	char ls[1000];
	for(i=1;i<=n;i++)
	{
		gets(ls);
		for(j=1;j<=m;j++)
		{
			a[i][j]=ls[j-1]-'0';
		}
	}
	book[1][1]=1;
	p1[top]=1;
	p2[top]=1;
	p3[top]=1;
	
	
	
	
	dfs(1,1,1);
	
	if (flag == 1)
	{
		for (i = 1; i < top; i++)
		{
			printf("(%d,%d,%d)", p1[i], p2[i], p3[i]);
			
		}
		printf("(%d,%d,%d)", n, m, 0);
	}
	else
	{
	}
	return 0;
	
}


