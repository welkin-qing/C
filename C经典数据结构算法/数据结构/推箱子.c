#include<stdio.h>
#include<stdlib.h>
typedef struct ele{ 
             int vno; /*��Ʒ��*/ 
           struct ele *link; /*��һ��Ʒ��ָ��*/ 
         }ELE; 
typedef struct hnode{ 
        int remainder;/*������ʣ�ռ�*/ 
        ELE *head; /*������Ʒ����Ԫָ��*/ 
        struct hnode *next;/*�������ĺ������ָ��*/ 
 }HNODE; 
main() 
{   
  int n,i,box_count,box_volume,*a; 
 HNODE *box_h,*box_t,*j; 
 ELE *p,*q; 
printf("���������ݻ� "); 
scanf("%d",&box_volume); 
printf("������Ʒ���� "); 
scanf("%d",&n); 
a=(int *)malloc(sizeof(int )*n);/*�洢��Ʒ�����Ϣ������*/ 
printf( "�밴�����С˳���������Ʒ������� "); 
for(i=0;i<n;i++) 
 scanf("%d",a+i); 
box_h=box_t=NULL; /*Ԥ������������Ϊ��*/ 
box_count=0; /*Ԥ���������Ӽ�����Ϊ0*/ 
for(i=0;i<n;i++) 
{               /*�ӵ�һֻ���ӿ�ʼ˳��Ѱ���ܷ�����Ʒi ������j*/ 
 p=(ELE *)malloc(sizeof(ELE)); 
 p->vno=i; 
 for(j=box_h;j!=NULL;j=j->next) 
      if(j->remainder>=a[i ]) 
         break;     /*�ҵ�������װ��Ʒi������*/ 
  if(j==NULL) 
    {            /*�������Ӷ�����װ��Ʒi*/ 
      j=(HNODE *)malloc(sizeof(HNODE));  /*ʹ��һֻ�µ�����*/ 
      
      j->remainder=box_volume-a[i ]; 
      j->head=NULL; 
      if(box_h==NULL) 
        box_h=box_t=j;   /* box-t��ʲô�ô����ܽ���һ����*/ 
      else box_t=box_t->next=j; /*����box-t����ʲô�ã��ڳ����У�����˵��һϸ*/ 
        j->next=NULL; 
         box_count++; 
     } 
else 
   j->remainder=a[i ];           /*����Ʒi��������j*/ 
  for(q=j->head;q!=NULL&&q->link!=NULL;q=q->link);/*���������Ƿ�����Ʒ��*/ 
    if(q==NULL) 
      { 
        p->link=j->head; 
        j->head=p; 
       } 
    else 
        { 
       p->link=NULL; 
       q->link=p; 
        } 
  }/*for i*/ 
}           