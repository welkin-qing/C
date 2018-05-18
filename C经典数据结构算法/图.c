# define true 1
# define false 0
# define ok 1
# define error 0
# define overflow -2
# define null 0
typedef int status;

# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# define maxlen 10
# define large 999

typedef struct
{
 int a[maxlen],b[maxlen],h[maxlen];/*��K�ߵ����,�յ�,Ȩֵ*/
 char vexs[maxlen];/*������Ϣ����*/
 int vexnum,arcnum;/*�������ͱ���*/
 int kind;/*ͼ������*/
 int arcs[maxlen][maxlen];/*�ڽӾ���*/
}graph;

typedef struct node/*����ṹ*/
{
 int adjvex;/*�����ͷ������ڽӵĶ����������е����*/
 int info;/*Ȩֵ*/
 struct node *next;/*ָ����ͷ������ڽ���һ������ı���*/
}edgenode;

typedef struct/*ͷ���ṹ*/
{
 int id;/*�������*/
 char data;/*������Ϣ*/
 edgenode *link;/*ָ��ͷ����Ӧ�ĵ������еı���*/
}vexnode;

typedef struct/*�ڽӱ�ṹ*/
{
 vexnode adjs[maxlen];/*�ڽӱ��ͷ��㼯��*/
 int vexnum,arcnum;/*������,����*/
 int kind;
}adjlist;

typedef struct qnode/*���д洢�ṹ*/
{int data;
 struct qnode *next;
}linkqlist;

typedef struct
{linkqlist *front;/*��ͷָ��*/
 linkqlist *rear;/*��βָ��*/
} linkqueue;



typedef struct/*ջ�ṹ*/
{int stack[maxlen];
 int top;
}stackstru;

int cnull=-1;
graph g;
adjlist adjl;
stackstru *t;/*�������ж���ջ*/
stackstru *s;/*����ȶ���ջ*/
linkqueue *q;



graph printf_adjmatrix(graph g)/*����ڽӾ���*/
 {
 int i,j;
 printf("�ڽӾ���:\n");
 printf("vertex\t");
 for (i=0;i<g.vexnum;i++) printf("%4c",g.vexs[i]);
 printf("\n");
 for(i=0;i<g.vexnum;i++)
  { printf("% 4c \t",g.vexs[i]);
    for(j=0;j<g.vexnum;j++) printf("%4d",g.arcs[i][j]);
    printf("\n");
   }
 return g;
}

void create_1(graph g)
{
  int i,j,k,c=0;
  for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
  for(k=0;k<g.arcnum;k++)
    g.arcs[g.a[k]-1][g.b[k]-1]=1;
  printf_adjmatrix(g);

 }
void create_2(graph g)
{
   int i,j,k,c=0;
   for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
   for(k=0;k<g.arcnum;k++)
    { g.arcs[g.a[k]-1][g.b[k]-1]=1;
      g.arcs[g.b[k]-1][g.a[k]-1]=1;
     }
   printf_adjmatrix(g);

}
graph create_3(graph g)
{
  int i,j,k,c=999;
  for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
  for(k=0;k<g.arcnum;k++)
	g.arcs[g.a[k]-1][g.b[k]-1]=g.h[k];
  printf_adjmatrix(g);
  return g;

}
graph create_4(graph g)
{
  int i,j,k,c=999;
  for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
  for (k=0;k<g.arcnum;k++)
   { g.arcs[g.a[k]-1][g.b[k]-1]=g.h[k];
      g.arcs[g.b[k]-1][g.a[k]-1]=g.h[k];
     }
 printf_adjmatrix(g);
 return g;
}

void creategraph(graph g)/*�ڽӾ���*/
{
 switch(g.kind)
    {
     case 1:create_1(g);break;
     case 2:create_2(g);break;
     case 3:create_3(g);break;
     case 4:create_4(g);break;
     default:printf("Error\n");
     }
}

adjlist  createlist (graph g ,adjlist adjl)/*�ڽӱ�*/
{
  int i;
  edgenode *p;
  if(g.kind==1||g.kind==3)
    { for(i=0;i<adjl.arcnum;i++)
      { p=(edgenode*)malloc(sizeof(edgenode));
	p->adjvex=g.b[i];
	p->info=g.h[i];
	p->next=adjl.adjs[g.a[i]-1].link;
	adjl.adjs[g.a[i]-1].link=p;
	}
     }
 if(g.kind==2||g.kind==4) 
   { for(i=0;i<adjl.arcnum;i++)
      { p=(edgenode*)malloc(sizeof(edgenode));
	p->info=g.h[i];
        p->adjvex=g.b[i];
       	p->next=adjl.adjs[g.a[i]-1].link;
        adjl.adjs[g.a[i]-1].link=p;
       
        p=(edgenode*)malloc(sizeof(edgenode));
        p->info=g.h[i];
        p->adjvex=g.a[i];
       	p->next=adjl.adjs[g.b[i]-1].link;
	adjl.adjs[g.b[i]-1].link=p;
	}
     }
printf("�ڽӱ�Ϊ:\n");
for(i=0;i<g.vexnum;i++)
 { printf("[%d,%c]=>",i+1,adjl.adjs[i].data);
   p=adjl.adjs[i].link;
   while(p!=cnull)
    {printf("[%c,%d]-->",adjl.adjs[(p->adjvex)-1].data,p->info);
   p=p->next;
 }
printf("^\n");
}
return adjl;
}
 void initqueue(linkqueue *p)
{    p->front=(linkqlist *)malloc(sizeof(linkqlist));
     p->rear=p->front;
     (p->front)->next=null;
     }

status empty(linkqueue *q)
{int v;
 if(q->front==q->rear) v=true;
 else   v=false;
 return v;
}
status addqueue(linkqueue *q,int e)/*�����*/
{
 q->rear->next=(linkqlist *)malloc(sizeof(linkqlist));
 q->rear=q->rear->next;
 if(!q->rear) return -1;
 q->rear->data=e;
 q->rear->next=null;
}

status delqueue(linkqueue *q)/*������*/
{
  linkqlist *p;
  int e;
  if (q->front==q->rear)
      printf("the linklist is overflow");
  else p=(q->front)->next;
       (q->front)->next=p->next;
  e=p->data;
  if(q->rear==p)
       q->rear=q->front;
  free(p);/*�ͷ�P��ָ���ڴ���*/
 return(e);
}


void DFS(int i, adjlist adjl)/*�����������*/
{edgenode *p;
 int j;
 int visited[maxlen];/*���ʱ�־����,���ʹ�Ϊ1,δ���ʹ�Ϊ0*/
 for(j=0;j<adjl.vexnum;j++) visited[j]=0;/*��ʼ��,���е㶼δ����*/
  printf("%4c->",adjl.adjs[i-1].data);
  visited[i-1]=1;
  p=adjl.adjs[i-1].link;
  while(p!=cnull)
  {if (visited[(p->adjvex)-1]!=1) DFS((p->adjvex),adjl);
     p=p->next;
   }
}

void BFS(int i,adjlist adjl)/*�����������*/
{ edgenode *p;
  int j;
  int visited[maxlen];
  for (j=0;j<adjl.vexnum;j++) visited[j]=0;/*��ʼ�����е�*/

  initqueue(q);
  printf("%4c->",adjl.adjs[i-1].data);
  visited[i-1]=1;
  addqueue(q,i);
  while(!empty(q))
    {i=delqueue(q);
     p=adjl.adjs[i-1].link;
     while(p!=cnull)
       {if (visited[(p->adjvex)-1]==0)
          {printf("%4c->",adjl.adjs[p->adjvex-1].data);
           visited[(p->adjvex)-1]=1;
           addqueue(q,p->adjvex);
           p=p->next;
           }
        }
     }
}

status initstack(stackstru *s)/*�����ջ*/
{s->top=0;
 return ok;
}

status push(stackstru *s,int x)/*��ջ*/
{if (s->top==maxlen)
 printf("the stack is overflow!\n");
 else{ s->top=s->top+1;
       s->stack[s->top]=x;
      }
}
status pop(stackstru *s)
{ int y;
  if(s->top==0)printf("the stack is empty!\n");
  else {y=s->stack[s->top];
	s->top=s->top-1;
	}
  return y;
}

status stackempty(stackstru *s)
{ if (s->top==maxlen) return (true);
  else return (false);
}


 

status topsort(adjlist adjl)/*��������*/
{
  int i,k,count;
  edgenode *p;
  
  printf("������������Ϊ:\n");
  initstack(s);
  
  for(i=0;i<adjl.vexnum;i++)
    if(adjl.adjs[i].id==0) push(s,adjl.adjs[i].data);
  count=0;
  while(!stackempty(s))
    { i=pop(s);
      printf("%4c->",adjl.adjs[i].data);
      ++count;
      for(p=adjl.adjs[i].link;p;p=p->next)
         { k=p->adjvex;
	   if(!(--adjl.adjs[k-1].id)) push(s,k-1);
          }
     }
  if(count<adjl.vexnum)
    { printf("\n�����л�!\n"); /*������������Ķ�����<ͼ�еĶ�����*/
      return error;
     }
  else return ok;
}






 

void prim(graph g)/*��С������*/
{
  int i,j,k,min;
  int lowcost[maxlen];/*Ȩֵ*/
  int closet[maxlen];/*��С���������*/
  printf("��С�������ı�Ϊ:\n");
  for(i=1;i<g.vexnum;i++)
   {
     lowcost[i]=g.arcs[0][i];
     closet[i]=1;
    }
  closet[1]=0;
  j=1;
  for(i=1;i<g.vexnum;i++)
   {
     min=lowcost[j];
     k=i;
     for(j=1;j<g.vexnum;j++)
       if(lowcost[j]<min&&closet[j]!=0)
         {
	  min=lowcost[j];
	  k=j;
	 }
      printf("(%c,%c),",g.vexs[k-1],g.vexs[closet[k-1]]);
      closet[k]=0;
      for(j=1;j<g.vexnum;j++)
        if(g.arcs[k][j]<lowcost[j]&&closet[j]!=0)
           {
              lowcost[j]=g.arcs[k][j];
              closet[j]=k;
	    }
     }
}

int ve[maxlen];/*���緢��ʱ��*/
int vl[maxlen];/*��ٷ���ʱ��*/
 
status toporder(adjlist adjl,stackstru *t)/*��������¼������緢��ʱ��ve*/
{ int i,j,count,k;
  edgenode *p;
  initstack(s);
  initstack(t);
  for(i=0;i<adjl.vexnum;i++)
    if(adjl.adjs[i].id==0) push(s,i);

  count=0;
  for(i=0;i<adjl.vexnum;i++) ve[i]=0;
  while(!stackempty(s))
    { j=pop(s);push(t,j);++count;
      for(p=adjl.adjs[j].link;p;p=p->next)
        { k=p->adjvex;
          if(--adjl.adjs[k-1].id==0) push(s,k-1);
	  if(ve[j]+(p->info)>ve[k-1]) ve[k-1]=ve[j]+(p->info);
         }
     }
  if(count<adjl.vexnum) return error;
   else return ok;
}

status criticalpath(adjlist adjl)/*�ؼ�·��*/
{  int i,j,k,dut,ee,el;
   edgenode *p;
   
   if(!toporder(adjl,t)) return error;
   for(i=0;i<adjl.vexnum;i++) vl[i]=ve[i-1];/*��ʼ�������¼�����ٷ���ʱ��*/
   printf("�ؼ�·��Ϊ:\n");
  while(!stackempty(t))/*�������������������������ٷ���ʱ��veֵ*/
    for(j=pop(t), p=adjl.adjs[j].link;p;p=p->next)
       { k=p->adjvex; dut=(p->info);
         if(vl[k]-dut<vl[j]) vl[j]=vl[k]-dut;
        }
  for(j=0;j<adjl.vexnum;++j)/*��ee,el�͹ؼ��*/
    for(p=adjl.adjs[j].link;p;p=p->next)
      { k=p->adjvex;dut=p->info;
        ee=ve[j];el=vl[k-1]-dut;
        if(ee==el) printf("(%c,%c)->",adjl.adjs[j].data,adjl.adjs[k-1].data);
       }
}

void shortpath_dijkstra(graph g)
{ int cost[maxlen][maxlen];
  int dist[maxlen];/*ĳԴ�㵽����������·������*/
  int path[maxlen];/*ĳԴ�㵽�յ㾭���Ķ��㼯�ϵ�����*/
  int s[maxlen];/*���·�����յ㼯��*/
  int i,j,n,v0,min,u;/*U������·�����յ�*/
  printf("\n���������ı��:");
  scanf("%d",&v0);
  v0--;
  for(i=0;i<g.vexnum;i++)
    {for(j=0;j<g.vexnum;j++)
      cost[i][j]=g.arcs[i][j];
     }
  for(i=0;i<g.vexnum;i++)
    { dist[i]=cost[v0][i];
      if(dist[i]<large&&dist[i]>0) path[i]=v0;
      s[i]=0;
     }
  s[v0]=1;
  for(i=0;i<g.vexnum;i++)
    { min=large;
      u=v0;
      for(j=0;j<g.vexnum;j++)
        if(s[j]==0&&dist[j]<min)
          {min=dist[j];u=j;}
      s[u]=1;   /*U������������·���Ķ�����*/
      for(j=0;j<g.vexnum;j++)
         if(s[j]==0&&dist[u]+cost[u][j]<dist[j])
           { dist[j]=dist[u]+cost[u][j];
             path[j]=u;
            }
      }
  printf("\n����%d������������·������Ϊ:\n",v0);
  for(i=0;i<g.vexnum;i++)/*������*/
     if(s[i]==1)
       { u=i;
         while(u!=v0)
            { printf("%4c<-",g.vexs[u]);
              u=path[u];
             }
          printf("%4c",g.vexs[u]);
          printf(":%d\n",path[i]);
         }
      else printf("%4c<-%4c:��·��\n",g.vexs[i],g.vexs[v0]);
}

void shortpath_floyd(graph g)
{ int path[maxlen][maxlen];
  int short3[maxlen][maxlen];/*Ȩֵ*/
  int i,j,k;
  for(i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
       { short3[i][j]=g.arcs[i][j];
         path[i][j]=0;
        }
  printf("\n�����������·��Ϊ:\n");
  for(k=0;k<g.vexnum;k++)
    for(i=0;i<g.vexnum;i++)
      { if(short3[i][j]>(short3[i][k]+short3[k][j]))
	  { short3[i][j]=short3[i][k]+short3[k][j];
            path[i][j]=k;
           }
	 printf("(%4c->%4c):%d",g.vexs[i-1],g.vexs[j-1],short3[i][j]);
       }
}




main()
{

int a,i,j,k,h;
printf("\n������ͼ������(1:����ͼ 2:����ͼ 3:������ 4:������):");
scanf("%d",&i);
{g.kind=i;adjl.kind=i;}
printf("�����붥����,����:");
scanf("%d,%d",&i,&j);
g.vexnum=i;adjl.vexnum=i;
g.arcnum=j;adjl.arcnum=j;
for (i=0;i<g.vexnum;i++)
 { printf("��%d���������Ϣ:",i+1);
   scanf("%s",&g.vexs[i]);
   adjl.adjs[i].data=g.vexs[i];
   adjl.adjs[i].link=cnull;
   adjl.adjs[i].id=0;
   }
for (k=1;k<=g.arcnum;k++)
{label:if (g.kind==1||g.kind==3)
	 printf("��%d���ߵ������,�յ���:",k);
       else printf("��%d���ߵ���������ı��:",k);
       scanf("%d,%d",&i,&j);
       g.a[k-1]=i;g.b[k-1]=j;
       while (i<1||i>g.vexnum||j<1||j>g.vexnum)
       {printf("     ��ų�����Χ,��������");goto label;

	}
       if (g.kind==3||g.kind==4)
       {printf("\t�ñߵ�Ȩֵ:");
	scanf("%d",&h);
	g.h[k-1]=h;
	}
	else  g.h[k-1]=null;
	adjl.adjs[i].id++;
}
loop1:printf("\n1__�ڽӾ���\n");
printf("2__�ڽӱ�\n");
printf("3__�����������\n");
printf("4__�����������\n");
printf("5__��С������\n");
printf("6__��������\n");
printf("7__�ؼ�·��\n");
printf("8__��ĳ��Դ�㵽�������������·��\n");
printf("9__ÿһ�Զ���֮������·��\n");
loop:printf("��ѡ��ͼ��ʵ��:\t");
scanf("%d",&a);
 switch(a)
 {
  case 1:creategraph(g);break;
  case 2:createlist(g,adjl);break;
  case 3:printf("�������������:");
           scanf("%d",&k);
          createlist(g,adjl);
           printf("\n�ӵ�%d������������������������:",k);
	   DFS(k,adjl);break;
  case 4:printf("�������������:");
           scanf("%d",&k);
           createlist( g,adjl);
           printf("\n�ӵ�%d������������������������:",k);	
	   BFS( k,adjl);
	   break;
  case 5:if (g.kind==4)
	       {create_4(g); prim(g);}
	   else{printf("\t���ܹ�����С������,������ѡ��:\n");goto loop;}
           break;
  case 6:if (g.kind==1||g.kind==3)
	       {createlist(g,adjl); topsort(adjl);}
	   else{printf("\t������������,������ѡ��:\n");goto loop;}
           break;
  case 7:if (g.kind==3)
	       {createlist(g,adjl);
	       criticalpath( adjl);
	       }
	   else{printf("\tû�йؼ�·��,������ѡ��:\n");goto loop;}
           break;
  case 8:if (g.kind==3)
	       {create_3(g); shortpath_dijkstra(g);}
	   else{printf("\tû�����·��,������ѡ��:\n");goto loop;}
           break;
  case 9:if (g.kind==3)
	       {create_3(g); shortpath_floyd(g);}
	   else{printf("\tû�����·��,������ѡ��:\n");goto loop;}
           break;
  default:printf(" \n\t*** wrong ***\n");
  }/*switch*/
goto loop1;
 }/*main()*/



