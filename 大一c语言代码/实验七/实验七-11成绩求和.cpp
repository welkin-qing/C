#include<stdio.h>
main()
{
	int a[5][4]={90,95,90,98,80,85,82,83,67,78,96,79,78,67,55,32,80,90,60,70}; 
	int i,j;
	int sum;
	double aver=1;
	printf("语数物外各成绩是\n");
	for(i=0;i<5;i++)
	{
	printf("第%d个学生的四科成绩：",i+1);
	for(j=0;j<4;j++)
	{
		printf("%5d",a[i][j]);
	}
	printf("\n");
    }
    for(i=0;i<5;i++)
    {
    	sum=0;
    	printf("第%d个学生的四科总成绩和平均分是：",i+1);
    	for(j=0;j<4;j++)
    	{
    		sum+=a[i][j];
		}
		aver=sum/4.0;
		printf("%5d      %f",sum,aver);
		printf("\n");
	}
	printf("按照语 数 物 外 的顺序:\n"); 
	for(j=0;j<4;j++)
	{
		sum=0;
		printf("单科成绩总分和平均分分别是:"); 
		for(i=0;i<5;i++)
		{
			sum+=a[i][j];
		}
		aver=sum/5.0;
		printf("%5d      %f",sum,aver);
		printf("\n");
	 } 
	
}
