#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXSIZE 1250
#define OK 1
#define FLASE 0

typedef int staus;
typedef int ElemType;

typedef struct{
	int i,j;
	ElemType e;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

staus Create(TSMatrix &M,int &row,int &col,int &n){
	M.mu = row;
	M.nu = col;
	M.tu = n;
	for(int k=1;k<=M.tu;k++)
	{
		scanf("(%d,",&(M.data[k].i));
		scanf("%d,",&(M.data[k].j));
		scanf("%d)",&(M.data[k].e));
	}
	return OK;
}




//������� 
void Display(TSMatrix M)
{
	int flag=1;
	for(int row=1;row<=M.mu;row++){
		for(int col=1;col<=M.nu;col++){
			for(int k=1;k<=M.tu ;k++){
				if(row==M.data[k].i&&col==M.data[k].j)
				{
					printf("%5d",M.data[k].e);
					flag=0; 
				}
			}
			if(flag)
			printf("%5d",0);
			flag=1; 
		}
		printf("\n");
	}
}


int main(){
	TSMatrix M,N,T;
	int r,l,n;
	int a,b,c;
	printf("������ϡ����������������������Ԫ�صĸ���:\n");
	scanf("%d %d %d",&r,&l,&n);
	printf("���������Ԫ�ص����±ꡢ���±꼰����Ԫ��ֵ:\n");
	Create(M,r,l,n);
	//printf("\n�����ϡ�����Ϊ:\n");
	Display(M);
	
	printf("������ϡ����������������������Ԫ�صĸ���:\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("���������Ԫ�ص����±ꡢ���±꼰����Ԫ��ֵ:\n");
	Create(N,a,b,c);
	printf("\n�����ϡ�����Ϊ:\n");
	//Display(M);
	//printf("\n");
	Display(N);
	
	return 0; 
}
