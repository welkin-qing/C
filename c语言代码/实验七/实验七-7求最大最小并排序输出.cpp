#include<stdio.h>
void function(int a[3][3])
{
	int i,j,b[9];
	int m=0,t,n=0;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		b[m]=a[i][j];
		m++;
	}
		for(i=0;i<8;i++)   
	{
		for(j=i+1;j<9;j++)  
		if(b[i]>b[j])   
		{
		t=b[i];
		b[i]=b[j];
		b[j]=t;
		}
		
	}
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		a[i][j]=b[n];
		n++;
	}
	for(i=2;i>=0;i--)
	{
	for(j=0;j<3;j++)
	{
		printf("%5d",a[i][j]);
	}
	printf("\n");
    }

}
main()
{
	int c[3][3]={1,2,3,4,5,6,7,8,9};
	function(c);
}
