#include<stdio.h>
main()
{
	int a[5][4]={90,95,90,98,80,85,82,83,67,78,96,79,78,67,55,32,80,90,60,70}; 
	int i,j;
	int sum;
	double aver=1;
	printf("����������ɼ���\n");
	for(i=0;i<5;i++)
	{
	printf("��%d��ѧ�����ĿƳɼ���",i+1);
	for(j=0;j<4;j++)
	{
		printf("%5d",a[i][j]);
	}
	printf("\n");
    }
    for(i=0;i<5;i++)
    {
    	sum=0;
    	printf("��%d��ѧ�����Ŀ��ܳɼ���ƽ�����ǣ�",i+1);
    	for(j=0;j<4;j++)
    	{
    		sum+=a[i][j];
		}
		aver=sum/4.0;
		printf("%5d      %f",sum,aver);
		printf("\n");
	}
	printf("������ �� �� �� ��˳��:\n"); 
	for(j=0;j<4;j++)
	{
		sum=0;
		printf("���Ƴɼ��ֺܷ�ƽ���ֱַ���:"); 
		for(i=0;i<5;i++)
		{
			sum+=a[i][j];
		}
		aver=sum/5.0;
		printf("%5d      %f",sum,aver);
		printf("\n");
	 } 
	
}
