#include<stdio.h> 
#define m 4
#define n 6
int main() {
    int i,j,max,min,flag=1,b;
    int a[m][n] {
    					{45,67,87,34,56,26},
						{93,75,85,75,92,75},
						{94,85,96,75,78,75},
						{23,17,75,28,98,61}

						
						
					}; /*
    printf("请输入二维数组a[%d][%d]:\n",m,n);
    
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&a[i][j]);*/
    printf("二维数组a[%d][%d]如下:\n",m,n);
    //输出数组 
    for (i=0;i<m;i++) 
	{
        for (j=0;j<n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
/* 
    for (i=0;i<m;i++) 
	{
		b=i;/*记录行数*/
    /*    for (min=a[i][0],j=0;j<n;j++)
            if (min>a[i][j])
                min=a[i][j];/*找出每行最小的*/ 
    //    printf("%5d",min);
        
    /*    for (j=0;j<n;j++) 
		{

            for (min=a[i][j],i=0;i<m;i++) /*将a[i][j]的值重新赋值*/ 
          /*      if (max<a[i][j])
                    max=a[i][j];/*找出每列最大的*/ 
        //    printf("%5d",max);
          //  i=b;  /*求所在最大数的列上找最大的*/ 
            /*if (a[i][j]==max&&a[i][j]==min) 
			{
                printf("a[%d][%d]=%d ",i,j,a[i][j]);
                flag++;
            }
        }

    }
    if (flag==0)
        printf("没有鞍点!\n");
    else printf("\n");*/
    
    
    for(i=0;i<m;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(a[i][flag]>a[i][j])
    		{
    			flag=j;
			}
			for(b=0;b<m;b++)
		{
			if(a[i][flag]<a[b][flag]) break;
		}
		if(b==m)  printf("%d=a[%d][%d]\n",a[i][flag],i,flag);
		}/*
		for(b=0;b<m;b++)
		{
			if(a[i][flag]<a[b][flag]);
		}
		if(b==m)  printf("%d=a[%d][%d]\n",a[i][flag],i,flag);*/
		flag=1;
	}
	return 0;
} 
