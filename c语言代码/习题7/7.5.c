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
			for(i=0;i<N;i++)   /*�տ�ʼ��i[0]ȥ�Ƚϲ���Сֵ����i[0]Ȼ������i��ֵ����i[i+1]��ʼ�Ƚ�*/ 
  /*   	{
		for(j=i+1;j<N;j++)  /*��i��ֵȥ��j�Ƚϣ�j��ֵ��i�� ,�Ҵӵ�i+1��ʼ����Ƚ�*/ 
	//	if(a[i]>a[j])   /*���i+1��ߵ�ֵС��i�����*/ 
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
	printf("����n����:n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d����",i+1);
		scanf("%d",&x);	/*����Ԫ�صĲ���,�����һ��Ԫ�ؿ�ʼ�������ƶ�*/
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


