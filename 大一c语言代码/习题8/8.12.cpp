#include<stdio.h>
void function(int n)
{
	int i,j,m;
	int a[n]={0};
	int f1,f2,f;
	f1=2,f2=3;
	a[0]=f1,a[1]=f2;
	for(m=1;m<n;)
	{
		f=f1*f2;;
		if(f<10)   a[++m]=f;
		if(f>=10)
		{
			a[++m]=f/10;
			a[++m]=f%10;
		
		}
		f1=a[m-1];
		f2=a[m];
	}
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}
main()
{
	int n;
	scanf("%d",&n);
	function(n);	
}
    


