#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct Node
{
	int row,col;
	int value;
}Node;
typedef struct LNode
{
	Node data[MAXSIZE+1];
	int rows,cols,nums;
}LNode;
void creat_JZ(LNode *A)
{
	int i = 0;
	scanf("%d %d %d",&A->rows,&A->cols,&A->nums);
	getchar();
	for(i=1;i<=A->nums;i++)
	{
	//	scanf("(%d,",&A->data[i].row);
	//	scanf("%d,",&A->data[i].col);
//		scanf("%d)",&A->data[i].value);
		scanf("(%d,%d,%d)",&A->data[i].row,&A->data[i].col,&A->data[i].value);
	}
	getchar();
}
int Judge_JZ(LNode *A,LNode *B)
{
	if(A->cols == B->cols&&A->rows == B->rows)
		return 1;
	else
		return 0;
}
void Plus_JZ(LNode *A,LNode *B,LNode *C)
{  
	int i,m=0,j=1;
	int n;
	C->cols = A->cols;
	C->rows = A->rows;
	C->nums= A->nums +B->nums;
	for(i = 1;i<=A->nums;i++)
	{
		C->data[i].col = A->data[i].col;
		C->data[i].row = A->data[i].row;
		C->data[i].value = A->data[i].value;
	}
	for(i = A->nums+1;i<=A->nums+B->nums;i++)
	{
		C->data[i].col = B->data[j].col;
		C->data[i].row = B->data[j].row;
		C->data[i].value = B->data[j].value;
		j++;
	}
	for(i=1;i<=C->nums-1;i++)
		for(j=i+1;j<=C->nums;j++)
		{
			if(C->data[i].col == C->data[j].col&&C->data[i].row == C->data[j].row)
			{
				C->data[i].value = C->data[i].value+C->data[j].value;
				if(C->data[i].value != 0)
				{
				C->data[j].col = 0;
				C->data[j].row = 0;
				C->data[j].value = 0;
                              
				}
				else
				{
				C->data[i].col = 0;
				C->data[i].row = 0;
				C->data[i].value = 0;
				C->data[j].col = 0;
				C->data[j].row = 0;
				C->data[j].value = 0;
                               
				}
			}
		}
		m=C->nums; 
		for(i=1;i<=C->nums;i++)
		{
			if(C->data[i].value==0)
			{
				m=m-1;
			}
		}
	printf("%d %d %d",C->rows,C->cols,m);
       printf("\n");
}

void Sub_JZ(LNode *A,LNode *B,LNode *C)
{
	int i,j=1;
	int n;
	C->cols = A->cols;
	C->rows = A->rows;
	C->nums = A->nums +B->nums;
	for(i = 1;i<=A->nums;i++)
	{
		C->data[i].col = A->data[i].col;
		C->data[i].row = A->data[i].row;
		C->data[i].value = A->data[i].value;
	}
	for(i = A->nums+1;i<=A->nums+B->nums;i++)
	{
		C->data[i].col = B->data[j].col;
		C->data[i].row = B->data[j].row;
		C->data[i].value = -B->data[j].value;
		j++;
	}
	for(i=1;i<=C->nums-1;i++)
		for(j=i+1;j<=C->nums;j++)
		{
			if(C->data[i].col == C->data[j].col&&C->data[i].row == C->data[j].row)
			{
				C->data[i].value = C->data[i].value+C->data[j].value;
				if(C->data[i].value != 0)
				{
				C->data[j].col = 0;
				C->data[j].row = 0;
				C->data[j].value = 0;
				}
				else
				{
				C->data[i].col = 0;
				C->data[i].row = 0;
				C->data[i].value = 0;
				C->data[j].col = 0;
				C->data[j].row = 0;
				C->data[j].value = 0;
				}
			}
		
       }
      n=C->nums;
       for(i=1;i<=C->nums;i++)
		{
			if(C->data[i].value==0)
			{
				n=n-1;
			}
		}
	printf("%d %d %d",C->rows,C->cols,n);
       printf("\n");
}

void Print_JZ(LNode *C)
{ 
	Node *D;
	int i,j;
	int m=0;
	D = (Node *)malloc(sizeof(Node)); 
	  for(i=1;i<=C->nums-1;i++)
		for(j=i+1;j<=C->nums;j++)
			{
			  if(C->data[i].row>C->data[j].row||(C->data[i].row==C->data[j].row&&C->data[i].col>C->data[j].col))			
				{
				  (*D) = C->data[i];
				  C->data[i] = C->data[j];
				  C->data[j] = (*D);

			    }
		    }
		    
	   /*m=C->nums;
       for(i=1;i<=C->nums;i++)
		{
			if(C->data[i].value==0)
			{
				m=C->nums-1;
			}
		}	   */ 
      // printf("%d %d %d",C->rows,C->cols,C->nums);
       //printf("\n");
      for(i=1;i<=C->nums;i++)
       if(C->data[i].col>0)
           printf("(%d,%d,%d)", C->data[i].row,C->data[i].col,C->data[i].value);

}


main()
{
	LNode *A,*B,*C;
	int p;
	A = (LNode *)malloc(sizeof(LNode));
	B = (LNode *)malloc(sizeof(LNode));
	C = (LNode *)malloc(sizeof(LNode));
	
	creat_JZ(A);
	creat_JZ(B);
	p = Judge_JZ(A,B);
	if(p == 0)
		printf("矩阵不能相加");
	else
	{
		Plus_JZ(A,B,C);

		Print_JZ(C);
		printf("\n");
		Sub_JZ(A,B,C);
		Print_JZ(C);	
	}
}
