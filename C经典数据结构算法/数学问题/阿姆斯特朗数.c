#include<stdio.h>
main()
{
	int i,t,k,a[3];
	printf("There are following Armstrong number smaller than 1000: \n");
	for(i=152;i<1000;i++)
	{
		for(t=0,k=1000;k>=10;t++)
		{
			a[t]=(i%k)/(k/10); /* k/=10  ������ȥ*/
			k/=10;
		}
		if(a[0]*a[0]*a[0]+a[1]*a[1]*a[1]+a[2]*a[2]*a[2]==i)
			printf("%d ",i);
	}
}

/*��ķ˹��������һ��������������ĸ�λ������������ 153=1*1*1+5*5*5+3*3*3 */