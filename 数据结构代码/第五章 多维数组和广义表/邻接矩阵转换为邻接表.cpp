//一个无向图的邻接矩阵转换为邻接表

#include<stdio.h>
#include<stdlib.h>
#define max 20
#define digit 1
#define zero 0
typedef struct{
       int  num;
       char  data;
}Vertex;  
typedef  struct{
       int n;    //顶点数
       int e;    //弧数
       Vertex  vexs[max];
       int  edges[max][max];
}MGraph;
typedef  struct  node{
       int adjvex;
       node *nextarc;
       char info;
}ARCNODE;   //邻接表的结点结构
typedef struct{
       char vexdata;
       ARCNODE *firstarc;
}VEXNODE;   //邻接表的表头结点
typedef  struct{
       int  vexnum,arcnum;   //顶点数、弧数
       VEXNODE  ve[max];
}ALGraph;   //邻接表类型
 
ALGraph *Creat_alg(){     //创建邻接表
       ALGraph  *alg;
       int  i,n,e,b,a;
       char  ch;
       ARCNODE  *AR;
       alg=(ALGraph*)malloc(sizeof(ALGraph));
       printf("输入顶点数:");
       scanf("%d",&n);
       printf("输入弧数:");
       scanf("%d",&e);
       alg->vexnum=n;
       alg->arcnum=e;
       printf("输入顶点信息:\n");
       for(i=0;i<n;i++){
              scanf("%s",&ch);
              alg->ve[i].vexdata=ch;
              alg->ve[i].firstarc=NULL;
       }
       printf("输入弧的信息(弧的两端点):\n");
       for(i=0;i<e;i++){
              scanf("%d%d",&a,&b);
              AR=(ARCNODE*)malloc(sizeof(ARCNODE));
              AR->adjvex=b;
              AR->info=alg->ve[b].vexdata;
              AR->nextarc=alg->ve[a].firstarc;
              alg->ve[a].firstarc=AR;
              AR=(ARCNODE*)malloc(sizeof(ARCNODE));
              AR->adjvex=a;
              AR->info=alg->ve[a].vexdata;
              AR->nextarc=alg->ve[b].firstarc;
              alg->ve[b].firstarc=AR;
       }
       return alg;
}

void ALGout(ALGraph *alg){     //邻接表输出
       int  i,n1;
       ARCNODE  *p;
       VEXNODE  *q;
       n1=alg->vexnum;
       for(i=0;i<n1;i++){
              q=&alg->ve[i];
              printf("%c",q->vexdata);
              p=q->firstarc;
              while(p!=NULL){
                     printf("─→");
                     printf("%c",p->info);
                     p=p->nextarc;
              }
              printf("\n");
       }
}

MGraph *ALG_change_MG(ALGraph *alg){    //将邻接表转换为邻接矩阵
       MGraph  *mg;
       int  i,n1;
       mg=(MGraph*)malloc(sizeof(MGraph));
       mg->n=alg->vexnum;
       mg->e=alg->arcnum;
       n1=mg->n;
       for(i=0;i<n1;i++){
              mg->vexs[i].num=i;
              mg->vexs[i].data=alg->ve[i].vexdata;
       }
       ARCNODE  *p;
       for(i=0;i<n1;i++){
              p=alg->ve[i].firstarc;
              while(p!=NULL){
                     mg->edges[i][p->adjvex]=1;
                     mg->edges[p->adjvex][i]=1;
                     p=p->nextarc;
              }
       }
       return  mg;
}

void MGout(MGraph *mg)
{   //输出邻接矩阵
       int  i,j,k;
       k=mg->n;
       for(i=0;i<k;i++){
              for(j=0;j<k;j++){
                     if(mg->edges[i][j]==1)
                            printf("%-5d",digit);
                     else
                            printf("%-5d",zero);
              }
              printf("\n");
       }
}

main()
{
       MGraph  *mg;
       ALGraph  *alg;
       printf("建立无向图的邻接表:\n");
       alg=Creat_alg();
       printf("邻接表输出:\n");
       ALGout(alg);
       mg=ALG_change_MG(alg);
       printf("邻接矩阵输出:\n");
       MGout(mg);
}
