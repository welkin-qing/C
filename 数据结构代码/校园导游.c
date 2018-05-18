#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#define    MAX       20   //ͼ�ж����������ֵ
#define    MAXedg   30   //ͼ�б��������ֵ  

typedef struct edgenode
{
	 int  adjvex;    //�ٽӵ����
	 int  length;    //��·����
	 char info[20];  //��������
	 char info2[100];    //������ϸ��Ϣ
	 struct edgenode *next;
}edgenode, *Node ;   
typedef struct
{
	 char  data[20];    //�洢���������.
	 char  str[100];    //����Ľ��ܴ˾���
	 struct edgenode *link;      //ָ����һ������
}vexnode;                     //���㼰����Ϣ.

typedef  struct Edge
{
	 int lengh;   //�ߵ�Ȩֵ����ʾ·������
	 int ivex, jvex;  //�ߵ����˶����
	 struct Edge *next;  //ָ����һ����
} EdgeType;   //�߼�����Ϣ

typedef struct 
{
	 int  num;   //������,û��ʹ�á�
	 char data[20];  //��������
} vertex;

typedef struct
{
	 vertex vexs[MAX];           //���㼯��
	 int    edges[MAX][MAX];  //�ٽ־���
}adjmax; 

FILE *fp;   //�ļ��Ķ�ȡ


void map()
{
	printf("|                           У ԰ �� ��                     |\n");
	printf("|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|\n");
	printf("|                                             ----11����----|\n");
	printf("| |        ----|��Ԣ|----               |                   |\n");
	printf("| |                                     | ----7 ����Է----  |\n");
	printf("| |    |==================|             |      12��Ԣ       |\n");
	printf("| |    |                  |             | -- -- - -- |      |\n");
	printf("| |    |  ��       ��     |             |            |      |\n");
	printf("| |    |                  |             | --9�ٳ�--- |      |\n");
	printf("| |    |==================|             |            |      |\n");
	printf("| |                      ----11������ --|            |      |\n");
    printf("| |                                     |            |10����|\n");
	printf("   ���� ���� ��������  ���� ���� ����   |            |      |\n");
    printf("|                                       |  --  -- -- |      |\n");
	printf("|-- -- 6 ��԰   -- -- 4ͼ��� -- -- --  |                   |\n");
	printf("|                     |     |           |                   |\n");
	printf("|                     |  �� |           | -5ʵ��¥-|========|\n");
	printf("|                     |  ˮ |           |          | 8��   =|\n");
	printf("|                     |     |           |          |  ��   =|\n");
	printf("|- -- -- 3��� - -- --|  �� |--  --  -- |          |  ��   =|\n");
	printf("|                     |  �� |           | -1��ѧ¥-|========|\n");
	printf("|                     |     |           |                   |\n");
	printf("|------|����¥| ----------------------- | ------------------|\n");
    printf("|                                                           |\n");
	printf("|-_-_-_-_-_-_--_-__-_-_-|| 2У�� ||_-_-_-_-_-_-_-_-_-_-_-_-_|\n");
}

void dengdai()//�ȴ����ؽ���
{
	int i;

	for(i=0;i<6;i++)
	{
		printf("��");
		Sleep(300);
	}
	printf("\n");
}


void clrscr() //����
{
	system("cls");
}

void creatgraph(vexnode g[],int *n,int *b, EdgeType e[],adjmax *adj) //�����ڽӱ�����У԰ͼ
{
	 int i,j,s,d,len;
	 struct edgenode *p,*q;     //����ͼ�Ľṹ�� 
	 if((fp = fopen("file.txt","r")) == NULL)  //���ļ�
	 {
		printf("�ļ��򿪴���\n");
		getchar();
		exit(0);
	 }
	 fscanf(fp,"%d %d\n",n,b);   //���뾰������ͱ���
	 for(i = 1; i <= *n; i++)     //���뾰�����ƺ���ϸ������Ϣ
	 {
		 fscanf(fp,"%s %s\n",&g[i].data,&g[i].str);
		strcpy(adj->vexs[i].data,g[i].data);
		g[i].link = NULL;   //��ʼ��
	 }
	 for(i = 1; i <= *n; i++)    //Ϊ�ڽӾ����е�Ȩֵ����ֵ1000
	 {
		for(j = 1; j <= *n; j++)
		{
			adj->edges[i][j] = 1000;  //��ʼֵΪ1000�������ڷ��������㷨�о�û�������ֵ��   
		 }
	 }
	 for(i = 1; i <= *b; i++)   //�����·��Ϣ
	 {  
		fscanf(fp,"%d %d %d\n",&e[i].lengh,&e[i].ivex,&e[i].jvex);  //�����·���Ⱥ���ʼ��
		s = e[i].ivex;    //s����㣬d���յ㡣
		d = e[i].jvex;
		len = e[i].lengh;
		adj->edges[s][d] = e[i].lengh;   //Ϊ�ڽӾ�������Ӧ�ı߸�ֵ
		adj->edges[d][s] = e[i].lengh;
		p = (Node)malloc(sizeof(edgenode));   //����һ�����ڵ㡣
		p->next = NULL;
		q = (Node)malloc(sizeof(edgenode));
		q->next = NULL;
		p->adjvex = d;     // ��pָ��Ķ���
		p->length = len;
		strcpy(p->info,g[d].data); //Ϊ���㸳����
		strcpy(p->info2,g[d].str); //Ϊ���㸳������Ϣ
		q->adjvex = s;      // ��qָ��Ķ��� 
		q->length = len;
		strcpy(q->info,g[s].data);  //Ϊ���㸳����
		strcpy(q->info2,g[s].str);  //Ϊ���㸳������Ϣ
		p->next = g[s].link;   //ͷ�巨�����ڽӱ�
		g[s].link = p;
		q->next = g[d].link;
		g[d].link = q;
	 }
	 printf("��ϲ�㣬У԰����ͼ�Ѿ�����!");
	 getchar();
} 
 
void save (vexnode g[],int *n,int *b, EdgeType e[])

{

	int i;
	if((fp=fopen ("file.txt","w"))==NULL)
	{
		printf ("�Բ����ļ��򿪴���!");
		getchar ();
		exit(0);
	}
	fprintf(fp,"%d %d\n",*n,*b); 
	for(i=1;i<=*n;i++)
	{
		fprintf (fp,"%s %s\n",g[i].data,g[i].str);
	}
	for(i = 1; i <=*b; i++)   //�����·��Ϣ
	{  
		fprintf(fp,"%d %d %d\n",e[i].lengh,e[i].ivex,e[i].jvex);  //�����·���Ⱥ���ʼ��
	}
	fclose (fp);
	printf("�ļ��洢�ɹ�");
  	dengdai();

}

void travgraph(vexnode g[],int n,adjmax adj)  //����ָ��������Ϣ
{
	 int i = 1,flag = 1,len;  //len�洢Ҫ��ѯ�ľ�������
	 char ch;
	 edgenode  *p;
	 printf("��������Ҫ��ѯ�ľ������:\n");
	 scanf("%d",&len);
	 getchar();
	 while(i <= n)    //�����ڽӱ�
	 {
		p = g[i].link;
		if(i == len && flag == 1)  
		{
		   printf("�˾����������: %s\n",g[i].data);
		   printf("�˾���Ľ�����: %s\n",g[i].str);   
		   printf("�Ƿ����? Y/N\n");
		   scanf("%c",&ch);
		   getchar();
		   if(ch == 'Y' || ch == 'y')  //����
		   {
				flag = 1;
				i = 1;
				printf("��������Ҫ��ѯ�ľ������:\n");
				scanf("%d",&len);
				getchar();
		   }
		   else
			flag = 0;   //��������
		 }
		  else
		   i++;
	 }
}

void travgraph1(vexnode g[],int n,adjmax adj)  //�������о�����Ϣ
{
	 int i = 1;  //len�洢Ҫ��ѯ�ľ�������
	 edgenode  *p;
	 while(i <= n)    //�����ڽӱ�
	 {
		 p = g[i].link;
		 printf("��%d�����������: %s\n",i,g[i].data);
		 printf("����Ľ�����: %s\n",g[i].str); 
		 i++;
	 }
}

void xiugai(vexnode g[],int n,int b,adjmax adj,EdgeType e[])  //����ָ��������Ϣ
{
	 int i = 1,flag = 1,len;  //len�洢Ҫ�޸ĵľ�������
	 char ch;
	 char f[30];
	 edgenode  *p;
	 printf("��������Ҫ�޸ĵľ������:\n");
	 scanf("%d",&len);
	 getchar();
	 while(i <= n)    //�����ڽӱ�
	 {
		  p = g[i].link;
		  if(i == len && flag == 1)  
		  {
			   printf("�˾����������: %s\n",g[i].data);
			   printf("�޸�Ϊ��\n");
			   scanf("%s",f);
			   strcpy(g[i].data ,f);
			   printf("�˾���Ľ�����: %s\n",g[i].str);  
			   printf("�޸�Ϊ��\n");
			   scanf("%s",f);
			   strcpy(g[i].str,f);
			   printf("�Ƿ����? Y/N\n");
			   scanf("%c",&ch);
				getchar();
			   if(ch == 'Y' || ch == 'y')  //����
			   {
					flag = 1;
					i = 1;
					printf("��������Ҫ�޸ĵľ������:\n");
					scanf("%d",&len);
					getchar();
			   }
			   else
			   {
					flag = 0;
					save(g,&n,&b,e);//��������
			   }
		  }
		  else
			i++;
	 }
}

void zengjia(vexnode g[],int *n,int *b,adjmax *adj,EdgeType e[])  //����ָ��������Ϣ
{
	 int i = 1,flag = 1,len; 
	 int num,bian,j,s,d;//len�洢Ҫ�޸ĵľ�������
	 struct edgenode  *p,*q;
	 printf("��������Ҫ���ӵľ���ĸ��� �����м��ÿո����:\n");
	 scanf("%d %d",&num,&bian);
	 getchar();
	 *n=*n+num;
	 *b=*b+bian;//���뾰�����ƺ���ϸ������Ϣ
	 for(i=(*n-num)+1;i<=*n;i++)
	{
	   printf("�����뾰������ƺ;���Ľ��ܣ��м��ÿո����\n");
	   scanf("%s %s",&g[i].data,&g[i].str);
	   getchar();
	   strcpy(adj->vexs[i].data,g[i].data);
	   g[i].link = NULL;   //��ʼ��
	 }
	 for(i=(*n-num)+1;i<=*n;i++)    //Ϊ�ڽӾ����е�Ȩֵ����ֵ1000
	{
		for(j=(*n-num)+1;j<=*n;j++)
		{
			 adj->edges[i][j] = 1000;  //��ʼֵΪ1000�������ڷ��������㷨�о�û�������ֵ��   
		}
	 }
	 for(i =( *b-bian)+1; i <=*b; i++)   //�����·��Ϣ
	 {  
		  printf("�������·����(Ȩֵ)����ʼ�㣬����ֹ���ÿո����\n");
		  scanf("%d %d %d",&e[i].lengh,&e[i].ivex,&e[i].jvex); 
		  getchar();//�����·���Ⱥ���ʼ��
		  s = e[i].ivex;    //s����㣬d���յ㡣
		  d = e[i].jvex;
		  len = e[i].lengh;
		  adj->edges[s][d] = e[i].lengh;   //Ϊ�ڽӾ�������Ӧ�ı߸�ֵ
		  adj->edges[d][s] = e[i].lengh;
		  p = (Node)malloc(sizeof(edgenode));   //����һ�����ڵ㡣
		  p->next = p;
		  q = (Node)malloc(sizeof(edgenode));
		  q->next = NULL;
		  p->adjvex = d;     // ��pָ��Ķ���
		  p->length = len;
		  strcpy(p->info,g[d].data); //Ϊ���㸳����
		  strcpy(p->info2,g[d].str); //Ϊ���㸳������Ϣ
		  q->adjvex = s;      // ��qָ��Ķ��� 
		  q->length = len;
		  strcpy(q->info,g[s].data);  //Ϊ���㸳����
		  strcpy(q->info2,g[s].str);  //Ϊ���㸳������Ϣ
		  p->next = g[s].link;   //ͷ�巨�����ڽӱ�
		  g[s].link = p;
		  q->next = g[d].link;
		  g[d].link = q;
	 }
	 save(g,n,b,e);
	 printf("�����µ�·���ɹ�");
 	 dengdai();
 }


void shanchu(vexnode g[],int *n,int *b,adjmax *adj,EdgeType e[])
{
	 int i = 1,flag = 1,len; //len�洢Ҫ�޸ĵľ�������
	 int num,bian,j,s,d,x1,y1;
	 struct edgenode  *p,*q;
	 printf("��������Ҫɾ���ľ���Ĵ��ź���������·����:\n");
	 scanf("%d %d",&num,&bian);
	 getchar();
	 *n=*n-1;
	 *b=*b-bian;//���뾰�����ƺ���ϸ������Ϣ
	for(i=num;i<=*n;i++)
	{
		strcpy(g[i].data ,g[i+1].data);
		strcpy(g[i].str  ,g[i+1].str );
		getchar();
	}

	printf("�������·�� ʼ�㣬�ÿո����\n");
	scanf("%d %d",&x1,&y1); 
	getchar();
	for(j=1;j<=(*b+bian);j++)
	{
	   if(e[j].ivex ==x1&&e[j].jvex ==y1)
		   break;
	}
	for(i =j; i <=*b; i++)   //�����·��Ϣ
	{   
		e[i].lengh=e[i+1].lengh;
		e[i].ivex=e[i+1].ivex ;
		e[i].jvex=e[i+1].jvex ;
		s = e[i+1].ivex;    //s����㣬d���յ�
		d = e[i+1].jvex;
		len = e[i+1].lengh;
		adj->edges[s][d] = e[i+1].lengh;   //Ϊ�ڽӾ�������Ӧ�ı߸�ֵ
		adj->edges[d][s] = e[i+1].lengh;
		p = (Node)malloc(sizeof(edgenode));   //����һ�����ڵ㡣
		p->next = p;
		q = (Node)malloc(sizeof(edgenode));
		q->next = NULL;
		p->adjvex = d;     // ��pָ��Ķ���
		p->length = len;
	    strcpy(p->info,g[d].data); //Ϊ���㸳����
	    strcpy(p->info2,g[d].str); //Ϊ���㸳������Ϣ
	    q->adjvex = s;      // ��qָ��Ķ��� 
	    q->length = len;
	    strcpy(q->info,g[s].data);  //Ϊ���㸳����
	    strcpy(q->info2,g[s].str);  //Ϊ���㸳������Ϣ
	    p->next = g[s].link;   //ͷ�巨�����ڽӱ�
	    g[s].link = p;
	    q->next = g[d].link;
	    g[d].link = q;
	}
	save(g,n,b,e);
	printf("ɾ��·���ɹ�");
 	dengdai();
}
	

void shanchulujing1(vexnode g[],int *n,int *b,adjmax *adj,EdgeType e[])
{
	int i = 1,flag = 1,len;   //len�洢Ҫ�޸ĵľ�������
	int h;
	int num,j,s,d,x1,y1,f;
	struct edgenode  *p,*q;
	printf("ɾ���� ·������:\n");
	scanf("%d %d",&num,&f);
	getchar();
	*n=*n-1;//���뾰�����ƺ���ϸ������Ϣ
	for(h=0;h<f;h++)
	{
 
	   for(i=num;i<=*n;i++)
	   {
		  strcpy(g[i].data,g[i+1].data);
		  strcpy(g[i].str,g[i+1].str );
		  getchar();
	   }
	   printf("�������·�� ʼ�㣬�ÿո����\n");
	   scanf("%d %d",&x1,&y1); 
	   getchar();
	   *b=*b-1;
	   for(j=1;j<=(*b+1);j++)
	   {
		   if(e[j].ivex ==x1&&e[j].jvex ==y1)
			   break;
	   }
	  for(i =j; i <=*b; i++)   //�����·��Ϣ
	  {   
		  e[i].lengh=e[i+1].lengh;
		  e[i].ivex=e[i+1].ivex ;
		  e[i].jvex=e[i+1].jvex ;
		  s = e[i+1].ivex;    //s����㣬d���յ㡣
		  d = e[i+1].jvex;
		  len = e[i+1].lengh;
		  adj->edges[s][d] = e[i+1].lengh;   //Ϊ�ڽӾ�������Ӧ�ı߸�ֵ
		  adj->edges[d][s] = e[i+1].lengh;
		  p = (Node)malloc(sizeof(edgenode));   //����һ�����ڵ㡣
		  p->next = p;
		  q = (Node)malloc(sizeof(edgenode));
		  q->next = NULL;
		  p->adjvex = d;     // ��pָ��Ķ���
		  p->length = len;
		  strcpy(p->info,g[d].data); //Ϊ���㸳����
		  strcpy(p->info2,g[d].str); //Ϊ���㸳������Ϣ
		  q->adjvex = s;      // ��qָ��Ķ��� 
		  q->length = len;
		  strcpy(q->info,g[s].data);  //Ϊ���㸳����
		  strcpy(q->info2,g[s].str);  //Ϊ���㸳������Ϣ
		  p->next = g[s].link;   //ͷ�巨�����ڽӱ�
		  g[s].link = p;
		  q->next = g[d].link;
		  g[d].link = q;
	  }
	 save(g,n,b,e);
	 num=*n;
	}
	printf("ɾ��·���ɹ�");
 	dengdai();
}
  

void Find_way(vexnode g[],EdgeType e[])  //��ѯ��·��Ϣ
{
	 int i;  //Ҫ��ѯ�ĵ�·���
	 char ch = 'a';  //�������
	 do 
	 {
		  printf("��������Ҫ��ѯ�ĵ�·���:\n");
		  scanf("%d",&i);
		  getchar();
		  printf("�˵�·������:%d��\n",e[i].lengh);
		  printf("�˵�·���ӵ�����������:%s��%s\n",g[e[i].ivex].data,g[e[i].jvex].data);
		  printf("�Ƿ�Ҫ������ѯ(Y/N)?\n");
		  scanf("%c",&ch);
	 } while(ch == 'Y' || ch == 'y');
}


void Find_way1(vexnode g[],EdgeType e[],int *b)  //��ѯ��·������Ϣ
{
	 int i=1;  
	 do 
	 {
		  printf("��%d��·������:%d��\n",i,e[i].lengh);
		  printf("�˵�·���ӵ�����������:%s����%s\n",g[e[i].ivex].data,g[e[i].jvex].data);
		  i++;
	 } while(i<=*b);
	 printf("·��������");
	 dengdai();
	 getchar();
}


 

void Ppath(int path[][MAX],int i,int j,vexnode g[])  
{
	 int k;
	 k = path[i][j];  //��¼���һ�����·���Ľڵ���
	 if(k == -1)
		return;
	 Ppath(path,i,k,g);  //������ǰһ�����·���ڵ����
	 printf("%s-->",g[k].data);
	 Ppath(path,k,j,g);  //������ǰһ�����·���ڵ����
}

 

void Dispath(int A[][MAX],int path[][MAX],int n,vexnode g[])
{
	 int i,j;
	 int a,b;     //a����ʼ������ţ�b����ֹ������š�
	 printf("��������Ҫ��ѯ����ʼ�������ֹ������ţ����Ÿ�����:\n");
	 scanf("%d,%d",&a,&b);
	 for(i = 1; i <= n; i++)
	 {
		for(j = 1; j <= n; j++)
		{
			if(A[i][j] != 1000 && A[i][j] != 0 && i == a && j == b)
			{
				printf("��%s-->%s���·��˳��Ϊ:  ",g[a].data,g[b].data);
				printf("%s -->",g[a].data);
				Ppath(path,a,b,g);
				printf("%s",g[b].data);
				printf("\n·������Ϊ: %d\n",A[i][j]);
			}
		 }
	 }
}


void Floyd(adjmax adj,int n,vexnode g[])  //��������������������·��
{
	 int A[MAX][MAX],path[MAX][MAX];  //A��·�����ȣ�path��·����
	 int i,j,k;
	 for(i = 1; i <= n; i++)   //��ʼ��
	 {
		for(j = 1; j <= n; j++)
		{
		   A[i][j] = adj.edges[i][j]; //i j֮�䳤��
		   if(i == j)
		   {
				A[i][j] = 0;
		   }
		   path[i][j] = -1;  //��ʼ��
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
				 A[i][j] = A[i][k]+A[k][j];  //�޸����·������ֵ
				 path[i][j] = k;   //�����·���Ľڵ�ű���
				}
			}
		}
	 }
	Dispath(A,path,n,g);   //�û����룬���������������������·����
}


void Deep_Find_View(vexnode g[],int v,int n,int visted[])  //������ȵݹ���ñ���,v��ʼ���㡣
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
		  if(visted[p->adjvex] == 0)  //δ�����ʣ�����ʡ�
		  {
			   printf("��>%s",p->info);
			   visted[p->adjvex] = 1;
			   Deep_Find_View(g,p->adjvex,n,visted);  //�ݹ����
		  }
		  p = p->next;
	 }
}
void bianli(int n,vexnode g[])  //��ȵݹ�������ҳ��ι�ȫ����������·�ߡ�
{
	 int i,v;
	 int visted[MAX];  //���ʱ�־����
	 for(i = 1; i <= n; i++)  
	 {
		visted[i] = 0;  //Ϊvisited[]���鸳��ֵ,0��ʾû���ʡ�
	 }
	 printf("��������ʼ����:\n");
	 scanf("%d",&v);
	 printf("����·��: ");
	 Deep_Find_View(g,v,n,visted);
}

int main(void)
{
	 int n=0,b=0; //������Ŀ              
	 vexnode  g[MAX];   //���涥�㼰����Ϣ
	 EdgeType e[MAXedg];  //����߼�����Ϣ
	 adjmax adj;    //����ߺͶ���
	 char choice = 'x';
	 while(1)
	 {
		 clrscr();
		 map();
		 printf("\n\t\t���������������������������������� ");
		 printf("\n\t\t��       У԰����ϵͳ           �� ");
		 printf("\n\t\t���������������������������������� ");
		 printf("\n\t\t���������������������������������� ");
		 printf("\n\t\t�� 1. �ļ����벢����У԰ͼ      �� ");
		 printf("\n\t\t�� 2. ��ѯ���о�����ϸ��Ϣ      �� ");
		 printf("\n\t\t�� 3. ��ѯ������ϸ��Ϣ          �� ");
		 printf("\n\t\t�� 4. ��ѯ��·��ϸ��Ϣ          �� ");
		 printf("\n\t\t�� 5. ��ѯ���е�·��ϸ��Ϣ      �� ");
		 printf("\n\t\t�� 6. ��������������·��      �� ");
		 printf("\n\t\t�� 7. ������Ѳι�·��          �� ");
		 printf("\n\t\t�� 8. �޸ľ�����Ϣ              �� ");
		 printf("\n\t\t�� 9. ���Ӿ��㣬·��            �� ");
		 printf("\n\t\t�� a. ɾ�����㣬·��            �� ");
		 printf("\n\t\t�� b. �����������������·��    �� ");
		 printf("\n\t\t�� c. �����������������·��    �� ");
		 printf("\n\t\t�� 0. �˳�                      �� ");
		 printf("\n\t\t�� Write By Edvis@2014/12/09    �� ");  
		 printf("\n\t\t���������������������������������� \n");
		 printf("������(0-c):\n ");
		 choice = getchar();
		 switch(choice)
		 {
			case '1':
				clrscr();
				creatgraph(g,&n,&b,e,&adj);//����ͼ(���㣬���������ߣ��ߺ;���)
				printf("\n�����������");
				dengdai();
				getchar();  
				break;
			case '2':
				clrscr();
				map();
				travgraph1(g,n,adj);//�������о�����Ϣ�����㣬���������ߺ;��㣩
				getchar();
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '3':
				clrscr();
				map();
				travgraph(g,n,adj);//����ָ��������Ϣ�����㣬���������ߺ;��㣩
				getchar();
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '4':   
				clrscr();
				map();
				Find_way(g,e);  //��ѯ��·��Ϣ�����㣬�ߣ�
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '5':   
				clrscr();
				map();
				Find_way1(g,e,&b);  //��ѯ���е�·��Ϣ�����㣬�ߣ�
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '6':
				clrscr();
				map();
				Floyd(adj,n,g); //����������������·�����ߺ;��㣬�����������㣩
				getchar();
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '7':
				clrscr();
				map();
				bianli(n,g);  //�ҳ��ι�ȫ����������·��
				getchar();
				printf("\n");
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '8':
				clrscr();
				map();
				xiugai(g,n,b,adj,e);  //�޸ľ�����Ϣ
				getchar();
				printf("\n");
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
	    	case '9':
				clrscr();
				zengjia(g,&n,&b,&adj,e);//���Ӿ����·��
				getchar();
				printf("\n");
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case 'a':
				clrscr();
				shanchulujing1(g,&n,&b,&adj,e);  //ɾ�������·��
				getchar();
				printf("\n");
				printf("\n�����������");
				dengdai();
				getchar(); 
				break;
			case '0': 
				clrscr();
				printf("\n��������˳�");
				dengdai();
				getchar();
     			exit(0);
				break;
	    	default:
				printf("\n�������,����������:\n");
				getchar(); 
				break;
		 }
	  } 
	  return 0;
}