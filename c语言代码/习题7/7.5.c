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
	/*for(i=0;i<10;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");*/
/*	for(i=0;i<10;i++)   
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
  
    
	for(i = 0 ; i < N; ++i)
	{
		for(j = i ; j >= 0 ; --j)
		{
			for(i=0;i<N;i++)   /*刚开始是i[0]去比较并把小值存在i[0]然后随着i的值变大从i[i+1]后开始比较*/ 
  /*   	{
		for(j=i+1;j<N;j++)  /*让i的值去和j比较，j的值比i大 ,且从第i+1开始往后比较*/ 
	//	if(a[i]>a[j])   /*如果i+1后边的值小于i则调换*/ 
	/*_	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;

		}
	    }
	    		
				
		printf("%d ",a[j]);
	    }


	}
		printf("\n");
                                         
}*/

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
		for(j=0;j<y+1;j++)
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
}


