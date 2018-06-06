#include<stdio.h>
int function(int m)
{
	int i,s=0;
	for(i=1;i<m;i++)
	{
		if(m%i==0) s+=i;  //计算约数的和 
	}
	return s;
}
main()
{
	int i,j;
	for(i=1;i<10000;i++)
	{
		j=function(i);
		if(j>i&&function(j)==i)  //判定两个数不等且约数的和的值一样 
		printf("%d %d\n",i,j);
	}
}
