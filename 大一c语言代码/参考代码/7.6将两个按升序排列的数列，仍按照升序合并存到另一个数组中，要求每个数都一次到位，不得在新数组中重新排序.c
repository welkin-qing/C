/*���������������е����У��԰�������ϲ��浽��һ�������У�Ҫ��ÿ������һ�ε�λ������������������������*/
#include <stdio.h>
#define M 10
#define N 10
int a[M]={1,2,3,4,5,6,7,8,9,10};
int b[N]={2,4,6,8,10,12,14,16,18,20};
int c[M+N];
void main()
{
	int i=0,j=0,k=0,min;
	while(i<M||j<N)
	{
		if(a[i]>b[j])
		{
			min=b[j];
			j++;
			if(j>=N) 
				b[j]=65535; //��Ϊ���ֵ
		}
		else
		{
			min=a[i];
			i++;
			if(i>=M) 
				a[i]=65535;
		}
		c[k]=min;
		k++;	
	}
	for(i=0;i<M+N;i++)	
		printf("%5d",c[i]);	
}