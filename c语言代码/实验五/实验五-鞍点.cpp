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
    printf("�������ά����a[%d][%d]:\n",m,n);
    
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&a[i][j]);*/
    printf("��ά����a[%d][%d]����:\n",m,n);
    //������� 
    for (i=0;i<m;i++) 
	{
        for (j=0;j<n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
/* 
    for (i=0;i<m;i++) 
	{
		b=i;/*��¼����*/
    /*    for (min=a[i][0],j=0;j<n;j++)
            if (min>a[i][j])
                min=a[i][j];/*�ҳ�ÿ����С��*/ 
    //    printf("%5d",min);
        
    /*    for (j=0;j<n;j++) 
		{

            for (min=a[i][j],i=0;i<m;i++) /*��a[i][j]��ֵ���¸�ֵ*/ 
          /*      if (max<a[i][j])
                    max=a[i][j];/*�ҳ�ÿ������*/ 
        //    printf("%5d",max);
          //  i=b;  /*�����������������������*/ 
            /*if (a[i][j]==max&&a[i][j]==min) 
			{
                printf("a[%d][%d]=%d ",i,j,a[i][j]);
                flag++;
            }
        }

    }
    if (flag==0)
        printf("û�а���!\n");
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
