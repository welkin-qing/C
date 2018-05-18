#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#define    MAX       20   //图中顶点数的最大值
#define    MAXedg   30   //图中边数的最大值  

typedef struct edgenode
{
	 int  adjvex;    //临接点序号
	 int  length;    //道路长度
	 char info[20];  //景点名称
	 char info2[100];    //景点详细信息
	 struct edgenode *next;
}edgenode, *Node ;   
typedef struct
{
	 char  data[20];    //存储景点的名称.
	 char  str[100];    //具体的介绍此景点
	 struct edgenode *link;      //指向下一个景点
}vexnode;                     //景点及其信息.

typedef  struct Edge
{
	 int lengh;   //边的权值，表示路径长度
	 int ivex, jvex;  //边的两端顶点号
	 struct Edge *next;  //指向下一条边
} EdgeType;   //边及其信息

typedef struct 
{
	 int  num;   //顶点编号,没有使用。
	 char data[20];  //顶点名称
} vertex;

typedef struct
{
	 vertex vexs[MAX];           //顶点集合
	 int    edges[MAX][MAX];  //临街矩阵
}adjmax; 

FILE *fp;   //文件的读取


void map()
{
	printf("|                           校 园 景 点                     |\n");
	printf("|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|\n");
	printf("|                                             ----11超市----|\n");
	printf("| |        ----|公寓|----               |                   |\n");
	printf("| |                                     | ----7 旭日苑----  |\n");
	printf("| |    |==================|             |      12公寓       |\n");
	printf("| |    |                  |             | -- -- - -- |      |\n");
	printf("| |    |  操       场     |             |            |      |\n");
	printf("| |    |                  |             | --9操场--- |      |\n");
	printf("| |    |==================|             |            |      |\n");
	printf("| |                      ----11体育馆 --|            |      |\n");
    printf("| |                                     |            |10美广|\n");
	printf("   —— —— ——东门  —— —— ——   |            |      |\n");
    printf("|                                       |  --  -- -- |      |\n");
	printf("|-- -- 6 花园   -- -- 4图书馆 -- -- --  |                   |\n");
	printf("|                     |     |           |                   |\n");
	printf("|                     |  乐 |           | -5实验楼-|========|\n");
	printf("|                     |  水 |           |          | 8银   =|\n");
	printf("|                     |     |           |          |  杏   =|\n");
	printf("|- -- -- 3大活 - -- --|  大 |--  --  -- |          |  林   =|\n");
	printf("|                     |  道 |           | -1教学楼-|========|\n");
	printf("|                     |     |           |                   |\n");
	printf("|------|行政楼| ----------------------- | ------------------|\n");
    printf("|                                                           |\n");
	printf("|-_-_-_-_-_-_--_-__-_-_-|| 2校门 ||_-_-_-_-_-_-_-_-_-_-_-_-_|\n");
}

void dengdai()//等待返回界面
{
	int i;

	for(i=0;i<6;i++)
	{
		printf("·");
		Sleep(300);
	}
	printf("\n");
}


void clrscr() //清屏
{
	system("cls");
}

void creatgraph(vexnode g[],int *n,int *b, EdgeType e[],adjmax *adj) //利用邻接表，创建校园图
{
	 int i,j,s,d,len;
	 struct edgenode *p,*q;     //定义图的结构体 
	 if((fp = fopen("file.txt","r")) == NULL)  //打开文件
	 {
		printf("文件打开错误！\n");
		getchar();
		exit(0);
	 }
	 fscanf(fp,"%d %d\n",n,b);   //读入景点个数和边数
	 for(i = 1; i <= *n; i++)     //读入景点名称和详细介绍信息
	 {
		 fscanf(fp,"%s %s\n",&g[i].data,&g[i].str);
		strcpy(adj->vexs[i].data,g[i].data);
		g[i].link = NULL;   //初始化
	 }
	 for(i = 1; i <= *n; i++)    //为邻接矩阵中的权值赋初值1000
	 {
		for(j = 1; j <= *n; j++)
		{
			adj->edges[i][j] = 1000;  //初始值为1000，所以在佛洛依德算法中就没定义最大值！   
		 }
	 }
	 for(i = 1; i <= *b; i++)   //输入道路信息
	 {  
		fscanf(fp,"%d %d %d\n",&e[i].lengh,&e[i].ivex,&e[i].jvex);  //读入道路长度和起始点
		s = e[i].ivex;    //s是起点，d是终点。
		d = e[i].jvex;
		len = e[i].lengh;
		adj->edges[s][d] = e[i].lengh;   //为邻接矩阵中相应的边赋值
		adj->edges[d][s] = e[i].lengh;
		p = (Node)malloc(sizeof(edgenode));   //申请一个弧节点。
		p->next = NULL;
		q = (Node)malloc(sizeof(edgenode));
		q->next = NULL;
		p->adjvex = d;     // 弧p指向的定点
		p->length = len;
		strcpy(p->info,g[d].data); //为景点赋名称
		strcpy(p->info2,g[d].str); //为景点赋介绍信息
		q->adjvex = s;      // 弧q指向的定点 
		q->length = len;
		strcpy(q->info,g[s].data);  //为景点赋名称
		strcpy(q->info2,g[s].str);  //为景点赋介绍信息
		p->next = g[s].link;   //头插法建立邻接表
		g[s].link = p;
		q->next = g[d].link;
		g[d].link = q;
	 }
	 printf("恭喜你，校园旅游图已经建立!");
	 getchar();
} 
 
void save (vexnode g[],int *n,int *b, EdgeType e[])

{

	int i;
	if((fp=fopen ("file.txt","w"))==NULL)
	{
		printf ("对不起，文件打开错误!");
		getchar ();
		exit(0);
	}
	fprintf(fp,"%d %d\n",*n,*b); 
	for(i=1;i<=*n;i++)
	{
		fprintf (fp,"%s %s\n",g[i].data,g[i].str);
	}
	for(i = 1; i <=*b; i++)   //输入道路信息
	{  
		fprintf(fp,"%d %d %d\n",e[i].lengh,e[i].ivex,e[i].jvex);  //读入道路长度和起始点
	}
	fclose (fp);
	printf("文件存储成功");
  	dengdai();

}

void travgraph(vexnode g[],int n,adjmax adj)  //查找指定景点信息
{
	 int i = 1,flag = 1,len;  //len存储要查询的景点的序号
	 char ch;
	 edgenode  *p;
	 printf("请输入您要查询的景点序号:\n");
	 scanf("%d",&len);
	 getchar();
	 while(i <= n)    //遍历邻接表
	 {
		p = g[i].link;
		if(i == len && flag == 1)  
		{
		   printf("此景点的名称是: %s\n",g[i].data);
		   printf("此景点的介绍是: %s\n",g[i].str);   
		   printf("是否继续? Y/N\n");
		   scanf("%c",&ch);
		   getchar();
		   if(ch == 'Y' || ch == 'y')  //继续
		   {
				flag = 1;
				i = 1;
				printf("请输入您要查询的景点序号:\n");
				scanf("%d",&len);
				getchar();
		   }
		   else
			flag = 0;   //不继续了
		 }
		  else
		   i++;
	 }
}

void travgraph1(vexnode g[],int n,adjmax adj)  //查找所有景点信息
{
	 int i = 1;  //len存储要查询的景点的序号
	 edgenode  *p;
	 while(i <= n)    //遍历邻接表
	 {
		 p = g[i].link;
		 printf("第%d景点的名称是: %s\n",i,g[i].data);
		 printf("景点的介绍是: %s\n",g[i].str); 
		 i++;
	 }
}

void xiugai(vexnode g[],int n,int b,adjmax adj,EdgeType e[])  //查找指定景点信息
{
	 int i = 1,flag = 1,len;  //len存储要修改的景点的序号
	 char ch;
	 char f[30];
	 edgenode  *p;
	 printf("请输入您要修改的景点序号:\n");
	 scanf("%d",&len);
	 getchar();
	 while(i <= n)    //遍历邻接表
	 {
		  p = g[i].link;
		  if(i == len && flag == 1)  
		  {
			   printf("此景点的名称是: %s\n",g[i].data);
			   printf("修改为：\n");
			   scanf("%s",f);
			   strcpy(g[i].data ,f);
			   printf("此景点的介绍是: %s\n",g[i].str);  
			   printf("修改为：\n");
			   scanf("%s",f);
			   strcpy(g[i].str,f);
			   printf("是否继续? Y/N\n");
			   scanf("%c",&ch);
				getchar();
			   if(ch == 'Y' || ch == 'y')  //继续
			   {
					flag = 1;
					i = 1;
					printf("请输入您要修改的景点序号:\n");
					scanf("%d",&len);
					getchar();
			   }
			   else
			   {
					flag = 0;
					save(g,&n,&b,e);//不继续了
			   }
		  }
		  else
			i++;
	 }
}

void zengjia(vexnode g[],int *n,int *b,adjmax *adj,EdgeType e[])  //查找指定景点信息
{
	 int i = 1,flag = 1,len; 
	 int num,bian,j,s,d;//len存储要修改的景点的序号
	 struct edgenode  *p,*q;
	 printf("请输入您要增加的景点的个数 边数中加用空格隔开:\n");
	 scanf("%d %d",&num,&bian);
	 getchar();
	 *n=*n+num;
	 *b=*b+bian;//读入景点名称和详细介绍信息
	 for(i=(*n-num)+1;i<=*n;i++)
	{
	   printf("请输入景点的名称和经典的介绍，中间用空格隔开\n");
	   scanf("%s %s",&g[i].data,&g[i].str);
	   getchar();
	   strcpy(adj->vexs[i].data,g[i].data);
	   g[i].link = NULL;   //初始化
	 }
	 for(i=(*n-num)+1;i<=*n;i++)    //为邻接矩阵中的权值赋初值1000
	{
		for(j=(*n-num)+1;j<=*n;j++)
		{
			 adj->edges[i][j] = 1000;  //初始值为1000，所以在佛洛依德算法中就没定义最大值！   
		}
	 }
	 for(i =( *b-bian)+1; i <=*b; i++)   //输入道路信息
	 {  
		  printf("请输入道路长度(权值)，起始点，和终止点用空格隔开\n");
		  scanf("%d %d %d",&e[i].lengh,&e[i].ivex,&e[i].jvex); 
		  getchar();//读入道路长度和起始点
		  s = e[i].ivex;    //s是起点，d是终点。
		  d = e[i].jvex;
		  len = e[i].lengh;
		  adj->edges[s][d] = e[i].lengh;   //为邻接矩阵中相应的边赋值
		  adj->edges[d][s] = e[i].lengh;
		  p = (Node)malloc(sizeof(edgenode));   //申请一个弧节点。
		  p->next = p;
		  q = (Node)malloc(sizeof(edgenode));
		  q->next = NULL;
		  p->adjvex = d;     // 弧p指向的定点
		  p->length = len;
		  strcpy(p->info,g[d].data); //为景点赋名称
		  strcpy(p->info2,g[d].str); //为景点赋介绍信息
		  q->adjvex = s;      // 弧q指向的定点 
		  q->length = len;
		  strcpy(q->info,g[s].data);  //为景点赋名称
		  strcpy(q->info2,g[s].str);  //为景点赋介绍信息
		  p->next = g[s].link;   //头插法建立邻接表
		  g[s].link = p;
		  q->next = g[d].link;
		  g[d].link = q;
	 }
	 save(g,n,b,e);
	 printf("增添新的路径成功");
 	 dengdai();
 }


void shanchu(vexnode g[],int *n,int *b,adjmax *adj,EdgeType e[])
{
	 int i = 1,flag = 1,len; //len存储要修改的景点的序号
	 int num,bian,j,s,d,x1,y1;
	 struct edgenode  *p,*q;
	 printf("请输入您要删除的景点的代号和所相连的路径号:\n");
	 scanf("%d %d",&num,&bian);
	 getchar();
	 *n=*n-1;
	 *b=*b-bian;//读入景点名称和详细介绍信息
	for(i=num;i<=*n;i++)
	{
		strcpy(g[i].data ,g[i+1].data);
		strcpy(g[i].str  ,g[i+1].str );
		getchar();
	}

	printf("请输入道路起 始点，用空格隔开\n");
	scanf("%d %d",&x1,&y1); 
	getchar();
	for(j=1;j<=(*b+bian);j++)
	{
	   if(e[j].ivex ==x1&&e[j].jvex ==y1)
		   break;
	}
	for(i =j; i <=*b; i++)   //输入道路信息
	{   
		e[i].lengh=e[i+1].lengh;
		e[i].ivex=e[i+1].ivex ;
		e[i].jvex=e[i+1].jvex ;
		s = e[i+1].ivex;    //s是起点，d是终点
		d = e[i+1].jvex;
		len = e[i+1].lengh;
		adj->edges[s][d] = e[i+1].lengh;   //为邻接矩阵中相应的边赋值
		adj->edges[d][s] = e[i+1].lengh;
		p = (Node)malloc(sizeof(edgenode));   //申请一个弧节点。
		p->next = p;
		q = (Node)malloc(sizeof(edgenode));
		q->next = NULL;
		p->adjvex = d;     // 弧p指向的定点
		p->length = len;
	    strcpy(p->info,g[d].data); //为景点赋名称
	    strcpy(p->info2,g[d].str); //为景点赋介绍信息
	    q->adjvex = s;      // 弧q指向的定点 
	    q->length = len;
	    strcpy(q->info,g[s].data);  //为景点赋名称
	    strcpy(q->info2,g[s].str);  //为景点赋介绍信息
	    p->next = g[s].link;   //头插法建立邻接表
	    g[s].link = p;
	    q->next = g[d].link;
	    g[d].link = q;
	}
	save(g,n,b,e);
	printf("删除路径成功");
 	dengdai();
}
	

void shanchulujing1(vexnode g[],int *n,int *b,adjmax *adj,EdgeType e[])
{
	int i = 1,flag = 1,len;   //len存储要修改的景点的序号
	int h;
	int num,j,s,d,x1,y1,f;
	struct edgenode  *p,*q;
	printf("删除点 路径个数:\n");
	scanf("%d %d",&num,&f);
	getchar();
	*n=*n-1;//读入景点名称和详细介绍信息
	for(h=0;h<f;h++)
	{
 
	   for(i=num;i<=*n;i++)
	   {
		  strcpy(g[i].data,g[i+1].data);
		  strcpy(g[i].str,g[i+1].str );
		  getchar();
	   }
	   printf("请输入道路起 始点，用空格隔开\n");
	   scanf("%d %d",&x1,&y1); 
	   getchar();
	   *b=*b-1;
	   for(j=1;j<=(*b+1);j++)
	   {
		   if(e[j].ivex ==x1&&e[j].jvex ==y1)
			   break;
	   }
	  for(i =j; i <=*b; i++)   //输入道路信息
	  {   
		  e[i].lengh=e[i+1].lengh;
		  e[i].ivex=e[i+1].ivex ;
		  e[i].jvex=e[i+1].jvex ;
		  s = e[i+1].ivex;    //s是起点，d是终点。
		  d = e[i+1].jvex;
		  len = e[i+1].lengh;
		  adj->edges[s][d] = e[i+1].lengh;   //为邻接矩阵中相应的边赋值
		  adj->edges[d][s] = e[i+1].lengh;
		  p = (Node)malloc(sizeof(edgenode));   //申请一个弧节点。
		  p->next = p;
		  q = (Node)malloc(sizeof(edgenode));
		  q->next = NULL;
		  p->adjvex = d;     // 弧p指向的定点
		  p->length = len;
		  strcpy(p->info,g[d].data); //为景点赋名称
		  strcpy(p->info2,g[d].str); //为景点赋介绍信息
		  q->adjvex = s;      // 弧q指向的定点 
		  q->length = len;
		  strcpy(q->info,g[s].data);  //为景点赋名称
		  strcpy(q->info2,g[s].str);  //为景点赋介绍信息
		  p->next = g[s].link;   //头插法建立邻接表
		  g[s].link = p;
		  q->next = g[d].link;
		  g[d].link = q;
	  }
	 save(g,n,b,e);
	 num=*n;
	}
	printf("删除路径成功");
 	dengdai();
}
  

void Find_way(vexnode g[],EdgeType e[])  //查询道路信息
{
	 int i;  //要查询的道路序号
	 char ch = 'a';  //继续与否
	 do 
	 {
		  printf("请输入您要查询的道路序号:\n");
		  scanf("%d",&i);
		  getchar();
		  printf("此道路长度是:%d米\n",e[i].lengh);
		  printf("此道路连接的两个景点是:%s—%s\n",g[e[i].ivex].data,g[e[i].jvex].data);
		  printf("是否要继续查询(Y/N)?\n");
		  scanf("%c",&ch);
	 } while(ch == 'Y' || ch == 'y');
}


void Find_way1(vexnode g[],EdgeType e[],int *b)  //查询道路所有信息
{
	 int i=1;  
	 do 
	 {
		  printf("第%d道路长度是:%d米\n",i,e[i].lengh);
		  printf("此道路连接的两个景点是:%s—》%s\n",g[e[i].ivex].data,g[e[i].jvex].data);
		  i++;
	 } while(i<=*b);
	 printf("路径输出完成");
	 dengdai();
	 getchar();
}


 

void Ppath(int path[][MAX],int i,int j,vexnode g[])  
{
	 int k;
	 k = path[i][j];  //记录最后一次最短路径的节点数
	 if(k == -1)
		return;
	 Ppath(path,i,k,g);  //依次向前一个最短路径节点递推
	 printf("%s-->",g[k].data);
	 Ppath(path,k,j,g);  //依次向前一个最短路径节点递推
}

 

void Dispath(int A[][MAX],int path[][MAX],int n,vexnode g[])
{
	 int i,j;
	 int a,b;     //a：起始景点序号，b：终止景点序号。
	 printf("请输入您要查询的起始景点和终止景点序号（逗号隔开）:\n");
	 scanf("%d,%d",&a,&b);
	 for(i = 1; i <= n; i++)
	 {
		for(j = 1; j <= n; j++)
		{
			if(A[i][j] != 1000 && A[i][j] != 0 && i == a && j == b)
			{
				printf("从%s-->%s最短路径顺序为:  ",g[a].data,g[b].data);
				printf("%s -->",g[a].data);
				Ppath(path,a,b,g);
				printf("%s",g[b].data);
				printf("\n路径长度为: %d\n",A[i][j]);
			}
		 }
	 }
}


void Floyd(adjmax adj,int n,vexnode g[])  //计算所有两个景点间最短路径
{
	 int A[MAX][MAX],path[MAX][MAX];  //A是路径长度，path是路径。
	 int i,j,k;
	 for(i = 1; i <= n; i++)   //初始化
	 {
		for(j = 1; j <= n; j++)
		{
		   A[i][j] = adj.edges[i][j]; //i j之间长度
		   if(i == j)
		   {
				A[i][j] = 0;
		   }
		   path[i][j] = -1;  //初始化
		}
	 }
	 for(k = 1; k <= n; k++)
	 {
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(A[i][j] > (A[i][k] + A[k][j]))  
				{
				 A[i][j] = A[i][k]+A[k][j];  //修改最短路径长度值
				 path[i][j] = k;   //将最短路径的节点号保存
				}
			}
		}
	 }
	Dispath(A,path,n,g);   //用户输入，查找任意两个景点间的最短路径。
}


void Deep_Find_View(vexnode g[],int v,int n,int visted[])  //深度优先递归调用遍历,v起始顶点。
{ 
	 edgenode *p;
	 int flag = 0;
	 if(flag == 0 && visted[v] == 0)
	 {
		  printf("%s",g[v].data);
		  flag = 1;
		  visted[v] = 1;
	 }
	 p = g[v].link;  
	 while(p != NULL)
	 {
		  if(visted[p->adjvex] == 0)  //未被访问，则访问。
		  {
			   printf("—>%s",p->info);
			   visted[p->adjvex] = 1;
			   Deep_Find_View(g,p->adjvex,n,visted);  //递归调用
		  }
		  p = p->next;
	 }
}
void bianli(int n,vexnode g[])  //深度递归遍历，找出参观全部景点的最佳路线。
{
	 int i,v;
	 int visted[MAX];  //访问标志数组
	 for(i = 1; i <= n; i++)  
	 {
		visted[i] = 0;  //为visited[]数组赋初值,0表示没访问。
	 }
	 printf("请输入起始景点:\n");
	 scanf("%d",&v);
	 printf("这条路是: ");
	 Deep_Find_View(g,v,n,visted);
}

int main(void)
{
	 int n=0,b=0; //景点数目              
	 vexnode  g[MAX];   //保存顶点及其信息
	 EdgeType e[MAXedg];  //保存边及其信息
	 adjmax adj;    //保存边和定点
	 char choice = 'x';
	 while(1)
	 {
		 clrscr();
		 map();
		 printf("\n\t\t┏━━━━━━━━━━━━━━━┑ ");
		 printf("\n\t\t┃       校园导游系统           ┃ ");
		 printf("\n\t\t┗━━━━━━━━━━━━━━━┛ ");
		 printf("\n\t\t┏━━━━━━━━━━━━━━━┑ ");
		 printf("\n\t\t┃ 1. 文件读入并创建校园图      ┃ ");
		 printf("\n\t\t┃ 2. 查询所有景点详细信息      ┃ ");
		 printf("\n\t\t┃ 3. 查询景点详细信息          ┃ ");
		 printf("\n\t\t┃ 4. 查询道路详细信息          ┃ ");
		 printf("\n\t\t┃ 5. 查询所有道路详细信息      ┃ ");
		 printf("\n\t\t┃ 6. 查找两景点间最短路径      ┃ ");
		 printf("\n\t\t┃ 7. 查找最佳参观路线          ┃ ");
		 printf("\n\t\t┃ 8. 修改景点信息              ┃ ");
		 printf("\n\t\t┃ 9. 增加景点，路线            ┃ ");
		 printf("\n\t\t┃ a. 删除景点，路线            ┃ ");
		 printf("\n\t\t┃ b. 查找两个景点的所有路径    ┃ ");
		 printf("\n\t\t┃ c. 查找两个景点的最优路径    ┃ ");
		 printf("\n\t\t┃ 0. 退出                      ┃ ");
		 printf("\n\t\t┃ Write By Edvis@2014/12/09    ┃ ");  
		 printf("\n\t\t┗━━━━━━━━━━━━━━━┛ \n");
		 printf("请输入(0-c):\n ");
		 choice = getchar();
		 switch(choice)
		 {
			case '1':
				clrscr();
				creatgraph(g,&n,&b,e,&adj);//创建图(景点，景点数，边，边和景点)
				printf("\n按任意键返回");
				dengdai();
				getchar();  
				break;
			case '2':
				clrscr();
				map();
				travgraph1(g,n,adj);//查找所有景点信息（景点，景点数，边和景点）
				getchar();
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '3':
				clrscr();
				map();
				travgraph(g,n,adj);//查找指定景点信息（景点，景点数，边和景点）
				getchar();
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '4':   
				clrscr();
				map();
				Find_way(g,e);  //查询道路信息（景点，边）
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '5':   
				clrscr();
				map();
				Find_way1(g,e,&b);  //查询所有道路信息（景点，边）
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '6':
				clrscr();
				map();
				Floyd(adj,n,g); //查找两个景点间最短路径（边和景点，景点数，景点）
				getchar();
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '7':
				clrscr();
				map();
				bianli(n,g);  //找出参观全部景点的最佳路线
				getchar();
				printf("\n");
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '8':
				clrscr();
				map();
				xiugai(g,n,b,adj,e);  //修改景点信息
				getchar();
				printf("\n");
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
	    	case '9':
				clrscr();
				zengjia(g,&n,&b,&adj,e);//增加景点和路线
				getchar();
				printf("\n");
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case 'a':
				clrscr();
				shanchulujing1(g,&n,&b,&adj,e);  //删除景点和路线
				getchar();
				printf("\n");
				printf("\n按任意键返回");
				dengdai();
				getchar(); 
				break;
			case '0': 
				clrscr();
				printf("\n按任意键退出");
				dengdai();
				getchar();
     			exit(0);
				break;
	    	default:
				printf("\n输入错误,请重新输入:\n");
				getchar(); 
				break;
		 }
	  } 
	  return 0;
}