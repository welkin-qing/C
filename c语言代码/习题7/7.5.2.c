/*#include<stdio.h> 
main()
{
	int a[11]={58,86,45,78,99},b[5]={56,89,66,44,22};
	int i,j,t;
	i=5;
	for(j = 0; j < 5; j ++)
	{
		 a[i++]=b[j];
	}
	
	
	
	for(i=0;i<10;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
	for(i=0;i<10;i++)   
	{
		for(j=i+1;j<10;j++)  
		if(a[i]>a[j])  
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
		
	}
	for(i=0;i<10;i++)
	printf("%d\n",a[i]);

}*/
/*
#define M 10
#define N 10
#include<stdio.h> 
main()
{
	int a[M],b[N];
	int i,j,m,n,t;
	scanf("%d,%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(j = 0; j < 5; j ++)
	{
		 a[i++]=b[j];
	}
	for(i=0;i<10;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
	for(i=0;i<10;i++)   
	{
		for(j=i+1;j<10;j++)  
		if(a[i]>a[j])  
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
		
	}
	for(i=0;i<10;i++)
	printf("%d\n",a[i]);

}*/
/* 
#define N 5
#include <stdio.h>

int main(void)
{
	int a[N];
	int j,t,i,n;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);

		
	}
  	for(i=0;i<N-1;i++)   
	{
		for(j=i+1;j<N;j++) 
		if(a[i]<a[j])   
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
		
	}
    
	for(i = N-1; i >=0; i--)
	{
		for(j = i ; j <N ; j++)
	{
	
		printf("%d ",a[j]);
    }
	  printf("\n");
	}
	
       return 0;                                  
}*/
/*
#include <stdio.h>
#define N 5 
main()
{
	int a[N];
	int n,i,j,k;
	int x,y;
	y=N;
	printf("插入n个数:n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个数",i+1);
		scanf("%d",&x);	/*数组元素的插入,从最后一个元素开始，往后移动*/
	/*	for(j=0;j<y+1;j++)
		{
			if(x<a[j]||j==y)
			{
				for(k=y+1;k>j;k--)
					a[k]=a[k-1];
				a[j]=x;
				break;
			}
		}
		y++;
		for(i=0;i<y;i++) printf("%d ",a[i]);
	}

	return 0;
}*/
/*
#define N 5
#include <stdio.h>

int main(void)
{
	int a[N];
	int j , i,n,t,m;

	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]); 
	 } 
	for(i = 0 ; i < N ; ++i)
	{

		for(j = i ; j >= 0 ; --j)
		{
		/*if(j>0)
			{
				for(j=1;j<i;j++)
				for(m=j;m<i;m++)
				
			   {
					if(a[j-1]<a[m])
					{
						t=a[j-1];
						a[j-1]=a[m];
						a[m]=t;
					}
				}
				printf("%d",a[j]);
			}
		*/
				/*	printf("%d ",a[j]);
		}
		printf("\n");
	}
	return 0;
}
*/
/*#define N 5
#include <stdio.h>

int main(void)
{
	int a[N];
	int j , i,n,t,m;

	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		if(i>0)
		{	for(j=1;j<i;j++)
				for(m=j;m<i;m++)
				
			   {
					if(a[j-1]<a[m])
					{
						t=a[j-1];
						a[j-1]=a[m];
						a[m]=t;
					}
				}
			
			printf("%d\n",a[i]);
		}

	//	printf("%d",a[i]);
	}
}
*//*
#include<stdio.h>
void  insertion_sort(int array[],int first,int last)
{
    int i,j;
    int a;
    for(i=first+1;i<last;i++)
   {
       a=array[i];
       j=i-1;
//与已排序的数逐一比较，大于temp时，该数移后
       while((j>=0)&&(array[j]>a))
     {
        array[j+1]=array[j];
        j--;
     }
//存在大于temp的数
     if(j!=i-1)
    {
	array[j+1]=a;
    }
   }
 
}
*/
/*#include<stdio.h>
#include<stdlib.h>
#define N 8
void insert_sort(int a[],int n)
{
	int k,temp,i,j;
    for(i=1; i<n; i++)
   {
   int j=0;
   while( (a[j]<a[i]) && (j<i))    j++;
   if(i != j) 
   {
       int temp = a[i];
       for(k = i; k > j; k--)
	   {
	   a[k] = a[k-1];
	   }
	   a[j] = temp;
	   }
	}
}

int main()

{
	int i;

  int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};
  insert_sort(num, N);
  for(i=0; i<N; i++)
  printf("%d ", num[i]);
  printf("\n");
  system("pause");
  return 0;

}*//*
#define N 5
#include<stdio.h>
main()
{	
	int a[N];
	int b[N];
	int i ,j,k,x;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);		
	}
	for(j=0,k=0;j<i;j++)
	{	b[j] = a[j];   正确答案 
		for(k=0;k<j;k++)
		{
			if(b[j] < b[k])
			{
				x=b[k];
				b[k]=b[j];
				b[j]=x;
			}
		}
		for(k=0;k<=j;k++)
			printf("%d ",b[k]);
		printf("\n");
	}
}
*/
/*
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define N 0x7ffffff
  
int main(void)
{
    int n,m=0;
    int array[100000];
    for(n=0;n<10000;n++)
        array[n]=0;
    memset(array,N,sizeof array);
    while(scanf("%d",&n)!=EOF)
    {
        array[m]=n;
        m++;
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                int swap;
                if( array[i] > array[j] )
                {
                    swap=array[i];
                    array[i]=array[j];
                    array[j]=swap;
                }
            }
        }
        for(int i=0;i<m;i++)
            printf("%d ",array[i]);
        printf("\n");
    }
}
   */
   /*
   
#define N 100
#include<stdio.h>
int main(void)
{
	int arr[N] = { 1,5,7,9,10,20,40 };
	int arr2[N];
	int n,i,j,k;

	//读取数据
	printf("请输入要插入的数据个数:\n");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		printf("请输入要插入的数据\n");
		scanf("%d",&arr2[i]);
	}

	//排序
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 7+i; j++)
		{
			if (arr2[i]<arr[j])
			{
				arr2[i] = arr[j] + arr2[i];
				arr[j] = arr2[i] - arr[j];
				arr2[i] = arr2[i] - arr[j];
			}
		}
		arr[j] = arr2[i];
	}

	//输出
	for (i = 0; i < 7 + n; i++)
	{
		printf("%-5d",arr[i]);
	}
	printf("\n");
	return;
}
*/
#define N 5
#include<stdio.h>
main()
{	
	int a[N];
	int b[N];
	int i,j,k,x;
	for(i=0;i<N;i++)
	{	scanf("%d",&a[i]);
		b[i] = a[i];
			for(k=0;k<i;k++)
			{
				if(b[i] < b[k])
				{
					x=b[k];
					b[k]=b[i];
					b[i]=x;
				}
			}
			for(k=0;k<=i;k++)
				printf("%d ",b[k]);
			printf("\n");
	}
}

