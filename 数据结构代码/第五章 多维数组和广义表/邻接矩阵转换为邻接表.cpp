//һ������ͼ���ڽӾ���ת��Ϊ�ڽӱ�

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
       int n;    //������
       int e;    //����
       Vertex  vexs[max];
       int  edges[max][max];
}MGraph;
typedef  struct  node{
       int adjvex;
       node *nextarc;
       char info;
}ARCNODE;   //�ڽӱ�Ľ��ṹ
typedef struct{
       char vexdata;
       ARCNODE *firstarc;
}VEXNODE;   //�ڽӱ�ı�ͷ���
typedef  struct{
       int  vexnum,arcnum;   //������������
       VEXNODE  ve[max];
}ALGraph;   //�ڽӱ�����
 
ALGraph *Creat_alg(){     //�����ڽӱ�
       ALGraph  *alg;
       int  i,n,e,b,a;
       char  ch;
       ARCNODE  *AR;
       alg=(ALGraph*)malloc(sizeof(ALGraph));
       printf("���붥����:");
       scanf("%d",&n);
       printf("���뻡��:");
       scanf("%d",&e);
       alg->vexnum=n;
       alg->arcnum=e;
       printf("���붥����Ϣ:\n");
       for(i=0;i<n;i++){
              scanf("%s",&ch);
              alg->ve[i].vexdata=ch;
              alg->ve[i].firstarc=NULL;
       }
       printf("���뻡����Ϣ(�������˵�):\n");
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

void ALGout(ALGraph *alg){     //�ڽӱ����
       int  i,n1;
       ARCNODE  *p;
       VEXNODE  *q;
       n1=alg->vexnum;
       for(i=0;i<n1;i++){
              q=&alg->ve[i];
              printf("%c",q->vexdata);
              p=q->firstarc;
              while(p!=NULL){
                     printf("����");
                     printf("%c",p->info);
                     p=p->nextarc;
              }
              printf("\n");
       }
}

MGraph *ALG_change_MG(ALGraph *alg){    //���ڽӱ�ת��Ϊ�ڽӾ���
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
{   //����ڽӾ���
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
       printf("��������ͼ���ڽӱ�:\n");
       alg=Creat_alg();
       printf("�ڽӱ����:\n");
       ALGout(alg);
       mg=ALG_change_MG(alg);
       printf("�ڽӾ������:\n");
       MGout(mg);
}
