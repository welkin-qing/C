/*找出6*6矩阵每列绝对值最大的元素，并与同行对角线元素交换*/
/*
#include<stdio.h>
#include<math.h>
int main()
{
	int a[6][6]={0};
	int b[6][6]={0};
	int i,j,k,m,n,o,max;
	printf("请输入一个6*6数组：\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for(j=0;j<6;j++)
	{
		for(i=0;i<6;i++)
		{
			o=fabs(a[0][j]);
			if(fabs(a[i][j])>o)
			{
				o=a[i][j];
			}	
		}
		for(j=0;j<6;j++)
		{
			max=fabs(a[0][j]);  
			for(i=1;i<6;i++)
			{
				if(fabs(a[i][j])>max)
				{
					max=a[i][j];
					k=i;
					n=j; 
				} 
			}
			for(i=0;i<6;i++)
			{
				if(a[i][j]==o)
				{
					b[k][5-j]=a[k][j];
					b[k][n]=a[k][5-n];  
				}
			}
			
		}
	}
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
				if(b[i][j]!=0)
					a[i][j]=b[i][j];
			}
		}
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	system("pause");
}    */

	/*printf("矩阵a为：\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("变化的矩阵为：\n"); */
#include<stdio.h>
#include<math.h>
int main(void)
{
    int array[6][6];
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
    scanf("%d,",&array[i][j]);                 
    for(int i = 0;i<6;i++)
    {
       int  max = 0;                            
        for(int j = 0;j<6;j++)
        {      
               if(abs(array[max][i])<abs(array[j][i]))
                    max=j;
        }                                     
        int swap = array[max][i];            
        array[max][i] = array[max][max];
        array[max][max] = swap;
         
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(j==5)
                printf("%d \n",array[i][j]);
            else    printf("%d ",array[i][j]);
        }
    }
}
 

