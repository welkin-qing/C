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
	printf("�鿴������ܣ������뾰�����:");
	while(scanf("%d",&n),n>v|| n<=0)
	{
		printf("�������������ֵΪ%d,��СֵΪ0,����������:\n",v+1);
	}
	//CLS;
	n-=1;
	printf("\n\t\t[%s] ����:\n    %s\n\n\n\n\n\n\n",nodeArr[n].name,nodeArr[n].ifo); 
	PAU;
	return 0;
}


int shortest()//�����· 
{
	int *result=MLC(v,int);
	int rn,len;
	int i;
	int m,n;
	CLS;
	p(); 
	printf("�����������ڵ����m n����ʾ���m��n�����·��\n");
	while(scanf("%d %d",&m,&n),m>v || n>v || m<=0 || n<=0)
	{
		printf("�������������ֵΪ%d,��СֵΪ1,����������:\n",v+1);
	}
	m-=1;
	n-=1; 
	len=minDis(nodeArr,v,m,n,result,&rn);   // ���result��ʾ��0��2���·��lenΪ���·��
//	CLS;
	if(len==-1)
	{
		printf("%d.%s �� %d.%s ֮��û��·��\n",m+1,nodeArr[m].name,n+1,nodeArr[n].name);
		PAU;
		return 0;
	}
	printf("���·����Ϊ%d��,·��Ϊ��\n",len);
	for(i=0;i<rn;i++)
	{
		printf("\t%d.%s\n",result[i]+1,nodeArr[result[i]].name);
		if(i!=rn-1)
		{
			printf("\t��\n");
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
		printf("�����ļ�ʧ�ܣ���ȷ���ļ��Ƿ�����Ҳ���ռ��,");
		if(confirm("�Ƿ����ԣ�"))
			continue;
		else
			return 2;		//�˳����� 
	}
	if(t!=-1)
	{
		printf("��������...�ɹ���\n");
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
		printf("����ʧ��");
	}
	if(confirm("ȷ��Ҫ�˳���"))
		return 1;
	return 0;
}

int main()
{
	reload();
	int (*func[])()={map,introduction,shortest,reload,quit};
	char const *list[]={"�鿴��ͼ","��ѯ�������","��ѯ��������·","���¶����ļ�","�˳�"};			//�˵��б� 
	menuEditor(list,5,func,"��ʼ�˵�,�Ѷ���%d���ڵ���Ϣ\n\n====================У԰����ϵͳ====================\n",v,"====================�����ʵ��ѧ====================\n",0);
}

