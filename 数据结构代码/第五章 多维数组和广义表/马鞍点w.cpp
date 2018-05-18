#include<stdio.h>


 int main()
 {
     
  int a[100][100];
  int i, j,M,N;
  int temp = 0, min[100], max[100];
  scanf("%d %d",&M,&N);
  for (i = 1;i<=M;i++)
    for (j = 1;j <= N;j++)
    scanf("%d", &a[i][j]);
     for (i = 1;i<=M;i++)
     {
         min[i]=999999;
     
         for (j = 1;j <= N;j++)
         {
             if(a[i][j]<min[i])
              min[i]=a[i][j];
         }
     }
     for (i = 1;i<=N;i++)
     {
         max[i]=-999999;
         for (j = 1;j <= M;j++)
         {
             if(a[j][i]>max[i])
                 max[i]=a[j][i];
         }
     }

           for (i = 1;i <= M;i++)
            {
                for (j =1;j <= N;j++)
                {
                    if (a[i][j] == min[i] && a[i][j] == max[j])
                {
                    temp=1;
                    printf("(%d,%d,%d)",i,j,a[i][j]);
                }
            }
                }
         if (temp == 0)
                 printf("NONE\n");
     return 0;
         }

