#include<stdio.h>
#include<stdlib.h>
#define M 100
typedef struct{
	int data[M];  //���еĴ����� 
	int front,rear;  //��ͷ��βָ�� 

}CSeQueue;   //ѭ���� 
CSeQueue* InitSeQueue()
{
	q=malloc(sizeof(CSeQueue));
	q->front=q->rear=M-1;
	return q;
 } 
 int InseQueue (CSeQueue *q,datatype x)  //��� 
 {
 	if((q->rear+1)%M==q->front)
 	{
 		printf("����");;
 		return FALSE;
	 }
	 else
	 {
	 	q->rear=(q->rear+1)%M;
	 	q->data[q->rear]=x;
	 	return true;
	 }
 }
int OutseQueue(CSeQueue *,int x)  //���� 
{
	if(q->front==q->rear)
	{
		printf("�ӿ�\n");
		return FALSE;
	 } 
	 else
	 {
	 	q->front=(q->front)%M;
	 	x=q->data[q->front];
	 	return TURE;
	 }
}
int EmptySeQueue(CSeQueue *q)   //�ж϶ӿ� 
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
	printf("��������еĸ���:\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		InseQueue(q,a[i]);
	}
}
