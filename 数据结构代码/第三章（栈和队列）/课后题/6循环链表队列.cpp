#include<stdio.h>
#include<stdlib.h>
#define M 100
typedef struct{
	int data[M];  //队列的储存区 
	int front,rear;  //队头队尾指针 

}CSeQueue;   //循环列 
CSeQueue* InitSeQueue()
{
	q=malloc(sizeof(CSeQueue));
	q->front=q->rear=M-1;
	return q;
 } 
 int InseQueue (CSeQueue *q,datatype x)  //入队 
 {
 	if((q->rear+1)%M==q->front)
 	{
 		printf("对满");;
 		return FALSE;
	 }
	 else
	 {
	 	q->rear=(q->rear+1)%M;
	 	q->data[q->rear]=x;
	 	return true;
	 }
 }
int OutseQueue(CSeQueue *,int x)  //出队 
{
	if(q->front==q->rear)
	{
		printf("队空\n");
		return FALSE;
	 } 
	 else
	 {
	 	q->front=(q->front)%M;
	 	x=q->data[q->front];
	 	return TURE;
	 }
}
int EmptySeQueue(CSeQueue *q)   //判断队空 
{
	if(q->front==q->rear)   return  True;
	else return FALSE;
}

main()
{
	CSeQueue *q;
	int m;
	int a[100];
	q=InitSeQueue();
	printf("请输入队列的个数:\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		InseQueue(q,a[i]);
	}
}
