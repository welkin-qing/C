/*
	函数/变量 除了第一个单词外首字母大写。
	宏字母大写
	数据类型名(如 Data)所有单词首字母大写 
	//版本2
	比上一版本在 Data结构体里多加了name成员，txt格式也多加了name成员 
	多加了全局变量v，表示节点的个数 
	新增了函数 
*/
typedef struct		//节点的数据结构，distence包含了已经压缩了的邻接矩阵的结构 
{
	int x,y;
	char *ifo;
	char *name;
	int *distence;		//左下邻接矩阵 
}Data;
Data *nodeArr;			//与宏 DIS 配合
int v=-1;					//节点个数 
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define PAU system("pause")								//暂停 
#define CLS system("cls")								//清屏 
#define NL printf("\n")									//换行 
#define MIN(a,b) ((a)>(b)?(b):(a))						//取最小值 
#define MAX(a,b) ((a)<(b)?(b):(a))						//取最大值 
#define DIS(m,n) nodeArr[MAX(m,n)].distence[MIN(m,n)]	//求m，n之间的距离
#define MLC(n,t) (t*)malloc(sizeof(t)*(n))				//申请n*sizeof(t)个空间 

#define kup 72
#define kdown 80
#define kleft 75
#define kright 77
#define kEsc 27
#define MAXLEN 9999999
#define MAXVEX 50
#define INFINITY 32767 
int book[500]={0}; 
/*
	功能：让用户确认操作，
		如果用户输入y，返回1，输入n返回0，else继续输入 
		eg. if(confirm("确定要退出吗"))
				return; 
	参数：将会把该参数指向的字符串打印在屏幕上 
*/
int confirm(char const *txt)
{
	printf(txt);
	printf("(按y确定，n取消)\n");
	while(1)
	{
		char ch=getch();
		if(ch=='y' || ch=='Y')
			return 1;
		if(ch=='N' || ch=='n')
			return 0;
	}
}


/*
	·功能
		读取文件内容到数组 
	·参数
		<1>文件名（相对路径或绝对路径）
		<2>指向盛放数据数组头指针的指针，该数组的长度是动态的。
	·返回值：返回读取的节点的个数，若读取失败则返回-1 
	·举例：
		Data *nodeArr;				//盛放节点的数组头指针 
		load("1.txt",&nodeArr); 	//将1.txt的内容读取到nodeArr中 
*/
int load(const char *fileName,Data **nodeArr)
{
	FILE *fp;
	fp=fopen(fileName,"rt");
	if(fp==NULL)
		return -1;
	int n;
	fscanf(fp,"%d",&n);		//第一个是节点的个数 
	int i;
	char temp[501];			//ifo不能超过500个字符长度	 
	*nodeArr=MLC(n,Data); 
	for(i=0;i<n;i++)		//接下来n个包含：x y ifo 
	{			
		fscanf(fp,"%d %d %s",&(*nodeArr)[i].x,&(*nodeArr)[i].y,temp);
		(*nodeArr)[i].name=MLC(strlen(temp)+1,char);
		strcpy((*nodeArr)[i].name,temp);
		fscanf(fp,"%s",temp);
		(*nodeArr)[i].ifo=MLC(strlen(temp)+1,char);
		strcpy((*nodeArr)[i].ifo,temp);
	}
			//邻接矩阵
	int j;
	for(i=0;i<n;i++)
	{
		(*nodeArr)[i].distence=MLC(i+1,int);	//申请左下邻接矩阵的空间 
		for(j=0;j<i+1;j++)
		{
			(*nodeArr)[i].distence[j]=MAXLEN;		//init
		}
	}
	int a=1,b=1,d;
	for(i=0;;i++)
	{
		fscanf(fp,"%d %d %d",&a,&b,&d);
		if((a||b||d)==0)
			break;				//结束条件为 0 0 0 
		a-=1;
		b-=1; 
		(*nodeArr)[MAX(a,b)].distence[MIN(a,b)]=d;
	}
	

	
	fclose(fp);
	return n;
}



/*
	·功能
		求所有路之间的最短路（包含起点和终点） ,若遇到最短路相同的多个选择，则优先选择路过节点多的路。 
	·参数
		<1>节点数据信息数组， 
		<2>节点个数 
		<3>起点序号 
		<4>终点序号
		<5>存放保存最短路的数组首地址指针。请保证result[]的空间足够大 
		<6>存放result路径里面有多少个节点 
	·返回值
		返回最短路长度，若起点和终点不联通，返回-1
	· 例如
		int rn;
		len=minDis(nodeArr,n,0,2,result,&rn);    结果result表示从0到2最短路，len为最短路径 
*/

int minDis(Data *nodeArr,int v,int a,int b,int result[],int *rn)
{
	/*
		书上使用的二维数组存放路径，需要n方的空间复杂度，此处不必要，
		使用father指针的方式记录最短路径，复杂度为n ，且函数只要找到终点即终止。 
	*/
	if(a==b)	 
	{
		result[0]=a;						//init
		*rn=1;
		return 0;
	}
	typedef struct
	{
		int n;
		int father;
		int value;
	}Latest;
	int i,j;
	char *temp=MLC(v,char);	//记录点是否入队。 
	for(i=0;i<v;i++)
	{
		temp[i]=0;							//init
	}
	Latest *vex=MLC(v,Latest);
	for(i=0;i<v;i++)
	{
		vex[i].n=0;
		vex[i].value=MAXLEN;				//init
	}
	vex[a].value=0;
	int flag=1;
	int min,mink=a;
	for(i=0;i<v;i++)	//最大循环v-1次 
	{
		temp[mink]=1;
		if(mink==b)
		{
			flag=0;
			break;
		}
		for(j=0;j<v;j++)
		{
			if(DIS(j,mink)<MAXLEN && temp[j]==0)	//往外扩 
			{
				if(vex[mink].value+DIS(mink,j)<vex[j].value)
				{
					vex[j].value=vex[mink].value+DIS(mink,j);
					vex[j].father=mink;
					vex[j].n=vex[mink].n+1;
				}
			}
		}
		//更新距离最短的路
		min=MAXLEN;
		for(j=0;j<v;j++)
		{
			if(vex[j].value<min && temp[j]==0)
			{
				min=vex[j].value;
				mink=j;
			}
		}
		
	}
	if(flag)	//没找到 
	{
		return -1;
	}
	//
	j=b;
	for(i=vex[b].n;i>=0;i--)
	{
		result[i]=j;
		j=vex[j].father;
	}
	result[0]=a;
	*rn=vex[b].n+1;
	return vex[b].value;
} 


//所有路径dfs
int r[500]={0};//
int rp=-1;
void DFSs(int m,int n)
{
	
	//int static book[500]={0};
	int i;
	rp++;
	r[rp]=m;
	if(m==n)
	{
		//printf("找到！\n");
		for(i=0;i<=rp;i++)
		{
		
			printf("%d.%s",r[i]+1,nodeArr[r[i]].name);
			if(i<rp)
				printf("-->");
		}
		rp--;
		NL;
		return;
	}
	book[m]=1;
	for(i=0;i<v;i++)
	{
		if(DIS(i,m)!=MAXLEN && book[i]==0)
		{
			DFSs(i,n);
		}
	}
	//printf("\n");
	book[m]=0;
	rp--;
	return;
}
void DFS(int m,int n)
{
	int i;
	for(i=0;i<v;i++)
	{
		book[i]=r[i]=0;
	}
	rp=-1;
	DFSs(m,n);
	return;
}
//简单路径bfs
void BFS(int m,int n)
{
	int line[v];
	int book[500]={0};
	int father[v];
	int head=0,end=1;
	int i;
	line[0]=m;
	book[0]=1;
	while(1)
	{
		for(i=0;i<v;i++)
		{
			if(DIS(i,line[head])!=MAXLEN && book[i]==0)
			{
				book[i]=1;
				line[end++]=i;
				father[i]=line[head];
				if(i==n)
				{
					int j=n;
					while(1)
					{
						printf("%d.%s",j+1,nodeArr[j].name);
						if(j==m)
						{
							break;
						}
						j=father[j];
						printf("-->");
					}
					printf("\n");
					return;
				}
			}
		}
		head++;
		if(head==end)
		{
			return;
		}
	}
} 
//删除函数 
int ifodelete(int a)
{
	
}
 
//prim 求最小生成树(最佳布网方案)
void Prim(Data *nodeArr)
{
	int start;
	int F[MAXVEX][MAXVEX];
	int distance=0;
	printf("\n\t\t\t\t---构建最小生成树---");
	printf("\n");
	printf("\n\t\t\t\t请输入初始结点：\n\t\t\t\t");
	scanf("%d",&start);
	printf("\n\t\t\t\t") ;
	getchar();
	struct 
	{
		int adjvex;
		int lowcost;
	}closedge[MAXVEX];
	int min,m=0;
	closedge[start].lowcost=0;
	for(int i=1;i<=v;i++)
		if(i!=start)
		{
			closedge[i].adjvex=start;
			closedge[i].lowcost=F[start][i];
		}
	for(int k=1;k<=v-1;k++)
	{
		min=INFINITY;int j;
		for(j=1;j<=v;j++)
		{
			if(closedge[j].lowcost!=0&&closedge[j].lowcost<min&&closedge[j].lowcost!=INFINITY)
			{
				m=j;
				min=closedge[j].lowcost;
			}
		}
		printf("(%d,%d)	权值为%d\n\t\t\t\t",closedge[m].adjvex,m,min);	
//		printf("");
		closedge[m].lowcost=0;
		for(int i=1;i<=v;i++)
		{
			if(i!=m&&DIS(m,i)<closedge[i].lowcost&&DIS(m,i)!=INFINITY)
			{
				closedge[i].lowcost=DIS(m,i);
				closedge[i].adjvex=m;
			}
		}

	}
	getchar();
}

#ifndef wbt 	//调试代码，不用删掉 
int func1()
{
	printf("1\n");
	PAU;
	return 0;
}
int func2()
{
	printf("2\n");
	PAU;
	return 0;
}
		
int main()
{
	int a,b;
	printf("\n***=================以下为调试输出：================***\n");
	v=load("1.txt",&nodeArr);
	//scanf("%d %d",&a,&b);
	//BFS(a-1,b-1);
	Prim(nodeArr);
	printf("\n***=================以上为调试输出：================***\n");
}
#endif


