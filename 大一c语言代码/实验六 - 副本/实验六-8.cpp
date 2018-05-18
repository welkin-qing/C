#include<stdio.h>
main()
{
	int a[4][4]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31},b[16]={0};
	int  i,j,m=0,t;
	int min,max;
	//printf("a[4][4]=");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
	
			b[m]=a[i][j];
			m++;
		}
		for(i=0;i<15;i++)   
	{
		for(j=i+1;j<16;j++) 
		if(b[i]<b[j])
		{
		t=b[i];
		b[i]=b[j];
		b[j]=t;
		}
		
	}
		printf("min=%d\n",min=b[i]);
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(min==a[i][j])
			{
				printf("%d行%d列\n",i+1,j+1);
			}
			m++;
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
		printf("max=%d\n",max=b[i]);
			for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(max==a[i][j])
			{
				printf("%d行%d列\n",i+1,j+1);
			}
			m++;
		}
}


