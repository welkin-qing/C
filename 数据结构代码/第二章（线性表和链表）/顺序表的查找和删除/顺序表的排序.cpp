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
 	printf("输入长度:\n");
 	scanf("%d",&m);
 	p->length=m;
 	printf("输入数据:\n");
 	for(int i=0;i<p->length;i++)
 	{
 		scanf("%d",&p->elem[i]);
	 }
 }
 void print_list(seqlist *p)
 {
 	int i;
 	printf("输出该表为：\n");
 	for(i=0;i<p->length;i++)
 	{
 		printf("%5d",p->elem[i]);
 		
	 }
	 printf("\n");
 }
 void store_list(seqlist *p)                 //从小到大排序 
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
	 printf("最小为%d",p->elem[m]);
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
