#define wbt 1
#include "wbt.cpp"
#define wq 1
#include "wq.cpp"

int map()
{
	CLS;
	p();
	PAU;
	return 0;
}


int introduction()
{
	int n;
	CLS;
	p();
	printf("查看景点介绍，请输入景点序号:");
	while(scanf("%d",&n),n>v|| n<=0)
	{
		printf("输入错误，序号最大值为%d,最小值为0,请重新输入:\n",v+1);
	}
	//CLS;
	n-=1;
	printf("\n\t\t[%s] 介绍:\n    %s\n\n\n\n\n\n\n",nodeArr[n].name,nodeArr[n].ifo); 
	PAU;
	return 0;
}


int shortest()//求最短路 
{
	int *result=MLC(v,int);
	int rn,len;
	int i;
	int m,n;
	CLS;
	p(); 
	printf("请输入两个节点序号m n，表示求从m到n的最短路：\n");
	while(scanf("%d %d",&m,&n),m>v || n>v || m<=0 || n<=0)
	{
		printf("输入错误，序号最大值为%d,最小值为1,请重新输入:\n",v+1);
	}
	m-=1;
	n-=1; 
	len=minDis(nodeArr,v,m,n,result,&rn);   // 结果result表示从0到2最短路，len为最短路径
//	CLS;
	if(len==-1)
	{
		printf("%d.%s 与 %d.%s 之间没有路。\n",m+1,nodeArr[m].name,n+1,nodeArr[n].name);
		PAU;
		return 0;
	}
	printf("最短路长度为%d米,路径为：\n",len);
	for(i=0;i<rn;i++)
	{
		printf("\t%d.%s\n",result[i]+1,nodeArr[result[i]].name);
		if(i!=rn-1)
		{
			printf("\t↓\n");
		}
	}
	PAU;
	return 0;
}


int reload()
{
	int t=v;
	if(v>0)
	{
		free(nodeArr);
	}
	while((v=load("1.txt",&nodeArr))==-1)
	{
		printf("读入文件失败，请确认文件是否存在且不被占用,");
		if(confirm("是否重试？"))
			continue;
		else
			return 2;		//退出程序 
	}
	if(t!=-1)
	{
		printf("重新载入...成功！\n");
		PAU;
	}
	return 0;
}


int quit()
{
	int t;
	v=load("1.txt",&nodeArr);
	if(v==-1)
	{
		printf("载入失败");
	}
	if(confirm("确定要退出吗？"))
		return 1;
	return 0;
}

int main()
{
	reload();
	int (*func[])()={map,introduction,shortest,reload,quit};
	char const *list[]={"查看地图","查询景点介绍","查询两点间最短路","重新读入文件","退出"};			//菜单列表 
	menuEditor(list,5,func,"开始菜单,已读入%d个节点信息\n\n====================校园导航系统====================\n",v,"====================西安邮电大学====================\n",0);
}

