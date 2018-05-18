
/*#define M 200
#define N 300
#include<stdio.h>
int main()
{
	int a[M][M],b[M][N];
	int i,j;
	int m , n ;
    scanf("%d,%d",&m,&n);
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}

	}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b[i][j]=a[j][i];
		for(i=0;i<m;i++)
		{
		for(j=0;j<n;j++)
		printf("%d ",b[i][j]); 
		printf("\n");
	}
		return 0;
 } */
 


/*#include<stdio.h>
#define N1 3
#define N2 2
int main()
{
    int a[N1][N2],b[N2][N1],i,j;
    printf("请输入一个%d行%d列的矩阵：\n",N1,N2);
    for(i=0;i<N1;i++)
        for(j=0;j<N2;j++)
           scanf("%d",&a[i][j]);
    printf("转置后的矩阵为：\n");
    for(i=0;i<N2;i++)
      {
        for(j=0;j<N1;j++)
        {
            b[i][j] = a[j][i];
            printf("%d\t",b[i][j]);            
        }
        printf("\n");
      }
}*/



/*#include <stdio.h>
int main()
{
   int a[20][20],b[20][20];
   int i,j,k,m,n;
   scanf("%d,%d",&n,&m);
   for(i=0;i<m;i++)
	   for(j=0;j<n;j++)
	   { 
	        scanf("%d",&a[i][j]);
			b[j][i]=a[i][j];	
	   }
	   for(i=0;i<n;i++)
	   {for(j=0;j<m;j++)
		   printf("%d ",b[i][j]);
	   printf("\n");
	   }
}*/


#include<stdio.h>
#define M 20
int main(void)
{
	int a[M][M],b[M][M];
	int i,j;
	int m,n;
    scanf("%d,%d",&m,&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			b[j][i]=a[i][j];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",b[i][j]); 
			printf("\n");
		}
		return 0;
} 


