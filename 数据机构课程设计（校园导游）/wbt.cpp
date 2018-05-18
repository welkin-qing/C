/*
	����/���� ���˵�һ������������ĸ��д��
	����ĸ��д
	����������(�� Data)���е�������ĸ��д 
	//�汾2
	����һ�汾�� Data�ṹ��������name��Ա��txt��ʽҲ�����name��Ա 
	�����ȫ�ֱ���v����ʾ�ڵ�ĸ��� 
	�����˺��� 
*/
typedef struct		//�ڵ�����ݽṹ��distence�������Ѿ�ѹ���˵��ڽӾ���Ľṹ 
{
	int x,y;
	char *ifo;
	char *name;
	int *distence;		//�����ڽӾ��� 
}Data;
Data *nodeArr;			//��� DIS ���
int v=-1;					//�ڵ���� 
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define PAU system("pause")								//��ͣ 
#define CLS system("cls")								//���� 
#define NL printf("\n")									//���� 
#define MIN(a,b) ((a)>(b)?(b):(a))						//ȡ��Сֵ 
#define MAX(a,b) ((a)<(b)?(b):(a))						//ȡ���ֵ 
#define DIS(m,n) nodeArr[MAX(m,n)].distence[MIN(m,n)]	//��m��n֮��ľ���
#define MLC(n,t) (t*)malloc(sizeof(t)*(n))				//����n*sizeof(t)���ռ� 

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
	���ܣ����û�ȷ�ϲ�����
		����û�����y������1������n����0��else�������� 
		eg. if(confirm("ȷ��Ҫ�˳���"))
				return; 
	����������Ѹò���ָ����ַ�����ӡ����Ļ�� 
*/
int confirm(char const *txt)
{
	printf(txt);
	printf("(��yȷ����nȡ��)\n");
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
	������
		��ȡ�ļ����ݵ����� 
	������
		<1>�ļ��������·�������·����
		<2>ָ��ʢ����������ͷָ���ָ�룬������ĳ����Ƕ�̬�ġ�
	������ֵ�����ض�ȡ�Ľڵ�ĸ���������ȡʧ���򷵻�-1 
	��������
		Data *nodeArr;				//ʢ�Žڵ������ͷָ�� 
		load("1.txt",&nodeArr); 	//��1.txt�����ݶ�ȡ��nodeArr�� 
*/
int load(const char *fileName,Data **nodeArr)
{
	FILE *fp;
	fp=fopen(fileName,"rt");
	if(fp==NULL)
		return -1;
	int n;
	fscanf(fp,"%d",&n);		//��һ���ǽڵ�ĸ��� 
	int i;
	char temp[501];			//ifo���ܳ���500���ַ�����	 
	*nodeArr=MLC(n,Data); 
	for(i=0;i<n;i++)		//������n��������x y ifo 
	{			
		fscanf(fp,"%d %d %s",&(*nodeArr)[i].x,&(*nodeArr)[i].y,temp);
		(*nodeArr)[i].name=MLC(strlen(temp)+1,char);
		strcpy((*nodeArr)[i].name,temp);
		fscanf(fp,"%s",temp);
		(*nodeArr)[i].ifo=MLC(strlen(temp)+1,char);
		strcpy((*nodeArr)[i].ifo,temp);
	}
			//�ڽӾ���
	int j;
	for(i=0;i<n;i++)
	{
		(*nodeArr)[i].distence=MLC(i+1,int);	//���������ڽӾ���Ŀռ� 
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
			break;				//��������Ϊ 0 0 0 
		a-=1;
		b-=1; 
		(*nodeArr)[MAX(a,b)].distence[MIN(a,b)]=d;
	}
	

	
	fclose(fp);
	return n;
}



/*
	������
		������·֮������·�����������յ㣩 ,���������·��ͬ�Ķ��ѡ��������ѡ��·���ڵ���·�� 
	������
		<1>�ڵ�������Ϣ���飬 
		<2>�ڵ���� 
		<3>������ 
		<4>�յ����
		<5>��ű������·�������׵�ַָ�롣�뱣֤result[]�Ŀռ��㹻�� 
		<6>���result·�������ж��ٸ��ڵ� 
	������ֵ
		�������·���ȣ��������յ㲻��ͨ������-1
	�� ����
		int rn;
		len=minDis(nodeArr,n,0,2,result,&rn);    ���result��ʾ��0��2���·��lenΪ���·�� 
*/

int minDis(Data *nodeArr,int v,int a,int b,int result[],int *rn)
{
	/*
		����ʹ�õĶ�ά������·������Ҫn���Ŀռ临�Ӷȣ��˴�����Ҫ��
		ʹ��fatherָ��ķ�ʽ��¼���·�������Ӷ�Ϊn ���Һ���ֻҪ�ҵ��յ㼴��ֹ�� 
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
	char *temp=MLC(v,char);	//��¼���Ƿ���ӡ� 
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
	for(i=0;i<v;i++)	//���ѭ��v-1�� 
	{
		temp[mink]=1;
		if(mink==b)
		{
			flag=0;
			break;
		}
		for(j=0;j<v;j++)
		{
			if(DIS(j,mink)<MAXLEN && temp[j]==0)	//������ 
			{
				if(vex[mink].value+DIS(mink,j)<vex[j].value)
				{
					vex[j].value=vex[mink].value+DIS(mink,j);
					vex[j].father=mink;
					vex[j].n=vex[mink].n+1;
				}
			}
		}
		//���¾�����̵�·
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
	if(flag)	//û�ҵ� 
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


//����·��dfs
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
		//printf("�ҵ���\n");
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
//��·��bfs
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
//ɾ������ 
int ifodelete(int a)
{
	
}
 
//prim ����С������(��Ѳ�������)
void Prim(Data *nodeArr)
{
	int start;
	int F[MAXVEX][MAXVEX];
	int distance=0;
	printf("\n\t\t\t\t---������С������---");
	printf("\n");
	printf("\n\t\t\t\t�������ʼ��㣺\n\t\t\t\t");
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
		printf("(%d,%d)	ȨֵΪ%d\n\t\t\t\t",closedge[m].adjvex,m,min);	
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

#ifndef wbt 	//���Դ��룬����ɾ�� 
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
	printf("\n***=================����Ϊ���������================***\n");
	v=load("1.txt",&nodeArr);
	//scanf("%d %d",&a,&b);
	//BFS(a-1,b-1);
	Prim(nodeArr);
	printf("\n***=================����Ϊ���������================***\n");
}
#endif


