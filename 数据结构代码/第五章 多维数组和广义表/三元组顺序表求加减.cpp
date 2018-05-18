
#include<stdio.h>
#define MAXSIZE 100
typedef struct{
	int row,col;
	int value;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int rows,cols,nums; 
}TSMatrix;
int CreatSMatrix(int n)
{
	int k;
	M.tu = n;
	M.mu = row;
	M.nu = col;
	for(k=1;k<=M.tu;k++){
		scanf("%d",&(M.data[k].i));
		scanf("%d",&(M.data[k].j));
		scanf("%d",&(M.data[k].e));
	//	scanf("(%d,%d,%d)",&(M.data[k].i),&(M.data[k].j),&(M.data[k].e));
	}
	return OK;
} 
mian()
{
	TSMatrix M;
	int r,c,n;
	printf("请输入稀疏矩阵的行数、列数及非零元素的个数:\n");
	scanf("%d%d%d",&r,&c,&n);
	CreatSMatrix();
}


