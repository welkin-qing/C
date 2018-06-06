#define wbt 1
#define wq 1
#include "wbt.cpp"
#include"wq.cpp"
int panduan1(char s[])
{
	if(strlen(s)==1)
	{
		if(strcmp(s,"1")==0||strcmp(s,"2")==0||strcmp(s,"3")==0||strcmp(s,"4")==0||
		strcmp(s,"5")==0||strcmp(s,"6")==0||strcmp(s,"7")==0)
		return 1;
		else return 0;
	}
	else return 0;
}
char panduan2(char s[])
{
	char c;
	c = s[0];
	return c;
}

int main()
{
	int m,n,x;
	char choice[100];
	char c;
	int result[100];
	int len,rn;    //最短路径 
	int ifo;
	int easylen,allen;  //简单路径 
    v=load("1.txt",&nodeArr);
    while((v=load("1.txt",&nodeArr))==-1)
	{
		printf("读入文件失败，请确认文件是否存在且不被占用,");
		if(confirm("是否重试？"))
			continue;
    }
    while(1)
    {
    	system("color 3F");
		printf("\t\t***************************************************************\n");
        printf("\t\t\t******请选择您要实现的功能：（请输入1~5）******\n");
        printf("\t\t\t*******-----1.查看地图-------------------******\n");
        printf("\t\t\t*******-----2.查询景点介绍---------------******\n");
        printf("\t\t\t*******-----3.查询两景点间的简单路径-----******\n");
        printf("\t\t\t*******-----4.查询两景点间的最短路径-----******\n");
        printf("\t\t\t*******-----5.查询两景点间的所有路径-----******\n"); 
        printf("\t\t\t*******-----6.重新读入文件---------------******\n");
        printf("\t\t\t*******-----7.退出-----------------------******\n");
        scanf("%s",choice);
        while(panduan1(choice)==0)
        {
        	printf("ERROR\n");
        	printf("请重新输入！\n");
        	scanf("%s",choice);
		}
		c = panduan2(choice);
        switch(c)
        {
        	case '1':   //查看地图 
        	        system("color 3");
        	 		CLS;
        			printf("\t\t***************************************************************\n");
                    putGraph();
                    printf("\t\t***************************************************************\n");
                    PAU;
                    CLS;
                    break;
        	case '2':   //查询景点介绍 
                    //CLS;
                    system("color F3");
					int n;
                    printf("\t\t\t*******-----查看景点介绍，请输入景点序号(1~16):-----******");
                    while(1)
					{
                        scanf("%d",&n);
                        CLS;
                        if (n>=v|| n<0)
                        {
							printf("\t\t*******-----输入错误，序号最大值为%d,最小值为0,请重新输入:-----******",v);
                        	//PAU;
                       		continue;
                        }
                        break;
                    }
                    
                    printf("·[%s] \n·介绍:\n\t%s\n\n\n",nodeArr[n].name,nodeArr[n].ifo);
                    PAU;
                    CLS;
            		break;
            case '3':  //简单路径bfs
			        printf("\t\t\t*******-----请输入两个景点：m n -----******\n");
					scanf("%d %d",&m,&n);
					if(m<1||n>16||m==n||m<'A'&&n>'z')
			        {
			        	CLS;
			        	printf("\n\n\n\t\t\t\t*******-----输入错误!-----******\n\n\n");
						continue;
					}
					BFS(m-1,n-1); 
					PAU;
                    CLS;
            		break;
        	case '4':  //最短路径 
			        //CLS;
					printf("\t\t\t*******-----请输入两个景点：m n -----******\n\n");
			        scanf("%d %d",&m,&n);
			        if(m<1||n>16||m==n||m<'A'&&n>'z')
			        {
			        	CLS;
			        	printf("\n\n\n\t\t\t\t*******-----输入错误!-----******\n\n\n");
						continue;
					}
			        len=minDis(nodeArr,v,m-1,n-1,result,&rn);
                    printf("\t\t\t*******-----最短路径是：%d-----******\n",len);
                    for(int i=0;i<rn;i++)
                    {
                    	printf("\t%d.%s\n",result[i]+1,nodeArr[result[i]].name);
                    	if(i!=rn-1)
                    		printf("\t   |\n\t   |\n\t   V\n");
					}
                    printf("\n");
                    PAU;
                    CLS;
                    break;
            case '5':  //所有路径 dfs
            	    printf("请输入两个景点：m n\n");
            	    scanf("%d %d",&m,&n);
            	    if(m<1||n>16||m==n||m<'A'&&n>'z')
			        {
			        	CLS;
			        	printf("\n\n\n\t\t\t\t*******-----输入错误!-----******\n\n\n");
						continue;
					}
            	    DFS(m-1,n-1);
            	    PAU;
                    CLS;
            		break;
            	    
        	case '6':  //重新读入 
		   			//CLS;
					free(nodeArr);
					v=load("1.txt",&nodeArr);
        			while((v=load("1.txt",&nodeArr))==-1)
					{
						printf("读入文件失败，请确认文件是否存在且不被占用,");
						if(confirm("是否重试？"))
						continue;
   					}
					printf("读入成功！\n");
					printf("读入%d个信息。",v);
					PAU;
					CLS;
					break;
//			case 7:  //删除景点 
//			        printf("请输入要删除节点的序号：");
//					scanf("%d",&ifo);
//					if(ifo<1||ifo>15)
//					{
//						printf("\t输入错误！\n");
//					}
					 
        	case '7':  //退出 
			  	//	CLS; 
					if(confirm("是否退出？"))
						return 0;
					CLS;
				    break; 	
        }
    }
}





       
