#include<stdio.h>
#include<stdlib.h> 
#define M 10
typedef struct{
	int elem[M];
	int length;
}seqlist;
 void creat_list(seqlist *p)
 {
 	int m;
 	printf("���볤��:\n");
 	scanf("%d",&m);
 	p->length=m;
 	printf("��������:\n");
 	for(int i=0;i<p->length;i++)
 	{
 		scanf("%d",&p->elem[i]);
	 }
 }
 void print_list(seqlist *p)
 {
 	int i;
 	printf("����ñ�Ϊ��\n");
 	for(i=0;i<p->length;i++)
 	{
 		printf("%5d",p->elem[i]);
 		
	 }
	 printf("\n");
 }
 void store_list(seqlist *p)                 //��С�������� 
 {
 	int a;
 	int m=0;
 	for(int i=0;i<p->length;i++)
 	for(int j=i;j<p->length+1;j++)
 	{
 		if(p->elem[i]>p->elem[j])
 		{
 			a=p->elem[i];
 			p->elem[i]=p->elem[j];
 			p->elem[j]=a;
		 }
	 }
	 printf("��СΪ%d",p->elem[m]);
 }
 main()
 {
 	seqlist *q;
 	q=(seqlist*)malloc(sizeof(seqlist));
 	creat_list(q);
 	print_list(q);
 	store_list(q);
 	//print_list(q);
 }
