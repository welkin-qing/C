/*
#include<stdio.h>
#define M 4
#define N 6
main()
{
	int m ,n;
	int minj,min,flag;
	//int a[M][N];
	scanf("%d %d",&m,&n);
	//建立数组 
/*	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d ",a[i][j]);
		}
		getchar();
	}*/
/*	int a[M][N] {
    					{45,67,87,34,56,26},
						{93,75,85,75,92,75},
						{94,85,96,75,78,75},
						{23,17,75,28,98,61}

						
						
					};
	for(int i=0;i<m;i++)  //找i行最小值 
	{
		min=a[i][0];
		minj=0;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				minj=j;
			}
			flag=1;
			for(int k=0;k<m;k++)
			{
				if(min<a[k][minj])
				{
					flag=0; 
					//contuine;
				}
				if(!flag)
				{
					printf("a[%d][%d]=%d\n",i,minj,min);
					break;
				}
			}
			if(!flag)   printf("none");
			
		}
	}
}
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#define M 50
#define N 50


int main(void) {
    int i,j,m,n;
    int max,jmax,flag,f = 1,flag1;
    int a[M][N];
    int p,q;
    int i1,i2,i3,i4;
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j)
            scanf("%d",&a[i][j]);
    for(i = 0; i < m; ++i) {
        max = a[i][0];
        jmax = 0;
        for(j = 1; j < n; ++j) { // 找出i行最大的
            if(max > a[i][j]) {
                max = a[i][j];
                jmax = j; // 且记录所在的列坐标
            }
        }
        flag = 1; // 预置标志
        for(j = 0; j < m && flag; ++j) { // 判断max是否为所在列最小的
            if(a[j][jmax] >max) // 不是
                flag = 0; // 则清标志
        }
        if(flag == 1) {
            printf("鞍点:a[%d][%d] = %d\n",i,jmax+1,max);
            f = 0;
            p=i;
            q=jmax+1;
            flag1=max;
            //function(p,q,flag1);
            for(int t=i;t<m;t++)
            {
            	for(int p=jmax+1;p<n;p++)
            	{
            		if(a[t][p]==max)
            		printf("鞍点:a[%d][%d] = %d\n",i1=t,i2=p+1,i3=a[t][p]);
				}
			}
			printf("%d %d\n",i1,i2);
			
        }
    }
    
    if(f) printf("没有鞍点。\n");
    return 0;
}/*
int function(int a,int b,int c)
{
	int t,k,flag;
	int m=4,n=6;
for(int t=p;t<m;t++)
            {
            	for(int k=q;k<n;k++)
            	{
            		if(a[t][k]==flag1)
            		printf("鞍点:a[%d][%d] = %d\n",t,k+1,a[t][k]);
            		function(t,k+1,a[t][k]);
				}
			}	
}
*/
