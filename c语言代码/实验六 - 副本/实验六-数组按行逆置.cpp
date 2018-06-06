#include<stdio.h>
int change(int *p,int *q)
{
	int t;
		while(p<q)
		{
		t=*p;
		*p=*q;
		*q=t;
		p++;
		q--; 
    	}
}
main()
{
	int c[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int i,j,m;
	int *p,*q;
	for(i=0;i<3;i++)
	{
		p=&c[i][0];
		q=&c[i][3];
		change(p,q);

	}
    for(i=0;i<3;i++)
    {
    for(j=0;j<4;j++)
		{
			printf("%5d",c[i][j]);
		}
			printf("\n");
	}

} 

