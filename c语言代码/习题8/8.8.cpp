#include<stdio.h>
int function(int m)
{
	int i,s=0;
	for(i=1;i<m;i++)
	{
		if(m%i==0) s+=i;  //����Լ���ĺ� 
	}
	return s;
}
main()
{
	int i,j;
	for(i=1;i<10000;i++)
	{
		j=function(i);
		if(j>i&&function(j)==i)  //�ж�������������Լ���ĺ͵�ֵһ�� 
		printf("%d %d\n",i,j);
	}
}
