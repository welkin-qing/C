/*#include<stdio.h>
#include<math.h>
#define MAX 100
int num[2][MAX];
main()
{
	//int num[2][MAX];
	int n,i; 
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d,%d",&num[0][i],&num[1][i]);
			
		}
		for(i=0;i<n;i++)
		{
			if(num[0][i]>0 && i!=0)
			   printf("+%d",num[0][i]);
			else   printf("%d",num[0][i]);
			if(num[1][i]!=0)
			  printf("X");
			if(num[1][i]>1)
			  printf("^%d",num[1][i]);
		}
		printf("\n");  break;
	 } 
	 return 0;
}*/
//acm������δ���� 
#include<stdio.h>
#include<stdlib.h>
#define M 10
typedef struct josephusNode {
 	int number;
 	struct josephusNode *next;
}josephusNode; 

//����Լɪ�� 
josephusNode  *createJosephus(int m) 	
{
	int i = 1;
	josephusNode  *phead;
	josephusNode  *s,*r;

	phead =(josephusNode  *)malloc(sizeof(josephusNode));
	phead->next = NULL;
	
	r=phead;
	
	while(i <= m){
		s = (josephusNode  *)malloc(sizeof(josephusNode));
		s -> number = i ++;
		
		s -> next = r -> next;
		r -> next = s;
		r = s; 
	}
	s -> next = phead ->next;
	 
	
	return phead -> next;;
}	

//���Լɪ��  

void 	printjosephus(josephusNode *phead)
{
	josephusNode *ptemp;
	ptemp = phead;
	while(ptemp -> next != phead){
		printf("%d ",ptemp -> number);
		ptemp = ptemp -> next; 
	}
	printf("%d ",ptemp -> number);
	printf("\n");
}

//���Լɪ������ 
void	sortjosephus(josephusNode *phead,  int n) 
{
	int i;
	int b[M];
	int j=0;
	josephusNode *p, *q, *s;
	
	p = phead;
	printf("\n\n���Լɪ������:\n");
	while(p->next != p)
	{
		for(i = 1; i < n; i ++ )
		{
			q = p;
			p = p -> next;
		}
		printf("%d ",p -> number);
		b[j]=p->number;
		j++;
		s = p -> next;
		q -> next = s;
		p = s;
		
		//free(p);
	} 
	printf("%d \n",p -> number);
	
	//printf("\n��ʤ�� %d\n", p -> number);
	for(i=0;i<n;i++)
	  printf("%d ",b[i]);
}  

//������
int main(void)
{
	int a[4]={7,5,1,4};
	josephusNode	*phead;
	int m,n;
	
	printf("���뻷�е����� ��\n");
	scanf("%d",&m);
	printf("����˳����ĺ��� ��\n");
	scanf("%d",&n);
	if(n > m) {
		printf("�����������������\n");
		scanf("%d",&n);
	} 
	//���� 
	phead = createJosephus(m);
	//��ʾ������Ϣ
	//printjosephus(phead);
	//��ʾԼɪ������
	sortjosephus(phead, n);
	return 0;
	 
}
