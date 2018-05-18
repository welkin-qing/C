/*#include<stdio.h>
int function(int b)
{
	int a[4],i,j,t,m,n;
	for(b=1000;b<10000;b++)
	{
		a[0]=b%10;
	    a[1]=b/10%10;
	    a[2]=b/100%10;
	    a[3]=b/1000;
	    for(i=0;i<3;i++)   
	{
		for(j=i+1;j<4;j++) 
		if(a[i]>a[j])
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
	}
	m=a[0]*1000+a[1]*100+a[2]*10+a[3];
	if(m%11==0)
	{
		n=a[3]*1000+a[2]*100+a[1]*10+a[0];
		if(n%11==0)   printf("%d",b);
	}
	}
}
main()
{
	int s,q;
	scanf("%d",&s);
	q=function(s);
}*/

main()
{
	
}
