/*
4 6
45 67 87 34 56 26
93 75 85 75 92 75
94 85 96 75 78 75
23 17 75 28 98 61
(2,4,75)(2,6,75)(3,4,75)(3,6,75) 
*/ 

#include<stdio.h>
#define M 4
#define N 6 
void saddle (int A[M][N],int m, int n)
/*m,n�ֱ��ʾ����A���к���*/
{ 
    int i,j;
    int k,p;
    int minn[M],maxx[N];
    int temp;
    /*
    for (i=0;i<m;i++)  /*���д���*/
  /*  { 
        min[i]=A[i][0];
        for (j=1; j<n; j++)
        {
        	if (A[i][j]<min[i] )  /*�ҵ�i����Сֵ*/
        /*	{
        		min[i]=A[i][j];
			}
            
		}
   }
        for (j=0; j<n; j++) /*�������е�ÿ����Сֵ�Ƿ��ǰ���*/
      /*  {
        	max[j]=A[0][j];
        	for(i=1;i<m;i++)
        	{
        		if(max[j]<A[i][j])  
                max[j]=A[i][j];
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(max[j]=min[i])
				{
					temp=1;
					printf("(%d,%d,%d)",i+1,j,A[i][j]);
				}
				
			}
		}
		if(temp==0)
		{
			printf("none!\n");
		}
           /* if (A[i][j]==min )
            { 
                k=j;
                p=0;
                 while (p<m && A[p][j]<min)
                     p++;
                 if ( p>=m) 
                     printf ("(%d,%d,%d)", i ,k,min);
            } */
    for(i=0; i<M; i++) //���ÿ����С��������minn[0,,,M-1]��  
    {  
        minn[i]=A[i][0];  
        for(j=1; j<N; j++)  
            if(minn[i]>A[i][j])  
                minn[i]=A[i][j];  
    }  
    for(j=0; j<N; j++) //���ÿ�������������maxx[0,,,N-1]��  
    {  
        maxx[j]=A[0][j];  
        for(i=1; i<M; i++)  
            if(maxx[j]<A[i][j])  
                maxx[j]=A[i][j];  
    }  
    for(i=0; i<M; i++)  
        for(j=0; j<N; j++)  
            if(minn[i]==maxx[j])//�ҵ�����  
            {  
                printf("(%d,%d,%d)",i+1,j+1,A[i][j]);  
                //have=true; 
				temp=1; 
            }  
    if(temp==0)  
        printf("û������\n");  
}
main()
{
	int A[M][N];
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d",&A[i][j]);
    saddle (A,m,n); 
}
