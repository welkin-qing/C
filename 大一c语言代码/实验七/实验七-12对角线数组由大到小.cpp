#include<stdio.h>
main()
{
	int a[4][4]={11,12,13,14,15,16,7,8,3,1,9,2,4,5,6,10};
	int b[16]={0};
	int i,j,m=0;
	int e,f,g,h,t; 
	printf("输出该数组\n");
	for(i=0;i<4;i++)
	{

	for(j=0;j<4;j++)
	{
		printf("%5d",a[i][j]);
		b[m]=a[i][j];
		m++;
	}
	printf("\n");
   }
    for(i=0;i<15;i++)  
	{
		for(j=i+1;j<16;j++)  
		if(b[i]>b[j])   
		{
		t=b[i];
		b[i]=b[j];
		b[j]=t;
		}
	} 
	e=a[0][0] ;   
	f=a[1][1] ;  
	g=a[2][2] ;   
	h=a[3][3] ;   
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	{
		if(b[3]==a[i][j])
		{
			a[i][j]=e;
		}

	 if(b[2]==a[i][j])
		{
			a[i][j]=f;
		}
	
	 if(b[1]==a[i][j])
		{
			a[i][j]=g;
		}
	if(b[0]==a[i][j])
		{
			a[i][j]=h;
		}
	}
	 a[0][0]=b[3];
	 a[1][1]=b[2];
	 a[2][2]=b[1];
	 a[3][3]=b[0];
	 printf("新数组是\n");
	for(i=0;i<4;i++)
	{

	for(j=0;j<4;j++)
	{
		printf("%5d",a[i][j]);
	}
	printf("\n");
   }
 } 
