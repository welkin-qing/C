/*�ҳ�6*6����ÿ�о���ֵ����Ԫ�أ�����ͬ�жԽ���Ԫ�ؽ���*/
#include<stdio.h>
#include<math.h>
int main()
{
	int a[6][6]={7,6,5,4,3,2,1,7,9,10,17,14,8,-9,6,7,12,15,17,42,43,41,52,0,8,11,4,2,6,10,11,25,34,27,38,19};
	int i,j,k,m,n,max;
	/*printf("������һ��6*6���飺\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}*/
	printf("����aΪ��\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("�仯�ľ���Ϊ��\n"); 
	for(j=0;j<6;j++)
	{
		max=fabs(a[0][j]);  
		for(i=1;i<6;i++)
		{
			if(fabs(a[i][j])>max)
			{
				max=a[i][j];
				k=i;
				n=j; 
			} 
		}
		{
			m=a[k][j];
			a[k][j]=a[k][5-n];
			a[k][5-n]=m;   
		}
		
	}
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	} 
	system("pause");
}     

